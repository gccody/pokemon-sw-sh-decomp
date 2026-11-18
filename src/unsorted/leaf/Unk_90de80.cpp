// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_90de80 {
    u8 _0[0x738];
    u64 field_738;
};
PKMN_OFFSET_ASSERT(Unk_90de80, field_738, 0x738);

void Unk_8f4430(u64);

// 0x710090de80
void Unk_90de80_call(const Unk_90de80* self) {
    if (self->field_738 != 0) {
        Unk_8f4430(self->field_738);
    }
}

struct Unk_913870_0 {
    u8 _0[0x728];
    u64 field_728;
};
PKMN_OFFSET_ASSERT(Unk_913870_0, field_728, 0x728);

struct Unk_913870 {
    Unk_913870_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_913870, field_0, 0x0);

// 0x7100913870
u64 Unk_913870_get(const Unk_913870* self) {
    return self->field_0->field_728;
}

// 0x7100913880
void Unk_913880_update() {}

struct Unk_913890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_913890_arg1, field_0, 0x0);

struct Unk_913890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_913890, field_0, 0x0);

// 0x7100913890
void Unk_913890_set(const Unk_913890* self, Unk_913890_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9138a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9138a0_arg1, field_0, 0x0);

struct Unk_9138a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9138a0, field_0, 0x0);

// 0x71009138a0
void Unk_9138a0_set(const Unk_9138a0* self, Unk_9138a0_arg1* value) {
    value->field_0 = self->field_0;
}
