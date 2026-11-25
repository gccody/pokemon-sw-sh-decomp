// Scope: common
// Setters of the interface at +0x90 of the gflib3 object with vtable
// 0x710239dbf0 (Unk_239dbe0). In the original they're this-adjusting thunks
// of the object's overriders with the body inlined; written here on the
// placeholder class of that vtable (0x710239e0d0), as
// src/unsorted/virtual/Unk_620110.cpp writes its other functions.
#include <arm_neon.h>

#include <types.h>

#include "gflib3/Unk_239a418_Make.h"

// A vector of four floats held in a NEON register: copying it copies the two
// halves in turn.
struct Unk_239e0c0_Vector {
    float32x4_t value;
};
static_assert(sizeof(Unk_239e0c0_Vector) == 0x10, "Unk_239e0c0_Vector");

class Unk_239e0c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual void vf26();
    virtual u32 vf27();
    virtual void vf28(f32 fvalue);
    virtual f32 vf29();
    virtual void vf30(const Unk_239e0c0_Vector& value);
    virtual void vf31(Unk_239a418* object);
    virtual u8* vf32();

    u8 _8[0x48];
    Unk_239e0c0_Vector field_50;
    u8 _60[0x40];
    Unk_239a418_Ref<Unk_239a418_Handle> field_a0;
};
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_a0, 0xa0);

// 0x71006376c0
void Unk_239e0c0::vf30(const Unk_239e0c0_Vector& value) {
    field_50 = value;
}

// 0x71006376e0
void Unk_239e0c0::vf31(Unk_239a418* object) {
    Unk_Assign(field_a0, object->vf2());
}
