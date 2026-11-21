// Scope: common
// The second base of the Unk_360c20 classes (Unk_2380c68) and small classes
// next to it. Placeholder names.
#include "Unk_360c20.h"

void operator delete(void* ptr) noexcept;

void* Unk_3046a0(int poolId, size_t size, u32 alignment);
void Unk_304740(int poolId, void* ptr);
void Unk_3b3970(void* self);
void Unk_3b2860(Unk_2380c68* self, u32 a1);
void Unk_3b1cc0();
void Unk_3b1ce0(Unk_2380c68* self, u64 a1, u64 a2, u32 a3);
void Unk_3b1f90(Unk_2380c68* self);

extern void* _ZTV11Unk_2380c68[];

// What an Unk_2380c68 keeps of its states.
struct Unk_362a20_Value {
    u16 field_0;  // the parameter
    u8 field_2;
};
PKMN_SIZE_ASSERT(Unk_362a20_Value, 4);

struct Unk_362a20_States {
    u64 field_0;
    Unk_GrowArray<Unk_362a20_Value> field_8;

    Unk_362a20_States() : field_0(0) {
        field_8.field_0 = nullptr;
        field_8.field_8 = 0;
        field_8.field_c = 0;
    }
    ~Unk_362a20_States() {
        field_0 = 0;
        field_8.Term();
    }
};
PKMN_SIZE_ASSERT(Unk_362a20_States, 0x18);

static inline Unk_362a20_States*& Unk_362a20_Get(Unk_2380c68* self) {
    return *reinterpret_cast<Unk_362a20_States**>(&self->field_10);
}

// 0x7100362a20
void Unk_362a20(void* self_) {
    Unk_2380c68* self = static_cast<Unk_2380c68*>(self_);
    Unk_SetVtable(self, _ZTV11Unk_2380c68);
    if (Unk_362a20_Get(self) != nullptr) {
        if (Unk_362a20_Get(self)->field_0 != 0) {
            Unk_3b3970(self);
            Unk_3b2860(self, 0);
        }
        Unk_Delete(Unk_362a20_Get(self));
        Unk_362a20_Get(self) = nullptr;
    }
    reinterpret_cast<void (*)(Unk_2380c68*)>(Unk_3b1cc0)(self);
}

// 0x7100362710
void* Unk_362710(Unk_2380c68* self) {
    Unk_362a20_States* states = Unk_362a20_Get(self);
    return states != nullptr ? &states->field_8 : nullptr;
}

// 0x7100362af0
bool Unk_362af0(Unk_2380c68* self) {
    if (Unk_362a20_Get(self) == nullptr)
        Unk_362a20_Get(self) = new (Unk_237e820) Unk_362a20_States;
    return Unk_362a20_Get(self) != nullptr;
}

// 0x7100362b40
void Unk_362b40(Unk_2380c68* base, u64 a1, u64 a2, bool a3) {
    Unk_360c20_T* self = &static_cast<Unk_360c20_T&>(*base);
    Unk_3b1ce0(base, a1, a2, 0);
    Unk_362a20_States* states = Unk_362a20_Get(base);
    if (states == nullptr)
        return;
    for (auto it = states->field_8.Begin(); it != Unk_362a20_Get(base)->field_8.End(); ++it) {
        for (auto value = self->field_60.Begin(); value != self->field_60.End(); ++value) {
            if ((*value).field_0 == (*it).field_0) {
                (*value).field_2 = (*it).field_2;
                break;
            }
        }
    }
    if (a3)
        Unk_3b1f90(base);
}

// An allocator on a memory pool.
struct Unk_362c90_T {
    virtual void vf0();
    virtual void vf1();
    virtual void* vf2(size_t size);
    virtual void vf3(void* ptr);

    int field_8;
};

// 0x7100362c90
void* Unk_362c90(Unk_362c90_T* self, size_t size) {
    return Unk_3046a0(self->field_8, size, 0x10);
}

// 0x7100362ca0
void Unk_362ca0(Unk_362c90_T* self, void* ptr) {
    Unk_304740(self->field_8, ptr);
}

// 0x7100362cc0
void Unk_362cc0(Unk_Indexed** self) {
    Unk_Delete(*self);
    *self = nullptr;
}

// An object with two buffers and an owner (0x7102380d70).
struct Unk_362ea0_Owner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_362f80_Point {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_SIZE_ASSERT(Unk_362f80_Point, 0x10);

struct Unk_362f80_List {
    Unk_362f80_Point* field_0;
    s32 field_8;  // number of points
    u8 _c[0xc];
};
PKMN_SIZE_ASSERT(Unk_362f80_List, 0x18);

struct Unk_362ea0_T {
    void** field_0;
    u8 _8[0x20];
    u32 field_28;
    u32 field_2c;
    void* field_30;
    u32 field_38;
    Unk_362f80_List* field_40;
    u32 field_48;
    u8 field_4c_0 : 6;
    u8 field_4c_6 : 1;
    u8 field_4c_7 : 1;
    Unk_362ea0_Owner* field_50;
};
PKMN_OFFSET_ASSERT(Unk_362ea0_T, field_50, 0x50);

extern void* Unk_2380d70[];
extern void* Unk_24bbbf0;
void Unk_38adb0_call(void* self, void* a1, unsigned long lists, u32 count, u32 a4, bool a5,
                     void* a6);

// 0x7100362ea0
void Unk_362ea0(Unk_362ea0_T* self) {
    Unk_SetVtable(self, Unk_2380d70);
    if (self->field_50 != nullptr)
        self->field_50->vf3();
}

// 0x7100362ed0
void Unk_362ed0(Unk_362ea0_T* self) {
    Unk_SetVtable(self, Unk_2380d70);
    if (self->field_50 != nullptr)
        self->field_50->vf3();
    operator delete(self);
}

// 0x7100362f20
void Unk_362f20(Unk_362ea0_T* self) {
    if (self->field_30 != nullptr) {
        Unk_3047c0(Unk_237e820, self->field_30);
        self->field_30 = nullptr;
    }
    if (self->field_40 != nullptr) {
        Unk_3047c0(Unk_237e820, self->field_40);
        self->field_40 = nullptr;
    }
    self->field_38 = 0;
    self->field_48 = 0;
}

// 0x7100362f80
void Unk_362f80(Unk_362ea0_T* self, u32 value) {
    self->field_2c = value;
    for (u32 i = 0; i < self->field_48; i++) {
        s32 last = self->field_40[i].field_8 - 1;
        if (last >= 0)
            self->field_40[i].field_0[last].field_c = self->field_2c;
    }
}

// 0x7100362fd0
void Unk_362fd0(Unk_362ea0_T* self, void* a1, void* a2) {
    Unk_38adb0_call(Unk_24bbbf0, a1, reinterpret_cast<unsigned long>(self->field_40),
                    self->field_48, self->field_28, self->field_4c_6, a2);
}
