#pragma once
// An abstract class on Unk_239bb58 (src/gflib3/Unk_239bb58.h), vtable
// 0x710239b8d8, 17 slots: it overrides vf7 and adds the pure vf15 and vf16.
// Its constructor is 0x71005ff5f0. 7 classes derive from it with destructors
// of their own, which tail-call its D2. Placeholder names: rename once the
// classes are known.
#include "gflib3/Unk_239bb58.h"

class Unk_239b8d8 : public Unk_239bb58 {
public:
    // Its type, whose parent is Unk_239bb58's. The classes on it inline it
    // into their getters; its own TU keeps it out of line (0x71005ffbb0, with
    // Unk_239bb58's inlined), and vf_type and its thunks tail-call it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    // Its key function. Its D2 is too big to be inlined: the destructor
    // thunks tail-call it, and the D0s are traps (the class is abstract).
    ~Unk_239b8d8() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    virtual void vf15() = 0;
    virtual void vf16() = 0;

    u64 field_a0;
    u64 field_a8;
    // References, each but the last with a u8 after it.
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u8 field_b8;
    Unk_239a418_Ref<Unk_239a418> field_c0;
    u8 field_c8;
    Unk_239a418_Ref<Unk_239a418> field_d0;
    u8 field_d8;
    Unk_239a418_Ref<Unk_239a418> field_e0;
    u8 field_e8;
    Unk_239a418_Ref<Unk_239a418> field_f0;
    u8 field_f8;
    Unk_239a418_Ref<Unk_239a418> field_100;
    u8 field_108;
    Unk_239a418_Ref<Unk_239a418> field_110;
    u8 field_118;
    Unk_239a418_Ref<Unk_239a418> field_120;
    u8 field_128;
    Unk_239a418_Ref<Unk_239a418> field_130;
    // Copied from the constructor's argument (its reference added to).
    u64 field_138;
    u64 field_140;
    u64 field_148;
    Unk_239a418_Ref<Unk_239a418> field_150;
    // Two members the constructor zeroes and initializes (0x7101787580 and
    // 0x7101787590); nothing destroys them.
    u64 field_158;
    u64 field_160;
    u64 field_168;
    u64 field_170;
    u64 field_178;
    u64 field_180;
    u64 field_188;
    u64 field_190;
    u64 field_198;
    u64 field_1a0;
    u64 field_1a8;
    u64 field_1b0;
    f32 field_1b8;
    f32 field_1bc;
    u64 field_1c0;
    f32 field_1c8;
    f32 field_1cc;
    u64 field_1d0;
    f32 field_1d8;
    f32 field_1dc;
    Unk_239a418_Ref<Unk_239a418> field_1e0;
    Unk_239a418_Ref<Unk_239a418> field_1e8;
    u64 field_1f0;
    u32 field_1f8;
    u32 field_1fc;
    u64 field_200;
    u8 field_208;
};
static_assert(sizeof(Unk_239b8d8) == 0x210, "Unk_239b8d8");
static_assert(__builtin_offsetof(Unk_239b8d8, field_b0) == 0xb0, "Unk_239b8d8::field_b0");
static_assert(__builtin_offsetof(Unk_239b8d8, field_130) == 0x130, "Unk_239b8d8::field_130");
static_assert(__builtin_offsetof(Unk_239b8d8, field_150) == 0x150, "Unk_239b8d8::field_150");
static_assert(__builtin_offsetof(Unk_239b8d8, field_1b8) == 0x1b8, "Unk_239b8d8::field_1b8");
static_assert(__builtin_offsetof(Unk_239b8d8, field_1e0) == 0x1e0, "Unk_239b8d8::field_1e0");
static_assert(__builtin_offsetof(Unk_239b8d8, field_208) == 0x208, "Unk_239b8d8::field_208");
