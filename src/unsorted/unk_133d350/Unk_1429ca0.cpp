// Scope: common
//
// A class on Unk_23f43c8 (vtable 0x710243a0d0): an Unk_13a4f20 and a
// reference. Its destructor is its key function: its vtable and thunks are
// emitted here. Placeholder names: rename once the class is known.
#include "unsorted/Unk_23f43c8.h"
#include "unsorted/unk_133d350/Unk_13a4f20.h"

class Unk_243a0d0 : public Unk_23f43c8 {
public:
    ~Unk_243a0d0() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_78;
    Unk_13a4f20 field_80;
    Unk_239a418_Ref<Unk_239a418> field_4b8;
};
static_assert(sizeof(Unk_243a0d0) == 0x4c0, "Unk_243a0d0");
static_assert(__builtin_offsetof(Unk_243a0d0, field_80) == 0x80, "Unk_243a0d0::field_80");

// 0x7101429ca0, its D0 and thunks for +0x48 and +0x50
Unk_243a0d0::~Unk_243a0d0() {}
