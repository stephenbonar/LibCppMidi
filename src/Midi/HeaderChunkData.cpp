// HeaderChunkData.cpp - Defines the Midi::HeaderChunkData class.
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

#include "Midi/HeaderChunkData.h"

using namespace Midi;

HeaderChunkData::HeaderChunkData()
{
    // We override the default endianness of the fields to be 
    // big-endian per the MIDI specification.
    format.SetEndianness(Binary::FieldEndianness::Big);
    numberOfTracks.SetEndianness(Binary::FieldEndianness::Big);
    timeDivision.SetEndianness(Binary::FieldEndianness::Big);
}

std::vector<Binary::DataField*> HeaderChunkData::Fields()
{
    std::vector<Binary::DataField*> fields;
    fields.push_back(&format);
    fields.push_back(&numberOfTracks);
    fields.push_back(&timeDivision);
    return fields;
}

std::vector<const Binary::DataField*> HeaderChunkData::Fields() const
{
    std::vector<const Binary::DataField*> fields;
    fields.push_back(&format);
    fields.push_back(&numberOfTracks);
    fields.push_back(&timeDivision);
    return fields;
}

size_t HeaderChunkData::Size() const
{
    return format.Size() + numberOfTracks.Size() + timeDivision.Size();
}