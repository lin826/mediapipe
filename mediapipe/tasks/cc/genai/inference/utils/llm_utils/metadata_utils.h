// Copyright 2024 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MEDIAPIPE_TASKS_GENAI_INFERENCE_UTILS_LLM_UTILS_METADATA_UTILS_H_
#define MEDIAPIPE_TASKS_GENAI_INFERENCE_UTILS_LLM_UTILS_METADATA_UTILS_H_

#include <memory>
#include <string>

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/strings/string_view.h"
#include "mediapipe/tasks/cc/genai/inference/proto/llm_params.pb.h"
#include "mediapipe/tasks/cc/genai/inference/utils/llm_utils/memory_mapped_file.h"
#include "tensorflow/lite/model_builder.h"

namespace mediapipe::tasks::genai::llm_utils {

// Retrieve LlmParameters proto from tflite flatbuffer metadata.
absl::StatusOr<mediapipe::tasks::genai::proto::LlmParameters> GetLlmParams(
    std::shared_ptr<mediapipe::tasks::genai::llm_utils::MemoryMappedFile>
        mmap_file);

// Retrieve LlmModelType from tflite flatbuffer metadata.
absl::StatusOr<mediapipe::tasks::genai::proto::LlmModelType> GetLlmModelType(
    std::shared_ptr<mediapipe::tasks::genai::llm_utils::MemoryMappedFile>
        mmap_file);

// Retrieve backend string from tflite flatbuffer metadata.
absl::StatusOr<std::string> GetLlmBackend(
    std::shared_ptr<mediapipe::tasks::genai::llm_utils::MemoryMappedFile>
        mmap_file);

// Retrieves SentencePiece from tflite's metadata and returns a string_view of
// the model content.
absl::StatusOr<absl::string_view> ExtractSentencePieceToStringView(
    const tflite::FlatBufferModel& model, absl::string_view metadata_key);

// Retrieve SentencePiece from tflite flatbuffer metadata and write it to
// the provided path.
absl::Status ExtractSentencePiece(
    std::shared_ptr<mediapipe::tasks::genai::llm_utils::MemoryMappedFile>
        mmap_file,
    absl::string_view spm_vocab_path);

}  // namespace mediapipe::tasks::genai::llm_utils

#endif  // MEDIAPIPE_TASKS_GENAI_INFERENCE_UTILS_LLM_UTILS_METADATA_UTILS_H_
