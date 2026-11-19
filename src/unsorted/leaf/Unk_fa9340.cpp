// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fa9340 {
    u8 _0[0x38];
    u32 field_38;
    u8 _3c[0x254];
    u8 field_290;
};
PKMN_OFFSET_ASSERT(Unk_fa9340, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_fa9340, field_290, 0x290);
void Unk_fa9190(void*, u32, u32, u32, u32, u64, u64, u64);

// 0x7100fa9340
void Unk_fa9340_update(Unk_fa9340* self, u32 value, u64 arg2, u64 arg3, u64 arg4) {
    if (self->field_290 != 0) {
        return;
    }
    self->field_38 = 0;
    Unk_fa9190(self, 1, 1, 0, value, arg2, arg3, arg4);
}

struct Unk_fa9870 {
    u8 _0[0x38];
    u64 field_38;
    u8 _40[0x250];
    u8 field_290;
};
PKMN_OFFSET_ASSERT(Unk_fa9870, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_fa9870, field_290, 0x290);
void Unk_fa9190(void*, u32, u32, u32, u32, u64, u64, u64);

// 0x7100fa9870
void Unk_fa9870_update(Unk_fa9870* self, u32 value, u64 arg2, u64 arg3, u64 arg4) {
    if (self->field_290 != 0) {
        return;
    }
    self->field_38 = 0xffffffff00000002;
    Unk_fa9190(self, 0, 0, 1, value, arg2, arg3, arg4);
}

struct Unk_fa98f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_fa98f0, field_28, 0x28);

void Unk_eb8e80(u64);

// 0x7100fa98f0
void Unk_fa98f0_call(const Unk_fa98f0* self) {
    Unk_eb8e80(self->field_28);
}

struct Unk_fa9900 {
    u8 _0[0x28];
    u64 field_28;
    u8 _30[0x58];
    u8 field_88;
    u8 _89[0x3];
    u32 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_fa9900, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_fa9900, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_fa9900, field_8c, 0x8c);

void Unk_eb8a80(u64, u32);

// 0x7100fa9900
void Unk_fa9900_call(Unk_fa9900* self) {
    if (self->field_88 != 0) {
        if (self->field_8c != 1)
            return;
        Unk_eb8a80(self->field_28, 1);
        self->field_8c = 2;
        self->field_88 = 1;
    }
}

struct Unk_faacd0_0 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_faacd0_0, field_7c, 0x7c);

struct Unk_faacd0 {
    Unk_faacd0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_faacd0, field_0, 0x0);

// 0x7100faacd0
void Unk_faacd0_set(const Unk_faacd0* self) {
    self->field_0->field_7c = 7;
}

// 0x7100faace0
void Unk_faace0_update() {}

struct Unk_faacf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faacf0_arg1, field_0, 0x0);

struct Unk_faacf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faacf0, field_0, 0x0);

// 0x7100faacf0
void Unk_faacf0_set(const Unk_faacf0* self, Unk_faacf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faad00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faad00_arg1, field_0, 0x0);

struct Unk_faad00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faad00, field_0, 0x0);

// 0x7100faad00
void Unk_faad00_set(const Unk_faad00* self, Unk_faad00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faad90
void Unk_faad90_update() {}

struct Unk_faada0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faada0_arg1, field_0, 0x0);

struct Unk_faada0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faada0, field_0, 0x0);

// 0x7100faada0
void Unk_faada0_set(const Unk_faada0* self, Unk_faada0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faadb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faadb0_arg1, field_0, 0x0);

struct Unk_faadb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faadb0, field_0, 0x0);

// 0x7100faadb0
void Unk_faadb0_set(const Unk_faadb0* self, Unk_faadb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_faadc0_0 {
    u8 _0[0x340];
    Unk_e807f0* field_340;
};
PKMN_OFFSET_ASSERT(Unk_faadc0_0, field_340, 0x340);

struct Unk_faadc0 {
    Unk_faadc0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_faadc0, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100faadc0
void Unk_faadc0_call(const Unk_faadc0* self) {
    Unk_e807f0_call(self->field_0->field_340, false);
}

// 0x7100faadd0
void Unk_faadd0_update() {}

struct Unk_faade0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faade0_arg1, field_0, 0x0);

struct Unk_faade0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faade0, field_0, 0x0);

// 0x7100faade0
void Unk_faade0_set(const Unk_faade0* self, Unk_faade0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faadf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faadf0_arg1, field_0, 0x0);

struct Unk_faadf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faadf0, field_0, 0x0);

// 0x7100faadf0
void Unk_faadf0_set(const Unk_faadf0* self, Unk_faadf0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faae70
void Unk_faae70_update() {}

struct Unk_faae80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faae80_arg1, field_0, 0x0);

struct Unk_faae80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faae80, field_0, 0x0);

// 0x7100faae80
void Unk_faae80_set(const Unk_faae80* self, Unk_faae80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faae90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faae90_arg1, field_0, 0x0);

struct Unk_faae90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faae90, field_0, 0x0);

// 0x7100faae90
void Unk_faae90_set(const Unk_faae90* self, Unk_faae90_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faaea0
void Unk_faaea0_update() {}

// 0x7100faaeb0
void Unk_faaeb0_update() {}

// 0x7100faaec0
void Unk_faaec0_update() {}

// 0x7100faaed0
void Unk_faaed0_update() {}

// 0x7100faaf60
void Unk_faaf60_update() {}

struct Unk_faaf70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faaf70_arg1, field_0, 0x0);

struct Unk_faaf70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faaf70, field_0, 0x0);

// 0x7100faaf70
void Unk_faaf70_set(const Unk_faaf70* self, Unk_faaf70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faaf80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faaf80_arg1, field_0, 0x0);

struct Unk_faaf80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faaf80, field_0, 0x0);

// 0x7100faaf80
void Unk_faaf80_set(const Unk_faaf80* self, Unk_faaf80_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faaf90
void Unk_faaf90_update() {}

// 0x7100faafa0
void Unk_faafa0_update() {}

// 0x7100faafb0
void Unk_faafb0_update() {}

// 0x7100faafc0
void Unk_faafc0_update() {}
