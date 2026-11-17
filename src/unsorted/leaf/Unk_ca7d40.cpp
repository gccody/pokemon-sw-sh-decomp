// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_ca7d50();

// 0x7100ca7d40
void Unk_ca7d40_call() {
    Unk_ca7d50();
}

struct Unk_ca92b0 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_ca92b0, field_a0, 0xa0);

void Unk_caefc0(u64);

// 0x7100ca92b0
void Unk_ca92b0_call(const Unk_ca92b0* self) {
    Unk_caefc0(self->field_a0);
}

struct Unk_caa7a0 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_caa7a0, field_a0, 0xa0);

void Unk_cae8c0(u64);

// 0x7100caa7a0
void Unk_caa7a0_call(const Unk_caa7a0* self) {
    Unk_cae8c0(self->field_a0);
}

void Unk_cacf60(void*, u64, u64, u64, u32);

// 0x7100cacf50
void Unk_cacf50_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_cacf60(self, value, arg2, arg3, 0);
}

void Unk_cacf60(void*, u64, u64, u64, u32);

// 0x7100cad140
void Unk_cad140_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_cacf60(self, value, arg2, arg3, 1);
}

void Unk_caeb90(void*, u64, u64, u64, u32);

// 0x7100caeb80
void Unk_caeb80_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_caeb90(self, value, arg2, arg3, 0);
}

void Unk_caeb90(void*, u64, u64, u64, u32);

// 0x7100caed70
void Unk_caed70_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_caeb90(self, value, arg2, arg3, 1);
}

void Unk_caf7d0(void*, u64, u64, u64, u32);

// 0x7100caf7c0
void Unk_caf7c0_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_caf7d0(self, value, arg2, arg3, 0);
}

void Unk_caf7d0(void*, u64, u64, u64, u32);

// 0x7100caf9b0
void Unk_caf9b0_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_caf7d0(self, value, arg2, arg3, 1);
}

struct Unk_cb1610 {
    u8 _0[0x54];
    u32 field_54;
    u16 field_58;
    bool field_5a;
    u8 _5b[0x1];
    u16 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_cb1610, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_cb1610, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_cb1610, field_5a, 0x5a);
PKMN_OFFSET_ASSERT(Unk_cb1610, field_5c, 0x5c);

// 0x7100cb1610
void Unk_cb1610_set(Unk_cb1610* self, bool value) {
    self->field_54 = 0;
    self->field_58 = 0;
    self->field_5c = 0;
    self->field_5a = value;
}

struct Unk_cb33d0 {
    u8 _0[0x80];
    u64 field_80;
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_cb33d0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_cb33d0, field_88, 0x88);

// 0x7100cb33d0
void Unk_cb33d0_set(Unk_cb33d0* self) {
    self->field_80 = 0xcbf29ce484222645;
    self->field_88 = 0;
}

struct Unk_cb3460 {
    u8 _0[0x98];
    u32 field_98;
    u16 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_cb3460, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_cb3460, field_9c, 0x9c);

// 0x7100cb3460
void Unk_cb3460_set(Unk_cb3460* self) {
    self->field_98 = 0;
    self->field_9c = 0;
}

struct Unk_cb3470_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cb3470_arg1, field_0, 0x0);

struct Unk_cb3470_arg2 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cb3470_arg2, field_0, 0x0);

struct Unk_cb3470 {
    u8 _0[0x98];
    u32 field_98;
    u16 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_cb3470, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_cb3470, field_9c, 0x9c);

// 0x7100cb3470
void Unk_cb3470_set(Unk_cb3470* self, const Unk_cb3470_arg1* value, const Unk_cb3470_arg2* arg2) {
    self->field_98 = value->field_0;
    self->field_9c = arg2->field_0;
}
