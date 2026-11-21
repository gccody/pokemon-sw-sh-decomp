// Scope: common
// The objects of the list of an Unk_363570_T (index 0x118, 0x40 bytes): each
// follows game parameters and has a table of points per child of its owner.
// Placeholder names.
#include "Unk_366110.h"
#include "Unk_BankRead.h"

extern void* Unk_2381450[];
extern void* Unk_24bbbf8;

void Unk_39b740(void* self, unsigned long owner, u32 id);
void Unk_39b730_call(void* self, unsigned long owner);
u32 Unk_39b0e0(void* self, Unk_366110_T* owner, u32 id, u32 a3);
u32 Unk_39b150(void* self, Unk_362360_T* owner, u32 a2, u8 a3, u8 a4, u32 parameter, u32 a6,
               u32 scaling, const Unk_35f3b0_Point* points, u32 count, unsigned long* a10, u32 a11,
               bool a12);
// The key is passed by reference; the parameter has another type by the name
// the function has.
static inline u32 Unk_39b150(void* self, Unk_362360_T* owner, u32 a2, u8 a3, u8 a4, u32 parameter,
                             u32 a6, u32 scaling, const Unk_35f3b0_Point* points, u32 count,
                             const Unk_366f90_Key& key, u32 a11, bool a12) {
    return Unk_39b150(self, owner, a2, a3, a4, parameter, a6, scaling, points, count,
                      reinterpret_cast<unsigned long*>(const_cast<Unk_366f90_Key*>(&key)), a11,
                      a12);
}
u32 Unk_367120(Unk_366110_T* self, u32 id, const Unk_35f3b0_Point* points, u32 count);

// The function has two parameters by its name, and is called with the ID too.
static inline void Unk_366110_Unsubscribe(Unk_366110_T* self, u32 id) {
    reinterpret_cast<void (*)(void*, unsigned long, u32)>(Unk_39b730_call)(
        Unk_24bbbf8, reinterpret_cast<unsigned long>(self), id);
}

// 0x7100366110
// NON_MATCHING: the loads of field_18's items and length before the loop are
// in the other order, as in Unk_3627c0.
void Unk_366110(void* self_) {
    Unk_366110_T* self = static_cast<Unk_366110_T*>(self_);
    Unk_SetVtable(self, Unk_2381450);
    for (u32 i = 0; self->field_28 != 0; i++) {
        u64 bit = 1ull << i;
        if (self->field_28 & bit) {
            Unk_39b740(Unk_24bbbf8, reinterpret_cast<unsigned long>(self), i);
            self->field_28 &= ~bit;
        }
    }
    if (self->field_38 != 0)
        Unk_366110_Unsubscribe(self, self->field_38);
    for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it)
        (*it).item.Term(self);
    self->field_18.Term();
    Unk_IndexedDtor(self);
}

// 0x7100366280
Unk_366110_T* Unk_366280(u32 id) {
    Unk_366110_T* self = static_cast<Unk_366110_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_366110_T)));
    if (self != nullptr) {
        Unk_363510(self, id);
        Unk_SetVtable(self, Unk_2381450);
        self->field_18.field_0 = nullptr;
        self->field_18.field_8 = 0;
        self->field_18.field_c = 0;
        self->field_28 = 0;
        self->field_30 = nullptr;
        self->field_38 = 0;
        self->field_3c = 0;
        Unk_IndexedAdd<0x118>(self);
    }
    return self;
}

// Follow a game parameter with one of the parameters of the object.
static inline u32 Unk_366110_Subscribe(Unk_366110_T* self, u32 a2, u8 a3, u8 a4, u32 parameter,
                                       u32 a6, u32 scaling, const Unk_35f3b0_Point* points,
                                       u32 count) {
    self->field_28 |= 1ull << parameter;
    return Unk_39b150(Unk_24bbbf8, reinterpret_cast<Unk_362360_T*>(self), a2, a3, a4, parameter,
                      a6, scaling, points, count, Unk_366f90_Key(), 4, true);
}

// 0x7100366f90
template <class T>
u32 Unk_366f90(u8** data, u32* size, T* owner, bool) {
    u32 count = Unk_ReadBank<u16>(*data);
    for (u32 i = 0; i < count; i++) {
        u32 a2 = Unk_ReadBank<u32>(*data);
        u8 a3 = Unk_ReadBank<u8>(*data);
        u8 a4 = Unk_ReadBank<u8>(*data);
        u32 parameter = Unk_ReadBankVar(*data);
        u32 a6 = Unk_ReadBank<u32>(*data);
        u8 scaling = Unk_ReadBank<u8>(*data);
        u16 points = Unk_ReadBank<u16>(*data);
        u32 result =
            Unk_366110_Subscribe(owner, a2, a3, a4, parameter, a6, scaling,
                                 reinterpret_cast<const Unk_35f3b0_Point*>(*data), points);
        if (result != 1)
            return result;
        Unk_SkipBank(*data, *size, points * sizeof(Unk_35f3b0_Point));
    }
    return 1;
}

// 0x7100366d90
u32 Unk_366d90(Unk_366110_T* self, u8** data, u32* size) {
    Unk_ReadBank<u32>(*data);
    u32 result = Unk_366f90(data, size, self, true);
    if (result != 1)
        return result;

    u32 id = Unk_ReadBank<u32>(*data);
    u8 a3 = Unk_ReadBank<u8>(*data);
    if (self->field_38 != id) {
        if (self->field_38 != 0)
            Unk_366110_Unsubscribe(self, self->field_38);
        self->field_38 = id;
        self->field_3c = a3;
        if (id != 0) {
            result = Unk_39b0e0(Unk_24bbbf8, self, id, a3);
            if (result != 1)
                self->field_38 = 0;
        }
        for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it) {
            Unk_366110_Node* node = (*it).item.field_8;
            if (node != nullptr && node->field_70 != nullptr && node->field_70->field_90 > 0)
                node->vf48(0);
        }
        if (result != 1)
            return result;
    }

    u32 count = Unk_ReadBank<u32>(*data);
    if (count != 0) {
        result = self->field_18.Reserve(count);
        if (result != 1)
            return result;
        for (u32 i = 0; i < count; i++) {
            u32 child = Unk_ReadBank<u32>(*data);
            u32 points = Unk_ReadBank<u32>(*data);
            result = Unk_367120(self, child, reinterpret_cast<const Unk_35f3b0_Point*>(*data),
                                points);
            if (result != 1)
                return result;
            Unk_SkipBank(*data, *size, points * sizeof(Unk_35f3b0_Point));
        }
    }
    return 1;
}

// 0x7100367500
u32 Unk_367500(Unk_366110_T* self, u32 id) {
    auto it = self->field_18.FindEx(id);
    if (it == self->field_18.End())
        return 0x10;
    u32 result = (*it).item.Term(self);
    self->field_18.Erase(it);
    return result;
}

// 0x7100367630
void Unk_367630(Unk_366110_T* self, void* owner) {
    if (self->field_30 != nullptr) {
        for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it)
            (*it).item.ClearChild(self);
    }
    self->field_30 = owner;
    if (owner != nullptr) {
        for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it) {
            if ((*it).item.field_8 == nullptr)
                (*it).item.UpdateChild(self);
        }
    }
}

// 0x7100367750
void Unk_367750(Unk_366110_T* self, u32 id) {
    auto it = self->field_18.FindEx(id);
    if (it != self->field_18.End() && (*it).item.field_8 == nullptr)
        (*it).item.UpdateChild(self);
}

// 0x71003807d0
// NON_MATCHING: the same instructions, with the copy loop of the growing
// array in another place (block layout).
u32 Unk_3807d0(Unk_366110_Node* self, Unk_366110_T* a1) {
    if (self->field_a8 == nullptr) {
        self->field_a8 = static_cast<Unk_GrowArray<Unk_366110_T*, Unk_PoolDefault, 4>*>(
            Unk_3045e0(Unk_237e820, 0x10));
        if (self->field_a8 != nullptr)
            new (self->field_a8) Unk_GrowArray<Unk_366110_T*, Unk_PoolDefault, 4>();
    }
    u32 result = 0x34;
    if (self->field_a8 != nullptr) {
        if (self->field_a8->AddLast(a1) != nullptr) {
            self->vf48(0);
            result = 1;
        }
    }
    if (result != 1 && self->field_a8 != nullptr && self->field_a8->Length() == 0) {
        Unk_3047c0(Unk_237e820, self->field_a8);
        self->field_a8 = nullptr;
    }
    return result;
}

// 0x7100367120
u32 Unk_367120(Unk_366110_T* self, u32 id, const Unk_35f3b0_Point* points, u32 count) {
    Unk_366110_Child* child = self->field_18.Exists(id);
    if (child == nullptr) {
        child = self->field_18.Set(id);
        if (child == nullptr)
            return 0x34;
        child->field_0 = id;
        if (child->field_8 == nullptr) {
            u32 result = child->UpdateChild(self);
            if (result != 1) {
                self->field_18.Unset(id);
                return result;
            }
        }
    }
    u32 result;
    if (count == 0) {
        child->field_10.Unset();
        result = 1;
    } else {
        result = child->field_10.Set(points, count, 0);
    }
    if (result == 1 && child->field_10.field_8 > 1) {
        child->field_20 = child->field_10.field_0[0].field_0;
        child->field_24 = child->field_10.field_0[child->field_10.field_8 - 1].field_0;
    } else {
        child->field_20 = -3.4028235e38f;
        child->field_24 = 3.4028235e38f;
    }
    if (child->field_8 != nullptr)
        child->field_8->vf48(0);
    return result;
}

// Whether a node plays.
static inline bool Unk_366110_IsActive(Unk_366110_Node* node) {
    return node != nullptr && node->field_70 != nullptr && node->field_70->field_90 > 0;
}

// 0x7100366380
// NON_MATCHING: two instructions before the loop are in the other order.
void Unk_366380(Unk_366110_T* self, bool a1) {
    for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it) {
        Unk_366110_Node* node = (*it).item.field_8;
        if (Unk_366110_IsActive(node))
            node->vf48(a1);
    }
}

// 0x7100366d40
bool Unk_366d40(Unk_366110_T* self) {
    for (auto it = self->field_18.Begin(), end = self->field_18.End(); it != end; ++it) {
        if (Unk_366110_IsActive((*it).item.field_8))
            return true;
    }
    return false;
}

struct Unk_366b00_Info {
    u32 field_0;
    Unk_366f90_Key field_8;
    bool field_38;
    void* field_40;
    f32 field_48;
};
PKMN_SIZE_ASSERT(Unk_366b00_Info, 0x50);

// 0x7100366b00
u32 Unk_366b00(Unk_366110_T* self, void*, u32 a2, void*, const Unk_366f90_Key* key, void* a5,
               f32 a6, f32 a7) {
    f32 delta = a6 - a7;
    Unk_366b00_Info info;
    info.field_0 = a2;
    info.field_38 = false;
    info.field_8 = *key;
    info.field_48 = delta;
    info.field_40 = a5;
    for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it) {
        Unk_366110_Node* node = (*it).item.field_8;
        if (Unk_366110_IsActive(node))
            node->vf23(&info);
    }
    return 1;
}

// A value from a game parameter, for 0x71003784f0 to fill.
struct Unk_366540_Value {
    f32 field_0;
    f32 field_4;
    u32 field_8;

    Unk_366540_Value() : field_0(0.0f), field_4(1.0f), field_8(0x39) {}
};
PKMN_SIZE_ASSERT(Unk_366540_Value, 0xc);

extern void* Unk_24bbc18;
bool Unk_3784f0(void* self, Unk_366110_T* owner, u32 parameter, u32 a3, void* a4,
                Unk_366540_Value* value);

// 0x7100366540
template Unk_366540_Value* Unk_GrowArray<Unk_366540_Value>::AddLast(const Unk_366540_Value&);

// 0x7100366460
u32 Unk_366460(Unk_366110_T* self, Unk_GrowArray<Unk_366540_Value>* out, u32 a2, void* a3) {
    if (self->field_28 & 1) {
        Unk_366540_Value value;
        if (Unk_3784f0(Unk_24bbc18, self, 0, a2, a3, &value))
            out->AddLast(value);
    }
    if (self->field_28 & 0x80) {
        Unk_366540_Value value;
        if (Unk_3784f0(Unk_24bbc18, self, 7, a2, a3, &value))
            out->AddLast(value);
    }
    return 1;
}
