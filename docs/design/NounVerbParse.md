# Noun-Verb Parse

| Subject Noun | Noun Type | Verb | Verb Type | Object Noun | Noun Type | Status |
| - | - | - | - | - | - | - |
| user | actor | want | requirement | support | feature | X |
| I | actor | want | requirement | (midi chunk) header | entity | X |
| I | actor | find | action | (data) structures | entity | C |
| (midi) file | entity | - | - | - | - | X |
| (chunk) header | entity | inherit | relationship | (binary chunk) header | entity | X |
| (chunk) header | entity | change | action | size | attribute | X |
| (little) endian | attribute value | - | - | - | - | C |
| (big) endian | attribute value | - | - | - | - | C |
| (midi) file | entity | use | requirement | (big endian) integer | attribute value | X |
| user | actor | want | requirement | support | feature | X |
| I | actor | want | requirement | (midi header chunk) data | entity | X |
| I | actor | read | action | (midi) file | entity | C |
| I | actor | write | action | (midi) file | entity | C |
| (midi header chunk) data | entity | inherit | relationship | (binary data) structure | X |
| (midi header chunk) data | contain | composition | (format) field | attribute | X |
| zero | attribute value | indicates | relationship | (single) track | constant | X |
| one | attribute value | indicates | relationship | (multiple simultaneous) track | constant | X |
| two | attribute value | indicates | relationship | (multiple independent) track | X |
| (midi header chunk) data | contain | composition | (number of tracks) field | attribute | X |
| (midi header chunk) data | contain | composition | (division) field | attribute | X |
| (most significant) bit | variable | is | relationship | zero | variable value | - |
| (remaining) bit | variable | is | relationship | ticks (per quarter note) | variable | - |
| (most significant) bit | variable | is | relationship | one | variable value | - |
| bit (14 - 8) | variable | represent | relationship | (time code) format | variable | - |
| bit (7 - 0) | variable | represent | relationship | ticks (per frame) | variable | - | 

Status:
- X = Documented
- \- = Undocumented
- C = Consolidated via assumptions