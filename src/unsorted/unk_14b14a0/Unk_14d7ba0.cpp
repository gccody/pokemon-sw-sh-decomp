// Scope: common
//
// A class on Unk_2443d60 (vtable 0x7102443dd8): three references. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a4c0.h"

// Its base (vtable 0x7102443d60), on Unk_239a4c0: two functions and a
// reference. Its destructor is implicit: this one inlines it (its own copy is
// another TU's, 0x71014d6ca0).
class Unk_2443d60 : public Unk_239a4c0 {
public:
    virtual void vf5();
    virtual void vf6();

    Unk_239a418_Ref<Unk_239a418> field_58;
};
static_assert(sizeof(Unk_2443d60) == 0x60, "Unk_2443d60");

class Unk_2443dd8 : public Unk_2443d60 {
public:
    ~Unk_2443dd8() override;

    u64 field_60;
    u64 field_68;
    u64 field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
};
static_assert(sizeof(Unk_2443dd8) == 0x90, "Unk_2443dd8");
static_assert(__builtin_offsetof(Unk_2443dd8, field_78) == 0x78, "Unk_2443dd8::field_78");

// 0x71014d7ba0, its D0 and thunks for +0x48
Unk_2443dd8::~Unk_2443dd8() {}
