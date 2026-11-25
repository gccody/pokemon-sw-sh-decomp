// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

void Unk_816320(u64, u16, ...);
void Unk_817de0(const Unk_8139c0_Self* self);

void Unk_817e00(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817e30(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817e90(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
void Unk_817ed0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817f00(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817f30(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817f60(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
void Unk_817fa0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818040(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
void Unk_818080(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8180c0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818100(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818140(const Unk_8139c0_Self* self, u8 pokeId);

// 0x7100811990
void Unk_811990(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_817e90(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x5d, arg1, arg2);
}

// 0x71008119e0
void Unk_8119e0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817ed0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x5e, pokeId);
}

// 0x7100811a20
void Unk_811a20(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817f00(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x5f, pokeId);
}

// 0x7100811a60
void Unk_811a60(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817f30(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x60, pokeId);
}

// 0x7100811aa0
void Unk_811aa0(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_817f60(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x61, arg1, arg2);
}

// 0x7100811af0
void Unk_811af0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8150c0(self->field_18, 0xa2, 4, 0x7f);
    Unk_816320(self->field_18, 0xb9, 0x180, pokeId, 0xffff0000);
}

// 0x7100811b40
void Unk_811b40(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817fa0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x51, pokeId);
}

// 0x7100811b80
void Unk_811b80(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_818040(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x53, arg1, arg2);
}

// 0x7100811bd0
void Unk_811bd0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818080(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x54, pokeId);
}

// 0x7100811c10
void Unk_811c10(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8180c0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x55, pokeId);
}

// 0x7100811c50
void Unk_811c50(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818100(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x56, pokeId);
}

// 0x7100811c90
void Unk_811c90(const Unk_811d90_Self* self) {
    Unk_817de0(self->field_20);
    Unk_8150c0(self->field_18, 0x65);
}

// 0x7100811cc0
void Unk_811cc0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817e00(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x66, pokeId);
}

// 0x7100811d00
void Unk_811d00(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817e30(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x67, pokeId);
}

// 0x7100811d40
void Unk_811d40(const Unk_811d90_Self* self) {
    Unk_8150c0(self->field_18, 0xb4);
}

// 0x7100811d50
void Unk_811d50(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818140(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x57, pokeId);
}
