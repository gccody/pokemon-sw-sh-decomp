#pragma once
// An abstract class on gflib3's reference-counted object (vtable
// 0x71023a45c8, gflnet3's area), 0x120 bytes and 16-aligned (its
// std::functions): an allocator, an allocator wrapper and an array of
// references in a container with another one. 10 classes derive from it
// and destroy members of their own before its D2. Placeholder names: rename
// once the classes are known.
#include <functional>

#include "gflib3/Unk_239a418.h"

// An allocator with the largest count it allocates (0x1fffffffffffffff for
// 8-byte elements) and a callable.
struct Unk_23a45c8_Allocator {
    template <class T>
    void deallocate(T* p, u64 n) {
        field_0->vf3(reinterpret_cast<u64>(p), n * sizeof(T), alignof(T));
    }

    Unk_239a418_Allocator* field_0;
    u64 field_8;
    std::function<void()> field_10;
};
static_assert(sizeof(Unk_23a45c8_Allocator) == 0x40, "Unk_23a45c8_Allocator");

// An array of references: its elements go first to last, then its memory
// (as many elements as its capacity) goes back to its allocator.
struct Unk_23a45c8_Array {
    ~Unk_23a45c8_Array() {
        Unk_239a418_Ref<Unk_239a418>* p = field_40;
        u64 n = field_48;
        while (n--) {
            p->~Unk_239a418_Ref();
            ++p;
        }
        if (field_50)
            field_0.deallocate(field_40, field_50);
    }

    Unk_23a45c8_Allocator field_0;
    Unk_239a418_Ref<Unk_239a418>* field_40;
    u64 field_48;  // its size
    u64 field_50;  // its capacity
};
PKMN_OFFSET_ASSERT(Unk_23a45c8_Array, field_40, 0x40);

class Unk_23a45c8 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's (0x71006ce780). Inline in its TU,
    // where another function calls it too, so that it stays out of line;
    // only declared here: vf_type and the derived classes' getters call it.
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_23a45c8() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;

    Unk_239a418_Allocator* field_60;
    u64 field_68;
    Unk_23a45c8_Allocator field_70;
    Unk_23a45c8_Array field_b0;
    u32 field_110;
};
static_assert(sizeof(Unk_23a45c8) == 0x120, "Unk_23a45c8");
static_assert(__builtin_offsetof(Unk_23a45c8, field_70) == 0x70, "Unk_23a45c8::field_70");
static_assert(__builtin_offsetof(Unk_23a45c8, field_b0) == 0xb0, "Unk_23a45c8::field_b0");
static_assert(__builtin_offsetof(Unk_23a45c8, field_110) == 0x110, "Unk_23a45c8::field_110");
