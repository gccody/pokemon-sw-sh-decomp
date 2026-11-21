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

    Unk_36fa70_Key5() : field_0(0) {}
    explicit Unk_36fa70_Key5(u64 a) : field_0(a) {}

    static u64 Any() { return 0; }
    bool IsAnyHere() const { return field_0 == 0; }
    bool IsAny() const { return field_0 == 0; }
    // Whether a key is any where the other one isn't (both by value).
    static bool IsWider(Unk_36fa70_Key5 other, Unk_36fa70_Key5 key) {
        return other.field_0 != 0 && key.field_0 == 0;
    }
};

struct Unk_36fa70_Key4 {
    u8 field_0;
    Unk_36fa70_Key5 field_8;

    Unk_36fa70_Key4() : field_0(0xff), field_8() {}
    Unk_36fa70_Key4(u8 a, u64 b) : field_0(a), field_8(b) {}

    static u8 Any() { return 0xff; }
    bool IsAnyHere() const { return field_0 == 0xff; }
    bool IsAny() const { return field_0 == 0xff && field_8.IsAny(); }
    bool IsWider(const Unk_36fa70_Key4& other) const {
        return Unk_36fa70_Key5::IsWider(other.field_8, field_8) ||
               (other.field_0 != 0xff && field_0 == 0xff);
    }
};

struct Unk_36fa70_Key3 {
    u8 field_0;
    Unk_36fa70_Key4 field_8;

    Unk_36fa70_Key3() : field_0(0xff), field_8() {}
    Unk_36fa70_Key3(u8 a, u8 b, u64 c) : field_0(a), field_8(b, c) {}

    static u8 Any() { return 0xff; }
    bool IsAnyHere() const { return field_0 == 0xff; }
    bool IsAny() const { return field_0 == 0xff && field_8.IsAny(); }
    bool IsWider(const Unk_36fa70_Key3& other) const {
        return field_8.IsWider(other.field_8) || (other.field_0 != 0xff && field_0 == 0xff);
    }
};

struct Unk_36fa70_Key2 {
    u32 field_0;
    Unk_36fa70_Key3 field_8;

    Unk_36fa70_Key2() : field_0(0), field_8() {}
    Unk_36fa70_Key2(u32 a, u8 b, u8 c, u64 d) : field_0(a), field_8(b, c, d) {}

    static u32 Any() { return 0; }
    bool IsAnyHere() const { return field_0 == 0; }
    bool IsAny() const { return field_0 == 0 && field_8.IsAny(); }
    bool IsWider(const Unk_36fa70_Key2& other) const {
        return field_8.IsWider(other.field_8) || (other.field_0 != 0 && field_0 == 0);
    }
};

struct Unk_36fa70_Key1 {
    u32 field_0;
    Unk_36fa70_Key2 field_8;

    Unk_36fa70_Key1() : field_0(0), field_8() {}
    Unk_36fa70_Key1(u32 a, u32 b, u8 c, u8 d, u64 e) : field_0(a), field_8(b, c, d, e) {}

    static u32 Any() { return 0; }
    bool IsAnyHere() const { return field_0 == 0; }
    bool IsAny() const { return field_0 == 0 && field_8.IsAny(); }
    bool IsWider(const Unk_36fa70_Key1& other) const {
        return field_8.IsWider(other.field_8) || (other.field_0 != 0 && field_0 == 0);
    }
};
PKMN_SIZE_ASSERT(Unk_36fa70_Key1, 0x28);

struct Unk_36fa70_Key0 {
    u64 field_0;
    Unk_36fa70_Key1 field_8;

    Unk_36fa70_Key0() : field_0(0), field_8() {}
    Unk_36fa70_Key0(u64 a, u32 b, u32 c, u8 d, u8 e, u64 f)
        : field_0(a), field_8(b, c, d, e, f) {}

    static u64 Any() { return 0; }
    bool IsAnyHere() const { return field_0 == 0; }
    bool IsAny() const { return field_0 == 0 && field_8.IsAny(); }
    bool IsWider(const Unk_36fa70_Key0& other) const {
        return field_8.IsWider(other.field_8) || (other.field_0 != 0 && field_0 == 0);
    }
};
PKMN_SIZE_ASSERT(Unk_36fa70_Key0, 0x30);

// A node: `Key` is the type of its key, `Child` what its array holds. The
// value and the array are a base class's (`Base`, with a vtable of its own).
#define UNK_36FA70_BASE(Base, Value, Child)                                                       \
    struct Base {                                                                                 \
        typedef bool (*Callback)(Value*, const Unk_36fa70_Key0&, void*);                          \
        typedef void (*Visitor)(Value*, const Unk_36fa70_Key0&, void*);                           \
                                                                                                  \
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

// What a node's RemoveAll does: the same for the nodes below, then its array.
#define UNK_36FA70_REMOVEALL_BELOW(self)                                                          \
    for (auto it = (self)->field_18.Begin(), end = (self)->field_18.End(); it != end; ++it)       \
        (*it).RemoveAll();                                                                        \
    (self)->field_18.Term();

// The second tree's first level: its RemoveAll (0x710039f8e0) has the name
// that Unk_3babc0.h, which calls it, gave it. (That header can't be included
// here: its sorted_array.h has another Unk_SortedKeyArray.) The same for the
// root's Remove (0x710039a100) and Set (0x710039c830).
struct Unk_2382c60_Item;
struct Unk_2382c60;
struct Unk_3babc0_Key;
void Unk_39f8e0(Unk_2382c60_Item* self);
void Unk_39a100(Unk_2382c60* self, const Unk_3babc0_Key& key);
u32* Unk_39c830(Unk_2382c60* self, const Unk_3babc0_Key& key);
#define UNK_36FA70_REMOVEALL_39F8E0(self) Unk_39f8e0(reinterpret_cast<Unk_2382c60_Item*>(self));

// A node of the levels that have nodes below: `Below` is what Remove takes,
// `REMOVEALL` one of the two above.
#define UNK_36FA70_NODE(Name, Base, Value, Key, Child, Below, Size, REMOVEALL)                    \
    UNK_36FA70_BASE(Base, Value, Child);                                                          \
    struct Name : Base {                                                                          \
        ~Name() override;                                                                         \
                                                                                                  \
        void Transfer(Name& other) {                                                              \
            key = other.key;                                                                      \
            Base::Transfer(other);                                                                \
        }                                                                                         \
                                                                                                  \
        void RemoveAll() { REMOVEALL(this) }                                                      \
                                                                                                  \
        void Remove(const Below& below);                                                          \
        void RemoveAll(const Below& below);                                                       \
                                                                                                  \
        Value* Find(const Below& below, Value** closest, bool* hasMore) {                         \
            if (!below.IsAny()) {                                                                 \
                if (closest != nullptr && this->field_10)                                         \
                    *closest = &this->field_8;                                                    \
                auto* child = this->field_18.Exists(below.field_0);                               \
                if (child != nullptr)                                                             \
                    return child->Find(below.field_8, closest, hasMore);                          \
                return nullptr;                                                                   \
            }                                                                                     \
            if (hasMore != nullptr)                                                               \
                *hasMore = !this->field_18.IsEmpty();                                             \
            if (this->field_10)                                                                   \
                return &this->field_8;                                                            \
            return nullptr;                                                                       \
        }                                                                                         \
                                                                                                  \
        bool Has(const Below& key, const Below& orig) {                                           \
            if (orig.IsAnyHere())                                                                 \
                return false;                                                                     \
            auto* child = this->field_18.Exists(orig.field_0);                                    \
            if (child == nullptr)                                                                 \
                child = this->field_18.Exists(Below::Any());                                      \
            bool all = key.IsAny();                                                               \
            bool result = child != nullptr && all;                                                \
            if (child != nullptr && !all)                                                         \
                result = child->Has(key.field_8, orig.field_8);                                   \
            return result;                                                                        \
        }                                                                                         \
                                                                                                  \
        bool ForEach(typename Base::Callback cb, const Unk_36fa70_Key0& a2, Below* below, void* a4); \
        bool ForEach(typename Base::Callback cb, const Below& filter, const Unk_36fa70_Key0& a3,  \
                     Below* below, void* a5, bool here);                                          \
                                                                                                  \
        inline void Visit(typename Base::Visitor cb, const Below& filter,                         \
                          const Unk_36fa70_Key0& a3, Below* below, void* a5, bool here) {         \
            if (here && this->field_10)                                                           \
                cb(&this->field_8, a3, a5);                                                       \
            if (filter.IsAnyHere()) {                                                             \
                for (auto it = this->field_18.Begin(); it != this->field_18.End(); ++it) {        \
                    below->field_0 = (*it).key;                                                   \
                    (*it).Visit(cb, filter.field_8, a3, &below->field_8, a5, true);               \
                }                                                                                 \
            } else {                                                                              \
                auto* child = this->field_18.Exists(filter.field_0);                              \
                if (child != nullptr) {                                                           \
                    below->field_0 = filter.field_0;                                              \
                    child->Visit(cb, filter.field_8, a3, &below->field_8, a5, true);              \
                }                                                                                 \
            }                                                                                     \
        }                                                                                         \
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
        Value* Find(const Unk_36fa70_Key5& below, Value** closest, bool* hasMore) {               \
            if (below.IsAny()) {                                                                  \
                if (hasMore != nullptr)                                                           \
                    *hasMore = !this->field_18.IsEmpty();                                         \
                if (this->field_10)                                                               \
                    return &this->field_8;                                                        \
                return nullptr;                                                                   \
            }                                                                                     \
            if (closest != nullptr && this->field_10)                                             \
                *closest = &this->field_8;                                                        \
            if (hasMore != nullptr)                                                               \
                *hasMore = false;                                                                 \
            Name##_Item* item = this->field_18.Exists(below.field_0);                             \
            return item != nullptr ? &item->field_0 : nullptr;                                    \
        }                                                                                         \
                                                                                                  \
        bool Has(const Unk_36fa70_Key5& key, const Unk_36fa70_Key5& orig) {                       \
            if (!key.IsAny())                                                                     \
                return false;                                                                     \
            if (orig.IsAnyHere())                                                                 \
                return false;                                                                     \
            return this->field_18.Exists(orig.field_0) != nullptr;                                \
        }                                                                                         \
                                                                                                  \
        void RemoveAll(const Unk_36fa70_Key5& below) {                                            \
            if (below.IsAny()) {                                                                  \
                if (this->field_10)                                                               \
                    this->field_10 = 0;                                                           \
                RemoveAll();                                                                      \
            } else {                                                                              \
                this->field_18.Unset(below.field_0);                                              \
            }                                                                                     \
        }                                                                                         \
                                                                                                  \
        bool ForEach(typename Base::Callback cb, const Unk_36fa70_Key5& filter,                   \
                     const Unk_36fa70_Key0& a3, Unk_36fa70_Key5* below, void* a5);                \
                                                                                                  \
        inline void Visit(typename Base::Visitor cb, const Unk_36fa70_Key5& filter,               \
                          const Unk_36fa70_Key0& a3, Unk_36fa70_Key5* below, void* a5,            \
                          bool here) {                                                            \
            if (here && this->field_10)                                                           \
                cb(&this->field_8, a3, a5);                                                       \
            if (filter.IsAnyHere()) {                                                             \
                for (auto it = this->field_18.Begin(); it != this->field_18.End(); ++it) {        \
                    below->field_0 = (*it).key;                                                   \
                    cb(&(*it).field_0, a3, a5);                                                   \
                }                                                                                 \
            } else {                                                                              \
                Name##_Item* item = this->field_18.Exists(filter.field_0);                        \
                if (item != nullptr) {                                                            \
                    below->field_0 = filter.field_0;                                              \
                    cb(&item->field_0, a3, a5);                                                   \
                }                                                                                 \
            }                                                                                     \
        }                                                                                         \
                                                                                                  \
        bool ForEach(typename Base::Callback cb, const Unk_36fa70_Key0& a2, Unk_36fa70_Key5* below, \
                     void* a4) {                                                                  \
            if (this->field_10) {                                                                 \
                if (cb(&this->field_8, a2, a4)) {                                                 \
                    if (this->field_10)                                                           \
                        this->field_10 = 0;                                                       \
                }                                                                                 \
            }                                                                                     \
            for (auto it = this->field_18.Begin(); it != this->field_18.End();) {                 \
                below->field_0 = (*it).key;                                                       \
                if (cb(&(*it).field_0, a2, a4))                                                   \
                    it = this->field_18.Erase(it);                                                \
                else                                                                              \
                    ++it;                                                                         \
            }                                                                                     \
            if (this->field_18.IsEmpty())                                                         \
                this->field_18.Term();                                                            \
            return !this->field_10 && this->field_18.IsEmpty();                                   \
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
        bool Has(const Unk_36fa70_Key0& key, const Unk_36fa70_Key0& orig);                        \
        Value* Find(const Unk_36fa70_Key0& below, Value** closest, bool* hasMore);                \
        bool ForEach(typename Name##_Base::Callback cb, const Unk_36fa70_Key0& a2,                \
                     Unk_36fa70_Key0* below, void* a4);                                           \
        bool ForEach(typename Name##_Base::Callback cb, const Unk_36fa70_Key0& filter,            \
                     const Unk_36fa70_Key0& a3, Unk_36fa70_Key0* below, void* a5, bool here);     \
        void Visit(typename Name##_Base::Visitor cb, const Unk_36fa70_Key0& filter,               \
                   const Unk_36fa70_Key0& a3, Unk_36fa70_Key0* below, void* a5, bool here);       \
        Value* Set(const Unk_36fa70_Key0& below);                                                 \
    }

// The tree of 0x710036fa70 (nodes of 0x30 bytes).
UNK_36FA70_LAST(Unk_23818a8, Unk_23818c8, Unk_36fa70_Value, u8, 0x30);
UNK_36FA70_NODE(Unk_2381868, Unk_2381888, Unk_36fa70_Value, u8, Unk_23818a8_Array,
                Unk_36fa70_Key4, 0x30,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_NODE(Unk_2381828, Unk_2381848, Unk_36fa70_Value, u32, Unk_2381868_Array,
                Unk_36fa70_Key3, 0x30,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_NODE(Unk_23817e8, Unk_2381808, Unk_36fa70_Value, u32, Unk_2381828_Array,
                Unk_36fa70_Key2, 0x30,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_NODE(Unk_23817a8, Unk_23817c8, Unk_36fa70_Value, u64, Unk_23817e8_Array,
                Unk_36fa70_Key1, 0x30,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_ROOT(Unk_36b160_Root, Unk_36fa70_Value, Unk_23817a8_Array);

// The tree of 0x71003a1830 (nodes of 0x28 bytes).
UNK_36FA70_LAST(Unk_2382da0, Unk_2382dc0, Unk_3a1830_Value, u8, 0x28);
UNK_36FA70_NODE(Unk_2382d60, Unk_2382d80, Unk_3a1830_Value, u8, Unk_2382da0_Array,
                Unk_36fa70_Key4, 0x28,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_NODE(Unk_2382d20, Unk_2382d40, Unk_3a1830_Value, u32, Unk_2382d60_Array,
                Unk_36fa70_Key3, 0x28,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_NODE(Unk_2382ce0, Unk_2382d00, Unk_3a1830_Value, u32, Unk_2382d20_Array,
                Unk_36fa70_Key2, 0x28,
                UNK_36FA70_REMOVEALL_BELOW);
UNK_36FA70_NODE(Unk_2382ca0, Unk_2382cc0, Unk_3a1830_Value, u64, Unk_2382ce0_Array,
                Unk_36fa70_Key1, 0x28,
                UNK_36FA70_REMOVEALL_39F8E0);
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
// 0x710039f8e0
void Unk_39f8e0(Unk_2382c60_Item* self) {
    Unk_2382ca0* node = reinterpret_cast<Unk_2382ca0*>(self);
    UNK_36FA70_REMOVEALL_BELOW(node)
}

// 0x710039a100
void Unk_39a100(Unk_2382c60* self, const Unk_3babc0_Key& key) {
    Unk_39a100_Root* root = reinterpret_cast<Unk_39a100_Root*>(self);
    const Unk_36fa70_Key0& below = reinterpret_cast<const Unk_36fa70_Key0&>(key);
    if (below.IsAny()) {
        if (root->field_10)
            root->field_10 = 0;
        return;
    }
    Unk_2382ca0* child = root->field_18.Exists(below.field_0);
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
    Unk_39a100_Root* root = reinterpret_cast<Unk_39a100_Root*>(self);
    const Unk_36fa70_Key0& below = reinterpret_cast<const Unk_36fa70_Key0&>(key);
    if (below.IsAny())
        return root->SetValue();
    Unk_2382ca0* child = root->field_18.Set(below.field_0);
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
UNK_36FA70_REMOVEALL(Unk_2382ca0, Unk_36fa70_Key1)
// 0x710039fb90
UNK_36FA70_REMOVEALL(Unk_2382ce0, Unk_36fa70_Key2)
// 0x71003a0000
UNK_36FA70_REMOVEALL(Unk_2382d20, Unk_36fa70_Key3)
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
    Unk_2382ca0* child = this->field_18.Exists(orig.field_0);
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
    Unk_2382ca0* child = this->field_18.Exists(below.field_0);
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

// What owns the first tree.
struct Unk_36a6b0_Item;
struct Unk_36b350_T {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x24];
    Unk_36b160_Root field_38;
    Unk_GrowArray<Unk_36a6b0_Item*> field_60;
};
PKMN_OFFSET_ASSERT(Unk_36b350_T, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_36b350_T, field_60, 0x60);

// 0x710036b350 (and 0x710036d980, the fourth level with the last inlined)
// NON_MATCHING: 0x710036d790, like 0x710039f290.
void* Unk_36b350(Unk_36b350_T* self, const Unk_36fa70_Key0& key) {
    Unk_36fa70_Value* value = self->field_38.Find(key, nullptr, nullptr);
    return value != nullptr ? value->field_0 : nullptr;
}

// What the first tree's values point to: an object with a reference count
// (the one Unk_373fd0_get, in lib/wwise/leaf, takes).
struct Unk_373fd0 {
    virtual ~Unk_373fd0();
    virtual void vf2(u32 a1, f32 a2);

    void Release() {
        if (--field_64 == 0)
            Unk_Delete(this);
    }

    // The key it is in the tree by.
    Unk_36fa70_Key0 Key() const {
        Unk_36fa70_Key0 key;
        key.field_0 = field_30;
        key.field_8.field_0 = field_48;
        key.field_8.field_8.field_0 = field_44;
        key.field_8.field_8.field_8.field_0 = field_41;
        key.field_8.field_8.field_8.field_8.field_0 = field_40;
        key.field_8.field_8.field_8.field_8.field_8.field_0 = field_18;
        return key;
    }

    u8 _8[0x10];
    u64 field_18;
    u8 _20[0x10];
    u64 field_30;
    u8 _38[8];
    u8 field_40;
    u8 field_41;
    u32 field_44;
    u32 field_48;
    struct {
        u8 _0[0xc];
        f32 field_c;
    }* field_50;
    u8 _58[0xc];
    u32 field_64;  // reference count
    u32 field_68;
    u8 _6c[4];
    f32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_373fd0, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_373fd0, field_70, 0x70);
bool Unk_373fd0_get(const Unk_373fd0* self);

struct Unk_36a620_Arg {
    u32 field_0;
    f32 field_4;
};

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
