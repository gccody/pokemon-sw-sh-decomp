// Scope: common
// What changes a source's speed (vtable 0x7102384858): the state at 0x10
// and two buffers. Written from the executable. Placeholder names.
#include "Unk_3dd7b0.h"

struct Unk_390440;
struct Unk_390500;
struct Unk_3d7680;
struct Unk_3d7690;
extern void* Unk_2384858[];

void Unk_390440_set(Unk_390440* self);
void Unk_390500_call(Unk_390500* self);
void Unk_3d6da0_update(u64 arg);
void Unk_3d7680_set(Unk_3d7680* self);
void Unk_3d7690_call(const Unk_3d7690* self);

// What it gets its samples from.
struct Unk_2384858_Prev {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6(u32 arg1, bool arg2);
    virtual u32 vf7();
};

// The state: 0x60 bytes.
struct Unk_2384858_State {
    u8 _0[0x20];
    u64 field_20;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
    u64 field_38;
    u8 _40[8];
    bool field_48;
    u8 _49[7];
    u32 field_50;
    f32 field_54;
    f32 field_58;
    u8 field_5c_0 : 2;
    u8 field_5c_2 : 6;
    u8 field_5d;
    u8 _5e;
    bool field_5f;
};
PKMN_SIZE_ASSERT(Unk_2384858_State, 0x60);

struct Unk_2384858_T {
    void** field_0;  // vptr
    Unk_2384858_Prev* field_8;
    Unk_2384858_State field_10;
    Unk_3dd7b0_Buffer field_70;
    Unk_3dd7b0_Buffer field_a8;
    u8 _e0[8];
    Unk_3dd7b0_Ctx* field_e8;
    bool field_f0;
    bool field_f1;
};
PKMN_OFFSET_ASSERT(Unk_2384858_T, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_2384858_T, field_e8, 0xe8);

// 0x71003d6930
void Unk_3d6930(Unk_2384858_T* self) {
    if (self->field_a8.field_0 != nullptr) {
        Unk_390500_call(reinterpret_cast<Unk_390500*>(&self->field_a8));
        // ClearAll() with the state's count reset before its last two stores.
        self->field_a8.field_c = 0x2b;
        self->field_a8.field_10 = 0;
        self->field_a8.field_12 = 0;
        self->field_a8.field_18 = 0;
        self->field_a8.field_20 = 0xffffffff;
        self->field_a8.field_24 = 1.0f;
        self->field_a8.field_0 = nullptr;
        self->field_a8.field_14 = 0;
        self->field_10.field_2c = 0;
        self->field_a8.field_28 = 0xffffffff;
        self->field_a8.field_2c = 1;
    }
}

// 0x71003d6bd0
u32 Unk_3d6bd0(Unk_2384858_T* self, u32 arg1, bool arg2) {
    if (arg1 == 1)
        self->field_70.field_12 = 0;
    if (self->field_f0)
        return 1;
    return self->field_8->vf6(arg1, arg2);
}

// 0x71003d6c00
u32 Unk_3d6c00(Unk_2384858_T* self) {
    self->field_8->vf3();
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_70));
    self->field_70.Clear();
    Unk_3d7680_set(reinterpret_cast<Unk_3d7680*>(&self->field_10));
    if (self->field_f0)
        return 1;
    return self->field_8->vf7();
}

// 0x71003d6ca0
void Unk_3d6ca0(Unk_2384858_T* self) {
    if (self->field_a8.field_0 != nullptr) {
        Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_a8));
        Unk_390500_call(reinterpret_cast<Unk_390500*>(&self->field_a8));
    }
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_70));
    self->field_e8 = nullptr;
    Unk_3d7690_call(reinterpret_cast<const Unk_3d7690*>(&self->field_10));
}

// 0x71003d6d10: the destructor
void Unk_3d6d10(Unk_2384858_T* self) {
    self->field_0 = Unk_2384858 + 2;
    Unk_3d6da0_update(reinterpret_cast<u64>(&self->field_10));
}

// 0x71003d6d30: the deleting destructor
void Unk_3d6d30(Unk_2384858_T* self) {
    self->field_0 = Unk_2384858 + 2;
    Unk_3d6da0_update(reinterpret_cast<u64>(&self->field_10));
    operator delete(self);
}
