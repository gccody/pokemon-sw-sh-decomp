#pragma once
// The object whose three sound tables 0x710112a570, 0x710112b6e0 and
// 0x710112c850 fill (its destructor is 0x710112d870: the tables are the last
// of its members). Placeholder names: rename once the class is known.
#include <initializer_list>

#include <types.h>

#include "unsorted/Unk_112dd40.h"
#include "unsorted/Unk_2771620.h"

// A sound's name, the key: the same with one more field, always 0 here.
struct Unk_112d870_Key {
    template <size_t N>
    constexpr Unk_112d870_Key(const char (&str)[N])
        : hash(Unk_112dd40_Hash(str, N - 1)), str(str), len(N - 1), field_18(0) {}

    u64 hash;
    const char* str;
    u64 len;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_112d870_Key, 0x20);

// A hash, copied by a constructor of its own.
struct Unk_112e110_Hash {
    Unk_112e110_Hash() : value(0) {}
    Unk_112e110_Hash(const Unk_112e110_Hash& other) : value(other.value) {}

    u64 value;
};

// A voice and the hashes of up to 8 motions.
struct Unk_112e110 {
    explicit Unk_112e110(const Unk_112dd40& voice) : voice(voice) {}

    Unk_112e110_Hash motions[8];
    Unk_112dd40 voice;
};
PKMN_OFFSET_ASSERT(Unk_112e110, voice, 0x40);
PKMN_SIZE_ASSERT(Unk_112e110, 0x58);

struct Unk_112d870 {
    u8 field_0[0x178];
    Unk_2771620_Map<u64, Unk_112dd40> field_178;
    Unk_2771620_Map<u64, Unk_112dd40> field_1d0;
    Unk_2771620_Map<u64, Unk_112e110> field_228;
};
PKMN_OFFSET_ASSERT(Unk_112d870, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_112d870, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_112d870, field_228, 0x228);
PKMN_SIZE_ASSERT(Unk_112d870, 0x280);
