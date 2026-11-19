// Scope: common
//
// Three classes (vtables 0x710236d678, 0x710236d6c8,
// 0x710236d718) on Unk_23a7ca0_Primary (src/unsorted/Unk_23a7ca0_Base.h), each with
// a holder (Unk_236d3d8). Their destructors are their key functions: their
// vtables are emitted here. Placeholder names: rename once the
// classes are known.
#include "unsorted/Unk_23a7ca0_Base.h"

class Unk_236d678 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_236d678() override;
    void vf2() override;
    void vf3() override;

    Unk_236d3d8 field_50;
};
static_assert(sizeof(Unk_236d678) == 0x160, "Unk_236d678");
static_assert(__builtin_offsetof(Unk_236d678, field_50) == 0x50, "Unk_236d678::field_50");

// 0x710000ad80, its D0
Unk_236d678::~Unk_236d678() {}

class Unk_236d6c8 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_236d6c8() override;
    void vf2() override;
    void vf3() override;

    Unk_236d3d8 field_50;
};
static_assert(sizeof(Unk_236d6c8) == 0x160, "Unk_236d6c8");
static_assert(__builtin_offsetof(Unk_236d6c8, field_50) == 0x50, "Unk_236d6c8::field_50");

// 0x710000b190, its D0
Unk_236d6c8::~Unk_236d6c8() {}

class Unk_236d718 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_236d718() override;
    void vf2() override;
    void vf3() override;

    Unk_236d3d8 field_50;
};
static_assert(sizeof(Unk_236d718) == 0x160, "Unk_236d718");
static_assert(__builtin_offsetof(Unk_236d718, field_50) == 0x50, "Unk_236d718::field_50");

// 0x710000b5a0, its D0
Unk_236d718::~Unk_236d718() {}
