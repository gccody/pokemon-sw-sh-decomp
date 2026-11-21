#pragma once
// What the samples of a sound come from (vtable 0x7102384dd0) and the playing
// context it has, as far as its functions use it. Written from the
// executable. Placeholder names.
#include <types.h>

// A playing context.
struct Unk_3dd7b0_Ctx {
    u8 _0[0xa];
    u8 field_a_0 : 4;
    u8 field_a_4 : 1;
    u8 _b[0x1cd];
    u32 field_1d8;
    u8 _1dc[0x2c];
    u32 field_208;
    u8 _20c[0x5c];
    u16 field_268;
    u8 _26a;
    // 40 bits of flags, not aligned.
    struct __attribute__((packed)) {
        u64 field_26b_0 : 22;
        u64 field_26b_22 : 1;
        u64 field_26b_23 : 17;
    };
};
PKMN_OFFSET_ASSERT(Unk_3dd7b0_Ctx, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(Unk_3dd7b0_Ctx, field_208, 0x208);
PKMN_OFFSET_ASSERT(Unk_3dd7b0_Ctx, field_268, 0x268);

// Samples and what was done to get them: 0x38 bytes.
struct Unk_3dd7b0_Buffer {
    void* field_0;
    u32 field_8;
    u32 field_c;  // state
    u16 field_10;  // how many samples a channel has room for
    u16 field_12;  // and how many it has
    u16 field_14;
    u8 _16[2];
    u64 field_18;
    u8 _20[0x10];
    u32 field_30;  // result
};
PKMN_SIZE_ASSERT(Unk_3dd7b0_Buffer, 0x38);

struct Unk_3dd7b0_T {
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
    virtual u32 vf10();
    virtual void vf11();
    virtual void vf12(Unk_3dd7b0_Buffer* buffer);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();

    u64 field_8;
    u64 field_10;
    Unk_3dd7b0_Ctx* field_18;
    u8 field_20_0 : 1;
    u8 field_20_1 : 1;
};
PKMN_OFFSET_ASSERT(Unk_3dd7b0_T, field_18, 0x18);

extern void* Unk_24bbc10;

void Unk_3dd7b0(Unk_3dd7b0_T* self, Unk_3dd7b0_Ctx* ctx);
u32 Unk_3ddc20(Unk_3dd7b0_T* self);
