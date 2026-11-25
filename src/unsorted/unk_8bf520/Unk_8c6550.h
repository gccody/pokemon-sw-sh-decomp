#pragma once
// The abstract class on gflib3's Unk_239a4c0 with vtable 0x71023bb238
// (Unk_23bb228; src/unsorted/virtual/Unk_8c67d0.cpp has its destructors, and
// its thunks are emitted with its vtable there), 0x68 bytes: a walk over the
// set bits of a mask in a range of bit numbers, 14 when it's done. Its
// constructor is src/unsorted/unk_8bf520/Unk_8c6550.cpp, the walk
// src/unsorted/unk_8bf520/Unk_8c6810.cpp. Placeholder names: rename once the
// class is known.
#include <types.h>

#include "gflib3/Unk_239a4c0.h"

class Unk_23bb228 : public Unk_239a4c0 {
public:
    Unk_23bb228(u8 arg1, u32 first, u32 last, u32 mask);
    ~Unk_23bb228() override;
    virtual void vf5() = 0;
    virtual u8 vf6() = 0;

    // The first set bit from field_54, or field_5c's next one.
    void Unk_8c6830();
    void Unk_8c6870();
    bool Unk_8c68b0() const;

    s32 field_54;
    s32 field_58;
    s32 field_5c;
    u32 field_60;
    u8 field_64;
};
static_assert(sizeof(Unk_23bb228) == 0x68, "Unk_23bb228");
PKMN_OFFSET_ASSERT(Unk_23bb228, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_23bb228, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_23bb228, field_64, 0x64);
