// Scope: common
// Two trees of five levels of sorted arrays, each node with a value and the
// nodes of the next level by their key: the arrays' Set, Insert, GrowArray
// and Unset for every level, and the nodes' removal of a key. Placeholder
// names; the node classes are named after their vtables.
#include "Unk_36fa70.h"

#define UNK_36FA70_LEVEL(Name, Key)                                                               \
    template Name*                                                                                \
        Unk_SortedKeyArray<Key, Name, Unk_PoolDefault, 1, Unk_TransferMove<Name>>::Set(Key);      \
    template bool                                                                                 \
        Unk_SortedKeyArray<Key, Name, Unk_PoolDefault, 1, Unk_TransferMove<Name>>::Unset(Key);    \
    template Name*                                                                                \
    Unk_GrowArray<Name, Unk_PoolDefault, 1, const Name&, Unk_TransferMove<Name>>::Insert(u32);    \
    template bool                                                                                 \
    Unk_GrowArray<Name, Unk_PoolDefault, 1, const Name&, Unk_TransferMove<Name>>::GrowArray(u32)

// 0x710036fa70, 0x710036fbc0, 0x710036fd80, 0x71003719d0
UNK_36FA70_LEVEL(Unk_23817a8, u64);
// 0x710036ffc0, 0x71003701f0, 0x71003703b0, 0x7100371c60
UNK_36FA70_LEVEL(Unk_23817e8, u32);
// 0x71003705f0, 0x7100370740, 0x7100370900, 0x7100371f10
UNK_36FA70_LEVEL(Unk_2381828, u32);
// 0x7100370b40, 0x7100370c90, 0x7100370e50, 0x7100372350
UNK_36FA70_LEVEL(Unk_2381868, u8);
// 0x7100371090, 0x71003711e0, 0x7100371350, 0x71003724c0
UNK_36FA70_LEVEL(Unk_23818a8, u8);

// 0x71003a1830, 0x71003a1980, 0x71003a1b40, 0x710039fa20
UNK_36FA70_LEVEL(Unk_2382c60_Item, u64);
// 0x71003a1d70, 0x71003a1fb0, 0x71003a2170, 0x710039fe90
UNK_36FA70_LEVEL(Unk_2382ce0, u32);
// 0x71003a23a0, 0x71003a24f0, 0x71003a26b0, 0x71003a03a0
UNK_36FA70_LEVEL(Unk_2382d20, u32);
// 0x71003a28e0, 0x71003a2a30, 0x71003a2bf0, 0x71003a0b20
UNK_36FA70_LEVEL(Unk_2382d60, u8);
// 0x71003a2e20, 0x71003a2f70, 0x71003a30e0, 0x71003a0c90
UNK_36FA70_LEVEL(Unk_2382da0, u8);

// A node removes what a key says from the nodes below it, and the nodes that
// are left with nothing.
#define UNK_36FA70_REMOVE(Name, Below)                                                            \
    void Name::Remove(const Below& below) {                                                       \
        if (below.IsAny()) {                                                                      \
            if (this->field_10)                                                                   \
                this->field_10 = 0;                                                               \
            return;                                                                               \
        }                                                                                         \
        auto* child = this->field_18.Exists(below.field_0);                                       \
        if (child != nullptr) {                                                                   \
            child->Remove(below.field_8);                                                         \
            if (!child->field_10 && child->field_18.IsEmpty()) {                                  \
                child->RemoveAll();                                                               \
                this->field_18.Unset(below.field_0);                                              \
            }                                                                                     \
        }                                                                                         \
    }

// 0x7100371870
UNK_36FA70_REMOVE(Unk_23817a8, Unk_36fa70_Key1)
// 0x7100371b40
UNK_36FA70_REMOVE(Unk_23817e8, Unk_36fa70_Key2)
// 0x7100371dd0
UNK_36FA70_REMOVE(Unk_2381828, Unk_36fa70_Key3)
// 0x7100372080
UNK_36FA70_REMOVE(Unk_2381868, Unk_36fa70_Key4)

// 0x71003a0e00
UNK_36FA70_REMOVE(Unk_2382c60_Item, Unk_36fa70_Key1)
// 0x71003a0f60
UNK_36FA70_REMOVE(Unk_2382ce0, Unk_36fa70_Key2)
// 0x71003a1080
UNK_36FA70_REMOVE(Unk_2382d20, Unk_36fa70_Key3)
// 0x71003a11c0
UNK_36FA70_REMOVE(Unk_2382d60, Unk_36fa70_Key4)

// 0x710036b160 (and 0x710036e680, the RemoveAll of the first level)
UNK_36FA70_REMOVE(Unk_36b160_Root, Unk_36fa70_Key0)
// 0x710039f8e0
void Unk_39f8e0(Unk_2382c60_Item* self) {
    UNK_36FA70_REMOVEALL_BELOW(self)
}

// 0x710039a100
void Unk_39a100(Unk_2382c60* self, const Unk_3babc0_Key& key) {
    Unk_2382c60* root = self;
    const Unk_36fa70_Key0& below = reinterpret_cast<const Unk_36fa70_Key0&>(key);
    if (below.IsAny()) {
        if (root->field_10)
            root->field_10 = 0;
        return;
    }
    Unk_2382c60_Item* child = root->field_18.Exists(below.field_0);
    if (child != nullptr) {
        child->Remove(below.field_8);
        if (!child->field_10 && child->field_18.IsEmpty()) {
            child->RemoveAll();
            root->field_18.Unset(below.field_0);
        }
    }
}

// NON_MATCHING: 0x710036b090, 0x7100370110 and 0x710039c830. The original
// has the code that sets a node's value once for all the levels inlined in a
// function; here each level keeps its copy.

// 0x710036b090 (and 0x7100370110, the Set of the second level)
Unk_36fa70_Value* Unk_36b160_Root::Set(const Unk_36fa70_Key0& below) {
    if (below.IsAny())
        return this->SetValue();
    Unk_23817a8* child = this->field_18.Set(below.field_0);
    if (child == nullptr)
        return nullptr;
    return child->Set(below.field_8);
}

// 0x710039c830 (and 0x71003a1ec0)
u32* Unk_39c830(Unk_2382c60* self, const Unk_3babc0_Key& key) {
    Unk_2382c60* root = self;
    const Unk_36fa70_Key0& below = reinterpret_cast<const Unk_36fa70_Key0&>(key);
    if (below.IsAny())
        return root->SetValue();
    Unk_2382c60_Item* child = root->field_18.Set(below.field_0);
    if (child == nullptr)
        return nullptr;
    return child->Set(below.field_8);
}

// 0x7100371530
template Unk_23818a8_Item* Unk_SortedKeyArray<u64, Unk_23818a8_Item>::Set(u64);
// 0x71003a32c0
template Unk_2382da0_Item* Unk_SortedKeyArray<u64, Unk_2382da0_Item>::Set(u64);

// A node calls a function with every value below it and the keys that lead
// there, removes the values the function says to, and the nodes left with
// nothing; true when the node itself is left with nothing.
#define UNK_36FA70_FOREACH(Name, Value, Below)                                                    \
    bool Name::ForEach(Callback cb, const Unk_36fa70_Key0& a2, Below* below, void* a4) {          \
        if (this->field_10) {                                                                     \
            if (cb(&this->field_8, a2, a4)) {                                                     \
                if (this->field_10)                                                               \
                    this->field_10 = 0;                                                           \
            }                                                                                     \
        }                                                                                         \
        for (auto it = this->field_18.Begin(); it != this->field_18.End();) {                     \
            below->field_0 = (*it).key;                                                           \
            if ((*it).ForEach(cb, a2, &below->field_8, a4)) {                                     \
                (*it).RemoveAll();                                                                \
                it = this->field_18.Erase(it);                                                    \
            } else {                                                                              \
                ++it;                                                                             \
            }                                                                                     \
        }                                                                                         \
        return !this->field_10 && this->field_18.Length() == 0;                                   \
    }

// 0x710036e2a0
UNK_36FA70_FOREACH(Unk_36b160_Root, Unk_36fa70_Value, Unk_36fa70_Key0)
// 0x710036e480
UNK_36FA70_FOREACH(Unk_23817a8, Unk_36fa70_Value, Unk_36fa70_Key1)
// 0x710036e7c0
UNK_36FA70_FOREACH(Unk_23817e8, Unk_36fa70_Value, Unk_36fa70_Key2)
// 0x710036e9a0
UNK_36FA70_FOREACH(Unk_2381828, Unk_36fa70_Value, Unk_36fa70_Key3)
// 0x710036ecf0
UNK_36FA70_FOREACH(Unk_2381868, Unk_36fa70_Value, Unk_36fa70_Key4)

// A node removes everything a key says from the levels below, where a key
// that is any stands for every node of its level, and the nodes left with
// nothing.
#define UNK_36FA70_REMOVEALL(Name, Below)                                                         \
    void Name::RemoveAll(const Below& below) {                                                    \
        if (below.IsAny()) {                                                                      \
            if (this->field_10)                                                                   \
                this->field_10 = 0;                                                               \
            RemoveAll();                                                                          \
        } else if (below.IsAnyHere()) {                                                           \
            for (auto it = this->field_18.Begin(); it != this->field_18.End();) {                 \
                (*it).RemoveAll(below.field_8);                                                   \
                if (!(*it).field_10 && (*it).field_18.IsEmpty()) {                                \
                    (*it).RemoveAll();                                                            \
                    it = this->field_18.Erase(it);                                                \
                } else {                                                                          \
                    ++it;                                                                         \
                }                                                                                 \
            }                                                                                     \
        } else {                                                                                  \
            auto* child = this->field_18.Exists(below.field_0);                                   \
            if (child != nullptr) {                                                               \
                child->RemoveAll(below.field_8);                                                  \
                if (!child->field_10 && child->field_18.IsEmpty()) {                              \
                    child->RemoveAll();                                                           \
                    this->field_18.Unset(below.field_0);                                          \
                }                                                                                 \
            }                                                                                     \
        }                                                                                         \
    }

// 0x710039f690
UNK_36FA70_REMOVEALL(Unk_2382c60_Item, Unk_36fa70_Key1)
// 0x710039fb90
UNK_36FA70_REMOVEALL(Unk_2382ce0, Unk_36fa70_Key2)
// 0x71003a0000
UNK_36FA70_REMOVEALL(Unk_2382d20, Unk_36fa70_Key3)
// 0x710039a5b0
void Unk_39a100_Root::RemoveAll(const Unk_36fa70_Key0& below) {
    if (below.IsAny()) {
        if (this->field_10)
            this->field_10 = 0;
        RemoveAll();
    } else if (below.IsAnyHere()) {
        for (auto it = this->field_18.Begin(); it != this->field_18.End();) {
            (*it).RemoveAll(below.field_8);
            if (!(*it).field_10 && (*it).field_18.IsEmpty()) {
                (*it).RemoveAll();
                it = this->field_18.Erase(it);
            } else {
                ++it;
            }
        }
    } else {
        Unk_2382c60_Item* child = this->field_18.Exists(below.field_0);
        if (child != nullptr) {
            child->RemoveAll(below.field_8);
            if (!child->field_10 && child->field_18.IsEmpty()) {
                child->RemoveAll();
                this->field_18.Unset(below.field_0);
            }
        }
    }
}
// 0x71003a0510
// NON_MATCHING: the original reads the key of the last level again for every
// node of the loop; here the read before the loop is kept for the first one
// (GVN's load PRE), and the blocks after it are laid out differently.
UNK_36FA70_REMOVEALL(Unk_2382d60, Unk_36fa70_Key4)

// The same for the values a key says: a key that is any stands for every
// node of its level. `here` is whether the node's own value is one of them.
#define UNK_36FA70_FOREACH_KEY(Name, Below, HERE)                                                 \
    bool Name::ForEach(Callback cb, const Below& filter, const Unk_36fa70_Key0& a3, Below* below, \
                       void* a5, bool here) {                                                     \
        if (here && this->field_10) {                                                             \
            if (cb(&this->field_8, a3, a5)) {                                                     \
                if (this->field_10)                                                               \
                    this->field_10 = 0;                                                           \
            }                                                                                     \
        }                                                                                         \
        if (filter.IsAnyHere()) {                                                                 \
            for (auto it = this->field_18.Begin(); it != this->field_18.End();) {                 \
                below->field_0 = (*it).key;                                                       \
                if ((*it).ForEach(cb, filter.field_8, a3, &below->field_8, a5 HERE)) {            \
                    (*it).RemoveAll();                                                            \
                    it = this->field_18.Erase(it);                                                \
                } else {                                                                          \
                    ++it;                                                                         \
                }                                                                                 \
            }                                                                                     \
        } else {                                                                                  \
            auto* child = this->field_18.Exists(filter.field_0);                                  \
            if (child != nullptr) {                                                               \
                below->field_0 = filter.field_0;                                                  \
                if (child->ForEach(cb, filter.field_8, a3, &below->field_8, a5 HERE)) {           \
                    child->RemoveAll();                                                           \
                    this->field_18.Unset(filter.field_0);                                         \
                }                                                                                 \
            }                                                                                     \
        }                                                                                         \
        return !this->field_10 && this->field_18.IsEmpty();                                       \
    }

#define UNK_36FA70_HERE , true
#define UNK_36FA70_NOT_HERE

// 0x7100372630
UNK_36FA70_FOREACH_KEY(Unk_36b160_Root, Unk_36fa70_Key0, UNK_36FA70_HERE)
// 0x71003728f0
UNK_36FA70_FOREACH_KEY(Unk_23817a8, Unk_36fa70_Key1, UNK_36FA70_HERE)
// 0x7100372c60
UNK_36FA70_FOREACH_KEY(Unk_23817e8, Unk_36fa70_Key2, UNK_36FA70_HERE)
// 0x7100372f20
UNK_36FA70_FOREACH_KEY(Unk_2381828, Unk_36fa70_Key3, UNK_36FA70_HERE)
// 0x71003732d0
UNK_36FA70_FOREACH_KEY(Unk_2381868, Unk_36fa70_Key4, UNK_36FA70_NOT_HERE)

// 0x71003735c0
bool Unk_23818a8::ForEach(Callback cb, const Unk_36fa70_Key5& filter, const Unk_36fa70_Key0& a3,
                          Unk_36fa70_Key5* below, void* a5) {
    if (this->field_10) {
        if (cb(&this->field_8, a3, a5)) {
            if (this->field_10)
                this->field_10 = 0;
        }
    }
    if (!filter.IsAnyHere()) {
        Unk_23818a8_Item* item = this->field_18.Exists(filter.field_0);
        if (item != nullptr) {
            below->field_0 = filter.field_0;
            if (cb(&item->field_0, a3, a5))
                this->field_18.Unset(filter.field_0);
        }
    } else {
        for (auto it = this->field_18.Begin(); it != this->field_18.End();) {
            below->field_0 = (*it).key;
            if (cb(&(*it).field_0, a3, a5))
                it = this->field_18.Erase(it);
            else
                ++it;
        }
        if (this->field_18.IsEmpty())
            this->field_18.Term();
    }
    return !this->field_10 && this->field_18.IsEmpty();
}

// A node calls a function with the values a key says, removing nothing.
// 0x710036f050 (and 0x710036f3d0 and 0x710036f750, two levels each)
void Unk_36b160_Root::Visit(Visitor cb, const Unk_36fa70_Key0& filter, const Unk_36fa70_Key0& a3,
                            Unk_36fa70_Key0* below, void* a5, bool here) {
    if (here && this->field_10)
        cb(&this->field_8, a3, a5);
    if (filter.IsAnyHere()) {
        for (auto it = this->field_18.Begin(); it != this->field_18.End(); ++it) {
            below->field_0 = (*it).key;
            (*it).Visit(cb, filter.field_8, a3, &below->field_8, a5, true);
        }
    } else {
        Unk_23817a8* child = this->field_18.Exists(filter.field_0);
        if (child != nullptr) {
            below->field_0 = filter.field_0;
            child->Visit(cb, filter.field_8, a3, &below->field_8, a5, true);
        }
    }
}

// Whether the second tree has something for a key, where a node whose key is
// any stands in for one that is missing.
// 0x71003a3690 (and 0x71003a37e0 and 0x71003a3930, the first and second
// level; the third is inlined in the second)
// NON_MATCHING: 0x71003a3bb0, the fourth level with the last one inlined.
// The original compares the node found with null before it combines the
// two tests of the key; here the two are combined first (three instructions
// in another order).
bool Unk_39a100_Root::Has(const Unk_36fa70_Key0& key, const Unk_36fa70_Key0& orig) {
    if (orig.IsAnyHere())
        return false;
    Unk_2382c60_Item* child = this->field_18.Exists(orig.field_0);
    if (child == nullptr)
        child = this->field_18.Exists(Unk_36fa70_Key0::Any());
    bool all = key.IsAny();
    bool result = child != nullptr && all;
    if (child != nullptr && !all)
        result = child->Has(key.field_8, orig.field_8);
    return result;
}

struct Unk_2382de0 {
    virtual bool vf0(const Unk_36fa70_Key0& other);

    const Unk_36fa70_Key0* field_8;
    Unk_39a100_Root* field_10;
};

// 0x71003a3600
bool Unk_2382de0::vf0(const Unk_36fa70_Key0& other) {
    Unk_39a100_Root* root = field_10;
    const Unk_36fa70_Key0* key = field_8;
    if (key->IsWider(other))
        return root->Has(*key, other);
    return false;
}

// The same for the first tree.
// 0x710036dbe0 (and 0x710036dd30 and 0x710036de80)
// NON_MATCHING: 0x710036e100, like 0x71003a3bb0.
bool Unk_36b160_Root::Has(const Unk_36fa70_Key0& key, const Unk_36fa70_Key0& orig) {
    if (orig.IsAnyHere())
        return false;
    Unk_23817a8* child = this->field_18.Exists(orig.field_0);
    if (child == nullptr)
        child = this->field_18.Exists(Unk_36fa70_Key0::Any());
    bool all = key.IsAny();
    bool result = child != nullptr && all;
    if (child != nullptr && !all)
        result = child->Has(key.field_8, orig.field_8);
    return result;
}

struct Unk_2381770 {
    Unk_2381770(const Unk_36fa70_Key0* key, Unk_36b160_Root* root) : field_8(key), field_10(root) {}

    virtual bool vf0(const Unk_36fa70_Key0& other);

    const Unk_36fa70_Key0* field_8;
    Unk_36b160_Root* field_10;
};

// 0x710036db50
bool Unk_2381770::vf0(const Unk_36fa70_Key0& other) {
    Unk_36b160_Root* root = field_10;
    const Unk_36fa70_Key0* key = field_8;
    if (key->IsWider(other))
        return root->Has(*key, other);
    return false;
}

// The value a key has in the tree, or null. `closest` gets the value of the
// last node on the way that has one, `hasMore` whether the node the key ends
// at has nodes below it.
// 0x710039f0a0 (and 0x710039f1a0 and 0x710039f480, the first and the fourth
// level, the fourth with the last one inlined)
// NON_MATCHING: 0x710039f290, the second level with the third inlined: one
// branch goes to the other of two returns (the block layout shares the
// return of the null check with another block's).
Unk_3a1830_Value* Unk_39a100_Root::Find(const Unk_36fa70_Key0& below, Unk_3a1830_Value** closest,
                                        bool* hasMore) {
    if (below.IsAny()) {
        if (hasMore != nullptr)
            *hasMore = !this->field_18.IsEmpty();
        if (this->field_10)
            return &this->field_8;
        return nullptr;
    }
    if (closest != nullptr && this->field_10)
        *closest = &this->field_8;
    Unk_2382c60_Item* child = this->field_18.Exists(below.field_0);
    if (child != nullptr)
        return child->Find(below.field_8, closest, hasMore);
    return nullptr;
}

// The same for the first tree: only its owner looks a key up, and has the
// root's and the first level's lookup inlined.
inline Unk_36fa70_Value* Unk_36b160_Root::Find(const Unk_36fa70_Key0& below,
                                               Unk_36fa70_Value** closest, bool* hasMore) {
    if (below.IsAny()) {
        if (hasMore != nullptr)
            *hasMore = !this->field_18.IsEmpty();
        if (this->field_10)
            return &this->field_8;
        return nullptr;
    }
    if (closest != nullptr && this->field_10)
        *closest = &this->field_8;
    Unk_23817a8* child = this->field_18.Exists(below.field_0);
    if (child != nullptr)
        return child->Find(below.field_8, closest, hasMore);
    return nullptr;
}

// 0x710036b350 (and 0x710036d980, the fourth level with the last inlined)
// NON_MATCHING: 0x710036d790, like 0x710039f290.
void* Unk_36b350(Unk_36b350_T* self, const Unk_36fa70_Key0& key) {
    Unk_36fa70_Value* value = self->field_38.Find(key, nullptr, nullptr);
    return value != nullptr ? value->field_0 : nullptr;
}

// 0x710036a620
void Unk_36a620(Unk_36fa70_Value* value, const Unk_36fa70_Key0&, void* arg) {
    Unk_36a620_Arg* a = static_cast<Unk_36a620_Arg*>(arg);
    static_cast<Unk_373fd0*>(value->field_0)->vf2(a->field_0, a->field_4);
}

// 0x710036a640
bool Unk_36a640(Unk_36fa70_Value* value, const Unk_36fa70_Key0&, void*) {
    Unk_373fd0* object = static_cast<Unk_373fd0*>(value->field_0);
    object->field_68 = 3;
    object->Release();
    return true;
}

// What the owner's array holds.
struct Unk_36a6b0_Item {
    struct Inner {
        void* field_0;
        struct {
            u8 _0[0x18];
            u32 field_18;
        }* field_8;
    };

    bool IsActive() const {
        if (field_48 == 1)
            return true;
        if (field_8 == 0 || field_8 == 7)
            return false;
        if (field_48 == 2)
            return field_0->field_8 != nullptr && field_0->field_8->field_18 != 0;
        return true;
    }

    Inner* field_0;
    u32 field_8;
    u8 _c[0x3c];
    u32 field_48;
};

void Unk_39c9e0(Unk_36a6b0_Item* item, u32 a1, f32 a2, const Unk_36fa70_Key0& key, void* test,
                void* a5, f32 a6);

// 0x710036a6b0
bool Unk_36a6b0(Unk_36fa70_Value* value, const Unk_36fa70_Key0& key, void* arg) {
    Unk_36b350_T* owner = static_cast<Unk_36b350_T*>(arg);
    Unk_373fd0* object = static_cast<Unk_373fd0*>(value->field_0);
    Unk_2381770 test(&key, &owner->field_38);
    for (auto it = owner->field_60.Begin(), end = owner->field_60.End(); it != end; ++it) {
        Unk_36a6b0_Item* item = *it;
        if (item->IsActive()) {
            f32 a6 = object->field_50 != nullptr ? object->field_50->field_c : object->field_70;
            Unk_39c9e0(item, owner->field_10, object->field_70, object->Key(), &test, nullptr, a6);
        }
    }
    if (Unk_373fd0_get(object)) {
        object->Release();
        return true;
    }
    return false;
}

// 0x710036b2a0
u32 Unk_36b2a0(Unk_36b350_T* self, const Unk_36fa70_Key0& filter) {
    Unk_36fa70_Key0 key;
    self->field_38.ForEach(Unk_36a640, filter, key, &key, nullptr, filter.IsAny());
    return 1;
}

// 0x710036b920
void Unk_36b920(Unk_36b350_T* self) {
    Unk_36fa70_Key0 key;
    self->field_38.ForEach(Unk_36a6b0, key, &key, self);
}

// The value that fits a key best in the second tree: where the tree has no
// node for a part of the key, the node for any is taken, and the key is
// changed to what was found.
u32* Unk_3657c0(Unk_2382c60* self, const Unk_3babc0_Key* key);

// 0x71003657c0 (and 0x7100365920, 0x7100365a70, 0x7100365bb0 and 0x7100365d00)
u32* Unk_3657c0(Unk_2382c60* self, const Unk_3babc0_Key* key) {
    Unk_2382c60* root = self;
    Unk_36fa70_Key0* below = reinterpret_cast<Unk_36fa70_Key0*>(const_cast<Unk_3babc0_Key*>(key));
    if (!below->IsAny()) {
        Unk_2382c60_Item* child = root->field_18.Exists(below->field_0);
        if (child == nullptr && !below->IsAnyHere()) {
            below->field_0 = Unk_36fa70_Key0::Any();
            child = root->field_18.Exists(Unk_36fa70_Key0::Any());
        }
        if (child != nullptr) {
            u32* value = child->FindBest(&below->field_8);
            if (value != nullptr)
                return value;
        }
    }
    below->field_8 = Unk_36fa70_Key1();
    return root->field_10 ? &root->field_8 : nullptr;
}
