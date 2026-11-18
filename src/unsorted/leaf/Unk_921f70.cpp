// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

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
