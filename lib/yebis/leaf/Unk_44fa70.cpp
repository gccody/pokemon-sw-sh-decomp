// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_44fa70_88 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_44fa70_88, field_90, 0x90);

struct Unk_44fa70 {
    u8 _0[0x88];
    Unk_44fa70_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_44fa70, field_88, 0x88);

// 0x710044fa70
u64 Unk_44fa70_get(const Unk_44fa70* self) {
    if (self->field_88 == nullptr) {
        return 0;
    }
    return self->field_88->field_90;
}

struct Unk_44fa90_88 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_44fa90_88, field_98, 0x98);

struct Unk_44fa90 {
    u8 _0[0x88];
    Unk_44fa90_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_44fa90, field_88, 0x88);

// 0x710044fa90
u64 Unk_44fa90_get(const Unk_44fa90* self) {
    if (self->field_88 == nullptr) {
        return 0;
    }
    return self->field_88->field_98;
}

struct Unk_44fab0_88 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_44fab0_88, field_40, 0x40);

struct Unk_44fab0 {
    u8 _0[0x88];
    Unk_44fab0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_44fab0, field_88, 0x88);

// 0x710044fab0
u64 Unk_44fab0_get(const Unk_44fab0* self) {
    if (self->field_88 == nullptr) {
        return 0;
    }
    return self->field_88->field_40;
}

struct Unk_44fad0 {
    u8 _0[0x130];
    u64 field_130;
};
PKMN_OFFSET_ASSERT(Unk_44fad0, field_130, 0x130);

// 0x710044fad0
u64 Unk_44fad0_get(const Unk_44fad0* self) {
    return self->field_130;
}

struct Unk_44fae0 {
    u8 _0[0x138];
    u32 field_138;
};
PKMN_OFFSET_ASSERT(Unk_44fae0, field_138, 0x138);

// 0x710044fae0
u32 Unk_44fae0_get(const Unk_44fae0* self) {
    return self->field_138;
}

struct Unk_44faf0 {
    u8 _0[0x13c];
    u32 field_13c;
};
PKMN_OFFSET_ASSERT(Unk_44faf0, field_13c, 0x13c);

// 0x710044faf0
u32 Unk_44faf0_get(const Unk_44faf0* self) {
    return self->field_13c;
}

struct Unk_44fb00 {
    u8 _0[0x140];
    u8 field_140;
};
PKMN_OFFSET_ASSERT(Unk_44fb00, field_140, 0x140);

// 0x710044fb00
const u8* Unk_44fb00_get(const Unk_44fb00* self) {
    return &self->field_140;
}

struct Unk_44fb10 {
    u8 _0[0x1c0];
    u8 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_44fb10, field_1c0, 0x1c0);

// 0x710044fb10
const u8* Unk_44fb10_get(const Unk_44fb10* self) {
    return &self->field_1c0;
}

struct Unk_44fb20 {
    u8 _0[0x200];
    u8 field_200;
};
PKMN_OFFSET_ASSERT(Unk_44fb20, field_200, 0x200);

// 0x710044fb20
const u8* Unk_44fb20_get(const Unk_44fb20* self) {
    return &self->field_200;
}
