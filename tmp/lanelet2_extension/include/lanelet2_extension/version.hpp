// Copyright 2015-2024 Autoware Foundation. All rights reserved.
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
//
// Authors: Mamoru Sobue

#ifndef LANELET2_EXTENSION__VERSION_HPP_
#define LANELET2_EXTENSION__VERSION_HPP_

// NOLINTBEGIN(readability-identifier-naming)

namespace lanelet::autoware
{
enum class Version : int {
  none = 0,
  v1,
};

static constexpr Version version = Version::v1;
}  // namespace lanelet::autoware

#endif  // LANELET2_EXTENSION__VERSION_HPP_
