// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100a73370
void Unk_a73370_update() {}

struct Unk_a73380 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_a73380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a73380, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a73380, field_10, 0x10);

// 0x7100a73380
void Unk_a73380_set(const Unk_a73380* self, Unk_a73380* value) {
    *value = *self;
}

struct Unk_a733a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_a733a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a733a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a733a0, field_10, 0x10);

// 0x7100a733a0
void Unk_a733a0_set(const Unk_a733a0* self, Unk_a733a0* value) {
    *value = *self;
}

// 0x7100a73430
void Unk_a73430_update() {}

struct Unk_a73440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73440_arg1, field_0, 0x0);

struct Unk_a73440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73440, field_0, 0x0);

// 0x7100a73440
void Unk_a73440_set(const Unk_a73440* self, Unk_a73440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a73450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73450_arg1, field_0, 0x0);

struct Unk_a73450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73450, field_0, 0x0);

// 0x7100a73450
void Unk_a73450_set(const Unk_a73450* self, Unk_a73450_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a75fe0
void Unk_a75fe0_update() {}

// 0x7100a75ff0
void Unk_a75ff0_update() {}

// 0x7100a76000
void Unk_a76000_update() {}

// 0x7100a76010
void Unk_a76010_update() {}

struct Unk_27d704c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d704c_Data, field_18, 0x18);

extern Unk_27d704c_Data Unk_27d704c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100a770c0
void Unk_a770c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d704c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d704c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d704c.field_18 = 0xffff;
    Unk_27d704c.field_10 = 0;
    Unk_27d704c.field_8 = r2;
    Unk_27d704c.field_c = 0;
    Unk_27d704c.field_14 = 0xffffffff;
}
