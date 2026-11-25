#pragma once
// The abstract class on gflib3's Unk_239a4c0 with vtable 0x71023bb238
// (Unk_23bb228; src/unsorted/virtual/Unk_8c67d0.cpp has its destructors, and
// its thunks are emitted with its vtable there), 0x68 bytes: a walk over the
// set bits of a mask in a range of bit numbers, 14 when it's done. Its
// constructor is src/unsorted/unk_8bf520/Unk_8c6550.cpp, the walk
// src/unsorted/unk_8bf520/Unk_8c6810.cpp. Placeholder names: rename once the
// class is known.
#include <types.h>

#include "gflib3/Unk_239a4c0.h"

class Unk_23bb228 : public Unk_239a4c0 {
public:
    Unk_23bb228(u8 arg1, u32 first, u32 last, u32 mask);
    ~Unk_23bb228() override;
    virtual void vf5() = 0;
    virtual u8 vf6() = 0;

    // The first set bit from field_54, or field_5c's next one.
    void Unk_8c6830();
    void Unk_8c6870();
    bool Unk_8c68b0() const;

    s32 field_54;
    s32 field_58;
    s32 field_5c;
    u32 field_60;
    u8 field_64;
};
static_assert(sizeof(Unk_23bb228) == 0x68, "Unk_23bb228");
PKMN_OFFSET_ASSERT(Unk_23bb228, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_23bb228, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_23bb228, field_64, 0x64);

// A reference to an object on Unk_239a4c0: added and dropped through its
// +0x48 interface (Unk_239a4f8::vf3 and vf4).
template <class T>
class Unk_8c6550_Ref {
public:
    Unk_8c6550_Ref() : m_ptr(nullptr) {}
    explicit Unk_8c6550_Ref(T* ptr) : m_ptr(ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    Unk_8c6550_Ref(const Unk_8c6550_Ref& other) : m_ptr(other.m_ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    ~Unk_8c6550_Ref() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }

    Unk_8c6550_Ref& operator=(Unk_8c6550_Ref&& other) {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
        m_ptr = other.Release();
        return *this;
    }

    // Lets go of the object: cleared first, then released.
    void Reset() {
        T* p = m_ptr;
        m_ptr = nullptr;
        if (p)
            static_cast<Unk_239a4f8*>(p)->vf4();
    }
    T* Release() {
        T* p = m_ptr;
        m_ptr = nullptr;
        return p;
    }

    T* m_ptr;
};

class Unk_239a418_Allocator;
struct Unk_7c2d80_Main;
struct Unk_7fe1d0;
struct Unk_7ecc90_Con;

// A random number generator (vtable 0x71023aa6d0, src/unsorted/virtual/
// Unk_7c3a70.cpp; its D2 is inline here: what holds one doesn't call it):
// xoroshiro128+'s state from +0x8, seeded by Unk_7f8c00.
class Unk_23aa6d0 {
public:
    Unk_23aa6d0() : field_8(0x0f4b17a579f18960), field_10(0x82a2b175229d6a5b), field_18(0) {}
    virtual ~Unk_23aa6d0() {}

    u64 field_8;
    u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23aa6d0) == 0x20, "Unk_23aa6d0");

u64 Unk_7f8c00(void* random, u64 max);

// The object at +0xb0 (vtable 0x71023baba8, 0xb8 bytes;
// src/unsorted/virtual/Unk_8c1990.cpp has its destructor).
class Unk_23bab98 : public Unk_239a4c0 {
public:
    Unk_23bab98();
    ~Unk_23bab98() override;

    u8 _58[0x60];
};
static_assert(sizeof(Unk_23bab98) == 0xb8, "Unk_23bab98");

// The object at +0xb8 (vtable 0x71023bac10, 0x2b0 bytes): its constructor
// doesn't use its first parameter.
class Unk_23bac00 : public Unk_239a4c0 {
public:
    Unk_23bac00(Unk_239a418_Allocator* allocator,
                Unk_7c2d80_Main* main,
                void* arg3,
                Unk_7fe1d0* arg4,
                u64 seed);
    ~Unk_23bac00() override;

    u8 _58[0x258];
};
static_assert(sizeof(Unk_23bac00) == 0x2b0, "Unk_23bac00");

// The class on Unk_23bb228 with vtable 0x71023bb2b0 (0x1a8 bytes): its vf6 is
// src/unsorted/virtual/Unk_8c67d0.cpp's.
class Unk_23bb2a0 : public Unk_23bb228 {
public:
    Unk_23bb2a0(Unk_239a418_Allocator* allocator,
                const Unk_8c6550_Ref<Unk_239a4c0>& arg2,
                Unk_7c2d80_Main* main,
                Unk_7fe1d0* arg4,
                void* arg5,
                u64 seed,
                u32 mask,
                u8 arg8);
    ~Unk_23bb2a0() override;
    void vf5() override;
    u8 vf6() override;

    void Unk_8c6e00(const u8* arg1, u8 arg2, u8 arg3, u16 arg4, bool arg5);
    void Unk_8c6e80();
    void Unk_8c6ef0();

    Unk_7c2d80_Main* field_68;
    Unk_7fe1d0* field_70;
    Unk_7ecc90_Con* field_78 = nullptr;
    void* field_80 = nullptr;
    Unk_23aa6d0 field_88;
    Unk_8c6550_Ref<Unk_239a4c0> field_a8;
    Unk_8c6550_Ref<Unk_23bab98> field_b0;
    Unk_8c6550_Ref<Unk_23bac00> field_b8;
    u8 field_c0 = 0x1f;
    u8 field_c1 = 5;
    u8 field_c2 = 5;
    u8 field_c3 = 5;
    u8 field_c4;
    u32 field_c8 = 0;
    u16 field_cc = 0;
    bool field_ce;
    u32 field_d0 = 0;
    u32 field_d4[5][4] = {};
    u32 field_124[5][4] = {};
    u8 field_174[4] = {};
    u8 _178[0x1e] = {};
    u32 field_198 = 0;
    u8 field_19c = 0;
    u8 field_19d = 5;
    u8 field_19e = 0;
    u8 field_19f = 0;
    u8 field_1a0 = 0;
    u8 field_1a1 = 0;
    u8 field_1a2 = 0;
};
static_assert(sizeof(Unk_23bb2a0) == 0x1a8, "Unk_23bb2a0");
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_ce, 0xce);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_d4, 0xd4);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_124, 0x124);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_174, 0x174);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_198, 0x198);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_19c, 0x19c);
PKMN_OFFSET_ASSERT(Unk_23bb2a0, field_1a2, 0x1a2);
