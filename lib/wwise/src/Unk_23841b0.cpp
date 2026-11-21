// Scope: common
// The class under a bus (vtable 0x71023841b0). Written from the executable.
// Placeholder names.
#include "Unk_FastMath.h"
#include "Unk_23841b0.h"

extern void* Unk_23841b0[];

// The source of what plays into something.
static inline Unk_23841b0_T* Unk_23841b0_Source(Unk_369930* item) {
    return reinterpret_cast<Unk_23841b0_T*>(Unk_369930_get(item));
}

// 0x71003cf7b0: the destructor
void Unk_3cf7b0(void* arg) {
    Unk_23841b0_T* self = static_cast<Unk_23841b0_T*>(arg);
    self->field_0 = Unk_23841b0 + 2;
    Unk_23841b0_List::IteratorEx it = self->field_40.BeginEx();
    while (it != self->field_40.End())
        it = Unk_3cf8e0(self, it);
    self->field_28.Term();
    self->field_50.Term();
    self->field_10.Term();
    while (!self->field_40.IsEmpty()) {
        Unk_369930* item = self->field_40.First();
        self->field_40.RemoveFirst();
        int pool = Unk_2381488;
        item->vf0();
        Unk_304740(pool, item);
    }
    self->field_40.first = nullptr;
    self->field_40.Reset();
}

// 0x71003cf8e0: something no longer plays into it
Unk_23841b0_List::IteratorEx Unk_3cf8e0(Unk_23841b0_T* self, Unk_23841b0_List::IteratorEx& it) {
    self->field_60_1 = 1;
    Unk_23841b0_Source(*it)->field_10.Unset(self);
    Unk_369930* item = *it;
    it = self->field_40.Erase(it);
    if (item != nullptr) {
        int pool = Unk_2381488;
        item->vf0();
        Unk_304740(pool, item);
    }
    return it;
}

// 0x71003cfa80: it no longer plays into anything
void Unk_3cfa80(Unk_24df148_Bus* arg) {
    Unk_23841b0_T* self = reinterpret_cast<Unk_23841b0_T*>(arg);
    while (!self->field_10.IsEmpty()) {
        Unk_23841b0_T* other = self->field_10.Last();
        Unk_23841b0_List::IteratorEx it = other->field_40.BeginEx();
        while (it != other->field_40.End()) {
            if (Unk_23841b0_Source(*it) == self)
                break;
            ++it;
        }
        if (it != other->field_40.End())
            Unk_3cf8e0(other, it);
        else
            self->field_10.field_8--;
    }
}

// 0x71003cfb30: the first of what plays into it that has nothing after it
void* Unk_3cfb30(void* arg) {
    Unk_23841b0_T* self = static_cast<Unk_23841b0_T*>(arg);
    Unk_369930* item = self->field_40.first;
    while (item != nullptr && item->field_2a0 != 0)
        item = item->field_40;
    return item;
}

// 0x71003d1160
void Unk_3d1160(Unk_23841b0_T* self, bool value) {
    for (Unk_369930* item = self->field_40.first; item != nullptr; item = item->field_40)
        item->field_2a4_1 = value;
}

// A source, as far as the next function reads it.
struct Unk_3d1190_Source {
    u8 _0[0x350];
    u32 field_350;
};

// 0x71003d1190: how many of them come from `id`
u32 Unk_3d1190(Unk_23841b0_T* self, u32 id) {
    u32 count = 0;
    for (Unk_369930* item = self->field_40.first; item != nullptr; item = item->field_40) {
        if (static_cast<Unk_3d1190_Source*>(item->field_50)->field_350 == id)
            count++;
    }
    return count;
}

struct Unk_34fb90;
// What 0x7100395920 gives: an array of 8-byte items.
struct Unk_395920_T {
    u8 _0[8];
    u64* field_8;
    u32 field_10;
};
void* Unk_395a20(void* arg);
Unk_395920_T* Unk_395920(void* arg);
u32 Unk_34fb90_get(const Unk_34fb90* self);

// 0x71003d11d0
void* Unk_3d11d0(Unk_23841b0_T* self) {
    return Unk_395a20(self->field_20->field_10);
}

// 0x71003d1260: copies the array (or says how many items it has)
bool Unk_3d1260(Unk_23841b0_T* self, u64* items, u32* count) {
    Unk_395920_T* array = Unk_395920(self->field_20->field_10);
    if (items == nullptr) {
        *count = array->field_10;
        return true;
    }
    *count = array->field_10 < *count ? array->field_10 : *count;
    for (u32 i = 0; i < *count; i++)
        items[i] = array->field_8[i];
    return *count == array->field_10;
}

// 0x71003d1310
u32 Unk_3d1310(Unk_23841b0_T* self) {
    return Unk_34fb90_get(reinterpret_cast<const Unk_34fb90*>(self->field_20));
}

extern const f32 Unk_238497c;

// 0x71003d0050: what plays into it is as loud as the buses it goes to let it be
// NON_MATCHING: the operands of one sum are the other way around (the original adds the
// change to the level, `fadd s17, s17, s18`; here the level is added to the change).
void Unk_3d0050(Unk_23841b0_T* self) {
    for (Unk_369930* item = self->field_40.first; item != nullptr; item = item->field_40) {
        Unk_24df148_Bus* bus = item->field_58;
        if (bus != nullptr) {
            f32 level = item->field_294;
            f32 volume = bus->field_3c;
            f32 limit = bus->field_368 + volume;
            f32 over = level - limit;
            if (over > 0.0f)
                limit = bus->field_36c * over + limit;
            limit = limit > bus->field_360 ? limit : bus->field_360;
            f32 change = volume - limit;
            item->field_290 *= Unk_FromDecibels(change);
            level += change;
            item->field_2a4_0 = Unk_238497c >= level;
            item->field_294 = level;
        }
    }
}
