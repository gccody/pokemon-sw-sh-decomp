// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_13ff280 {
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
    u8 _8[0x278];
    u8 field_280;
};
PKMN_OFFSET_ASSERT(Unk_13ff280, field_280, 0x280);

void Unk_13a3250();
void Unk_13a33c0(void*);
void Unk_66b8c0(void*);

// 0x71013ff280
void Unk_13ff280_call(Unk_13ff280* self) {
    if (self->field_280 != 0) {
        Unk_13a3250();
        Unk_66b8c0(self);
        self->vf12();
        Unk_13a33c0(self);
    }
}

struct Unk_1400490 {
    u8 _0[0x1f8];
    u64 field_1f8;
    u8 _200[0x8];
    u32 field_208;
    u32 field_20c;
    u32 field_210;
    u32 field_214;
};
PKMN_OFFSET_ASSERT(Unk_1400490, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_1400490, field_208, 0x208);
PKMN_OFFSET_ASSERT(Unk_1400490, field_20c, 0x20c);
PKMN_OFFSET_ASSERT(Unk_1400490, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_1400490, field_214, 0x214);

// 0x7101400490
void Unk_1400490_set(Unk_1400490* self, u64 value, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    self->field_1f8 = value;
    self->field_208 = arg2;
    self->field_20c = arg3;
    self->field_210 = arg4;
    self->field_214 = arg5;
}

struct Unk_1400540 {
    u8 _0[0x200];
    u64 field_200;
    u8 _208[0x10];
    u32 field_218;
    u32 field_21c;
    u32 field_220;
    u32 field_224;
};
PKMN_OFFSET_ASSERT(Unk_1400540, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_1400540, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_1400540, field_21c, 0x21c);
PKMN_OFFSET_ASSERT(Unk_1400540, field_220, 0x220);
PKMN_OFFSET_ASSERT(Unk_1400540, field_224, 0x224);

// 0x7101400540
void Unk_1400540_set(Unk_1400540* self, u64 value, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    self->field_200 = value;
    self->field_218 = arg2;
    self->field_21c = arg3;
    self->field_220 = arg4;
    self->field_224 = arg5;
}

void Unk_1401490(void*, u64, u64, u64, u64, u64);

// 0x7101401b20
void Unk_1401b20_call(void* self, u64 value, u64 arg2, u64 arg3, u64 arg4) {
    Unk_1401490(self, 0xcbf29ce484222645, value, arg2, arg3, arg4);
}
