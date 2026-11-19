// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_15b4d40_28 {
    u8 _0[0x90];
    void* field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b4d40_28, field_90, 0x90);

struct Unk_15b4d40 {
    u8 _0[0x28];
    Unk_15b4d40_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b4d40, field_28, 0x28);

void Unk_15b4d50(void*, void*, void*, void*);

// 0x71015b4d40
void Unk_15b4d40_call(const Unk_15b4d40* self, void* value, void* arg2, void* arg3) {
    Unk_15b4d50(self->field_28->field_90, value, arg2, arg3);
}

struct Unk_15b4f90_28 {
    u8 _0[0x90];
    void* field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b4f90_28, field_90, 0x90);

struct Unk_15b4f90 {
    u8 _0[0x28];
    Unk_15b4f90_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b4f90, field_28, 0x28);

void Unk_15b4fa0(void*, void*, void*, void*, void*);

// 0x71015b4f90
void Unk_15b4f90_call(const Unk_15b4f90* self, void* value, void* arg2, void* arg3, void* arg4) {
    Unk_15b4fa0(self->field_28->field_90, value, arg2, arg3, arg4);
}

struct Unk_15b5200_28 {
    u8 _0[0x90];
    void* field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b5200_28, field_90, 0x90);

struct Unk_15b5200 {
    u8 _0[0x28];
    Unk_15b5200_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b5200, field_28, 0x28);

void Unk_15b5210(void*, void*, void*, void*, void*);

// 0x71015b5200
void Unk_15b5200_call(const Unk_15b5200* self, void* value, void* arg2, void* arg3, void* arg4) {
    Unk_15b5210(self->field_28->field_90, value, arg2, arg3, arg4);
}

struct Unk_15b5470_28 {
    u8 _0[0x90];
    void* field_90;
};
PKMN_OFFSET_ASSERT(Unk_15b5470_28, field_90, 0x90);

struct Unk_15b5470 {
    u8 _0[0x28];
    Unk_15b5470_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b5470, field_28, 0x28);

void Unk_15b5480(void*, void*, u64, u64, u64, u64, u64, u64);

// 0x71015b5470
void Unk_15b5470_call(const Unk_15b5470* self, void* value, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7) {
    Unk_15b5480(self->field_28->field_90, value, arg2, arg3, arg4, arg5, arg6, arg7);
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
