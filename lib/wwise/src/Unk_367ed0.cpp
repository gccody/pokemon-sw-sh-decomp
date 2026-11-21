// Scope: common
// Pooled lists of the range 0x710035ead0-0x71003b6ee0: the Term of three of
// them. Placeholder names.
#include "Unk_368a60.h"
#include "list2.h"

// The pooled list with its pool as a parameter (Unk_List2Ex has the default
// pool's): the same Term.
template <class T, class A>
struct Unk_367ed0_List {
    struct Item {
        Item* next;
        T item;
    };

    Item* field_0;  // first
    Item* field_8;  // last
    Item* field_10;  // free items
    Item* field_18;  // preallocated items
    u32 field_20;  // number of preallocated items
    u32 field_24;  // number of items

    // An item and the one before it.
    struct IteratorEx {
        Item* item;
        Item* prev;

        void operator++() {
            prev = item;
            item = item->next;
        }
    };

    IteratorEx BeginEx() const {
        IteratorEx it;
        it.item = field_0;
        it.prev = nullptr;
        return it;
    }

    // Preallocates `count` items: 1, or 0x34 without memory.
    u32 Init(u32 count) {
        field_18 = static_cast<Item*>(A::Alloc(sizeof(Item) * count));
        if (field_18 == nullptr)
            return 0x34;
        field_10 = field_18;
        field_20 = count;
        Item* p = field_18;
        for (u32 i = 0; i < field_20; i++) {
            p->next = p + 1;
            p++;
        }
        (p - 1)->next = nullptr;
        return 1;
    }

    T* AddLast() {
        if (field_10 == nullptr) {
            Item* p = static_cast<Item*>(A::Alloc(sizeof(Item)));
            if (p == nullptr)
                return nullptr;
            p->next = field_10;
            field_10 = p;
        }
        if (field_8 != nullptr)
            field_8->next = field_10;
        else
            field_0 = field_10;
        field_8 = field_10;
        field_10 = field_10->next;
        field_8->next = nullptr;
        field_24++;
        return &field_8->item;
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

    bool IsPreallocated(Item* p) const { return field_18 <= p && field_18 + field_20 > p; }

    void FreeItem(Item* p) {
        if (IsPreallocated(p)) {
            p->next = field_10;
            field_10 = p;
        } else {
            A::Free(p);
        }
    }

    void RemoveFirst() {
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

template <class T, class A>
void Unk_367ed0_List<T, A>::Term() {
    RemoveAll();
    for (Item* p = field_10; p != nullptr;) {
        Item* next = p->next;
        if (!IsPreallocated(p))
            A::Free(p);
        p = next;
    }
    if (field_18 != nullptr) {
        A::Free(field_18);
        field_18 = nullptr;
    }
    field_20 = 0;
    field_0 = nullptr;
    field_8 = nullptr;
    field_10 = nullptr;
}

// What the list of 0x71024bcb50 holds: something a context asked for, and
// when.
struct Unk_3be850_Ctx;
struct Unk_367ed0_Item {
    Unk_3be850_Ctx* field_0;
    u32 field_8;
    u16 field_c_0 : 8;
    u16 field_c_8 : 1;
};
PKMN_SIZE_ASSERT(Unk_367ed0_Item, 0x10);
struct Unk_3b4190_Item {
    u64 field_0;
    u64 field_8;
};
struct Unk_395cb0_Item {
    u64 field_0;
};

// 0x7100367ed0
template void Unk_367ed0_List<Unk_367ed0_Item, Unk_Pool2381488>::Term();
// 0x71003b4190
template void Unk_List2Ex<Unk_3b4190_Item>::Term();
// 0x7100395cb0
template void Unk_List2Ex<Unk_395cb0_Item>::Term();

typedef Unk_367ed0_List<Unk_367ed0_Item, Unk_Pool2381488> Unk_367ed0_Requests;
Unk_367ed0_Requests Unk_24bcb50;
u32 Unk_24bcb48;

// A list without a pool: the last item, then the first.
struct Unk_368870_List {
    struct IteratorEx {
        Unk_368a60_T* item;
        Unk_368a60_T* prev;
    };

    Unk_368a60_T* field_0;  // last
    Unk_368a60_T* field_8;  // first

    IteratorEx BeginEx() const {
        IteratorEx it;
        it.item = field_8;
        it.prev = nullptr;
        return it;
    }

    void RemoveItem(Unk_368a60_T* p, Unk_368a60_T* prev) {
        if (p == field_8)
            field_8 = p->field_68;
        else
            prev->field_68 = p->field_68;
        if (p == field_0)
            field_0 = prev;
    }

    IteratorEx Erase(const IteratorEx& it) {
        IteratorEx next;
        next.item = it.item->field_68;
        next.prev = it.prev;
        RemoveItem(it.item, it.prev);
        return next;
    }
};
Unk_368870_List Unk_24bcb38;
u8 Unk_24bcb78;

// 0x7100367e30
u32 Unk_367e30() {
    Unk_24bcb48 = 0;
    return Unk_24bcb50.Init(0x200);
}

// 0x7100367eb0
void Unk_367eb0() {
    Unk_24bcb38.field_0 = nullptr;
    Unk_24bcb38.field_8 = nullptr;
    Unk_24bcb50.Term();
}

// 0x7100367fe0: forgets what a context asked for.
void Unk_367fe0(Unk_3be850_Ctx* ctx) {
    for (auto it = Unk_24bcb50.BeginEx(); it.item != nullptr;) {
        if (it.item->item.field_0 == ctx)
            it = Unk_24bcb50.Erase(it);
        else
            ++it;
    }
}

// 0x71003680c0: 1, or 2 without memory.
u32 Unk_3680c0(u32 type, Unk_3be850_Ctx* ctx) {
    Unk_367ed0_Item* item = Unk_24bcb50.AddLast();
    if (item == nullptr)
        return 2;
    item->field_0 = ctx;
    item->field_8 = Unk_24bcb48;
    item->field_c_0 = type;
    item->field_c_8 = 0;
    if (type <= 1)
        Unk_24bcb78 = 1;
    return 1;
}

// 0x7100368870
void Unk_368870() {
    for (auto it = Unk_24bcb38.BeginEx(); it.item != nullptr;) {
        Unk_368a60_T* object = it.item;
        it = Unk_24bcb38.Erase(it);
        Unk_368a60(object, 0);
    }
}

// The settings of this part of the engine (0x71024bcb80).
struct Unk_3689f0_Settings {
    u8 _0[0x84];
    u32 field_84;  // the pool's size
    u8 _88[4];
    u16 field_8c;
    u8 _8e[2];
};
PKMN_SIZE_ASSERT(Unk_3689f0_Settings, 0x90);
Unk_3689f0_Settings Unk_24bcb80;

struct Unk_2380d10_T {
    u64 field_0;
    u32 field_8;
};
extern Unk_2380d10_T Unk_2380d10;

int Unk_305450(void* a0, u32 size, u32 a2, u32 a3, u32 a4);
bool Unk_3044e0(void* a0);
void Unk_305660(int poolId);
void Unk_3338a0(void* settings);
extern "C" void* memcpy(void* dest, const void* src, size_t size);

// 0x7100368900: creates the pool: 1, or 0x34.
u32 Unk_368900() {
    if (Unk_2381488 == -1) {
        Unk_2381488 = Unk_305450(nullptr, Unk_24bcb80.field_84 > 0x40 ? Unk_24bcb80.field_84 : 0x1000000,
                                 0x40, 1, 0x10);
        if (Unk_2381488 == -1)
            return 0x34;
        Unk_2380d10.field_8 = Unk_2381488;
    }
    return 1;
}

// 0x7100368990
void Unk_368990(void* a0) {
    if (Unk_3044e0(a0) && Unk_2381488 != -1) {
        Unk_305660(Unk_2381488);
        Unk_2381488 = -1;
    }
}

// 0x71003689f0: sets the settings and gives them back as they are used, or
// the defaults without settings.
void Unk_3689f0(Unk_3689f0_Settings* settings) {
    if (settings != nullptr) {
        memcpy(&Unk_24bcb80, settings, sizeof(Unk_24bcb80));
        if (Unk_24bcb80.field_8c == 0)
            Unk_24bcb80.field_8c = 4;
        memcpy(settings, &Unk_24bcb80, sizeof(Unk_24bcb80));
    } else {
        Unk_3338a0(&Unk_24bcb80);
    }
}

// 0x7100368ff0: the array of 0x71024bcc18, whose items can own a buffer.
struct Unk_368ff0_Item {
    u8 _0[0x18];
    void* field_18;
    u32 field_20;
    u8 field_24;
};
PKMN_SIZE_ASSERT(Unk_368ff0_Item, 0x28);
Unk_Array<Unk_368ff0_Item> Unk_24bcc18;

void Unk_368ff0() {
    for (auto it = Unk_24bcc18.Begin(); it != Unk_24bcc18.End(); ++it) {
        if ((*it).field_24 && (*it).field_18 != nullptr)
            Unk_Pool2381488::Free((*it).field_18);
    }
    Unk_24bcc18.Term();
}

// A table of strings: 0x71003690b0 allocates it, 0x7100369110 frees it and
// 0x71003691b0 sets one.
struct Unk_3690b0_T {
    // What an item is known by: an ID and a position.
    struct Head {
        u32 field_0;
        u32 field_4;
    };
    struct Item {
        Head field_0;
        char* field_8;
    };

    u32 field_0;
    Item* field_8;
};

// 0x71003690b0
u32 Unk_3690b0(Unk_3690b0_T* self, u32 count) {
    self->field_0 = count;
    self->field_8 = static_cast<Unk_3690b0_T::Item*>(
        Unk_3045e0(Unk_2381488, sizeof(Unk_3690b0_T::Item) * count));
    if (self->field_8 == nullptr) {
        self->field_0 = 0;
        return 0x34;
    }
    return 1;
}

// 0x7100369110
void Unk_369110(void* object) {
    Unk_3690b0_T* self = static_cast<Unk_3690b0_T*>(object);
    if (self->field_8 != nullptr) {
        for (u32 i = 0; i < self->field_0; i++) {
            if (self->field_8[i].field_8 != nullptr) {
                Unk_Pool2381488::Free(self->field_8[i].field_8);
                self->field_8[i].field_8 = nullptr;
            }
        }
        Unk_Pool2381488::Free(self->field_8);
        self->field_8 = nullptr;
    }
    self->field_0 = 0;
}

// 0x71003691b0
u32 Unk_3691b0(Unk_3690b0_T* self, u32 index, const char* string, u32 length) {
    char* copy = static_cast<char*>(Unk_Pool2381488::Alloc(length + 1));
    if (copy == nullptr)
        return 0x34;
    memcpy(copy, string, length);
    copy[length] = 0;
    self->field_8[index].field_8 = copy;
    return 1;
}

// What 0x7100369240 fills: the items of a stretch of positions.
struct Unk_369240_Ctx {
    u64 field_0;
    u8 field_8;
};

struct Unk_369240_Out {
    struct Item {
        Unk_369240_Ctx* field_0;
        u32 field_8;
        Unk_3690b0_T::Item field_10;
    };

    u8 _0[0x12];
    u16 field_12;  // the length of the stretch
    u16 field_14;  // the number of items
    Item* field_18;
};
PKMN_SIZE_ASSERT(Unk_369240_Out::Item, 0x20);
PKMN_OFFSET_ASSERT(Unk_369240_Out, field_18, 0x18);

// 0x7100369240
void Unk_369240(Unk_3690b0_T* self, Unk_369240_Ctx* ctx, Unk_369240_Out* out, u32 start) {
    if (self->field_8 == nullptr || !(ctx->field_8 & 4))
        return;
    u32 length = out->field_12;
    out->field_18 = nullptr;
    out->field_14 = 0;
    for (u32 i = 0; i < self->field_0; i++) {
        if (self->field_8[i].field_0.field_4 >= start &&
            self->field_8[i].field_0.field_4 < start + length)
            out->field_14++;
    }
    if (out->field_14 == 0)
        return;
    out->field_18 = static_cast<Unk_369240_Out::Item*>(
        Unk_3045e0(Unk_2381488, sizeof(Unk_369240_Out::Item) * out->field_14));
    if (out->field_18 == nullptr) {
        out->field_14 = 0;
        return;
    }
    Unk_369240_Out::Item* item = out->field_18;
    for (u32 i = 0; i < self->field_0; i++) {
        if (self->field_8[i].field_0.field_4 >= start &&
            self->field_8[i].field_0.field_4 < start + length) {
            item->field_0 = ctx;
            item->field_8 = self->field_8[i].field_0.field_4 - start;
            item->field_10 = self->field_8[i];
            item++;
        }
    }
}

extern void* Unk_24bbc08;
void Unk_38f380(void* manager, Unk_369240_Ctx* ctx, Unk_3690b0_T::Item* item);

// 0x7100369380
void Unk_369380(Unk_3690b0_T* self, Unk_369240_Ctx* ctx, u32 start, u32 end) {
    if (self->field_8 == nullptr || !(ctx->field_8 & 4))
        return;
    for (u32 i = 0; i < self->field_0; i++) {
        if (self->field_8[i].field_0.field_4 >= start && self->field_8[i].field_0.field_4 < end)
            Unk_38f380(Unk_24bbc08, ctx, &self->field_8[i]);
    }
}

// 0x7100369430: the item closest to a position.
Unk_3690b0_T::Item* Unk_369430(Unk_3690b0_T* self, u32 position) {
    u32 distance = 0;
    Unk_3690b0_T::Item* closest = nullptr;
    for (u32 i = 0; i < self->field_0; i++) {
        s32 d = self->field_8[i].field_0.field_4 - position;
        if (d < 0)
            d = -d;
        if (closest == nullptr || static_cast<u32>(d) < distance) {
            distance = d;
            closest = &self->field_8[i];
        }
    }
    return closest;
}

extern "C" float sqrtf(float);

struct Unk_3694a0_Vec {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};

// 0x71003694a0
f32 Unk_3694a0(const Unk_3694a0_Vec* a, const Unk_3694a0_Vec* b) {
    f32 x = a->field_0 - b->field_0;
    f32 y = a->field_4 - b->field_4;
    f32 z = a->field_8 - b->field_8;
    return sqrtf(x * x + y * y + z * z);
}

// 0x71003694d0: the value at `x` on the line from (x0, y0) to (x1, y1).
f32 Unk_3694d0(f32 x0, f32 y0, f32 x1, f32 y1, f32 x) {
    if (x <= x0)
        return y0;
    if (x >= x1)
        return y1;
    return y0 + (x - x0) / (x1 - x0) * (y1 - y0);
}
