// VariableLengthQuantityTests.cpp - Defines VariableLengthQuantity tests.
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

#include "VariableLengthQuantityTests.h"

void VariableLengthQuantityTests::SetUp()
{
}

TEST_F(VariableLengthQuantityTests, ConstructorAllocatesMemoryProperly)
{
    size_t size{ 4 };

    Midi::VariableLengthQuantity q(size);

    EXPECT_EQ(q.Size(), size);
}

TEST_F(VariableLengthQuantityTests, ValueIsZeroByDefault)
{
    size_t size{ 4 };

    Midi::VariableLengthQuantity q(size);

    EXPECT_EQ(q.Value(), 0);
}

TEST_F(VariableLengthQuantityTests, SetValueUpdatesValueProperly)
{
    size_t initialSize{ 4 };
    std::uint32_t value{ 10000 };
    size_t expectedSize{ 2 };

    Midi::VariableLengthQuantity q(initialSize);
    q.SetValue(value);

    // The size should change to however many bytes are needed to represent
    // the value in variable-length quantity format.
    ASSERT_EQ(q.Size(), expectedSize);

    // Check that the raw bytes are correctly represented as big endian numbers
    // stored with 7-bit bytes with leading continuation bits. Cast the raw
    // data elements to unsigned char before comparison since char is signed
    // on some platforms and this can cause the positive 0xCE value to fail
    // the comparison if the char ends up negative.
    EXPECT_EQ(static_cast<unsigned char>(q.RawData()[0]), 0xCE);
    EXPECT_EQ(static_cast<unsigned char>(q.RawData()[1]), 0x10);

    // We should get the same value back. 
    EXPECT_EQ(q.Value(), value);
}

TEST_F(VariableLengthQuantityTests, ValueIsCorrectlyConvertedFromRawData)
{
    size_t size{ 2 };
    std::uint32_t expectedValue{ 10000 };

    Midi::VariableLengthQuantity q(size);

    // Set the raw data to represent the value 10000 in variable-length quantity
    // format. The bytes should be 0xCE, 0x10.
    q.RawData()[0] = static_cast<char>(0xCE);
    q.RawData()[1] = static_cast<char>(0x10);

    EXPECT_EQ(q.Value(), expectedValue);
}

TEST_F(VariableLengthQuantityTests, ToStringReturnsCorrectStringRepresentation)
{
    size_t size{ 2 };
    std::uint32_t value{ 10000 };

    Midi::VariableLengthQuantity q(size);
    q.SetValue(value);

    // The resulting string should be a decimal representation.
    std::string expectedString{ "10000" };

    EXPECT_EQ(q.ToString(), expectedString);
}