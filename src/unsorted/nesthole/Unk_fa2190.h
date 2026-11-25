#pragma once
// Two classes of game/nesthole on gflib3's object: one that holds six
// references (vtable 0x7102402190, src/unsorted/nesthole/Unk_fa2190.cpp) and
// one that is made from them (vtable 0x7102402240,
// src/unsorted/nesthole/Unk_fa25f0.cpp). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// Its base (vtable 0x71024a8668's group), as in src/unsorted/Unk_23f43c8.h,
// with its constructor.
class Unk_23f4318 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    Unk_23f4318();  // 0x7100e7c210
    ~Unk_23f4318() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
};
static_assert(sizeof(Unk_23f4318) == 0x60, "Unk_23f4318");

// Six references, copied as one: each new one is added before the old one is
// dropped.
struct Unk_2402180_Refs {
    using Ref = Unk_239a418_Ref<Unk_239a418>;

    Unk_2402180_Refs() = default;
    Unk_2402180_Refs(const Unk_2402180_Refs& other) = default;

    static void Assign(Ref& to, const Ref& from) {
        Unk_239a418* p = from.m_ptr;
        if (p)
            static_cast<Unk_239a458*>(p)->vf4();
        Unk_239a418* old = to.m_ptr;
        to.m_ptr = p;
        if (old)
            static_cast<Unk_239a458*>(old)->vf5();
    }

    // 0x7100fa21f0
    Unk_2402180_Refs& operator=(const Unk_2402180_Refs& other) {
        Assign(field_0, other.field_0);
        Assign(field_8, other.field_8);
        Assign(field_10, other.field_10);
        Assign(field_18, other.field_18);
        Assign(field_20, other.field_20);
        Assign(field_28, other.field_28);
        return *this;
    }

    Ref field_0;
    Ref field_8;
    Ref field_10;
    Ref field_18;
    Ref field_20;
    Ref field_28;
};
static_assert(sizeof(Unk_2402180_Refs) == 0x30, "Unk_2402180_Refs");

class Unk_2402180 : public Unk_23f4318 {
public:
    Unk_2402180();
    ~Unk_2402180() override;
    // Out of line here: src/unsorted/types/Unk_fa24e0.cpp has it.
    const Unk_239a418_Type* vf_type() override;

    void Unk_fa21e0(const Unk_2402180_Refs& refs);
    Unk_239a418_Ref<Unk_239a418> Unk_fa2340() const;
    Unk_239a418_Ref<Unk_239a418> Unk_fa2360() const;
    Unk_239a418_Ref<Unk_239a418> Unk_fa2380() const;
    Unk_239a418_Ref<Unk_239a418> Unk_fa23a0() const;
    Unk_239a418_Ref<Unk_239a418> Unk_fa23c0() const;
    Unk_239a418_Ref<Unk_239a418> Unk_fa23e0() const;

    Unk_2402180_Refs field_60;
};
static_assert(sizeof(Unk_2402180) == 0x90, "Unk_2402180");
static_assert(__builtin_offsetof(Unk_2402180, field_60) == 0x60, "Unk_2402180::field_60");
