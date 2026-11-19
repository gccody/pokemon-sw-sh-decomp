// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_76d9a0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_76d9a0, field_8, 0x8);

// 0x710076d9a0
u32 Unk_76d9a0_getField8(const Unk_76d9a0* self) {
    return self->field_8;
}

struct Unk_76d9b0 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_76d9b0, field_c, 0xc);

// 0x710076d9b0
u16 Unk_76d9b0_getFieldc(const Unk_76d9b0* self) {
    return self->field_c;
}

struct Unk_76e7d0_arg1 {
    u8 _0[0x8];
    u32 field_8;
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_76e7d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_76e7d0_arg1, field_c, 0xc);

struct Unk_76e7d0 {
    u8 _0[0x8];
    u32 field_8;
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_76e7d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_76e7d0, field_c, 0xc);

extern "C" void* memcpy(void*, const void*, unsigned long);

// 0x710076e7d0
void Unk_76e7d0_call(const Unk_76e7d0* self, Unk_76e7d0_arg1* value) {
    memcpy(&value->field_c, &self->field_c, 0x194);
    value->field_8 = self->field_8;
}

struct Unk_76e810 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_76e810, field_8, 0x8);

// 0x710076e810
u32 Unk_76e810_getField8(const Unk_76e810* self) {
    return self->field_8;
}

// 0x710076f430
void Unk_76f430() {}

struct Unk_770cd0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_770cd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_770cd0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_770cd0, field_18, 0x18);

// 0x7100770cd0
void Unk_770cd0_set(Unk_770cd0* self, u64 value, u64 arg2) {
    self->field_8 = arg2;
    self->field_10 = value;
    self->field_18 = 1;
}

struct Unk_770ce0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_770ce0, field_8, 0x8);

// 0x7100770ce0
bool Unk_770ce0_check(const Unk_770ce0* self) {
    return self->field_8 != 0;
}

struct Unk_770eb0 {
    u8 _0[0x19];
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_770eb0, field_19, 0x19);

// 0x7100770eb0
u8 Unk_770eb0_getField19(const Unk_770eb0* self) {
    return self->field_19;
}

struct Unk_771130_arg1 {
    u8 _0[0x148];
    u8 field_148;
};
PKMN_OFFSET_ASSERT(Unk_771130_arg1, field_148, 0x148);

void Unk_771140(void*, void*, void*);

// 0x7100771130
void Unk_771130_call(void* self, Unk_771130_arg1* value) {
    Unk_771140(self, value, &value->field_148);
}

struct Unk_771260_10 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_771260_10, field_0, 0x0);

struct Unk_771260 {
    u8 _0[0x10];
    Unk_771260_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_771260, field_10, 0x10);

// 0x7100771260
u32 Unk_771260_get(const Unk_771260* self) {
    return self->field_10->field_0;
}

struct Unk_771270_10 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_771270_10, field_4, 0x4);

struct Unk_771270 {
    u8 _0[0x10];
    Unk_771270_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_771270, field_10, 0x10);

// 0x7100771270
u32 Unk_771270_get(const Unk_771270* self) {
    return (self->field_10->field_4 >> 2) & 1;
}

extern const u8 Unk_1f0c4b8[] __attribute__((visibility("hidden")));
struct Unk_7805e0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7805e0, field_0, 0x0);

// 0x71007805e0
const u8* Unk_7805e0_update(Unk_7805e0* self) {
    self->field_0 = 0xd;
    return Unk_1f0c4b8;
}

extern const u8 Unk_1f0c4ec[] __attribute__((visibility("hidden")));
struct Unk_780600 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_780600, field_0, 0x0);

// 0x7100780600
const u8* Unk_780600_update(Unk_780600* self) {
    self->field_0 = 0xc;
    return Unk_1f0c4ec;
}

struct Unk_780a80_0 {
    virtual void vf0();
};

struct Unk_780a80_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(void*, u64, u64);
};

struct Unk_780a80 {
    Unk_780a80_0* field_0;
    Unk_780a80_8* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_780a80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_780a80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_780a80, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_780a80, field_18, 0x18);

// 0x7100780a80
void Unk_780a80_call(Unk_780a80* self) {
    Unk_780a80_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        v0->vf0();
        self->field_8->vf3(v0, self->field_10, self->field_18);
    }
}
