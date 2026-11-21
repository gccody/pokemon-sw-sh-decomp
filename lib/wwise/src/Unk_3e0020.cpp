// Scope: common
// A source whose samples an effect makes (on the class of 0x7102384dd0):
// the effect at 0xf0, an array of what it was given at 0x78 and a buffer at
// 0x38. Written from the executable. Placeholder names.
#include "Unk_FastMath.h"
#include "Unk_3dd7b0.h"
#include "containers.h"

struct Unk_390500;
void Unk_390500_call(Unk_390500* self);
u32 Unk_304740(int poolId, void* ptr);
u32 Unk_3ddc60(Unk_3dd7b0_T* self, u32* count);

// The effect.
struct Unk_3e0020_Plugin {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* alloc);
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual f32 vf8();
    virtual f32 vf9();
    virtual u32 vf10();
    virtual void vf11();
    virtual u32 vf12(u32* count);
};

// What the effect was given: 0x20 bytes.
struct Unk_3e0020_Item {
    u64 field_0;
    void* field_8;
    u64 field_10;
    void* field_18;
};

bool Unk_3c99e0(void* key, void** arg1, Unk_3e0020_Plugin* plugin);

// What an effect starts with (vtable 0x7102380be8): 0x68 bytes.
struct Unk_3dfec0_Base {
    void* const* field_0;  // vptr
    u8 _8[0x60];
};
PKMN_SIZE_ASSERT(Unk_3dfec0_Base, 0x68);

// With the effect after it.
struct Unk_3dfec0_T : Unk_3dfec0_Base {
    Unk_3e0020_Plugin* field_68;
};
PKMN_SIZE_ASSERT(Unk_3dfec0_T, 0x70);

struct Unk_3e0020_T {
    void** field_0;  // vptr
    u8 _8[0x20];
    void** field_28;  // the second and third tables of functions
    void** field_30;
    void* field_38;  // samples
    u8 _40[0x30];
    // 24 bits of flags.
    struct __attribute__((packed)) {
        u32 field_70_0 : 18;
        u32 field_70_18 : 1;
        u32 field_70_19 : 5;
    };
    u8 _73[5];
    Unk_Array<Unk_3e0020_Item> field_78;
    // What the effect starts with and the effect: two members here (the
    // address of the first is computed where it is passed on).
    Unk_3dfec0_Base field_88;
    Unk_3e0020_Plugin* field_f0;
};
PKMN_OFFSET_ASSERT(Unk_3e0020_T, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_3e0020_T, field_88, 0x88);

struct Unk_362360_T;
struct Unk_3c9550_Item;
extern void* Unk_2380d10;
extern void* const Unk_2380be8[8];
extern void* Unk_23852e8[];
void Unk_362360(Unk_362360_T* self);
void Unk_3c9550(Unk_Array<Unk_3c9550_Item, Unk_PoolDefault>* self);

static inline void Unk_3e0020_FreeSamples(Unk_3e0020_T* self) {
    if (self->field_38 != nullptr) {
        if (self->field_70_18) {
            Unk_390500_call(reinterpret_cast<Unk_390500*>(&self->field_38));
        } else {
            Unk_304740(Unk_2381488, self->field_38);
            self->field_38 = nullptr;
        }
    }
}

// The effect goes, and what it started with is told.
static inline void Unk_3dfe70_Term(Unk_3e0020_T* self) {
    if (self->field_f0 != nullptr) {
        self->field_f0->vf2(&Unk_2380d10);
        self->field_f0 = nullptr;
    }
    Unk_362360(reinterpret_cast<Unk_362360_T*>(&self->field_88));
}

// The destructor: the function at 3 of the table (0x71003e0020) is called
// as this class's own.
static inline void Unk_3df910_Dtor(Unk_3e0020_T* self) {
    self->field_0 = Unk_23852e8 + 2;
    self->field_28 = Unk_23852e8 + 0x3c;
    self->field_30 = Unk_23852e8 + 0x4f;
    Unk_3e0020_FreeSamples(self);
    Unk_3dfe70_Term(self);
    self->field_88.field_0 = Unk_2380be8 + 2;
    reinterpret_cast<void (*)(Unk_3dfec0_Base*)>(Unk_2380be8[7])(&self->field_88);
    Unk_3c9550(reinterpret_cast<Unk_Array<Unk_3c9550_Item, Unk_PoolDefault>*>(&self->field_78));
}

// 0x71003df910
void Unk_3df910(Unk_3e0020_T* self) {
    Unk_3df910_Dtor(self);
}

// 0x71003df9e0: the same from the second table of functions (the object's
// address is a number less, as the bus's from its second base)
void Unk_3df9e0(void* self) {
    Unk_3df910_Dtor(reinterpret_cast<Unk_3e0020_T*>(reinterpret_cast<u64>(self) - 0x28));
}

// 0x71003dfab0: and from the third
void Unk_3dfab0(void* self) {
    Unk_3df910_Dtor(reinterpret_cast<Unk_3e0020_T*>(reinterpret_cast<u64>(self) - 0x30));
}

// 0x71003dfb80: the deleting destructor
void Unk_3dfb80(void* arg) {
    Unk_3e0020_T* self = static_cast<Unk_3e0020_T*>(arg);
    Unk_3df910_Dtor(self);
    operator delete(self);
}

// 0x71003dfe70
void Unk_3dfe70(Unk_3e0020_T* self) {
    reinterpret_cast<Unk_3dd7b0_T*>(self)->vf3();
    Unk_3dfe70_Term(self);
}

// 0x71003dfec0
void Unk_3dfec0(Unk_3dfec0_T* self) {
    if (self->field_68 != nullptr) {
        self->field_68->vf2(&Unk_2380d10);
        self->field_68 = nullptr;
    }
    Unk_362360(reinterpret_cast<Unk_362360_T*>(self));
}

// 0x71003e0020: its samples go
void Unk_3e0020(Unk_3e0020_T* self) {
    Unk_3e0020_FreeSamples(self);
}

// 0x71003e0080
void Unk_3e0080(Unk_3e0020_T* self, u32 arg1) {
    if (arg1 == 0 && self->field_f0 != nullptr)
        self->field_f0->vf3();
}

// 0x71003e00a0
u32 Unk_3e00a0(Unk_3e0020_T* self, u32* count) {
    if (self->field_f0 == nullptr)
        return 0x2d;
    u32 result = self->field_f0->vf12(count);
    if (result != 0)
        return result;
    return Unk_3ddc60(reinterpret_cast<Unk_3dd7b0_T*>(self), count);
}

// 0x71003e0100
f32 Unk_3e0100(Unk_3e0020_T* self) {
    if (self->field_f0 != nullptr)
        return self->field_f0->vf8();
    return 0.0f;
}

// 0x71003e01c0
u32 Unk_3e01c0(Unk_3e0020_T* self) {
    if (self->field_f0 != nullptr)
        return self->field_f0->vf10();
    return 2;
}

// 0x71003e02d0
bool Unk_3e02d0(Unk_3e0020_T* self, void* key) {
    for (auto it = self->field_78.Begin(); it != self->field_78.End(); ++it) {
        if ((*it).field_18 == key && !Unk_3c99e0(key, &(*it).field_8, self->field_f0))
            return true;
    }
    return false;
}

// 0x71003e0360: whether an item has `key`
bool Unk_3e0360(Unk_3e0020_T* self, void* key) {
    for (auto it = self->field_78.Begin(); it != self->field_78.End(); ++it) {
        if ((*it).field_8 == key)
            return true;
    }
    return false;
}

// 0x71003e0120
f32 Unk_3e0120(Unk_3e0020_T* self) {
    if (self->field_f0 == nullptr)
        return 0.0f;
    return Unk_ToDecibels(self->field_f0->vf9());
}
