#pragma once
// A battle app object on gflib3's reference-counted object (vtable
// 0x71023bdda8, on Unk_23f4318) and the 0x5a0-byte object it holds at +0x638
// (vtable 0x71023bde58): sixteen small objects of one family (their shared D2
// is the `ret` at 0x71008eb220), a reference among them. Placeholder names:
// rename once the classes are known.
#include <functional>

#include "gflib3/Unk_2399590.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_131fb20_Array.h"
#include "unsorted/Unk_23f43c8.h"

// The family's base (vtable 0x71023bd140): three words. Its vf2 (0x71008ea080)
// isn't written here, so its vtable comes out with it; its destructor is
// empty and inline, every class of the family gets it as its D2.
class Unk_23bd130 {
public:
    Unk_23bd130() : field_8(0), field_10(0), field_18(0) {}
    virtual ~Unk_23bd130() {}
    virtual void vf2();

    u64 field_8;
    u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23bd130) == 0x20, "Unk_23bd130");

// The family's classes from game/unk_8bf520 (vtables 0x71023bd168,
// 0x71023bd190, 0x71023bd1b8, 0x71023bd1e0, 0x71023bd208): their vf2s are out
// of line there.
class Unk_23bd158 : public Unk_23bd130 {
public:
    Unk_23bd158() : field_20(0) {}
    void vf2() override;

    u64 field_20;
};
static_assert(sizeof(Unk_23bd158) == 0x28, "Unk_23bd158");

class Unk_23bd180 : public Unk_23bd130 {
public:
    Unk_23bd180() : field_20(0) {}
    void vf2() override;

    u64 field_20;
};
static_assert(sizeof(Unk_23bd180) == 0x28, "Unk_23bd180");

class Unk_23bd1a8 : public Unk_23bd130 {
public:
    Unk_23bd1a8() : field_20(0) {}
    void vf2() override;

    u64 field_20;
};
static_assert(sizeof(Unk_23bd1a8) == 0x28, "Unk_23bd1a8");

class Unk_23bd1d0 : public Unk_23bd130 {
public:
    Unk_23bd1d0() : field_20(0) {}
    void vf2() override;

    u64 field_20;
};
static_assert(sizeof(Unk_23bd1d0) == 0x28, "Unk_23bd1d0");

// Part of Unk_23bd1f8: a word and a 32-bit value (it's padded).
struct Unk_23bd1f8_Pair {
    Unk_23bd1f8_Pair() : field_0(0), field_8(0) {}

    u64 field_0;
    u32 field_8;
};
static_assert(sizeof(Unk_23bd1f8_Pair) == 0x10, "Unk_23bd1f8_Pair");

class Unk_23bd1f8 : public Unk_23bd130 {
public:
    Unk_23bd1f8() : field_20(0), field_28(0), field_30(), field_38(0), field_50(0), field_54(0) {}
    void vf2() override;

    u32 field_20;
    u64 field_28;
    u8 field_30[5];
    u64 field_38;
    Unk_23bd1f8_Pair field_40;
    u32 field_50;
    u8 field_54;
};
static_assert(sizeof(Unk_23bd1f8) == 0x58, "Unk_23bd1f8");
PKMN_OFFSET_ASSERT(Unk_23bd1f8, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_23bd1f8, field_54, 0x54);

// The battle app's classes of the family (vtable 0x71023bdd80): its vf2
// (0x710090e2d0, empty) is out of line, the others' vtables and D0s come out
// where they're constructed.
class Unk_23bdd70 : public Unk_23bd130 {
public:
    void vf2() override;
};
static_assert(sizeof(Unk_23bdd70) == 0x20, "Unk_23bdd70");

// vtable 0x71023bde78
class Unk_23bde68 : public Unk_23bdd70 {
public:
    Unk_23bde68() : field_20(0), field_28(0), field_30(0), field_38(0) {}

    u64 field_20;
    u32 field_28;
    u64 field_30;
    u16 field_38;
};
static_assert(sizeof(Unk_23bde68) == 0x40, "Unk_23bde68");

// vtable 0x71023bdea0
class Unk_23bde90 : public Unk_23bdd70 {
public:
    Unk_23bde90() : field_20(0), field_28(0), field_30(0), field_38(0), field_3a(0) {}

    u64 field_20;
    u8 field_28;
    u64 field_30;
    u16 field_38;
    u8 field_3a;
};
static_assert(sizeof(Unk_23bde90) == 0x40, "Unk_23bde90");

// vtable 0x71023bdec8
class Unk_23bdeb8 : public Unk_23bdd70 {
public:
    Unk_23bdeb8() : field_20(0), field_24(0), field_26(0), field_28(0), field_2a(0), field_2c(0) {}

    u32 field_20;
    u8 field_24;
    u16 field_26;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
};
static_assert(sizeof(Unk_23bdeb8) == 0x30, "Unk_23bdeb8");

// vtable 0x71023bdef0
class Unk_23bdee0 : public Unk_23bdd70 {
public:
    Unk_23bdee0() : field_20(0), field_24(0), field_28(0), field_2c(0) {}

    u8 field_20;
    u32 field_24;
    u32 field_28;
    u16 field_2c;
};
static_assert(sizeof(Unk_23bdee0) == 0x30, "Unk_23bdee0");

// What Unk_23bdf08 holds 48 of.
struct Unk_23bdf08_Entry {
    Unk_23bdf08_Entry() : field_0(0), field_4(0) {}

    u16 field_0;
    u32 field_4;
};
static_assert(sizeof(Unk_23bdf08_Entry) == 0x8, "Unk_23bdf08_Entry");

// vtable 0x71023bdf18
class Unk_23bdf08 : public Unk_23bdd70 {
public:
    Unk_23bdf08() : field_20(), field_1b0(0) {}

    u8 field_20[14];
    Unk_23bdf08_Entry field_30[48];
    u16 field_1b0;
};
static_assert(sizeof(Unk_23bdf08) == 0x1b8, "Unk_23bdf08");
PKMN_OFFSET_ASSERT(Unk_23bdf08, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_23bdf08, field_1b0, 0x1b0);

// vtable 0x71023bdf40
class Unk_23bdf30 : public Unk_23bdd70 {
public:
    Unk_23bdf30() : field_20(0), field_28(0), field_2c(0), field_30(0), field_38(0), field_3a(1) {}

    u64 field_20;
    u32 field_28;
    u8 field_2c;
    u64 field_30;
    u16 field_38;
    u8 field_3a;
};
static_assert(sizeof(Unk_23bdf30) == 0x40, "Unk_23bdf30");

// vtable 0x71023bdf68
class Unk_23bdf58 : public Unk_23bdd70 {
public:
    Unk_23bdf58() : field_20(0), field_24(0), field_28(0) {}

    u16 field_20;
    u32 field_24;
    u16 field_28;
};
static_assert(sizeof(Unk_23bdf58) == 0x30, "Unk_23bdf58");

// vtable 0x71023bdf90: a reference (its D2 0x710090f2b0, D0 0x710090f300).
class Unk_23bdf80 : public Unk_23bdd70 {
public:
    Unk_23bdf80() : field_d0(0) {}

    Unk_239a418_Ref<Unk_239a418> field_20;
    u8 field_28[0xa8];
    u16 field_d0;
};
static_assert(sizeof(Unk_23bdf80) == 0xd8, "Unk_23bdf80");
PKMN_OFFSET_ASSERT(Unk_23bdf80, field_d0, 0xd0);

// vtable 0x71023bdfb8
class Unk_23bdfa8 : public Unk_23bdd70 {
public:
    Unk_23bdfa8() : field_20(0) {}

    u16 field_20;
};
static_assert(sizeof(Unk_23bdfa8) == 0x28, "Unk_23bdfa8");

// vtable 0x71023bde58, constructed at 0x710090e980.
class Unk_23bde48 {
public:
    Unk_23bde48();
    virtual ~Unk_23bde48();

    Unk_23bd1f8 field_8;
    Unk_23bde68 field_60;
    Unk_23bde90 field_a0;
    Unk_23bdeb8 field_e0;
    Unk_23bdee0 field_110;
    Unk_23bdf08 field_140;
    Unk_23bd130 field_2f8;
    u64 field_318;
    u64 field_320;
    u64 field_328;
    u64 field_330;
    u64 field_338;
    u8 field_340;
    Unk_23bd158 field_348;
    Unk_23bd180 field_370;
    Unk_23bd1a8 field_398;
    Unk_23bd1d0 field_3c0;
    Unk_23bdd70 field_3e8;
    u64 field_408;
    u8 field_410[13];
    u64 field_420;
    u16 field_428;
    u8 field_42a;
    Unk_23bdf30 field_430;
    Unk_23bdf58 field_470;
    Unk_23bdf80 field_4a0;
    Unk_23bdfa8 field_578;
};
static_assert(sizeof(Unk_23bde48) == 0x5a0, "Unk_23bde48");
PKMN_OFFSET_ASSERT(Unk_23bde48, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_3e8, 0x3e8);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_410, 0x410);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_42a, 0x42a);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_430, 0x430);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_470, 0x470);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(Unk_23bde48, field_578, 0x578);

// What the array at +0x3d0 holds (8 bytes, 4-aligned: it frees with
// alignment 4).
struct Unk_23bdd98_Entry {
    u32 field_0;
    u32 field_4;
};

// vtable 0x71023bdda8 (type in src/unsorted/types/Unk_90e070.cpp): references,
// a callable, a function, an array and the object above. Its destructor is
// its key function; vf_type is out of line there.
class Unk_23bdd98 : public Unk_23f4318 {
public:
    ~Unk_23bdd98() override;
    const Unk_239a418_Type* vf_type() override;

    u8 _60[0x10];
    Unk_239a418_Ref<Unk_239a418> field_70;
    u8 _78[0x10];
    Unk_239a418_Ref<Unk_239a418> field_88;
    u64 field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    u64 field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    u64 field_b0;
    Unk_239a418_Ref<Unk_239a418> field_b8;
    u8 _c0[0xc0];
    Unk_239a418_Ref<Unk_239a418> field_180;
    u8 _188[0x28];
    Unk_239a418_Ref<Unk_239a418> field_1b0;
    Unk_239a418_Ref<Unk_239a418> field_1b8;
    u8 _1c0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_1d8;
    Unk_239a418_Ref<Unk_239a418> field_1e0;
    u8 _1e8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_200;
    u8 _208[0x68];
    Unk_2399590_Callable field_270;
    Unk_239a418_Ref<Unk_239a418> field_2f0;
    u8 _2f8[0x48];
    Unk_239a418_Ref<Unk_239a418> field_340;
    u8 _348[0x18];
    Unk_239a418_Ref<Unk_239a418> field_360;
    u8 _368[0x18];
    Unk_239a418_Ref<Unk_239a418> field_380;
    u8 _388[0x18];
    std::function<void()> field_3a0;
    Unk_131fb20_Array<Unk_23bdd98_Entry> field_3d0;
    u8 _430[0x208];
    Unk_23bde48 field_638;
};
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_270, 0x270);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_2f0, 0x2f0);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_3a0, 0x3a0);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_638, 0x638);
