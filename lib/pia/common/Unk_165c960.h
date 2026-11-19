#pragma once
// Pia's big-endian accessors (0x710165c960-0x710165ca20). The ones
// tools/leafgen.py matched (lib/nx_middleware/leaf/Unk_16598a0.cpp) keep its
// names: Unk_<addr>_set(Unk_<addr>*, value), Unk_<addr>_get(const Unk_<addr>*).
#include <types.h>

struct Unk_165c960;
struct Unk_165c9a0;
struct Unk_165c9b0;
struct Unk_165c9d0;
struct Unk_165c9e0;
struct Unk_165c9f0;
struct Unk_165ca00;
struct Unk_165ca10;

void Unk_165c960_set(Unk_165c960* self, u64 value);
u64 Unk_165c9a0_get(const Unk_165c9a0* self);
void Unk_165c9b0_set(Unk_165c9b0* self, u32 value);
u32 Unk_165c9d0_get(const Unk_165c9d0* self);
void Unk_165c9e0_set(Unk_165c9e0* self, u32 value);
u16 Unk_165c9f0_get(const Unk_165c9f0* self);
void Unk_165ca00_set(Unk_165ca00* self, u8 value);
u8 Unk_165ca10_get(const Unk_165ca10* self);
