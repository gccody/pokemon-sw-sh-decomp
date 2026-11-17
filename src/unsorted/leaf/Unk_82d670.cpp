// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82d670 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_82d670, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_82d670, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82d670, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82d670, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_82d670, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_82d670, field_28, 0x28);

// 0x710082d670
void Unk_82d670_set(Unk_82d670* self) {
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

void Unk_7eb260();

// 0x710082d990
void Unk_82d990_call() {
    Unk_7eb260();
}

void Unk_780d70();

// 0x710082da60
void Unk_82da60_call() {
    Unk_780d70();
}

void Unk_7812a0();

// 0x710082da70
void Unk_82da70_call() {
    Unk_7812a0();
}
