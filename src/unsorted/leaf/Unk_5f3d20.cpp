// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5f3d20 {
    u8 _0[0xe0];
    void* field_e0;
};
PKMN_OFFSET_ASSERT(Unk_5f3d20, field_e0, 0xe0);

void Unk_5f3e90(void*);

// 0x71005f3d20
void Unk_5f3d20_call(const Unk_5f3d20* self) {
    Unk_5f3e90(self->field_e0);
}

struct Unk_5f3d30 {
    u8 _0[0xe0];
    void* field_e0;
};
PKMN_OFFSET_ASSERT(Unk_5f3d30, field_e0, 0xe0);

void Unk_5f4030(void*);

// 0x71005f3d30
void Unk_5f3d30_call(const Unk_5f3d30* self) {
    Unk_5f4030(self->field_e0);
}

struct Unk_5f5760 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_5f5760, field_d8, 0xd8);

// 0x71005f5760
u64 Unk_5f5760_getFieldd8(const Unk_5f5760* self) {
    return self->field_d8;
}

void Unk_1787c60(void*, void*);

// 0x71005f7100
void Unk_5f7100_call(void* self, void* value) {
    Unk_1787c60(self, value);
}

void Unk_1787bf0(void*);

// 0x71005f7110
void Unk_5f7110_call(void* self) {
    Unk_1787bf0(self);
}

void Unk_1787c10(u64);

// 0x71005f7120
void Unk_5f7120_call(u64 self) {
    Unk_1787c10(self);
}

struct Unk_5f7190_8 {
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
};

struct Unk_5f7190 {
    u8 _0[0x8];
    Unk_5f7190_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_5f7190, field_8, 0x8);

// 0x71005f7190
void Unk_5f7190_call(const Unk_5f7190* self) {
    if (self->field_8 != nullptr) {
        self->field_8->vf12();
    }
}
