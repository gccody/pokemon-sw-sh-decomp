#pragma once
// A class on Unk_23c44f8 (src/unsorted/Unk_23c44f8.h), vtable 0x71023c2c68,
// 8 slots: a reference and two signed counts, constructed by 0x710098efb0
// (the reference and the limit). It inherits Unk_23c44f8's vf_type and
// overrides vf7 (0x710098f020, not decompiled yet). Placeholder names: rename
// once the class is known.
#include "unsorted/Unk_23c44f8.h"

class Unk_23c2c68 : public Unk_23c44f8 {
public:
    // 0x710098efb0
    Unk_23c2c68(const Unk_239a418_Ref<Unk_239a418>& ref, s32 limit);

    // Its D2 releases the reference, then runs Unk_23c44f8's, inlined; the
    // D0 and the four thunks are copies of it.
    ~Unk_23c2c68() override;
    void vf7(s32 arg) override;

    Unk_239a418_Ref<Unk_239a418> field_80;
    s32 field_88;  // the limit
    s32 field_8c;  // the count vf7 adds to
};
static_assert(sizeof(Unk_23c2c68) == 0x90, "Unk_23c2c68");
static_assert(__builtin_offsetof(Unk_23c2c68, field_80) == 0x80, "Unk_23c2c68::field_80");
static_assert(__builtin_offsetof(Unk_23c2c68, field_88) == 0x88, "Unk_23c2c68::field_88");
