#pragma once
// The regulation download's object (vtable 0x710242ffd0), 0x41bb8 bytes:
// most of it a buffer nothing here reads, then a vector of words it owns,
// freed through an allocator, and two references. Constructed at
// 0x710131c9a0. Placeholder names: rename once the class is known.
#include <memory>
#include <vector>

#include "unsorted/Unk_23f43c8.h"
#include "unsorted/Unk_23f4660.h"

class Unk_242ffd0 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_242ffd0() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    u8 _78[0x41b88 - 0x78];
    std::unique_ptr<std::vector<u32, Unk_239a418_StdAllocator<u32>>, Unk_23f4660_Deleter>
        field_41b88;
    Unk_239a418_Ref<Unk_239a418> field_41ba8;
    Unk_239a418_Ref<Unk_239a418> field_41bb0;
};
static_assert(sizeof(Unk_242ffd0) == 0x41bb8, "Unk_242ffd0");
static_assert(__builtin_offsetof(Unk_242ffd0, field_41b88) == 0x41b88, "Unk_242ffd0::field_41b88");
static_assert(__builtin_offsetof(Unk_242ffd0, field_41ba8) == 0x41ba8, "Unk_242ffd0::field_41ba8");
