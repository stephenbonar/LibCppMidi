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

VariableLengthQuantity::VariableLengthQuantity(size_t size) :
    Binary::RawField(size)
{
}

size_t VariableLengthQuantity::Size() const
{
    return 0;
}

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

std::uint32_t VariableLengthQuantity::Value() const
{
    return 0;
}

void VariableLengthQuantity::SetValue(std::uint32_t value)
{
}

std::uint32_t VariableLengthQuantity::ConvertFromRawData() const
{
    return 0;
}

void VariableLengthQuantity::ConvertToRawData(std::uint32_t value)
{
}