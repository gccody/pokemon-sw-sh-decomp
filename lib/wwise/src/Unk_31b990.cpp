// Scope: common
// The destructors of the classes of vtables 0x710237dbc8 and 0x710237dd38
// (Unk_31b990.h), the second one's constructor, and slots of the first.
// Placeholder names.
#include <types.h>

#include "Unk_31b990.h"

extern u32 Unk_2382e68;  // samples in a second

void Unk_308aa0(void* self);
void* Unk_319500(void* self, u64 a1, Unk_310160_T* a2);
void Unk_30b6c0(void* self, u32 a1, u32 a2, u32 a3);

// What slot 18 takes.
struct Unk_31bb90_Arg {
    u32 field_0;
    bool field_4;
    u32 field_8;
};

// The first class's slot 18, as Unk_31bb90 calls it.
class Unk_31bb90_Self {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u32 vf18(void* a1, Unk_31bb90_Arg* arg, void* out, s32* a4, u32 a5, u32 a6);
};

// 0x710031b990: the destructor of the class of vtable 0x710237dbc8 (slot 10)
void Unk_31b990(void* object) {
    Unk_31b990_T* self = static_cast<Unk_31b990_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dbc8);
    if (self->field_90 != nullptr)
        self->field_90->vf3();
    Unk_3191e0(self);
}

// 0x710031b9f0: the destructor through the vptr at 0x18
void Unk_31b9f0(void* object) {
    Unk_31b990(static_cast<u8*>(object) - 0x18);
}

// 0x710031ba50: the deleting destructor (slot 11)
void Unk_31ba50(void* object) {
    Unk_31b990(object);
    operator delete(object);
}

// 0x710031bab0: the deleting destructor through the vptr at 0x18
void Unk_31bab0(void* object) {
    Unk_31ba50(static_cast<u8*>(object) - 0x18);
}

// 0x710031c020: the constructor of the class of vtable 0x710237dd38
void Unk_31c020(Unk_310160_T* object, Unk_237c170* node, void* a2) {
    Unk_319190(object, a2);
    Unk_31c020_T* self = reinterpret_cast<Unk_31c020_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dd38);
    self->field_90 = node;
    Unk_3168a0(&self->field_98, node);
    self->field_e0 = true;
    if (self->field_90 != nullptr)
        self->field_90->vf2();
}

// 0x710031c0a0: its destructor (slot 10)
void Unk_31c0a0(void* object) {
    Unk_31c020_T* self = static_cast<Unk_31c020_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dd38);
    Unk_316c50(&self->field_98);
    if (self->field_90 != nullptr)
        self->field_90->vf3();
    Unk_3168d0_update(reinterpret_cast<u64>(&self->field_98));
    Unk_3191e0(self);
}

// 0x710031c110: the destructor through the vptr at 0x18
void Unk_31c110(void* object) {
    Unk_31c0a0(static_cast<u8*>(object) - 0x18);
}

// 0x710031c190: the deleting destructor (slot 11)
void Unk_31c190(void* object) {
    Unk_31c0a0(object);
    operator delete(object);
}

// 0x710031bb90
u32 Unk_31bb90(void* object, u64 a1, u64 a2, u32 position, void* out, bool a5) {
    Unk_31b990_T* self = static_cast<Unk_31b990_T*>(object);
    *static_cast<s32*>(out) = 0;
    if (static_cast<s32>(Unk_30ea20(Unk_31b990_Node(self)) + Unk_30ea00(Unk_31b990_Node(self))) <= static_cast<s32>(position))
        return 2;
    Unk_310160_T* source =
        Unk_31b990_Node(self)->Unk_30e1a0(self, reinterpret_cast<void*>(a1), reinterpret_cast<void*>(a2), a5 & 1);
    if (source == nullptr)
        return 2;
    void* added = Unk_319500(self, 0, source);
    Unk_308aa0(source);
    if (added == nullptr)
        return 2;
    self->field_68 = 0;
    s32 unused;
    Unk_31bb90_Arg arg;
    arg.field_0 = position;
    arg.field_4 = false;
    arg.field_8 = 0;
    if (reinterpret_cast<Unk_31bb90_Self*>(self)->vf18(nullptr, &arg, out, &unused, 0, 0) == 0)
        return 2;
    Unk_30b6c0(added, 0, 4, Unk_30ea20(Unk_31b990_Node(self)) + Unk_30ea00(Unk_31b990_Node(self)));
    return Unk_319500(self, Unk_30ea20(Unk_31b990_Node(self)), nullptr) != nullptr ? 1 : 2;
}

// 0x710031bce0: slot 26, to a position in milliseconds (rounded to the
// position it goes to when `snap`)
u32 Unk_31bce0(Unk_31b990_T* self, s32* ms, bool snap) {
    s32 position = static_cast<s64>(*ms) * Unk_2382e68 / 1000;
    if (position < -static_cast<s32>(Unk_30e9f0(reinterpret_cast<u64>(Unk_31b990_Node(self)))))
        position = -Unk_30e9f0(reinterpret_cast<u64>(Unk_31b990_Node(self)));
    if (snap) {
        position = Unk_30ec40(Unk_31b990_Node(self), position);
        f64 value = position * 1000.0 / Unk_2382e68;
        *ms = static_cast<s32>(value + (value > 0.0 ? 0.5 : -0.5));
    }
    return Unk_31bdc0(self, position);
}

// 0x710031beb0: slot 27, to a position as a fraction of the length
u32 Unk_31beb0(Unk_31b990_T* self, f32* fraction, bool snap) {
    s32 position = *fraction * Unk_30ea20(Unk_31b990_Node(self));
    if (snap) {
        position = Unk_30ec40(Unk_31b990_Node(self), position);
        *fraction = static_cast<f32>(position) / Unk_30ea20(Unk_31b990_Node(self));
    }
    return Unk_31bdc0(self, position);
}

// What slot 28 builds on the stack.
struct Unk_319150_T {
    struct Item {
        u8 _0[0x18];
        void* field_18;
    }* field_0;
    void* field_8;
};

struct Unk_3187b0_T {
    u8 _0[0x108];
    Unk_319150_T field_108;
    u8 _118[0x18];
};
PKMN_OFFSET_ASSERT(Unk_3187b0_T, field_108, 0x108);
PKMN_SIZE_ASSERT(Unk_3187b0_T, 0x130);

void Unk_3187b0(Unk_3187b0_T* self, void* object, bool a2);
void Unk_318820_update(void* self);
u64 Unk_3190a0(Unk_3187b0_T* self, u32 index);
u64 Unk_319150(Unk_319150_T* self, u64 position);
u64 Unk_30b050(void* self);
u32 Unk_30b300(Unk_319150_T::Item* self, u32 position, void* a2, f32 a3);

// NON_MATCHING: register allocation: the original computes the address of
// the state's member at 0x108 where it is used, and the time after the test;
// here the stack pointer is kept in a register from the start.
// 0x710031bf30: slot 28
u32 Unk_31bf30(Unk_31b990_T* self, void* a1) {
    Unk_3187b0_T state;
    Unk_3187b0(&state, self, true);
    u32 result;
    Unk_319150_T::Item* item = state.field_108.field_0;
    if (item != nullptr) {
        u64 start = self->field_60->field_8;
        u64 base = Unk_30b050(self);
        u32 offset = 0;
        if (state.field_108.field_0->field_18 != nullptr)
            offset = Unk_319150(&state.field_108, start - base - Unk_3190a0(&state, 0));
        result = Unk_30b300(item, offset, a1, self->field_60->field_4c);
    } else {
        result = 2;
    }
    Unk_318820_update(&state);
    return result;
}
