#pragma once
// A request step base (vtable 0x710240ce98) and three steps derived from it
// (vtables 0x71024128d8, 0x7102412948 and 0x7102412a98): a weak reference to
// the step's target, and a callable each derived step holds to fall back on.
// The base's functions are in another unit (0x7101079bc0-0x7101079d60), its
// simple accessors in src/unsorted/virtual/Unk_1079c00.cpp. The derived
// steps' vf11 overrides are folded into one (0x7101079bc0). Placeholder
// types: rename and move once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// What the steps call: slot 0.
class Unk_10b96e0_Callable {
public:
    virtual void vf0();
};

class Unk_240ce88 {
public:
    // Inline: the derived steps' destructors inline it (its out-of-line copy,
    // 0x7101079c30, is the base's own).
    virtual ~Unk_240ce88() {}
    virtual bool vf2() = 0;
    virtual u32 vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    // 0x7101079d60: the target, while its handle still has references.
    virtual Unk_10b96e0_Callable* vf11() {
        Unk_239a418_Handle* handle = field_18.m_ptr;
        if (handle != nullptr && handle->field_54.load() != 0)
            return field_20;
        return nullptr;
    }

    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
    // A weak reference: the handle and its object.
    Unk_239a418_Ref<Unk_239a418_Handle> field_18;
    Unk_10b96e0_Callable* field_20;
};
PKMN_OFFSET_ASSERT(Unk_240ce88, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_240ce88, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_240ce88, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_240ce88, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_240ce88, field_20, 0x20);
static_assert(sizeof(Unk_240ce88) == 0x28, "Unk_240ce88");
