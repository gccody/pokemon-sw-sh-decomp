// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_7f0ba0(const Unk_7ee6b0* self, u32 index);
void Unk_7f26e0(Unk_7ee6b0* self, u32 index);

void Unk_816a20(const Unk_8139c0_Self* self, u8 pokeId, u32 flag);
void Unk_816a60(const Unk_8139c0_Self* self, u8 pokeId, u32 flag);
void Unk_816aa0(const Unk_8139c0_Self* self, u8 pokeId, u32 index, u8 value);
void Unk_816b40(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u32 value);
void Unk_816b90(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_816bc0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_816cb0(const Unk_8139c0_Self* self, u8 pokeId, u8 slot, u8 count);
void Unk_816e00(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_816e40(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_816e80(const Unk_8139c0_Self* self, u8 pokeId);

// 0x710080f7a0
void Unk_80f7a0(void* self, const Unk_7ee6b0* poke, u32 flag) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    Unk_816a20(server->field_20, Unk_7ee6b0_getField7d(poke), flag);
    Unk_8150c0(server->field_18, 0x1f, Unk_7ee6b0_getField7d(poke), flag);
}

// 0x710080f810
void Unk_80f810(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, u32 flag) {
    Unk_816a60(self->field_20, Unk_7ee6b0_getField7d(poke), flag);
    Unk_8150c0(self->field_18, 0x22, Unk_7ee6b0_getField7d(poke), flag);
}

// 0x710080f880
// NON_MATCHING: the original takes the index as a u32 (it passes it on to
// Unk_816aa0 unmasked and masks it only for the command); the name's u8 index
// makes clang mask it up front.
void Unk_80f880(void* self, const Unk_7ee6b0* poke, u8 index, u8 value) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    Unk_816aa0(server->field_20, Unk_7ee6b0_getField7d(poke), index, value);
    Unk_8150c0(server->field_18, 0x33, Unk_7ee6b0_getField7d(poke), index, value);
}

// 0x710080f900
// The index goes to the Pokemon as a u32, and into the command as one byte.
void Unk_80f900(const Unk_811d90_Self* self, Unk_7ee6b0* poke, u32 index) {
    if (poke != nullptr) {
        Unk_7f26e0(poke, index);
        u8 value = Unk_7f0ba0(poke, index);
        Unk_8150c0(self->field_18, 0x33, Unk_7ee6b0_getField7d(poke), static_cast<u8>(index),
                   value);
    }
}

// 0x710080f970
void Unk_80f970(const Unk_811d90_Self* self, u8 pokeId, u8 index, u32 value) {
    Unk_816b40(self->field_20, pokeId, index, value);
    Unk_8150c0(self->field_18, 0x35, pokeId, index, value);
}

// 0x710080f9c0
void Unk_80f9c0(const Unk_811d90_Self* self, u8 pokeId, u8 index) {
    Unk_816b40(self->field_20, pokeId, index, 1);
    Unk_8150c0(self->field_18, 0x35, pokeId, index, 1);
}

// 0x710080fa10
void Unk_80fa10(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_816b90(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x23, pokeId);
}

// 0x710080fa50
void Unk_80fa50(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_816bc0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x36, pokeId);
}

// 0x710080fa90
void Unk_80fa90(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, u16 value) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_816e00(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x25, pokeId, value);
}

// 0x710080faf0
void Unk_80faf0(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, u16 value) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_816e40(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x1c, pokeId, value);
}

// 0x710080fb50
void Unk_80fb50(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_816e80(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x3c, pokeId);
}

// 0x710080feb0
void Unk_80feb0(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, u8 slot, u8 count) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_816cb0(self->field_20, pokeId, slot, count);
    Unk_8150c0(self->field_18, 5, pokeId, slot, count);
}
