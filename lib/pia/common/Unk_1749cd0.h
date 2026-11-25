#pragma once
// A Pia object holding three addresses (at 0x8, 0x28, 0x48) and flags at 0x78.
// Its getters are in lib/nx_middleware/leaf/Unk_1721740.cpp (0x7101749cd0 on).
// Placeholder names: each class after its constructor or first member.
#include "pia/common/Unk_165e060.h"

namespace nn {
namespace pia {

// A polymorphic 0x20-byte value: 16 bytes compared with memcmp
// (0x7101653860) and a u16. Constructor 0x7101652c70.
class Unk_1652c70 {
public:
    virtual ~Unk_1652c70();

    Unk_1652c70& operator=(const Unk_1652c70& other);  // copies both fields

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

// A polymorphic wrapper of one Unk_1652c70.
class Unk_165fb30 {
public:
    Unk_165fb30();
    virtual ~Unk_165fb30();

    Unk_165e060 Unk_165fd90(const Unk_1652c70& value);  // sets field_8

    Unk_1652c70 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165fb30, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_165fb30, 0x28);

class Unk_1749cf0 {
public:
    Unk_165fb30 Unk_1749cf0_get() const;
    bool Unk_1749e60(const Unk_1749cf0& other) const;
    bool Unk_1749e70(const Unk_1749cf0& other) const;
    void Unk_1749f00(const Unk_1652c70& value);
    void Unk_1749f10(const Unk_1652c70& value);
    void Unk_1749f20(const Unk_1652c70& value);
    void Unk_1749f60(u32 value);

    u8 _0[0x8];
    Unk_1652c70 field_8;
    Unk_1652c70 field_28;
    Unk_1652c70 field_48;
    u64 field_68;
    u32 field_70;
    u32 field_74;
    u8 field_78;  // bits 0-1, 2-3 and 4-7: three values
    u8 field_79;
    u8 field_7a;
    u8 field_7b;
};
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_74, 0x74);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_79, 0x79);
PKMN_OFFSET_ASSERT(Unk_1749cf0, field_7b, 0x7b);

}  // namespace pia
}  // namespace nn
