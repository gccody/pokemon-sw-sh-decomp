// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71006bfa40
void Unk_6bfa40_update() {}

struct Unk_6bfa50 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bfa50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bfa50, field_8, 0x8);

// 0x71006bfa50
void Unk_6bfa50_set(const Unk_6bfa50* self, Unk_6bfa50* value) {
    *value = *self;
}

struct Unk_6bfa60 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bfa60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bfa60, field_8, 0x8);

// 0x71006bfa60
void Unk_6bfa60_set(const Unk_6bfa60* self, Unk_6bfa60* value) {
    *value = *self;
}

struct Unk_6bfa70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6bfa70_arg1, field_0, 0x0);

struct Unk_6bfa70_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6bfa70_arg2, field_0, 0x0);

struct Unk_6bfa70_arg3 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6bfa70_arg3, field_0, 0x0);

struct Unk_6bfa70 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bfa70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bfa70, field_8, 0x8);

void Unk_6bf240(u64, u64, u32, u16, u8);

// 0x71006bfa70
void Unk_6bfa70_call(const Unk_6bfa70* self,
                     const Unk_6bfa70_arg1* value,
                     const Unk_6bfa70_arg2* arg2,
                     const Unk_6bfa70_arg3* arg3) {
    Unk_6bf240(self->field_0, value->field_0, arg2->field_0, arg3->field_0, self->field_8);
}

// 0x71006bfa90
void Unk_6bfa90_update() {}

struct Unk_6bfaa0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bfaa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bfaa0, field_8, 0x8);

// 0x71006bfaa0
void Unk_6bfaa0_set(const Unk_6bfaa0* self, Unk_6bfaa0* value) {
    *value = *self;
}

struct Unk_6bfab0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bfab0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bfab0, field_8, 0x8);

// 0x71006bfab0
void Unk_6bfab0_set(const Unk_6bfab0* self, Unk_6bfab0* value) {
    *value = *self;
}
