#pragma once
// Two trees of five levels of sorted arrays, each node with a value and the
// nodes of the next level by their key (their member functions are in
// Unk_36fa70.cpp), and what owns the first tree. Placeholder names; the node
// classes are named after their vtables.
#include "Unk_237c170.h"
#include "Unk_Indexed.h"
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

// Unk_3babc0.h (the switch groups' manager) calls three functions of the
// second tree and named them with its own placeholder types: the first
// level's RemoveAll (0x710039f8e0), the root's Remove (0x710039a100) and Set
// (0x710039c830). They keep those names here, and the first level's node
// class has that header's name for it, Unk_2382c60_Item (its vtable is at
// 0x7102382ca0), so that the call needs no cast: with one, the callers'
// registers come out in another order. (The header itself can't be included
// here: its sorted_array.h has another Unk_SortedKeyArray.)
struct Unk_2382c60_Item;
struct Unk_2382c60;
struct Unk_3babc0_Key;
void Unk_39f8e0(Unk_2382c60_Item* self);
void Unk_39a100(Unk_2382c60* self, const Unk_3babc0_Key& key);
u32* Unk_39c830(Unk_2382c60* self, const Unk_3babc0_Key& key);
#define UNK_36FA70_REMOVEALL_39F8E0(self) Unk_39f8e0(self);

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
        Value* FindBest(Below* below) {                                                           \
            if (!below->IsAny()) {                                                                \
                auto* child = this->field_18.Exists(below->field_0);                              \
                if (child == nullptr && !below->IsAnyHere()) {                                    \
                    below->field_0 = Below::Any();                                                \
                    child = this->field_18.Exists(Below::Any());                                  \
                }                                                                                 \
                if (child != nullptr) {                                                           \
                    Value* value = child->FindBest(&below->field_8);                              \
                    if (value != nullptr)                                                         \
                        return value;                                                             \
                }                                                                                 \
            }                                                                                     \
            below->field_8 = decltype(below->field_8)();                                          \
            return this->field_10 ? &this->field_8 : nullptr;                                     \
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
        Value* FindBest(Unk_36fa70_Key5* below) {                                                 \
            if (!below->IsAny()) {                                                                \
                Name##_Item* item = this->field_18.Exists(below->field_0);                        \
                if (item != nullptr)                                                              \
                    return &item->field_0;                                                        \
            }                                                                                     \
            *below = Unk_36fa70_Key5();                                                           \
            return this->field_10 ? &this->field_8 : nullptr;                                     \
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
#define UNK_36FA70_ROOT(Name, RootBase, Value, Child)                                             \
    UNK_36FA70_BASE(RootBase, Value, Child);                                                      \
    struct Name : RootBase {                                                                      \
        void Remove(const Unk_36fa70_Key0& below);                                                \
        void RemoveAll() { UNK_36FA70_REMOVEALL_BELOW(this) }                                     \
        void RemoveAll(const Unk_36fa70_Key0& below);                                             \
        bool Has(const Unk_36fa70_Key0& key, const Unk_36fa70_Key0& orig);                        \
        Value* Find(const Unk_36fa70_Key0& below, Value** closest, bool* hasMore);                \
        bool ForEach(typename RootBase::Callback cb, const Unk_36fa70_Key0& a2,                   \
                     Unk_36fa70_Key0* below, void* a4);                                           \
        bool ForEach(typename RootBase::Callback cb, const Unk_36fa70_Key0& filter,               \
                     const Unk_36fa70_Key0& a3, Unk_36fa70_Key0* below, void* a5, bool here);     \
        void Visit(typename RootBase::Visitor cb, const Unk_36fa70_Key0& filter,                  \
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
UNK_36FA70_ROOT(Unk_36b160_Root, Unk_36b160_Root_Base, Unk_36fa70_Value, Unk_23817a8_Array);

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
UNK_36FA70_NODE(Unk_2382c60_Item, Unk_2382cc0, Unk_3a1830_Value, u64, Unk_2382ce0_Array,
                Unk_36fa70_Key1, 0x28,
                UNK_36FA70_REMOVEALL_39F8E0);
// Its root's base class has the name Unk_3babc0.h has for it too (its vtable
// is at 0x7102382c60).
UNK_36FA70_ROOT(Unk_39a100_Root, Unk_2382c60, Unk_3a1830_Value, Unk_2382c60_Item_Array);

// What owns the first tree (0x78 bytes, index 0x188): one of two classes by
// its kind (vtables 0x7102381690 and 0x71023816f0).
struct Unk_36a6b0_Item;
struct Unk_36b350_T : Unk_Indexed {
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8();
    virtual bool vf9(void* a1);

    u32 field_18;  // the kind
    Unk_PropBundle<Unk_PropValue> field_20;
    Unk_PropBundle<u64> field_28;
    u32 field_30;  // the game parameters it follows, a bit each
    Unk_36b160_Root field_38;
    Unk_GrowArray<Unk_36a6b0_Item*> field_60;
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_36b350_T, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_36b350_T, field_60, 0x60);
PKMN_SIZE_ASSERT(Unk_36b350_T, 0x78);

// What the first tree's values point to: an object with a reference count
// (the one Unk_373fd0_get, in lib/wwise/leaf, takes).
struct Unk_373fd0;
// What the object lets go of when it is destroyed.
void Unk_3739f0(Unk_373fd0* self);

struct Unk_373fd0 {
    Unk_373fd0();  // 0x71003739b0
    virtual ~Unk_373fd0() { Unk_3739f0(this); }  // 0x7100374410
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

// Unk_36fa70.cpp
void* Unk_36b350(Unk_36b350_T* self, const Unk_36fa70_Key0& key);
void Unk_36a620(Unk_36fa70_Value* value, const Unk_36fa70_Key0&, void* arg);
bool Unk_36a640(Unk_36fa70_Value* value, const Unk_36fa70_Key0&, void*);
