// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e39660 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e39660, field_60, 0x60);

void Unk_e3a000(u64);

// 0x7100e39660
void Unk_e39660_call(const Unk_e39660* self) {
    Unk_e3a000(self->field_60);
}

struct Unk_e39670 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e39670, field_60, 0x60);

void Unk_e3a130(u64);

// 0x7100e39670
void Unk_e39670_call(const Unk_e39670* self) {
    Unk_e3a130(self->field_60);
}

struct Unk_e39680 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_e39680, field_68, 0x68);

void Unk_e39d70(u64);

// 0x7100e39680
void Unk_e39680_call(const Unk_e39680* self) {
    Unk_e39d70(self->field_68);
}

struct Unk_e396d0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_e396d0, field_70, 0x70);

void Unk_e3a2a0(u64);

// 0x7100e396d0
void Unk_e396d0_call(const Unk_e396d0* self) {
    Unk_e3a2a0(self->field_70);
}

struct Unk_e396e0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_e396e0, field_70, 0x70);

void Unk_e3a390(u64);

// 0x7100e396e0
void Unk_e396e0_call(const Unk_e396e0* self) {
    Unk_e3a390(self->field_70);
}

struct Unk_e396f0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e396f0, field_78, 0x78);

void Unk_e3a500(u64);

// 0x7100e396f0
void Unk_e396f0_call(const Unk_e396f0* self) {
    Unk_e3a500(self->field_78);
}

struct Unk_e39700 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e39700, field_78, 0x78);

void Unk_e3a5f0(u64);

// 0x7100e39700
void Unk_e39700_call(const Unk_e39700* self) {
    Unk_e3a5f0(self->field_78);
}
