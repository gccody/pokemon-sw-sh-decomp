#pragma once
// A class on gflib3's reference-counted object (vtable 0x71023d4470) with
// three references, five callables and a fourth reference. 63 classes derive
// from it without a destructor of their own, all in its TU
// (0x7100bba3d0-0x7100c23050): with that many callers its type getter isn't
// inlined anywhere, and each derived class's getter, inlined into its
// vf_type, calls it. Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a418.h"

// A callable, 0x80 bytes: when it holds one, its manager (+0x8) disposes of
// the storage (+0x20). Clearing it zeroes the four words first. Clear() is a
// function of its own: with the four stores in the destructor, the
// destructor of Unk_23dcdd0's vector of Unk_23c14c0s (0x7100c69620,
// src/unsorted/Unk_23dcdd0.h) computes their addresses in another order.
class Unk_23d4470_Callable {
public:
    // Empty: the four words zeroed, the storage left as it is (Unk_23c4ef0's
    // constructor, 0x71009be950, for its Unk_236d618).
    Unk_23d4470_Callable() : field_0(0), field_8(nullptr), field_10(0), field_18(0) {}
    ~Unk_23d4470_Callable() {
        if (void (*manager)(void*) = field_8) {
            Clear();
            manager(field_20);
        }
    }

    void Clear() {
        field_18 = 0;
        field_10 = 0;
        field_8 = nullptr;
        field_0 = 0;
    }

    u64 field_0;
    void (*field_8)(void*);
    u64 field_10;
    u64 field_18;
    u8 field_20[0x60];
};
static_assert(sizeof(Unk_23d4470_Callable) == 0x80, "Unk_23d4470_Callable");

class Unk_23d4470 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23d4470() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual u32 vf8();

    u8 _60[0x20];
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    u8 _98[0x28];
    Unk_23d4470_Callable field_c0;
    Unk_23d4470_Callable field_140;
    Unk_23d4470_Callable field_1c0;
    Unk_23d4470_Callable field_240;
    Unk_23d4470_Callable field_2c0;
    Unk_239a418_Ref<Unk_239a418> field_340;
};
static_assert(sizeof(Unk_23d4470) == 0x348, "Unk_23d4470");
static_assert(__builtin_offsetof(Unk_23d4470, field_80) == 0x80, "Unk_23d4470::field_80");
static_assert(__builtin_offsetof(Unk_23d4470, field_c0) == 0xc0, "Unk_23d4470::field_c0");
static_assert(__builtin_offsetof(Unk_23d4470, field_340) == 0x340, "Unk_23d4470::field_340");
