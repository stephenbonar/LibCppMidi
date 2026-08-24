# Requirements

## Story: Midi Files

### Description

As a user, I want support for reading from and writing to MIDI files so I can manipulate MIDI data.

### Requirements

A MIDI file should have a path, support loading the file to memory, and saving changes to the file.

## Story: Midi Chunk Headers

### Description

As a user, I want support for MIDI chunk headers so I can find specific data structures in the MIDI file.

### Requirements

A chunk header should inherit from Binary::ChunkHeader but change the size from little endian to big endian as MIDI files use big endian integers.

## Story: MIDI Header Chunk Data

### Description

As a user, I want support for MIDI Header Chunk Data so I can properly read from and write to the MIDI file structure.

### Requirements

The MIDI header chunk data should inherit from Binary::DataStructure and contain a Binary::UInt16 format field where 0 indicates a single multi-channel track, 1 indicates simultaneous tracks, and 2 indicates sequentially independent single track patterns, followed by a Binary::UInt16 number of tracks field, followed by a Binary::UInt16 division field, where if most significant bit is 0, the remaining bits represent ticks per quarter note, but if the most significant bit is 1, bits 14 - 8 represent time code format and bits 7 - 0 represent ticks per frame

## Story: MIDI Track Chunk Data

### Description

As a user, I want support for MIDI track chunk data so I can properly read and write midi tracks in an MIDI file.

### Requirements

MIDI Track Chunk Data should inherit from Binary::DataStructure and contain one or more MIDI track events.

## Story: MIDI Track Events

### Description

As a user, I want support for MIDI track events so I can read and write MIDI track events to MIDI files.

### Requirements

A MIDI track event should inherit from Binary::DataStructure and should have a variable-length quantity delta-time field followed by a MIDI event field.

## Story: Variable Length Quantities

### Description

As a user, I want support for variable length quantities as many MIDI data fields are stored as these.

### Requirements

A variable length quantity is a series of bytes that represent a number where each byte is a 7-bit number with the most significant bit determining if there's another byte representing the number. If the most signficiant bit is 1, then there's another byte in the sequence. If the most signficiant bit is 0, it is the last byte that makes up the number. The variable length quantity should inherit from Binary::DataField and provide Value() and SetValue() methods that retrieve and store the integer value, automatically converting the underlying raw bytes. Midi::File should have the ability to read variable length quantities and return the resulting variable length quantity object (writes should be able to be done natively to Binary::Stream objects).

## Story: MIDI Events

### Description

As a user, I want support for MIDI events so I can read and write the MIDI events that make up a song to and from MIDI files.

### Requirements

A MIDI event is part of a MIDI track event and can contain different data depending on the event type (thus should be a base class and report its type, which derived types will provide).

## Story: MidiMessageEvent

### Description

As a user, I want support for MIDI message events so I retrieve and store MIDI messages within events in the MIDI file.

### Requirements

A MIDI message event carries a MIDI message and should report a type of MIDI message. It should inherit from Midi::Event. 

## Story: Midi Message

### Description

As a user, I want support for MIDI messages so I can read and write MIDI protocol messages to and from the file.

### Requirements

A MIDI message is composed of a status byte followed by zero or more data bytes. A MIDI message should be able to report its type, and human readable details. MIDI message should inherit from Binary::DataStructure.

## Story: Channel Message

### Description

As a user, I want support for channel messages so I can read and write messages that control MIDI channels to and from a MIDI file.

### Requirements

A MIDI channel message should inherit from Midi::Message and be able to report the channel encoded in its status byte.

## Story: Unrecognized Message

### Description

As a user, I want support for an unrecognized message so I can display information about messages the library is not yet able to decode.

### Requirements

The unrecognized message should inherit from Midi::Message and its details should indicate that this type of message is not recognized.

## Story: Note Off Message

### Description

As a user, I want support for Note Off messages so I can read and write the sequence of music notes in the MIDI file. 

### Requirements

A Note Off message should inherit from Midi::ChannelMessage and provide the note number and velociy.

## Story: Note On Message

### Description

As a user, I want support for Note On messages so I can read and write the sequence of music notes in the MIDI file. 

### Requirements

A Note On message should inherit from Midi::ChannelMessage and provide the note number and velociy.

## Story: Polyphonic Key Pressure Message

### Description

As a user, I want support for Polyphonic Key Pressure messages so I can read and write key pressure messages in the MIDI file.

### Requirements

A Polyphonic Key Pressure message should inherit from Midi::ChannelMessage and provide the note number and pressure value.

## Story: Control Change Message

### Description

As a user, I want support for Control Change message so I can read and write messages from control devices such as pedals and levers in the MIDI file. 

### Requirements

A Control change message should inherit from Midi::ChannelMessage and provide the controller number and controller value.

## Story: Program Change Message

### Description

As a user, I want support for Program Change messages so I can read and write patch (instrument) changes in the MIDI file. 

### Requirements

A program change message should inherit from Midi::ChannelMessage and provide the program number.

## Story: Channel Pressure Message

### Description

As a user, I want support for channel pressure messages so I can read and write channel pressure messages in the MIDI file. 

### Requirements

A channel pressure message should inherit from Midi::ChannelMessage and provide the pressure value.

## Story: Pitch Bend Change Message

### Description

As a user, I want support for pitch change messages so I can read and write pitch changes in the MIDI file.

### Requirements

A pitch change message should inherit from Midi::ChannelMessage andh provide a pitch bender value (derived from both 7-bit bytes)

## Story: System Common Events

### Description

As a user, I want support for system common events so I can read and write global, non‑real‑time musical context events (such as Song Position Pointer and Song Select) in MIDI files. 