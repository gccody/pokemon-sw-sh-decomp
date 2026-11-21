// Scope: common
// What plays a source (vtable 0x7102384a98): the source, the object with
// the vtable 0x7102384248 at 0x1a0 and up to four effects at 0x350.
// Written from the executable. Placeholder names.
#include "Unk_2384190.h"
#include "Unk_2384858.h"
#include "Unk_2384c90.h"
#include "Unk_3dd7b0.h"
#include "Unk_PlacementNew.h"

// The object at 0x1a0, as far as it is called here.
struct Unk_2384a98_Member {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
};

// What a node gives for an effect: a counted object and whether the effect
// is not used.
struct Unk_3dbf80_Object {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
};
struct Unk_3dbf80_Ref {
    Unk_3dbf80_Object* field_0;
    u16 field_8;

    Unk_3dbf80_Ref() : field_0(nullptr) {}
    ~Unk_3dbf80_Ref() {
        if (field_0 != nullptr) {
            field_0->vf3();
            field_0 = nullptr;
        }
    }
};

// The node of the sound.
struct Unk_3dbf80_Node {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57(u32 index, Unk_3dbf80_Ref* ref, void* arg3);
};

// The playing context from here: its node and what the node is given.
struct Unk_3dbf80_Ctx {
    u8 _0[0x28];
    void* field_28;
    u8 _30[0x130];
    Unk_3dbf80_Node* field_160;
};
PKMN_OFFSET_ASSERT(Unk_3dbf80_Ctx, field_160, 0x160);

// What the samples of a source go through: what changes their speed, the
// filters and up to four effects.
struct Unk_2384a98_Chain {
    Unk_2384858_T field_0;
    u8 _f8[8];
    Unk_2384a98_Member field_100;
    u8 _108[8];
    Unk_2384190 field_110;
    u8 _2a0[0x10];
    Unk_2384c90_T* field_2b0[4];
    void** field_2d0;  // an object with the vtable 0x7102385610
    u64 field_2d8;
    Unk_3dd7b0_Ctx* field_2e0;
};
PKMN_OFFSET_ASSERT(Unk_2384a98_Chain, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_2384a98_Chain, field_2b0, 0x2b0);
PKMN_SIZE_ASSERT(Unk_2384a98_Chain, 0x2e8);

// What plays a source. The class under it (vtable 0x7102384980) has what is
// up to 0xa0.
struct Unk_2384a98_T {
    void** field_0;  // vptr
    u8 _8[0x18];
    void* field_20;  // the playing context, from 0x18 of it
    u8 _28[8];
    u32 field_30;
    u8 _34[4];
    u32 field_38;
    u8 _3c[0x1c];
    u32 field_58;
    u8 _5c[4];
    u8 field_60_0 : 1;
    u8 _61[0xf];
    Unk_3dd7b0_T* field_70[2];  // the source and the one after it
    u32 field_80;  // 1: it plays, 2: it stopped, 3: it waits
    u32 field_84;
    u32 field_88;
    u8 field_8c_0 : 1;
    u8 _8d[0x13];
    Unk_2384a98_Chain field_a0;

    // The functions of its table that are called here.
    void vf18() { reinterpret_cast<void (**)(Unk_2384a98_T*)>(field_0)[18](this); }
};
PKMN_OFFSET_ASSERT(Unk_2384a98_T, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_2384a98_T, field_a0, 0xa0);
PKMN_SIZE_ASSERT(Unk_2384a98_T, 0x388);

u64 Unk_38ddf0(void* ctx);

// The playing context of what is at 0x20 (0x18 into it).
static inline Unk_3dd7b0_Ctx* Unk_2384a98_Ctx(void* base) {
    return base != nullptr
               ? reinterpret_cast<Unk_3dd7b0_Ctx*>(reinterpret_cast<u8*>(base) - 0x18)
               : nullptr;
}

// 0x71003db8a0
void Unk_3db8a0(Unk_2384a98_T* self) {
    Unk_2384a98_Member& member = self->field_a0.field_100;
    member.vf3();
}

// 0x71003dbe70: which effects are not used
void Unk_3dbe70(Unk_2384a98_T* self, u32 bits, u32 mask) {
    for (u32 i = 0; i < 4; i++) {
        if ((mask & (1 << i)) && self->field_a0.field_2b0[i] != nullptr)
            self->field_a0.field_2b0[i]->field_8a = (bits >> i) & 1;
    }
}

// 0x71003dbed0
void Unk_3dbed0(Unk_2384a98_T* self, u32 index, u16 value) {
    if (self->field_a0.field_2b0[index] != nullptr)
        self->field_a0.field_2b0[index]->field_8a = value;
}

// 0x71003dbef0
u16 Unk_3dbef0(Unk_2384a98_T* self, u32 index) {
    if (self->field_a0.field_2b0[index] != nullptr)
        return self->field_a0.field_2b0[index]->field_8a;
    return 0;
}

// 0x71003dbf80: asks the node whether an effect is used
void Unk_3dbf80(Unk_2384a98_T* self, u32 index) {
    if (self->field_70[0] != nullptr) {
        Unk_2384c90_T* effect = self->field_a0.field_2b0[index];
        if (effect != nullptr) {
            Unk_3dbf80_Ctx* ctx = reinterpret_cast<Unk_3dbf80_Ctx*>(self->field_70[0]->field_18);
            Unk_3dbf80_Node* node = ctx->field_160;
            Unk_3dbf80_Ref ref;
            node->vf57(index, &ref, ctx->field_28);
            effect->field_8a = ref.field_8;
        }
    }
}

// 0x71003dc700
s32 Unk_3dc700(Unk_2384a98_T* self) {
    return static_cast<s32>(Unk_2384a98_Ctx(self->field_20)->field_270);
}

// 0x71003dc720
u64 Unk_3dc720(Unk_2384a98_T* self) {
    return Unk_38ddf0(Unk_2384a98_Ctx(self->field_20));
}

struct Unk_34fb90;
struct Unk_2383da8_T;
extern void* Unk_24bbc08;
extern void* Unk_2384248[];
extern void* Unk_2384980_Vtable[];
extern void* Unk_2384a98_Vtable[];

u32 Unk_34fb90_get(const Unk_34fb90* self);
void Unk_38f7f0(void* self, u32 arg1, u32 arg2);
void Unk_3dd9d0(Unk_3dd7b0_T* self, u32 arg1);
void Unk_3ddb80(void* self);
void Unk_3ddb90(Unk_3dd7b0_T* self);
void Unk_3ddbd0(Unk_3dd7b0_T* self, f32 arg1);
void Unk_3dda40(void* self);
u32 Unk_3ddce0(Unk_3dd7b0_T* self);
void Unk_3cd470(void* self);
void Unk_390a10(void* self, u32 arg1, void* arg2, void* arg3);
bool Unk_38e7a0(Unk_3dd7b0_Ctx* self);
void Unk_38dec0(Unk_3dd7b0_Ctx* self);
void Unk_38e0a0(Unk_3dd7b0_Ctx* self, u32* arg1, u32* arg2);
void Unk_38d280(Unk_3dd7b0_Ctx* self, u32 arg1);
Unk_3dd7b0_T* Unk_3dd7e0(u32 arg0, u32 arg1, Unk_3dd7b0_Ctx* ctx);
u32 Unk_3dc150(Unk_2384a98_T* self, Unk_3dd7b0_T* source, bool arg2, bool arg3);
void Unk_3d0150(void* self);
void Unk_3d0460(void* self);
bool Unk_3c9b70(Unk_2383da8_T* self, void* arg1);
bool Unk_3c9ae0(void* self, void* arg1, void* arg2);
void Unk_3e0ab0();
void Unk_3d6da0_update(u64 arg);
void Unk_3cf7b0(void* self);

// The playing context that has `second` 0x18 into it, and the other way.
static inline Unk_3dd7b0_Ctx* Unk_2384a98_Playing(void* second) {
    return second != nullptr
               ? reinterpret_cast<Unk_3dd7b0_Ctx*>(reinterpret_cast<u64>(second) - 0x18)
               : nullptr;
}
static inline void* Unk_2384a98_Second(Unk_3dd7b0_Ctx* ctx) {
    return static_cast<Unk_3dcd40_Second*>(reinterpret_cast<Unk_3dcd40_Playing*>(ctx));
}

// What the playing context has at 0x18, called.
struct Unk_2384a98_CtxSecond {
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
    virtual void vf10(void* arg1);
    virtual void vf11();
};

// The playing context itself, called.
struct Unk_2384a98_CtxFirst {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
};

template <typename T>
static inline void Unk_2384a98_Delete(T* object) {
    if (object != nullptr) {
        int pool = Unk_2381488;
        object->vf0();
        Unk_3047c0(pool, object);
    }
}

// 0x71003da4b0: the effects go, and what the others have
void Unk_3da4b0(Unk_2384a98_Chain* self) {
    for (u32 i = 0; i < 4; i++) {
        if (self->field_2b0[i] != nullptr) {
            self->field_2b0[i]->vf11();
            Unk_2384a98_Delete(self->field_2b0[i]);
            self->field_2b0[i] = nullptr;
        }
    }
    Unk_3d6ca0(&self->field_0);
    Unk_3cd470(&self->field_110);
}

// 0x71003da600: the destructor of the class under it
void Unk_3da600(Unk_2384a98_T* self) {
    self->field_0 = Unk_2384980_Vtable + 2;
    Unk_3cf7b0(self);
}

// 0x71003da830
void Unk_3da830(Unk_2384a98_T* self) {
    if (self->field_70[0]->field_20_1)
        return;
    self->field_8c_0 = 1;
    Unk_3dd7b0_Ctx* ctx = Unk_2384a98_Ctx(self->field_20);
    Unk_38f7f0(Unk_24bbc08, ctx->field_1d8,
               Unk_34fb90_get(reinterpret_cast<const Unk_34fb90*>(reinterpret_cast<u8*>(ctx) + 0x18)));
}

// 0x71003da8a0: waits
void Unk_3da8a0(Unk_2384a98_T* self) {
    if (self->field_80 != 3) {
        if (self->field_80 == 1) {
            Unk_3ddb90(self->field_70[0]);
            self->field_80 = 3;
        } else {
            self->vf18();
        }
    }
}

// 0x71003dac80: its source goes
void Unk_3dac80(Unk_2384a98_T* self, u32 arg1) {
    if (self->field_70[0] != nullptr) {
        Unk_3dd9d0(self->field_70[0], arg1);
        Unk_2384a98_Delete(self->field_70[0]);
        self->field_70[0] = nullptr;
    }
    Unk_3da4b0(&self->field_a0);
    self->field_60_0 = 1;
}

// 0x71003dabc0: and the one after it
void Unk_3dabc0(Unk_2384a98_T* self) {
    Unk_3dac80(self, 0);
    if (self->field_70[1] != nullptr) {
        Unk_3dd9d0(self->field_70[1], 0);
        Unk_2384a98_Delete(self->field_70[1]);
        self->field_70[1] = nullptr;
    }
}

// 0x71003dad00: stops
void Unk_3dad00(Unk_2384a98_T* self) {
    if (self->field_70[0] != nullptr)
        Unk_3ddb80(self->field_70[0]);
    self->field_80 = 2;
}

// 0x71003dad30: plays again
void Unk_3dad30(Unk_2384a98_T* self) {
    if (self->field_80 != 1) {
        if (self->field_80 == 3) {
            Unk_3dd7b0_T* source = self->field_70[0];
            Unk_3ddbd0(source, Unk_3d6db0(&self->field_a0.field_0.field_10));
            self->field_80 = 1;
        } else {
            self->vf18();
        }
    }
}

// 0x71003db7e0
void Unk_3db7e0(Unk_2384a98_T* self, Unk_3dd7b0_Buffer* buffer) {
    Unk_3dd7b0_T* source = self->field_70[0];
    Unk_3dd7b0_Ctx* ctx = source->field_18;
    if (ctx->field_a_4 && buffer->field_20 != 0xffffffff)
        Unk_390a10(Unk_24bbc10, ctx->field_1d8, &buffer->field_20, source);
    u32 count = reinterpret_cast<Unk_2384a98_CtxFirst*>(ctx)->vf23();
    if (count != 0xffffffff) {
        if (count < buffer->field_12)
            buffer->field_12 = count;
        buffer->field_34 = true;
    }
    if (self->field_70[1] != nullptr) {
        Unk_3dd7b0_Ctx* next = self->field_70[1]->field_18;
        if (reinterpret_cast<u32 (*)(Unk_3dd7b0_T*, u8*, u32)>(Unk_3ddce0)(
                self->field_70[1], next->field_290, next->field_298) == 2)
            buffer->field_30 = 2;
    }
}

// 0x71003db8c0: the one after its source is its source
void Unk_3db8c0(Unk_2384a98_T* self) {
    Unk_3dd9d0(self->field_70[0], 0);
    Unk_2384a98_Delete(self->field_70[0]);
    self->field_70[0] = self->field_70[1];
    Unk_3dd7b0_Ctx* ctx = self->field_70[0]->field_18;
    self->field_70[1] = nullptr;
    self->field_20 = Unk_2384a98_Second(ctx);
    Unk_3dda40(self->field_70[0]);
    self->field_a0.field_2e0 = self->field_70[0]->field_18;
    self->field_70[0]->field_18->field_26b_26 = 0;
}

// 0x71003dc000
void Unk_3dc000(Unk_2384a98_T* self) {
    Unk_3dd7b0_Ctx* ctx = self->field_70[0]->field_18;
    Unk_2384a98_CtxSecond* second =
        reinterpret_cast<Unk_2384a98_CtxSecond*>(reinterpret_cast<u8*>(ctx) + 0x18);
    if (!(ctx->field_16c & 0x20))
        second->vf10(nullptr);
    else if (ctx->field_16c & 0x200)
        second->vf11();
    if (ctx->field_26b_25 || ctx->field_26b_27) {
        if (Unk_38e7a0(ctx) || self->field_88 == 0) {
            self->field_84 = 1;
            self->field_88 = 2;
        }
        self->field_38 = 0;
        self->field_30 = 0;
        Unk_38dec0(ctx);
        self->field_58 = 0;
        return;
    }
    Unk_3d0150(self);
    Unk_3d0460(self);
}

// 0x71003dc0c0
u32 Unk_3dc0c0(Unk_2384a98_T* self, Unk_3dd7b0_Ctx* ctx, bool arg2) {
    u32 first;
    u32 second;
    Unk_38e0a0(ctx, &first, &second);
    Unk_3dd7b0_T* source = Unk_3dd7e0(first, second, ctx);
    if (source == nullptr) {
        Unk_38d280(ctx, 1);
        return 2;
    }
    return Unk_3dc150(self, source, arg2, true);
}

// 0x71003dc320: a playing context is not played any more
void Unk_3dc320(Unk_2384a98_T* self, Unk_3dd7b0_Ctx* ctx) {
    if (self->field_70[0] != nullptr && self->field_70[0]->field_18 == ctx) {
        if (self->field_70[0]->field_20_0 && self->field_70[0]->vf14() == 1)
            return;
        self->vf18();
        return;
    }
    if (self->field_70[1] != nullptr && self->field_70[1]->field_18 == ctx) {
        Unk_3dd9d0(self->field_70[1], 0);
        Unk_2384a98_Delete(self->field_70[1]);
        self->field_70[1] = nullptr;
    }
}

// 0x71003dc3f0
void Unk_3dc3f0(Unk_2384a98_T* self) {
    if (self->field_84 == 0 && self->field_88 == 2) {
        Unk_3dd7b0_Ctx* ctx = Unk_2384a98_Playing(self->field_20);
        if (ctx != nullptr)
            ctx->ResetSeek();
        return;
    }
    if (self->field_70[0] != nullptr && self->field_70[0]->field_20_0) {
        Unk_2384a98_Member& member = self->field_a0.field_100;
        member.vf3();
        if (member.vf7() != 1)
            self->vf18();
    }
}

// 0x71003dc4b0
bool Unk_3dc4b0(Unk_2384a98_T* self, void* arg1) {
    for (u32 i = 0; i < 4; i++) {
        Unk_2384c90_T* effect = self->field_a0.field_2b0[i];
        if (effect != nullptr && effect->field_18 != nullptr &&
            Unk_3c9ae0(effect->field_18, arg1, effect->vf16()))
            return true;
    }
    for (u32 i = 0; i < 2; i++) {
        if (self->field_70[i] != nullptr && self->field_70[i]->vf17(arg1))
            return true;
    }
    return false;
}

// 0x71003dc5f0
bool Unk_3dc5f0(Unk_2384a98_T* self, void* arg1) {
    for (u32 i = 0; i < 4; i++) {
        Unk_2384c90_T* effect = self->field_a0.field_2b0[i];
        if (effect != nullptr && effect->field_18 != nullptr &&
            Unk_3c9b70(reinterpret_cast<Unk_2383da8_T*>(effect->field_18), arg1))
            return true;
    }
    for (u32 i = 0; i < 2; i++) {
        if (self->field_70[i] != nullptr && self->field_70[i]->vf18(arg1))
            return true;
    }
    return false;
}

// 0x71003dc6e0
u32 Unk_3dc6e0(Unk_2384a98_T* self) {
    return Unk_2384a98_Ctx(self->field_20)->field_1d8;
}

// 0x71003dc750: the destructor
void Unk_3dc750(Unk_2384a98_T* self) {
    self->field_0 = Unk_2384a98_Vtable + 2;
    reinterpret_cast<void (*)(void*)>(Unk_3e0ab0)(&self->field_a0.field_2d0);
    *reinterpret_cast<void***>(&self->field_a0.field_100) = Unk_2384248 + 2;
    new (&self->field_a0.field_110) Unk_2384190;
    self->field_a0.field_0.field_0 = Unk_2384858 + 2;
    Unk_3d6da0_update(reinterpret_cast<u64>(&self->field_a0.field_0.field_10));
    self->field_0 = Unk_2384980_Vtable + 2;
    Unk_3cf7b0(self);
}

// 0x71003dc7d0: the deleting destructor
void Unk_3dc7d0(Unk_2384a98_T* self) {
    Unk_3dc750(self);
    operator delete(self);
}
