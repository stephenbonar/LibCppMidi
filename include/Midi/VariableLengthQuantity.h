// VariableLengthQuantity.h - Declares the Midi::VariableLengthQuantity class.
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

#ifndef MIDI_VARIABLE_LENGTH_QUANTITY_H
#define MIDI_VARIABLE_LENGTH_QUANTITY_H

#include <LibCppBinary.h>
#include <cstdint>
#include <memory>

namespace Midi
{
    /// @brief Represents a MIDI variable-length quantity.
    class VariableLengthQuantity : public Binary::RawField
    {
    public:
        VariableLengthQuantity(size_t size);

        //size_t Size() const override;

        //char* RawData() override;

        //const char* RawData() const override;

        std::string ToString() const override
        {
            return std::to_string(Value());
        }

        //std::string ToString(Binary::StringFormat format) const override;

        std::uint32_t Value() const { return ConvertFromRawData(); }

        void SetValue(std::uint32_t value) { ConvertToRawData(value); }

    private:
        // std::unique_ptr<char[]> rawData;

        std::uint32_t ConvertFromRawData() const;
        
        void ConvertToRawData(std::uint32_t value);
    };
}

#endif