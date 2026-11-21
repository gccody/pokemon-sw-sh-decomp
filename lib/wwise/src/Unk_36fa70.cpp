// Scope: common
// A tree of five levels of sorted arrays, each node with a value and the
// nodes of the next level by their key: the arrays' Set, Insert and
// GrowArray for every level. Placeholder names; the node classes are named
// after their vtables.
#include "Unk_SortedArray.h"

// The value of a node.
struct Unk_36fa70_Value {
    Unk_36fa70_Value() : field_0(0) {}

    u64 field_0;
};

// A node: `Key` is the type of its key, `Child` what its array holds. The
// value and the array are a base class's (`Base`, with a vtable of its own).
#define UNK_36FA70_NODE(Name, Base, Key, Child)                                                   \
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
        Unk_36fa70_Value field_8;                                                                 \
        u8 field_10;                                                                              \
        Child field_18;                                                                           \
    };                                                                                            \
    struct Name : Base {                                                                          \
        ~Name() override;                                                                         \
                                                                                                  \
        void Transfer(Name& other) {                                                              \
            key = other.key;                                                                      \
            Base::Transfer(other);                                                                \
        }                                                                                         \
                                                                                                  \
        Key key;                                                                                  \
    };                                                                                            \
    PKMN_SIZE_ASSERT(Name, 0x30);                                                                 \
    typedef Unk_SortedKeyArray<Key, Name, Unk_PoolDefault, 1, Unk_TransferMove<Name>> Name##_Array

// What the last level holds.
struct Unk_23818a8_Item {
    u64 field_0;
    u64 field_8;
};

UNK_36FA70_NODE(Unk_23818a8, Unk_23818c8, u8, Unk_GrowArray<Unk_23818a8_Item>);
UNK_36FA70_NODE(Unk_2381868, Unk_2381888, u8, Unk_23818a8_Array);
UNK_36FA70_NODE(Unk_2381828, Unk_2381848, u32, Unk_2381868_Array);
UNK_36FA70_NODE(Unk_23817e8, Unk_2381808, u32, Unk_2381828_Array);
UNK_36FA70_NODE(Unk_23817a8, Unk_23817c8, u64, Unk_23817e8_Array);

#define UNK_36FA70_LEVEL(Name, Key)                                                               \
    template Name*                                                                                \
        Unk_SortedKeyArray<Key, Name, Unk_PoolDefault, 1, Unk_TransferMove<Name>>::Set(Key);      \
    template Name*                                                                                \
    Unk_GrowArray<Name, Unk_PoolDefault, 1, const Name&, Unk_TransferMove<Name>>::Insert(u32);    \
    template bool                                                                                 \
    Unk_GrowArray<Name, Unk_PoolDefault, 1, const Name&, Unk_TransferMove<Name>>::GrowArray(u32)

// NON_MATCHING: the five GrowArray (0x710036fd80, 0x71003703b0, 0x7100370900,
// 0x7100370e50, 0x7100371350). In their loop the original keeps the address
// of the new item's field_10 across the constructor's null check and takes
// field_8's from the item; here both addresses are kept.

// 0x710036fa70, 0x710036fbc0, 0x710036fd80
UNK_36FA70_LEVEL(Unk_23817a8, u64);
// 0x710036ffc0, 0x71003701f0, 0x71003703b0
UNK_36FA70_LEVEL(Unk_23817e8, u32);
// 0x71003705f0, 0x7100370740, 0x7100370900
UNK_36FA70_LEVEL(Unk_2381828, u32);
// 0x7100370b40, 0x7100370c90, 0x7100370e50
UNK_36FA70_LEVEL(Unk_2381868, u8);
// 0x7100371090, 0x71003711e0, 0x7100371350
UNK_36FA70_LEVEL(Unk_23818a8, u8);
