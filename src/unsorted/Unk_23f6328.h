#pragma once
// An abstract class on Unk_23f4660 (src/unsorted/Unk_23f4660.h), vtable
// 0x71023f6328, 19 slots (vf18 is pure, so its D0 and the D0 thunks are
// traps): two references, an object it owns, two flags and an Unk_236d3f8,
// 0x6f8 bytes (its data ends at 0x6f1: a derived class puts a u32 at 0x6f4).
// 6 classes derive from it without a destructor of their own: their D2 is
// this one, their D0s and thunks tail-call it (the family's operator delete
// is empty). Their constructors allocate 0x700 bytes with alignment 0x10.
// Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_23f4660.h"

// The objects Unk_236d3f8 owns: destroyed through their virtual destructors.
class Unk_236d3f8_Owned {
public:
    virtual ~Unk_236d3f8_Owned();
};

// A member of Unk_23f6328 (vtable 0x710236d3f8), 0xe8 bytes, constructed by
// 0x7100ea46c0: three objects it owns, freed through an allocator. Its
// destructor is inline: its D2 (0x7100008090) and D0 (0x71000081d0, global
// operator delete) are emitted with its vtable wherever it's destroyed.
class Unk_236d3f8 {
public:
    virtual ~Unk_236d3f8() {}

    u64 field_8;
    u64 field_10;
    u64 field_18;
    std::unique_ptr<Unk_236d3f8_Owned, Unk_23f4660_Deleter> field_20;
    std::unique_ptr<Unk_236d3f8_Owned, Unk_23f4660_Deleter> field_40;
    std::unique_ptr<Unk_236d3f8_Owned, Unk_23f4660_Deleter> field_60;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
    u64 field_c0;
    u64 field_c8;
    u64 field_d0;
    u64 field_d8;
    u32 field_e0;
};
static_assert(sizeof(Unk_236d3f8) == 0xe8, "Unk_236d3f8");
static_assert(__builtin_offsetof(Unk_236d3f8, field_20) == 0x20, "Unk_236d3f8::field_20");
static_assert(__builtin_offsetof(Unk_236d3f8, field_80) == 0x80, "Unk_236d3f8::field_80");

// The object Unk_23f6328 owns: destroyed through its virtual destructor.
class Unk_23f6328_5e0 {
public:
    virtual ~Unk_23f6328_5e0();
};

class Unk_23f6328 : public Unk_23f4660 {
public:
    // Its type, whose parent is Unk_23f4660's (inlined: 0x7100eb84a0 has four
    // guarded statics). Too big to be inlined into vf_type: vf_type, its
    // thunks and the derived classes' getters call it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23f6328() override;
    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    u32 vf9() override;
    void vf13() override;
    u32 vf16() override;
    virtual void vf17();
    virtual u32 vf18() = 0;

    Unk_239a418_Ref<Unk_239a418> field_5d0;
    Unk_239a418_Ref<Unk_239a418> field_5d8;
    std::unique_ptr<Unk_23f6328_5e0, Unk_23f4660_Deleter> field_5e0;
    u8 field_600;
    u8 field_601;
    Unk_236d3f8 field_608;
    u8 field_6f0;
};
static_assert(sizeof(Unk_23f6328) == 0x6f8, "Unk_23f6328");
static_assert(__builtin_offsetof(Unk_23f6328, field_5d0) == 0x5d0, "Unk_23f6328::field_5d0");
static_assert(__builtin_offsetof(Unk_23f6328, field_5e0) == 0x5e0, "Unk_23f6328::field_5e0");
static_assert(__builtin_offsetof(Unk_23f6328, field_600) == 0x600, "Unk_23f6328::field_600");
static_assert(__builtin_offsetof(Unk_23f6328, field_608) == 0x608, "Unk_23f6328::field_608");
static_assert(__builtin_offsetof(Unk_23f6328, field_6f0) == 0x6f0, "Unk_23f6328::field_6f0");
