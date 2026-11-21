// Scope: common
// What plays a source (vtable 0x7102384a98): the source, the object with
// the vtable 0x7102384248 at 0x1a0 and up to four effects at 0x350.
// Written from the executable. Placeholder names.
#include "Unk_2384c90.h"
#include "Unk_3dd7b0.h"

// The object at 0x1a0, as far as it is called here.
struct Unk_2384a98_Member {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
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

// The source it plays.
struct Unk_2384a98_Source {
    u8 _0[0x18];
    Unk_3dbf80_Ctx* field_18;
};

struct Unk_2384a98_T {
    u8 _0[0x20];
    void* field_20;  // the playing context, from 0x18 of it
    u8 _28[0x48];
    Unk_2384a98_Source* field_70;
    u8 _78[0x128];
    Unk_2384a98_Member field_1a0;
    u8 _1a8[0x1a8];
    Unk_2384c90_T* field_350[4];
};
PKMN_OFFSET_ASSERT(Unk_2384a98_T, field_1a0, 0x1a0);
PKMN_OFFSET_ASSERT(Unk_2384a98_T, field_350, 0x350);

u64 Unk_38ddf0(void* ctx);

// The playing context of what is at 0x20 (0x18 into it).
static inline Unk_3dd7b0_Ctx* Unk_2384a98_Ctx(void* base) {
    return base != nullptr
               ? reinterpret_cast<Unk_3dd7b0_Ctx*>(reinterpret_cast<u8*>(base) - 0x18)
               : nullptr;
}

// 0x71003db8a0
void Unk_3db8a0(Unk_2384a98_T* self) {
    Unk_2384a98_Member& member = self->field_1a0;
    member.vf3();
}

// 0x71003dbe70: which effects are not used
void Unk_3dbe70(Unk_2384a98_T* self, u32 bits, u32 mask) {
    for (u32 i = 0; i < 4; i++) {
        if ((mask & (1 << i)) && self->field_350[i] != nullptr)
            self->field_350[i]->field_8a = (bits >> i) & 1;
    }
}

// 0x71003dbed0
void Unk_3dbed0(Unk_2384a98_T* self, u32 index, u16 value) {
    if (self->field_350[index] != nullptr)
        self->field_350[index]->field_8a = value;
}

// 0x71003dbef0
u16 Unk_3dbef0(Unk_2384a98_T* self, u32 index) {
    if (self->field_350[index] != nullptr)
        return self->field_350[index]->field_8a;
    return 0;
}

// 0x71003dbf80: asks the node whether an effect is used
void Unk_3dbf80(Unk_2384a98_T* self, u32 index) {
    if (self->field_70 != nullptr) {
        Unk_2384c90_T* effect = self->field_350[index];
        if (effect != nullptr) {
            Unk_3dbf80_Ctx* ctx = self->field_70->field_18;
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
