// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e371c0 {
    u8 _0[0x270];
    u32 field_270;
    u16 field_274;
    u8 _276[0xa];
    u32 field_280;
};
PKMN_OFFSET_ASSERT(Unk_e371c0, field_270, 0x270);
PKMN_OFFSET_ASSERT(Unk_e371c0, field_274, 0x274);
PKMN_OFFSET_ASSERT(Unk_e371c0, field_280, 0x280);

void Unk_e371e0(u32, u16, u32, u64, void*, void*, u32);

// 0x7100e371c0
void Unk_e371c0_call(Unk_e371c0* self, void* value, u32 arg2, u64 arg3) {
    Unk_e371e0(self->field_270, self->field_274, self->field_280, arg3, self, value, arg2);
}

struct Unk_e39660 {
    u8 _0[0x60];
    void* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e39660, field_60, 0x60);

void Unk_e3a000(void*, void*);

// 0x7100e39660
void Unk_e39660_call(const Unk_e39660* self, void* value) {
    Unk_e3a000(self->field_60, value);
}

struct Unk_e39670 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e39670, field_60, 0x60);

void Unk_e3a130(u64, void*, u32);

// 0x7100e39670
void Unk_e39670_call(const Unk_e39670* self, void* value, u32 arg2) {
    Unk_e3a130(self->field_60, value, arg2);
}

struct Unk_e39680 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_e39680, field_68, 0x68);

void Unk_e39d70(void*, void*, u32);

// 0x7100e39680
void Unk_e39680_call(const Unk_e39680* self, void* value, u32 arg2) {
    Unk_e39d70(self->field_68, value, arg2);
}

struct Unk_e396d0 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_e396d0, field_70, 0x70);

void Unk_e3a2a0(void*, void*);

// 0x7100e396d0
void Unk_e396d0_call(const Unk_e396d0* self, void* value) {
    Unk_e3a2a0(self->field_70, value);
}

struct Unk_e396e0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_e396e0, field_70, 0x70);

void Unk_e3a390(u64, void*, u32);

// 0x7100e396e0
void Unk_e396e0_call(const Unk_e396e0* self, void* value, u32 arg2) {
    Unk_e3a390(self->field_70, value, arg2);
}

struct Unk_e396f0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_e396f0, field_78, 0x78);

void Unk_e3a500(void*, void*);

// 0x7100e396f0
void Unk_e396f0_call(const Unk_e396f0* self, void* value) {
    Unk_e3a500(self->field_78, value);
}

struct Unk_e39700 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e39700, field_78, 0x78);

void Unk_e3a5f0(u64, void*, u32);

// 0x7100e39700
void Unk_e39700_call(const Unk_e39700* self, void* value, u32 arg2) {
    Unk_e3a5f0(self->field_78, value, arg2);
}
