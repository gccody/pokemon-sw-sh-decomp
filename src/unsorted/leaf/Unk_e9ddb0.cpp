// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e9ddb0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e9ddb0, field_78, 0x78);

// 0x7100e9ddb0
bool Unk_e9ddb0_check(const Unk_e9ddb0* self) {
    return self->field_78 != 0;
}

struct Unk_e9ddc0 {
    u8 _0[0x89];
    u8 field_89;
};
PKMN_OFFSET_ASSERT(Unk_e9ddc0, field_89, 0x89);

// 0x7100e9ddc0
u8 Unk_e9ddc0_getField89(const Unk_e9ddc0* self) {
    return self->field_89;
}

struct Unk_e9fab0_60 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_e9fab0_60, field_108, 0x108);

struct Unk_e9fab0 {
    u8 _0[0x60];
    Unk_e9fab0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e9fab0, field_60, 0x60);

// 0x7100e9fab0
bool Unk_e9fab0_check(const Unk_e9fab0* self) {
    return self->field_60->field_108 != 0;
}

// 0x7100ea2450
void Unk_ea2450_update() {}

struct Unk_ea2460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2460_arg1, field_0, 0x0);

struct Unk_ea2460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2460, field_0, 0x0);

// 0x7100ea2460
void Unk_ea2460_set(const Unk_ea2460* self, Unk_ea2460_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ea2470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2470_arg1, field_0, 0x0);

struct Unk_ea2470 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2470, field_0, 0x0);

// 0x7100ea2470
void Unk_ea2470_set(const Unk_ea2470* self, Unk_ea2470_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ea24f0
void Unk_ea24f0_update() {}

struct Unk_ea2500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2500_arg1, field_0, 0x0);

struct Unk_ea2500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2500, field_0, 0x0);

// 0x7100ea2500
void Unk_ea2500_set(const Unk_ea2500* self, Unk_ea2500_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ea2510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2510_arg1, field_0, 0x0);

struct Unk_ea2510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea2510, field_0, 0x0);

// 0x7100ea2510
void Unk_ea2510_set(const Unk_ea2510* self, Unk_ea2510_arg1* value) {
    value->field_0 = self->field_0;
}

extern u64 Unk_24ba5c8;
void Unk_130e7d0(u64);

// 0x7100ea2920
u32 Unk_ea2920_call() {
    Unk_130e7d0(Unk_24ba5c8);
    return 0;
}

// 0x7100ea2950
void Unk_ea2950_update() {}

// 0x7100ea2960
void Unk_ea2960_update() {}

// 0x7100ea2970
void Unk_ea2970_update() {}
