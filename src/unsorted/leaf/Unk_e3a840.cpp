// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e3a840 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e3a840, field_60, 0x60);

void Unk_e3ba60(u64);

// 0x7100e3a840
void Unk_e3a840_call(const Unk_e3a840* self) {
    if (self->field_60 != 0) {
        Unk_e3ba60(self->field_60);
    }
}

struct Unk_e3a850 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_e3a850, field_68, 0x68);

void Unk_e3b270(u64);

// 0x7100e3a850
void Unk_e3a850_call(const Unk_e3a850* self) {
    if (self->field_68 != 0) {
        Unk_e3b270(self->field_68);
    }
}

struct Unk_e3a860 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_e3a860, field_70, 0x70);

void Unk_e3b520(u64);

// 0x7100e3a860
void Unk_e3a860_call(const Unk_e3a860* self) {
    if (self->field_70 != 0) {
        Unk_e3b520(self->field_70);
    }
}

struct Unk_e3a870 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_e3a870, field_70, 0x70);

void Unk_e3b630(u64);

// 0x7100e3a870
void Unk_e3a870_call(const Unk_e3a870* self) {
    if (self->field_70 != 0) {
        Unk_e3b630(self->field_70);
    }
}

struct Unk_e3a880 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e3a880, field_78, 0x78);

void Unk_e3b7c0(u64);

// 0x7100e3a880
void Unk_e3a880_call(const Unk_e3a880* self) {
    if (self->field_78 != 0) {
        Unk_e3b7c0(self->field_78);
    }
}

struct Unk_e3a890 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e3a890, field_78, 0x78);

void Unk_e3b8d0(u64);

// 0x7100e3a890
void Unk_e3a890_call(const Unk_e3a890* self) {
    if (self->field_78 != 0) {
        Unk_e3b8d0(self->field_78);
    }
}

struct Unk_e3aca0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_e3aca0, field_80, 0x80);

// 0x7100e3aca0
u8* Unk_e3aca0_getField80Ptr(Unk_e3aca0* self) {
    return &self->field_80;
}

u64 Unk_ead710();

// 0x7100e3b3d0
bool Unk_e3b3d0_call() {
    u64 r0 = Unk_ead710();
    return r0 != 0;
}
