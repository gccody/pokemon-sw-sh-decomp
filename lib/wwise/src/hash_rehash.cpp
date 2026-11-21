// Scope: common
// The out-of-line Reserve of the hash tables of 0x71003b6ee0-0x710040f550
// (Unk_HashList.h, hash_list.h), one instance per item type: the items
// differ in where their key and their link are, and the tables in the pool
// they allocate from. Placeholder names.
#include "Unk_HashList.h"
#include "hash_list.h"

// The key and the link of an item with the members `key` and `next`.
struct Unk_HashMembers {
    template <class T>
    static u32 Key(T* item) {
        return item->key;
    }
    template <class T>
    static T*& Next(T* item) {
        return item->next;
    }
};

// Items with the key first and the link after it.
template <int Tag>
struct Unk_HashItem8 {
    u32 key;
    Unk_HashItem8* next;
};

// 0x7100404a20
template u32 Unk_HashListBare<Unk_HashItem8<0x404a20>, Unk_HashMembers>::Reserve(u32);

struct Unk_3ee4a0_Item {
    u32 key;
    u8 _4[0x14];
    Unk_3ee4a0_Item* next;
};
PKMN_OFFSET_ASSERT(Unk_3ee4a0_Item, next, 0x18);

// 0x71003ee4a0
template u32 Unk_PoolHashListBare<Unk_3ee4a0_Item, Unk_HashMembers, Unk_Pool2385820>::Reserve(u32);

template <int Tag>
struct Unk_HashItem40 {
    u8 _0[0x38];
    u32 key;
    Unk_HashItem40* next;
};

// 0x71003ee840
template u32
    Unk_PoolHashListBare<Unk_HashItem40<0x3ee840>, Unk_HashMembers, Unk_Pool2385820>::Reserve(u32);
// 0x71003eef50
template u32
    Unk_PoolHashListBare<Unk_HashItem40<0x3eef50>, Unk_HashMembers, Unk_Pool2385820>::Reserve(u32);
