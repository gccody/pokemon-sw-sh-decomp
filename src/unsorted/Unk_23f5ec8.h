#pragma once
// An abstract class on gflib3's reference-counted object (vtable
// 0x71023f5ec8, 13 slots: vf7-vf11 are pure, so its D0 and the D0 thunks are
// traps), 0x80 bytes, constructed by 0x7100eb2c80: an object it owns, freed
// through an allocator. Its D2 is inlined into its D1 thunks. 6 classes derive
// from it, with destructors of their own that tail-call its D2 (Unk_23f2df0,
// src/unsorted/Unk_23f2df0.h, for one). Placeholder names: rename once the
// classes are known.
#include <memory>

#include "unsorted/Unk_23f4660.h"

// The object it owns. Its destructor isn't virtual, and it's out of line
// (0x7100eb58b0: it releases references).
class Unk_23f5ec8_60 {
public:
    ~Unk_23f5ec8_60();
};

// Tail-called by vf12 with 0.
void Unk_eb5330(void* self, u32 arg);

class Unk_23f5ec8 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. Every derived class's getter
    // inlines it, so no copy of it is out of line: the functions of its TU get
    // it from Unk_eb57c0.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f5ec8() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual u32 vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12();

    std::unique_ptr<Unk_23f5ec8_60, Unk_23f4660_Deleter> field_60;
};
static_assert(sizeof(Unk_23f5ec8) == 0x80, "Unk_23f5ec8");
static_assert(__builtin_offsetof(Unk_23f5ec8, field_60) == 0x60, "Unk_23f5ec8::field_60");

// The functions of Unk_23f5ec8's TU get its type from this one
// (0x7100eb57c0): its getter inlined, nothing else.
const Unk_239a418_Type* Unk_eb57c0();
