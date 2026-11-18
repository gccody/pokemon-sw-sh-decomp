// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100919180
void Unk_919180_call(void* self) {
    Unk_eb6230(self, 3);
}

// 0x7100919be0
void Unk_919be0_update() {}

struct Unk_919bf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919bf0_arg1, field_0, 0x0);

struct Unk_919bf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919bf0, field_0, 0x0);

// 0x7100919bf0
void Unk_919bf0_set(const Unk_919bf0* self, Unk_919bf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_919c00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919c00_arg1, field_0, 0x0);

struct Unk_919c00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919c00, field_0, 0x0);

// 0x7100919c00
void Unk_919c00_set(const Unk_919c00* self, Unk_919c00_arg1* value) {
    value->field_0 = self->field_0;
}
