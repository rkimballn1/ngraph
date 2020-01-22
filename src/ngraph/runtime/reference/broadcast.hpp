//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include <cmath>

#include "ngraph/coordinate_transform.hpp"
#include "ngraph/shape_util.hpp"

namespace ngraph
{
    namespace runtime
    {
        namespace reference
        {
            template <typename T>
            void broadcast(const T* arg,
                           T* out,
                           const Shape& in_shape,
                           const Shape& out_shape,
                           const AxisSet& broadcast_axes)
            {
                Shape adj_in_shape;
                for (auto len : in_shape)
                {
                    if (len != 1)
                    {
                        adj_in_shape.push_back(len);
                    }
                }
                AxisSet adj_broadcast_axes = broadcast_axes;
                for (size_t i = 0; i < out_shape.size(); ++i)
                {
                    if (out_shape[i] == 1)
                    {
                        adj_broadcast_axes.insert(i);
                    }
                }
                CoordinateTransform input_transform(adj_in_shape);
                CoordinateTransform output_transform(out_shape);

                for (const Coordinate& output_coord : output_transform)
                {
                    Coordinate input_coord = reduce(output_coord, adj_broadcast_axes);

                    out[output_transform.index(output_coord)] =
                        arg[input_transform.index(input_coord)];
                }
            }
        }
    }
}
