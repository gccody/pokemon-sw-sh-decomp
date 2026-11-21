#pragma once
// An effect between a source and what plays it (vtable 0x7102384c90): what
// it gets its samples from, an effect and the samples of the effect.
// Written from the executable. Placeholder names.
#include "Unk_24df148.h"

// What it gets its samples from.
struct Unk_2384c90_Prev {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4(u32* count);
    virtual void vf5(u32 arg1);
    virtual u32 vf6(u64 arg1, bool arg2);
    virtual void vf7();
};

// The effect.
struct Unk_2384c90_Plugin {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* alloc);
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7(void* alloc, void* arg2, void* arg3, void* info);
    virtual void vf8(void* buffer);
    virtual void vf9(u32 count);
};

// What it is told about the sound.
struct Unk_2384c90_Info {
    u32 field_0;
    u32 field_4;
};

class Unk_2384c90 {
public:
    void vf5(u32 arg1);
};

struct Unk_2384c90_T {
    virtual void vf0();
    virtual void vf1();
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

    Unk_2384c90_Prev* field_8;
    void* field_10;
    Unk_24df148_Object* field_18;
    Unk_24df148_SlotCtx field_20;
    bool field_88;
    u16 field_8a;
    u8 field_8c;
    u32 field_90;
    Unk_2384c90_Plugin* field_98;
    void* field_a0;  // its samples
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_2384c90_T, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2384c90_T, field_98, 0x98);

struct Unk_362360_T;
extern void* Unk_2380d10;
extern void* const Unk_2380be8[8];
extern void* Unk_2384c90_Vtable[];

void Unk_362360(Unk_362360_T* self);
u32 Unk_3dcd40(Unk_2384c90_T* self, Unk_2384c90_Plugin* plugin, void* arg2, u32 arg3, void* arg4);
void Unk_3dce10(Unk_2384c90_T* self);

static inline void Unk_2380be8_Dtor(Unk_24df148_SlotCtx* self) {
    *reinterpret_cast<void* const**>(self) = Unk_2380be8 + 2;
    reinterpret_cast<void (*)(Unk_24df148_SlotCtx*)>(Unk_2380be8[7])(self);
}
