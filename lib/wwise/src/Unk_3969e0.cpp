// Scope: common
// What gives the game-parameter manager the values of one of an object's
// items (0x60 bytes each): a distance, angles in degrees, two percentages.
// Placeholder names.
#include "Unk_366110.h"

extern void* Unk_24bbbf8;

// An item, as far as its values go.
struct Unk_3969e0_Item {
    u8 _0[0x24];
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    u8 _30[0xc];
    f32 field_3c;
    f32 field_40;
    u8 _44[0x1c];
};
PKMN_SIZE_ASSERT(Unk_3969e0_Item, 0x60);

struct Unk_3969e0_T {
    u8 _0[8];
    u64 field_8;  // what the values are for
    u8 _10[0x38];
    Unk_3969e0_Item* field_48;
};

// Two angles of an item as `a2` sees it.
void Unk_32e350(void* a0, Unk_3969e0_Item* item, f32* a2, f32* a3);
// Sets the value of a built-in parameter for a key.
void Unk_39eff0(void* self, u32 parameter, Unk_366f90_Key* key, f32 value);

// An angle in degrees, less its whole turns.
static inline f32 Unk_3969e0_Degrees(f32 angle) {
    return (angle - static_cast<f32>(static_cast<s32>(angle * 0.15915494f))) * 57.29578f;
}

// Gives the manager an item's values for an object.
static inline void Unk_3969e0_Report(Unk_3969e0_Item* items, u32 index, u64 object, void* a2) {
    Unk_366f90_Key key(object);
    Unk_3969e0_Item* item = items + index;
    f32 angle1;
    f32 angle2;
    Unk_32e350(a2, item, &angle1, &angle2);
    Unk_39eff0(Unk_24bbbf8, 1, &key, item->field_24);
    Unk_39eff0(Unk_24bbbf8, 2, &key, Unk_3969e0_Degrees(angle1));
    Unk_39eff0(Unk_24bbbf8, 3, &key, Unk_3969e0_Degrees(angle2));
    Unk_39eff0(Unk_24bbbf8, 4, &key, Unk_3969e0_Degrees(item->field_28));
    Unk_39eff0(Unk_24bbbf8, 5, &key, item->field_40 * 100.0f);
    Unk_39eff0(Unk_24bbbf8, 6, &key, item->field_3c * 100.0f);
    Unk_39eff0(Unk_24bbbf8, 7, &key, Unk_3969e0_Degrees(item->field_2c));
}

// 0x71003969e0
void Unk_3969e0(Unk_3969e0_T* self, u32 index, void* a2) {
    Unk_3969e0_Report(self->field_48, index, self->field_8, a2);
}
