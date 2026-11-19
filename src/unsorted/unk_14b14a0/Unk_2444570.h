#pragma once
// An abstract node of a tree of UI objects (vtable 0x7102444570), on gflib3's
// reference-counted object: its parent (+0x68, not referenced), its next
// sibling and its first child (references), flags, and a reference to the
// object that does the work (+0x98, given the address of +0x88). vf26 appends
// a child; vf10 shows the node (the whole tree is hidden first), telling it
// and then each of its ancestors. Placeholder names: rename once the classes
// are known.
#include "gflib3/Unk_239a418.h"

// What the node hands its work to: its own primary base, and gflib3's
// reference-counted interface at +0x48 (it is held by a reference).
class Unk_2444570_98_Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u64* arg1, u64 arg2);
    virtual void vf6(u64* arg1);
    virtual void vf7(u64* arg1, u64 arg2);

    u8 _8[0x40];
};

class Unk_2444570_98 : public Unk_2444570_98_Base, public Unk_239a458 {};

class Unk_2444570 : public Unk_239a418 {
public:
    Unk_2444570();
    ~Unk_2444570() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7(u64 arg);
    virtual void vf8();
    virtual void vf9(u64 arg);
    virtual void vf10();
    virtual void vf11(Unk_2444570* node, u32 arg);
    virtual void vf12() = 0;
    virtual void vf13();
    virtual void vf14();
    virtual void vf15() = 0;
    virtual void vf16();
    virtual u32 vf17();
    virtual void vf18(bool value) = 0;
    virtual void vf19(bool value) = 0;
    virtual void vf20(bool value) = 0;
    virtual void vf21(bool value, Unk_2444570* node);
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual u32 vf24();
    virtual u8 vf25();
    virtual void vf26(Unk_239a418_Ref<Unk_2444570>& child);

    Unk_2444570* GetRoot() {
        Unk_2444570* node = this;
        while (node->field_68)
            node = node->field_68;
        return node;
    }

    u64 field_60;
    Unk_2444570* field_68;
    Unk_239a418_Ref<Unk_2444570> field_70;
    Unk_239a418_Ref<Unk_2444570> field_78;
    bool field_80;
    u8 field_81;
    bool field_82;
    bool field_83;
    u8 field_84;
    u8 field_85;
    u64 field_88;
    u64 field_90;
    Unk_239a418_Ref<Unk_2444570_98> field_98;
};
static_assert(sizeof(Unk_2444570) == 0xa0, "Unk_2444570");
static_assert(__builtin_offsetof(Unk_2444570, field_68) == 0x68, "Unk_2444570::field_68");
static_assert(__builtin_offsetof(Unk_2444570, field_80) == 0x80, "Unk_2444570::field_80");
static_assert(__builtin_offsetof(Unk_2444570, field_88) == 0x88, "Unk_2444570::field_88");
static_assert(__builtin_offsetof(Unk_2444570, field_98) == 0x98, "Unk_2444570::field_98");

// A tree walk (0x71014e2020), not decompiled yet.
void Unk_14e2020(Unk_2444570* node, bool arg);
