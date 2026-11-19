// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c737e0_608 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_c737e0_608, field_60, 0x60);

struct Unk_c737e0 {
    u8 _0[0x608];
    Unk_c737e0_608* field_608;
};
PKMN_OFFSET_ASSERT(Unk_c737e0, field_608, 0x608);

// 0x7100c737e0
bool Unk_c737e0_check(const Unk_c737e0* self) {
    if (self->field_608 == nullptr) {
        return true;
    }
    return self->field_608->field_60 != 0;
}

struct Unk_c739f0 {
    u8 _0[0x5e8];
    void* field_5e8;
    void* field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_c739f0, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_c739f0, field_5f0, 0x5f0);

void Unk_c73490(void*, u32);

// 0x7100c739f0
void Unk_c739f0_call(const Unk_c739f0* self) {
    Unk_c73490(self->field_5e8, 1);
    Unk_c73490(self->field_5f0, 0);
}

struct Unk_c73a20 {
    u8 _0[0x65a];
    u8 field_65a;
};
PKMN_OFFSET_ASSERT(Unk_c73a20, field_65a, 0x65a);

// 0x7100c73a20
void Unk_c73a20_set(Unk_c73a20* self) {
    self->field_65a = 1;
}

struct Unk_c75b60_arg1 {
    u8 field_0;
    u8 _1[0xf];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_c75b60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c75b60_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_c75b60_arg1, field_18, 0x18);

struct Unk_c75b60 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_c75b60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c75b60, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_c75b60, field_18, 0x18);

// 0x7100c75b60
void Unk_c75b60_set(Unk_c75b60* self, const Unk_c75b60_arg1* value) {
    self->field_8 = value->field_0;
    self->field_18 = value->field_18;
    self->field_10 = value->field_10;
}
