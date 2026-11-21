#pragma once
// A bus of the lower engine (vtable 0x71023844d0, with a second one at 0xc0),
// as far as the code uses it. Written from the executable. Placeholder names.
#include "Unk_KeyArray.h"
#include "block_pool.h"

u32 Unk_304740(int poolId, void* ptr);

// How many channels and which ones: four bytes that are passed by value.
struct Unk_24df148_Config {
    u32 field_0_0 : 8;   // how many
    u32 field_0_8 : 4;   // the kind: 1 has a mask
    u32 field_0_12 : 20;  // the mask
};
PKMN_SIZE_ASSERT(Unk_24df148_Config, 4);

// Samples: 0x18 bytes.
struct Unk_24df148_Buffer {
    void* field_0;
    Unk_24df148_Config field_8;
    u32 field_c;  // state
    u16 field_10;  // how many samples a channel has room for
    u16 field_12;  // and how many it has

    Unk_24df148_Config GetConfig() const { return field_8; }

    // Frees the samples (pool 0x7102381488) and has nothing.
    void Free() {
        if (field_0 != nullptr) {
            Unk_304740(Unk_2381488, field_0);
            field_0 = nullptr;
            field_10 = 0;
            field_12 = 0;
            field_c = 0x2b;
            *reinterpret_cast<u32*>(&field_8) = 0;
        }
    }
};
PKMN_SIZE_ASSERT(Unk_24df148_Buffer, 0x18);

// What a bus mixes with, as far as these functions call it.
struct Unk_24df148_Mix {
    virtual void vf0();  // the destructor
    virtual void vf1();
    virtual void vf2(u32 arg1, f32 arg2, f32 arg3);
    virtual void vf3(u32 arg1, u32 arg2);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u32 arg1);

    u8 _8[8];
    void* field_10;
    u8 _18[0x108];
    f32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_24df148_Mix, field_120, 0x120);

// The node of a bus.
struct Unk_24df148_Node {
    u8 _0[0x10];
    u32 field_10;  // ID
    u8 _14[0x6c];
    void* field_80;
};

// What a bus is the bus of: a structure around its node (its address is
// taken apart from the node's load).
struct Unk_24df148_Ctx {
    Unk_24df148_Node* field_0;
};

// What plays into a bus: a list through 0x40.
struct Unk_24df148_Bus;
struct Unk_369930 {
    virtual void vf0();  // the destructor

    u8 _8[0x38];
    Unk_369930* field_40;
    u8 _48[8];
    void* field_50;  // where it comes from
    Unk_24df148_Bus* field_58;  // and the bus it goes to
    u8 _60[0x230];
    f32 field_290;  // how loud it is
    f32 field_294;  // decibels over the bus's
    u8 _298[8];
    u32 field_2a0;
    u8 field_2a4_0 : 1;
    u8 field_2a4_1 : 1;
};
PKMN_OFFSET_ASSERT(Unk_369930, field_2a0, 0x2a0);

template <>
struct Unk_ListNext<Unk_369930> {
    static Unk_369930*& Get(Unk_369930* item) { return item->field_40; }
};

// An effect, as far as a bus calls it.
struct Unk_24df148_Plugin {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* alloc);
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(void* arg1);
};

// What an effect of a bus has with it (deleted with the pool 0x7102381488).
struct Unk_24df148_Object {
    virtual void vf0();  // the destructor
};

// What an effect of a bus starts with (vtable 0x7102380be8): 0x68 bytes.
struct Unk_24df148_SlotCtx {
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();

    u8 _8[0x58];
    u32 field_60;
};
PKMN_SIZE_ASSERT(Unk_24df148_SlotCtx, 0x68);

// One of the four effects a bus has at 0xc8: 0x80 bytes. Its functions are
// those of its first member: the address they are called with is computed
// where they are called.
struct Unk_24df148_Slot {
    Unk_24df148_SlotCtx field_0;
    Unk_24df148_Plugin* field_68;
    Unk_24df148_Object* field_70;
    u16 field_78;  // not used when it is set
    u16 field_7a;
};
PKMN_SIZE_ASSERT(Unk_24df148_Slot, 0x80);

// What a bus has at 0x328.
struct Unk_24df148_Fx {
    virtual void vf0();  // the destructor
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();

    u8 _8[0x58];
    Unk_24df148_Plugin* field_60;
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_24df148_Fx, field_60, 0x60);

// What the array at 0x330 has for a key.
struct Unk_24df148_Value {
    u64 field_0;
    u32 field_8;
    u8 _c[0xc];
};
PKMN_SIZE_ASSERT(Unk_24df148_Value, 0x18);

// The second base of a bus (0xc0).
struct Unk_24df148_Sub {
    void** field_0;  // vptr
};

// A bus of the lower engine: the array at 0x71024df148 has them.
struct Unk_24df148_Bus {
    void** field_0;  // vptr
    u8 _8[0x18];
    Unk_24df148_Mix* field_20;
    u8 _28[0x14];
    f32 field_3c;  // decibels
    u8 _40[8];
    Unk_369930* field_48;
    u8 _50[0x20];
    Unk_24df148_Ctx field_70;
    u64 field_78;
    u8 _80[8];
    Unk_24df148_Buffer field_88;
    u8 _a0[8];
    Unk_24df148_Object* field_a8;  // what measures it
    u8 _b0[8];
    u8 field_b8_0 : 2;
    u8 field_b8_2 : 5;
    u8 field_b9_0 : 5;
    u8 _ba[6];
    Unk_24df148_Sub field_c0;
    Unk_24df148_Slot field_c8[4];
    Unk_24df148_Buffer field_2c8[4];  // what the effects give
    Unk_24df148_Fx* field_328;
    Unk_KeyArray<u32, Unk_24df148_Value> field_330;
    u16 field_340;  // no effect is used when it is set
    u8 _342[2];
    u8 field_344_0 : 1;
    u8 field_344_1 : 1;
    u8 _345[3];
    u32 field_348;
    u32 field_34c;
    u8 _350[4];
    u8 field_354_0 : 1;
    u8 _355[0xb];
    f32 field_360;  // decibels: the lowest it goes
    u8 _364[4];
    f32 field_368;  // decibels from which what plays into it is less loud
    f32 field_36c;  // by this much of what it is over

    u32 Id() const { return field_70.field_0 != nullptr ? field_70.field_0->field_10 : 0; }
};
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_2c8, 0x2c8);
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_328, 0x328);
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_24df148_Bus, field_348, 0x348);

// The bus of its second base (computed as a number: the offset of a member
// is not added to it where it is computed).
static inline Unk_24df148_Bus* Unk_24df148_Outer(Unk_24df148_Sub* self) {
    return reinterpret_cast<Unk_24df148_Bus*>(reinterpret_cast<u64>(self) -
                                              0xc0);
}

// What 0x710037d6b0 finds for a bus's node.
struct Unk_37d6b0_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u32* arg1, u32* arg2);

    u8 _8[0x110];
    Unk_24df148_Bus* field_118;
};
PKMN_OFFSET_ASSERT(Unk_37d6b0_T, field_118, 0x118);

Unk_37d6b0_T* Unk_37d6b0(Unk_24df148_Ctx* ctx);
void Unk_3d1930(Unk_24df148_Bus* bus);
void Unk_3d2290(Unk_24df148_Bus* bus, u32 arg1, u32 arg2);
void Unk_3d4310(void* bus);  // a bus's destructor
void Unk_3d45f0(Unk_24df148_Bus* bus, u32 mask);
