// Scope: common
//
// A UI tree node (vtable 0x7102444ca0, on Unk_2444570) with an interface of
// its own at +0xa0, six callables, two references and two objects it owns
// (one an Unk_24455a8), freed through allocators. Its destructor is its key
// function: its vtable is emitted here. Placeholder names: rename once the
// classes are known.
#include <memory>

#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/unk_14b14a0/Unk_24455a8.h"

// The interface at +0xa0 (vtable 0x7102444e18).
class Unk_2444e18 {
public:
    virtual ~Unk_2444e18() {}
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct Unk_2444ca0_428 {
    Unk_239a418_Ref<Unk_239a418> field_0;
};

class Unk_2444ca0 : public Unk_2444570, public Unk_2444e18 {
public:
    ~Unk_2444ca0() override;
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

    u64 field_a8;
    Unk_23d4470_Callable field_b0[6];
    u64 field_3b0;
    Unk_239a418_Ref<Unk_239a418> field_3b8;
    u64 field_3c0;
    u64 field_3c8;
    Unk_239a418_Ref<Unk_239a418> field_3d0;
    u8 _3d8[0x408 - 0x3d8];
    std::unique_ptr<Unk_24455a8, Unk_23f4660_Deleter> field_408;
    std::unique_ptr<Unk_2444ca0_428, Unk_23f4660_Deleter> field_428;
    // Set by the constructor (0x71014e5e00), left alone by the destructor:
    // 0x71014fcda0 allocates the node as 0x460 bytes aligned to 0x10.
    u64 field_448;
    u64 field_450;
    u64 field_458;
};
static_assert(sizeof(Unk_2444ca0) == 0x460, "Unk_2444ca0");
static_assert(__builtin_offsetof(Unk_2444ca0, field_b0) == 0xb0, "Unk_2444ca0::field_b0");
static_assert(__builtin_offsetof(Unk_2444ca0, field_408) == 0x408, "Unk_2444ca0::field_408");

// 0x71014e8460 (its D0 tail-calls it)
Unk_2444ca0::~Unk_2444ca0() {}
