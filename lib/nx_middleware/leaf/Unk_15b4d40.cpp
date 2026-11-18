// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_15b4d40_28 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b4d40_28, field_90, 0x90);

struct Unk_15b4d40 {
    u8 _0[0x28];
    Unk_15b4d40_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b4d40, field_28, 0x28);

void Unk_15b4d50(u64);

// 0x71015b4d40
void Unk_15b4d40_call(const Unk_15b4d40* self) {
    Unk_15b4d50(self->field_28->field_90);
}

struct Unk_15b4f90_28 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b4f90_28, field_90, 0x90);

struct Unk_15b4f90 {
    u8 _0[0x28];
    Unk_15b4f90_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b4f90, field_28, 0x28);

void Unk_15b4fa0(u64);

// 0x71015b4f90
void Unk_15b4f90_call(const Unk_15b4f90* self) {
    Unk_15b4fa0(self->field_28->field_90);
}

struct Unk_15b5200_28 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b5200_28, field_90, 0x90);

struct Unk_15b5200 {
    u8 _0[0x28];
    Unk_15b5200_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b5200, field_28, 0x28);

void Unk_15b5210(u64);

// 0x71015b5200
void Unk_15b5200_call(const Unk_15b5200* self) {
    Unk_15b5210(self->field_28->field_90);
}

struct Unk_15b5470_28 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b5470_28, field_90, 0x90);

struct Unk_15b5470 {
    u8 _0[0x28];
    Unk_15b5470_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b5470, field_28, 0x28);

void Unk_15b5480(u64);

// 0x71015b5470
void Unk_15b5470_call(const Unk_15b5470* self) {
    Unk_15b5480(self->field_28->field_90);
}

// 0x71015b59d0
void Unk_15b59d0_update() {
}

// 0x71015b59e0
void Unk_15b59e0_update() {
}

// 0x71015b59f0
void Unk_15b59f0_update() {
}
