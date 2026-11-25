#pragma once
// A class on Unk_23f43c8 (src/unsorted/Unk_23f43c8.h), vtable 0x7102423d30
// (21 slots, 0xa0 bytes), in game/pokecamp: three interfaces of its own
// (+0x78, +0x80, +0x88) and two references. Its destructor is inline: a class
// on it without members to destroy has its D2 (0x7101216a70) in slot 0, and
// its D0 and destructor thunks are copies of it (Unk_2425e60's, in
// src/unsorted/Unk_1240830.cpp). Its type getter (0x7101217300) and vf_type
// (0x7101216b70) are out of line. Placeholder names, after the vtables.
#include "unsorted/Unk_23f43c8.h"

// The interfaces, named after their vtables (Unk_2423d30 implements their
// slots; not declared here).
class Unk_2423e50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class Unk_2423e98 {
public:
    virtual void vf0();
};

class Unk_2423eb0 {
public:
    virtual void vf0();
};

class Unk_2423d30 : public Unk_23f43c8, public Unk_2423e50, public Unk_2423e98, public Unk_2423eb0 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;  // 0x7101214fa0
    u32 vf8() override;   // 0x71012150e0
    void vf9() override;  // 0x7101215360
    virtual void vf11();  // 0x7101215490
    virtual void vf12();  // 0x71012154d0
    virtual void vf13();  // 0x71012159e0
    virtual void vf14();  // 0x7101215a20
    virtual void vf15();  // 0x7101215b80
    virtual void vf16();  // 0x7101215bc0
    virtual void vf17();  // 0x7101215d20
    virtual void vf18();  // 0x7101215df0
    virtual void vf19();  // 0x7101216850
    virtual void vf20();  // 0x7101216a50

    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
};
static_assert(sizeof(Unk_2423d30) == 0xa0, "Unk_2423d30");
PKMN_OFFSET_ASSERT(Unk_2423d30, field_90, 0x90);
