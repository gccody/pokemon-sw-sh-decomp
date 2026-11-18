// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100920c60
void Unk_920c60_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100920c70
void Unk_920c70_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_921040 {
    u8 _0[0x798];
    u64 field_798;
};
PKMN_OFFSET_ASSERT(Unk_921040, field_798, 0x798);

void Unk_14e1a00(u64, u32);

// 0x7100921040
void Unk_921040_call(const Unk_921040* self, bool value) {
    Unk_14e1a00(self->field_798, value);
}

struct Unk_921590_0 {
    u8 _0[0x768];
    u16 field_768;
};
PKMN_OFFSET_ASSERT(Unk_921590_0, field_768, 0x768);

struct Unk_921590 {
    Unk_921590_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_921590, field_0, 0x0);

// 0x7100921590
void Unk_921590_set(const Unk_921590* self) {
    self->field_0->field_768 = 0x101;
}

// 0x71009215a0
void Unk_9215a0_update() {}

struct Unk_9215b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9215b0_arg1, field_0, 0x0);

struct Unk_9215b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9215b0, field_0, 0x0);

// 0x71009215b0
void Unk_9215b0_set(const Unk_9215b0* self, Unk_9215b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9215c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9215c0_arg1, field_0, 0x0);

struct Unk_9215c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9215c0, field_0, 0x0);

// 0x71009215c0
void Unk_9215c0_set(const Unk_9215c0* self, Unk_9215c0_arg1* value) {
    value->field_0 = self->field_0;
}
