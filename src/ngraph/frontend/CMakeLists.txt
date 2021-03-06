# ******************************************************************************
# Copyright 2017-2020 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ******************************************************************************

if (NGRAPH_ONNX_IMPORT_ENABLE)
    add_subdirectory(onnx_import)
endif()

# FIXME(silee2): Re-enable NORMALIZE_BOOL after implementing a proper fix for #4293
option(NGRAPH_FLUID_ENABLE "Enable build for PaddlePaddle Fluid support" ON)
#NORMALIZE_BOOL(NGRAPH_FLUID_ENABLE)
message(STATUS "NGRAPH_FLUID_ENABLE:                  ${NGRAPH_FLUID_ENABLE}")

if (NGRAPH_FLUID_ENABLE)
    option(NGRAPH_FLUID_TEST_ENABLE "Enable PaddlePaddle Fluid operator tests" OFF)
    #NORMALIZE_BOOL(NGRAPH_FLUID_TEST_ENABLE)
    message(STATUS "NGRAPH_FLUID_TEST_ENABLE:             ${NGRAPH_FLUID_TEST_ENABLE}")
    add_subdirectory(fluid)
endif()

option(NGRAPH_ATEN_ENABLE "Enable build for PyTorch ATen support" OFF)
#NORMALIZE_BOOL(NGRAPH_ATEN_ENABLE)
message(STATUS "NGRAPH_ATEN_ENABLE:                   ${NGRAPH_ATEN_ENABLE}")

if (NGRAPH_ATEN_ENABLE)
    option(NGRAPH_ATEN_TEST_ENABLE "Enable PaddlePaddle Fluid operator tests" OFF)
    #NORMALIZE_BOOL(NGRAPH_ATEN_TEST_ENABLE)
    message(STATUS "NGRAPH_ATEN_TEST_ENABLE:              ${NGRAPH_ATEN_TEST_ENABLE}")
    add_subdirectory(ATen)
endif()
