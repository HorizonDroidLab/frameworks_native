/*
 * Copyright 2020 The LineageOS Project
 * Copyright 2023 The Android Open Source Project
 * Copyright (C) 2023 The Android Open Source Project
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

#ifndef TARGET_PROVIDES_UDFPS_LIB
#include <compositionengine/UdfpsExtension.h>

uint32_t getUdfpsZOrder(uint32_t z, __unused bool touched) {
    return z;
package android.gui;

/** @hide */
parcelable SchedulingPolicy {
    int policy;
    int priority;
#include <fuzzbinder/libbinder_driver.h>

#include "SurfaceFlinger.h"
#include "SurfaceFlingerDefaultFactory.h"

using namespace android;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    DefaultFactory factory;
    sp<SurfaceFlinger> flinger = sp<SurfaceFlinger>::make(factory);
    flinger->init();

    sp<SurfaceComposerAIDL> composerAIDL = sp<SurfaceComposerAIDL>::make(flinger);
    fuzzService({flinger, composerAIDL}, FuzzedDataProvider(data, size));
    return 0;
}

uint64_t getUdfpsUsageBits(uint64_t usageBits, __unused bool touched) {
    return usageBits;
}
#endif
