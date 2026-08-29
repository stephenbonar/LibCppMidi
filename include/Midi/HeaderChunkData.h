// HeaderChunkData.h - Declares the Midi::HeaderChunkData class.
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

#ifndef MIDI_HEADER_CHUNK_DATA_H
#define MIDI_HEADER_CHUNK_DATA_H

#include <LibCppBinary.h>
#include <vector>

/// @brief Indicates format is single-track (Type 0).
constexpr int singleTrackFormat{ 0 };

/// @brief Indicates the format is simultaneous multi-track (Type 1).
constexpr int multiSimultaneousTrackFormat{ 1 };

/// @brief Indicates the format is independent multi-track (Type 2).
constexpr int multiIndependentTrackFormat{ 2 };

namespace Midi
{
    /// @brief Represents the data contained in a MIDI header chunk.
    struct HeaderChunkData : public Binary::DataStructure
    {
        Binary::UInt16Field format;
        Binary::UInt16Field numberOfTracks;
        Binary::UInt16Field timeDivision;

        /// @brief Default constructor; creates new instance of HeaderChunkData.
        HeaderChunkData();  

        /// @copydoc Binary::DataStructure::Fields()
        std::vector<Binary::DataField*> Fields() override;

        /// @copydoc Binary::DataStructure::Fields() const
        std::vector<const Binary::DataField*> Fields() const override;

        /// @copydoc Binary::DataStructure::Size()
        size_t Size() const override;
    };
}

#endif