// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_406230 {
    u8 _0[0x30];
    u64 field_30;
    u8 _38[0x8];
    u16 field_40;
    u16 field_42;
};
PKMN_OFFSET_ASSERT(Unk_406230, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_406230, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_406230, field_42, 0x42);

// 0x7100406230
u32 Unk_406230_update(Unk_406230* self, u16 value, u16 arg2) {
    self->field_30 = 0xffffffffffffffff;
    self->field_40 = value;
    self->field_42 = arg2;
    return 0;
}

void Unk_4071b0(u32, void*);

// 0x71004071a0
void Unk_4071a0_call(u32 self, void* value) {
    Unk_4071b0(self, value);
}
