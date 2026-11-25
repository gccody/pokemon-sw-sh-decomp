// Scope: common
#include <types.h>

// Five 3-byte slots; a slot is in use when field_0 is set, and field_2 is
// the id it holds.
struct Unk_803600_Slot {
    u8 field_0;
    u8 field_1;
    u8 field_2;
};
PKMN_SIZE_ASSERT(Unk_803600_Slot, 0x3);

struct Unk_803600_Slots {
    Unk_803600_Slot slots[5];
};
PKMN_SIZE_ASSERT(Unk_803600_Slots, 0xf);

static inline u8 Unk_803600_Find(const Unk_803600_Slots* self, u8 id) {
    for (u8 i = 0; i < 5; i++) {
        if (self->slots[i].field_0 != 0 && self->slots[i].field_2 == id)
            return i;
    }
    return 5;
}

// 0x7100803600
u8 Unk_803600(void* self, u8 id) {
    return Unk_803600_Find(static_cast<Unk_803600_Slots*>(self), id);
}

struct Unk_7c2d80_Main;
bool Unk_7cad50(const Unk_7c2d80_Main* self, u8 index);

// 0x71008036a0
bool Unk_8036a0(void* self, void* target, u8 id) {
    u8 index = Unk_803600_Find(static_cast<Unk_803600_Slots*>(self), id);
    if (index == 5)
        return false;
    return Unk_7cad50(static_cast<const Unk_7c2d80_Main*>(target), index);
}

struct Unk_803760_Table {
    u8 _0[0x30];
    u8* field_30;
    u32 field_38;
    u8 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_803760_Table, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_803760_Table, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_803760_Table, field_3c, 0x3c);

// 0x7100803760
u8 Unk_803760(void* self, u8 index) {
    Unk_803760_Table* table = static_cast<Unk_803760_Table*>(self);
    if (table->field_30 != nullptr && index < table->field_38)
        return table->field_30[index];
    return table->field_3c;
}

// 0x7100803790
u8 Unk_803790(void* self, u8 index) {
    return static_cast<Unk_803600_Slots*>(self)->slots[index].field_2;
}
