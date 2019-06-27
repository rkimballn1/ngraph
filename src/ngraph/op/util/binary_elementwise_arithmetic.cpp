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

#include "ngraph/op/util/binary_elementwise_arithmetic.hpp"

using namespace std;
using namespace ngraph;

op::util::BinaryElementwiseArithmetic::BinaryElementwiseArithmetic()
{
}

op::util::BinaryElementwiseArithmetic::BinaryElementwiseArithmetic(const Output<Node>& arg0,
                                                                   const Output<Node>& arg1,
                                                                   const AutoBroadcastSpec& autob)
    : Op({arg0, arg1})
    , m_autob(autob)
{
}

op::util::BinaryElementwiseArithmetic::BinaryElementwiseArithmetic(
    const std::shared_ptr<Node>& arg0,
    const std::shared_ptr<Node>& arg1,
    const AutoBroadcastSpec& autob)
    : Op(check_single_output_args({arg0, arg1}))
    , m_autob(autob)
{
}

op::util::BinaryElementwiseArithmetic::BinaryElementwiseArithmetic(
    const std::string& node_type,
    const std::shared_ptr<Node>& arg0,
    const std::shared_ptr<Node>& arg1,
    const AutoBroadcastSpec& autob)
    : Op(node_type, check_single_output_args({arg0, arg1}))
    , m_autob(autob)
{
}

void op::util::BinaryElementwiseArithmeticValidator::validate()
{
    node->validate_and_infer_elementwise_arithmetic(node->m_autob);
}
