// Scope: common
//
// A UI tree node (vtable 0x7102445268, on Unk_2444570) with two interfaces of
// its own (+0xa0, +0xa8), eleven callables, references and six objects it
// owns, freed through allocators; and one of those objects' classes (vtable
// 0x71024454d0: a virtual destructor and nothing else). Their destructors are
// their key functions: their vtables are emitted here. Placeholder names:
// rename once the classes are known.
#include <memory>
#include <vector>

#include "unsorted/Unk_131fb20_Array.h"
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/unk_14b14a0/Unk_2444570.h"

struct alignas(16) Unk_24454d0_Element {
    u8 _0[0x30];
};

// A callback and an array of 0x30-byte, 16-aligned elements. Final: the
// deleter that destroys it calls its destructor directly.
class Unk_24454d0 final {
public:
    virtual ~Unk_24454d0();

    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    std::function<void()> field_30;
    Unk_131fb20_Array<Unk_24454d0_Element> field_60;
};
static_assert(sizeof(Unk_24454d0) == 0xc0, "Unk_24454d0");
static_assert(__builtin_offsetof(Unk_24454d0, field_30) == 0x30, "Unk_24454d0::field_30");
static_assert(__builtin_offsetof(Unk_24454d0, field_60) == 0x60, "Unk_24454d0::field_60");

// 0x71014f2140, 0x71014f2200 (D0)
Unk_24454d0::~Unk_24454d0() {}

// The interface at +0xa0 (vtable 0x7102445408): no destructor.
class Unk_2445408 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// The interface at +0xa8 (vtable 0x7102445440).
class Unk_2445440 {
public:
    virtual ~Unk_2445440() {}
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// Owned objects destroyed through their vtables.
class Unk_2445268_Owned {
public:
    virtual ~Unk_2445268_Owned();
};

struct Unk_2445268_750 {
    u64 field_0;
};

struct Unk_2445268_770 {
    Unk_239a418_Ref<Unk_239a418> field_0;
};

class Unk_2445268 : public Unk_2444570, public Unk_2445408, public Unk_2445440 {
public:
    ~Unk_2445268() override;
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
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();

    Unk_239a418_Ref<Unk_239a418> field_b0;
    u64 field_b8;
    Unk_23d4470_Callable field_c0[11];
    u64 field_640;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670;
    u64 field_678;
    u64 field_680;
    u64 field_688;
    u64 field_690;
    std::unique_ptr<Unk_2445268_Owned, Unk_23f4660_Deleter> field_698;
    std::unique_ptr<Unk_24454d0, Unk_23f4660_Deleter> field_6b8;
    std::unique_ptr<std::vector<u64, Unk_239a418_StdAllocator<u64>>, Unk_23f4660_Deleter> field_6d8;
    u64 field_6f8;
    u64 field_700;
    u64 field_708;
    u64 field_710;
    Unk_239a418_Ref<Unk_239a418> field_718;
    Unk_239a418_Ref<Unk_239a418> field_720;
    u64 field_728;
    std::unique_ptr<Unk_2445268_Owned, Unk_23f4660_Deleter> field_730;
    std::unique_ptr<Unk_2445268_750, Unk_23f4660_Deleter> field_750;
    std::unique_ptr<Unk_2445268_770, Unk_23f4660_Deleter> field_770;
    u8 _790[0x830 - 0x790];
    Unk_239a418_Ref<Unk_239a418> field_830;
    // Set by the constructor (0x71014ecc50: a byte at +0x838, zeroes up to +0x84c,
    // a halfword there), left alone by the destructor: 0x71014fe520 allocates
    // the object as 0x850 bytes aligned to 0x10.
    u8 _838[0x850 - 0x838];
};
static_assert(sizeof(Unk_2445268) == 0x850, "Unk_2445268");
static_assert(__builtin_offsetof(Unk_2445268, field_b0) == 0xb0, "Unk_2445268::field_b0");
static_assert(__builtin_offsetof(Unk_2445268, field_698) == 0x698, "Unk_2445268::field_698");
static_assert(__builtin_offsetof(Unk_2445268, field_718) == 0x718, "Unk_2445268::field_718");
static_assert(__builtin_offsetof(Unk_2445268, field_770) == 0x770, "Unk_2445268::field_770");

// 0x71014ed590, 0x71014ed9f0 (D0)
Unk_2445268::~Unk_2445268() {}
