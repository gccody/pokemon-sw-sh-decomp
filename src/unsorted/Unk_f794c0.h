#pragma once
// A view of the mystery gift app (game/mystery), vtable 0x7102400138: a class
// on the attention view (Unk_23f5fa8, vtable 0x71023f5fa8) with an interface
// at +0x5e8 whose calls it forwards to the object at +0x5f0, and 41
// references. Constructed by Unk_790260_Owner::Create<Unk_2400128>
// (0x7100f62300). Placeholder names: rename once the classes are known.
//
// Its type getter (vf_type, 0x7100f798d0) is in src/unsorted/types/Unk_f798d0.cpp
// (generated), which declares the class on Unk_239a418 alone.
#include <types.h>

#include "unsorted/Unk_23f4660.h"

// What an attention view shows (0x10 bytes): a kind and the message (as in
// src/contents/common/framework.h).
struct Unk_eb5fb0_Params {
    Unk_eb5fb0_Params() : field_0(0), field_8(nullptr) {}

    u32 field_0;
    Unk_239a418* field_8;
};
static_assert(sizeof(Unk_eb5fb0_Params) == 0x10, "Unk_eb5fb0_Params");

// The attention view. src/contents/common/framework.h declares it without its
// members, which this class needs to lay out its own: its vf10 sets field_5e0
// (0x7100eb5f60), and its D2 is Unk_23f4660's.
class Unk_23f5fa8 : public Unk_23f4660 {
public:
    // Shows a message (0x7100eb5fb0).
    void Unk_eb5fb0(const Unk_eb5fb0_Params& params);

    u64 _5d0[2];
    bool field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_23f5fa8, _5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_23f5fa8, field_5e0, 0x5e0);

// Slots 11 and 12 of the attention view (0x7100eb5f70, 0x7100eb5f90). They
// take a state where Unk_23f4660's header declares none, so they're written
// as free functions over the object.
void Unk_eb5f70(Unk_23f5fa8* self, u32 state);
void Unk_eb5f90(Unk_23f5fa8* self, u32 state);

// What Unk_2400128 forwards its interface's calls to (+0x5f0).
class Unk_2400128_5f0 {
public:
    virtual void vf0(void* arg);
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// Its interface at +0x5e8 (vtable 0x7102400258). Named after the primary
// vtable's slots its overrides get.
class Unk_2400128_5e8 {
public:
    virtual void vf17(void* arg) = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual ~Unk_2400128_5e8() {}
};

class Unk_2400128 : public Unk_23f5fa8, public Unk_2400128_5e8 {
public:
    ~Unk_2400128() override;
    const Unk_239a418_Type* vf_type() override;

    // 0x7100f795c0 (and its thunk 0x7100f79c60)
    void vf17(void* arg) override {
        if (field_5f0)
            field_5f0->vf0(arg);
    }
    // 0x7100f79510 (and its thunk 0x7100f79c80)
    void vf18() override {
        if (field_5f0)
            field_5f0->vf1();
    }
    // 0x7100f79940 (and its thunk 0x7100f79ca0)
    void vf19() override {
        if (field_5f0)
            field_5f0->vf2();
    }
    // 0x7100f79960 (and its thunk 0x7100f79cc0)
    void vf20() override {
        if (field_5f0)
            field_5f0->vf3();
    }

    void Unk_f795e0(u32 index);

    Unk_2400128_5f0* field_5f0;
    Unk_239a418_Ref<Unk_239a418> field_5f8[41];
    bool field_740;
    u64 field_748;
};
PKMN_OFFSET_ASSERT(Unk_2400128, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_2400128, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_2400128, field_740, 0x740);
PKMN_OFFSET_ASSERT(Unk_2400128, field_748, 0x748);

// Slots 11 and 12.
void Unk_f794c0(Unk_2400128* self, u32 state);
void Unk_f79530(Unk_2400128* self, u32 state);
