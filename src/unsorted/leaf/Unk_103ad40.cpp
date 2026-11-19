// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710103ad40
void Unk_103ad40_update() {}

struct Unk_103ad50 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_103ad50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_103ad50, field_8, 0x8);

// 0x710103ad50
void Unk_103ad50_set(const Unk_103ad50* self, Unk_103ad50* value) {
    *value = *self;
}

struct Unk_103ad60 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_103ad60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_103ad60, field_8, 0x8);

// 0x710103ad60
void Unk_103ad60_set(const Unk_103ad60* self, Unk_103ad60* value) {
    *value = *self;
}

// 0x710103adf0
void Unk_103adf0_update() {}

struct Unk_103ae00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_103ae00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_103ae00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_103ae00, field_10, 0x10);

// 0x710103ae00
void Unk_103ae00_set(const Unk_103ae00* self, Unk_103ae00* value) {
    *value = *self;
}

struct Unk_103ae20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_103ae20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_103ae20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_103ae20, field_10, 0x10);

// 0x710103ae20
void Unk_103ae20_set(const Unk_103ae20* self, Unk_103ae20* value) {
    *value = *self;
}

// 0x710103af20
void Unk_103af20_update() {}

struct Unk_103af30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_103af30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_103af30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_103af30, field_10, 0x10);

// 0x710103af30
void Unk_103af30_set(const Unk_103af30* self, Unk_103af30* value) {
    *value = *self;
}

struct Unk_103af50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_103af50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_103af50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_103af50, field_10, 0x10);

// 0x710103af50
void Unk_103af50_set(const Unk_103af50* self, Unk_103af50* value) {
    *value = *self;
}

struct Unk_27e34dc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e34dc_Data, field_18, 0x18);

extern Unk_27e34dc_Data Unk_27e34dc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710103c360
void Unk_103c360_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e34dc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e34dc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e34dc.field_18 = 0xffff;
    Unk_27e34dc.field_10 = 0;
    Unk_27e34dc.field_8 = r2;
    Unk_27e34dc.field_c = 0;
    Unk_27e34dc.field_14 = 0xffffffff;
}
