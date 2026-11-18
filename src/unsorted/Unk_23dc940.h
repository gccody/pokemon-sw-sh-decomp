#pragma once
// A class on Unk_23c1a68 (src/unsorted/Unk_23c1a68.h), vtable 0x71023dc940, 47
// slots. 16 classes derive from it without a destructor of their own (their
// D2 is its D2, their D0s and thunks tail-call it), and 12 more tail-call it
// from theirs. Placeholder names: rename once the classes are known.
#include <vector>

#include "unsorted/Unk_23c1a68.h"

// A member of Unk_23dc940 (vtable 0x71023c1a48): a vector of references. Its
// destructor is inline: its D2 (0x7100978e00) and D0 (0x7100978eb0) are
// emitted with its vtable wherever Unk_23dc940's destructor is.
class Unk_23c1a48 {
public:
    virtual ~Unk_23c1a48() {}

    std::vector<Unk_239a418_Ref<Unk_239a418>, Unk_23c1a68_Allocator<Unk_239a418_Ref<Unk_239a418>>>
        field_8;
};
static_assert(sizeof(Unk_23c1a48) == 0x38, "Unk_23c1a48");

// A member of Unk_23dc940 with a destructor of its own, out of line
// (0x71005c6850, empty; its constructor is 0x71005c6830).
class Unk_2399140 {
public:
    virtual ~Unk_2399140();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();

    u8 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
};
static_assert(sizeof(Unk_2399140) == 0x40, "Unk_2399140");

// 0x390 bytes, constructed by 0x7100c622f0.
class Unk_23dc940 : public Unk_23c1a68 {
public:
    // Its type (0x71027d6130), whose parent is Unk_23c1a68's. The copy other
    // TUs call is 0x7100c6eac0.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c1a68::Unk_GetType());
        return &type;
    }

    // Inline: its D2 (0x7100978cf0) is emitted in the TU of a class on it, its
    // D0 with its vtable. Written, not implicit: an implicit destructor is
    // `inline` to clang's inliner (a higher threshold), which then inlines the
    // D2 into the D0 and the thunks, where the original tail-calls it.
    ~Unk_23dc940() override {}
    // Overrides the interfaces' type getter (slot 6 of the primary vtable).
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7() {}
    virtual void vf8() {}
    virtual u32 vf9() { return 0; }
    // Its key function (0x7100c628b0): the functions before it are inline.
    virtual u32 vf10();
    virtual u8 vf11() { return field_1e0; }
    virtual u32 vf12();
    virtual void vf13();
    virtual u8 vf14() { return field_1e1; }
    virtual u8 vf15() { return field_1e2; }
    virtual void vf16() {
        vf45();
        if (!vf17())
            field_1e8 = 1;
    }
    virtual bool vf17() { return field_1e8 != 0; }
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual u32 vf33() { return 0; }
    virtual void vf34();
    virtual void vf35();
    virtual u32 vf36() { return 0; }
    virtual void vf37() {}
    virtual f32 vf38() { return 0; }
    virtual void vf39();
    virtual void vf40() {}
    virtual void vf41() {}
    virtual void vf42() {}
    virtual u32 vf43() { return 0; }
    virtual void vf44() {}
    virtual void vf45() {}
    virtual u32 vf46() { return 0; }

    u64 field_188;
    u64 field_190;
    u64 field_198;
    u64 field_1a0;
    u64 field_1a8;
    u64 field_1b0;
    u64 field_1b8;
    u64 field_1c0;
    u64 field_1c8;
    u64 field_1d0;
    u64 field_1d8;
    u8 field_1e0;
    u8 field_1e1;
    u8 field_1e2;
    u8 field_1e3;
    u8 field_1e4;
    u32 field_1e8;
    u64 field_1f0;
    u64 field_1f8;
    Unk_23c1a48 field_200;
    u64 field_238;
    Unk_2399140 field_240;
    u8 field_280;
    u64 field_288;
    u64 field_290;
    u64 field_298;
    u32 field_2a0;
    u64 field_2a8;
    u64 field_2b0;
    u64 field_2b8;
    u64 field_2c0;
    std::vector<u64, Unk_23c1a68_Allocator<u64>> field_2c8;
    u64 field_2f8;
    u64 field_300;
    u64 field_308;
    u64 field_310;
    u64 field_318;
    u64 field_320;
    u64 field_328;
    u64 field_330;
    u64 field_338;
    u8 field_340;
    u64 field_348;
    u64 field_350;
    u64 field_358;
    f32 field_360;
    u32 field_364;
    u32 field_368;
    u32 field_36c;
    u32 field_370;
    u32 field_374;
    u32 field_378;
    Unk_239a418_Ref<Unk_239a418> field_380;
    u64 field_388;
};
static_assert(sizeof(Unk_23dc940) == 0x390, "Unk_23dc940");
static_assert(__builtin_offsetof(Unk_23dc940, field_188) == 0x188, "Unk_23dc940::field_188");
static_assert(__builtin_offsetof(Unk_23dc940, field_1e0) == 0x1e0, "Unk_23dc940::field_1e0");
static_assert(__builtin_offsetof(Unk_23dc940, field_1e8) == 0x1e8, "Unk_23dc940::field_1e8");
static_assert(__builtin_offsetof(Unk_23dc940, field_200) == 0x200, "Unk_23dc940::field_200");
static_assert(__builtin_offsetof(Unk_23dc940, field_240) == 0x240, "Unk_23dc940::field_240");
static_assert(__builtin_offsetof(Unk_23dc940, field_2a8) == 0x2a8, "Unk_23dc940::field_2a8");
static_assert(__builtin_offsetof(Unk_23dc940, field_2c8) == 0x2c8, "Unk_23dc940::field_2c8");
static_assert(__builtin_offsetof(Unk_23dc940, field_300) == 0x300, "Unk_23dc940::field_300");
static_assert(__builtin_offsetof(Unk_23dc940, field_348) == 0x348, "Unk_23dc940::field_348");
static_assert(__builtin_offsetof(Unk_23dc940, field_360) == 0x360, "Unk_23dc940::field_360");
static_assert(__builtin_offsetof(Unk_23dc940, field_374) == 0x374, "Unk_23dc940::field_374");
static_assert(__builtin_offsetof(Unk_23dc940, field_380) == 0x380, "Unk_23dc940::field_380");
