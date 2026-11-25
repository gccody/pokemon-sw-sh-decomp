// Scope: common
// Two classes on gflib3's reference-counted object that hold a block of data
// (0x2300 and 0x644 bytes) whose last 4 bytes follow what Unk_65c7c0 computes
// over the rest (src/unsorted/leaf/Unk_8d0d40.cpp reads both through their
// owner, at +0x180 and +0x188): their factories, their destructors and
// thunks, and the owner's refresh of the first one from its source. Their
// vtables are emitted here, with their type getters (whose copies are
// src/unsorted/types/Unk_8e1510.cpp). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_New.h"

u32 Unk_65c7c0(void*, u32);

struct Unk_23bc600_Data {
    u8 field_0[0x2300];
};

class Unk_23bc600 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // 0x71008e1800 (D0); its D1 is the object's D2
    ~Unk_23bc600() override;
    // Inline: its thunks are emitted with the vtable, and call its copy
    // (0x71008e1850).
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    Unk_23bc600_Data field_60 = {};
};
static_assert(sizeof(Unk_23bc600) == 0x2360, "Unk_23bc600");
static_assert(__builtin_offsetof(Unk_23bc600, field_60) == 0x60, "Unk_23bc600::field_60");

struct Unk_23bc6b0_Data {
    u8 field_0[0x644];
};

class Unk_23bc6b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // 0x71008e1bb0 (D0); its D1 is the object's D2
    ~Unk_23bc6b0() override;
    // Inline: its thunks are emitted with the vtable, and call its copy
    // (0x71008e1c00).
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    Unk_23bc6b0_Data field_60 = {};
};
static_assert(sizeof(Unk_23bc6b0) == 0x6a8, "Unk_23bc6b0");
static_assert(__builtin_offsetof(Unk_23bc6b0, field_60) == 0x60, "Unk_23bc6b0::field_60");

struct Unk_8e1620_Source {
    u8 _0[0x190];
    const Unk_23bc600_Data* field_190;
};
static_assert(__builtin_offsetof(Unk_8e1620_Source, field_190) == 0x190,
              "Unk_8e1620_Source::field_190");

struct Unk_8e1620_Owner {
    u8 _0[0x60];
    Unk_239a418_Allocator* field_60;
    u8 _68[0x10];
    Unk_8e1620_Source* field_78;
    u8 _80[0x100];
    Unk_239a418_Ref<Unk_23bc600> field_180;
};
static_assert(__builtin_offsetof(Unk_8e1620_Owner, field_60) == 0x60, "Unk_8e1620_Owner::field_60");
static_assert(__builtin_offsetof(Unk_8e1620_Owner, field_78) == 0x78, "Unk_8e1620_Owner::field_78");
static_assert(__builtin_offsetof(Unk_8e1620_Owner, field_180) == 0x180,
              "Unk_8e1620_Owner::field_180");

struct Unk_8e1620_Self {
    Unk_8e1620_Owner* field_0;
};

// 0x71008e1620
void Unk_8e1620(Unk_8e1620_Self* self) {
    Unk_8e1620_Owner* owner = self->field_0;
    const Unk_23bc600_Data* source = owner->field_78->field_190;
    if (owner->field_180.m_ptr == nullptr)
        owner->field_180 =
            Unk_239a418_Ref<Unk_23bc600>(Unk_New().Create<Unk_23bc600>(owner->field_60));
    owner->field_180.m_ptr->field_60 = *source;
    if (owner->field_180.m_ptr != nullptr)
        Unk_65c7c0(&owner->field_180.m_ptr->field_60, 0x22fc);
}

// 0x71008e16f0
template Unk_23bc600* Unk_New::Create<Unk_23bc600>(Unk_239a418_Allocator*);

// 0x71008e1800 (D0), its thunks for +0x48 (0x71008e1940 D1, 0x71008e1990 D0)
// and +0x50 (0x71008e1a00 D1, 0x71008e1a50 D0); the type getter's thunks
// 0x71008e19e0 (+0x48) and 0x71008e19f0 (+0x50)
Unk_23bc600::~Unk_23bc600() = default;

// 0x71008e1aa0
template Unk_23bc6b0* Unk_New::Create<Unk_23bc6b0>(Unk_239a418_Allocator*);

// 0x71008e1bb0 (D0), its thunks for +0x48 (0x71008e1cf0 D1, 0x71008e1d40 D0)
// and +0x50 (0x71008e1db0 D1, 0x71008e1e00 D0); the type getter's thunks
// 0x71008e1d90 (+0x48) and 0x71008e1da0 (+0x50)
Unk_23bc6b0::~Unk_23bc6b0() = default;
