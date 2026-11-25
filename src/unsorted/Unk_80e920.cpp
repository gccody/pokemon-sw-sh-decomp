// Scope: common
// Battle server command wrappers: queue a message (Unk_816320, mostly the
// one a kind of thing picks) or act on the server's state at +0x20, then
// queue the command for the clients. Placeholder names: rename once they're
// known.
#include "unsorted/Unk_80e920.h"

u8 Unk_7cc1b0(void* self, void* poke);
bool Unk_7ef5d0(Unk_7ee6b0* self, u32 arg);
u32 Unk_7f7690(u32 max);
u8 Unk_7cb490(u8 position);
u16 Unk_803c00(u32 kind);
void Unk_7f8ba0(const void* condition, u32* outA, u32* outB);

bool Unk_8170d0(const Unk_8139c0_Self* self, u32 condition, const u64* value);
void Unk_817100(const Unk_8139c0_Self* self, u32 condition, void* value);
bool Unk_817130(const Unk_8139c0_Self* self, u32 value);
bool Unk_817160(const Unk_8139c0_Self* self, u32 index);
void Unk_817190(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);
bool Unk_8171c0(const Unk_8139c0_Self* self, u8 arg1, u32 arg2);

// 0x710080e920
// NON_MATCHING: block order only. The original places the default message's
// block (0x55) right after the one cases 30 to 32 share; clang places it where
// case 5 would be. The order of the cases in the source doesn't change it.
void Unk_80e920(void* self, void* object, u32 id, u32 arg3) {
    const Unk_80e920_Self* server = static_cast<const Unk_80e920_Self*>(self);
    Unk_7ee6b0* poke = static_cast<Unk_7ee6b0*>(object);
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    switch (static_cast<u8>(arg3)) {
        case 1:
            Unk_816320(server->field_18, 0xb9, 0x60, pokeId, 0xffff0000);
            break;
        case 2:
            Unk_816320(server->field_18, 0xba, 0x1a4, pokeId, 0xffff0000);
            if (Unk_7cc1b0(server->field_8, object) == 0xff)
                Unk_816320(server->field_18, 0xb9, 0x109, 0xffff0000);
            break;
        case 3:
            Unk_816320(server->field_18, 0xba, 0x178, pokeId, 0xffff0000);
            break;
        case 4:
            Unk_816320(server->field_18, 0xba, 0x18c, pokeId, 0xffff0000);
            break;
        case 6:
            Unk_816320(server->field_18, 0xba, 0x1ec, pokeId, 0xffff0000);
            break;
        case 7:
            Unk_816320(server->field_18, 0xba, 0x1f0, pokeId, 0xffff0000);
            break;
        case 8:
            Unk_816320(server->field_18, 0xba, 0x1c8, pokeId, 0xffff0000);
            break;
        case 9:
            Unk_816320(server->field_18, 0xba, 0x322, pokeId, id, 0xffff0000);
            break;
        case 10:
            Unk_816320(server->field_18, 0xba, 0x302, pokeId, id, 0xffff0000);
            break;
        case 11:
            Unk_816320(server->field_18, 0xba, 0x30e, pokeId, id, 0xffff0000);
            break;
        case 12:
            Unk_816320(server->field_18, 0xba, 0x31a, pokeId, id, 0xffff0000);
            break;
        case 13:
            Unk_816320(server->field_18, 0xba, 0x4b4, pokeId, id, 0xffff0000);
            break;
        case 14:
            Unk_816320(server->field_18, 0xba, 0x4b8, pokeId, 0xffff0000);
            break;
        case 15:
            Unk_8150c0(server->field_18, 0xb6, pokeId);
            Unk_816320(server->field_18, 0xba, 0x262, pokeId, 0xffff0000);
            Unk_8150c0(server->field_18, 0xb7, pokeId);
            break;
        case 18:
            Unk_816320(server->field_18, 0xba, 0x25a, pokeId, 0xffff0000);
            break;
        case 19:
        case 25:
            break;
        case 20:
            Unk_816320(server->field_18, 0xba, 0x5c0, pokeId, id, 0xffff0000);
            break;
        case 22:
            if (Unk_7ef5d0(poke, 0)) {
                Unk_816320(server->field_18, 0xb9, 0xd9, pokeId, 0xffff0000);
            } else {
                u8 random = Unk_7f7690(4);
                Unk_816320(server->field_18, 0xb9, 0xd3 + random, pokeId, 0xffff0000);
            }
            break;
        case 23:
            Unk_816320(server->field_18, 0xb9, 0xd8, pokeId, 0xffff0000);
            break;
        case 26:
            Unk_816320(server->field_18, 0xb9, 0x110, 0xffff0000);
            break;
        case 27:
            Unk_816320(server->field_18, 0xb9, 0x123, 0xffff0000);
            break;
        case 28:
            Unk_816320(server->field_18, 0xb9, 0x124, 0xffff0000);
            break;
        case 29:
            Unk_816320(server->field_18, 0xb9, 0x129, pokeId, 0xffff0000);
            break;
        case 30:
        case 31:
        case 32:
            Unk_816320(server->field_18, 0xb9, 0x12a, pokeId, 0xffff0000);
            break;
        case 33:
            Unk_816320(server->field_18, 0xba, 0x744, pokeId, 0xffff0000);
            break;
        case 34:
            Unk_816320(server->field_18, 0xba, 0x760, pokeId, 0xffff0000);
            break;
        case 35:
            Unk_816320(server->field_18, 0xba, 0x7ae, pokeId, 0xffff0000);
            break;
        case 36:
            Unk_816320(server->field_18, 0xb9, 0x1d6, pokeId, 0xffff0000);
            break;
        case 40:
            Unk_816320(server->field_18, 0xb9, 0x19a, pokeId, 0xffff0000);
            break;
        case 41:
            Unk_816320(server->field_18, 0xb9, 0x19b, pokeId, 0xffff0000);
            break;
        default:
            Unk_816320(server->field_18, 0xb9, 0x55, pokeId, 0xffff0000);
            break;
    }
}

// 0x710080ecb0
void Unk_80ecb0(const Unk_80e920_Self* self, const Unk_7ee6b0* poke) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    u8 side = Unk_7cb490(pokeId);
    Unk_8150c0(self->field_18, 0x91, side, pokeId);
}

// 0x710080ecf0
void Unk_80ecf0(const Unk_80e920_Self* self, const Unk_7ee6b0* poke, u8 kind, u32 value, u8 other) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    if (kind == 1) {
        switch (value) {
            case 1:
                Unk_816320(self->field_18, 0xba, 0x180, pokeId, 0xffff0000);
                return;
            case 2:
                Unk_816320(self->field_18, 0xba, 0x1ac, pokeId, 0xffff0000);
                return;
            case 3:
                Unk_816320(self->field_18, 0xba, 0x194, pokeId, 0xffff0000);
                return;
            case 4:
                Unk_816320(self->field_18, 0xba, 0x16c, pokeId, 0xffff0000);
                return;
            case 5:
                Unk_816320(self->field_18, 0xba, 0x154, pokeId, 0xffff0000);
                return;
            case 6:
                Unk_816320(self->field_18, 0xba, 0x1e0, pokeId, 0xffff0000);
                return;
            case 15:
                Unk_816320(self->field_18, 0xba, 0x28, pokeId, 0xffff0000);
                return;
            case 20:
                return;
        }
    } else if (kind == 2) {
        if (other == 5) {
            s16 id = Unk_803c00(value);
            if (id >= 0) {
                Unk_816320(self->field_18, 0xba, id, pokeId, 0xffff0000);
                return;
            }
        }
        Unk_816320(self->field_18, 0xba, 0x120, pokeId, 0xffff0000);
        return;
    } else if (kind == 3) {
        Unk_816320(self->field_18, 0xb9, 0x17b, pokeId, 0xffff0000);
        return;
    }
    Unk_816320(self->field_18, 0xb9, 0x55, 0xffff0000);
}

// 0x710080ee90
void Unk_80ee90(const Unk_80e920_Self* self, u8 pokeId, s32 kind) {
    u32 id;
    switch (kind) {
        case 0:
            id = 0x8f;
            break;
        case 1:
            id = 0x93;
            break;
        case 2:
            id = 0x9b;
            break;
        case 3:
            id = 0x9f;
            break;
        case 4:
            id = 0xa3;
            break;
        case 5:
            id = 0xa7;
            break;
        case 6:
            id = 0xab;
            break;
        case 7:
            id = 0xaf;
            break;
        case 8:
            id = 0xb3;
            break;
        case 11:
            id = 0xbb;
            break;
        case 12:
            id = 0xbf;
            break;
        case 13:
            id = 0xc3;
            break;
        case 14:
            id = 0xe9;
            break;
        case 17:
            id = 0x97;
            break;
        case 19:
            id = 0x1cd;
            break;
        default:
            return;
    }
    Unk_816320(self->field_18, 0xb9, id, pokeId, 0xffff0000);
}

// Queues command `cmd` with a condition's two values (Unk_7f8ba0 reads them).
static inline void Unk_80e920_PutCondition(u64 que, u32 cmd, u8 id, const u64* condition) {
    u32 a = 0;
    u32 b = 0;
    Unk_7f8ba0(condition, &a, &b);
    Unk_8150c0(que, cmd, id, a, b);
}

// 0x710080eed0
bool Unk_80eed0(const Unk_80e920_Self* self, u32 condition, const u64* value) {
    if (!Unk_8170d0(self->field_20, condition, value))
        return false;
    Unk_80e920_PutCondition(self->field_18, 0x30, condition, value);
    return true;
}

// 0x710080ef50
void Unk_80ef50(const Unk_80e920_Self* self, u32 condition, u64* value) {
    Unk_817100(self->field_20, condition, value);
    Unk_80e920_PutCondition(self->field_18, 0x2e, condition, value);
}

// 0x710080efb0
bool Unk_80efb0(const Unk_80e920_Self* self, u32 value) {
    bool result = Unk_817130(self->field_20, value);
    Unk_8150c0(self->field_18, 0x32, static_cast<u8>(value));
    return result;
}

// 0x710080f000
bool Unk_80f000(const Unk_80e920_Self* self, u32 index) {
    bool result = Unk_817160(self->field_20, index);
    Unk_8150c0(self->field_18, 0x40, index);
    return result;
}

// 0x710080f050
void Unk_80f050(const Unk_80e920_Self* self, u32 arg1, u32 arg2) {
    Unk_817190(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x2f, static_cast<u8>(arg1), static_cast<u8>(arg2));
}

// 0x710080f0a0
bool Unk_80f0a0(const Unk_80e920_Self* self, const Unk_7ee6b0* poke, u32 arg2) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    bool result = Unk_8171c0(self->field_20, pokeId, arg2);
    Unk_8150c0(self->field_18, 0x31, pokeId, static_cast<u8>(arg2));
    return result;
}
