// Scope: common
//
// A class on Unk_23f43c8 (vtable 0x710243b490): a reference of its own. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the class is known.
#include "unsorted/Unk_23f43c8.h"

class Unk_243b490 : public Unk_23f43c8 {
public:
    ~Unk_243b490() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
};
static_assert(sizeof(Unk_243b490) == 0xa0, "Unk_243b490");
static_assert(__builtin_offsetof(Unk_243b490, field_98) == 0x98, "Unk_243b490::field_98");

// 0x710143a9e0, its D0 and thunks for +0x48 and +0x50
Unk_243b490::~Unk_243b490() {}
