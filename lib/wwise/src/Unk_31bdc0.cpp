// Scope: common
// Slot 26/27's common part, in a file of its own: the original calls it
// from Unk_31bce0 and Unk_31beb0 (Unk_31b990.cpp). Placeholder names.
#include <types.h>

#include "Unk_31b990.h"

struct Unk_305720_Obj;
struct Unk_309380;

// The callbacks' arguments to Unk_309250.
struct Unk_309250_Arg {
    u32 field_0;
    u32 field_4;
    bool field_8;
};

void Unk_308aa0(void* self);
void Unk_309250(Unk_305720_Obj* self, void* a1, int a2);
void Unk_309380_call(Unk_309380* self);
void Unk_319470(void* self);
u64 Unk_30b050(void* self);

// NON_MATCHING: the two stores of the argument of Unk_309250 are in the other
// order (the merged store of field_0 and field_4 first).
// 0x710031bdc0: goes to `position`: 1, or 2
u32 Unk_31bdc0(Unk_31b990_T* self, s32 position) {
    if (self->field_5a_1 != 0)
        return 2;
    self->field_48++;
    for (Unk_31b990_Item* item = self->field_30; item != nullptr;) {
        Unk_31b990_Item* next = item->next;
        Unk_309380_call(reinterpret_cast<Unk_309380*>(item));
        item = next;
    }
    Unk_319470(self);
    Unk_31b990_Ctx* ctx = self->field_60;
    s32 offset;
    u32 result = Unk_31bb90(self, ctx->field_30, reinterpret_cast<u64>(ctx->field_18), position,
                            &offset, ctx->field_38);
    if (result == 1) {
        u64 start = self->field_60->field_8;
        self->field_68 = start - Unk_30b050(self) + offset;
    } else {
        Unk_309250_Arg arg;
        arg.field_0 = 0;
        arg.field_4 = 4;
        arg.field_8 = false;
        Unk_309250(reinterpret_cast<Unk_305720_Obj*>(self), &arg, 0);
    }
    Unk_308aa0(self);
    return result;
}
