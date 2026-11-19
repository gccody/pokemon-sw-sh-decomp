// Scope: common
//
// A class on Unk_23f4e40 (vtable 0x7102402f68): nine references and an
// object it owns, freed through an allocator. Its destructor is its key
// function: its vtable and thunks are emitted here. Placeholder names: rename
// once the classes are known.
#include <memory>

#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_23f4e40.h"

// The object it owns: three references.
struct Unk_2402f68_Owned {
    u64 field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    Unk_239a418_Ref<Unk_239a418> field_28;
    u64 field_30;
    Unk_239a418_Ref<Unk_239a418> field_38;
};
static_assert(sizeof(Unk_2402f68_Owned) == 0x40, "Unk_2402f68_Owned");

class Unk_2402f68 : public Unk_23f4e40 {
public:
    ~Unk_2402f68() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    std::unique_ptr<Unk_2402f68_Owned, Unk_23f4660_Deleter> field_b0;
    Unk_239a418_Ref<Unk_239a418> field_d0;
    Unk_239a418_Ref<Unk_239a418> field_d8;
    Unk_239a418_Ref<Unk_239a418> field_e0;
    Unk_239a418_Ref<Unk_239a418> field_e8;
};
static_assert(sizeof(Unk_2402f68) == 0xf0, "Unk_2402f68");
static_assert(__builtin_offsetof(Unk_2402f68, field_b0) == 0xb0, "Unk_2402f68::field_b0");

// 0x7100fc2b30, its D0 and thunks for +0x48 and +0x50
Unk_2402f68::~Unk_2402f68() {}
