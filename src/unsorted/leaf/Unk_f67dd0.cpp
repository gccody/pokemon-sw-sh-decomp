// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_f67dd0 {
    u8 _0[0x80];
    void* field_80;
};
PKMN_OFFSET_ASSERT(Unk_f67dd0, field_80, 0x80);

void Unk_f68f00(void*, u32, u64, u64);

// 0x7100f67dd0
void Unk_f67dd0_call(const Unk_f67dd0* self, u32 value, u64 arg2, u64 arg3) {
    Unk_f68f00(self->field_80, value, arg2, arg3);
}

struct Unk_f67de0 {
    u8 _0[0x80];
    void* field_80;
};
PKMN_OFFSET_ASSERT(Unk_f67de0, field_80, 0x80);

void Unk_f68e00(void*, u64);

// 0x7100f67de0
void Unk_f67de0_call(const Unk_f67de0* self, u64 value) {
    Unk_f68e00(self->field_80, value);
}

struct Unk_f6c980_0 {
    u8 _0[0x5e4];
    u8 field_5e4;
};
PKMN_OFFSET_ASSERT(Unk_f6c980_0, field_5e4, 0x5e4);

struct Unk_f6c980 {
    Unk_f6c980_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6c980, field_0, 0x0);

// 0x7100f6c980
void Unk_f6c980_set(const Unk_f6c980* self) {
    self->field_0->field_5e4 = 1;
}

// 0x7100f6c990
void Unk_f6c990_update() {}

struct Unk_f6c9a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6c9a0_arg1, field_0, 0x0);

struct Unk_f6c9a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6c9a0, field_0, 0x0);

// 0x7100f6c9a0
void Unk_f6c9a0_set(const Unk_f6c9a0* self, Unk_f6c9a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f6c9b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6c9b0_arg1, field_0, 0x0);

struct Unk_f6c9b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6c9b0, field_0, 0x0);

// 0x7100f6c9b0
void Unk_f6c9b0_set(const Unk_f6c9b0* self, Unk_f6c9b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f6c9c0 {
    u64 field_0;
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_88, 0x88);

// 0x7100f6c9c0
void Unk_f6c9c0_set(Unk_f6c9c0* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_80 = 0;
    self->field_88 = 0;
    self->field_70 = 0;
    self->field_78 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
    self->field_50 = 0;
    self->field_58 = 0;
    self->field_40 = 0;
    self->field_48 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_f6cc70 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6cc70, field_0, 0x0);

void Unk_eb8a30(void*, u32);

// 0x7100f6cc70
void Unk_f6cc70_call(const Unk_f6cc70* self) {
    Unk_eb8a30(self->field_0, 1);
}

struct Unk_f6cdc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6cdc0, field_0, 0x0);

void Unk_eb8e80(u64);

// 0x7100f6cdc0
void Unk_f6cdc0_call(const Unk_f6cdc0* self) {
    Unk_eb8e80(self->field_0);
}

// 0x7100f71a80
void Unk_f71a80_update() {}

struct Unk_f71a90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71a90_arg1, field_0, 0x0);

struct Unk_f71a90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71a90, field_0, 0x0);

// 0x7100f71a90
void Unk_f71a90_set(const Unk_f71a90* self, Unk_f71a90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f71aa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71aa0_arg1, field_0, 0x0);

struct Unk_f71aa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71aa0, field_0, 0x0);

// 0x7100f71aa0
void Unk_f71aa0_set(const Unk_f71aa0* self, Unk_f71aa0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f71ac0
void Unk_f71ac0_update() {}

struct Unk_f71ad0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71ad0_arg1, field_0, 0x0);

struct Unk_f71ad0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71ad0, field_0, 0x0);

// 0x7100f71ad0
void Unk_f71ad0_set(const Unk_f71ad0* self, Unk_f71ad0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f71ae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71ae0_arg1, field_0, 0x0);

struct Unk_f71ae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71ae0, field_0, 0x0);

// 0x7100f71ae0
void Unk_f71ae0_set(const Unk_f71ae0* self, Unk_f71ae0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f71c20_0 {
    u8 _0[0x600];
    u8 field_600;
};
PKMN_OFFSET_ASSERT(Unk_f71c20_0, field_600, 0x600);

struct Unk_f71c20 {
    Unk_f71c20_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71c20, field_0, 0x0);

// 0x7100f71c20
void Unk_f71c20_set(const Unk_f71c20* self) {
    self->field_0->field_600 = 1;
}

// 0x7100f71c30
void Unk_f71c30_update() {}

struct Unk_f71c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71c40_arg1, field_0, 0x0);

struct Unk_f71c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71c40, field_0, 0x0);

// 0x7100f71c40
void Unk_f71c40_set(const Unk_f71c40* self, Unk_f71c40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f71c50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71c50_arg1, field_0, 0x0);

struct Unk_f71c50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f71c50, field_0, 0x0);

// 0x7100f71c50
void Unk_f71c50_set(const Unk_f71c50* self, Unk_f71c50_arg1* value) {
    value->field_0 = self->field_0;
}

void Unk_f6c850(void*, u32, u32);

// 0x7100f74240
void Unk_f74240_call(void* self, bool value) {
    Unk_f6c850(self, 4, value);
}

void Unk_f6c850(void*, u32, u32);

// 0x7100f74250
void Unk_f74250_call(void* self, bool value) {
    Unk_f6c850(self, 3, value);
}

// 0x7100f762b0
void Unk_f762b0_update() {}

struct Unk_f762c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f762c0_arg1, field_0, 0x0);

struct Unk_f762c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f762c0, field_0, 0x0);

// 0x7100f762c0
void Unk_f762c0_set(const Unk_f762c0* self, Unk_f762c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f762d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f762d0_arg1, field_0, 0x0);

struct Unk_f762d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f762d0, field_0, 0x0);

// 0x7100f762d0
void Unk_f762d0_set(const Unk_f762d0* self, Unk_f762d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76460 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f76460, field_8, 0x8);

// 0x7100f76460
void Unk_f76460_call(Unk_f76460* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f764a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f764a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f764a0_arg1, field_8, 0x8);

struct Unk_f764a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f764a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f764a0, field_8, 0x8);

// 0x7100f764a0
void Unk_f764a0_call(const Unk_f764a0* self, Unk_f764a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f764d0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f764d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f764d0_arg1, field_8, 0x8);

struct Unk_f764d0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f764d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f764d0, field_8, 0x8);

// 0x7100f764d0
void Unk_f764d0_call(const Unk_f764d0* self, Unk_f764d0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f76530 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f76530, field_8, 0x8);

// 0x7100f76530
void Unk_f76530_call(Unk_f76530* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f76570_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f76570_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f76570_arg1, field_8, 0x8);

struct Unk_f76570 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f76570, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f76570, field_8, 0x8);

// 0x7100f76570
void Unk_f76570_call(const Unk_f76570* self, Unk_f76570_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f765a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f765a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f765a0_arg1, field_8, 0x8);

struct Unk_f765a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f765a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f765a0, field_8, 0x8);

// 0x7100f765a0
void Unk_f765a0_call(const Unk_f765a0* self, Unk_f765a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100f765f0
void Unk_f765f0_update() {}

struct Unk_f76600_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76600_arg1, field_0, 0x0);

struct Unk_f76600 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76600, field_0, 0x0);

// 0x7100f76600
void Unk_f76600_set(const Unk_f76600* self, Unk_f76600_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76610_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76610_arg1, field_0, 0x0);

struct Unk_f76610 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76610, field_0, 0x0);

// 0x7100f76610
void Unk_f76610_set(const Unk_f76610* self, Unk_f76610_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76620_0 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f76620_0, field_80, 0x80);

struct Unk_f76620 {
    Unk_f76620_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76620, field_0, 0x0);

// 0x7100f76620
void Unk_f76620_set(const Unk_f76620* self) {
    self->field_0->field_80 = 4;
}

// 0x7100f76630
void Unk_f76630_update() {}

struct Unk_f76640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76640_arg1, field_0, 0x0);

struct Unk_f76640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76640, field_0, 0x0);

// 0x7100f76640
void Unk_f76640_set(const Unk_f76640* self, Unk_f76640_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76650_arg1, field_0, 0x0);

struct Unk_f76650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76650, field_0, 0x0);

// 0x7100f76650
void Unk_f76650_set(const Unk_f76650* self, Unk_f76650_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76660_0 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_f76660_0, field_a0, 0xa0);

struct Unk_f76660 {
    Unk_f76660_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76660, field_0, 0x0);

void Unk_f6cd80(void*);

// 0x7100f76660
void Unk_f76660_call(const Unk_f76660* self) {
    Unk_f6cd80(&self->field_0->field_a0);
}

// 0x7100f76670
void Unk_f76670_update() {}

struct Unk_f76680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76680_arg1, field_0, 0x0);

struct Unk_f76680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76680, field_0, 0x0);

// 0x7100f76680
void Unk_f76680_set(const Unk_f76680* self, Unk_f76680_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76690_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76690_arg1, field_0, 0x0);

struct Unk_f76690 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76690, field_0, 0x0);

// 0x7100f76690
void Unk_f76690_set(const Unk_f76690* self, Unk_f76690_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f76730
void Unk_f76730_update() {}

struct Unk_f76740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76740_arg1, field_0, 0x0);

struct Unk_f76740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76740, field_0, 0x0);

// 0x7100f76740
void Unk_f76740_set(const Unk_f76740* self, Unk_f76740_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f76750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76750_arg1, field_0, 0x0);

struct Unk_f76750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f76750, field_0, 0x0);

// 0x7100f76750
void Unk_f76750_set(const Unk_f76750* self, Unk_f76750_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e16f4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e16f4_Data, field_18, 0x18);

extern Unk_27e16f4_Data Unk_27e16f4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f76760
void Unk_f76760_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e16f4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e16f4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e16f4.field_18 = 0xffff;
    Unk_27e16f4.field_10 = 0;
    Unk_27e16f4.field_8 = r2;
    Unk_27e16f4.field_c = 0;
    Unk_27e16f4.field_14 = 0xffffffff;
}
