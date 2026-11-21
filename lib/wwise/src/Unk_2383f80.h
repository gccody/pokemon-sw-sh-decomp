#pragma once
// A source with the vtable 0x7102383f80 (on the class of 0x7102384dd0).
// Written from the executable. Placeholder names.
#include "Unk_3dd7b0.h"

// Its constructor (0x71003cbc30) is not here: the table of functions has it
// without a parameter, which is how the matched constructors of the classes
// on it call it, and the playing context it passes on to the constructor of
// the base class is a parameter.
class Unk_2383f80 {
public:
    Unk_2383f80();

    void** field_0;  // vptr
    u64 field_8;
    void* field_10;  // data of its own (the stream source)
    Unk_3dd7b0_Ctx* field_18;
    u8 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u8 _3c[4];
    u8 field_40[0x10];
    u32 field_50;
    u16 field_54;
};
PKMN_OFFSET_ASSERT(Unk_2383f80, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_2383f80, field_54, 0x54);
