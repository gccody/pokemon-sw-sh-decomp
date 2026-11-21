// Scope: common
// Three indexed classes of one shape (Unk_360c20_T): their creation
// functions, which construct the object and add it to its index, and their
// destructor. Placeholder names.
#include "Unk_360c20.h"
#include "Unk_BankRead.h"

extern void* Unk_2380888[];
extern void* Unk_2380a38[];
extern void* Unk_2380960[];
extern void* Unk_2380b10[];

// The second base of an object, which is never null here.
static inline Unk_2380c68* Unk_360c20_Base(Unk_360c20_T* self) {
    return &static_cast<Unk_2380c68&>(*self);
}

template <void** Vtable, u32 Offset>
static inline Unk_360c20_T* Unk_360c20_Create(u32 id) {
    Unk_360c20_T* self = static_cast<Unk_360c20_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_360c20_T)));
    if (self != nullptr) {
        Unk_363510(self, id);
        new (Unk_360c20_Base(self)) Unk_2380c68;
        self->field_30 = 0xffffffff;
        for (int i = 0; i < 8; i++)
            (&self->field_38)[i] = nullptr;
        Unk_SetVtable(self, Vtable);
        Unk_SetVtable(Unk_360c20_Base(self), Vtable + 8);
        Unk_IndexedAdd<Offset>(self);
    }
    return self;
}

// 0x7100360c20
Unk_360c20_T* Unk_360c20(u32 id) {
    return Unk_360c20_Create<Unk_2380a38, 0x230>(id);
}

// 0x7100360ec0
Unk_360c20_T* Unk_360ec0(u32 id) {
    return Unk_360c20_Create<Unk_2380960, 0x2a0>(id);
}

// 0x7100361160
Unk_360c20_T* Unk_361160(u32 id) {
    return Unk_360c20_Create<Unk_2380b10, 0x268>(id);
}

// 0x71003627c0
// NON_MATCHING: the loads of field_50's items and length before the loop are
// in the other order.
void Unk_3627c0(void* self_) {
    Unk_360c20_T* self = static_cast<Unk_360c20_T*>(self_);
    Unk_SetVtable(self, Unk_2380888);
    Unk_SetVtable(Unk_360c20_Base(self), Unk_2380888 + 8);
    for (auto it = self->field_50.Begin(); it != self->field_50.End(); ++it)
        (*it).field_10.Unset();
    self->field_50.Term();
    self->field_60.Term();
    self->field_40.Term();
    if (self->field_38 != nullptr)
        self->field_38->vf5(&Unk_2380d00);
    Unk_362a20(Unk_360c20_Base(self));
    Unk_IndexedDtor(self);
}

u32 Unk_39f090_get(const struct Unk_39f090* self);
u32 Unk_35f0e0(void* allocator, u32 id, void** out);
u32 Unk_360640(Unk_360c20_T* self, u32 a1, u8 a2, u8 a3, u32 parameter, u32 a5, u32 scaling,
               const Unk_35f3b0_Point* points, u32 count, bool notify);

static inline u32 Unk_360550_Set(Unk_360c20_T* self, u32 id, const void* data, u32 size) {
    Unk_360c20_Params* params = nullptr;
    u32 result = Unk_35f0e0(&Unk_2380d00, id, reinterpret_cast<void**>(&params));
    if (result != 1 || params == nullptr) {
        self->field_30 = id;
        return 1;
    }
    result = params->vf4(&Unk_2380d00, data, size);
    Unk_360c20_Params* p = params;
    if (result != 1) {
        p->vf5(&Unk_2380d00);
        return result;
    }
    if (self->field_38 != nullptr) {
        self->field_38->vf5(&Unk_2380d00);
        self->field_38 = nullptr;
    }
    self->field_30 = id;
    self->field_38 = p;
    return 1;
}

// 0x7100360550
u32 Unk_360550(Unk_360c20_T* self, u32 id, const void* data, u32 size) {
    return Unk_360550_Set(self, id, data, size);
}

struct Unk_3476d0_Obj;

// 0x710035ff30
u32 Unk_35ff30(Unk_3476d0_Obj* self_, u32* data_, u32 size_) {
    Unk_360c20_T* self = reinterpret_cast<Unk_360c20_T*>(self_);
    u8* data = reinterpret_cast<u8*>(data_);
    u32 size = size_;
    Unk_ReadBank<u32>(data);
    u32 id = Unk_ReadBank<u32>(data);
    u32 paramsSize = Unk_ReadBank<u32>(data);
    u32 result = 1;
    if (id != 0xffffffff)
        result = Unk_360550_Set(self, id, data, paramsSize);
    Unk_SkipBank(data, size, paramsSize);
    if (result != 1)
        return result;

    u32 count = Unk_ReadBank<u8>(data);
    result = self->field_40.Reserve(count);
    if (result != 1)
        return result;
    for (u32 i = 0; i < count; i++) {
        u8 key = Unk_ReadBank<u8>(data);
        u32 value = Unk_ReadBank<u32>(data);
        self->field_40.Set(key, value);
    }

    result = self->field_50.Reserve(Unk_39f090_get(reinterpret_cast<const Unk_39f090*>(&data)));
    if (result != 1)
        return result;
    count = Unk_ReadBank<u16>(data);
    for (u32 i = 0; i < count; i++) {
        u32 a1 = Unk_ReadBank<u32>(data);
        u8 a2 = Unk_ReadBank<u8>(data);
        u8 a3 = Unk_ReadBank<u8>(data);
        u32 a4 = Unk_ReadBankVar(data);
        u32 a5 = Unk_ReadBank<u32>(data);
        u8 a6 = Unk_ReadBank<u8>(data);
        u16 points = Unk_ReadBank<u16>(data);
        result = Unk_360640(self, a1, a2, a3, a4, a5, a6,
                            reinterpret_cast<const Unk_35f3b0_Point*>(data), points, false);
        if (result != 1)
            return result;
        Unk_SkipBank(data, size, points * sizeof(Unk_35f3b0_Point));
    }

    result = self->wf14(&data, &size);
    if (result != 1)
        return result;

    count = Unk_ReadBank<u16>(data);
    result = self->field_60.Reserve(count);
    if (result != 1)
        return result;
    for (u32 i = 0; i < count; i++) {
        u32 parameter = Unk_ReadBankVar(data);
        u8 set = Unk_ReadBank<u8>(data);
        f32 number = Unk_ReadBank<f32>(data);
        Unk_360c20_Value* value = self->field_60.AddLast();
        if (value != nullptr)
            value->Set(parameter, set, number);
    }
    return 1;
}

extern void* Unk_24bbbf8;
void Unk_39b150(void* self, Unk_362360_T* owner, u32 a2, u8 a3, u8 a4, u32 parameter, u32 a6,
                u32 scaling, const Unk_35f3b0_Point* points, u32 count, u64* a10, u32 a11,
                bool a12);
void Unk_361fa0(Unk_362360_T* self, u32 parameter, f32 value);

// 0x7100360640
u32 Unk_360640(Unk_360c20_T* self, u32 a1, u8 a2, u8 a3, u32 parameter, u32 a5, u32 scaling,
               const Unk_35f3b0_Point* points, u32 count, bool notify) {
    auto it = self->field_50.Begin();
    while (it != self->field_50.End()) {
        if ((*it).field_6 == static_cast<u16>(parameter) && (*it).field_8 == a5) {
            (*it).field_10.Unset();
            it = self->field_50.Erase(it);
        } else {
            ++it;
        }
    }

    Unk_360c20_Sub* sub = self->field_50.AddLast();
    if (sub == nullptr)
        return 0x34;
    sub->field_8 = a5;
    sub->field_0 = a1;
    sub->field_6 = parameter;
    sub->field_4 = a2;
    sub->field_5 = a3;
    if (points != nullptr && count != 0) {
        u32 result = sub->field_10.Set(points, count, scaling);
        if (result != 1)
            return result;
    }

    for (auto value = self->field_60.Begin(); value != self->field_60.End(); ++value) {
        if ((*value).field_0 == parameter) {
            (*value).field_2 = a3;
            break;
        }
    }
    if (!notify)
        return 1;

    for (Unk_362360_T* p = self->field_70.field_0; p != nullptr; p = p->field_58)
        Unk_39b150(Unk_24bbbf8, p, sub->field_0, a2, a3, parameter, a5, scaling, points, count,
                   &p->field_18, 1, true);

    for (Unk_362360_T* p = self->field_70.field_0; p != nullptr; p = p->field_58) {
        auto item = p->field_48.Begin();
        while (item != p->field_48.End()) {
            if ((*item).field_8 == static_cast<u16>(parameter))
                item = p->field_48.Erase(item);
            else
                ++item;
        }
        f32* value = p->field_10->field_60.Exists(parameter);
        if (value != nullptr)
            Unk_361fa0(p, parameter, *value);
    }
    return 1;
}
