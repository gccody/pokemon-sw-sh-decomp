// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71010406a0
void Unk_10406a0_update() {}

struct Unk_10406b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10406b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10406b0, field_8, 0x8);

// 0x71010406b0
void Unk_10406b0_set(const Unk_10406b0* self, Unk_10406b0* value) {
    *value = *self;
}

struct Unk_10406c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10406c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10406c0, field_8, 0x8);

// 0x71010406c0
void Unk_10406c0_set(const Unk_10406c0* self, Unk_10406c0* value) {
    *value = *self;
}

// 0x7101040750
void Unk_1040750_update() {}

struct Unk_1040760 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1040760, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1040760, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1040760, field_10, 0x10);

// 0x7101040760
void Unk_1040760_set(const Unk_1040760* self, Unk_1040760* value) {
    *value = *self;
}

struct Unk_1040780 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1040780, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1040780, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1040780, field_10, 0x10);

// 0x7101040780
void Unk_1040780_set(const Unk_1040780* self, Unk_1040780* value) {
    *value = *self;
}

// 0x7101040880
void Unk_1040880_update() {}

struct Unk_1040890 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1040890, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1040890, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1040890, field_10, 0x10);

// 0x7101040890
void Unk_1040890_set(const Unk_1040890* self, Unk_1040890* value) {
    *value = *self;
}

struct Unk_10408b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10408b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10408b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10408b0, field_10, 0x10);

// 0x71010408b0
void Unk_10408b0_set(const Unk_10408b0* self, Unk_10408b0* value) {
    *value = *self;
}

struct Unk_27e3584_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3584_Data, field_18, 0x18);

extern Unk_27e3584_Data Unk_27e3584 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101041b40
void Unk_1041b40_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3584.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3584.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3584.field_18 = 0xffff;
    Unk_27e3584.field_10 = 0;
    Unk_27e3584.field_8 = r2;
    Unk_27e3584.field_c = 0;
    Unk_27e3584.field_14 = 0xffffffff;
}
