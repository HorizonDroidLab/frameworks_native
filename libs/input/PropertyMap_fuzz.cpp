/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "android-base/file.h"
#include "fuzzer/FuzzedDataProvider.h"
#include "input/PropertyMap.h"

static constexpr int MAX_FILE_SIZE = 256;
static constexpr int MAX_STR_LEN = 2048;
static constexpr int MAX_OPERATIONS = 1000;

static const std::vector<std::function<void(FuzzedDataProvider*, android::PropertyMap&)>>
        operations = {
                [](FuzzedDataProvider*, android::PropertyMap& propertyMap) -> void {
                    propertyMap.clear();
                },
                [](FuzzedDataProvider* dataProvider, android::PropertyMap& propertyMap) -> void {
                    std::string key = dataProvider->ConsumeRandomLengthString(MAX_STR_LEN);
                    propertyMap.getString(key);
                },
                [](FuzzedDataProvider* dataProvider, android::PropertyMap& /*unused*/) -> void {
                    TemporaryFile tf;
                    // Generate file contents
                    std::string contents = dataProvider->ConsumeRandomLengthString(MAX_FILE_SIZE);
                    // If we have string contents, dump them into the file.
                    // Otherwise, just leave it as an empty file.
                    if (contents.length() > 0) {
                        const char* bytes = contents.c_str();
                        android::base::WriteStringToFd(bytes, tf.fd);
                    }
                    android::PropertyMap::load(tf.path);
                },
                [](FuzzedDataProvider* dataProvider, android::PropertyMap& propertyMap) -> void {
                    std::string key = dataProvider->ConsumeRandomLengthString(MAX_STR_LEN);
                    std::string val = dataProvider->ConsumeRandomLengthString(MAX_STR_LEN);
                    propertyMap.addProperty(key, val);
                },
};
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    FuzzedDataProvider dataProvider(data, size);
    android::PropertyMap propertyMap;

    int opsRun = 0;
    while (dataProvider.remaining_bytes() > 0 && opsRun++ < MAX_OPERATIONS) {
        uint8_t op = dataProvider.ConsumeIntegralInRange<uint8_t>(0, operations.size() - 1);
        operations[op](&dataProvider, propertyMap);
    }
    return 0;
}
