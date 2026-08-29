// ChunkHeaderTests.cpp - Defines the ChunkHeaderTests class and tests.
//
// Copyright (C) 2026 Stephen Bonar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http ://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ChunkHeaderTests.h"

void ChunkHeaderTests::SetUp()
{
    // This function is called before each test is run.
    // You can use it to set up any common test data or state.
}

TEST_F(ChunkHeaderTests, DataSizeBigEndian)
{
    Midi::ChunkHeader header;

    EXPECT_EQ(header.dataSize.Endianness(), Binary::FieldEndianness::Big);
}