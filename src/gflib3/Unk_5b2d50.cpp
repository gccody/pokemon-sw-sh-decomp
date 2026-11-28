// Scope: common
// A vector of Unk_2398848's growing (src/gflib3/Unk_5b2810.h). Placeholder
// names.
#include "gflib3/Unk_5b2810.h"

#include <vector>

#include "unsorted/Unk_2771620.h"

template <class T>
using Unk_2771620_Vector = std::vector<T, Unk_2771620_Allocator<T>>;

// What a vector's element keeps at +0x8, 0x20 bytes: a hash (0x71005b1140
// makes a default one from an FNV-1a hash of a string), a string, and a
// reference. Its copy constructor is written out: the vector copies its words
// one at a time, where an implicit one would copy the first three together.
struct Unk_5b3080_Name {
    Unk_5b3080_Name(const Unk_5b3080_Name& other)
        : field_0(other.field_0),
          field_8(other.field_8),
          field_10(other.field_10),
          field_18(other.field_18) {}

    u64 field_0;
    const char* field_8;
    u64 field_10;
    Unk_239a418_Ref2<Unk_239a418_Handle> field_18;
};
PKMN_SIZE_ASSERT(Unk_5b3080_Name, 0x20);
PKMN_OFFSET_ASSERT(Unk_5b3080_Name, field_18, 0x18);

// A vector's element, 0x30 bytes (Unk_2398848 keeps a vector of them at
// +0x68, 0x71005b1140): what it reads first is a flatbuffers table.
struct Unk_5b3080 {
    const void* field_0;
    Unk_5b3080_Name field_8;
    u32 field_28;
    u8 field_2c;
};
PKMN_SIZE_ASSERT(Unk_5b3080, 0x30);
PKMN_OFFSET_ASSERT(Unk_5b3080, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5b3080, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_5b3080, field_2c, 0x2c);

// 0x71005b3080
template void Unk_2771620_Vector<Unk_5b3080>::reserve(size_t);
