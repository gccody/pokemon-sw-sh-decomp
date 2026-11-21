#pragma once
// The classes with the vtables 0x7102383cc0 (an owner with a list of items),
// 0x7102383c78 (the items' base class) and 0x7102383ce0 (the items the owner
// at 0x71024df140 has). Their vtables are data here, and their constructors
// and destructors functions that store the vptr. Placeholder names.
#include "Unk_23837d0.h"
#include "block_pool.h"
#include "keylist.h"

struct Unk_2383c58_Item;
u32 Unk_3c2c30(void* self);

// A playing context, as far as these classes use it.
struct Unk_3c44e0_Ctx {
    u8 _0[0x2b8];
    u32 field_2b8;
};

// A node with something that goes with it: the value of the first list.
struct Unk_3c44e0_NodeRef {
    Unk_23837d0_Node* field_0;
    u64 field_8;
};

// What plays for a node of an item: three lists by key (0x90 bytes), counted.
struct Unk_3c44e0_T {
    u32 field_0;  // references
    u8 _4[0xc];
    struct Unk_3c44e0_Use* field_10;  // its use in the owner's list
    Unk_KeyList<u64, Unk_3c44e0_NodeRef> field_18;
    Unk_KeyList<u64, Unk_3c44e0_Ctx*> field_40;
    Unk_KeyList<u64, void*> field_68;
};
PKMN_OFFSET_ASSERT(Unk_3c44e0_T, field_40, 0x40);
PKMN_SIZE_ASSERT(Unk_3c44e0_T, 0x90);

// One use of a node by an item, in the lists of the owner: 0x38 bytes.
struct Unk_3c44e0_Use {
    Unk_3c44e0_Use* next;
    u32 field_8;  // references
    Unk_3c44e0_T* field_10;
    Unk_2383c58_Item* field_18;
    Unk_23837d0_Node* field_20;
    u8 field_28;
    u8 field_29;
    u8 _2a[6];
    u8 field_30_0 : 3;
};
PKMN_SIZE_ASSERT(Unk_3c44e0_Use, 0x38);

// The uses the owner has by node: 0x20 bytes.
struct Unk_2383cc0_Entry {
    Unk_23837d0_Node* key;
    Unk_ListWithLast<Unk_3c44e0_Use> item;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_2383cc0_Entry, 0x20);

// A list by its first item only.
typedef Unk_ListPolicy<Unk_2383c58_Item, Unk_ListNoCount, Unk_ListNoLast> Unk_2383cc0_List;

// The owner: tools/vtables.py named its constructor (0x71003c2cb0).
class Unk_2383cc0 {
public:
    Unk_2383cc0();
    ~Unk_2383cc0();

    void** field_0;  // vptr
    Unk_2383cc0_List field_8;  // the items
    Unk_Array<Unk_2383cc0_Entry> field_10;  // the uses by node
    Unk_ListWithLast<Unk_3c44e0_Use> field_20;  // and the other ones
};
PKMN_SIZE_ASSERT(Unk_2383cc0, 0x30);

// What an item is for: 0x18 bytes, copied field by field with the reference.
struct Unk_2383c78_User {
    u32* field_0;  // a reference counted object, or null
    u64 field_8;
    u32 field_10;
    u32 field_14;

    void Set(const Unk_2383c78_User& other) {
        field_14 = other.field_14;
        field_8 = other.field_8;
        field_10 = other.field_10;
        u32* object = other.field_0;
        if (object != nullptr)
            ++*object;
        field_0 = object;
    }
};

// 12 bytes: packed to 4.
struct __attribute__((packed, aligned(4))) Unk_2383c78_Key {
    u64 field_0;
    u32 field_8;
};
PKMN_SIZE_ASSERT(Unk_2383c78_Key, 0xc);

// What a derived item keeps: a list of these, sorted by `field_4`.
struct Unk_2383ce0_Entry {
    u32 field_0;
    u32 field_4;
    Unk_2383ce0_Entry* next;
};

// An item: the base class's part up to 0x58, then the derived one's.
struct Unk_2383c58_Item {
    virtual ~Unk_2383c58_Item();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5();
    virtual void* vf6();

    Unk_2383c58_Item* next;
    Unk_23837d0_Object* field_10;  // the game object
    Unk_2383c78_User field_18;
    Unk_2383c78_Key field_30;
    u32 field_3c;  // the ID of its node
    Unk_23837d0_Node* field_40;  // and the node
    bool field_48;
    u32 field_4c;  // references
    bool field_50;
    Unk_2383cc0* field_58;  // the owner
    Unk_ListWithLast<Unk_2383ce0_Entry> field_60;
    u8 field_70_0 : 1;  // ended
};
PKMN_OFFSET_ASSERT(Unk_2383c58_Item, field_3c, 0x3c);
PKMN_OFFSET_ASSERT(Unk_2383c58_Item, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_2383c58_Item, field_60, 0x60);
PKMN_SIZE_ASSERT(Unk_2383c58_Item, 0x78);

static inline void Unk_2383cc0_SetVptr(void* self, void** vtable) {
    *static_cast<void***>(self) = vtable + 2;
}

// Something an item did, for its owner to pass on: 0x20 bytes.
struct Unk_3c2f40_Event {
    Unk_2383c58_Item* field_0;
    u32 field_8;
    u32 field_c;
    u32 field_10_0 : 30;
    u32 field_10_30 : 1;
    u32 field_10_31 : 1;
    Unk_3c2f40_Event* next;

    ~Unk_3c2f40_Event() { Unk_3c2c30(field_0); }
};
PKMN_SIZE_ASSERT(Unk_3c2f40_Event, 0x20);

// A list of them (the name is the one its first user gave it).
struct Unk_3c2490_Pair : Unk_ListWithLast<Unk_3c2f40_Event> {};

// Slot 1 of the owner's vtable.
static inline void Unk_2383cc0_vf1(Unk_2383cc0* self, Unk_3c2490_Pair* events,
                                   Unk_3c2f40_Event* event) {
    reinterpret_cast<void (*)(Unk_2383cc0*, Unk_3c2490_Pair*, Unk_3c2f40_Event*)>(
        self->field_0[1])(self, events, event);
}

extern void* Unk_2383c78[];
extern void* Unk_2383cc0_Vtable[];
extern void* Unk_2383ce0[];

void Unk_3c2900(Unk_2383c58_Item* self, Unk_23837d0_Object* object, Unk_2383c78_Key* key,
                Unk_2383c78_User* user, u32 id);
void Unk_3c2990(Unk_2383c58_Item* self);
u32 Unk_3c2a50(Unk_2383c58_Item* self);
void Unk_3c2ec0(Unk_2383cc0* self, Unk_2383c58_Item* item);
void Unk_3c2ee0(Unk_2383cc0* self, Unk_2383c58_Item* item);
void Unk_3c3610(void* self, Unk_2383c58_Item* item);
void Unk_3c44e0(Unk_3c44e0_T* self);
u32 Unk_3c4880(Unk_3c44e0_Use* self);
void Unk_3c5180(Unk_3c44e0_Use* self);
void Unk_3c51e0(Unk_3c44e0_Use* self);
void Unk_3c5260(Unk_3c44e0_Use* self);
