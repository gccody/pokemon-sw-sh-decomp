// Scope: common
//
// A class on Unk_23f4e40 (vtable 0x7102402e98): a member with a destructor of
// its own (0x7100fc0a80), an Unk_13a4f20 and a reference. Its destructor is
// its key function: its vtable and thunks are emitted here. Placeholder names:
// rename once the classes are known.
#include "unsorted/Unk_23f4e40.h"
#include "unsorted/unk_133d350/Unk_13a4f20.h"

// A member with an out-of-line destructor (0x7100fc0a80), not decompiled
// yet.
struct Unk_fc0a80 {
    ~Unk_fc0a80();

    u8 _0[0x3d0];
};

class Unk_2402e98 : public Unk_23f4e40 {
public:
    ~Unk_2402e98() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    u64 field_88;
    Unk_fc0a80 field_90;
    Unk_13a4f20 field_460;
    u64 field_898;
    Unk_239a418_Ref<Unk_239a418> field_8a0;
};
static_assert(sizeof(Unk_2402e98) == 0x8a8, "Unk_2402e98");
static_assert(__builtin_offsetof(Unk_2402e98, field_90) == 0x90, "Unk_2402e98::field_90");
static_assert(__builtin_offsetof(Unk_2402e98, field_460) == 0x460, "Unk_2402e98::field_460");

// 0x7100fc1af0, its D0 and thunks for +0x48 and +0x50
Unk_2402e98::~Unk_2402e98() {}
