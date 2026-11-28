// Scope: common
// The reading virtual function of Unk_2432ba8 and its accessors. Its callers
// (src/unsorted/Unk_13e6430.cpp, Unk_13e6ac0.cpp, src/battle/battle_engine/
// Unk_7f7fe0.cpp) name some of them as functions over the object's base.
#include "battle/battle_engine/Unk_137af00.h"

// The type the store's read of the block is instantiated with
// (src/unsorted/families/Unk_13456e0.cpp): it's the block's (the same key as
// the write's), but its placeholder was named apart from Unk_137b770_T.
struct Unk_137bd80_T;

// 0x710136e810
void Unk_136e810(u32 kind, u32 value);

// 0x710067be60 (src/unsorted/leaf/Unk_67bdb0.cpp): copies a string of u16
// units.
u32 Unk_67be60_call(Unk_67be60* self, u64 value);

// The multiplier of each count of bits of the block's field_0 (0 to 8).
extern const u8 Unk_1f34574[] __attribute__((visibility("hidden")));

static const u32 kMax = 9999999;

// 0x710137b540
// NON_MATCHING: the first key's stack slot, as in vf9 (Unk_137af00.cpp).
void Unk_2432ba8::vf8() {
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x1b882b09;
        if (!store->Unk_1346030(key, reinterpret_cast<Unk_137bd80_T*>(&field_60), sizeof(field_60))
                 .field_0 &&
            store->field_58 != nullptr)
            store->field_58->vf10(&key);
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x3f8120ba;
        Unk_2432ba8_Value<u16> value = Unk_1346e90(store, key);
        if (!value.field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&key);
        field_27c = value.field_value;
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x9ec079da;
        Unk_2432ba8_Value<u16> value = Unk_1346e90(store, key);
        if (!value.field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&key);
        field_27e = value.field_value;
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0xe2798dde;
        Unk_2432ba8_Value<u8> value = Unk_134d370(store, key);
        if (!value.field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&key);
        field_280 = value.field_value;
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x6c99f9a0;
        Unk_2432ba8_Value<u16> value = Unk_1346e90(store, key);
        if (!value.field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&key);
        field_282 = value.field_value;
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0xc7652f1c;
        Unk_2432ba8_Value<u32> value = Unk_13586b0(store, key);
        if (!value.field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&key);
        field_284 = value.field_value;
    }
}

// 0x710137b8e0
u32 Unk_137b8e0(Unk_239a418* self, u32 value) {
    Unk_2432ba8* object = static_cast<Unk_2432ba8*>(self);
    if (value > kMax) {
        object->field_60.field_4 = kMax;
        return kMax;
    }
    object->field_60.field_4 += value;
    Unk_136e810(0x2c, value);
    if (object->field_60.field_4 > kMax) {
        object->field_60.field_4 = kMax;
        return kMax;
    }
    return object->field_60.field_4;
}

// 0x710137b970
u32 Unk_2432ba8::Unk_137b970() {
    u32 count = 0;
    for (u32 bits = field_60.field_0; bits != 0; bits >>= 1)
        count += bits & 1;
    return count;
}

// 0x710137b9a0
void Unk_2432ba8::Unk_137b9a0(u8 count) {
    if (count > 8)
        return;
    u32 bits = 0;
    for (u32 i = 0; i < count; i++)
        bits |= 1 << i;
    field_60.field_0 = bits;
}

// 0x710137ba50
u32 Unk_137ba50(Unk_239a418* self, u32 value) {
    Unk_2432ba8* object = static_cast<Unk_2432ba8*>(self);
    u8 count = object->Unk_137b970();
    u32 amount = value * Unk_1f34574[count] * 4;
    u32 have = object->field_60.field_4;
    return have > amount ? amount : have;
}

// 0x710137bb00
u32 Unk_2432ba8::Unk_137bb00(Unk_67be60* target) {
    return Unk_67be60_call(target, reinterpret_cast<u64>(field_60.field_200));
}

// 0x710137bb10
bool Unk_137bb10(Unk_239a418* self, u32 item) {
    Unk_2432ba8* object = static_cast<Unk_2432ba8*>(self);
    u16 count;
    switch (item) {
        case 79:
            count = 100;
            break;
        case 76:
            count = 200;
            break;
        case 77:
            count = 250;
            break;
        default:
            return false;
    }
    object->field_27e = count;
    object->field_27c = item;
    return true;
}

// 0x710137bb60
s32 Unk_137bb60(Unk_239a418* self) {
    Unk_2432ba8* object = static_cast<Unk_2432ba8*>(self);
    if (object->field_27e == 0)
        return 0;
    switch (object->field_27c) {
        case 76:
        case 77:
        case 79:
            return 1;
        default:
            return 0;
    }
}
