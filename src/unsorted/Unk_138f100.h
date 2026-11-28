#pragma once
// Two classes of game/unk_133d350 whose data is one block of the scrambled
// block store (src/unsorted/families/Unk_13471e0.h), read from and written to
// the store whole: Unk_2432f50 (vtable 0x7102432f60, src/unsorted/
// Unk_138f100.cpp) and Unk_2433018 (vtable 0x7102433028, src/unsorted/
// Unk_138fc70.cpp). Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/families/Unk_13471e0.h"

// The base (vtable 0x7102431858), as in src/unsorted/Unk_1392d70.h, with its
// destructor inline: these classes' destructors inline it.
class Unk_2431de8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2431de8() override {}
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// Unk_2432f50's block: what goes to the store. Its reset puts an FNV-1a basis
// (the hash of "") in field_8.
struct Unk_138f3c0_T {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_138f3c0_T, 0x20);

class Unk_2432f50 : public Unk_2431de8 {
public:
    Unk_2432f50();
    ~Unk_2432f50() override;
    void vf7() override;  // reset the block and write it
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    Unk_138f3c0_T field_60;
};
PKMN_SIZE_ASSERT(Unk_2432f50, 0x80);
PKMN_OFFSET_ASSERT(Unk_2432f50, field_60, 0x60);

// Unk_2433018's block: what goes to the store.
struct Unk_138fce0_T {
    u8 _0[0x400];
};
PKMN_SIZE_ASSERT(Unk_138fce0_T, 0x400);

class Unk_2433018 : public Unk_2431de8 {
public:
    Unk_2433018();
    ~Unk_2433018() override;
    void vf7() override;  // clear the block and write it
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    Unk_138fce0_T field_60;
};
PKMN_SIZE_ASSERT(Unk_2433018, 0x460);
PKMN_OFFSET_ASSERT(Unk_2433018, field_60, 0x60);
