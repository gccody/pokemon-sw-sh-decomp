// Scope: common
// A source with the vtable 0x7102383f80 (on the class of 0x7102384dd0).
// Written from the executable. Placeholder names.
#include "Unk_2383f80.h"

void Unk_3690a0_update(u64 arg);
void Unk_390a10(void* self, u32 id, void* args, void* source);

extern void* Unk_2383f80_Vtable[];

// 0x71003cbca0: the destructor
void Unk_3cbca0(Unk_2383f80* self) {
    self->field_0 = Unk_2383f80_Vtable + 2;
    Unk_3690a0_update(reinterpret_cast<u64>(self->field_40));
}

// What 0x7100390a10 is told.
struct Unk_3cbde0_Args {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};

// 0x71003cbde0
u32 Unk_3cbde0(Unk_2383f80* self) {
    u32 result = Unk_3ddc20(reinterpret_cast<Unk_3dd7b0_T*>(self));
    Unk_3dd7b0_Ctx* ctx = self->field_18;
    if (ctx->field_a_4) {
        // What it tells is read before it is written.
        u32 a = self->field_24;
        u32 b = self->field_28;
        u32 c = ctx->field_208;
        Unk_3cbde0_Args args;
        args.field_8 = a;
        args.field_c = c;
        args.field_0 = b;
        args.field_4 = 0;
        Unk_390a10(Unk_24bbc10, ctx->field_1d8, &args, self);
    }
    return result;
}

// 0x71003cbe60: milliseconds it plays for, with what it repeats
f32 Unk_3cbe60(Unk_2383f80* self) {
    u16 count = self->field_18->field_268;
    if (count == 0)
        return 0.0f;
    f32 samples = self->field_24 + (count - 1) * static_cast<f32>(self->field_38 + 1 - self->field_34);
    return samples * 1000.0f / reinterpret_cast<u32 (**)(Unk_2383f80*)>(self->field_0)[28](self);
}
