# Entities

| struct Midi::ChunkHeader : Binary::ChunkHeader |
| - |
| |
| + ChunkHeader() - Changes endianness |

| class Midi::File |
| - |
| - VariableLengthQuantity ReadVariableLengthQuantity() |

| struct Midi::HeaderChunkData : public Binary::DataStructure |
| - |
| + const int singleTrack{ 0 } |
| + const int multipleSimultaneousTracks{ 1 } |
| + const int multipleIndependentTracks{ 2 } |
| + HeaderChunkData() - Sets fields to Big Endian |
| + Binary::UInt16 format |
| + Binary::UInt16 numberOfTracks |
| + Binary::UInt16 division | 

| class Midi::VariableLengthQuantity : public Binary::DataField |
| - |
| + VariableLengthQuantity(size_t size) |
| + std::uint32_t Value() const |
| + void SetValue(std::uint32_t v) |
| - std::unique_ptr<char[]> rawData |
| - std::uint32_t ConvertFromRawData() const |
| - void ConvertToRawData(std::uint32_t) |

| abstract class Midi::Event |
| - |
| + Midi::EventType Type() |

| class Midi::EventType |
| - |
| + Midi |
| + SystemExclusive |
| + Meta |

| class Midi::TrackEvent : public Binary::DataStructure |
| - |
| - VariableLengthQuantity deltaTime |
| - Midi::Event event |