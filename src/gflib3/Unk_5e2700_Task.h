#pragma once
// The layout of Unk_239a360 (vtable 0x710239a370, 0x190 bytes), a class on
// Unk_239a418 whose constructor (0x71005e2180) calls Unk_239a418's: it
// waits until it's done (a mutex, a condition variable and a flag) and holds
// two vectors of listeners and a weak reference to an object. Its destructor
// is 0x71005e2ee0, its vf3 (destroy and free) waits first. The class itself
// is declared by a generator (src/unsorted/types/Unk_5e30f0.cpp, its type
// getter): its functions here are placeholder free functions over this
// layout. Placeholder names: rename once the class is known.
#include <vector>

#include <nn/os.h>
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

// A weak reference: an object and the handle that keeps the object's count
// (src/gflib3/Unk_239a418.h). Copying it adds a reference to the handle,
// dropping it drops one.
struct Unk_239a360_Weak {
    Unk_239a360_Weak() : field_0(0), field_8(nullptr) {}
    Unk_239a360_Weak(const Unk_239a360_Weak& other)
        : field_0(other.field_0), field_8(other.field_8) {
        if (field_8)
            static_cast<Unk_239a458*>(field_8)->vf4();
    }
    ~Unk_239a360_Weak() {
        if (field_8)
            static_cast<Unk_239a458*>(field_8)->vf5();
    }
    Unk_239a360_Weak& operator=(const Unk_239a360_Weak& other) {
        field_0 = other.field_0;
        Unk_239a418_Handle* handle = other.field_8;
        if (handle)
            static_cast<Unk_239a458*>(handle)->vf4();
        Unk_239a418_Handle* old = field_8;
        field_8 = handle;
        if (old)
            static_cast<Unk_239a458*>(old)->vf5();
        return *this;
    }

    u64 field_0;
    Unk_239a418_Handle* field_8;
};
PKMN_SIZE_ASSERT(Unk_239a360_Weak, 0x10);

// Whether the weak reference's object is still there (0x71005e3aa0: its
// handle's object count isn't zero).
bool Unk_5e3aa0(const Unk_239a360_Weak* weak);

// What's told when the object is done (slot 0).
class Unk_239a360_Listener {
public:
    virtual void vf0();
};

// The member at +0x90 (0x18 bytes), which 0x71005e6090 hands its +0x10 to
// an SDK function.
struct Unk_239a360_Field90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_SIZE_ASSERT(Unk_239a360_Field90, 0x18);

void Unk_5e6090(Unk_239a360_Field90* field);

using Unk_239a360_Listeners =
    std::vector<Unk_239a360_Listener*, Unk_2771620_Allocator<Unk_239a360_Listener*>>;

class Unk_239a360_Self : public Unk_239a418 {
public:
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    u32 field_88;
    Unk_239a360_Field90 field_90;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    Unk_239a360_Listeners field_b0;
    Unk_239a360_Listeners field_e0;
    nn::os::MutexType field_110;
    nn::os::MutexType field_130;
    nn::os::ConditionVariableType field_150;
    u64 field_158;
    Unk_239a360_Weak field_160;
    bool field_170;  // done
    bool field_171;
    u64 field_178;
    u64 field_180;
    u64 field_188;
};
PKMN_SIZE_ASSERT(Unk_239a360_Self, 0x190);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_170, 0x170);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_239a360_Self, field_188, 0x188);
