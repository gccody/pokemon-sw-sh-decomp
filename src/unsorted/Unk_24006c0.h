#pragma once
// A class on Unk_23f43c8 (src/unsorted/Unk_23f43c8.h), vtable 0x71024006c0,
// 19 slots, 0x2a0 bytes, constructed by 0x7100f7cfd0 (Mystery Gift's area):
// references and three members with a callable each. 5 classes derive from it
// and release members of their own before its D2 (0x71024003a0's, for one,
// puts a u8 at 0x2a0). Placeholder names: rename once the classes are known.
//
// In the original its destructor is implicit (its D0 and thunks follow its
// last virtual function, emitted with its vtable) and too big to be inlined
// into them: they tail-call its D2. Here it's its key function instead, which
// makes the same code.
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f43c8.h"

// Its members with a callable, constructed by 0x7100f6c9c0, 0x7100f7e5c0 and
// 0x7100f7e2c0.
struct Unk_24006c0_b0 {
    u64 field_0;
    u8 field_8;
    Unk_23d4470_Callable field_10;
};
static_assert(sizeof(Unk_24006c0_b0) == 0x90, "Unk_24006c0_b0");

struct Unk_24006c0_140 {
    u8 field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
};
static_assert(sizeof(Unk_24006c0_140) == 0x90, "Unk_24006c0_140");

struct Unk_24006c0_1d0 {
    u8 field_0;
    u32 field_4;
    u32 field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    Unk_23d4470_Callable field_30;
};
static_assert(sizeof(Unk_24006c0_1d0) == 0xb0, "Unk_24006c0_1d0");
static_assert(__builtin_offsetof(Unk_24006c0_1d0, field_30) == 0x30, "Unk_24006c0_1d0::field_30");

class Unk_24006c0 : public Unk_23f43c8 {
public:
    // Its type, whose parent is Unk_23f43c8's (inlined: 0x7100f7bcb0 has four
    // guarded statics). Too big to be inlined into vf_type: vf_type, its
    // thunks and the derived classes' getters call it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_24006c0() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    virtual void vf11();
    virtual void vf12();
    // Each sets the state and passes it to vf17.
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(u32 state);
    virtual u32 vf18() { return 1; }

    u32 field_78;
    u8 field_7c;
    u32 field_80;
    u32 field_84;
    u32 field_88;
    u32 field_8c;
    u32 field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    u64 field_a8;
    Unk_24006c0_b0 field_b0;
    Unk_24006c0_140 field_140;
    Unk_24006c0_1d0 field_1d0;
    u64 field_280;
    u64 field_288;
    u64 field_290;
    Unk_239a418_Ref<Unk_239a418> field_298;
};
static_assert(sizeof(Unk_24006c0) == 0x2a0, "Unk_24006c0");
static_assert(__builtin_offsetof(Unk_24006c0, field_78) == 0x78, "Unk_24006c0::field_78");
static_assert(__builtin_offsetof(Unk_24006c0, field_98) == 0x98, "Unk_24006c0::field_98");
static_assert(__builtin_offsetof(Unk_24006c0, field_b0) == 0xb0, "Unk_24006c0::field_b0");
static_assert(__builtin_offsetof(Unk_24006c0, field_140) == 0x140, "Unk_24006c0::field_140");
static_assert(__builtin_offsetof(Unk_24006c0, field_1d0) == 0x1d0, "Unk_24006c0::field_1d0");
static_assert(__builtin_offsetof(Unk_24006c0, field_298) == 0x298, "Unk_24006c0::field_298");
