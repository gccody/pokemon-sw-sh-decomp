// Scope: common
// Two small lists behind an interface (the classes with the vtables
// 0x7102382a40 and 0x7102382ac0): pairs of a key and a value, and plain keys.
// Placeholder names; the members are vf<slot>, as in lib/wwise/class.
#include "Unk_PlacementNew.h"
#include "containers.h"

struct Unk_394ec0_Item {
    u32 key;
    u32 value;
};

// The list of pairs.
class Unk_2382a40 {
public:
    Unk_2382a40() {
        field_8.field_0 = nullptr;
        field_8.field_8 = 0;
        field_8.field_c = 0;
    }
    virtual ~Unk_2382a40();
    virtual u32 vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual u32 vf5(u16 index);
    virtual u32 vf6(u32 key, u32 value);
    virtual void vf7(u32 key);
    virtual void vf8();
    virtual bool vf9(u32 key);
    virtual bool vf10(u32 key, u16* index);
    virtual u32 vf11(u16 index);
    virtual void vf12(u16 index, u32 value);
    virtual u32 vf13();

    Unk_Array<Unk_394ec0_Item, Unk_PoolDefault, 8> field_8;
};

// 0x7100394ec0
void Unk_394ec0(Unk_2382a40* self) {
    new (self) Unk_2382a40;
}

// 0x7100394f20
void Unk_2382a40::vf3() {
    field_8.Term();
    Unk_Delete(this);
}

// 0x7100394fa0
u32 Unk_2382a40::vf5(u16 index) {
    return field_8.field_0[index].key;
}

// 0x7100394fc0
u32 Unk_2382a40::vf6(u32 key, u32 value) {
    Unk_394ec0_Item* item = field_8.AddLastGrow();
    if (item != nullptr) {
        item->value = value;
        item->key = key;
        return 1;
    }
    return 2;
}

// 0x7100395110
void Unk_2382a40::vf7(u32 key) {
    for (auto it = field_8.Begin(); it != field_8.End();) {
        if ((*it).key == key)
            it = field_8.Erase(it);
        else
            ++it;
    }
}

// 0x7100395300
bool Unk_2382a40::vf9(u32 key) {
    for (auto it = field_8.Begin(), end = field_8.End(); it != end; ++it) {
        if ((*it).key == key)
            return true;
    }
    return false;
}

// 0x7100395340
bool Unk_2382a40::vf10(u32 key, u16* index) {
    u32 i = 0;
    for (auto it = field_8.Begin(), end = field_8.End(); it != end; ++i, ++it) {
        if ((*it).key == key) {
            *index = i;
            return true;
        }
    }
    return false;
}

// 0x7100395240
u32 Unk_2382a40::vf11(u16 index) {
    return field_8.field_0[index].value;
}

// 0x7100395220
void Unk_2382a40::vf12(u16 index, u32 value) {
    field_8.field_0[index].value = value;
}

// 0x7100395260
u32 Unk_2382a40::vf13() {
    u32 sum = 0;
    for (auto it = field_8.Begin(), end = field_8.End(); it != end; ++it)
        sum += (*it).value;
    return sum;
}

// The list of keys.
class Unk_2382ac0 {
public:
    Unk_2382ac0() {
        field_8.field_0 = nullptr;
        field_8.field_8 = 0;
        field_8.field_c = 0;
    }
    virtual ~Unk_2382ac0();
    virtual u32 vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual u32 vf5(u16 index);
    virtual u32 vf6(u32 key);
    virtual void vf7(u32 key);
    virtual void vf8();
    virtual bool vf9(u32 key);
    virtual bool vf10(u32 key, u16* index);

    Unk_Array<u32, Unk_PoolDefault, 16> field_8;
};

// 0x7100395390
void Unk_395390(Unk_2382ac0* self) {
    new (self) Unk_2382ac0;
}

// 0x71003953f0
void Unk_2382ac0::vf3() {
    field_8.Term();
    Unk_Delete(this);
}

// 0x7100395470
u32 Unk_2382ac0::vf5(u16 index) {
    return field_8.field_0[index];
}

// 0x7100395480
u32 Unk_2382ac0::vf6(u32 key) {
    return field_8.AddLastGrow(key) != nullptr ? 1 : 2;
}

// 0x71003955c0
void Unk_2382ac0::vf7(u32 key) {
    auto it = field_8.FindEx(key);
    if (it != field_8.End())
        field_8.Erase(it);
}

// 0x71003956c0
bool Unk_2382ac0::vf9(u32 key) {
    return field_8.FindEx(key) != field_8.End();
}

// 0x7100395710
bool Unk_2382ac0::vf10(u32 key, u16* index) {
    auto it = field_8.FindEx(key);
    if (it != field_8.End()) {
        *index = it.item - field_8.field_0;
        return true;
    }
    return false;
}
