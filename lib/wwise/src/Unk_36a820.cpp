// Scope: common
// What owns the first tree of Unk_36fa70.h (0x78 bytes, index 0x188): its
// creation, what it reads from a bank, and what it asks of its properties.
// Placeholder names.
#include "Unk_366110.h"
#include "Unk_36fa70.h"
#include "Unk_BankRead.h"

extern void* Unk_2381690[];
extern void* Unk_23816f0[];
extern void* Unk_24bbbf8;

// The properties' defaults.
extern Unk_PropValue Unk_24bcc28[];

// The constructor of the two kinds' base.
static inline void Unk_36a820_Init(Unk_36b350_T* self, u32 id) {
    Unk_363510(self, id);
    self->field_18 = 0;
    self->field_20.field_0 = nullptr;
    self->field_28.field_0 = nullptr;
    self->field_30 = 0;
    new (&self->field_38) Unk_36b160_Root;
    self->field_60.field_0 = nullptr;
    self->field_60.field_8 = 0;
    self->field_60.field_c = 0;
    self->field_70 = 0;
}

// 0x710036a820: a new object of one of the two kinds, in the index. The
// function has the name its callers gave it, with a bool; it tells 0, 1 and
// the rest apart.
Unk_36b350_T* Unk_36a820(u32 id, u32 kind) __asm__("_Z10Unk_36a820jb");
Unk_36b350_T* Unk_36a820(u32 id, u32 kind) {
    Unk_36b350_T* self;
    switch (kind) {
    case 0:
        self = static_cast<Unk_36b350_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_36b350_T)));
        if (self == nullptr)
            return nullptr;
        Unk_36a820_Init(self, id);
        Unk_SetVtable(self, Unk_2381690);
        self->field_18 = 0;
        break;
    case 1:
        self = static_cast<Unk_36b350_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_36b350_T)));
        if (self == nullptr)
            return nullptr;
        Unk_36a820_Init(self, id);
        Unk_SetVtable(self, Unk_23816f0);
        self->field_18 = 1;
        break;
    default:
        return nullptr;
    }
    Unk_IndexedAdd<0x188>(self);
    return self;
}

// 0x710036b690
bool Unk_36b690(Unk_36b350_T* self) {
    if (self->field_18 == 0)
        return false;
    Unk_PropValue def = Unk_24bcc28[1];
    return self->field_20.GetProp(1, def).i != 0;
}

// The property 0: how much of a key counts (0: all of it).
static inline s32 Unk_36abf0_Scope(const Unk_36b350_T* self) {
    Unk_PropValue def = Unk_24bcc28[0];
    return self->field_20.GetProp(0, def).i;
}

// Calls `cb` for every value of the tree that `filter` covers.
static inline void Unk_36abf0_Visit(Unk_36b160_Root& root, Unk_36b160_Root::Visitor cb,
                                    const Unk_36fa70_Key0& filter, void* arg) {
    Unk_36fa70_Key0 any;
    root.Visit(cb, filter, any, &any, arg, filter.IsAny());
}

// 0x710036abf0: calls every object of the tree that `key` covers, as far as
// the property 0 says the key counts: all of it (0), without its last part
// and, when it has a fifth, its second (1), its first part alone (2), or
// nothing of it.
void Unk_36abf0(Unk_36b350_T* self, u32 a1, f32 a2, const Unk_36fa70_Key0& key) {
    Unk_36a620_Arg arg;
    arg.field_0 = a1;
    arg.field_4 = a2;
    s32 scope = Unk_36abf0_Scope(self);
    Unk_36b160_Root& root = self->field_38;
    Unk_36fa70_Key0 filter = key;
    if (scope >= 1) {
        filter.field_8.field_8.field_8.field_8.field_8.field_0 = 0;
        if (key.field_8.field_8.field_8.field_8.field_0 != 0xff)
            filter.field_8.field_0 = 0;
        if (scope >= 2) {
            filter.field_8.field_8.field_8.field_8.field_0 = 0xff;
            filter.field_8.field_8.field_8.field_0 = 0xff;
            filter.field_8.field_8.field_0 = 0;
            filter.field_8.field_0 = 0;
            if (scope != 2)
                filter.field_0 = 0;
        }
    }
    Unk_36abf0_Visit(root, Unk_36a620, filter, &arg);
}

// Reads a set of properties from a bank's data: the number of them, their
// IDs, their values. False without memory.
template <class T>
static inline bool Unk_36a9f0_ReadProps(Unk_PropBundle<T>& props, u8*& data) {
    u8 count = Unk_ReadBank<u8>(data);
    if (count != 0) {
        u32 first = (count + 4) & ~3;
        size_t size = count * sizeof(T);
        u32 total = first + size;
        u8* bundle = static_cast<u8*>(Unk_3045e0(Unk_237e820, total));
        if (bundle == nullptr)
            return false;
        bundle[0] = count;
        memcpy(bundle + 1, data, count);
        data += count;
        memcpy(bundle + first, data, size);
        data += size;
        props.field_0 = bundle;
    }
    return true;
}

u32 Unk_39b150(void* self, Unk_362360_T* owner, u32 a2, u8 a3, u8 a4, u32 parameter, u32 a6,
               u32 scaling, const Unk_35f3b0_Point* points, u32 count, unsigned long* a10, u32 a11,
               bool a12);

// The key is passed by reference; the parameter has another type by the name
// the function has (as in Unk_366110.cpp).
static inline u32 Unk_39b150(void* self, Unk_362360_T* owner, u32 a2, u8 a3, u8 a4, u32 parameter,
                             u32 a6, u32 scaling, const Unk_35f3b0_Point* points, u32 count,
                             const Unk_366f90_Key& key, u32 a11, bool a12) {
    return Unk_39b150(self, owner, a2, a3, a4, parameter, a6, scaling, points, count,
                      reinterpret_cast<unsigned long*>(const_cast<Unk_366f90_Key*>(&key)), a11,
                      a12);
}

// Follow a game parameter with one of the parameters of the object.
static inline u32 Unk_36a9f0_Subscribe(Unk_36b350_T* self, u32 a2, u8 a3, u8 a4, u32 parameter,
                                       u32 a6, u32 scaling, const Unk_35f3b0_Point* points,
                                       u32 count) {
    self->field_30 |= 1ull << parameter;
    return Unk_39b150(Unk_24bbbf8, reinterpret_cast<Unk_362360_T*>(self), a2, a3, a4, parameter,
                      a6, scaling, points, count, Unk_366f90_Key(), 3, true);
}

// The game parameters an object follows, read from a bank's data (as
// Unk_366f90, for this class).
static inline u32 Unk_36a9f0_ReadParams(u8** data, u32* size, Unk_36b350_T* owner) {
    u32 count = Unk_ReadBank<u16>(*data);
    for (u32 i = 0; i < count; i++) {
        u32 a2 = Unk_ReadBank<u32>(*data);
        u8 a3 = Unk_ReadBank<u8>(*data);
        u8 a4 = Unk_ReadBank<u8>(*data);
        u32 parameter = Unk_ReadBankVar(*data);
        u32 a6 = Unk_ReadBank<u32>(*data);
        u32 scaling = Unk_ReadBank<u8>(*data);
        u16 points = Unk_ReadBank<u16>(*data);
        u32 result =
            Unk_36a9f0_Subscribe(owner, a2, a3, a4, parameter, a6, scaling,
                                 reinterpret_cast<const Unk_35f3b0_Point*>(*data), points);
        if (result != 1)
            return result;
        Unk_SkipBank(*data, *size, points * sizeof(Unk_35f3b0_Point));
    }
    return 1;
}

// 0x710036a9f0: what the object reads from a bank: its two sets of
// properties and the game parameters it follows. 1, or the failure's code.
u32 Unk_36a9f0(Unk_36b350_T* self, u8* data) {
    u32 size = 0;
    data += 4;
    if (!Unk_36a9f0_ReadProps(self->field_20, data))
        return 2;
    if (!Unk_36a9f0_ReadProps(self->field_28, data))
        return 2;
    return Unk_36a9f0_ReadParams(&data, &size, self);
}
