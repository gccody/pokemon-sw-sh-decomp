// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c3220_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c3220_arg1, field_0, 0x0);

u32 Unk_7ef6a0();
void Unk_8c20a0(void*, u32);

// 0x71008c3220
bool Unk_8c3220_call(void* self, const Unk_8c3220_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u32 r1 = Unk_7ef6a0();
    return r1 != 0;
}

struct Unk_8c3250_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c3250_arg1, field_0, 0x0);

u32 Unk_7ef6a0();
void Unk_8c20a0(void*, u32);

// 0x71008c3250
bool Unk_8c3250_call(void* self, const Unk_8c3250_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u32 r1 = Unk_7ef6a0();
    return r1 == 0;
}

struct Unk_8c32f0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c32f0_arg1, field_0, 0x0);

u64 Unk_7ef630();
void Unk_8c20a0(void*, u32);

// 0x71008c32f0
u64 Unk_8c32f0_call(void* self, const Unk_8c32f0_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u64 r1 = Unk_7ef630();
    return r1 & 1;
}

struct Unk_8c3b80_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c3b80_arg1, field_0, 0x0);

u64 Unk_780ec0(u32);

// 0x71008c3b80
u64 Unk_8c3b80_call(void* /*unused*/, const Unk_8c3b80_arg1* value) {
    u64 r0 = Unk_780ec0(value->field_0);
    return r0 & 1;
}

struct Unk_8c4400_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c4400_arg1, field_0, 0x0);

u64 Unk_8c6230(void*, u32);

// 0x71008c4400
u64 Unk_8c4400_call(void* self, const Unk_8c4400_arg1* value) {
    u64 r0 = Unk_8c6230(self, value->field_0);
    return r0 & 1;
}

u64 Unk_8c6180();

// 0x71008c4560
u64 Unk_8c4560_call() {
    u64 r0 = Unk_8c6180();
    return r0 & 1;
}

struct Unk_8c4710_arg1 {
    u32 field_0;
    u8 _4[0x4];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8c4710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8c4710_arg1, field_8, 0x8);

u64 Unk_8c62f0(void*, u32, u32);

// 0x71008c4710
u64 Unk_8c4710_call(void* self, const Unk_8c4710_arg1* value) {
    u64 r0 = Unk_8c62f0(self, value->field_0, value->field_8);
    return r0 & 1;
}

struct Unk_8c5740_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5740_arg1, field_0, 0x0);

u64 Unk_7ef2b0();
void Unk_8c20a0(void*, u32);

// 0x71008c5740
u64 Unk_8c5740_call(void* self, const Unk_8c5740_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u64 r1 = Unk_7ef2b0();
    return r1 & 1;
}

struct Unk_8c5820_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5820_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c5820
bool Unk_8c5820_call(void* /*unused*/, const Unk_8c5820_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 < v0;
}

struct Unk_8c5850_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5850_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c5850
bool Unk_8c5850_call(void* /*unused*/, const Unk_8c5850_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 > v0;
}

struct Unk_8c5880_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5880_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c5880
bool Unk_8c5880_call(void* /*unused*/, const Unk_8c5880_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 == v0;
}

struct Unk_8c58b0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c58b0_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c58b0
bool Unk_8c58b0_call(void* /*unused*/, const Unk_8c58b0_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 != v0;
}

// 0x71008c5b00
u64 Unk_8c5b00_get() {
    return 0;
}

// 0x71008c5b10
u64 Unk_8c5b10_get() {
    return 0;
}

struct Unk_8c5b20_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5b20_arg1, field_0, 0x0);

u32 Unk_7f0b30();
void Unk_8c20a0(void*, u32);

// 0x71008c5b20
bool Unk_8c5b20_call(void* self, const Unk_8c5b20_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u32 r1 = Unk_7f0b30();
    return r1 != 0x19;
}
