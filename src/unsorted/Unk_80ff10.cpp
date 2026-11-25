// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_80f7a0.h"

u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

void Unk_8173b0(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId);
// Returns what Unk_7f22a0 returns: the caller keeps bit 0 of it.
bool Unk_817410(const Unk_8139c0_Self* self, u8 pokeId, u16 types, u32 arg3);
void Unk_817460(const Unk_8139c0_Self* self, u8 pokeId, u8 value, u32 arg3);
void Unk_8174b0(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_8174f0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, bool arg3);
void Unk_817bb0(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_816eb0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_816ee0(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
u64 Unk_7ef750(const Unk_7ee6b0* self, u32 index);
u8 Unk_803600(void* self, u8 id);
void Unk_816f20(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId);
void Unk_816f90(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 arg2,
                u8 arg3,
                u8 arg4,
                u32 arg5,
                u16 arg6,
                u16 arg7);

u32 Unk_7f02d0(Unk_7ee6b0* self, u8 slot, u8 count);
u32 Unk_7f0320(Unk_7ee6b0* self, u8 slot, u8 count);
void Unk_7f1490(Unk_7ee6b0* self, u32 index, const u64* condition);
void Unk_7f8ba0(const void* condition, u32* outA, u32* outB);
struct Unk_7f88c0;
bool Unk_7f88c0_check(const Unk_7f88c0* self);

// 0x710080ff10
void Unk_80ff10(const Unk_811d90_Self* self, Unk_7ee6b0* poke, u8 slot, u8 count, bool flag) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    if (flag) {
        Unk_7f0320(poke, slot, count);
        Unk_8150c0(self->field_18, 0xb, pokeId, slot, count);
    } else {
        Unk_7f02d0(poke, slot, count);
        Unk_8150c0(self->field_18, 0xa, pokeId, slot, count);
    }
}

// Queues command 0x13: the condition's two values (Unk_7f8ba0 reads them).
static inline void Unk_80ffa0_PutCondition(u64 que, u8 pokeId, u8 index, const u64* condition) {
    u32 a = 0;
    u32 b = 0;
    Unk_7f8ba0(condition, &a, &b);
    Unk_8150c0(que, 0x13, pokeId, index, a, b);
}

// 0x710080ffa0
void Unk_80ffa0(const Unk_811d90_Self* self, Unk_7ee6b0* poke, s32 index, const u64* condition) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_7f1490(poke, index, condition);
    Unk_80ffa0_PutCondition(self->field_18, pokeId, index, condition);
    if (index <= 5) {
        s32 kind = index;
        if (index == 5)
            kind = Unk_7f88c0_check(reinterpret_cast<const Unk_7f88c0*>(condition)) ? 6 : 5;
        Unk_8150c0(self->field_18, 0x8b, pokeId, kind);
    }
}

// 0x7100810070
// NON_MATCHING: the original repeats the id lookup and the index test after
// each side of the `out` test (tail duplication: the registers and the block
// layout differ); this has them once.
void Unk_810070(void* self, Unk_7ee6b0* poke, s32 index, u64* out) {
    const Unk_80fb90_Self* server = static_cast<const Unk_80fb90_Self*>(self);
    if (index == 0)
        return;
    if (out != nullptr)
        *out = Unk_7ef750(poke, index);
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    if (index <= 5) {
        Unk_816eb0(server->field_20, pokeId);
        Unk_8150c0(server->field_18, 0x14, pokeId);
        if (Unk_803600(Unk_7fe250_getFielda8(server->field_10), pokeId) != 5)
            Unk_8150c0(server->field_18, 0x8b, pokeId, 0);
    } else {
        Unk_816ee0(server->field_20, pokeId, index);
        Unk_8150c0(server->field_18, 0x15, pokeId, static_cast<u16>(index));
    }
}

// Queues command 0x3d with the two ids.
static inline void Unk_810170_PutIds(u64 que, u8 pokeId, u8 otherId) {
    Unk_8150c0(que, 0x3d, pokeId, otherId);
}

// 0x7100810170
void Unk_810170(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, const Unk_7ee6b0* other) {
    Unk_816f20(self->field_20, Unk_7ee6b0_getField7d(poke), Unk_7ee6b0_getField7d(other));
    Unk_810170_PutIds(self->field_18, Unk_7ee6b0_getField7d(poke), Unk_7ee6b0_getField7d(other));
}

// Queues command 0x3e.
static inline void
Unk_810520_Put(u64 que, u8 pokeId, u8 otherId, u32 arg3, u8 arg4, u32 arg5, u16 arg6, u16 arg7) {
    Unk_8150c0(que, 0x3e, pokeId, otherId, arg3, arg4, arg5, arg6, arg7);
}

// 0x7100810520
// NON_MATCHING: the original takes arg3 as a u32 (it passes it to the command
// unmasked); the name's u8 makes clang mask it. With u32 it matches.
void Unk_810520(void* self,
                void* object,
                void* other,
                u8 arg3,
                u8 arg4,
                u32 arg5,
                u32 arg6,
                u16 arg7) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    const Unk_7ee6b0* poke = static_cast<const Unk_7ee6b0*>(object);
    const Unk_7ee6b0* target = static_cast<const Unk_7ee6b0*>(other);
    Unk_816f90(server->field_20, Unk_7ee6b0_getField7d(poke), Unk_7ee6b0_getField7d(target), arg3,
               arg4, arg5, arg6, arg7);
    Unk_810520_Put(server->field_18, Unk_7ee6b0_getField7d(poke), Unk_7ee6b0_getField7d(target),
                   arg3, arg4, arg5, arg6, arg7);
}

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
