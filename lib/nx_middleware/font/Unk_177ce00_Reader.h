#pragma once
// NintendoWare Font 7.3.2: the character stream reader nn::font::Font's
// Unk_177ce00 and Unk_177ce70 return. Placeholder names.
#include <types.h>

// A character stream reader: the stream and the member function that reads
// its next character.
class Unk_177ce00_Reader {
public:
    using Read = u32 (Unk_177ce00_Reader::*)();

    Unk_177ce00_Reader(const void* stream, Read read) : field_0(stream), field_8(read) {}

    u32 Unk_177cf20();  // UTF-8 (lib/nx_middleware/font/Unk_177cf20.cpp)
    u32 Unk_177cf60();  // UTF-16
    u32 Unk_177cf80();  // one byte a character
    u32 Unk_177cfa0();  // one or two bytes a character

    const void* field_0;
    Read field_8;
};
PKMN_SIZE_ASSERT(Unk_177ce00_Reader, 0x18);
