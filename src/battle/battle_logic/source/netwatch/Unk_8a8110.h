#pragma once
// The object the battle logic's view of the battle (Unk_23b9048) owns at
// +0x78, 0x48 bytes, with the two objects it makes: a copy of a battle module
// (vtable 0x71023ac8d8, 0x318 bytes) and an object of 0x190 bytes that reads
// it. src/battle/battle_logic/source/netwatch/Unk_8a8e30.h declares the same
// class, with what slots 252 to 279 of Unk_23b9048 show of it; this
// declaration has what its constructor shows. Placeholder names: rename once
// the classes are known.
#include <memory>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f4660.h"

// What the battle module's copy is made from: the allocator and the module.
struct Unk_23ac8d8_Args {
    Unk_239a418_Allocator* field_0;
    void* field_8;
};
PKMN_SIZE_ASSERT(Unk_23ac8d8_Args, 0x10);

// The battle module's copy (vtable 0x71023ac8d8: its two destructors only).
class Unk_23ac8d8 {
public:
    explicit Unk_23ac8d8(const Unk_23ac8d8_Args& args);  // 0x71007fd000, not decompiled yet
    virtual ~Unk_23ac8d8();                              // 0x71007fe3d0, not decompiled yet

    u8 _8[0x310];
};
PKMN_SIZE_ASSERT(Unk_23ac8d8, 0x318);

// What the second object is made from: the allocator, the module and the
// module's copy.
struct Unk_7dfde0_Args {
    Unk_239a418_Allocator* field_0;
    void* field_8;
    Unk_23ac8d8* field_10;
};
PKMN_SIZE_ASSERT(Unk_7dfde0_Args, 0x18);

// The second object: its destructor is out of line, not virtual.
class Unk_7dfde0 {
public:
    explicit Unk_7dfde0(const Unk_7dfde0_Args& args);  // 0x71007e7c20, not decompiled yet
    ~Unk_7dfde0();                                     // 0x71007dfde0, not decompiled yet

    void* field_0;
    Unk_23ac8d8* field_8;
    u8 _10[0x180];
};
PKMN_SIZE_ASSERT(Unk_7dfde0, 0x190);

// What the object is made from: the allocator and two of the battle's
// modules (+0x58 and +0x68).
struct Unk_8a82e0_Args {
    Unk_239a418_Allocator* field_0;
    void* field_8;
    void* field_10;
};
PKMN_SIZE_ASSERT(Unk_8a82e0_Args, 0x18);

class Unk_8a82e0 {
public:
    explicit Unk_8a82e0(const Unk_8a82e0_Args& args);                 // 0x71008a82e0
    void Unk_8a8330(Unk_239a418_Allocator* allocator, void* module);  // 0x71008a8330
    void Unk_8a8440(Unk_239a418_Allocator* allocator, void* module);  // 0x71008a8440

    void* field_0;
    std::unique_ptr<Unk_23ac8d8, Unk_23f4660_Deleter> field_8;
    std::unique_ptr<Unk_7dfde0, Unk_23f4660_Deleter> field_28;
};
PKMN_SIZE_ASSERT(Unk_8a82e0, 0x48);
PKMN_OFFSET_ASSERT(Unk_8a82e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8a82e0, field_28, 0x28);
