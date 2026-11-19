// Scope: common
//
// A class on gflib3's other reference-counted object, Unk_239a4c0 (vtable
// 0x7102435620): three vectors of entries that
// hold a reference. Its destructor is its
// key function: its vtable and thunks are emitted here. Placeholder names:
// rename once the class is known.
#include <vector>

#include "gflib3/Unk_239a4c0.h"

struct Unk_2435620_Entry20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
};
static_assert(sizeof(Unk_2435620_Entry20) == 0x20, "Unk_2435620_Entry20");

struct Unk_2435620_Entry28 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
    u64 field_20;
};
static_assert(sizeof(Unk_2435620_Entry28) == 0x28, "Unk_2435620_Entry28");

class Unk_2435620 : public Unk_239a4c0 {
public:
    ~Unk_2435620() override;

    std::vector<Unk_2435620_Entry20, Unk_239a418_StdAllocator<Unk_2435620_Entry20>> field_58;
    u64 field_78;
    u64 field_80;
    std::vector<Unk_2435620_Entry28, Unk_239a418_StdAllocator<Unk_2435620_Entry28>> field_88;
    u64 field_a8;
    u64 field_b0;
    std::vector<Unk_2435620_Entry28, Unk_239a418_StdAllocator<Unk_2435620_Entry28>> field_b8;
};
static_assert(sizeof(Unk_2435620) == 0xd8, "Unk_2435620");
static_assert(__builtin_offsetof(Unk_2435620, field_58) == 0x58, "Unk_2435620::field_58");
static_assert(__builtin_offsetof(Unk_2435620, field_88) == 0x88, "Unk_2435620::field_88");
static_assert(__builtin_offsetof(Unk_2435620, field_b8) == 0xb8, "Unk_2435620::field_b8");

// 0x71013cc110, its D0 and thunks for +0x48
Unk_2435620::~Unk_2435620() {}
