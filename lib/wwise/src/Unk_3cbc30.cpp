// Scope: common
// A source with the vtable 0x7102383f80 (on the class of 0x7102384dd0).
// Written from the executable. Placeholder names.
#include "Unk_3dd7b0.h"

void Unk_3690a0_update(u64 arg);
void Unk_390a10(void* self, u32 id, void* args, void* source);

extern void* Unk_2383f80_Vtable[];

// Its constructor (0x71003cbc30) is not here: the table of functions has it
// without a parameter, which is how the matched constructors of the classes
// on it call it, and the playing context it passes on to the constructor of
// the base class is a parameter.
class Unk_2383f80 {
public:
    void** field_0;  // vptr
    u64 field_8;
    u64 field_10;
    Unk_3dd7b0_Ctx* field_18;
    u8 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u8 _3c[4];
    u8 field_40[0x10];
    u32 field_50;
    u16 field_54;
};
PKMN_OFFSET_ASSERT(Unk_2383f80, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_2383f80, field_54, 0x54);

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
