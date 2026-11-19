// Scope: common
//
// A UI tree node (vtable 0x7102445c20, on Unk_2444570) with a callable of
// its own. Its destructor is its key function: its vtable and thunks are
// emitted here. Placeholder names: rename once the class is known.
#include "unsorted/Unk_23d4470.h"
#include "unsorted/unk_14b14a0/Unk_2444570.h"

class Unk_2445c20 : public Unk_2444570 {
public:
    ~Unk_2445c20() override;
    const Unk_239a418_Type* vf_type() override;
    void vf12() override;
    void vf15() override;
    void vf18(bool value) override;
    void vf19(bool value) override;
    void vf20(bool value) override;
    void vf22() override;
    void vf23() override;
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();

    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
    Unk_23d4470_Callable field_c0;
};
static_assert(sizeof(Unk_2445c20) == 0x140, "Unk_2445c20");
static_assert(__builtin_offsetof(Unk_2445c20, field_c0) == 0xc0, "Unk_2445c20::field_c0");

// 0x71014fc200, 0x71014fc2f0 (D0), thunks 0x71014fc450/0x71014fc540 (+0x48)
// and 0x71014fc710/0x71014fc800 (+0x50)
Unk_2445c20::~Unk_2445c20() {}
