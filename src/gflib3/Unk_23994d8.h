#pragma once
// A gflib3 class on Unk_239a4c0 (vtable 0x71023994d8), with an interface of
// its own at +0x58 (vtable 0x7102399568). Its destructor (0x71005d0c40, not
// decompiled yet) finalizes a light event and frees an object it owns
// through an allocator; game classes derive from it and tail-call it. Only
// what those need is declared here. Placeholder names: rename once the class
// is known.
#include "gflib3/Unk_239a4c0.h"

// The interface at +0x58: one function, then its destructor.
class Unk_2399568 {
public:
    virtual void vf0();
    virtual ~Unk_2399568() {}
};

class Unk_23994d8 : public Unk_239a4c0, public Unk_2399568 {
public:
    ~Unk_23994d8() override;
    void vf2() override;
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();

    u8 _60[0x2b8 - 0x60];
    u64 field_2b8;  // the owned object, and its deleter's allocator, size and alignment
    u64 field_2c0;
    u64 field_2c8;
    u64 field_2d0;
    u32 field_2d8;
    u8 field_2dc[0xc];  // a light event
};
static_assert(sizeof(Unk_23994d8) == 0x2e8, "Unk_23994d8");
