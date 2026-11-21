#pragma once
// Three indexed classes of one shape (0x78 bytes, a second base at 0x18), and
// the objects that refer to them (Unk_362360_T), kept in a list each.
// Placeholder names.
#include <string.h>
#include "Unk_Indexed.h"
#include "Unk_KeyArray.h"

// The second base (0x71003629e0 constructs it, 0x7100362a20 destroys it).
class Unk_2380c68 {
public:
    Unk_2380c68();
    virtual ~Unk_2380c68();
    virtual void wf2();
    virtual void wf3();
    virtual void wf4();
    virtual void wf5();
    virtual void wf6();
    virtual void wf7();
    virtual void wf8();
    virtual void wf9();
    virtual void wf10();
    virtual void wf11();
    virtual void wf12();
    virtual void wf13();
    virtual u32 wf14(u8** data, u32* size);
    u8 field_8;
    u64 field_10;
};
void Unk_362a20(void* self);

// memcpy with a 32-bit size.
static inline void Unk_MemCpy(void* dest, const void* src, u32 size) {
    memcpy(dest, src, size);
}

// A table of points, with what it converts.
struct Unk_35f3b0_Point {
    f32 field_0;
    f32 field_4;
    u32 field_8;
};

struct Unk_35f3b0_Table {
    Unk_35f3b0_Point* field_0;
    u32 field_8;  // number of points
    u32 field_c;  // scaling

    Unk_35f3b0_Table() : field_0(nullptr), field_8(0), field_c(0) {}

    void Unset() {
        if (field_0 != nullptr) {
            Unk_3047c0(Unk_237e820, field_0);
            field_0 = nullptr;
        }
        field_8 = 0;
        field_c = 0;
    }

    u32 Set(const Unk_35f3b0_Point* points, u32 count, u32 scaling) {
        u32 result = 0x1f;
        Unset();
        if (count != 0 && points != nullptr) {
            field_0 = static_cast<Unk_35f3b0_Point*>(
                Unk_3045e0(Unk_237e820, count * sizeof(Unk_35f3b0_Point)));
            if (field_0 != nullptr) {
                Unk_MemCpy(field_0, points, count * sizeof(Unk_35f3b0_Point));
                field_8 = count;
                field_c = scaling;
                result = 1;
            } else {
                result = 0x34;
                field_8 = 0;
            }
        }
        return result;
    }
};

// A parameter of the object that follows a game parameter.
struct Unk_360c20_Sub {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u16 field_6;  // the parameter
    u32 field_8;
    Unk_35f3b0_Table field_10;
};
PKMN_SIZE_ASSERT(Unk_360c20_Sub, 0x20);

// The value of a parameter.
struct Unk_360c20_Value {
    Unk_360c20_Value() : field_0(0), field_2(0), field_4(0) {}

    void Set(Unk_360c20_Value other) { *this = other; }
    void Set(u16 parameter, u8 set, f32 number) {
        Unk_360c20_Value value;
        value.field_0 = parameter;
        value.field_2 = set;
        value.field_4 = number;
        Set(value);
    }

    u16 field_0;  // the parameter
    u8 field_2;  // set
    f32 field_4;
};
PKMN_SIZE_ASSERT(Unk_360c20_Value, 8);

struct Unk_360c20_Values : Unk_GrowArray<Unk_360c20_Value, Unk_PoolDefault, 2, Unk_360c20_Value> {
    Iterator FindEx(u16 parameter) const {
        Iterator it = Begin();
        for (Iterator end = End(); it != end; ++it) {
            if ((*it).field_0 == parameter)
                break;
        }
        return it;
    }

    // The value of a parameter, or null.
    f32* Exists(u16 parameter) const {
        Iterator it = FindEx(parameter);
        return it != End() ? &it.item->field_4 : nullptr;
    }
};

// The object of the parameters of a plugin.
struct Unk_360c20_Params {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* allocator);
    virtual void vf3();
    virtual u32 vf4(void* allocator, const void* data, u32 size);
    virtual void vf5(void* allocator);
};

struct Unk_362360_T;

// A list of Unk_362360_T by its first one.
struct Unk_362360_List {
    struct IteratorEx {
        Unk_362360_T* item;
        Unk_362360_T* prev;

        inline IteratorEx& operator++();
        bool operator!=(const IteratorEx& other) const { return item != other.item; }
    };

    Unk_362360_T* field_0;

    IteratorEx BeginEx() {
        IteratorEx it;
        it.item = field_0;
        it.prev = nullptr;
        return it;
    }

    IteratorEx End() {
        IteratorEx it;
        it.item = nullptr;
        it.prev = nullptr;
        return it;
    }

    IteratorEx FindEx(Unk_362360_T* item) {
        IteratorEx it = BeginEx();
        for (; it != End(); ++it) {
            if (it.item == item)
                break;
        }
        return it;
    }

    inline void AddFirst(Unk_362360_T* item);
    inline void RemoveItem(Unk_362360_T* item, Unk_362360_T* prev);

    // Whether the item was in the list.
    bool Remove(Unk_362360_T* item) {
        IteratorEx it = FindEx(item);
        if (it != End()) {
            RemoveItem(it.item, it.prev);
            return true;
        }
        return false;
    }
};

struct Unk_360c20_T : Unk_Indexed, Unk_2380c68 {
    virtual void vf2();  // add a reference
    virtual void vf3();  // release

    u32 field_30;
    Unk_360c20_Params* field_38;
    Unk_KeyArray<u32, u32> field_40;
    Unk_GrowArray<Unk_360c20_Sub, Unk_PoolDefault, 2> field_50;
    Unk_360c20_Values field_60;
    Unk_362360_List field_70;
};
PKMN_OFFSET_ASSERT(Unk_360c20_T, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_360c20_T, field_50, 0x50);
PKMN_SIZE_ASSERT(Unk_360c20_T, 0x78);

// A value of a parameter of an Unk_362360_T, and where it comes from.
struct Unk_362360_Item {
    Unk_362360_Item() : field_0(0), field_4(0), field_8(0), field_c(0) {}

    u32 field_0;
    u32 field_4;
    u16 field_8;  // the parameter
    f32 field_c;
};
PKMN_SIZE_ASSERT(Unk_362360_Item, 0x10);

struct Unk_362360_Sink {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u32 parameter, const f32* value, u32 size);
    virtual void vf3();
    virtual u32 vf4(void* allocator, const void* data, u32 size);
    virtual void vf5(void* allocator);
};

// An object that refers to an Unk_360c20_T.
struct Unk_362360_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();

    Unk_360c20_Params* field_8;
    Unk_360c20_T* field_10;
    u64 field_18;
    u32 field_20;
    u32 _24;
    u32 field_28;
    u32 _2c;
    u8 field_30;
    u8 _31[7];
    u8 field_38;
    u8 _39[7];
    u64 field_40;
    Unk_GrowArray<Unk_362360_Item, Unk_PoolDefault, 2> field_48;
    Unk_362360_T* field_58;  // next
};
PKMN_OFFSET_ASSERT(Unk_362360_T, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_362360_T, field_58, 0x58);

inline void Unk_362360_List::AddFirst(Unk_362360_T* item) {
    if (field_0 == nullptr) {
        field_0 = item;
        item->field_58 = nullptr;
    } else {
        item->field_58 = field_0;
        field_0 = item;
    }
}

inline Unk_362360_List::IteratorEx& Unk_362360_List::IteratorEx::operator++() {
    prev = item;
    item = item->field_58;
    return *this;
}

inline void Unk_362360_List::RemoveItem(Unk_362360_T* item, Unk_362360_T* prev) {
    if (item == field_0)
        field_0 = item->field_58;
    else
        prev->field_58 = item->field_58;
}

// The allocators the plugins and their parameters are created with.
extern u8 Unk_2380d00;
extern u8 Unk_2380d10;
