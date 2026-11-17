// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_938ab0(void*, u64, u32, u32);

// 0x7100938aa0
void Unk_938aa0_call(void* self, u64 value, bool arg2) {
    Unk_938ab0(self, value, arg2, 0);
}

void Unk_938ab0(void*, u64, u32, u32);

// 0x7100938d00
void Unk_938d00_call(void* self, u64 value) {
    Unk_938ab0(self, value, 0, 0);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939600
void Unk_939600_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 1);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939610
void Unk_939610_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 2);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939620
void Unk_939620_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 3);
}

struct Unk_939650 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_939650, field_38, 0x38);

// 0x7100939650
void Unk_939650_setField38(Unk_939650* self, u64 value) {
    self->field_38 = value;
}

struct Unk_93a2a0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_93a2a0, field_20, 0x20);

void Unk_93d6e0(u64);

// 0x710093a2a0
void Unk_93a2a0_call(const Unk_93a2a0* self) {
    Unk_93d6e0(self->field_20);
}

struct Unk_93cc90_78 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_93cc90_78, field_58, 0x58);

struct Unk_93cc90 {
    u8 _0[0x78];
    Unk_93cc90_78* field_78;
    u8 _80[0x10];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_93cc90, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_93cc90, field_90, 0x90);

// 0x710093cc90
void Unk_93cc90_set(Unk_93cc90* self, bool value, bool arg2) {
    self->field_90 = value;
    self->field_78->field_58 = (self->field_78->field_58 & 0xfffffffe) | (arg2);
}

void Unk_eb6230(void*, u32);

// 0x710093d6d0
void Unk_93d6d0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_952910 {
    u8 _0[0x4c8];
    u64 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952910, field_4c8, 0x4c8);

void Unk_9a8190(u64);

// 0x7100952910
void Unk_952910_call(const Unk_952910* self) {
    Unk_9a8190(self->field_4c8);
}

struct Unk_952930 {
    u8 _0[0x4c8];
    u64 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952930, field_4c8, 0x4c8);

void Unk_9a8a20(u64);

// 0x7100952930
void Unk_952930_call(const Unk_952930* self) {
    Unk_9a8a20(self->field_4c8);
}

struct Unk_95abc0 {
    u8 _0[0x608];
    u64 field_608;
};
PKMN_OFFSET_ASSERT(Unk_95abc0, field_608, 0x608);

void Unk_9bbed0(u64, u32);

// 0x710095abc0
void Unk_95abc0_call(const Unk_95abc0* self) {
    Unk_9bbed0(self->field_608, 4);
}

struct Unk_95abd0 {
    u8 _0[0xa0];
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_95abd0, field_a0, 0xa0);

// 0x710095abd0
bool Unk_95abd0_check(const Unk_95abd0* self) {
    return self->field_a0 == 0;
}

struct Unk_95abe0 {
    u8 _0[0x608];
    u64 field_608;
};
PKMN_OFFSET_ASSERT(Unk_95abe0, field_608, 0x608);

void Unk_9bc580(u64);

// 0x710095abe0
void Unk_95abe0_call(const Unk_95abe0* self) {
    Unk_9bc580(self->field_608);
}
