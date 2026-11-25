// Scope: common
// A battle server command wrapper that calls Unk_80fb90 (its own TU: clang
// would inline it, and the original calls it). Placeholder names: rename once
// they're known.
#include "unsorted/Unk_811d90.h"

struct Unk_7f8b70;
u32 Unk_7f8b70_get(const Unk_7f8b70* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u64 Unk_7ef750(const Unk_7ee6b0* self, u32 index);
void Unk_816320(u64 que, u16 id, ...);
void Unk_80fb90(void* self, void* object, u32 amount, u32 arg3, u32 arg4, u32 notify);

// 0x710080fd50
void Unk_80fd50(const Unk_811d90_Self* self, Unk_7ee6b0* poke, u32 amount) {
    u64 condition = Unk_7ef750(poke, 6);
    u32 value = Unk_7f8b70_get(reinterpret_cast<const Unk_7f8b70*>(&condition));
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_8150c0(self->field_18, 0x8c, pokeId);
    Unk_80fb90(const_cast<Unk_811d90_Self*>(self), poke, -amount, 2, value, 1);
    Unk_816320(self->field_18, 0xb9, 0x5e, pokeId, 0xffff0000);
}
