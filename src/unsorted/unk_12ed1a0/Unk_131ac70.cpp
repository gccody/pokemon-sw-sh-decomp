// Scope: common
//
// A class on Unk_23f4318 (vtable 0x710242f8c8): 100 entries that end with a
// reference. Its destructor is its key function: its vtable and thunks are
// emitted here. Placeholder names: rename once the class is known.
#include "unsorted/Unk_23f43c8.h"

struct Unk_242f8c8_Entry {
    u64 field_0;
    u64 field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
};
static_assert(sizeof(Unk_242f8c8_Entry) == 0x18, "Unk_242f8c8_Entry");

class Unk_242f8c8 : public Unk_23f4318 {
public:
    ~Unk_242f8c8() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_60;
    u64 field_68;
    Unk_242f8c8_Entry field_70[100];
};
static_assert(sizeof(Unk_242f8c8) == 0x9d0, "Unk_242f8c8");
static_assert(__builtin_offsetof(Unk_242f8c8, field_70) == 0x70, "Unk_242f8c8::field_70");

// 0x710131ac70, its D0 and thunks for +0x48 and +0x50
Unk_242f8c8::~Unk_242f8c8() {}
