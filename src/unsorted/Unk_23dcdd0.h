#pragma once
// A class on Unk_23dc940 (src/unsorted/Unk_23dc940.h), vtable 0x71023dcdd0, 69
// slots, 0x4b0 bytes, constructed by 0x7100c692c0. Its destructor is its key
// function. 12 classes derive from it without a destructor of their own, and
// 20 more tail-call its D2 from theirs. Placeholder names: rename once the
// classes are known.
#include <memory>
#include <vector>

#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23dc940.h"
#include "unsorted/Unk_23f4660.h"

class Unk_23c14c0;

// Called with an object and an Unk_23c14c0 it holds, before it lets go of it.
void Unk_5e2bc0(Unk_239a418* object, Unk_23c14c0* holder);

// A class with two callables (vtable 0x71023c14c0: vf0 and vf1 invoke them,
// 0x7100967200 and 0x7100967220) and a reference to an object, which its
// destructor (not virtual) hands to Unk_5e2bc0 and drops.
class Unk_23c14c0 {
public:
    virtual void vf0();
    virtual void vf1();

    ~Unk_23c14c0() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        Unk_239a418* object = field_8.m_ptr;
        field_8.m_ptr = nullptr;
        if (object)
            static_cast<Unk_239a458*>(object)->vf5();
    }

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
    u64 field_110;
    u64 field_118;
    u64 field_120;
    u64 field_128;
};
static_assert(sizeof(Unk_23c14c0) == 0x130, "Unk_23c14c0");

// The elements of Unk_23dcdd0::field_448, 16-aligned (the vector frees them
// with that alignment). Its destructor is inlined into the vector's, which
// is out of line (0x7100c69620).
struct alignas(16) Unk_23dcdd0_448 {
    u64 field_0;
    u64 field_8;
    Unk_23c14c0 field_10;
    Unk_239a418_Ref<Unk_239a418> field_140;
    u64 field_148;
    u64 field_150;
    u64 field_158;
    u64 field_160;
    u64 field_168;
    u64 field_170;
    u64 field_178;
};
static_assert(sizeof(Unk_23dcdd0_448) == 0x180, "Unk_23dcdd0_448");
static_assert(__builtin_offsetof(Unk_23dcdd0_448, field_140) == 0x140,
              "Unk_23dcdd0_448::field_140");

// The objects Unk_23dcdd0 owns: destroyed through their virtual destructors.
class Unk_23dcdd0_390 {
public:
    virtual ~Unk_23dcdd0_390();
};

class Unk_23dcdd0_3c0 {
public:
    virtual ~Unk_23dcdd0_3c0();
};

class Unk_23dcdd0 : public Unk_23dc940 {
public:
    // Its type (0x71027d6230), whose parent is Unk_23dc940's.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dc940::Unk_GetType());
        return &type;
    }

    ~Unk_23dcdd0() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    void vf8() override;
    u32 vf10() override;
    u32 vf12() override;
    void vf13() override;
    void vf18() override;
    void vf19() override;
    u32 vf36() override;
    void vf37() override;
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual u32 vf68() { return 8; }

    std::vector<std::unique_ptr<Unk_23dcdd0_390, Unk_23f4660_Deleter>,
                Unk_23c1a68_Allocator<std::unique_ptr<Unk_23dcdd0_390, Unk_23f4660_Deleter>>>
        field_390;
    std::unique_ptr<Unk_23dcdd0_3c0, Unk_23f4660_Deleter> field_3c0;
    u64 field_3e0;
    const char* field_3e8;
    u64 field_3f0;
    Unk_239a418_Ref<Unk_239a418> field_3f8;
    Unk_239a418_Ref<Unk_239a418> field_400;
    std::vector<Unk_239a418_Ref<Unk_239a418>, Unk_23c1a68_Allocator<Unk_239a418_Ref<Unk_239a418>>>
        field_408;
    f32 field_438;
    u8 field_43c;
    u64 field_440;
    std::vector<Unk_23dcdd0_448, Unk_23c1a68_Allocator<Unk_23dcdd0_448>> field_448;
    std::vector<u64, Unk_23c1a68_Allocator<u64>> field_478;
    u32 field_4a8;
    u8 field_4ac;
};
static_assert(sizeof(Unk_23dcdd0) == 0x4b0, "Unk_23dcdd0");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_390) == 0x390, "Unk_23dcdd0::field_390");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_3c0) == 0x3c0, "Unk_23dcdd0::field_3c0");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_3f8) == 0x3f8, "Unk_23dcdd0::field_3f8");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_408) == 0x408, "Unk_23dcdd0::field_408");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_438) == 0x438, "Unk_23dcdd0::field_438");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_448) == 0x448, "Unk_23dcdd0::field_448");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_478) == 0x478, "Unk_23dcdd0::field_478");
static_assert(__builtin_offsetof(Unk_23dcdd0, field_4a8) == 0x4a8, "Unk_23dcdd0::field_4a8");
