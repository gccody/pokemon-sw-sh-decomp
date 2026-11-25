// Scope: common
// Four flags kept in the scrambled block store (src/unsorted/families/
// Unk_13471e0.h), each a bool block of its own. Placeholder names: rename once
// the flags are known.
#include <types.h>

#include "unsorted/families/Unk_13471e0.h"

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// 0x710135caa0: writes a bool block, adding it if it's not there (as
// Unk_13471e0_Store::Unk_13456e0, sized by the value).
bool Unk_135caa0(Unk_13471e0_Store* self, const u32& key, const bool& value);

// What Unk_135e220 returns: whether the block was found, and its value.
struct Unk_135e220_Result {
    u8 field_0;
    u8 field_1;
};

// 0x710135e220: reads a bool block.
Unk_135e220_Result Unk_135e220(Unk_13471e0_Store* self, const u32& key);

// The flags' keys in the store.
extern const u32 Unk_1f345a4 __attribute__((visibility("hidden")));
extern const u32 Unk_1f345a8 __attribute__((visibility("hidden")));
extern const u32 Unk_1f345ac __attribute__((visibility("hidden")));
extern const u32 Unk_1f345b0 __attribute__((visibility("hidden")));

// Writes a flag.
static inline bool Unk_Write(const u32& key, bool value) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    return Unk_135caa0(store, key, value);
}

// Reads a flag; tells the store's listener when it isn't there.
static inline bool Unk_Read(const u32& key) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_135e220_Result result = Unk_135e220(store, key);
    if (!result.field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&key);
    return result.field_1 != 0;
}

// 0x7101387400
bool Unk_1387400(bool value) {
    return Unk_Write(Unk_1f345a4, value);
}

// 0x7101387450
bool Unk_1387450() {
    return Unk_Read(Unk_1f345a4);
}

// 0x71013874d0
bool Unk_13874d0(bool value) {
    return Unk_Write(Unk_1f345a8, value);
}

// 0x7101387520
bool Unk_1387520() {
    return Unk_Read(Unk_1f345a8);
}

// 0x71013875a0
bool Unk_13875a0(bool value) {
    return Unk_Write(Unk_1f345ac, value);
}

// 0x71013875f0
bool Unk_13875f0() {
    return Unk_Read(Unk_1f345ac);
}

// 0x7101387670
bool Unk_1387670(bool value) {
    return Unk_Write(Unk_1f345b0, value);
}

// 0x71013876c0
bool Unk_13876c0() {
    return Unk_Read(Unk_1f345b0);
}
