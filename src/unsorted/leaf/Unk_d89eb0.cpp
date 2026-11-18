// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d89eb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89eb0_arg1, field_0, 0x0);

struct Unk_d89eb0_0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89eb0_0, field_0, 0x0);

struct Unk_d89eb0 {
    Unk_d89eb0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89eb0, field_0, 0x0);

void Unk_619300(u64, u32);

// 0x7100d89eb0
void Unk_d89eb0_call(const Unk_d89eb0* self, const Unk_d89eb0_arg1* value) {
    Unk_619300(value->field_0, self->field_0->field_0);
}

// 0x7100d89ed0
void Unk_d89ed0_update() {}

struct Unk_d89ee0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89ee0_arg1, field_0, 0x0);

struct Unk_d89ee0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89ee0, field_0, 0x0);

// 0x7100d89ee0
void Unk_d89ee0_set(const Unk_d89ee0* self, Unk_d89ee0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d89ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89ef0_arg1, field_0, 0x0);

struct Unk_d89ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89ef0, field_0, 0x0);

// 0x7100d89ef0
void Unk_d89ef0_set(const Unk_d89ef0* self, Unk_d89ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d89f00_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f00_arg2, field_0, 0x0);

struct Unk_d89f00_0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f00_0, field_0, 0x0);

struct Unk_d89f00 {
    Unk_d89f00_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f00, field_0, 0x0);

void Unk_619300(u64, u32);

// 0x7100d89f00
void Unk_d89f00_call(const Unk_d89f00* self, u64 /*unused*/, const Unk_d89f00_arg2* arg2) {
    Unk_619300(arg2->field_0, self->field_0->field_0);
}

// 0x7100d89f20
void Unk_d89f20_update() {}

struct Unk_d89f30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f30_arg1, field_0, 0x0);

struct Unk_d89f30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f30, field_0, 0x0);

// 0x7100d89f30
void Unk_d89f30_set(const Unk_d89f30* self, Unk_d89f30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d89f40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f40_arg1, field_0, 0x0);

struct Unk_d89f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d89f40, field_0, 0x0);

// 0x7100d89f40
void Unk_d89f40_set(const Unk_d89f40* self, Unk_d89f40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d89f50_arg1 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_d89f50_arg1, field_90, 0x90);

// 0x7100d89f50
bool Unk_d89f50_check(void* /*unused*/, const Unk_d89f50_arg1* value) {
    return value->field_90 == 1;
}

// 0x7100d89f60
void Unk_d89f60_update() {}

// 0x7100d89f70
void Unk_d89f70_update() {}

// 0x7100d89f80
void Unk_d89f80_update() {}

// 0x7100d8b430
void Unk_d8b430_update() {}

struct Unk_d8b440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d8b440_arg1, field_0, 0x0);

struct Unk_d8b440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d8b440, field_0, 0x0);

// 0x7100d8b440
void Unk_d8b440_set(const Unk_d8b440* self, Unk_d8b440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d8b450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d8b450_arg1, field_0, 0x0);

struct Unk_d8b450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d8b450, field_0, 0x0);

// 0x7100d8b450
void Unk_d8b450_set(const Unk_d8b450* self, Unk_d8b450_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100d8b460
void Unk_d8b460_update() {}

// 0x7100d8b470
void Unk_d8b470_update() {}

// 0x7100d8b480
void Unk_d8b480_update() {}

// 0x7100d8b490
void Unk_d8b490_update() {}
