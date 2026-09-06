// VariableLengthQuantity.cpp - Defines the Midi::VariableLengthQuantity class.
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

#include "Midi/VariableLengthQuantity.h"

using namespace Midi;

constexpr int maxBytes{ 4 };
constexpr int valueBits{ 7 };
constexpr int bitMask7Bits{ 0x7F };
constexpr int continuationBit{ 0x80 };

VariableLengthQuantity::VariableLengthQuantity(size_t size) :
    Binary::RawField(size)
{
}

/*
size_t VariableLengthQuantity::Size() const
{
    return 0;
}
*/

/*
char* VariableLengthQuantity::RawData()
{
    return nullptr;
}

const char* VariableLengthQuantity::RawData() const
{
    return nullptr;
}
*/

/*
std::string VariableLengthQuantity::ToString() const
{
    return {};
}

std::string VariableLengthQuantity::ToString(Binary::StringFormat format) const
{
    return {};
}
*/

std::uint32_t VariableLengthQuantity::ConvertFromRawData() const
{
    std::uint32_t value{ 0 };

    for (size_t i = 0; i < size; i++)
    {
        std::uint8_t byte = static_cast<std::uint8_t>(rawData[i]);

        // We assume that rawData already contains a variable length encoded 
        // value and that size was properly determined during the encoding 
        // process using ConvertToRawData(). Therefore, we don't need to check
        // the encoding bits and simply apply the 7-bit mask using bitwise AND.
        byte &= bitMask7Bits;
        
        // Left shift any existing bits in the value by 7 to make room for the
        // new 7-bit portion of the value.
        value = (value << valueBits);
        
        // Bitwise OR the new 7-bit portion into the value.
        value |= byte;
    }

    return value;
}

void VariableLengthQuantity::ConvertToRawData(std::uint32_t value)
{
    uint8_t encoded[maxBytes];
    int encodingIndex{ 0 };
    bool foundMostSignificantByte{ false };

    for (int multiplier = maxBytes - 1; multiplier >= 0; multiplier--)
    {
        // First, we determine how many bits we need to shift to the right to
        // isolate the first 7-bit portion of the value. The starting shift
        // amount should be 3 * 7 = 21.
        int shift = multiplier * valueBits;

        // Then, perform the shift, which isolates the next 7-bit portion of the
        // value.
        int valuePortion = value >> shift;

        // Then, apply a 7-bit bitmask to clear all but the last 7-bits.
        valuePortion &= bitMask7Bits;

        if (valuePortion == 0 && !foundMostSignificantByte)
        {
            // If we haven't found the most significant byte yet and the current
            // value portion is 0, we skip it as the most significant byte
            // should be the first one we store in the encoded array.
            continue;
        }
        else if (!foundMostSignificantByte)
        {
            foundMostSignificantByte = true;
        }

        if (multiplier > 0)
        {
            // Every byte except the last one needs the continuation bit set.
            valuePortion |= continuationBit; 
        }

        encoded[encodingIndex] = static_cast<uint8_t>(valuePortion);
        encodingIndex++;
    }

    // Re-allocate rawData to match the size necessary for encoding the value.
    rawData = std::make_unique<char[]>(encodingIndex);
    size = encodingIndex;

    // Copy the encoded bytes into rawData so they can be stored.
    for (int i = 0; i < encodingIndex; i++)
    {
        rawData[i] = static_cast<char>(encoded[i]);
    }
}