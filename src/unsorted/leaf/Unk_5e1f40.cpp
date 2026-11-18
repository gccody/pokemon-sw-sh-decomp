// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5e1f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f40, field_0, 0x0);

void Unk_5e1dc0(u64);

// 0x71005e1f40
void Unk_5e1f40_call(const Unk_5e1f40* self) {
    Unk_5e1dc0(self->field_0);
}

// 0x71005e1f50
void Unk_5e1f50_update() {}

struct Unk_5e1f60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f60_arg1, field_0, 0x0);

struct Unk_5e1f60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f60, field_0, 0x0);

// 0x71005e1f60
void Unk_5e1f60_set(const Unk_5e1f60* self, Unk_5e1f60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5e1f70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f70_arg1, field_0, 0x0);

struct Unk_5e1f70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f70, field_0, 0x0);

// 0x71005e1f70
void Unk_5e1f70_set(const Unk_5e1f70* self, Unk_5e1f70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5e3a50_0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5e3a50_0, field_10, 0x10);

struct Unk_5e3a50 {
    Unk_5e3a50_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e3a50, field_0, 0x0);

// 0x71005e3a50
u32 Unk_5e3a50_get(const Unk_5e3a50* self) {
    if (self->field_0 == nullptr) {
        return 0;
    }
    return self->field_0->field_10;
}
