#pragma once

// Fixed-width types used throughout the decomp (no libc headers needed).
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long s64;
typedef unsigned long u64;
typedef float f32;
typedef double f64;
typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef unsigned long uintptr_t;

// Struct layout assertions - use these on every reconstructed type.
#define PKMN_SIZE_ASSERT(T, size) static_assert(sizeof(T) == (size), "sizeof(" #T ") != " #size)
#define PKMN_OFFSET_ASSERT(T, field, offset)                \
    static_assert(__builtin_offsetof(T, field) == (offset), \
                  "offsetof(" #T "::" #field ") != " #offset)
