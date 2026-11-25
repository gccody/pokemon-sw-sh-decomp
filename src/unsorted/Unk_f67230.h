#pragma once
// The mystery gift app's views (game/mystery): classes on Unk_23f4660 with a
// common base, Unk_27e15e0 (named after its type, 0x71027e15e0, the parent of
// its derived classes' types), 0x5f0 bytes. Four classes derive from it
// (vtables 0x71023ff280, 0x71023ff3e0, 0x7102400570 and 0x7102400910): their
// vtables share its destructor (0x7100f673c0, inline: their D0s and thunks
// inline it, a tail call to Unk_23f4660's) and its slots 11, 12 and 16-20,
// emitted with the first of them. Placeholder names: rename once the classes
// are known.
//
// Its slots 11, 12 and 15 take arguments where Unk_23f4660's header declares
// none, so they're written as free functions over the object (below).
#include <types.h>

#include "unsorted/Unk_23f4660.h"

// What Unk_27e15e0 forwards its interface's calls to (+0x5d8).
class Unk_27e15e0_5d8 {
public:
    virtual void vf0(void* arg);
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// Its interface at +0x5d0 (its own vtable isn't known: its derived classes'
// are 0x71023ff3a0 and 0x71023ff500). Named after the primary vtable's slots
// its overrides get.
class Unk_27e15e0_5d0 {
public:
    virtual void vf17(void* arg) = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual ~Unk_27e15e0_5d0() {}
};

class Unk_27e15e0 : public Unk_23f4660, public Unk_27e15e0_5d0 {
public:
    // 0x7100f67690, not written here: inline in the original (its statics are
    // weak, reached through the GOT), the copy its derived classes' type
    // getters call (src/unsorted/types/Unk_f673e0.cpp, generated) is emitted
    // with them: static Unk_239a418_Type type(Unk_23f4660::Unk_GetType()).
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_27e15e0() override {}
    // 0x7100f67830
    u32 vf16() override { return 1; }
    // 0x7100f67450 (and its thunk 0x7100f675f0)
    void vf17(void* arg) override {
        if (field_5d8)
            field_5d8->vf0(arg);
    }
    // 0x7100f67470 (and its thunk 0x7100f67610)
    void vf18() override {
        if (field_5d8)
            field_5d8->vf1();
    }
    // 0x7100f67490 (and its thunk 0x7100f67630)
    void vf19() override {
        if (field_5d8)
            field_5d8->vf2();
    }
    // 0x7100f674b0 (and its thunk 0x7100f67650)
    void vf20() override {
        if (field_5d8)
            field_5d8->vf3();
    }

    Unk_27e15e0_5d8* field_5d8;
    u32 field_5e0;
    u8 _5e4[0xc];
};
static_assert(sizeof(Unk_27e15e0) == 0x5f0, "Unk_27e15e0");
static_assert(__builtin_offsetof(Unk_27e15e0, field_5d8) == 0x5d8, "Unk_27e15e0::field_5d8");
static_assert(__builtin_offsetof(Unk_27e15e0, field_5e0) == 0x5e0, "Unk_27e15e0::field_5e0");

// vtable 0x71023ff280, constructed by 0x7100f60390.
class Unk_23ff270 : public Unk_27e15e0 {
public:
    ~Unk_23ff270() override;
    const Unk_239a418_Type* vf_type() override;

    void Unk_f67340();
    void Unk_f67380();
};

// vtable 0x71023ff3e0, constructed by 0x7100f61fa0.
class Unk_23ff3d0 : public Unk_27e15e0 {
public:
    ~Unk_23ff3d0() override;
    const Unk_239a418_Type* vf_type() override;

    void Unk_f67a20();
    void Unk_f67a60();
};

// What slot 15 fills in: the layout's file name (and a flag it clears).
struct Unk_27e15e0_Layout {
    Unk_23f4660_Name field_0;
    u8 _30[0x30];
    bool field_60;
};
PKMN_OFFSET_ASSERT(Unk_27e15e0_Layout, field_60, 0x60);

// Shows or hides a view (and its children).
void Unk_e806b0(Unk_23f4660* view, bool visible, bool children);

// A name for a file path (0x7100c46830).
Unk_23f4660_Name Unk_c46830(const char* const& path);

// Moves a name into another: what `dst` held goes first, its string object
// only when it has characters (as its Reset).
inline void Unk_27e15e0_MoveName(Unk_23f4660_Name& dst, Unk_23f4660_Name&& src) {
    dst.Reset();
    dst.field_8 = src.field_8;
    dst.field_10 = src.field_10;
    dst.field_18 = src.field_18;
    dst.field_20 = src.field_20;
    src.field_20 = nullptr;
    dst.field_28 = src.field_28;
    if (dst.field_18) {
        if (dst.field_0)
            static_cast<Unk_239a458*>(dst.field_0)->vf5();
        Unk_239a418* object = src.field_0;
        src.field_0 = nullptr;
        dst.field_0 = object;
    } else {
        dst.field_0 = src.field_0;
    }
}

// Slot 15 of Unk_23ff270 and Unk_23ff3d0: their layout files.
void Unk_f67230(Unk_23ff270* self, Unk_27e15e0_Layout* layout);
void Unk_f67910(Unk_23ff3d0* self, Unk_27e15e0_Layout* layout);
// Slots 11 and 12: show the view for some states.
void Unk_f677c0(Unk_27e15e0* self, u32 state);
void Unk_f677f0(Unk_27e15e0* self, u32 state);
