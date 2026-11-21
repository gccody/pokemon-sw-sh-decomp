#pragma once
// The objects of the list of 0x71024bcb38, linked at 0x68. Placeholder names.
#include "containers.h"

struct Unk_368a60_T {
    virtual ~Unk_368a60_T();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(u32 a1);

    u8 _8[0x60];
    Unk_368a60_T* field_68;  // next
};
PKMN_OFFSET_ASSERT(Unk_368a60_T, field_68, 0x68);

// Tells an object of the list and deletes it.
void Unk_368a60(Unk_368a60_T* object, u32 a1);
