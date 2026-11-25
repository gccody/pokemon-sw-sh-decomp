// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

void Unk_8173b0(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId);
// Returns what Unk_7f22a0 returns: the caller keeps bit 0 of it.
bool Unk_817410(const Unk_8139c0_Self* self, u8 pokeId, u16 types, u32 arg3);
void Unk_817460(const Unk_8139c0_Self* self, u8 pokeId, u8 value, u32 arg3);
void Unk_8174b0(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_8174f0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, bool arg3);
void Unk_817bb0(const Unk_8139c0_Self* self, u8 pokeId, u8 value);

// 0x7100810450
void Unk_810450(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, u8 value) {
    Unk_817bb0(self->field_20, Unk_7ee6b0_getField7d(poke), value);
    Unk_8150c0(self->field_18, 0x4e, Unk_7ee6b0_getField7d(poke), value);
}

// 0x71008104c0
void Unk_8104c0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8150c0(self->field_18, 0xa7, pokeId);
}

// 0x71008104d0
void Unk_8104d0(const Unk_811d90_Self* self, u8 pokeId, u32 arg2, bool arg3) {
    Unk_8174f0(self->field_20, pokeId, arg2, arg3);
    Unk_8150c0(self->field_18, 0x6b, pokeId, static_cast<u8>(arg2), arg3);
}

// 0x7100810600
void Unk_810600(const Unk_811d90_Self* self, u8 pokeId, u8 otherId) {
    Unk_8173b0(self->field_20, pokeId, otherId);
    Unk_8150c0(self->field_18, 0x37, pokeId, otherId);
}

// 0x7100810650
bool Unk_810650(const Unk_811d90_Self* self, u8 pokeId, u16 types, u32 arg3) {
    bool result = Unk_817410(self->field_20, pokeId, types, arg3);
    Unk_8150c0(self->field_18, 0x1a, pokeId, static_cast<u8>(arg3), types);
    return result;
}

// 0x71008106b0
void Unk_8106b0(const Unk_811d90_Self* self, u8 pokeId, u8 value, u32 arg3) {
    Unk_817460(self->field_20, pokeId, value, arg3);
    Unk_8150c0(self->field_18, 0x1b, pokeId, value, static_cast<u8>(arg3));
}

// 0x7100810700
void Unk_810700(const Unk_811d90_Self* self, u8 pokeId, u16 value) {
    Unk_8174b0(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x24, pokeId, value);
}
