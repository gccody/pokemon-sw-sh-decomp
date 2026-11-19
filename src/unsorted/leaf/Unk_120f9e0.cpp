// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_120f9e0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_120f9e0, field_70, 0x70);

// 0x710120f9e0
void Unk_120f9e0_setField70(Unk_120f9e0* self, u64 value) {
    self->field_70 = value;
}

struct Unk_1210230 {
    u8 _0[0x140];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_1210230, field_140, 0x140);

// 0x7101210230
u32 Unk_1210230_getField140(const Unk_1210230* self) {
    return self->field_140;
}

struct Unk_1210240 {
    u8 _0[0x148];
    u8 field_148;
};
PKMN_OFFSET_ASSERT(Unk_1210240, field_148, 0x148);

// 0x7101210240
u8* Unk_1210240_getField148Ptr(Unk_1210240* self) {
    return &self->field_148;
}

// 0x7101210f50
void Unk_1210f50_update() {}

struct Unk_1210f60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210f60_arg1, field_0, 0x0);

struct Unk_1210f60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210f60, field_0, 0x0);

// 0x7101210f60
void Unk_1210f60_set(const Unk_1210f60* self, Unk_1210f60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1210f70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210f70_arg1, field_0, 0x0);

struct Unk_1210f70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210f70, field_0, 0x0);

// 0x7101210f70
void Unk_1210f70_set(const Unk_1210f70* self, Unk_1210f70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1210f80 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210f80, field_0, 0x0);

void Unk_1210b40(void*);

// 0x7101210f80
void Unk_1210f80_call(const Unk_1210f80* self) {
    Unk_1210b40(self->field_0);
}

// 0x7101210f90
void Unk_1210f90_update() {}

struct Unk_1210fa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210fa0_arg1, field_0, 0x0);

struct Unk_1210fa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210fa0, field_0, 0x0);

// 0x7101210fa0
void Unk_1210fa0_set(const Unk_1210fa0* self, Unk_1210fa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1210fb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210fb0_arg1, field_0, 0x0);

struct Unk_1210fb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1210fb0, field_0, 0x0);

// 0x7101210fb0
void Unk_1210fb0_set(const Unk_1210fb0* self, Unk_1210fb0_arg1* value) {
    value->field_0 = self->field_0;
}
