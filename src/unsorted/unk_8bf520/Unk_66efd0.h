#pragma once
// Scope: common
// The script machine the commands of 0x71023a0500 ("float", ...) run on, as
// far as its math commands use it.

#include <math.h>
#include <types.h>

// The loaded script: the offset of its data block is at +0x10.
struct Unk_66efd0_Header {
    u8 _0[0x10];
    s32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_66efd0_Header, field_10, 0x10);

struct Unk_66efd0 {
    Unk_66efd0_Header* field_0;
    u8 _8[0x8];
    u8* field_10;  // the data block, or null for the one in the header's
    u8 _18[0x28];
    s64 field_40;  // the offsets from field_40 up to field_50 aren't strings
    u8 _48[0x8];
    s64 field_50;
    s64 field_58;  // the end of the data block
    u8 _60[0x44];
    u32 field_a4;  // the error code
};
PKMN_OFFSET_ASSERT(Unk_66efd0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_66efd0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_66efd0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_66efd0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_66efd0, field_a4, 0xa4);

// A command's argument: a 64-bit slot, an integer or a double.
union Unk_66efd0_Arg {
    s64 i;
    f64 f;
};
PKMN_SIZE_ASSERT(Unk_66efd0_Arg, 0x8);

// A command's arguments (the first, field_0, isn't read here).
struct Unk_66efd0_Args {
    Unk_66efd0_Arg field_0;
    Unk_66efd0_Arg field_8;
    Unk_66efd0_Arg field_10;
};
PKMN_OFFSET_ASSERT(Unk_66efd0_Args, field_10, 0x10);

// A double as the command's result.
inline s64 Unk_66efd0_Result(f64 value) {
    Unk_66efd0_Arg result;
    result.f = value;
    return result.i;
}

// The angle of a trigonometric command (field_8) in radians: field_10 says
// whether it's in radians, degrees (1) or gradians (2).
inline f64 Unk_66efd0_Radians(const Unk_66efd0_Args* args) {
    f64 angle = args->field_8.f;
    switch (static_cast<s32>(args->field_10.i)) {
        case 1:
            return angle * M_PI / 180.0;
        case 2:
            return angle * M_PI / 200.0;
    }
    return angle;
}
