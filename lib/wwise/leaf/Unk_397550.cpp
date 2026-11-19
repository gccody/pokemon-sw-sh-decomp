// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_397550 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u8 _28[0x8];
    u64 field_30;
    u64 field_38;
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_397550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_397550, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_397550, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_397550, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_397550, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_397550, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_397550, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_397550, field_40, 0x40);

// 0x7100397550
void Unk_397550_set(Unk_397550* self) {
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_0 = 0;
    self->field_40 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
}

extern u64 Unk_24bbc18;
void Unk_378420(u64, u32, void*, u64);

// 0x7100399c50
void Unk_399c50_call(u32 self, void* value, u64 arg2) {
    Unk_378420(Unk_24bbc18, self, value, arg2);
}

// 0x710039a900
void Unk_39a900_update(u64 /*unused*/) {
}

void Unk_39b740(void*, u64, u32);

// 0x710039b730
void Unk_39b730_call(void* self, u64 value) {
    Unk_39b740(self, value, 0x39);
}

void Unk_39b740(void*, u64, u32);

// 0x710039b8b0
void Unk_39b8b0_call(void* self, u64 value) {
    Unk_39b740(self, value, 0x39);
}

struct Unk_39f090_0 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_39f090_0, field_0, 0x0);

struct Unk_39f090 {
    Unk_39f090_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_39f090, field_0, 0x0);

// 0x710039f090
u16 Unk_39f090_get(const Unk_39f090* self) {
    return self->field_0->field_0;
}

struct Unk_3a45b0 {
    u8 _0[0x40];
    void* field_40;
};
PKMN_OFFSET_ASSERT(Unk_3a45b0, field_40, 0x40);

void Unk_386bc0(void*, void*, void*, u32);

// 0x71003a45b0
void Unk_3a45b0_call(Unk_3a45b0* self, void* value, bool arg2) {
    if (self->field_40 != nullptr) {
        Unk_386bc0(self->field_40, self, value, arg2);
        self->field_40 = nullptr;
    }
}

struct Unk_3a56f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_3a56f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3a56f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3a56f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3a56f0, field_18, 0x18);

// 0x71003a56f0
void Unk_3a56f0_set(Unk_3a56f0* self) {
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

// 0x71003a5700
void Unk_3a5700_update(u64 /*unused*/) {
}
