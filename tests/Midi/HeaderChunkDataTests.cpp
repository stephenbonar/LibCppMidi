// HeaderChunkDataTests.cpp - Defines the HeaderChunkDataTests class and tests.
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

#include "HeaderChunkDataTests.h"

void HeaderChunkDataTests::SetUp()
{
    // This function is called before each test is run.
    // You can use it to set up any common test data or state.
}

TEST_F(HeaderChunkDataTests, FieldsBigEndian)
{
    Midi::HeaderChunkData data;

    EXPECT_EQ(data.format.Endianness(), Binary::FieldEndianness::Big);
    EXPECT_EQ(data.numberOfTracks.Endianness(), Binary::FieldEndianness::Big);
    EXPECT_EQ(data.timeDivision.Endianness(), Binary::FieldEndianness::Big);
}

TEST_F(HeaderChunkDataTests, FieldsReturnsPointersToCorrectFields)
{
    Midi::HeaderChunkData data;
    std::vector<Binary::DataField*> fields = data.Fields();

    ASSERT_EQ(fields.size(), 3);
    EXPECT_EQ(fields[0], &data.format);
    EXPECT_EQ(fields[1], &data.numberOfTracks);
    EXPECT_EQ(fields[2], &data.timeDivision);
}

TEST_F(HeaderChunkDataTests, ConstFieldsReturnsPointersToCorrectFields)
{
    const Midi::HeaderChunkData data;
    std::vector<const Binary::DataField*> fields = data.Fields();

    ASSERT_EQ(fields.size(), 3);
    EXPECT_EQ(fields[0], &data.format);
    EXPECT_EQ(fields[1], &data.numberOfTracks);
    EXPECT_EQ(fields[2], &data.timeDivision);
}

TEST_F(HeaderChunkDataTests, SizeReturnsCorrectSize)
{
    Midi::HeaderChunkData data;

    EXPECT_EQ(data.Size(), 6);
}