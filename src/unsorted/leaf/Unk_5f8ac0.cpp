// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x71005f8ac0
void Unk_5f8ac0_update() {}

struct Unk_5f8ad0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5f8ad0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5f8ad0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5f8ad0, field_10, 0x10);

// 0x71005f8ad0
void Unk_5f8ad0_set(const Unk_5f8ad0* self, Unk_5f8ad0* value) {
    *value = *self;
}

struct Unk_5f8af0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5f8af0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5f8af0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5f8af0, field_10, 0x10);

// 0x71005f8af0
void Unk_5f8af0_set(const Unk_5f8af0* self, Unk_5f8af0* value) {
    *value = *self;
}

void Unk_5fa8e0();

// 0x71005fa8d0
void Unk_5fa8d0_call() {
    Unk_5fa8e0();
}

void Unk_5fabd0();

// 0x71005fabc0
void Unk_5fabc0_call() {
    Unk_5fabd0();
}

struct Unk_5fcfe0 {
    u8 _0[0x180];
    f32 field_180;
    u8 _184[0x5c];
    u8 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_5fcfe0, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_5fcfe0, field_1e0, 0x1e0);

// 0x71005fcfe0
void Unk_5fcfe0_set(Unk_5fcfe0* self, f32 fvalue) {
    self->field_180 = fvalue;
    self->field_1e0 = 1;
}

struct Unk_5fcff0 {
    u8 _0[0x173];
    u8 field_173;
    u8 _174[0x6c];
    u8 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_5fcff0, field_173, 0x173);
PKMN_OFFSET_ASSERT(Unk_5fcff0, field_1e0, 0x1e0);

// 0x71005fcff0
void Unk_5fcff0_set(Unk_5fcff0* self, u8 value) {
    self->field_173 = value;
    self->field_1e0 = 1;
}

void Unk_5fe110();

// 0x71005fe100
void Unk_5fe100_call() {
    Unk_5fe110();
}

// 0x7100600360
void Unk_600360_update() {}

struct Unk_600370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_600370_arg1, field_0, 0x0);

struct Unk_600370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_600370, field_0, 0x0);

// 0x7100600370
void Unk_600370_set(const Unk_600370* self, Unk_600370_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_600380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_600380_arg1, field_0, 0x0);

struct Unk_600380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_600380, field_0, 0x0);

// 0x7100600380
void Unk_600380_set(const Unk_600380* self, Unk_600380_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6008c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6008c0, field_0, 0x0);

void Unk_600390(u64);

// 0x71006008c0
void Unk_6008c0_call(const Unk_6008c0* self) {
    Unk_600390(self->field_0);
}

// 0x71006008d0
void Unk_6008d0_update() {}

struct Unk_6008e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6008e0_arg1, field_0, 0x0);

struct Unk_6008e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6008e0, field_0, 0x0);

// 0x71006008e0
void Unk_6008e0_set(const Unk_6008e0* self, Unk_6008e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6008f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6008f0_arg1, field_0, 0x0);

struct Unk_6008f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6008f0, field_0, 0x0);

// 0x71006008f0
void Unk_6008f0_set(const Unk_6008f0* self, Unk_6008f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_601800_198 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_601800_198, field_78, 0x78);

struct Unk_601800 {
    u8 _0[0x198];
    Unk_601800_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_601800, field_198, 0x198);

// 0x7100601800
u8* Unk_601800_get(const Unk_601800* self) {
    return &self->field_198->field_78;
}

struct Unk_602010_arg2 {
    u8 _0[0x180];
    Unk_239a418* field_180;
};
PKMN_OFFSET_ASSERT(Unk_602010_arg2, field_180, 0x180);

// 0x7100602010
void Unk_602010_call(void* /*unused*/, u32 /*unused*/, Unk_602010_arg2* arg2) {
    Unk_239a418* v0 = arg2->field_180;
    arg2->field_180 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

// 0x7100604130
void Unk_604130_update() {}

struct Unk_604140 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_604140, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_604140, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_604140, field_10, 0x10);

// 0x7100604140
void Unk_604140_set(const Unk_604140* self, Unk_604140* value) {
    *value = *self;
}

struct Unk_604160 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_604160, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_604160, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_604160, field_10, 0x10);

// 0x7100604160
void Unk_604160_set(const Unk_604160* self, Unk_604160* value) {
    *value = *self;
}

struct Unk_606ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_606ef0, field_0, 0x0);

void Unk_604830(u64);

// 0x7100606ef0
void Unk_606ef0_call(const Unk_606ef0* self) {
    Unk_604830(self->field_0);
}

// 0x7100606f00
void Unk_606f00_update() {}

struct Unk_606f10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_606f10_arg1, field_0, 0x0);

struct Unk_606f10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_606f10, field_0, 0x0);

// 0x7100606f10
void Unk_606f10_set(const Unk_606f10* self, Unk_606f10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_606f20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_606f20_arg1, field_0, 0x0);

struct Unk_606f20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_606f20, field_0, 0x0);

// 0x7100606f20
void Unk_606f20_set(const Unk_606f20* self, Unk_606f20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_60e2b0 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_60e2b0, field_e0, 0xe0);

void Unk_60f390(u64);

// 0x710060e2b0
void Unk_60e2b0_call(const Unk_60e2b0* self) {
    Unk_60f390(self->field_e0);
}

struct Unk_60e840 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_60e840, field_0, 0x0);

void Unk_60e6d0(u64);

// 0x710060e840
void Unk_60e840_call(const Unk_60e840* self) {
    Unk_60e6d0(self->field_0);
}

// 0x710060e850
void Unk_60e850_update() {}

struct Unk_60e860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_60e860_arg1, field_0, 0x0);

struct Unk_60e860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_60e860, field_0, 0x0);

// 0x710060e860
void Unk_60e860_set(const Unk_60e860* self, Unk_60e860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_60e870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_60e870_arg1, field_0, 0x0);

struct Unk_60e870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_60e870, field_0, 0x0);

// 0x710060e870
void Unk_60e870_set(const Unk_60e870* self, Unk_60e870_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_60fbf0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_60fbf0, field_0, 0x0);

// 0x710060fbf0
void Unk_60fbf0_call(Unk_60fbf0* self) {
    Unk_239a418* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

// 0x7100619490
void Unk_619490() {}

// 0x7100619980
void Unk_619980_update() {}

struct Unk_619990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_619990_arg1, field_0, 0x0);

struct Unk_619990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_619990, field_0, 0x0);

// 0x7100619990
void Unk_619990_set(const Unk_619990* self, Unk_619990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6199a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6199a0_arg1, field_0, 0x0);

struct Unk_6199a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6199a0, field_0, 0x0);

// 0x71006199a0
void Unk_6199a0_set(const Unk_6199a0* self, Unk_6199a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100619b80
void Unk_619b80_update() {}

struct Unk_619b90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_619b90_arg1, field_0, 0x0);

struct Unk_619b90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_619b90, field_0, 0x0);

// 0x7100619b90
void Unk_619b90_set(const Unk_619b90* self, Unk_619b90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_619ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_619ba0_arg1, field_0, 0x0);

struct Unk_619ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_619ba0, field_0, 0x0);

// 0x7100619ba0
void Unk_619ba0_set(const Unk_619ba0* self, Unk_619ba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_61d660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61d660_arg1, field_0, 0x0);

struct Unk_61d660 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61d660, field_0, 0x0);

void Unk_61cf60(u64, bool);

// 0x710061d660
void Unk_61d660_call(const Unk_61d660* self, const Unk_61d660_arg1* value) {
    Unk_61cf60(value->field_0, self->field_0 != 0);
}

// 0x710061d680
void Unk_61d680_update() {}

struct Unk_61d690_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61d690_arg1, field_0, 0x0);

struct Unk_61d690 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61d690, field_0, 0x0);

// 0x710061d690
void Unk_61d690_set(const Unk_61d690* self, Unk_61d690_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_61d6a0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61d6a0_arg1, field_0, 0x0);

struct Unk_61d6a0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61d6a0, field_0, 0x0);

// 0x710061d6a0
void Unk_61d6a0_set(const Unk_61d6a0* self, Unk_61d6a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_61e850 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61e850, field_0, 0x0);

void Unk_61e6e0(u64);

// 0x710061e850
void Unk_61e850_call(const Unk_61e850* self) {
    Unk_61e6e0(self->field_0);
}

// 0x710061e860
void Unk_61e860_update() {}

struct Unk_61e870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61e870_arg1, field_0, 0x0);

struct Unk_61e870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61e870, field_0, 0x0);

// 0x710061e870
void Unk_61e870_set(const Unk_61e870* self, Unk_61e870_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_61e880_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61e880_arg1, field_0, 0x0);

struct Unk_61e880 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_61e880, field_0, 0x0);

// 0x710061e880
void Unk_61e880_set(const Unk_61e880* self, Unk_61e880_arg1* value) {
    value->field_0 = self->field_0;
}
