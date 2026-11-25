// Scope: common
// Five more blocks of the scrambled block store (src/unsorted/families/
// Unk_13471e0.h), each read and written whole through template instantiations
// of its own: three blocks of 0x33d0 bytes sharing a type, one of 0x268 and one
// of 0x1c. Placeholder names: rename once the blocks are known.
#include <types.h>

#include "unsorted/families/Unk_13471e0.h"

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The blocks' keys in the store.
extern const u32 Unk_1f34590 __attribute__((visibility("hidden")));
extern const u32 Unk_1f34594 __attribute__((visibility("hidden")));
extern const u32 Unk_1f34598 __attribute__((visibility("hidden")));
extern const u32 Unk_1f3459c __attribute__((visibility("hidden")));
extern const u32 Unk_1f345a0 __attribute__((visibility("hidden")));

// The three 0x33d0-byte blocks, as they're written and as they're read.
struct Unk_1386be0_T {
    u8 _0[0x33d0];
};
PKMN_SIZE_ASSERT(Unk_1386be0_T, 0x33d0);

struct Unk_1388b10_T {
    u8 _0[0x33d0];
};
PKMN_SIZE_ASSERT(Unk_1388b10_T, 0x33d0);

// The 0x268-byte block.
struct Unk_13870a0_T {
    u8 _0[0x268];
};
PKMN_SIZE_ASSERT(Unk_13870a0_T, 0x268);

struct Unk_1389190_T {
    u8 _0[0x268];
};
PKMN_SIZE_ASSERT(Unk_1389190_T, 0x268);

// The 0x1c-byte block.
struct Unk_13872c0_T {
    u8 _0[0x1c];
};
PKMN_SIZE_ASSERT(Unk_13872c0_T, 0x1c);

struct Unk_1389810_T {
    u8 _0[0x1c];
};
PKMN_SIZE_ASSERT(Unk_1389810_T, 0x1c);

// Reads a block; tells the store's listener when it isn't there.
template <class T>
static inline void Unk_Read(const u32& key, T* data) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    u64 size = sizeof(*data);
    if (!store->Unk_1346030(key, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&key);
}

// Writes a block.
template <class T>
static inline bool Unk_Write(const u32& key, T* data) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    u64 size = sizeof(*data);
    return store->Unk_13456e0(key, data, size);
}

// 0x7101386d20
void Unk_1386d20(Unk_1388b10_T* data) {
    Unk_Read(Unk_1f34590, data);
}

// 0x7101386da0
bool Unk_1386da0(Unk_1386be0_T* data) {
    return Unk_Write(Unk_1f34590, data);
}

// 0x7101386e00
void Unk_1386e00(Unk_1388b10_T* data) {
    Unk_Read(Unk_1f34594, data);
}

// 0x7101386e80
bool Unk_1386e80(Unk_1386be0_T* data) {
    return Unk_Write(Unk_1f34594, data);
}

// 0x7101386ee0
void Unk_1386ee0(Unk_1388b10_T* data) {
    Unk_Read(Unk_1f34598, data);
}

// 0x7101386f60
bool Unk_1386f60(Unk_1386be0_T* data) {
    return Unk_Write(Unk_1f34598, data);
}

// 0x7101386fc0
void Unk_1386fc0(Unk_1389190_T* data) {
    Unk_Read(Unk_1f3459c, data);
}

// 0x7101387040
bool Unk_1387040(Unk_13870a0_T* data) {
    return Unk_Write(Unk_1f3459c, data);
}

// 0x71013871e0
void Unk_13871e0(Unk_1389810_T* data) {
    Unk_Read(Unk_1f345a0, data);
}

// 0x7101387260
bool Unk_1387260(Unk_13872c0_T* data) {
    return Unk_Write(Unk_1f345a0, data);
}
