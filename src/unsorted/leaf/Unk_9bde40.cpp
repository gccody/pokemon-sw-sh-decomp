// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9bde40 {
    u8 _0[0x34];
    u8 field_34;
};
PKMN_OFFSET_ASSERT(Unk_9bde40, field_34, 0x34);

// 0x71009bde40
void Unk_9bde40_set(Unk_9bde40* self) {
    self->field_34 = 1;
}

struct Unk_9bde50 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9bde50, field_10, 0x10);

// 0x71009bde50
bool Unk_9bde50_check(const Unk_9bde50* self) {
    return self->field_10 == 0;
}

// 0x71009be200
u32 Unk_9be200_get() {
    return 1;
}
