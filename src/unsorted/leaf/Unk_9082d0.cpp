// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9082d0_410 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_9082d0_410, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9082d0_410, field_4, 0x4);
struct Unk_9082d0 {
    u8 _0[0x410];
    Unk_9082d0_410* field_410;
    u64 field_418;
};
PKMN_OFFSET_ASSERT(Unk_9082d0, field_410, 0x410);
PKMN_OFFSET_ASSERT(Unk_9082d0, field_418, 0x418);

// 0x71009082d0
u32 Unk_9082d0_get(const Unk_9082d0* self) {
    if (self->field_418 != 0) {
        if (self->field_410->field_4 != 0) {
            return self->field_410->field_0;
        }
        return 0;
    }
    return 0;
}

struct Unk_90de80 {
    u8 _0[0x738];
    void* field_738;
};
PKMN_OFFSET_ASSERT(Unk_90de80, field_738, 0x738);

void Unk_8f4430(void*);

// 0x710090de80
void Unk_90de80_call(const Unk_90de80* self) {
    if (self->field_738 != nullptr) {
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
