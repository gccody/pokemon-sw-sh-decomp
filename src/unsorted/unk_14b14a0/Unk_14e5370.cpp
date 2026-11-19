// Scope: common
//
// A UI tree node (vtable 0x71024449a0, on Unk_2444570) with two callables,
// references and an object it owns (vtable 0x71024455a8), freed through an
// allocator. Its destructor is its key function: its vtable is emitted here.
// Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/unk_14b14a0/Unk_24455a8.h"

// An entry of the node: a reference and three words.
struct Unk_24449a0_Entry {
    Unk_239a418_Ref<Unk_239a418> field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_24449a0_Entry) == 0x20, "Unk_24449a0_Entry");

class Unk_24449a0 : public Unk_2444570 {
public:
    ~Unk_24449a0() override;
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
    u64 field_1e0;
    u64 field_1e8;
    Unk_239a418_Ref<Unk_239a418> field_1f0;
    Unk_239a418_Ref<Unk_239a418> field_1f8;
    Unk_239a418_Ref<Unk_239a418> field_200;
    Unk_239a418_Ref<Unk_239a418> field_208;
    Unk_239a418_Ref<Unk_239a418> field_210;
    Unk_239a418_Ref<Unk_239a418> field_218;
    Unk_239a418_Ref<Unk_239a418> field_220;
    u8 _228[0x260 - 0x228];
    std::unique_ptr<Unk_24455a8, Unk_23f4660_Deleter> field_260;
    u8 _280[0x2b0 - 0x280];
    Unk_24449a0_Entry field_2b0[15];
    Unk_23d4470_Callable field_490;
};
static_assert(sizeof(Unk_24449a0) == 0x510, "Unk_24449a0");
static_assert(__builtin_offsetof(Unk_24449a0, field_160) == 0x160, "Unk_24449a0::field_160");
static_assert(__builtin_offsetof(Unk_24449a0, field_260) == 0x260, "Unk_24449a0::field_260");
static_assert(__builtin_offsetof(Unk_24449a0, field_2b0) == 0x2b0, "Unk_24449a0::field_2b0");
static_assert(__builtin_offsetof(Unk_24449a0, field_490) == 0x490, "Unk_24449a0::field_490");

// 0x71014e5370 (its D0 tail-calls it)
Unk_24449a0::~Unk_24449a0() {}
