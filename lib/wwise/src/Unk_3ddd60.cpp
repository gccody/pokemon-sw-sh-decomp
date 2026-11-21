// Scope: common
// More of the source with the vtable 0x7102383f80 and the class on it with
// the vtable 0x7102384ec0 (its samples are in memory). Written from the
// executable. Placeholder names.
#include "Unk_2383f80.h"

extern void* _ZTV11Unk_2384ec0[];

// The class with the vtable 0x7102384ec0: its samples are in memory.
class Unk_2384ec0_T : public Unk_2383f80 {
public:
    u8* field_58;
};
PKMN_OFFSET_ASSERT(Unk_2384ec0_T, field_58, 0x58);

void Unk_3cbca0(Unk_2383f80* self);
u32 Unk_3cbff0(Unk_2383f80* self, u8* samples, u32 count, u32 arg3, u32 arg4,
               Unk_3dd7b0_Buffer* buffer);
u32 Unk_3cc0e0(Unk_2383f80* self);

// 0x71003ddd60
bool Unk_3ddd60(Unk_2383f80* self) {
    return self->field_18->field_26b_29;
}

// 0x71003dddc0: the destructor of the class with the vtable 0x7102384ec0
void Unk_3dddc0(Unk_2383f80* self) {
    self->field_0 = _ZTV11Unk_2384ec0 + 2;
    Unk_3cbca0(self);
}

// 0x71003ddde0: its deleting destructor
void Unk_3ddde0(Unk_2383f80* self) {
    self->field_0 = _ZTV11Unk_2384ec0 + 2;
    Unk_3cbca0(self);
    operator delete(self);
}

// 0x71003ddfd0: where its samples are
u32 Unk_3ddfd0(Unk_2384ec0_T* self, u8* base) {
    if (self->field_58 != nullptr)
        self->field_58 = base + self->field_30;
    return 1;
}

// 0x71003ddff0: gives samples from where it is
u32 Unk_3ddff0(Unk_2384ec0_T* self, Unk_3dd7b0_Buffer* buffer) {
    u16 loops = self->field_54;
    Unk_3dd7b0_Ctx* ctx = self->field_18;
    u32 count = buffer->field_10;
    u32 end = loops == 1 ? self->field_24 : self->field_38 + 1;
    if (self->field_28 + count > end)
        count = end - self->field_28;
    return Unk_3cbff0(self, self->field_58 + self->field_28 * ctx->field_210_6, count,
                      ctx->field_208, ctx->field_20c, buffer);
}

// Where the playing context says it is, and whether that is the end.
static inline u32 Unk_3de0f0_Seek(Unk_2383f80* self) {
    self->field_28 = Unk_3cc0e0(self);
    self->field_18->ResetSeek();
    return self->field_28 >= self->field_24 ? 2 : 1;
}

// 0x71003de050
u32 Unk_3de050(Unk_2383f80* self, u32 arg1, bool arg2) {
    if (arg1 == 0) {
        self->field_28 = 0;
        self->field_54 = self->field_18 != nullptr ? self->field_18->field_268 : 1;
    } else if (arg2 && arg1 == 1) {
        return Unk_3de0f0_Seek(self);
    }
    return 1;
}

// 0x71003de0f0
u32 Unk_3de0f0(Unk_2383f80* self) {
    return Unk_3de0f0_Seek(self);
}
