// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

struct Unk_7f29c0;
struct Unk_7f29d0;

// Returns one flag bit: the caller tests bit 0 of the result.
bool Unk_7f29c0_get(const Unk_7f29c0* self);
u8 Unk_7f29d0_getField246(const Unk_7f29d0* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

void Unk_8175a0(const Unk_8139c0_Self* self, u8 pokeId, u32 stat, u16 value);
void Unk_8175f0(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_817770(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8177b0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8177f0(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_817830(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817860(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_8178c0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817910(const Unk_8139c0_Self* self,
                u8 pokeId,
                u32 value,
                bool* outA,
                const u64* arg4,
                bool* outB);
void Unk_817980(const Unk_8139c0_Self* self,
                u8 arg1,
                u8 arg2,
                u8 arg3,
                bool arg4,
                u32 arg5,
                u32 arg6);

// 0x7100810750
// The stat goes to the server as a u32, and into the command as one byte.
void Unk_810750(const Unk_811d90_Self* self, u8 pokeId, u32 stat, u16 value) {
    Unk_8175a0(self->field_20, pokeId, stat, value);
    Unk_8150c0(self->field_18, 0x17, pokeId, static_cast<u8>(stat), value);
}

// 0x71008107a0
void Unk_8107a0(const Unk_811d90_Self* self, u8 pokeId, u16 value) {
    Unk_8175f0(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x18, pokeId, value);
}

// 0x71008107f0
void Unk_8107f0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817770(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x27, pokeId);
}

// 0x7100810830
void Unk_810830(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8177b0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x28, pokeId);
}

// 0x7100810870
void Unk_810870(const Unk_811d90_Self* self, u8 pokeId, u16 value) {
    Unk_8177f0(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x38, pokeId, value);
}

// 0x71008108c0
void Unk_8108c0(void* self, u8 pokeId) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    Unk_817830(server->field_20, pokeId);
    Unk_8150c0(server->field_18, 0x39, pokeId);
}

// 0x7100810900
void Unk_810900(const Unk_811d90_Self* self, u8 pokeId, u16 value) {
    Unk_817860(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x3, pokeId, value);
}

// 0x7100810950
void Unk_810950(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8178c0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x3f, pokeId);
}

// 0x7100810990
void Unk_810990(const Unk_811d90_Self* self,
                u8 pokeId,
                u32 value,
                bool* outA,
                const u64* arg4,
                bool* outB) {
    Unk_817910(self->field_20, pokeId, value, outA, arg4, outB);
    Unk_8150c0(self->field_18, 0x19, pokeId, value);
}

// 0x71008109e0
void Unk_8109e0(const Unk_811d90_Self* self,
                u8 arg1,
                u32 arg2,
                u8 arg3,
                bool arg4,
                u32 arg5,
                u32 arg6) {
    Unk_817980(self->field_20, arg1, arg2, arg3, arg4, arg5, arg6);
    Unk_8150c0(self->field_18, 0x1d, arg1, arg2, arg3, arg4, 0, arg5, arg6);
}

// 0x7100810a90
void Unk_810a90(const Unk_811d90_Self* self, const Unk_7ee6b0* poke) {
    if (poke != nullptr) {
        u8 pokeId = Unk_7ee6b0_getField7d(poke);
        if (pokeId != 0x1f)
            Unk_8150c0(self->field_18, 0xb6, pokeId);
    }
}

// 0x7100810b00
void Unk_810b00(const Unk_811d90_Self* self, const Unk_7ee6b0* poke) {
    if (poke != nullptr) {
        u8 pokeId = Unk_7ee6b0_getField7d(poke);
        if (pokeId != 0x1f)
            Unk_8150c0(self->field_18, 0xb7, pokeId);
    }
}

// 0x7100810b50
void Unk_810b50(const Unk_811d90_Self* self, const Unk_7ee6b0* poke) {
    u8 pokeId;
    if (Unk_7f29c0_get(reinterpret_cast<const Unk_7f29c0*>(poke)))
        pokeId = Unk_7f29d0_getField246(reinterpret_cast<const Unk_7f29d0*>(poke));
    else
        pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_8150c0(self->field_18, 0x4b, pokeId);
}

// 0x7100810ba0
void Unk_810ba0(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, bool flag) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_8150c0(self->field_18, 0x4c, pokeId, flag);
}
