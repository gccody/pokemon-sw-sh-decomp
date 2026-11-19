// Scope: common
//
// A class on gflib3's other reference-counted object, Unk_239a4c0 (vtable
// 0x71024355b8): a reference and a vector of
// 0x20-byte entries that end with one. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the class is known.
#include <vector>

#include "gflib3/Unk_239a4c0.h"

struct Unk_24355b8_Entry {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
};
static_assert(sizeof(Unk_24355b8_Entry) == 0x20, "Unk_24355b8_Entry");

class Unk_24355b8 : public Unk_239a4c0 {
public:
    ~Unk_24355b8() override;

    u64 field_58;
    u64 field_60;
    u64 field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    u64 field_78;
    u64 field_80;
    std::vector<Unk_24355b8_Entry, Unk_239a418_StdAllocator<Unk_24355b8_Entry>> field_88;
};
static_assert(sizeof(Unk_24355b8) == 0xa8, "Unk_24355b8");
static_assert(__builtin_offsetof(Unk_24355b8, field_70) == 0x70, "Unk_24355b8::field_70");
static_assert(__builtin_offsetof(Unk_24355b8, field_88) == 0x88, "Unk_24355b8::field_88");

// 0x71013cb710, its D0 and thunks for +0x48
Unk_24355b8::~Unk_24355b8() {}
