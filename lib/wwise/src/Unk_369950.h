#pragma once
// The class with the vtables 0x7102381490 and 0x71023815b0 (what a plug-in
// gets to ask about the sound it is in), as far as its members in
// Unk_369950.cpp and Unk_36a200.cpp need it. Placeholder names;
// `Unk_369950_Base2` is the object seen from its second base, 8 bytes in.
#include "Unk_360c20.h"

// What a notification about a parameter carries.
struct Unk_361770_Params {
    Unk_361770_Params()
        : field_0(0), field_8(0), field_9(0xff), field_10(0), field_18(0), field_20(0), field_24(1),
          field_28(0) {}

    u64 field_0;
    u8 field_8;
    u8 field_9;
    u64 field_10;
    u64 field_18;
    u32 field_20;
    u32 field_24;
    u64 field_28;
};
PKMN_SIZE_ASSERT(Unk_361770_Params, 0x30);

// What the context refers to.
struct Unk_369950_Sound {
    struct Params {
        u8 _0[0x4c];
        u8 field_4c_0 : 3;
    };

    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(Unk_361770_Params* params, u32 a2);

    u64 field_8;
    u64 field_10[6];  // what its values are looked up by
    u8 _40[0x10];
    u8 field_50[0xc0];
    f32 field_110;
    f32 field_114;
    f32 field_118;
    u8 field_11c;
    u8 _11d[0x23];
    Params* field_140;
    u64 field_148;
    u32 _150;
    u16 field_154_0 : 2;
    u16 field_154_2 : 2;
    u16 field_154_4 : 12;
};
PKMN_OFFSET_ASSERT(Unk_369950_Sound, field_140, 0x140);

// What the context is of: the object Unk_3d08c0.cpp's functions take, with
// the name they have for it.
struct Unk_3d08c0_Self {
    virtual void vf0();
    virtual void vf1();
    virtual u64 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 a1, u64 a2);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    struct A {
        u8 _0[0x10];
        struct B {
            u8 _0[0x38];
            struct C {
                struct D {
                    u8 _0[0x38];
                    u16 field_38;
                }* field_0;
            }* field_38;
        }* field_10;
    };

    u8 _8[0x18];
    union {
        Unk_369950_Sound* field_20;
        A* field_20_a;
    };
};

// A pair of arrays the context owns (as lib/wwise/leaf has it).
struct Unk_36a5e0 {
    u64 field_0;
    u32 field_8;
    u64 field_10;
    u64 field_18;
};

struct Unk_3d45c0;

// The context (0x2b0 bytes). Its second base is 8 bytes in; the object at
// 0x68 is one that refers to an Unk_360c20_T, the one at 0xe0 has the vtable
// 0x7102384248 and a member of 0x1a0 bytes.
struct Unk_369950_T {
    void** vptr;
    void** vptr2;
    f32 field_10[4];
    Unk_36a5e0 field_20;
    Unk_369950_T* field_40;  // next
    Unk_3d08c0_Self* field_48;
    Unk_3d45c0* field_50;
    void* field_58;
    u64 field_60;
    Unk_362360_T field_68;
    u64 field_c8;
    u64 field_d0;
    u64 _d8;
    void** field_e0;
    u64 field_e8;
    alignas(16) u8 field_f0[0x1a0];
    f32 field_290;
    f32 field_294;
    f32 field_298;
    u32 field_29c;
    u32 field_2a0;
    u8 field_2a4_0 : 1;
    u8 field_2a4_1 : 1;
    u8 field_2a4_2 : 1;
};
PKMN_OFFSET_ASSERT(Unk_369950_T, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_369950_T, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_369950_T, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_369950_T, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_369950_T, field_290, 0x290);
PKMN_OFFSET_ASSERT(Unk_369950_T, field_2a0, 0x2a0);
PKMN_SIZE_ASSERT(Unk_369950_T, 0x2b0);

struct Unk_369950_Base2 {
    u8 _0[0x40];
    Unk_3d08c0_Self* field_40;
    u8 _48[0x78];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_369950_Base2, field_c0, 0xc0);
