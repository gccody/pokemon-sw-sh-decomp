// Scope: common
// A Wwise module that keeps a list of objects (Unk_305720_Obj) and runs
// global callbacks over it. One TU: its static initialiser is at
// 0x7100307100.
#include "containers.h"

// The objects the module keeps, linked through field_70.
struct Unk_305720_Ctx {
    u8 _0[0x2c];
    u32 field_2c;
    void* field_30;
    u8 _38[0x18];
    u8 field_50;
    u8 field_51;
    u8 _52[6];
    u8 field_58;  // start of a member (Unk_3e1c80)
};
PKMN_OFFSET_ASSERT(Unk_305720_Ctx, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_305720_Ctx, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_305720_Ctx, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_305720_Ctx, field_58, 0x58);

struct Unk_305720_Owner {
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
    virtual bool vf37(u32 a1);
    virtual void vf38(u32 a1);
};

struct Unk_305720_Obj {
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
    virtual Unk_305720_Owner* vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual u32 vf26(u32* value, bool a2);
    virtual u32 vf27(float* value, bool a2);
    virtual u32 vf28(void* out);

    u8 _8[0x10];
    u8 field_18;  // start of a member
    u8 _19[9];
    u8 field_22_0 : 5;
    u8 field_22_5 : 1;
    u8 _23[0x37];
    u8 field_5a_0 : 1;
    u8 field_5a_1 : 3;
    u8 field_5a_4 : 1;
    u8 _5b[5];
    Unk_305720_Ctx* field_60;
    u8 _68[8];
    Unk_305720_Obj* next;
};
PKMN_OFFSET_ASSERT(Unk_305720_Obj, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_305720_Obj, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_305720_Obj, next, 0x70);

// An entry of Unk_24bb9d0.
struct Unk_305720_Entry {
    u32 field_0;
    u32 field_4;
    u8 field_8_0 : 1;
    u8 field_8_1 : 1;
};

// 0x30 bytes, constructed and destroyed out of line.
struct Unk_24bb9a0_T {
    Unk_24bb9a0_T();
    ~Unk_24bb9a0_T();
    u8 _0[0x30];
};

struct Unk_305720_Inst {
    Unk_305720_Inst() {}
};

// The module's settings: Unk_305c00 sets the defaults.
struct Unk_305720_Settings {
    float field_0;
};

// 0x7100305c00
void Unk_305c00(u64 out) {
    reinterpret_cast<Unk_305720_Settings*>(out)->field_0 = 1.0f;
}
struct Unk_30adf0;
struct Unk_30b000;
struct Unk_3e1c80_T;

// The callbacks' arguments to Unk_309250.
struct Unk_309250_Arg {
    u32 field_0;
    u32 field_4;
    bool field_8;
};

void Unk_3323d0(void (*callback)(), u32 location, void* cookie);
void Unk_332890(bool (*callback)(u32, u32));
void Unk_3328a0(u32 (*callback)(u8*, void*, u32));
void Unk_3328b0(void (*callback)(void*));

void Unk_31b540(Unk_24bb9a0_T* self);
u32 Unk_31b580(Unk_24bb9a0_T* self, u32 id);
void Unk_31b860(Unk_24bb9a0_T* self, u32 id);
void Unk_31b7b0(Unk_24bb9a0_T* self, u32 id, void* data);
void Unk_30be30(Unk_305720_Ctx* self, u16 a1);
void Unk_309250(Unk_305720_Obj* self, void* a1, int a2);
void Unk_309390(Unk_305720_Obj* self, void* a1);
void Unk_309480(Unk_305720_Obj* self, void* a1, bool a2);
void Unk_316000();
s64 Unk_30cae0(Unk_305720_Ctx* self, u32 id, bool* found, u32* a3, u64* a4);
u32 Unk_30cdd0(Unk_305720_Ctx* self, Unk_305720_Entry* entry, u32 a2, u64 a3);
void Unk_330840(u32 id, u32 a1, u32 a2, u32 a3);
void Unk_3e1c80(Unk_3e1c80_T* self, void* a1, bool a2);
void Unk_30bc20(Unk_305720_Ctx* self, Unk_305720_Obj* obj, void* a2, void* a3, bool a4);
void Unk_30bcf0(Unk_305720_Ctx* self);
void Unk_30adf0_set(Unk_30adf0* self, u64 value);
void Unk_30b000_set(Unk_30b000* self, u32 value);
u32 Unk_38fae0(void* self, u32 id, void* a2, u32* a3);
void Unk_38fb90(void* self, u32 id, void* a2);
void Unk_38f170(void* self, u32 id);
void Unk_305830();
void Unk_305920();
bool Unk_3059d0(u32 a0, u32 a1);
u32 Unk_307160(u8* a0, void* a1, u32 a2);
void Unk_305c20(Unk_List2<Unk_305720_Entry>* list);
void Unk_307820_call(void* self);

extern u16 Unk_2382e78;
extern void* Unk_24bbc08;

Unk_305720_Inst* Unk_24bb988;
Unk_ListBare<Unk_305720_Obj> Unk_24bb990;
Unk_24bb9a0_T Unk_24bb9a0;
Unk_List2<Unk_305720_Entry> Unk_24bb9d0;
Unk_305720_Settings Unk_24bb9f8;
u8 Unk_24bb9fc;
bool Unk_24bb9fd;

// 0x7100305c10
void Unk_305c10(void*) {
}

// 0x7100306930
void Unk_306930(u64, void* a1, u32 a2) {
    for (Unk_305720_Obj* o = Unk_24bb990.field_8; o != nullptr; o = o->next) {
        if (o->field_60 != nullptr)
            Unk_3e1c80(reinterpret_cast<Unk_3e1c80_T*>(&o->field_60->field_58), a1, a2 & 1);
    }
}

struct Unk_3069c0_Arg {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_3069c0_Arg, field_14, 0x14);

// Releases the entries of Unk_24bb9d0 not marked in use (field_8_1).
static inline void Unk_305720_Purge() {
    for (auto it = Unk_24bb9d0.BeginEx(); it.item != nullptr;) {
        if (!it.item->item.field_8_1)
            it = Unk_24bb9d0.Erase(it);
        else
            ++it;
    }
}

using Unk_305720_Iterator = Unk_List2<Unk_305720_Entry>::Iterator;
using Unk_305720_IteratorEx = Unk_List2<Unk_305720_Entry>::IteratorEx;

// 0x7100306fb0
void Unk_306fb0(u32 id, Unk_305720_Iterator& it) {
    Unk_330840(id, it.item->item.field_4, 0, 1);
    it.item->item.field_8_0 = true;
    it.item->item.field_8_1 = false;
    for (; it.item != nullptr; ++it) {
        if (it.item->item.field_0 == id)
            it.item->item.field_8_0 = true;
    }
    Unk_305720_Purge();
}

