// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a4020 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_6a4020, field_b8, 0xb8);

// 0x71006a4020
u64 Unk_6a4020_getFieldb8(const Unk_6a4020* self) {
    return self->field_b8;
}

struct Unk_6a4100 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6a4100, field_c0, 0xc0);

// 0x71006a4100
u64 Unk_6a4100_getFieldc0(const Unk_6a4100* self) {
    return self->field_c0;
}

struct Unk_6a41e0 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_6a41e0, field_c8, 0xc8);

// 0x71006a41e0
u64 Unk_6a41e0_getFieldc8(const Unk_6a41e0* self) {
    return self->field_c8;
}

struct Unk_6a42c0 {
    u8 _0[0xd0];
    u64 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_6a42c0, field_d0, 0xd0);

// 0x71006a42c0
u64 Unk_6a42c0_getFieldd0(const Unk_6a42c0* self) {
    return self->field_d0;
}

struct Unk_6a43a0 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_6a43a0, field_d8, 0xd8);

// 0x71006a43a0
u64 Unk_6a43a0_getFieldd8(const Unk_6a43a0* self) {
    return self->field_d8;
}

struct Unk_6a4480 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_6a4480, field_e0, 0xe0);

// 0x71006a4480
u64 Unk_6a4480_getFielde0(const Unk_6a4480* self) {
    return self->field_e0;
}

struct Unk_6a4b80 {
    u8 _0[0x91];
    u8 field_91;
};
PKMN_OFFSET_ASSERT(Unk_6a4b80, field_91, 0x91);

// 0x71006a4b80
u8 Unk_6a4b80_getField91(const Unk_6a4b80* self) {
    return self->field_91;
}

struct Unk_6a4b90 {
    u8 _0[0x93];
    u8 field_93;
};
PKMN_OFFSET_ASSERT(Unk_6a4b90, field_93, 0x93);

// 0x71006a4b90
u8 Unk_6a4b90_getField93(const Unk_6a4b90* self) {
    return self->field_93;
}

struct Unk_6a4cc0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4cc0, field_b0, 0xb0);

void Unk_163ece0(u64);

// 0x71006a4cc0
void Unk_6a4cc0_call(const Unk_6a4cc0* self) {
    if (self->field_b0 != 0) {
        Unk_163ece0(self->field_b0);
    }
}

struct Unk_6a4cd0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4cd0, field_b0, 0xb0);

void Unk_163ecf0(u64);

// 0x71006a4cd0
void Unk_6a4cd0_call(const Unk_6a4cd0* self) {
    if (self->field_b0 != 0) {
        Unk_163ecf0(self->field_b0);
    }
}

struct Unk_6a4d30_b0 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6a4d30_b0, field_c0, 0xc0);

struct Unk_6a4d30 {
    u8 _0[0xb0];
    Unk_6a4d30_b0* field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4d30, field_b0, 0xb0);

// 0x71006a4d30
u64 Unk_6a4d30_get(const Unk_6a4d30* self) {
    if (self->field_b0 == nullptr) {
        return 0;
    }
    return self->field_b0->field_c0;
}

struct Unk_6a4d50 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4d50, field_b0, 0xb0);

// 0x71006a4d50
u64 Unk_6a4d50_getFieldb0(const Unk_6a4d50* self) {
    return self->field_b0;
}

// 0x71006a5220
void Unk_6a5220_update() {}
