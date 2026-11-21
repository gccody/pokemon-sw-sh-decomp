// Scope: common
// Two trees of five levels of sorted arrays, each node with a value and the
// nodes of the next level by their key: the arrays' Set, Insert, GrowArray
// and Unset for every level, and the nodes' removal of a key. Placeholder
// names; the node classes are named after their vtables.
#include "Unk_SortedArray.h"

// The values of the nodes of the two trees.
struct Unk_36fa70_Value {
    Unk_36fa70_Value() : field_0(nullptr) {}

    void* field_0;
};

typedef u32 Unk_3a1830_Value;

// What a node is given to find something below it: the keys of the levels
// below, and what the last level holds. 0 or 0xff in a key is any.
struct Unk_36fa70_Key5 {
    u64 field_0;

    bool IsAny() const { return field_0 == 0; }
};

struct Unk_36fa70_Key4 {
    u8 field_0;
    Unk_36fa70_Key5 field_8;

    bool IsAny() const { return field_0 == 0xff && field_8.IsAny(); }
};

struct Unk_36fa70_Key3 {
    u8 field_0;
    Unk_36fa70_Key4 field_8;

    bool IsAny() const { return field_0 == 0xff && field_8.IsAny(); }
};

struct Unk_36fa70_Key2 {
    u32 field_0;
    Unk_36fa70_Key3 field_8;

    bool IsAny() const { return field_0 == 0 && field_8.IsAny(); }
};

struct Unk_36fa70_Key1 {
    u32 field_0;
    Unk_36fa70_Key2 field_8;

    bool IsAny() const { return field_0 == 0 && field_8.IsAny(); }
};
PKMN_SIZE_ASSERT(Unk_36fa70_Key1, 0x28);

struct Unk_36fa70_Key0 {
    u64 field_0;
    Unk_36fa70_Key1 field_8;

    bool IsAny() const { return field_0 == 0 && field_8.IsAny(); }
};
PKMN_SIZE_ASSERT(Unk_36fa70_Key0, 0x30);

// A node: `Key` is the type of its key, `Child` what its array holds. The
// value and the array are a base class's (`Base`, with a vtable of its own).
#define UNK_36FA70_BASE(Base, Value, Child)                                                       \
    struct Base {                                                                                 \
        Base() : field_8(), field_10(0), field_18() {}                                            \
        virtual ~Base();                                                                          \
                                                                                                  \
        void Transfer(Base& other) {                                                              \
            field_8 = other.field_8;                                                              \
            field_10 = other.field_10;                                                            \
            field_18.Transfer(other.field_18);                                                    \
        }                                                                                         \
                                                                                                  \
        Value* SetValue() {                                                                       \
            if (!field_10) {                                                                      \
                Unk_PlacementNew(&field_8) Value();                                               \
                field_10 = 1;                                                                     \
            }                                                                                     \
            return &field_8;                                                                      \
        }                                                                                         \
                                                                                                  \
        Value field_8;                                                                            \
        u8 field_10;                                                                              \
        Child field_18;                                                                           \
    }

// A node of the levels that have nodes below: `Below` is what Remove takes.
#define UNK_36FA70_NODE(Name, Base, Value, Key, Child, Below, Size)                               \
    UNK_36FA70_BASE(Base, Value, Child);                                                          \
    struct Name : Base {                                                                          \
        ~Name() override;                                                                         \
                                                                                                  \
        void Transfer(Name& other) {                                                              \
            key = other.key;                                                                      \
            Base::Transfer(other);                                                                \
        }                                                                                         \
                                                                                                  \
        void RemoveAll() {                                                                        \
            for (auto it = this->field_18.Begin(), end = this->field_18.End(); it != end; ++it)   \
                (*it).RemoveAll();                                                                \
            this->field_18.Term();                                                                \
        }                                                                                         \
                                                                                                  \
        void Remove(const Below& below);                                                          \
                                                                                                  \
        Value* Set(const Below& below) {                                                          \
            if (below.IsAny())                                                                    \
                return this->SetValue();                                                          \
            auto* child = this->field_18.Set(below.field_0);                                      \
            if (child == nullptr)                                                                 \
                return nullptr;                                                                   \
            return child->Set(below.field_8);                                                     \
        }                                                                                         \
                                                                                                  \
        Key key;                                                                                  \
    };                                                                                            \
    PKMN_SIZE_ASSERT(Name, Size);                                                                 \
    typedef Unk_SortedKeyArray<Key, Name, Unk_PoolDefault, 1, Unk_TransferMove<Name>> Name##_Array

// What a last level holds, sorted too, and its array, which has a
// constructor of its own.
#define UNK_36FA70_ITEMS(Name, Value)                                                             \
    struct Name##_Item {                                                                          \
        Name##_Item() : field_0() {}                                                              \
                                                                                                  \
        Value field_0;                                                                            \
        u64 key;                                                                                  \
    };                                                                                            \
    struct Name##_Items : Unk_SortedKeyArray<u64, Name##_Item> {                                  \
        Name##_Items() {                                                                          \
            field_0 = nullptr;                                                                    \
            field_8 = 0;                                                                          \
            field_c = 0;                                                                          \
        }                                                                                         \
    }

// A node of the last level.
#define UNK_36FA70_LAST(Name, Base, Value, Key, Size)                                             \
    UNK_36FA70_ITEMS(Name, Value);                                                                \
    UNK_36FA70_BASE(Base, Value, Name##_Items);                                                   \
    struct Name : Base {                                                                          \
        ~Name() override;                                                                         \
                                                                                                  \
        void Transfer(Name& other) {                                                              \
            key = other.key;                                                                      \
            Base::Transfer(other);                                                                \
        }                                                                                         \
                                                                                                  \
        void RemoveAll() { this->field_18.Term(); }                                               \
                                                                                                  \
        void Remove(const Unk_36fa70_Key5& below) {                                               \
            if (below.IsAny()) {                                                                  \
                if (this->field_10)                                                               \
                    this->field_10 = 0;                                                           \
                return;                                                                           \
            }                                                                                     \
            this->field_18.Unset(below.field_0);                                                  \
            if (this->field_18.IsEmpty())                                                         \
                this->field_18.Term();                                                            \
        }                                                                                         \
                                                                                                  \
        Value* Set(const Unk_36fa70_Key5& below) {                                                \
            if (below.IsAny())                                                                    \
                return this->SetValue();                                                          \
            Name##_Item* item = this->field_18.Set(below.field_0);                                \
            return item != nullptr ? &item->field_0 : nullptr;                                    \
        }                                                                                         \
                                                                                                  \
        Key key;                                                                                  \
    };                                                                                            \
    PKMN_SIZE_ASSERT(Name, Size);                                                                 \
    typedef Unk_SortedKeyArray<Key, Name, Unk_PoolDefault, 1, Unk_TransferMove<Name>> Name##_Array

// The root of a tree: a node without a key.
#define UNK_36FA70_ROOT(Name, Value, Child)                                                       \
    UNK_36FA70_BASE(Name##_Base, Value, Child);                                                   \
    struct Name : Name##_Base {                                                                   \
        void Remove(const Unk_36fa70_Key0& below);                                                \
        Value* Set(const Unk_36fa70_Key0& below);                                                 \
    }

// The tree of 0x710036fa70 (nodes of 0x30 bytes).
UNK_36FA70_LAST(Unk_23818a8, Unk_23818c8, Unk_36fa70_Value, u8, 0x30);
UNK_36FA70_NODE(Unk_2381868, Unk_2381888, Unk_36fa70_Value, u8, Unk_23818a8_Array,
                Unk_36fa70_Key4, 0x30);
UNK_36FA70_NODE(Unk_2381828, Unk_2381848, Unk_36fa70_Value, u32, Unk_2381868_Array,
                Unk_36fa70_Key3, 0x30);
UNK_36FA70_NODE(Unk_23817e8, Unk_2381808, Unk_36fa70_Value, u32, Unk_2381828_Array,
                Unk_36fa70_Key2, 0x30);
UNK_36FA70_NODE(Unk_23817a8, Unk_23817c8, Unk_36fa70_Value, u64, Unk_23817e8_Array,
                Unk_36fa70_Key1, 0x30);
UNK_36FA70_ROOT(Unk_36b160_Root, Unk_36fa70_Value, Unk_23817a8_Array);

// The tree of 0x71003a1830 (nodes of 0x28 bytes).
UNK_36FA70_LAST(Unk_2382da0, Unk_2382dc0, Unk_3a1830_Value, u8, 0x28);
UNK_36FA70_NODE(Unk_2382d60, Unk_2382d80, Unk_3a1830_Value, u8, Unk_2382da0_Array,
                Unk_36fa70_Key4, 0x28);
UNK_36FA70_NODE(Unk_2382d20, Unk_2382d40, Unk_3a1830_Value, u32, Unk_2382d60_Array,
                Unk_36fa70_Key3, 0x28);
UNK_36FA70_NODE(Unk_2382ce0, Unk_2382d00, Unk_3a1830_Value, u32, Unk_2382d20_Array,
                Unk_36fa70_Key2, 0x28);
UNK_36FA70_NODE(Unk_2382ca0, Unk_2382cc0, Unk_3a1830_Value, u64, Unk_2382ce0_Array,
                Unk_36fa70_Key1, 0x28);
UNK_36FA70_ROOT(Unk_39a100_Root, Unk_3a1830_Value, Unk_2382ca0_Array);

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
UNK_36FA70_LEVEL(Unk_2382ca0, u64);
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
UNK_36FA70_REMOVE(Unk_2382ca0, Unk_36fa70_Key1)
// 0x71003a0f60
UNK_36FA70_REMOVE(Unk_2382ce0, Unk_36fa70_Key2)
// 0x71003a1080
UNK_36FA70_REMOVE(Unk_2382d20, Unk_36fa70_Key3)
// 0x71003a11c0
UNK_36FA70_REMOVE(Unk_2382d60, Unk_36fa70_Key4)

// 0x710036b160 (and 0x710036e680, the RemoveAll of the first level)
UNK_36FA70_REMOVE(Unk_36b160_Root, Unk_36fa70_Key0)
// 0x710039a100 (and 0x710039f8e0)
UNK_36FA70_REMOVE(Unk_39a100_Root, Unk_36fa70_Key0)

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
Unk_3a1830_Value* Unk_39a100_Root::Set(const Unk_36fa70_Key0& below) {
    if (below.IsAny())
        return this->SetValue();
    Unk_2382ca0* child = this->field_18.Set(below.field_0);
    if (child == nullptr)
        return nullptr;
    return child->Set(below.field_8);
}

// 0x7100371530
template Unk_23818a8_Item* Unk_SortedKeyArray<u64, Unk_23818a8_Item>::Set(u64);
// 0x71003a32c0
template Unk_2382da0_Item* Unk_SortedKeyArray<u64, Unk_2382da0_Item>::Set(u64);
