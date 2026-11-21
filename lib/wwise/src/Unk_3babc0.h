#pragma once
// The switch groups' manager (the object at 0x71024bbbc8): which subscriber
// follows which group. Placeholder names.
#include "Unk_23837a8.h"
#include "hash_list.h"
#include "sorted_array.h"

// A subscription: a subscriber and the group it follows.
struct Unk_3babc0_Entry {
    Unk_23837a8* key;  // the subscriber
    Unk_3babc0_Entry* next;
    u32 field_10;  // the group
    bool field_14;  // false once it is unsubscribed while the manager is locked

    Unk_3babc0_Entry() : field_14(true) {}
};
PKMN_SIZE_ASSERT(Unk_3babc0_Entry, 0x18);

struct Unk_3babc0_EntryPolicy {
    static u32 Key(Unk_3babc0_Entry* item) { return Hash(item->key); }
    static Unk_23837a8* Id(Unk_3babc0_Entry* item) { return item->key; }
    static u32 Hash(Unk_23837a8* key) { return static_cast<u32>(reinterpret_cast<u64>(key)); }
    static Unk_3babc0_Entry*& Next(Unk_3babc0_Entry* item) { return item->next; }
};

typedef Unk_SortedKeyArray<Unk_3babc0_Entry*, Unk_3babc0_Entry*, Unk_KeyIsItem<Unk_3babc0_Entry*>>
    Unk_3babc0_Entries;

// An array that starts empty.
template <class Array>
struct Unk_Empty : Array {
    Unk_Empty() {
        this->field_0 = nullptr;
        this->field_8 = 0;
        this->field_c = 0;
    }
};

// What a value is looked up by: the game object and more (0x30 bytes, every
// member in a word of its own).
struct Unk_3babc0_Key {
    void* field_0;  // the game object
    u32 field_8;
    u32 field_10 __attribute__((aligned(8)));
    u8 field_18 __attribute__((aligned(8)));
    u8 field_20 __attribute__((aligned(8)));
    void* field_28;

    Unk_3babc0_Key() : field_8(0), field_10(0), field_18(0xff), field_20(0xff), field_28(nullptr) {
        field_0 = nullptr;
    }
    explicit Unk_3babc0_Key(void* object)
        : field_8(0), field_10(0), field_18(0xff), field_20(0xff), field_28(nullptr) {
        field_0 = object;
    }
};
PKMN_SIZE_ASSERT(Unk_3babc0_Key, 0x30);

// An item of Unk_2382c60's array: 0x28 bytes with a virtual destructor.
struct Unk_2382c60_Item {
    virtual ~Unk_2382c60_Item();

    u8 _8[0x20];
};
void Unk_39f8e0(Unk_2382c60_Item* self);

// The values of a group by key (the classes with the vtables 0x7102382c60
// and, derived from it, 0x7102382c80).
struct Unk_2382c60 {
    virtual void vf0();

    u32 field_8;
    union {
        u8 field_c;
    };
    Unk_Array<Unk_2382c60_Item> field_10;

    Unk_2382c60() : field_8(0), field_c(0) {
        field_10.field_0 = nullptr;
        field_10.field_8 = 0;
        field_10.field_c = 0;
    }
    ~Unk_2382c60() {}

    void Term() {
        for (auto it = field_10.Begin(), end = field_10.End(); it != end; ++it)
            Unk_39f8e0(&*it);
        field_10.Term();
    }
};

struct Unk_2382c80 : Unk_2382c60 {
    void vf0() override;
};

void Unk_39a100(Unk_2382c60* self, const Unk_3babc0_Key& key);
u32* Unk_39c830(Unk_2382c60* self, const Unk_3babc0_Key& key);
void Unk_39b8b0_call(void*, u64);
extern void* Unk_24bbbf8;

// A point of the curve that maps a game parameter to a group's values, as it
// is given and as the parameter's manager takes it.
struct Unk_3babc0_Point {
    u32 field_0;
    u32 field_4;  // the value
    u32 field_8;
};
struct Unk_3babc0_CurvePoint {
    u32 field_0;
    f32 field_4;  // the index of the value
    u32 field_8;
};
u32 Unk_39b840(void* self, struct Unk_3babc0_Group* group, u32 id, u32 type,
               Unk_3babc0_CurvePoint* points, u32 numPoints);
f32 Unk_39d550(void* self, struct Unk_3babc0_Group* group, const Unk_3babc0_Key* key);
u32* Unk_3657c0(Unk_2382c60* self, const Unk_3babc0_Key* key);

// A group: its subscribers, sorted by address.
struct Unk_3babc0_Group {
    u32 key;  // the group's ID
    Unk_3babc0_Group* next;
    Unk_Empty<Unk_Array<u32>> field_10;
    u32 field_20;
    u32 field_24;
    Unk_Empty<Unk_3babc0_Entries> field_28;
    Unk_2382c80 field_38;

    explicit Unk_3babc0_Group(u32 id) : key(id), field_20(0), field_24(0) {}
    ~Unk_3babc0_Group();

    // Stops taking the value from a game parameter.
    void ClearCurve() {
        field_20 = 0;
        field_10.Term();
    }

    void UnsetCurve() {
        if (field_20 != 0) {
            Unk_39b8b0_call(Unk_24bbbf8, reinterpret_cast<u64>(this));
            ClearCurve();
        }
    }

    u32* SetValue(void* object) {
        return Unk_39c830(&field_38, Unk_3babc0_Key(object));
    }

    void RemoveValues(void* object) {
        Unk_39a100(&field_38, Unk_3babc0_Key(object));
    }
};
PKMN_OFFSET_ASSERT(Unk_3babc0_Group, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3babc0_Group, field_38, 0x38);
PKMN_SIZE_ASSERT(Unk_3babc0_Group, 0x58);

struct Unk_3babc0_GroupPolicy {
    static u32 Key(Unk_3babc0_Group* item) { return item->key; }
    static u32 Id(Unk_3babc0_Group* item) { return item->key; }
    static u32 Hash(u32 key) { return key; }
    static Unk_3babc0_Group*& Next(Unk_3babc0_Group* item) { return item->next; }
};

// What to do once the manager is unlocked.
struct Unk_3babc0_Action {
    u32 field_0;  // 0 subscribe, 1 unsubscribe
    Unk_23837a8* field_8;  // the subscriber
    u32 field_10;  // the group

    Unk_3babc0_Action() : field_0(0), field_8(nullptr), field_10(0) {}
    Unk_3babc0_Action(u32 type, Unk_23837a8* subscriber, u32 group)
        : field_0(type), field_8(subscriber), field_10(group) {}
};
PKMN_SIZE_ASSERT(Unk_3babc0_Action, 0x18);

struct Unk_3babc0 {
    Unk_HashListBareEx<u32, Unk_3babc0_Group, Unk_3babc0_GroupPolicy> field_0;
    Unk_HashListBareEx<Unk_23837a8*, Unk_3babc0_Entry, Unk_3babc0_EntryPolicy> field_18;
    Unk_Array<Unk_3babc0_Action> field_30;
    s32 field_40;  // locked while above 0

    // Tells the subscribers of a group its value for a game object.
    static void Notify(Unk_3babc0_Group* group, u32 value, void* object, void* arg3) {
        for (auto it = group->field_28.Begin(); it != group->field_28.End(); ++it) {
            Unk_3babc0_Entry* entry = *it;
            if (entry->field_14 && entry->key != nullptr)
                entry->key->vf2(value, Unk_3babc0_Key(object), arg3);
        }
    }

    // Takes a subscription out of its group's list.
    void Unlink(Unk_3babc0_Entry* entry) {
        Unk_3babc0_Group* group = field_0.Exists(entry->field_10);
        if (group != nullptr)
            group->field_28.Unset(entry);
    }
};
PKMN_OFFSET_ASSERT(Unk_3babc0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_40, 0x40);
