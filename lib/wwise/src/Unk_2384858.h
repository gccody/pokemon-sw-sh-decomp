#pragma once
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
    virtual void vf5(u32 arg1);
    virtual u32 vf6(u32 arg1, bool arg2);
    virtual u32 vf7();
    virtual f32 vf8();  // the pitch
};

// The state: 0x60 bytes.
struct Unk_2384858_State {
    u8 _0[0x20];
    u64 field_20;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;  // the step through the samples, 16 bits of it a fraction
    u32 field_38;  // and the one it goes to
    u32 field_3c;
    u8 _40[4];
    u32 field_44;  // how many samples are asked for
    bool field_48;
    u8 _49[7];
    u32 field_50;  // 1: one step, 2: from one step to another
    f32 field_54;  // how fast the source's samples are over how fast they are played
    f32 field_58;  // the pitch it has
    u8 field_5c;  // the kind of samples
    u8 field_5d;
    u8 _5e;
    bool field_5f;  // no pitch yet
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

// What makes the samples: by what the state does and the kind of samples.
typedef u32 (*Unk_23848b8_Fn)(Unk_3dd7b0_Buffer* in, Unk_3dd7b0_Buffer* out, u32 count,
                              Unk_2384858_State* state);
extern const Unk_23848b8_Fn Unk_23848b8[][8] __attribute__((visibility("hidden")));

void Unk_3d6ca0(Unk_2384858_T* self);
void Unk_3d63c0(Unk_2384858_T* self, Unk_3dd7b0_Buffer* buffer);
void Unk_3d71c0(Unk_2384858_State* self, bool arg1, f32 pitch);
f32 Unk_3d6db0(Unk_2384858_State* self);
