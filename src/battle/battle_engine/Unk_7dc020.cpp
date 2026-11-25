// Scope: common
// Battle client commands (0x71007dc020 to 0x71007dc3e0): each reads the
// command's arguments and forwards them to a server command or to an entry
// the main module at +0x70 looks up. Placeholder names: rename once the class
// is known.
#include "battle/battle_engine/Unk_7dc020.h"

// The server commands (src/battle/battle_engine/Unk_8139c0.cpp).
void Unk_816f20(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_817160(const Unk_8139c0_Self* self, u32 index);
void Unk_817370(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_8178c0(const Unk_8139c0_Self* self, u8 pokeId);

// What the main module at +0x48 and +0x68 looks up by two keys
// (src/unsorted/leaf/Unk_7fe1d0.cpp declares the lookups as void).
struct Unk_7fe210;
struct Unk_7fe230;
struct Unk_8022b0_Entry;
Unk_8022b0_Entry* Unk_7fe210_call(const Unk_7fe210* self, u64 value, u64 arg2);
void* Unk_7fe230_call(const Unk_7fe230* self, u64 value, u64 arg2);

bool Unk_802430(Unk_8022b0_Entry* self);
bool Unk_8023b0(Unk_8022b0_Entry* self, const u64* value);
struct Unk_802500;
void Unk_802500_set(Unk_802500* self);

// A condition's value (src/battle/battle_engine/Unk_7f8780.cpp would hold it).
void Unk_7f8bc0(u64* self, u32 arg1, u32 arg2);

// Declared as src/unsorted/leaf/Unk_801780.cpp names them.
struct Unk_801780_arg1 {
    u32 field_0;
};
struct Unk_801780;
u32 Unk_801780_update(Unk_801780* self, const Unk_801780_arg1* value);
struct Unk_8017c0_arg1 {
    u32 field_0;
};
struct Unk_8017c0;
void Unk_8017c0_set(Unk_8017c0* self, const Unk_8017c0_arg1* value);
struct Unk_8017d0;
void Unk_8017d0_clearField10(Unk_8017d0* self);

static inline Unk_8022b0_Entry* Unk_7dc020_Entry(const Unk_7cdac0_Self* self, u32 key1, u32 key2) {
    return Unk_7fe210_call(reinterpret_cast<const Unk_7fe210*>(self->field_70), key1, key2);
}

static inline void* Unk_7dc020_Other(const Unk_7cdac0_Self* self, u32 key1, u32 key2) {
    return Unk_7fe230_call(reinterpret_cast<const Unk_7fe230*>(self->field_70), key1, key2);
}

// 0x71007dc020
bool Unk_7dc020(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 value = args[1];
    Unk_816f20(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc0d0
bool Unk_7dc0d0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_8178c0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc100
bool Unk_7dc100(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 index = args[0];
    Unk_817160(Unk_7cdac0_Server(self), index);
    return true;
}

// 0x71007dc1a0
bool Unk_7dc1a0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 value = args[1];
    Unk_817370(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc1e0
// NON_MATCHING: Unk_7fe230_call's name gives its keys as u64; they are 32-bit (mov w, not x).
bool Unk_7dc1e0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 key1 = args[0];
    u32 key2 = args[1];
    Unk_801780_arg1 value;
    value.field_0 = args[2];
    Unk_801780_update(static_cast<Unk_801780*>(Unk_7dc020_Other(self, key2, key1)), &value);
    return true;
}

// 0x71007dc220
// NON_MATCHING: Unk_7fe230_call's name gives its keys as u64; they are 32-bit (mov w, not x).
bool Unk_7dc220(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_8017d0_clearField10(static_cast<Unk_8017d0*>(Unk_7dc020_Other(self, args[1], args[0])));
    return true;
}

// 0x71007dc250
// NON_MATCHING: Unk_7fe230_call's name gives its keys as u64; they are 32-bit (mov w, not x).
bool Unk_7dc250(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 key1 = args[0];
    u32 key2 = args[1];
    Unk_8017c0_arg1 value;
    value.field_0 = args[2];
    Unk_8017c0_set(static_cast<Unk_8017c0*>(Unk_7dc020_Other(self, key2, key1)), &value);
    return true;
}

// 0x71007dc330
// NON_MATCHING: Unk_7fe210_call's name gives its keys as u64; they are 32-bit (mov w, not x).
bool Unk_7dc330(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 key1 = args[0];
    u32 key2 = args[1];
    u64 value;
    Unk_7f8bc0(&value, args[2], args[3]);
    Unk_8023b0(Unk_7dc020_Entry(self, key1, key2), &value);
    return true;
}

// 0x71007dc380
bool Unk_7dc380(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_802430(Unk_7dc020_Entry(self, args[0], args[1]));
    return true;
}

// 0x71007dc3b0
bool Unk_7dc3b0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_802500_set(reinterpret_cast<Unk_802500*>(Unk_7dc020_Entry(self, args[0], args[1])));
    return true;
}
