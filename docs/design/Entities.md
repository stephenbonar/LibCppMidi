# Entities

| struct Midi::ChunkHeader : Binary::ChunkHeader |
| - |
| |
| + ChunkHeader() - Changes endianness |

| class Midi::File |
| - |
|  |

| struct Midi::HeaderChunkData : public Binary::DataStructure |
| - |
| + const int singleTrack{ 0 } |
| + const int multipleSimultaneousTracks{ 1 } |
| + const int multipleIndependentTracks{ 2 } |
| + HeaderChunkData() - Sets fields to Big Endian |
| + Binary::UInt16 format |
| + Binary::UInt16 numberOfTracks |
| + Binary::UInt16 division | 
