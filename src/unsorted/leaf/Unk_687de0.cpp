// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_687de0_198 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_687de0_198, field_80, 0x80);

struct Unk_687de0 {
    u8 _0[0x198];
    Unk_687de0_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_687de0, field_198, 0x198);

// 0x7100687de0
u8* Unk_687de0_get(const Unk_687de0* self) {
    return &self->field_198->field_80;
}

struct Unk_68bde0 {
    u8 _0[0x280];
    u64 field_280;
};
PKMN_OFFSET_ASSERT(Unk_68bde0, field_280, 0x280);

void Unk_602930(u64, u64);

// 0x710068bde0
void Unk_68bde0_call(const Unk_68bde0* self, u64 value) {
    Unk_602930(value, self->field_280);
}

struct Unk_68d900 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_68d900, field_260, 0x260);

// 0x710068d900
u8* Unk_68d900_getField260Ptr(Unk_68d900* self) {
    return &self->field_260;
}

struct Unk_68d910_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_68d910_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_68d910_arg1, field_8, 0x8);

struct Unk_68d910 {
    u8 _0[0x260];
    u64 field_260;
    u64 field_268;
};
PKMN_OFFSET_ASSERT(Unk_68d910, field_260, 0x260);
PKMN_OFFSET_ASSERT(Unk_68d910, field_268, 0x268);

// 0x710068d910
void Unk_68d910_set(Unk_68d910* self, const Unk_68d910_arg1* value) {
    self->field_268 = value->field_8;
    self->field_260 = value->field_0;
}

struct Unk_68d930 {
    u8 _0[0x27a];
    u8 field_27a;
};
PKMN_OFFSET_ASSERT(Unk_68d930, field_27a, 0x27a);

// 0x710068d930
void Unk_68d930_set(Unk_68d930* self) {
    self->field_27a = 1;
}

struct Unk_68d940 {
    u8 _0[0x27a];
    u8 field_27a;
};
PKMN_OFFSET_ASSERT(Unk_68d940, field_27a, 0x27a);

// 0x710068d940
void Unk_68d940_clearField27a(Unk_68d940* self) {
    self->field_27a = 0;
}

struct Unk_68da30 {
    u8 _0[0x270];
    u64 field_270;
};
PKMN_OFFSET_ASSERT(Unk_68da30, field_270, 0x270);

void Unk_691560(u64);

// 0x710068da30
void Unk_68da30_call(const Unk_68da30* self) {
    Unk_691560(self->field_270);
}

struct Unk_68da40 {
    u8 _0[0xf8];
    u64 field_f8;
    u8 _100[0x179];
    u8 field_279;
};
PKMN_OFFSET_ASSERT(Unk_68da40, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_68da40, field_279, 0x279);
void Unk_68f670(u64);

// 0x710068da40
void Unk_68da40_update(const Unk_68da40* self) {
    if (self->field_279 != 0) {
        return;
    }
    Unk_68f670(self->field_f8);
}

struct Unk_68da60 {
    u8 _0[0xf8];
    u64 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_68da60, field_f8, 0xf8);

void Unk_68ef10(u64, u32, u32);

// 0x710068da60
void Unk_68da60_call(const Unk_68da60* self, bool value) {
    Unk_68ef10(self->field_f8, value, 0);
}

struct Unk_68da70 {
    u8 _0[0xf8];
    u64 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_68da70, field_f8, 0xf8);

void Unk_68f030(u64);

// 0x710068da70
void Unk_68da70_call(const Unk_68da70* self) {
    Unk_68f030(self->field_f8);
}

struct Unk_68da90 {
    u8 _0[0xf8];
    u64 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_68da90, field_f8, 0xf8);

void Unk_68f170(u64, u32);

// 0x710068da90
void Unk_68da90_call(const Unk_68da90* self, bool value) {
    Unk_68f170(self->field_f8, value);
}

struct Unk_68f160 {
    u8 _0[0x68];
    f32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_68f160, field_68, 0x68);

// 0x710068f160
void Unk_68f160_setField68(Unk_68f160* self, f32 value) {
    self->field_68 = value;
}

struct Unk_690370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_690370, field_0, 0x0);

void Unk_690260(u64);

// 0x7100690370
void Unk_690370_call(const Unk_690370* self) {
    Unk_690260(self->field_0);
}

// 0x7100690380
void Unk_690380_update() {}

struct Unk_690390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_690390_arg1, field_0, 0x0);

struct Unk_690390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_690390, field_0, 0x0);

// 0x7100690390
void Unk_690390_set(const Unk_690390* self, Unk_690390_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6903a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6903a0_arg1, field_0, 0x0);

struct Unk_6903a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6903a0, field_0, 0x0);

// 0x71006903a0
void Unk_6903a0_set(const Unk_6903a0* self, Unk_6903a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_690e00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_690e00, field_0, 0x0);

// 0x7100690e00
void Unk_690e00_call(Unk_690e00* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_6910e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_6910e0_arg1, field_0, 0x0);

struct Unk_6910e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_6910e0, field_0, 0x0);

// 0x71006910e0
void Unk_6910e0_call(const Unk_6910e0* self, Unk_6910e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_691100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_691100_arg1, field_0, 0x0);

struct Unk_691100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_691100, field_0, 0x0);

// 0x7100691100
void Unk_691100_set(Unk_691100* self, Unk_691100_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_691260_e0 {
    u8 _0[0x2c];
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_691260_e0, field_2c, 0x2c);

struct Unk_691260 {
    u8 _0[0xe0];
    Unk_691260_e0* field_e0;
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_691260, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_691260, field_e8, 0xe8);

// 0x7100691260
void Unk_691260_set(Unk_691260* self) {
    if (self->field_e0 != nullptr) {
        if (self->field_e8 != self->field_e0->field_2c)
            return;
        self->field_e0 = nullptr;
        self->field_e8 = 0xffffffff;
    }
}

struct Unk_691b40 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691b40, field_238, 0x238);

void Unk_694d90(u64);

// 0x7100691b40
void Unk_691b40_call(const Unk_691b40* self) {
    Unk_694d90(self->field_238);
}

struct Unk_691b50 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691b50, field_238, 0x238);

void Unk_695020(u64);

// 0x7100691b50
void Unk_691b50_call(const Unk_691b50* self) {
    Unk_695020(self->field_238);
}

struct Unk_691b60 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691b60, field_238, 0x238);

void Unk_695150(u64);

// 0x7100691b60
void Unk_691b60_call(const Unk_691b60* self) {
    Unk_695150(self->field_238);
}

struct Unk_691bf0 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691bf0, field_238, 0x238);

void Unk_6953f0(u64);

// 0x7100691bf0
void Unk_691bf0_call(const Unk_691bf0* self) {
    Unk_6953f0(self->field_238);
}

struct Unk_691c00 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691c00, field_238, 0x238);

void Unk_6954e0(u64, u64, u64, u64, u64, u64, u32);

// 0x7100691c00
void Unk_691c00_call(const Unk_691c00* self,
                     u64 value,
                     u64 arg2,
                     u64 arg3,
                     u64 arg4,
                     u64 arg5,
                     bool arg6) {
    Unk_6954e0(self->field_238, value, arg2, arg3, arg4, arg5, arg6);
}

struct Unk_691d00_arg2 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_691d00_arg2, field_8, 0x8);

struct Unk_691d00 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691d00, field_238, 0x238);

void Unk_695ad0(u64, u64, u64);

// 0x7100691d00
void Unk_691d00_call(const Unk_691d00* self, u64 value, const Unk_691d00_arg2* arg2) {
    Unk_695ad0(self->field_238, value, arg2->field_8);
}

struct Unk_691d10 {
    u8 _0[0x238];
    u64 field_238;
};
PKMN_OFFSET_ASSERT(Unk_691d10, field_238, 0x238);

void Unk_695de0(u64);

// 0x7100691d10
void Unk_691d10_call(const Unk_691d10* self) {
    Unk_695de0(self->field_238);
}

// 0x7100692590
void Unk_692590_update() {}

struct Unk_6925a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6925a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6925a0, field_8, 0x8);

// 0x71006925a0
void Unk_6925a0_set(const Unk_6925a0* self, Unk_6925a0* value) {
    *value = *self;
}

struct Unk_6925b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6925b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6925b0, field_8, 0x8);

// 0x71006925b0
void Unk_6925b0_set(const Unk_6925b0* self, Unk_6925b0* value) {
    *value = *self;
}

struct Unk_692920_198 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_692920_198, field_80, 0x80);

struct Unk_692920 {
    u8 _0[0x198];
    Unk_692920_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_692920, field_198, 0x198);

// 0x7100692920
u32 Unk_692920_get(const Unk_692920* self) {
    return self->field_198->field_80;
}

// 0x7100694510
void Unk_694510() {}

// 0x71006955b0
void Unk_6955b0() {}

// 0x7100696bf0
void Unk_696bf0_update() {}

struct Unk_696d80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_696d80_arg1, field_0, 0x0);

struct Unk_696d80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_696d80, field_0, 0x0);

// 0x7100696d80
void Unk_696d80_set(const Unk_696d80* self, Unk_696d80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_696d90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_696d90_arg1, field_0, 0x0);

struct Unk_696d90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_696d90, field_0, 0x0);

// 0x7100696d90
void Unk_696d90_set(const Unk_696d90* self, Unk_696d90_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100699710
void Unk_699710_update() {}

struct Unk_699720_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_699720_arg1, field_0, 0x0);

struct Unk_699720 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_699720, field_0, 0x0);

// 0x7100699720
void Unk_699720_set(const Unk_699720* self, Unk_699720_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_699730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_699730_arg1, field_0, 0x0);

struct Unk_699730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_699730, field_0, 0x0);

// 0x7100699730
void Unk_699730_set(const Unk_699730* self, Unk_699730_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69a210 {
    u8 _0[0x410];
    u8 field_410;
    u8 _411[0x1ef];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_69a210, field_410, 0x410);
PKMN_OFFSET_ASSERT(Unk_69a210, field_600, 0x600);

void Unk_699f60(void*, u64);

// 0x710069a210
void Unk_69a210_call(Unk_69a210* self, u32 value, u64 arg2) {
    self->field_600 = value;
    Unk_699f60(&self->field_410, arg2);
}

struct Unk_69a220 {
    u8 _0[0x610];
    u8 field_610;
    u8 _611[0x1ef];
    u32 field_800;
};
PKMN_OFFSET_ASSERT(Unk_69a220, field_610, 0x610);
PKMN_OFFSET_ASSERT(Unk_69a220, field_800, 0x800);

void Unk_699f60(void*, u64);

// 0x710069a220
void Unk_69a220_call(Unk_69a220* self, u32 value, u64 arg2) {
    self->field_800 = value;
    Unk_699f60(&self->field_610, arg2);
}
