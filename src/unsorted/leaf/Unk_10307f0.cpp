// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10307f0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10307f0, field_18, 0x18);

void Unk_1030800(u64);

// 0x71010307f0
void Unk_10307f0_call(const Unk_10307f0* self) {
    if (self->field_18 != 0) {
        Unk_1030800(self->field_18);
    }
}

void Unk_1031080(void*, u32);

// 0x71010314a0
void Unk_10314a0_call(void* self) {
    Unk_1031080(self, 1);
}

void Unk_1031080(void*, u32);

// 0x71010314b0
void Unk_10314b0_call(void* self) {
    Unk_1031080(self, 2);
}

void Unk_1031080(void*, u32);

// 0x71010314c0
void Unk_10314c0_call(void* self) {
    Unk_1031080(self, 3);
}

void Unk_1031080(void*, u32);

// 0x71010314d0
void Unk_10314d0_call(void* self) {
    Unk_1031080(self, 4);
}

void Unk_1031080(void*, u32);

// 0x71010314e0
void Unk_10314e0_call(void* self) {
    Unk_1031080(self, 5);
}

// 0x7101032a40
void Unk_1032a40_update() {}

struct Unk_1032a50 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1032a50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1032a50, field_8, 0x8);

// 0x7101032a50
void Unk_1032a50_set(const Unk_1032a50* self, Unk_1032a50* value) {
    *value = *self;
}

struct Unk_1032a60 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1032a60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1032a60, field_8, 0x8);

// 0x7101032a60
void Unk_1032a60_set(const Unk_1032a60* self, Unk_1032a60* value) {
    *value = *self;
}

// 0x7101032af0
void Unk_1032af0_update() {}

struct Unk_1032b00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1032b00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1032b00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1032b00, field_10, 0x10);

// 0x7101032b00
void Unk_1032b00_set(const Unk_1032b00* self, Unk_1032b00* value) {
    *value = *self;
}

struct Unk_1032b20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1032b20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1032b20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1032b20, field_10, 0x10);

// 0x7101032b20
void Unk_1032b20_set(const Unk_1032b20* self, Unk_1032b20* value) {
    *value = *self;
}

// 0x7101032c20
void Unk_1032c20_update() {}

struct Unk_1032c30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1032c30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1032c30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1032c30, field_10, 0x10);

// 0x7101032c30
void Unk_1032c30_set(const Unk_1032c30* self, Unk_1032c30* value) {
    *value = *self;
}

struct Unk_1032c50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1032c50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1032c50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1032c50, field_10, 0x10);

// 0x7101032c50
void Unk_1032c50_set(const Unk_1032c50* self, Unk_1032c50* value) {
    *value = *self;
}

struct Unk_27e33d4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e33d4_Data, field_18, 0x18);

extern Unk_27e33d4_Data Unk_27e33d4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010356e0
void Unk_10356e0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e33d4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e33d4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e33d4.field_18 = 0xffff;
    Unk_27e33d4.field_10 = 0;
    Unk_27e33d4.field_8 = r2;
    Unk_27e33d4.field_c = 0;
    Unk_27e33d4.field_14 = 0xffffffff;
}
