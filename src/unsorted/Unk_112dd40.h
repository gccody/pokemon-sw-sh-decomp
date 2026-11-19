#pragma once
// A string and its hash, the key of Game Freak's tables and data documents.
// Placeholder names: rename once the type is known.
#include <cstddef>

#include <types.h>

// The 64-bit FNV-1a hash of a string, with the offset basis 0xcbf29ce484222645
// (the hash of "").
constexpr u64 Unk_112dd40_Hash(const char* str, size_t len) {
    u64 hash = 0xcbf29ce484222645;
    for (size_t i = 0; i < len; i++) {
        hash ^= static_cast<u8>(str[i]);
        hash *= 0x100000001b3;
    }
    return hash;
}

// A string and its hash.
struct Unk_112dd40 {
    template <size_t N>
    constexpr Unk_112dd40(const char (&str)[N])
        : hash(Unk_112dd40_Hash(str, N - 1)), str(str), len(N - 1) {}
    Unk_112dd40(const Unk_112dd40& other) : hash(other.hash), str(other.str), len(other.len) {}

    u64 hash;
    const char* str;
    u64 len;
};
PKMN_SIZE_ASSERT(Unk_112dd40, 0x18);
