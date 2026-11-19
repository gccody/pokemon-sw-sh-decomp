// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_8faa60(void*, void*, u32, void*);

// 0x71008fa9a0
void Unk_8fa9a0_call(void* self, void* value, u32 arg2, void* arg3) {
    if (arg2 != 0) {
        if (arg2 != 1) {
            if (arg2 == 2) {
                Unk_8faa60(self, value, 0, arg3);
                Unk_8faa60(self, value, 2, arg3);
                Unk_8faa60(self, value, 1, arg3);
                Unk_8faa60(self, value, 3, arg3);
                return;
            }
            return;
        }
        Unk_8faa60(self, value, arg2, arg3);
        Unk_8faa60(self, value, 3, arg3);
        return;
    }
    Unk_8faa60(self, value, arg2, arg3);
    Unk_8faa60(self, value, 2, arg3);
}

struct Unk_8fac20_6f8 {
    u8 _0[0x200];
    u8 field_200;
};
PKMN_OFFSET_ASSERT(Unk_8fac20_6f8, field_200, 0x200);
struct Unk_8fac20 {
    u8 _0[0x6f8];
    Unk_8fac20_6f8* field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_8fac20, field_6f8, 0x6f8);
void Unk_8fc010(void*, u32);

// 0x71008fac20
void Unk_8fac20_call(const Unk_8fac20* self, u32 value, u32 arg2) {
    if (value != 1) {
        if (value == 0) {
            Unk_8fc010(self->field_6f8, arg2);
            return;
        }
        return;
    }
    Unk_8fc010(&self->field_6f8->field_200, arg2);
}

// 0x71008faf50
void Unk_8faf50_update() {}

struct Unk_8faf60 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8faf60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8faf60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8faf60, field_10, 0x10);

// 0x71008faf60
void Unk_8faf60_set(const Unk_8faf60* self, Unk_8faf60* value) {
    *value = *self;
}

struct Unk_8faf80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8faf80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8faf80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8faf80, field_10, 0x10);

// 0x71008faf80
void Unk_8faf80_set(const Unk_8faf80* self, Unk_8faf80* value) {
    *value = *self;
}

// 0x71008faff0
void Unk_8faff0_update() {}

struct Unk_8fb000 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8fb000, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8fb000, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8fb000, field_10, 0x10);

// 0x71008fb000
void Unk_8fb000_set(const Unk_8fb000* self, Unk_8fb000* value) {
    *value = *self;
}

struct Unk_8fb020 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8fb020, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8fb020, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8fb020, field_10, 0x10);

// 0x71008fb020
void Unk_8fb020_set(const Unk_8fb020* self, Unk_8fb020* value) {
    *value = *self;
}
