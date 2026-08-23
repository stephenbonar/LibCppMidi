# CMakeLists.txt - CMakeLists for building the LibCppMidi project.
#
# Copyright (C) 2026 Stephen Bonar
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http ://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.16.0)

# Define the project metadata.
project(LibCppMidi VERSION 0.51.0 LANGUAGES C CXX)

# Specify the C++ standard. C++ 17 is the modern default with the widest 
# compatibility.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main source code directory to the project so we can compile the
# library.
add_subdirectory(src)

# Add the tests directory to the project so we can compile the test program.
add_subdirectory(tests)