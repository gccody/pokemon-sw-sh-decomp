// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_69a3e0_0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_69a3e0_0 {
    virtual void vf0();
    Unk_69a3e0_0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_69a3e0_0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_69a3e0_0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_69a3e0_0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_69a3e0_0, field_20, 0x20);

struct Unk_69a3e0 {
    Unk_69a3e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a3e0, field_0, 0x0);

// 0x710069a3e0
void Unk_69a3e0_call(Unk_69a3e0* self) {
    Unk_69a3e0_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        Unk_69a3e0_0_8* v1 = v0->field_8;
        u64 v2 = v0->field_10;
        u64 v3 = v0->field_18;
        u64 v4 = v0->field_20;
        v0->vf0();
        v1->vf3(v2, v3, v4);
    }
}

// 0x710069a490
void Unk_69a490_update() {}

struct Unk_69a4a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4a0_arg1, field_0, 0x0);

struct Unk_69a4a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4a0, field_0, 0x0);

// 0x710069a4a0
void Unk_69a4a0_set(const Unk_69a4a0* self, Unk_69a4a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69a4b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4b0_arg1, field_0, 0x0);

struct Unk_69a4b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4b0, field_0, 0x0);

// 0x710069a4b0
void Unk_69a4b0_set(const Unk_69a4b0* self, Unk_69a4b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710069a510
void Unk_69a510_update() {}

struct Unk_69a520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a520_arg1, field_0, 0x0);

struct Unk_69a520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a520, field_0, 0x0);

// 0x710069a520
void Unk_69a520_set(const Unk_69a520* self, Unk_69a520_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69a530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a530_arg1, field_0, 0x0);

struct Unk_69a530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a530, field_0, 0x0);

// 0x710069a530
void Unk_69a530_set(const Unk_69a530* self, Unk_69a530_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69bde0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69bde0, field_50, 0x50);

void Unk_69a540(void*, void*);

// 0x710069bde0
void Unk_69bde0_call(const Unk_69bde0* self, void* value) {
    Unk_69a540(self->field_50, value);
}

struct Unk_69bdf0_50 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_69bdf0_50, field_b0, 0xb0);

struct Unk_69bdf0 {
    u8 _0[0x50];
    Unk_69bdf0_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69bdf0, field_50, 0x50);

// 0x710069bdf0
u8 Unk_69bdf0_get(const Unk_69bdf0* self) {
    return self->field_50->field_b0;
}

struct Unk_69c1e0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69c1e0, field_50, 0x50);

void Unk_69b100(void*, u32, void*, void*, void*);

// 0x710069c1e0
void Unk_69c1e0_call(const Unk_69c1e0* self, u32 value, void* arg2, void* arg3, void* arg4) {
    Unk_69b100(self->field_50, value, arg2, arg3, arg4);
}

struct Unk_69c250_50 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_69c250_50, field_68, 0x68);

struct Unk_69c250 {
    u8 _0[0x50];
    Unk_69c250_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69c250, field_50, 0x50);

u32 Unk_418310(u64);

// 0x710069c250
bool Unk_69c250_call(const Unk_69c250* self) {
    u32 r0 = Unk_418310(self->field_50->field_68);
    return r0 == 0;
}
