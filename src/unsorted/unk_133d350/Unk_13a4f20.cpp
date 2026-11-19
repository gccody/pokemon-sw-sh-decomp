// Scope: common
//
// Unk_13a4f20's destructor (src/unsorted/unk_133d350/Unk_13a4f20.h) and two
// classes on Unk_23f4e40 of the same TU. Their destructors are their key
// functions: their vtables and thunks are emitted here. Placeholder names:
// rename once the classes are known.
#include "unsorted/unk_133d350/Unk_13a4f20.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_23f4e40.h"

// 0x71013a4f20
Unk_13a4f20::~Unk_13a4f20() {}

// vtable 0x7102433de0: an Unk_13a4f20 and a reference.
class Unk_2433de0 : public Unk_23f4e40 {
public:
    ~Unk_2433de0() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    Unk_13a4f20 field_88;
    u64 field_4c0;
    Unk_239a418_Ref<Unk_239a418> field_4c8;
};
static_assert(sizeof(Unk_2433de0) == 0x4d0, "Unk_2433de0");
static_assert(__builtin_offsetof(Unk_2433de0, field_88) == 0x88, "Unk_2433de0::field_88");

// 0x71013a5740, its D0 and thunks for +0x48 and +0x50
Unk_2433de0::~Unk_2433de0() {}

// vtable 0x7102433eb0: a name and a reference.
class Unk_2433eb0 : public Unk_23f4e40 {
public:
    ~Unk_2433eb0() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    Unk_23f4660_Name field_88;
    u64 field_b8;
    u64 field_c0;
    Unk_239a418_Ref<Unk_239a418> field_c8;
};
static_assert(sizeof(Unk_2433eb0) == 0xd0, "Unk_2433eb0");
static_assert(__builtin_offsetof(Unk_2433eb0, field_88) == 0x88, "Unk_2433eb0::field_88");

// 0x71013a5ed0, its D0 and thunks for +0x48 and +0x50
Unk_2433eb0::~Unk_2433eb0() {}
