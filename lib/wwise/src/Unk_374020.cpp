// Scope: common
// Two objects' "set a parameter" (a number for which, a value): times in
// seconds are kept as numbers of samples, percentages as fractions.
// Placeholder names.
#include <types.h>

// The sample rate.
extern u32 Unk_2382e68;

// A time in seconds as a number of samples, rounded.
static inline s32 Unk_374020_Samples(f32 seconds) {
    f64 samples = static_cast<f64>(Unk_2382e68) * static_cast<f64>(seconds);
    return static_cast<s32>(samples + (samples > 0.0 ? 0.5 : -0.5));
}

struct Unk_374020_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();

    u8 _8[0x90];
    f32 field_98;
    s32 field_9c;
    u8 _a0[4];
    u32 field_a4;
    f32 field_a8;
    f32 field_ac;
    f32 field_b0;
    u8 _b4[0x24];
    bool field_d8;
};
PKMN_OFFSET_ASSERT(Unk_374020_T, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_374020_T, field_d8, 0xd8);

// 0x7100374020
bool Unk_374020(Unk_374020_T* self, u32 parameter, f32 value) {
    switch (parameter) {
    case 0:
        self->field_98 = value * 0.01f;
        break;
    case 1:
        self->field_9c = Unk_374020_Samples(value);
        break;
    case 2:
        self->field_a8 = value;
        self->field_d8 = true;
        self->vf4();
        break;
    case 3:
        self->field_a4 = static_cast<u32>(value);
        self->field_d8 = true;
        break;
    case 4:
        self->field_ac = value * 0.01f;
        self->field_d8 = true;
        break;
    case 5:
        self->field_b0 = value * 0.01f;
        self->field_d8 = true;
        break;
    default:
        return false;
    }
    return true;
}

struct Unk_374140_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();

    u8 _8[0x54];
    s32 field_5c;
    u8 _60[0x3c];
    s32 field_9c;
    f32 field_a0;
    f32 field_a4;
    s32 field_a8;
    s32 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_374140_T, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_374140_T, field_9c, 0x9c);

// 0x7100374140
bool Unk_374140(Unk_374140_T* self, u32 parameter, f32 value) {
    switch (parameter) {
    case 8:
        self->field_9c = Unk_374020_Samples(value);
        self->vf4();
        break;
    case 9:
        self->field_a0 = value * 0.01f;
        break;
    case 10:
        self->field_a8 = Unk_374020_Samples(value);
        self->vf4();
        break;
    case 11:
        self->field_a4 = value * 0.01f;
        break;
    case 12:
        if (value >= 0.0f)
            self->field_5c = self->field_9c + self->field_a8 + Unk_374020_Samples(value);
        else
            self->field_5c = 0x7fffffff;
        break;
    case 13:
        self->field_ac = Unk_374020_Samples(value);
        break;
    default:
        return false;
    }
    return true;
}
