// Event.h - Declares the Midi::Event class.
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

#ifndef MIDI_EVENT_H
#define MIDI_EVENT_H

#include "EventType.h"

namespace Midi
{
    /// @brief Represents a MIDI event encapsulated in a Midi::TrackEvent.
    ///
    /// This is the base class for all MIDI events contained within a 
    /// Midi::TrackEvent. The Midi::TrackEvent associates a delta time with
    /// each event while the Event class itself does not store timing 
    /// information. Rather, this Event class encapsulates the event payload,
    /// which can be a MIDI protocol message, such as a Channel Message or
    /// System Exclusive Message, or it can be a Meta event, which is a file
    /// specific event defined by the MIDI file format.
    class Event
    {
    public:
        /// @brief Virtual destructor so derived events are destroyed correctly
        /// when deleted through an Event pointer.
        virtual ~Event() = default;

        /// @brief Gets the type of the MIDI event.
        /// @return The type of the event as a Midi::EventType.
        virtual EventType Type() const = 0;
    };
}

#endif