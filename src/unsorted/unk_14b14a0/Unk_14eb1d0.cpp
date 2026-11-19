// Scope: common
//
// A UI tree node (vtable 0x7102444f50, on Unk_2444570) with a callable and
// five pairs of references of its own. Its destructor is its key function: its
// vtable and thunks are emitted here. Placeholder names: rename once the
// classes are known.
#include "unsorted/Unk_23d4470.h"
#include "unsorted/unk_14b14a0/Unk_2444570.h"

struct Unk_14eb900_Entry {
    u64 field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    Unk_239a418_Ref<Unk_239a418> field_28;
};
static_assert(sizeof(Unk_14eb900_Entry) == 0x30, "Unk_14eb900_Entry");

// Five entries, with an out-of-line destructor (0x71014eb900).
struct Unk_14eb900 {
    ~Unk_14eb900();

    Unk_14eb900_Entry field_0[5];
};
static_assert(sizeof(Unk_14eb900) == 0xf0, "Unk_14eb900");

class Unk_2444f50 : public Unk_2444570 {
public:
    ~Unk_2444f50() override;
    const Unk_239a418_Type* vf_type() override;
    void vf12() override;
    void vf15() override;
    void vf18(bool value) override;
    void vf19(bool value) override;
    void vf20(bool value) override;
    void vf22() override;
    void vf23() override;

    u8 _a0[0x160 - 0xa0];
    Unk_23d4470_Callable field_160;
    Unk_14eb900 field_1e0;
};
static_assert(sizeof(Unk_2444f50) == 0x2d0, "Unk_2444f50");
static_assert(__builtin_offsetof(Unk_2444f50, field_160) == 0x160, "Unk_2444f50::field_160");
static_assert(__builtin_offsetof(Unk_2444f50, field_1e0) == 0x1e0, "Unk_2444f50::field_1e0");

// 0x71014eb1d0, its D0 and thunks for +0x48 and +0x50
Unk_2444f50::~Unk_2444f50() {}

// 0x71014eb900
Unk_14eb900::~Unk_14eb900() {}
