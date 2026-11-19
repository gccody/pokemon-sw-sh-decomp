#pragma once
// A class on gflib3's reference-counted object (vtable 0x7102434918) with two
// callbacks: vf7 asks the first (with the address of its field_e0) and
// answers yes when there's none, vf8 tells the second; 0x100 bytes, the last
// 0x20 of which its constructor leaves alone (16-aligned for the callbacks;
// a derived class has a vector at +0x108). Its destructor is implicit,
// inlined into its derived classes'. Placeholder names: rename once
// the class is known.
#include <functional>

#include "gflib3/Unk_239a418.h"

// What the first callback is given.
struct Unk_2434918_e0 {
    u8 _0[0x20];
};

class Unk_2434918 : public Unk_239a418 {
public:
    Unk_2434918(u64 arg1, const u64* arg2);

    static const Unk_239a418_Type* Unk_GetType();

    // The key function: declared before the type getter's override.
    virtual bool vf7(bool value);
    const Unk_239a418_Type* vf_type() override;
    virtual void vf8(bool value);
    virtual u32 vf9();
    virtual u32 vf10();
    virtual u32 vf11();

    u64 field_60;
    u64 field_68;
    u64 field_70;  // a hash, FNV-1a of "" when constructed
    u64 field_78;
    std::function<bool(Unk_2434918_e0*, bool)> field_80;
    std::function<void(bool)> field_b0;
    Unk_2434918_e0 field_e0;
};
static_assert(sizeof(Unk_2434918) == 0x100, "Unk_2434918");
static_assert(__builtin_offsetof(Unk_2434918, field_80) == 0x80, "Unk_2434918::field_80");
static_assert(__builtin_offsetof(Unk_2434918, field_b0) == 0xb0, "Unk_2434918::field_b0");
static_assert(__builtin_offsetof(Unk_2434918, field_e0) == 0xe0, "Unk_2434918::field_e0");
