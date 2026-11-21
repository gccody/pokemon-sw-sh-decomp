#pragma once
// The class with the vtables 0x7102381490 and 0x71023815b0 (what a plug-in
// gets to ask about the sound it is in), as far as its members in
// Unk_369950.cpp and Unk_36a200.cpp need it. Placeholder names;
// `Unk_369950_Base2` is the object seen from its second base, 8 bytes in.
#include <types.h>

// What the context refers to.
struct Unk_369950_Sound {
    struct Params {
        u8 _0[0x4c];
        u8 field_4c_0 : 3;
    };

    u8 _0[0x110];
    f32 field_110;
    f32 field_114;
    f32 field_118;
    u8 field_11c;
    u8 _11d[0x23];
    Params* field_140;
    u8 _148[0xc];
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
    virtual void vf2();
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

struct Unk_369950_T {
    u8 _0[0x48];
    Unk_3d08c0_Self* field_48;
    u8 _50[0x78];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_369950_T, field_c8, 0xc8);

struct Unk_369950_Base2 {
    u8 _0[0x40];
    Unk_3d08c0_Self* field_40;
    u8 _48[0x78];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_369950_Base2, field_c0, 0xc0);
