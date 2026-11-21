// Scope: common
// A bus of the lower engine: what its effects and its second base (0xc0)
// ask it. The second base's functions are the bus's own ones again.
// Written from the executable. Placeholder names.
#include "Unk_24df148.h"
#include "Unk_Indexed.h"

#include <string.h>

// The work memory of 0x71003c0e30 and where it comes from.
struct Unk_3c0e30_Alloc {
    virtual void vf0();
    virtual void vf1();
    virtual void* vf2(u64 size);  // allocates
    virtual void vf3(void* ptr);  // frees
};
struct Unk_3c0e30_T {
    u8 field_0[0x60];
};

// The bus's node, a number and a counted object: 0x18 bytes at 0x70.
struct Unk_3ca240_T;

extern void* Unk_23844d0[];

u64 Unk_369930_get(const Unk_369930* self);
void Unk_356bc0(Unk_24df148_Node* self, u32 key, u32* result);
void Unk_368ee0(u32 arg0, u64 arg1, u32 arg2, void** buffer, u32* size);
u32 Unk_37b3e0(Unk_37d6b0_T* self, u64 arg1, u64 arg2, u64 arg3);
void Unk_3ad110(Unk_24df148_Config arg0, Unk_24df148_Config arg1, void* arg2);
u32 Unk_3b1200(Unk_37d6b0_T* self, f32 arg1, Unk_24df148_Config arg2, f32 arg3, void* arg4);
u32 Unk_3c0e30(Unk_3c0e30_T* self, Unk_3c0e30_Alloc* alloc, u32 count);
void Unk_3c0fb0(Unk_3c0e30_T* self, Unk_3c0e30_Alloc* alloc);
void Unk_3c10c0(Unk_3c0e30_T* self, void* arg1, u32 arg2);
void Unk_3c1450(void* arg0, u32 arg1, void* arg2);
Unk_24df148_Value* Unk_3c9600(Unk_KeyArray<u32, Unk_24df148_Value>* self, u32 key, u32 id);
void Unk_3ca400(Unk_3ca240_T* self, u32 key, u32* result);
void Unk_3cfa80(Unk_24df148_Bus* self);
void Unk_3d2050(Unk_24df148_Bus* self);
void Unk_3d23e0(Unk_24df148_Bus* self);
void Unk_3d4470(Unk_24df148_Bus* self);

extern void* Unk_2380d10;  // what the effects are created from and freed to
extern void* const Unk_2380be8[8];
extern void* const Unk_23842a8[];
struct Unk_3c9550_Item;
void Unk_3c9550(Unk_Array<Unk_3c9550_Item, Unk_PoolDefault>* self);
void Unk_3cf7b0(void* self);

// 0x71003d1930: the bus has no effects any more. (The effect is named anew
// at each use: its address is computed where its function is called, and
// the first one's is then the base of what follows in that block.)
void Unk_3d1930(Unk_24df148_Bus* bus) {
    for (u32 i = 0; i < 4; i++) {
        if (bus->field_c8[i].field_68 != nullptr) {
            bus->field_c8[i].field_68->vf2(&Unk_2380d10);
            bus->field_c8[i].field_68 = nullptr;
        }
        Unk_24df148_Object* object = bus->field_c8[i].field_70;
        if (object != nullptr) {
            int pool = Unk_2381488;
            object->vf0();
            Unk_3047c0(pool, object);
            bus->field_c8[i].field_70 = nullptr;
        }
        Unk_24df148_SlotCtx& ctx = bus->field_c8[i].field_0;
        ctx.field_60 = 0xffffffff;
        ctx.vf5();
        bus->field_2c8[i].Free();
    }
    bus->field_344_0 = 0;
    bus->field_344_1 = 0;
}

static inline void Unk_2380be8_Dtor(Unk_24df148_SlotCtx* self) {
    *reinterpret_cast<void* const**>(self) = Unk_2380be8 + 2;
    reinterpret_cast<void (*)(Unk_24df148_SlotCtx*)>(Unk_2380be8[7])(self);
}

// 0x71003d17f0: the destructor of the class under the bus
void Unk_3d17f0(void* arg) {
    Unk_24df148_Bus* self = static_cast<Unk_24df148_Bus*>(arg);
    self->field_0 = const_cast<void**>(Unk_23842a8) + 2;
    self->field_c0.field_0 = const_cast<void**>(Unk_23842a8) + 0x2d;
    Unk_3d1930(self);
    if (self->field_328 != nullptr) {
        if (self->field_328->field_60 != nullptr) {
            self->field_328->field_60->vf2(&Unk_2380d10);
            self->field_328->field_60 = nullptr;
        }
        self->field_328->vf5();
        self->field_328->field_68 = 0xffffffff;
        Unk_24df148_Fx* fx = self->field_328;
        if (fx != nullptr) {
            int pool = Unk_2381488;
            fx->vf0();
            Unk_3047c0(pool, fx);
        }
    }
    Unk_24df148_Object* meter = self->field_a8;
    if (meter != nullptr) {
        int pool = Unk_2381488;
        meter->vf0();
        Unk_3047c0(pool, meter);
        self->field_a8 = nullptr;
    }
    Unk_3c9550(reinterpret_cast<Unk_Array<Unk_3c9550_Item, Unk_PoolDefault>*>(&self->field_330));
    // An array's destructors are a loop: the function they call is read
    // once, before the first one.
    for (s32 i = 3; i >= 0; i--)
        Unk_2380be8_Dtor(&self->field_c8[i].field_0);
    Unk_3cf7b0(self);
}

// 0x71003d14e0
void Unk_3d14e0(void* arg, u32* arg1, u32* arg2) {
    Unk_24df148_Bus* self = static_cast<Unk_24df148_Bus*>(arg);
    *arg2 = 0xffffffff;
    *arg1 = 0xffffffff;
    Unk_37d6b0_T* found = Unk_37d6b0(&self->field_70);
    if (found != nullptr)
        found->vf4(arg1, arg2);
}

// 0x71003d1540: whether everything that plays into the bus has the two bits
bool Unk_3d1540(Unk_24df148_Bus* self, bool& arg1, bool& arg2) {
    arg1 = true;
    arg2 = true;
    for (Unk_369930* item = self->field_48; item != nullptr; item = item->field_40) {
        arg2 = arg2 && item->field_2a4_1;
        arg1 = arg1 && item->field_2a4_0;
    }
    return !arg1 || !arg2;
}

// Whether an effect is used or not (a number): the bus knows that it
// changed before the number is stored.
static inline void Unk_3d2290_Set(Unk_24df148_Bus* bus, u16& field, u16 value) {
    bus->field_344_1 = (value != 0) != (field != 0);
    field = value;
    if (bus->field_344_1 && bus->field_20 != nullptr)
        bus->field_20->field_120 = 101.0f;
}

// 0x71003d2290: which effects are not used (and whether none is)
void Unk_3d2290(Unk_24df148_Bus* bus, u32 bits, u32 mask) {
    for (u32 i = 0; i < 4; i++) {
        if (mask & (1 << i))
            Unk_3d2290_Set(bus, bus->field_c8[i].field_78, (bits >> i) & 1);
    }
    if (mask & 0x10)
        Unk_3d2290_Set(bus, bus->field_340, (bits >> 4) & 1);
}

// 0x71003d2b60: the channels of what the last used effect gives
Unk_24df148_Config Unk_3d2b60(Unk_24df148_Bus* self) {
    Unk_24df148_Config result = self->field_88.GetConfig();
    if (self->field_340 == 0) {
        for (s32 i = 3; i >= 0; i--) {
            if (self->field_c8[i].field_78 == 0 && self->field_2c8[i].field_0 != nullptr) {
                result = self->field_2c8[i].GetConfig();
                break;
            }
        }
    }
    return result;
}

// 0x71003d2be0
u32 Unk_3d2be0(Unk_24df148_Bus* self, u32* arg1, u32* arg2) {
    *arg2 = 0xffffffff;
    *arg1 = 0xffffffff;
    Unk_37d6b0_T* found = Unk_37d6b0(&self->field_70);
    if (found != nullptr)
        found->vf4(arg1, arg2);
    return 1;
}

// 0x71003d2c80: what the bus has for a key
void Unk_3d2c80(Unk_24df148_Bus* self, u32 key, u64* result1, u32* result2) {
    Unk_24df148_Value* value = self->field_330.Exists(key);
    if (value == nullptr) {
        u32 id = 0xffffffff;
        Unk_3ca400(reinterpret_cast<Unk_3ca240_T*>(&self->field_70), key, &id);
        if (id != 0xffffffff)
            value = Unk_3c9600(&self->field_330, key, id);
    }
    if (value != nullptr) {
        *result2 = value->field_8;
        *result1 = value->field_0;
    } else {
        *result1 = 0;
        *result2 = 0;
    }
}

// 0x71003d2d60
void Unk_3d2d60(Unk_24df148_Sub* self, u32 key, u64* result1, u32* result2) {
    Unk_3d2c80(Unk_24df148_Outer(self), key, result1, result2);
}

// 0x71003d2e40
void Unk_3d2e40(Unk_24df148_Bus* self, u64 arg1, u64 arg2) {
    u32 id;
    u64 number;
    if (self->field_70.field_0 != nullptr) {
        id = self->field_70.field_0->field_10;
        number = self->field_78;
    } else {
        id = 0;
        number = 0xffffffffffffffff;
    }
    Unk_368ee0(id, number, self->field_328 != nullptr ? self->field_328->vf2() : 0xffffffff,
               reinterpret_cast<void**>(arg1), reinterpret_cast<u32*>(arg2));
}

// 0x71003d2ec0
void Unk_3d2ec0(Unk_24df148_Sub* self, u64 arg1, u64 arg2) {
    Unk_3d2e40(Unk_24df148_Outer(self), arg1, arg2);
}

// 0x71003d2f40: the same for one of the four effects
void Unk_3d2f40(void* arg0, u32 index, u64 arg1, u64 arg2) {
    Unk_24df148_Bus* self = static_cast<Unk_24df148_Bus*>(arg0);
    u64 number;
    u32 id;
    if (self->field_70.field_0 != nullptr) {
        number = self->field_78;
        id = self->field_70.field_0->field_10;
    } else {
        id = 0;
        number = 0xffffffffffffffff;
    }
    Unk_24df148_SlotCtx& ctx = self->field_c8[index].field_0;
    Unk_368ee0(id, number, ctx.vf2(), reinterpret_cast<void**>(arg1),
               reinterpret_cast<u32*>(arg2));
}

// 0x71003d3110: the channels of what plays into the bus
u32 Unk_3d3110(Unk_24df148_Bus* self, Unk_24df148_Config* result) {
    for (Unk_369930* item = self->field_48; item != nullptr; item = item->field_40) {
        u32 more = item->field_2a0;
        *result = reinterpret_cast<Unk_24df148_Bus*>(Unk_369930_get(item))->field_88.field_8;
        if (more == 0)
            break;
    }
    return result->field_0_0 != 0 ? 1 : 2;
}

// 0x71003d3170
u32 Unk_3d3170(Unk_24df148_Sub* self, Unk_24df148_Config* result) {
    return Unk_3d3110(Unk_24df148_Outer(self), result);
}

// 0x71003d31f0
u32 Unk_3d31f0(Unk_24df148_Bus* self, u64 arg1, u64 arg2, u64 arg3) {
    Unk_37d6b0_T* found = Unk_37d6b0(&self->field_70);
    if (found == nullptr)
        return 2;
    return Unk_37b3e0(found, arg1, arg2, arg3);
}

// 0x71003d3250
u32 Unk_3d3250(Unk_24df148_Sub* self, u64 arg1, u64 arg2, u64 arg3) {
    return Unk_3d31f0(Unk_24df148_Outer(self), arg1, arg2, arg3);
}

// With only one of the two pairs of channels behind (0x10 and 0x200 of the
// mask), a mask has the pair at 0x600.
static inline void Unk_3d32b0_Fix(Unk_24df148_Config& config) {
    if (config.field_0_8 == 1) {
        u32 mask = config.field_0_12;
        if (((mask & 0x10) != 0) != ((mask & 0x200) != 0))
            mask = (mask & ~0x630) | 0x600;
        config.field_0_12 = mask;
    }
}

// 0x71003d32b0
u32 Unk_3d32b0(Unk_24df148_Bus* self, Unk_24df148_Config arg1, Unk_24df148_Config arg2,
               void* arg3) {
    Unk_3d32b0_Fix(arg1);
    Unk_3d32b0_Fix(arg2);
    Unk_3ad110(arg1, arg2, arg3);
    return 1;
}

// 0x71003d3340
u32 Unk_3d3340(Unk_24df148_Sub* self, Unk_24df148_Config arg1, Unk_24df148_Config arg2,
               void* arg3) {
    return Unk_3d32b0(Unk_24df148_Outer(self), arg1, arg2, arg3);
}

// 0x71003d3530
u32 Unk_3d3530(Unk_24df148_Bus* self, f32 arg1, Unk_24df148_Config arg2, f32 arg3, void* arg4) {
    Unk_37d6b0_T* found = Unk_37d6b0(&self->field_70);
    if (found == nullptr)
        return 2;
    return Unk_3b1200(found, arg1, arg2, arg3, arg4);
}

// 0x71003d3590
u32 Unk_3d3590(Unk_24df148_Sub* self, f32 arg1, Unk_24df148_Config arg2, f32 arg3, void* arg4) {
    return Unk_3d3530(Unk_24df148_Outer(self), arg1, arg2, arg3, arg4);
}

// 0x71003d35f0: makes the work memory of 0x71003c0e30 (the memory is not
// typed until it is used: the result is what the allocator gave)
u32 Unk_3d35f0(Unk_24df148_Bus* self, Unk_3c0e30_Alloc* alloc, void* arg2, u32 count,
               void** result) {
    void* object = alloc->vf2(sizeof(Unk_3c0e30_T));
    if (object != nullptr) {
        memset(object, 0, sizeof(Unk_3c0e30_T));
        if (Unk_3c0e30(static_cast<Unk_3c0e30_T*>(object), alloc, count) == 1) {
            Unk_3c10c0(static_cast<Unk_3c0e30_T*>(object), arg2, count);
        } else {
            alloc->vf3(object);
            object = nullptr;
        }
    }
    *result = object;
    return object != nullptr ? 1 : 2;
}

// 0x71003d36b0
u32 Unk_3d36b0(Unk_24df148_Sub* self, Unk_3c0e30_Alloc* alloc, void* arg2, u32 count,
               void** result) {
    return Unk_3d35f0(Unk_24df148_Outer(self), alloc, arg2, count, result);
}

// 0x71003d3770
u32 Unk_3d3770(Unk_24df148_Bus* self, void* arg1, u32 arg2, void* arg3) {
    Unk_3c1450(arg1, arg2, arg3);
    return 1;
}

// 0x71003d37a0
u32 Unk_3d37a0(Unk_24df148_Sub* self, void* arg1, u32 arg2, void* arg3) {
    return Unk_3d3770(Unk_24df148_Outer(self), arg1, arg2, arg3);
}

// 0x71003d37d0: and destroys it
u32 Unk_3d37d0(Unk_24df148_Bus* self, Unk_3c0e30_Alloc* alloc, Unk_3c0e30_T* object) {
    Unk_3c0fb0(object, alloc);
    alloc->vf3(object);
    return 1;
}

// 0x71003d3810
u32 Unk_3d3810(Unk_24df148_Sub* self, Unk_3c0e30_Alloc* alloc, Unk_3c0e30_T* object) {
    return Unk_3d37d0(Unk_24df148_Outer(self), alloc, object);
}

// 0x71003d3f40
void Unk_3d3f40(Unk_24df148_Bus* self, u32 arg1) {
    self->field_b9_0 = arg1;
    Unk_3d23e0(self);
}

// 0x71003d3f50
void Unk_3d3f50(Unk_24df148_Sub* self, u32 arg1) {
    Unk_3d3f40(Unk_24df148_Outer(self), arg1);
}

// 0x71003d4310: the destructor
void Unk_3d4310(void* bus) {
    Unk_24df148_Bus* self = static_cast<Unk_24df148_Bus*>(bus);
    self->field_0 = Unk_23844d0 + 2;
    self->field_c0.field_0 = Unk_23844d0 + 0x2d;
    Unk_3cfa80(self);
    Unk_3d1930(self);
    if (self->field_20 != nullptr) {
        self->field_20->vf8(0);
        Unk_24df148_Mix* mix = self->field_20;
        if (mix != nullptr) {
            int pool = Unk_2381488;
            mix->vf0();
            Unk_3047c0(pool, mix);
        }
    }
    if (self->field_88.field_0 != nullptr) {
        Unk_304740(Unk_2381488, self->field_88.field_0);
        self->field_88.field_0 = nullptr;
    }
    Unk_3d17f0(self);
}

// 0x71003d4430
void Unk_3d4430(Unk_24df148_Bus* self) {
    Unk_3d4470(self);
    memset(self->field_88.field_0, 0,
           sizeof(f32) * self->field_88.field_10 * self->field_88.field_8.field_0_0);
}

static inline void Unk_3d4470_End(Unk_24df148_Bus* self, Unk_24df148_Buffer& buffer) {
    self->field_348 = buffer.field_c == 0x11 ? 4 : 1;
    buffer.field_c = 0x11;
    buffer.field_12 = 0;
}

// 0x71003d4470: nothing more comes out of the bus and its effects
void Unk_3d4470(Unk_24df148_Bus* self) {
    Unk_3d4470_End(self, self->field_88);
    if (self->field_340 == 0) {
        for (u32 i = 0; i < 4; i++) {
            if (self->field_c8[i].field_78 == 0 && self->field_2c8[i].field_0 != nullptr)
                Unk_3d4470_End(self, self->field_2c8[i]);
        }
    }
}

// 0x71003d4550
void Unk_3d4550(Unk_24df148_Bus* self, void* arg1) {
    if (self->field_328 != nullptr) {
        if (self->field_328->field_60 == nullptr && self->field_20 != nullptr)
            Unk_3d2050(self);
        if (self->field_328->field_60 != nullptr)
            self->field_328->field_60->vf8(arg1);
    }
    self->field_34c++;
}
