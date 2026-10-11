// TrackEvent.h - Declares the Midi::TrackEvent class.
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

#ifndef MIDI_TRACK_EVENT_H
#define MIDI_TRACK_EVENT_H

#include <memory>
#include <LibCppBinary.h>
#include "Event.h"
#include "VariableLengthQuantity.h"

namespace Midi
{
    /// @brief Represents a MIDI track event including its delta time and event.
    struct TrackEvent : public Binary::DataStructure
    {
    public:
        VariableLengthQuantity deltaTime;
        std::shared_ptr<Event> event;

        /// @copydoc Binary::DataStructure::Fields()
        std::vector<Binary::DataField*> Fields() override;

        /// @copydoc Binary::DataStructure::Fields() const
        std::vector<const Binary::DataField*> Fields() const override;

        /// @copydoc Binary::DataStructure::Size()
        size_t Size() const override;
    };
}

#endif