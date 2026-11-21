// Scope: common
// The effect between a source and what plays it that gives other samples
// than it gets (on the class with the vtable 0x7102384c90): two buffers.
// Written from the executable. Placeholder names.
#include "Unk_2384c90.h"
#include "Unk_3dd7b0.h"

struct Unk_390440;
void Unk_390440_set(Unk_390440* self);
void Unk_3dce10(Unk_2384c90_T* self);

// The same up to the effect, then its own members.
struct Unk_3dd380_T {
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
    u8 _a0[8];
    Unk_3dd7b0_Buffer field_a8;  // what it gets
    Unk_3dd7b0_Buffer field_e0;  // what it gives
    u8 _118[8];
    u32 field_120;  // samples it got
    u32 field_124;  // samples the effect was asked for
};
PKMN_OFFSET_ASSERT(Unk_3dd380_T, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_3dd380_T, field_e0, 0xe0);

// 0x71003dd380
void Unk_3dd380(Unk_3dd380_T* self) {
    if (self->field_e0.field_0 != nullptr) {
        Unk_3047c0(Unk_2381488, self->field_e0.field_0);
        self->field_e0.ClearAll();
    }
}

// 0x71003dd3e0
void Unk_3dd3e0(Unk_3dd380_T* self) {
    self->field_98->vf3();
    self->field_8->vf3();
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_a8));
    self->field_a8.Clear();
    self->field_88 = false;
    self->field_8->vf7();
}

// 0x71003dd450
void Unk_3dd450(Unk_3dd380_T* self, u32 arg1) {
    if (arg1 != 2) {
        self->field_98->vf3();
        self->vf13();
    }
    reinterpret_cast<Unk_2384c90*>(self)->vf5(arg1);
}

// 0x71003dd560
void Unk_3dd560(Unk_3dd380_T* self) {
    self->vf12();
    Unk_3dce10(reinterpret_cast<Unk_2384c90_T*>(self));
    if (self->field_e0.field_0 != nullptr) {
        Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_e0));
        Unk_3047c0(Unk_2381488, self->field_e0.field_0);
        self->field_e0.field_0 = nullptr;
        self->field_e0.field_10 = 0;
        self->field_e0.field_12 = 0;
    }
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_a8));
}

// 0x71003dd6e0
u32 Unk_3dd6e0(Unk_3dd380_T* self) {
    if (self->field_8 != nullptr)
        self->field_8->vf3();
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_a8));
    self->field_a8.Clear();
    return 1;
}

// The effect, asked for samples.
struct Unk_3dd600_Plugin {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9(u32* count);
};

extern u16 Unk_2382e78;  // the samples of a buffer

// 0x71003dd600: what the effect needs is taken from what it gets its samples from
u32 Unk_3dd600(Unk_3dd380_T* self, u32* count) {
    if (self->field_88)
        return 0x11;
    u32 left = *count;
    u32 result = reinterpret_cast<Unk_3dd600_Plugin*>(self->field_98)->vf9(&left);
    self->field_124 += left;
    left = self->field_124 - self->field_120;
    while (left >= Unk_2382e78 && result == 0x2d) {
        u32 taken = Unk_2382e78;
        result = self->field_8->vf4(&taken);
        left -= taken;
        self->field_120 += taken;
        self->field_88 = result == 0x11;
    }
    return result;
}
