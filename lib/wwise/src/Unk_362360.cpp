// Scope: common
// The objects that refer to an Unk_360c20_T (Unk_362360_T) and a class
// derived from them. Placeholder names.
#include "Unk_369950.h"

void operator delete(void* ptr) noexcept;

extern void* Unk_2380be8[];
extern void* Unk_2380c28[];
extern void* Unk_24bbbf8;

void Unk_39b740(void* self, unsigned long owner, u32 id);

struct Unk_3624a0_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* allocator);
};

struct Unk_3624a0_T : Unk_362360_T {
    Unk_3624a0_Obj* field_60;
};

// 0x7100362360
void Unk_362360(Unk_362360_T* self) {
    Unk_360c20_T* target = self->field_10;
    if (target != nullptr) {
        for (auto it = target->field_50.Begin(); it != target->field_50.End(); ++it)
            Unk_39b740(Unk_24bbbf8, reinterpret_cast<unsigned long>(self), (*it).field_6);
    }
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_30 = 0xff;
    self->field_38 = 0xff;
    self->field_40 = 0;
    if (self->field_8 != nullptr) {
        self->field_8->vf5(&Unk_2380d10);
        self->field_8 = nullptr;
    }
    Unk_360c20_T* p = self->field_10;
    if (p != nullptr) {
        if (p->field_70.Remove(self))
            p->vf3();
        self->field_10 = nullptr;
    }
    self->field_48.Term();
}

static inline void Unk_3624a0_Term(Unk_3624a0_T* self) {
    if (self->field_60 != nullptr) {
        self->field_60->vf2(&Unk_2380d10);
        self->field_60 = nullptr;
    }
    Unk_362360(self);
}

// 0x71003624a0
void Unk_3624a0(Unk_3624a0_T* self) {
    Unk_3624a0_Term(self);
}

// 0x71003624e0
void Unk_3624e0(Unk_3624a0_T* self, Unk_3624a0_T* other) {
    Unk_3624a0_Obj* obj = other->field_60;
    other->field_60 = nullptr;
    self->vf5();
    self->field_8 = other->field_8;
    Unk_360c20_T* p = other->field_10;
    self->field_10 = p;
    if (p != nullptr) {
        p->field_70.AddFirst(self);
        p->vf2();
    }
    other->field_8 = nullptr;
    other->vf5();
    self->field_60 = obj;
}

// 0x7100362570
void Unk_362570(Unk_362360_T* self) {
    Unk_SetVtable(self, Unk_2380be8);
    Unk_362360(self);
}

// 0x7100362590
void Unk_362590(Unk_362360_T* self) {
    Unk_SetVtable(self, Unk_2380be8);
    Unk_362360(self);
    operator delete(self);
}

static inline void Unk_362610_Dtor(Unk_3624a0_T* self) {
    Unk_SetVtable(self, Unk_2380c28);
    Unk_3624a0_Term(self);
    Unk_SetVtable(self, Unk_2380be8);
    Unk_362360(self);
}

// 0x7100362610
void Unk_362610(Unk_3624a0_T* self) {
    Unk_362610_Dtor(self);
}

// 0x7100362680
void Unk_362680(Unk_3624a0_T* self) {
    Unk_362610_Dtor(self);
    operator delete(self);
}

// 0x7100361e80
template Unk_362360_Item*
Unk_GrowArray<Unk_362360_Item, Unk_PoolDefault, 2>::AddLast(const Unk_362360_Item&);

void Unk_361fa0(Unk_362360_T* self, u32 parameter, f32 value);

// 0x7100361c80
void Unk_361c80(Unk_362360_T* self, u32 a1, u32 a2, u32 parameter, u32 mode, f32 value) {
    if (self->field_8 == nullptr)
        return;
    Unk_362360_Sink* sink = reinterpret_cast<Unk_362360_Sink*>(self->field_8);
    if (mode == 1) {
        sink->vf2(parameter, &value, 4);
        return;
    }
    f32 total = mode == 3 ? 1.0f : 0.0f;
    auto found = self->field_48.End();
    for (auto it = self->field_48.Begin(); it != self->field_48.End(); ++it) {
        if ((*it).field_8 == parameter) {
            if ((*it).field_0 == a1 && (*it).field_4 == a2) {
                found = it;
                (*it).field_c = value;
            }
            if (mode != 4 || (*it).field_0 != 0)
                total = mode != 3 ? (*it).field_c + total : (*it).field_c * total;
        }
    }
    if (found == self->field_48.End()) {
        Unk_362360_Item item;
        item.field_0 = a1;
        item.field_4 = a2;
        item.field_8 = parameter;
        item.field_c = value;
        if (self->field_48.AddLast(item) != nullptr)
            total = mode != 3 ? value + total : value * total;
    }
    reinterpret_cast<Unk_362360_Sink*>(self->field_8)->vf2(parameter, &total, 4);
}

// 0x71003625d0
void Unk_3625d0(Unk_362360_T* self, u32 parameter, u32 a2, u32 mode, f32 value) {
    Unk_361c80(self, 1, a2, parameter, mode, value);
}

// 0x71003625f0
void Unk_3625f0(Unk_362360_T* self, u32 parameter, u32 a2, u32 mode, f32 value) {
    Unk_361c80(self, 1, a2, parameter, mode, value);
}

// 0x7100360ba0
void Unk_360ba0(void* self_) {
    Unk_360c20_T* self = static_cast<Unk_360c20_T*>(self_);
    for (Unk_362360_T* p = self->field_70.field_0; p != nullptr; p = p->field_58) {
        p->field_48.field_8 = 0;
        if (p->field_10 != nullptr) {
            for (auto it = p->field_10->field_60.Begin(); it != p->field_10->field_60.End(); ++it) {
                if ((*it).field_2)
                    Unk_361fa0(p, (*it).field_0, (*it).field_4);
            }
        }
    }
}

// 0x7100362bf0
void Unk_362bf0(Unk_2380c68* base, u16 parameter, u32 mode, u32 a3, f32, f32 value) {
    Unk_360c20_T* self = &static_cast<Unk_360c20_T&>(*base);
    for (Unk_362360_T* p = self->field_70.field_0; p != nullptr; p = p->field_58)
        Unk_361c80(p, 2, a3, parameter, mode, value);
}

void Unk_39b150(void* self, Unk_362360_T* owner, u32 a2, u8 a3, u8 a4, u32 parameter, u32 a6,
                u32 scaling, const Unk_35f3b0_Point* points, u32 count, u64* a10, u32 a11,
                bool a12);

// What says whose parameter a notification is about (as Unk_237ff98.h has
// it).
struct Unk_NodeTarget {
    void* field_0;
    u64 field_8;
    u32 field_10;
    u32 field_14;
};
extern void* Unk_24bbc18;
void Unk_377930(void* self, Unk_NodeTarget* target, void* a2, void* a3);

// The two values after the ID are bytes by the name the function has; here
// they are widened where they are read, as for parameters of 32 bits.
static inline void Unk_39b150_Wide(void* self, Unk_362360_T* owner, u32 a2, u32 a3, u32 a4,
                                   u32 parameter, u32 a6, u32 scaling,
                                   const Unk_35f3b0_Point* points, u32 count, u64* key, u32 a11,
                                   bool a12) {
    reinterpret_cast<void (*)(void*, Unk_362360_T*, u32, u32, u32, u32, u32, u32,
                              const Unk_35f3b0_Point*, u32, u64*, u32, bool)>(Unk_39b150)(
        self, owner, a2, a3, a4, parameter, a6, scaling, points, count, key, a11, a12);
}

// Registers the object for every parameter of its target that follows a
// game parameter, with `key` for what its values are looked up by.
static inline void Unk_361770_Register(Unk_362360_T* self, u64* key) {
    Unk_360c20_T* target = self->field_10;
    if (target == nullptr)
        return;
    for (auto it = target->field_50.Begin(); it != target->field_50.End(); ++it)
        Unk_39b150_Wide(Unk_24bbbf8, self, (*it).field_0, (*it).field_4, (*it).field_5,
                        (*it).field_6, (*it).field_8, (*it).field_10.field_c,
                        (*it).field_10.field_0, (*it).field_10.field_8, key, 1, true);
    memcpy(&self->field_18, key, 0x30);
}

// 0x7100361770
void Unk_361770(Unk_362360_T* self, Unk_369950_Sound* sound) {
    Unk_361770_Register(self, sound->field_10);
    if (self->field_10 == nullptr)
        return;
    Unk_NodeTarget node;
    node.field_0 = self;
    node.field_10 = 1;
    node.field_14 = 0;
    Unk_361770_Params params;
    node.field_8 = sound->field_148;
    sound->vf9(&params, 1);
    params.field_20 = 0;
    Unk_360c20_T* target = self->field_10;
    for (auto it = target->field_50.Begin(); it != target->field_50.End(); ++it) {
        if ((*it).field_4 == 2)
            Unk_377930(Unk_24bbc18, &node, &params, sound->field_50);
    }
}

// 0x7100361900
void Unk_361900(Unk_362360_T* self, void* a1, void* a2) {
    u64* key = static_cast<u64*>(a1);
    Unk_361770_Register(self, key);
    Unk_360c20_T* target = self->field_10;
    if (target == nullptr)
        return;
    u64 first = *key;
    Unk_NodeTarget node;
    node.field_0 = self;
    node.field_8 = 0;
    node.field_10 = 1;
    node.field_14 = 2;
    Unk_361770_Params params;
    params.field_0 = first;
    for (auto it = target->field_50.Begin(); it != target->field_50.End(); ++it) {
        if ((*it).field_4 == 2)
            Unk_377930(Unk_24bbc18, &node, &params, a2);
    }
}

bool Unk_362160(Unk_362360_T* self, u32 parameter, u32 mode, f32* total);

// 0x7100361a70: gives the parameters object the total of every parameter the
// target has values of.
void Unk_361a70(Unk_362360_T* self) {
    Unk_361410_A* a = self->field_10->wf7();
    if (a == nullptr)
        return;
    u32 count = self->field_48.Length();
    for (Unk_361a70_Item* it = a->field_0; it != a->field_0 + a->field_8; ++it) {
        u32 parameter = it->field_0;
        u32 mode = it->field_2;
        f32 total = mode == 3 ? 1.0f : 0.0f;
        f32 own = total;
        bool other = false;
        for (u32 i = 0; i < count; i++) {
            Unk_362360_Item& item = self->field_48.field_0[i];
            if (item.field_8 == parameter) {
                if (mode == 3)
                    total *= item.field_c;
                else
                    total += item.field_c;
                if (item.field_0 == 0)
                    own = item.field_c;
                else
                    other = true;
            }
        }
        bool more = Unk_362160(self, parameter, mode, &total);
        if (mode == 4 && (other | more))
            total -= own;
        reinterpret_cast<Unk_362360_Sink*>(self->field_8)->vf2(parameter, &total, 4);
    }
}

// 0x7100361410: makes the object one of `target`, with room for its values:
// what it has of the target's parameters object, or null.
Unk_360c20_Params* Unk_361410(Unk_362360_T* self, Unk_360c20_T* target, Unk_369950_Sound* sound,
                              void* a3, void* a4, bool a5) {
    if (target->field_38 == nullptr)
        return self->field_8;
    self->field_8 = target->field_38->vf3(&Unk_2380d10);
    self->field_10 = target;
    if (self != nullptr) {
        target->field_70.AddFirst(self);
        target->vf2();
    }
    self->field_48.field_8 = 0;
    u32 count = self->field_10->field_60.Length();
    for (auto it = self->field_10->field_50.Begin(); it != self->field_10->field_50.End(); ++it) {
        if ((*it).field_5 != 1)
            count++;
    }
    Unk_361410_A* a = self->field_10->wf7();
    Unk_361410_B* b = self->field_10->wf16();
    if (a != nullptr && b != nullptr) {
        u32 n = 0;
        for (Unk_361410_Node* node = b->field_0; node != nullptr; node = node->field_10)
            n++;
        count += a->field_8 * n;
    }
    if (count != 0) {
        if (!self->field_48.Resize(count)) {
            self->vf5();
            return self->field_8;
        }
    }
    for (size_t i = 0; i < self->field_10->field_60.Length(); i++) {
        Unk_360c20_Value& value = self->field_10->field_60.field_0[i];
        Unk_362360_Item& item = self->field_48.field_0[i];
        item.field_8 = value.field_0;
        item.field_c = value.field_4;
    }
    if (sound != nullptr)
        Unk_361770(self, sound);
    else if (a5)
        Unk_361900(self, a3, a4);
    Unk_361a70(self);
    return self->field_8;
}

// 0x7100361400
Unk_360c20_Params* Unk_361400(Unk_362360_T* self, Unk_360c20_T* object, Unk_369950_Sound* sound) {
    return Unk_361410(self, object, sound, sound->field_10, nullptr, true);
}
