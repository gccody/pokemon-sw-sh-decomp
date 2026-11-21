// Scope: common
// What plays for a node of an item (three lists by key) and one use of it.
// Written from the executable. Placeholder names.
#include "Unk_2383cc0.h"

// 0x710038c050 was named with this type for Unk_23837d0_Transition.
struct Unk_3bff70_Transition;
struct Unk_3be850_Ctx;
struct Unk_3c2c10;
void Unk_38c050(Unk_3be850_Ctx* ctx, Unk_3bff70_Transition* transition, bool arg2);
void Unk_38c1a0(Unk_3c44e0_Ctx* ctx, Unk_23837d0_Transition* transition);
void Unk_38c220(Unk_3c44e0_Ctx* ctx, Unk_23837d0_Transition* transition, bool arg2);
void Unk_33a8a0(void* self, void* arg1);
void Unk_33bb80(void* self, void* arg1);
void Unk_3c2c10_update(Unk_3c2c10* self);  // one reference more (lib/wwise/leaf)
extern void* Unk_24bbbc0;

// 0x71003c44e0: the destructor
void Unk_3c44e0(Unk_3c44e0_T* self) {
    for (auto it = self->field_18.Begin(); it != self->field_18.End(); ++it)
        (*it).item.field_0->vf3();
    self->field_18.Term();
    self->field_40.Term();
    self->field_68.Term();
}

static inline u32 Unk_3c44e0_Release(Unk_3c44e0_T* self) {
    u32 count = --self->field_0;
    if (count == 0) {
        int pool = Unk_237e820;
        Unk_3c44e0(self);
        Unk_3047c0(pool, self);
    }
    return count;
}

// 0x71003c47b0: one reference less
u32 Unk_3c47b0(Unk_3c44e0_T* self) {
    return Unk_3c44e0_Release(self);
}

// 0x71003c4810: the constructor of a use
void Unk_3c4810(Unk_3c44e0_Use* self, Unk_2383c58_Item* item, Unk_23837d0_Node* node) {
    self->field_8 = 1;
    self->field_28 = 0;
    self->field_29 = 0xff;
    self->field_10 = nullptr;
    self->field_18 = item;
    self->field_20 = node;
    self->field_30_0 = 0;
    if (item != nullptr)
        Unk_3c2c10_update(reinterpret_cast<Unk_3c2c10*>(item));
    if (self->field_20 != nullptr)
        self->field_20->vf2();
}

// 0x71003c4880: one reference less to a use
u32 Unk_3c4880(Unk_3c44e0_Use* self) {
    u32 count = --self->field_8;
    if (count == 0) {
        int pool = Unk_237e820;
        if (self->field_18 != nullptr)
            Unk_3c2c30(self->field_18);
        if (self->field_20 != nullptr)
            self->field_20->vf3();
        if (self->field_10 != nullptr)
            Unk_3c44e0_Release(self->field_10);
        Unk_3047c0(pool, self);
    }
    return count;
}

// 0x71003c5180
void Unk_3c5180(Unk_3c44e0_Use* self) {
    for (auto it = self->field_10->field_40.Begin(); it != self->field_10->field_40.End(); ++it) {
        Unk_3c44e0_Ctx* ctx = (*it).item;
        ctx->field_2b8 = 0xffffffff;
        Unk_23837d0_Transition transition;
        transition.field_0 = 0;
        transition.field_4 = 4;
        Unk_38c050(reinterpret_cast<Unk_3be850_Ctx*>(ctx),
                   reinterpret_cast<Unk_3bff70_Transition*>(&transition), true);
    }
}

// 0x71003c51e0
void Unk_3c51e0(Unk_3c44e0_Use* self) {
    for (auto it = self->field_10->field_40.Begin(); it != self->field_10->field_40.End(); ++it) {
        Unk_3c44e0_Ctx* ctx = (*it).item;
        Unk_23837d0_Transition transition;
        transition.field_0 = 0;
        transition.field_4 = 4;
        Unk_38c1a0(ctx, &transition);
    }
    for (auto it = self->field_10->field_68.Begin(); it != self->field_10->field_68.End(); ++it)
        Unk_33a8a0(Unk_24bbbc0, (*it).item);
}

// 0x71003c5260
void Unk_3c5260(Unk_3c44e0_Use* self) {
    for (auto it = self->field_10->field_40.Begin(); it != self->field_10->field_40.End(); ++it) {
        Unk_3c44e0_Ctx* ctx = (*it).item;
        Unk_23837d0_Transition transition;
        transition.field_0 = 0;
        transition.field_4 = 4;
        Unk_38c220(ctx, &transition, false);
    }
    for (auto it = self->field_10->field_68.Begin(); it != self->field_10->field_68.End(); ++it)
        Unk_33bb80(Unk_24bbbc0, (*it).item);
}
