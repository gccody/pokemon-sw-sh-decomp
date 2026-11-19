// Scope: common
//
// A class on Unk_23f4660 (vtable 0x710242fb30): 100 entries of two
// references each, and three more references. Its destructor is its key
// function: its vtable and thunks are emitted here. Placeholder names: rename
// once the class is known.
#include "unsorted/Unk_23f4660.h"

struct Unk_242fb30_Entry {
    u64 field_0;
    u64 field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
    u64 field_20;
    u64 field_28;
};
static_assert(sizeof(Unk_242fb30_Entry) == 0x30, "Unk_242fb30_Entry");

class Unk_242fb30 : public Unk_23f4660 {
public:
    ~Unk_242fb30() override;
    const Unk_239a418_Type* vf_type() override;

    Unk_242fb30_Entry field_5d0[100];
    u64 field_1890;
    u64 field_1898;
    Unk_239a418_Ref<Unk_239a418> field_18a0;
    u64 field_18a8;
    Unk_239a418_Ref<Unk_239a418> field_18b0;
    Unk_239a418_Ref<Unk_239a418> field_18b8;
};
static_assert(sizeof(Unk_242fb30) == 0x18c0, "Unk_242fb30");
static_assert(__builtin_offsetof(Unk_242fb30, field_5d0) == 0x5d0, "Unk_242fb30::field_5d0");
static_assert(__builtin_offsetof(Unk_242fb30, field_18a0) == 0x18a0, "Unk_242fb30::field_18a0");

// 0x710131f180, 0x710131f250 (D0), thunks 0x710131f330/0x710131f400 (+0x48)
// and 0x710131f4f0/0x710131f5c0 (+0x50)
Unk_242fb30::~Unk_242fb30() {}
