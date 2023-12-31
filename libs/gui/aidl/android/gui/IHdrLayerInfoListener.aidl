/*
 * Copyright 2021 The Android Open Source Project
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

package android.gui;

/** @hide */
oneway interface IHdrLayerInfoListener {
    // Callback with the total number of HDR layers, the dimensions of the largest layer,
    // a placeholder flags, and the max desired HDR/SDR ratio. The max desired HDR/SDR
    // ratio may be positive infinity to indicate an unbounded ratio.
    // TODO (b/182312559): Define the flags (likely need an indicator that a UDFPS layer is present)
    void onHdrLayerInfoChanged(int numberOfHdrLayers, int maxW, int maxH,
            int flags, float maxDesiredHdrSdrRatio);
}