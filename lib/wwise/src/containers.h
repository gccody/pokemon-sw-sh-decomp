#pragma once
// Wwise's container templates, reconstructed from the code they inline into.
// Placeholder names: Wwise has no symbols or RTTI in the executable.
#include <types.h>

// The default memory pool's ID (0x710237e820).
extern int Unk_237e820;

void* Unk_3045e0(int poolId, size_t size);
u32 Unk_3047c0(int poolId, void* ptr);

// Allocation from a pool: `new (poolId) T(...)` is null when the pool is full.
inline void* operator new(size_t size, int poolId) noexcept {
    return Unk_3045e0(poolId, size);
}

// Construction in allocated memory.
struct Unk_Placement {};
inline void* operator new(size_t, void* ptr, Unk_Placement) noexcept {
    return ptr;
}

// Allocation policies of the containers: the pool they allocate from.
struct Unk_PoolDefault {
    static void* Alloc(size_t size) { return Unk_3045e0(Unk_237e820, size); }
    static void Free(void* ptr) { Unk_3047c0(Unk_237e820, ptr); }
};

// Another pool (0x7102385820).
extern int Unk_2385820;
struct Unk_Pool2385820 {
    static void* Alloc(size_t size) { return Unk_3045e0(Unk_2385820, size); }
    static void Free(void* ptr) { Unk_3047c0(Unk_2385820, ptr); }
};

// A third pool (0x7102381488).
extern int Unk_2381488;
struct Unk_Pool2381488 {
    static void* Alloc(size_t size) { return Unk_3045e0(Unk_2381488, size); }
    static void Free(void* ptr) { Unk_3047c0(Unk_2381488, ptr); }
};

// A growable array of T: a full array grows by GrowBy items when one is added.
template <class T, class A = Unk_PoolDefault, u32 GrowBy = 1>
struct Unk_Array {
    T* field_0;  // items
    u32 field_8;  // length
    u32 field_c;  // reserved

    u32 Length() const { return field_8; }

    // Without growing the array.
    T* AddLast() {
        if (field_8 >= field_c)
            return nullptr;
        return field_0 + field_8++;
    }

    T* AddLast(const T& item) {
        T* p = AddLast();
        if (p != nullptr)
            *p = item;
        return p;
    }

    // Takes the items of `other`, which is left empty.
    void Transfer(Unk_Array& other) {
        Term();
        field_0 = other.field_0;
        field_8 = other.field_8;
        field_c = other.field_c;
        other.field_0 = nullptr;
        other.field_8 = 0;
        other.field_c = 0;
    }

    bool GrowArray(u32 growBy) {
        u32 reserved = field_c + growBy;
        T* items = static_cast<T*>(A::Alloc(sizeof(T) * reserved));
        if (items == nullptr)
            return false;
        u32 length = Length();
        if (field_0 != nullptr && field_0 != items) {
            for (u32 i = 0; i < length; i++) {
                new (items + i, Unk_Placement()) T;
                items[i] = field_0[i];
            }
            A::Free(field_0);
        }
        field_0 = items;
        field_c = reserved;
        return true;
    }

    // Allocates the items of an empty array: 1, or 0x34 when out of memory.
    u32 Reserve(u32 reserved) {
        if (reserved != 0) {
            field_0 = static_cast<T*>(A::Alloc(sizeof(T) * reserved));
            if (field_0 == nullptr)
                return 0x34;
            field_c = reserved;
        }
        return 1;
    }

    struct Iterator {
        T* item;

        Iterator& operator++() {
            ++item;
            return *this;
        }
        T& operator*() { return *item; }
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
    };

    Iterator Begin() const {
        Iterator it;
        it.item = field_0;
        return it;
    }

    Iterator End() const {
        Iterator it;
        it.item = field_0 + field_8;
        return it;
    }

    // End() when the array doesn't have `item`.
    Iterator FindEx(const T& item) const {
        Iterator it = Begin();
        for (Iterator end = End(); it != end; ++it) {
            if (*it == item)
                break;
        }
        return it;
    }

    T* Exists(const T& item) const {
        Iterator it = FindEx(item);
        return it != End() ? it.item : nullptr;
    }

    // Growing the array when it is full.
    T* AddLastGrow() {
        size_t length = Length();
        if (length >= field_c) {
            if (!GrowArray(GrowBy))
                return nullptr;
        }
        if (length < field_c) {
            T* end = field_0 + field_8++;
            new (end, Unk_Placement()) T;
            return end;
        }
        return nullptr;
    }

    T* AddLastGrow(const T& item) {
        T* p = AddLastGrow();
        if (p != nullptr)
            *p = item;
        return p;
    }

    // The same with the item passed by value: it is read before the array
    // grows (0x71003b8500 builds the 8 bytes to store before the call).
    T* AddLastGrowValue(T item) {
        T* p = AddLastGrow();
        if (p != nullptr)
            *p = item;
        return p;
    }

    // A new item at `index`, the ones from there on moved up.
    inline T* Insert(u32 index) {
        size_t length = Length();
        if (length >= field_c) {
            if (!GrowArray(GrowBy))
                return nullptr;
        }
        if (length < field_c) {
            T* end = field_0 + field_8++;
            new (end, Unk_Placement()) T;
            for (T* p = end; p > field_0 + index; --p)
                p[0] = p[-1];
            new (field_0 + index, Unk_Placement()) T;
            return field_0 + index;
        }
        return nullptr;
    }

    // Removes the item at `it`, the ones after it moved down.
    Iterator Erase(Iterator& it) {
        T* last = field_0 + field_8 - 1;
        for (T* p = it.item; p < last; p++)
            p[0] = p[1];
        last->~T();
        field_8--;
        return it;
    }

    bool Resize(u32 size) {
        u32 length = Length();
        if (size < length) {
            field_8 = size;
            return true;
        }
        if (size > field_c) {
            if (!GrowArray(size - length))
                return false;
        }
        field_8 = size;
        return true;
    }

    void RemoveAll() {
        for (Iterator it = Begin(), end = End(); it != end; ++it)
            (*it).~T();
        field_8 = 0;
    }

    void Term() {
        if (field_0 != nullptr) {
            RemoveAll();
            A::Free(field_0);
            field_0 = nullptr;
            field_c = 0;
        }
    }
};

// The table sizes of the hash lists: the first prime in this list that is at
// least the requested size, or 0 when the request is larger than all.
static const u32 Unk_HashPrimes[] = {
    29, 53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241,
    786433, 1572869, 3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611,
    402653189, 805306457, 1610612741,
};

static inline u32 Unk_HashPrime(u32 size) {
    for (u32 i = 0; i < sizeof(Unk_HashPrimes) / sizeof(Unk_HashPrimes[0]); i++) {
        if (Unk_HashPrimes[i] > size)
            return Unk_HashPrimes[i];
    }
    return 0;
}

// An intrusive singly linked list: T has a `next` pointer. The last item is
// kept before the first.
template <class T>
struct Unk_ListBare {
    T* field_0;  // last
    T* field_8;  // first

    Unk_ListBare() : field_0(nullptr), field_8(nullptr) {}

    void AddFirst(T* item) {
        T* first = field_8;
        field_8 = item;
        if (first == nullptr)
            field_0 = item;
        item->next = first;
    }

    void Remove(T* item) {
        T* prev = nullptr;
        T* p = field_8;
        while (p != nullptr && p != item) {
            prev = p;
            p = p->next;
        }
        if (p == nullptr)
            return;
        if (field_8 == p)
            field_8 = p->next;
        else
            prev->next = p->next;
        if (field_0 == p)
            field_0 = prev;
    }

    // An item and the one before it.
    struct IteratorEx {
        T* item;
        T* prev;

        void operator++() {
            prev = item;
            item = item->next;
        }
    };

    IteratorEx BeginEx() const {
        IteratorEx it;
        it.item = field_8;
        it.prev = nullptr;
        return it;
    }

    IteratorEx FindEx(T* item) const {
        IteratorEx it = BeginEx();
        for (; it.item != nullptr; ++it) {
            if (it.item == item)
                break;
        }
        return it;
    }

    void RemoveItem(T* item, T* prev) {
        T* next = item->next;
        if (item == field_8)
            field_8 = next;
        else
            prev->next = next;
        if (field_0 == item)
            field_0 = prev;
    }

    // Like Remove, in the form most of the code has it.
    void RemoveEx(T* item) {
        IteratorEx it = FindEx(item);
        if (it.item != nullptr)
            RemoveItem(it.item, it.prev);
    }
};

// A singly linked list of T whose items come from a free list: the items of a
// preallocated block (field_18, field_20 items) and items allocated one at a
// time from the default pool, which go back to the free list when removed.
template <class T>
struct Unk_List2 {
    struct Item {
        Item* next;
        T item;
    };

    struct Iterator {
        Item* item;

        void operator++() { item = item->next; }
        T& operator*() { return item->item; }
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
    };

    struct IteratorEx : Iterator {
        Item* prev;

        void operator++() {
            prev = this->item;
            this->item = this->item->next;
        }
    };

    Item* field_0;  // first
    Item* field_8;  // last
    Item* field_10;  // free items
    Item* field_18;  // preallocated items
    u32 field_20;  // number of preallocated items
    u32 field_24;  // number of items

    Unk_List2()
        : field_0(nullptr), field_8(nullptr), field_10(nullptr), field_18(nullptr), field_20(0),
          field_24(0) {}

    IteratorEx BeginEx() const {
        IteratorEx it;
        it.item = field_0;
        it.prev = nullptr;
        return it;
    }

    Iterator Begin() const {
        Iterator it;
        it.item = field_0;
        return it;
    }

    Iterator End() const {
        Iterator it;
        it.item = nullptr;
        return it;
    }

    bool IsPreallocated(Item* p) const { return field_18 <= p && field_18 + field_20 > p; }

    void FreeItem(Item* p) {
        if (IsPreallocated(p)) {
            p->next = field_10;
            field_10 = p;
        } else {
            Unk_3047c0(Unk_237e820, p);
        }
    }

    Item* AllocItem() {
        if (field_10 == nullptr) {
            Item* p = static_cast<Item*>(Unk_3045e0(Unk_237e820, sizeof(Item)));
            if (p == nullptr)
                return nullptr;
            p->next = field_10;
            field_10 = p;
        }
        return field_10;
    }

    T* AddFirst() {
        Item* p = AllocItem();
        if (p == nullptr)
            return nullptr;
        if (field_0 == nullptr)
            field_8 = p;
        field_10 = p->next;
        p->next = field_0;
        field_0 = p;
        field_24++;
        return &p->item;
    }

    void RemoveItem(Item* p, Item* prev) {
        if (p == field_0)
            field_0 = p->next;
        else
            prev->next = p->next;
        if (field_8 == p)
            field_8 = prev;
        FreeItem(p);
        field_24--;
    }

    IteratorEx Erase(const IteratorEx& it) {
        IteratorEx next;
        next.item = it.item->next;
        next.prev = it.prev;
        RemoveItem(it.item, it.prev);
        return next;
    }

    void RemoveFirst() {
        if (field_0 == nullptr)
            return;
        Item* p = field_0;
        field_0 = p->next;
        if (field_8 == p)
            field_8 = nullptr;
        FreeItem(p);
        field_24--;
    }

    void RemoveAll() {
        while (field_0 != nullptr)
            RemoveFirst();
    }

    void Term();
};

// Not inline: the executable has it out of line.
template <class T>
void Unk_List2<T>::Term() {
    RemoveAll();
    for (Item* p = field_10; p != nullptr;) {
        Item* next = p->next;
        if (!IsPreallocated(p))
            Unk_3047c0(Unk_237e820, p);
        p = next;
    }
    if (field_18 != nullptr) {
        Unk_3047c0(Unk_237e820, field_18);
        field_18 = nullptr;
    }
    field_20 = 0;
    field_10 = nullptr;
    field_0 = nullptr;
    field_8 = nullptr;
}
