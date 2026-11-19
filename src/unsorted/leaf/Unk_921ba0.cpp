// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_921ba0 {
    u8 _0[0x80];
    void* field_80;
    u8 _88[0x30];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_921ba0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_921ba0, field_b8, 0xb8);

void Unk_9228b0(void*, void*);

// 0x7100921ba0
void Unk_921ba0_call(Unk_921ba0* self, void* value) {
    Unk_9228b0(self->field_80, value);
    self->field_b8 = 0;
}

// 0x7100921f70
void Unk_921f70_update() {}

struct Unk_921f80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_921f80_arg1, field_0, 0x0);

struct Unk_921f80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_921f80, field_0, 0x0);

// 0x7100921f80
void Unk_921f80_set(const Unk_921f80* self, Unk_921f80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_921f90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_921f90_arg1, field_0, 0x0);

struct Unk_921f90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_921f90, field_0, 0x0);

// 0x7100921f90
void Unk_921f90_set(const Unk_921f90* self, Unk_921f90_arg1* value) {
    value->field_0 = self->field_0;
}
