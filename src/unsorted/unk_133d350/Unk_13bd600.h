#pragma once
// Script commands of game/unk_133d350 (0x71013bd600-0x71013be4e8), entries of
// the command table 0x71013bd600 returns: as those of
// src/field/content/Unk_13f1360.h, they take the script and its arguments,
// and most look field objects up by an id or a name's hash. Placeholder
// names: rename once the classes are known.
#include <arm_neon.h>

#include <types.h>

#include "field/content/Unk_13f1360.h"

// A command's arguments: 64-bit slots, each an integer or a double (the
// first, the size of the rest, isn't read).
union Unk_13bd600_Arg {
    s64 i;
    f64 f;
};
PKMN_SIZE_ASSERT(Unk_13bd600_Arg, 0x8);

// What the script's +0x84 points to: what it waits for is at +0x60.
struct Unk_13bd600_Owner;

// The script the commands are given: a packed struct, its owner at +0x84.
struct __attribute__((packed)) Unk_13bd600_Script {
    u8 _0[0x84];
    Unk_13bd600_Owner* field_84;
};
PKMN_OFFSET_ASSERT(Unk_13bd600_Script, field_84, 0x84);

// 0x71013b12d0: the hash (FNV-1a) of the script's string at `address`.
u64 Unk_13b12d0(Unk_13bd600_Script* self, s64 address);

// The manager's own virtual functions (Unk_13f1360_Manager starts with a
// vptr).
class Unk_13bd600_Manager {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual bool vf10();
    virtual void vf11();
    virtual void vf12();
    virtual bool vf13(bool value);
};

inline Unk_13bd600_Manager* Unk_13bd600_GetManager() {
    return reinterpret_cast<Unk_13bd600_Manager*>(Unk_27d6158);
}

// A double as an argument slot: what the commands that answer a number
// return.
inline s64 Unk_13bd600_ToArg(f64 value) {
    Unk_13bd600_Arg arg;
    arg.f = value;
    return arg.i;
}

// A position or a rotation: a vector of four floats, copied through two
// general registers (the game is built with -mno-implicit-float).
struct Unk_13bd600_Vector {
    float32x4_t v;
};
PKMN_SIZE_ASSERT(Unk_13bd600_Vector, 0x10);
