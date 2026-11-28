// Scope: common
// Battle server command wrappers: act on the server's state or the main
// module's entries, then queue the command or message for the clients.
// Placeholder names: rename once they're known.
#include "unsorted/Unk_80e920.h"

// The main module's lookups by two keys (src/unsorted/leaf/Unk_7fe1d0.cpp).
struct Unk_7fe210;
struct Unk_7fe230;
struct Unk_8022b0_Entry;
Unk_8022b0_Entry* Unk_7fe210_call(const Unk_7fe210* self, u32 value, u32 arg2);
void* Unk_7fe230_call(const Unk_7fe230* self, u32 value, u32 arg2);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);

bool Unk_802430(Unk_8022b0_Entry* self);
bool Unk_8023b0(Unk_8022b0_Entry* self, const u64* value);
struct Unk_802500;
void Unk_802500_set(Unk_802500* self);

// Declared as src/unsorted/leaf/Unk_801780.cpp names them.
struct Unk_801780_arg1 {
    u32 field_0;
};
struct Unk_801780;
bool Unk_801780_update(Unk_801780* self, const Unk_801780_arg1* value);

bool Unk_7fa9c0(u8 position);
// A client's id (5: none). A scoped enum: the queue's variadic arguments get
// it as is, without the promotion a u8 gets.
enum class Unk_80f3e0_Client : u8 {};
Unk_80f3e0_Client Unk_7c9b60(void* self, u8 client, u8 index);
Unk_80f3e0_Client Unk_803600(void* self, u8 id);
void Unk_7f8ba0(const void* condition, u32* outA, u32* outB);
u32 Unk_7ef710(const Unk_7ee6b0* self, u32 index);
struct Unk_7f09c0;
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
bool Unk_786d90(u16 id);

void Unk_816960(const Unk_8139c0_Self* self, u8 pokeId, u32 flag);
void Unk_8169e0(const Unk_8139c0_Self* self, u8 pokeId, u32 flag);
void Unk_816ff0(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u8 other, u32 arg4);
bool Unk_8171f0(const Unk_8139c0_Self* self, u32 arg1, u32 arg2, u32 arg3);

static inline Unk_8022b0_Entry* Unk_80f100_Entry(const Unk_80e920_Self* self, u32 key1, u32 key2) {
    return Unk_7fe210_call(static_cast<const Unk_7fe210*>(self->field_10), key1, key2);
}

// Queues command 0x47 with a condition's two values (Unk_7f8ba0 reads them).
static inline void Unk_80f100_PutCondition(u64 que, u8 pos, u32 kind, const u64* condition) {
    u32 a = 0;
    u32 b = 0;
    Unk_7f8ba0(condition, &a, &b);
    Unk_8150c0(que, 0x47, pos, kind, a, b);
}

// 0x710080f100
bool Unk_80f100(const Unk_80e920_Self* self, u32 pos, u32 kind, const u64* value) {
    if (!Unk_7fa9c0(pos))
        return false;
    if (!Unk_8023b0(Unk_80f100_Entry(self, pos, kind), value))
        return false;
    Unk_80f100_PutCondition(self->field_18, pos, kind, value);
    return true;
}

// 0x710080f1a0
bool Unk_80f1a0(const Unk_80e920_Self* self, u32 pos, u32 kind) {
    if (!Unk_7fa9c0(pos))
        return false;
    if (!Unk_802430(Unk_80f100_Entry(self, pos, kind)))
        return false;
    Unk_8150c0(self->field_18, 0x48, static_cast<u8>(pos), kind);
    return true;
}

// 0x710080f230
void Unk_80f230(const Unk_80e920_Self* self, u32 pos, u32 kind) {
    Unk_802500_set(reinterpret_cast<Unk_802500*>(Unk_80f100_Entry(self, pos, kind)));
    Unk_8150c0(self->field_18, 0x49, static_cast<u8>(pos), kind);
}

// 0x710080f280
bool Unk_80f280(const Unk_80e920_Self* self, u32 arg1, u32 arg2, u32 arg3) {
    if (!Unk_8171f0(self->field_20, arg1, arg2, arg3))
        return false;
    Unk_8150c0(self->field_18, 0x4a, static_cast<u8>(arg1), static_cast<u8>(arg2), arg3);
    return true;
}

// 0x710080f2f0
bool Unk_80f2f0(const Unk_80e920_Self* self, u32 key1, u32 key2, const Unk_801780_arg1* value) {
    void* other = Unk_7fe230_call(static_cast<const Unk_7fe230*>(self->field_10), key1, key2);
    if (!Unk_801780_update(static_cast<Unk_801780*>(other), value))
        return false;
    Unk_8150c0(self->field_18, 0x43, key2, key1, value->field_0);
    return true;
}

// Queues command 0xa2 for a client, unless there's none (5).
static inline void Unk_80f3e0_Put(const Unk_80e920_Self* self, Unk_80f3e0_Client client, u16 id) {
    if (client == static_cast<Unk_80f3e0_Client>(5))
        return;
    Unk_8150c0(self->field_18, 0xa2, client, id);
}

// 0x710080f3e0
void Unk_80f3e0(void* self, u8 client, u16 id) {
    Unk_80f3e0_Put(static_cast<const Unk_80e920_Self*>(self),
                   static_cast<Unk_80f3e0_Client>(client), id);
}

// 0x710080f370
void Unk_80f370(const Unk_80e920_Self* self, const Unk_7ee6b0* poke, u16 id) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_80f3e0_Put(
        self,
        Unk_803600(Unk_7fe250_getFielda8(static_cast<const Unk_7fe250*>(self->field_10)), pokeId),
        id);
}

// 0x710080f410
void Unk_80f410(const Unk_80e920_Self* self, u8 pos, u16 id) {
    Unk_80f3e0_Put(self, Unk_7c9b60(self->field_8, pos, 0), id);
}

// 0x710080f470
void Unk_80f470(const Unk_80e920_Self* self, u32 arg1, u32 arg2, u16 arg3) {
    Unk_8150c0(self->field_18, 0xa4, arg1, arg2, arg3);
}

// 0x710080f490
void Unk_80f490(const Unk_80e920_Self* self, const Unk_7ee6b0* poke) {
    Unk_80f370(self, poke, 0x2f);
    Unk_816320(self->field_18, 0xba, 0x1d8, Unk_7ee6b0_getField7d(poke), 0xffff0000);
}

// 0x710080f520
void Unk_80f520(const Unk_80e920_Self* self, const Unk_7ee6b0* poke) {
    u32 value = Unk_7ef710(poke, 7);
    Unk_80f370(self, poke, 0x30);
    Unk_816320(self->field_18, 0xba, 0x1c4, Unk_7ee6b0_getField7d(poke), static_cast<u16>(value),
               0xffff0000);
}

// 0x710080f5c0
void Unk_80f5c0(const Unk_80e920_Self* self, const Unk_7ee6b0* poke) {
    bool flag = Unk_786d90(Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(poke)));
    Unk_8150c0(self->field_18, 0x96, Unk_7ee6b0_getField7d(poke), flag);
}

// 0x710080f620
void Unk_80f620(const Unk_80e920_Self* self, const Unk_7ee6b0* poke) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_816320(self->field_18, 0xba, 0x47c, pokeId, 0xffff0000);
}

// 0x710080f660
void Unk_80f660(const Unk_80e920_Self* self, u8 pokeId, u8 index, u8 other, u32 arg4) {
    Unk_816ff0(self->field_20, pokeId, index, other, arg4);
    Unk_8150c0(self->field_18, 0x16, pokeId, index, other, static_cast<u16>(arg4));
}

// 0x710080f6c0
void Unk_80f6c0(const Unk_80e920_Self* self, const Unk_7ee6b0* poke, u32 flag) {
    Unk_816960(self->field_20, Unk_7ee6b0_getField7d(poke), flag);
    Unk_8150c0(self->field_18, 0x20, Unk_7ee6b0_getField7d(poke), flag);
}

// 0x710080f730
void Unk_80f730(const Unk_80e920_Self* self, const Unk_7ee6b0* poke, u32 flag) {
    Unk_8169e0(self->field_20, Unk_7ee6b0_getField7d(poke), flag);
    Unk_8150c0(self->field_18, 0x1e, Unk_7ee6b0_getField7d(poke), flag);
}
