#pragma once
// An object the UI tree nodes own (vtable 0x71024455a8): a callback and an
// array, each owned and freed through an allocator. Placeholder names: rename
// once the class is known.
#include <memory>

#include "unsorted/Unk_131fb20_Array.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/unk_14b14a0/Unk_2444570.h"

struct Unk_24455a8_Callback {
    u64 field_0;
    u64 field_8;
    std::function<void()> field_10;
};
static_assert(sizeof(Unk_24455a8_Callback) == 0x40, "Unk_24455a8_Callback");

struct Unk_24455a8_Element {
    u64 field_0;
    u64 field_8;
};

// Its destructor is implicit; its vtable is another TU's (its D0
// is 0x71014f4d30), and the copy of its D2 that the nodes call is
// 0x71014e5880. Final: the deleter calls it directly.
class Unk_24455a8 final {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual ~Unk_24455a8() = default;

    u64 field_8;
    u64 field_10;
    u64 field_18;
    std::unique_ptr<Unk_24455a8_Callback, Unk_23f4660_Deleter> field_20;
    std::unique_ptr<Unk_131fb20_Array<Unk_24455a8_Element>, Unk_23f4660_Deleter> field_40;
};
static_assert(sizeof(Unk_24455a8) == 0x60, "Unk_24455a8");
