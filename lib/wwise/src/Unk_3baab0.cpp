// Scope: common
// What is told when a group's data is prepared: the objects are in a list of
// their group. Written from the executable. Placeholder names.
#include "block_pool.h"

// The object: a base class of the classes that ask (the vtable, then the
// next one of the group's list).
struct Unk_3baab0_Item {
    virtual void vf0();

    Unk_3baab0_Item* next;
};

// What the groups' index has for a group.
struct Unk_3baab0_Group {
    u8 _0[0x20];
    Unk_ListWithLast<Unk_3baab0_Item> field_20;
};
PKMN_OFFSET_ASSERT(Unk_3baab0_Group, field_20, 0x20);

extern u64 Unk_24bbbd0;
// 0x71003b54e0 has the name of a function with one parameter (lib/wwise/leaf):
// the group's ID and type are passed on to it.
u64 Unk_3b54e0(u64 self);
static inline Unk_3baab0_Group* Unk_3baab0_Find(u32 group, u32 type) {
    return reinterpret_cast<Unk_3baab0_Group* (*)(u64, u32, u32)>(Unk_3b54e0)(Unk_24bbbd0, group,
                                                                              type);
}

// 0x71003baab0: into the group's list
u32 Unk_3baab0(void* self, u32 group, u32 type) {
    Unk_3baab0_Group* p = Unk_3baab0_Find(group, type);
    if (p == nullptr)
        return 2;
    p->field_20.AddFirst(static_cast<Unk_3baab0_Item*>(self));
    return 1;
}

// 0x71003bab30: out of the group's list
void Unk_3bab30(void* self, u32 group, u32 type) {
    Unk_3baab0_Group* p = Unk_3baab0_Find(group, type);
    if (p != nullptr)
        p->field_20.Remove(static_cast<Unk_3baab0_Item*>(self));
}
