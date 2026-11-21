// Scope: common
// What an effect of a source asks about the sound (three tables of
// functions: at 0, 0x28 and 0x30 of an object with the playing context at
// 0x18). The functions of the second and third are written from their own
// address. Written from the executable. Placeholder names.
#include "Unk_24df148.h"
#include "Unk_3dd7b0.h"

struct Unk_34fb90;
// What 0x7100395920 gives: an array of 8-byte items.
struct Unk_395920_T {
    u8 _0[8];
    u64* field_8;
    u32 field_10;
};

extern void* Unk_24bbc08;
extern void* const Unk_2380be8[8];

u32 Unk_34fb90_get(const Unk_34fb90* self);
u64 Unk_34fc00(void* arg);
u64 Unk_34fc50(void* arg);
u64 Unk_34fdc0(void* arg);
u64 Unk_38ddf0(void* ctx);
void* Unk_38fd40(void* self, u32 id);
Unk_395920_T* Unk_395920(void* arg);
void* Unk_395a20(void* arg);

// The object, from its first table of functions.
struct Unk_3e02b0_T {
    void** field_0;  // vptr
    u8 _8[0x10];
    Unk_3dd7b0_Ctx* field_18;
};

// From its second (0x28) and third (0x30) ones.
struct Unk_3e02b0_Second {
    void** field_0;
};
struct Unk_3e02b0_Third {
    void** field_0;
};

static inline Unk_3dd7b0_Ctx* Unk_3e02b0_Ctx(Unk_3e02b0_Second* self) {
    return reinterpret_cast<Unk_3e02b0_T*>(reinterpret_cast<u64>(self) - 0x28)->field_18;
}
static inline Unk_3dd7b0_Ctx* Unk_3e02b0_Ctx(Unk_3e02b0_Third* self) {
    return reinterpret_cast<Unk_3e02b0_T*>(reinterpret_cast<u64>(self) - 0x30)->field_18;
}

// What the playing context has at 0x18.
static inline void* Unk_3e02b0_Sub(Unk_3dd7b0_Ctx* ctx) {
    return reinterpret_cast<u8*>(ctx) + 0x18;
}

// Copies the array of the node (or says how many items it has).
static inline bool Unk_3e0820_Copy(Unk_3dd7b0_Ctx* ctx, u64* items, u32* count) {
    Unk_395920_T* array = Unk_395920(ctx->field_28);
    if (items == nullptr) {
        *count = array->field_10;
        return true;
    }
    *count = array->field_10 < *count ? array->field_10 : *count;
    for (u32 i = 0; i < *count; i++)
        items[i] = array->field_8[i];
    return *count == array->field_10;
}

// 0x71003e02b0
u32 Unk_3e02b0(Unk_3e02b0_T* self) {
    return Unk_34fb90_get(static_cast<const Unk_34fb90*>(Unk_3e02b0_Sub(self->field_18)));
}

// 0x71003e02c0
u32 Unk_3e02c0(Unk_3e02b0_Second* self) {
    return Unk_34fb90_get(static_cast<const Unk_34fb90*>(Unk_3e02b0_Sub(Unk_3e02b0_Ctx(self))));
}

// 0x71003e0620
void* Unk_3e0620(Unk_3e02b0_T* self) {
    if (Unk_24bbc08 != nullptr && self->field_18 != nullptr)
        return Unk_38fd40(Unk_24bbc08, self->field_18->field_1d8);
    return nullptr;
}

// 0x71003e0650
void* Unk_3e0650(Unk_3e02b0_Second* self) {
    if (Unk_24bbc08 != nullptr && Unk_3e02b0_Ctx(self) != nullptr)
        return Unk_38fd40(Unk_24bbc08, Unk_3e02b0_Ctx(self)->field_1d8);
    return nullptr;
}

// 0x71003e0680: one more deleting destructor of what an effect starts with
void Unk_3e0680(Unk_24df148_SlotCtx* self) {
    *reinterpret_cast<void* const**>(self) = Unk_2380be8 + 2;
    reinterpret_cast<void (*)(Unk_24df148_SlotCtx*)>(Unk_2380be8[7])(self);
    operator delete(self);
}

// 0x71003e0760
s32 Unk_3e0760(Unk_3e02b0_T* self) {
    return static_cast<s32>(self->field_18->field_270);
}

// 0x71003e0790
void* Unk_3e0790(Unk_3e02b0_T* self) {
    return Unk_395a20(self->field_18->field_28);
}

// 0x71003e07a0
u64 Unk_3e07a0(Unk_3e02b0_T* self) {
    return Unk_34fdc0(Unk_3e02b0_Sub(self->field_18));
}

// 0x71003e0810
u64 Unk_3e0810(Unk_3e02b0_T* self) {
    return Unk_34fc00(Unk_3e02b0_Sub(self->field_18));
}

// 0x71003e0820
bool Unk_3e0820(Unk_3e02b0_T* self, u64* items, u32* count) {
    return Unk_3e0820_Copy(self->field_18, items, count);
}

// 0x71003e08c0
u64 Unk_3e08c0(Unk_3e02b0_T* self) {
    return Unk_34fc50(Unk_3e02b0_Sub(self->field_18));
}

// 0x71003e0900
u16 Unk_3e0900(Unk_3e02b0_Second* self) {
    return Unk_3e02b0_Ctx(self)->field_268;
}

// 0x71003e0920
u32 Unk_3e0920(Unk_3e02b0_Second* self) {
    return Unk_3e02b0_Ctx(self)->field_29c;
}

// 0x71003e0930
u64 Unk_3e0930(Unk_3e02b0_Third* self) {
    return Unk_3e02b0_Ctx(self)->field_28->field_48;
}

// 0x71003e0940
void* Unk_3e0940(Unk_3e02b0_Third* self) {
    return Unk_395a20(Unk_3e02b0_Ctx(self)->field_28);
}

// 0x71003e0950
u64 Unk_3e0950(Unk_3e02b0_Third* self) {
    return Unk_34fdc0(Unk_3e02b0_Sub(Unk_3e02b0_Ctx(self)));
}

// 0x71003e0960
u16 Unk_3e0960(Unk_3e02b0_Third* self) {
    return (*Unk_3e02b0_Ctx(self)->field_28->field_38)->field_38;
}

// 0x71003e0980
u64 Unk_3e0980(Unk_3e02b0_Third* self) {
    return Unk_34fc00(Unk_3e02b0_Sub(Unk_3e02b0_Ctx(self)));
}

// 0x71003e0990
u32 Unk_3e0990(Unk_3e02b0_Third* self) {
    return (*Unk_3e02b0_Ctx(self)->field_28->field_38)->field_3a_0;
}

// 0x71003e09b0
f32 Unk_3e09b0(Unk_3e02b0_Third* self) {
    return (*Unk_3e02b0_Ctx(self)->field_28->field_38)->field_40;
}

// 0x71003e09d0
bool Unk_3e09d0(Unk_3e02b0_Third* self, u64* items, u32* count) {
    return Unk_3e0820_Copy(Unk_3e02b0_Ctx(self), items, count);
}

// 0x71003e0a70
u64 Unk_3e0a70(Unk_3e02b0_Third* self) {
    return Unk_34fc50(Unk_3e02b0_Sub(Unk_3e02b0_Ctx(self)));
}

// 0x71003e0a80
u32 Unk_3e0a80(Unk_3e02b0_Third* self) {
    return Unk_3e02b0_Ctx(self)->field_1d8;
}

// 0x71003e0a90
s32 Unk_3e0a90(Unk_3e02b0_Third* self) {
    return static_cast<s32>(Unk_3e02b0_Ctx(self)->field_270);
}

// 0x71003e0aa0
u64 Unk_3e0aa0(Unk_3e02b0_Third* self) {
    return Unk_38ddf0(Unk_3e02b0_Ctx(self));
}
