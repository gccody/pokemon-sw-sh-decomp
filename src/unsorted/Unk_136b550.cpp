// Scope: common
// Functions of Unk_2432540 (src/unsorted/Unk_136af10.h) on its ID and string.
#include "unsorted/Unk_136af10.h"

// 0x710067c120 (src/unsorted/leaf/Unk_67bdb0.cpp): copies a string of u16
// units.
u32 Unk_67c120(u64, u64, u16);

// 0x710067c270: whether two strings of u16 units are equal.
bool Unk_67c270(const u16* a, const u16* b);

// Functions of the object Unk_2432540::Unk_136b5e0 compares with
// (src/unsorted/leaf/Unk_7626f0.cpp): its ID, its byte and its string.
struct Unk_767d90;
struct Unk_7676d0;
struct Unk_767680;
u32 Unk_767d90_call(const Unk_767d90* self);
u32 Unk_7676d0_call(const Unk_7676d0* self);
void Unk_767680_call(const Unk_767680* self, void* value, u32 arg2);

// 0x71007692e0 and 0x7100769330: a mode of the object turned on (whether it
// was off), then back off when it was.
bool Unk_7692e0(void* self);
bool Unk_769330(void* self, bool value);

// 0x710136b5b0
void Unk_2432540::Unk_136b5b0(Unk_136b5b0_Out* out) {
    out->field_0 = field_60.field_a0;
    out->field_4 = field_60.field_a5;
    out->field_5 = field_60.field_a7;
    Unk_67c120(reinterpret_cast<u64>(out->field_6), reinterpret_cast<u64>(field_60.field_b0), 13);
}

// 0x710136b5e0
bool Unk_2432540::Unk_136b5e0(void* object) {
    bool was = Unk_7692e0(object);
    bool result = false;
    if (field_60.field_a0 == Unk_767d90_call(static_cast<const Unk_767d90*>(object)) &&
        field_60.field_a5 == Unk_7676d0_call(static_cast<const Unk_7676d0*>(object))) {
        u16 name[13];
        Unk_767680_call(static_cast<const Unk_767680*>(object), name, 13);
        result = Unk_67c270(name, field_60.field_b0);
    }
    Unk_769330(object, was);
    return result;
}

// 0x710136b6a0
u32 Unk_2432540::Unk_136b6a0() {
    return field_60.field_a0 % 1000000;
}
