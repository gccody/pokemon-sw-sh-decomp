#pragma once
// Three classes with two callables (vf0 and vf1 invoke them) and a reference to
// an object, which their destructors (not virtual, inline) hand to Unk_5e2bc0
// and drop: Unk_23c14c0's shape (src/unsorted/Unk_23dcdd0.h). Members of many
// game classes: 231 functions reference Unk_236d3d8's vtable, 36
// Unk_236d4d8's. Placeholder names: rename once the classes are known.
#include "gflib3/Unk_5e2bc0.h"
#include "unsorted/Unk_23d4470.h"

// vtable 0x710236d3d8: vf0 0x7100008190, vf1 0x71000081b0.
class Unk_236d3d8 {
public:
    virtual void vf0();
    virtual void vf1();

    ~Unk_236d3d8() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        Unk_239a418* object = field_8.m_ptr;
        field_8.m_ptr = nullptr;
        if (object)
            static_cast<Unk_239a458*>(object)->vf5();
    }

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_236d3d8) == 0x110, "Unk_236d3d8");

// vtable 0x710236d4d8: vf0 0x7100008db0, vf1 0x7100008dd0.
class Unk_236d4d8 {
public:
    virtual void vf0();
    virtual void vf1();

    ~Unk_236d4d8() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        Unk_239a418* object = field_8.m_ptr;
        field_8.m_ptr = nullptr;
        if (object)
            static_cast<Unk_239a458*>(object)->vf5();
    }

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_236d4d8) == 0x110, "Unk_236d4d8");

// vtable 0x710236d658: vf0 0x710000a930, vf1 0x710000a950.
class Unk_236d658 {
public:
    virtual void vf0();
    virtual void vf1();

    ~Unk_236d658() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        Unk_239a418* object = field_8.m_ptr;
        field_8.m_ptr = nullptr;
        if (object)
            static_cast<Unk_239a458*>(object)->vf5();
    }

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_236d658) == 0x110, "Unk_236d658");
