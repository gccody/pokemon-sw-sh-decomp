// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100dcec50
void Unk_dcec50_update() {}

struct Unk_dcec60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec60_arg1, field_0, 0x0);

struct Unk_dcec60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec60, field_0, 0x0);

// 0x7100dcec60
void Unk_dcec60_set(const Unk_dcec60* self, Unk_dcec60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_dcec70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec70_arg1, field_0, 0x0);

struct Unk_dcec70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec70, field_0, 0x0);

// 0x7100dcec70
void Unk_dcec70_set(const Unk_dcec70* self, Unk_dcec70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100dcf530
void Unk_dcf530_update() {}

struct Unk_dcf540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf540_arg1, field_0, 0x0);

struct Unk_dcf540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf540, field_0, 0x0);

// 0x7100dcf540
void Unk_dcf540_set(const Unk_dcf540* self, Unk_dcf540_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_dcf550_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf550_arg1, field_0, 0x0);

struct Unk_dcf550 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf550, field_0, 0x0);

// 0x7100dcf550
void Unk_dcf550_set(const Unk_dcf550* self, Unk_dcf550_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27debe4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27debe4_Data, field_18, 0x18);

extern Unk_27debe4_Data Unk_27debe4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100ddd6b0
void Unk_ddd6b0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27debe4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27debe4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27debe4.field_18 = 0xffff;
    Unk_27debe4.field_10 = 0;
    Unk_27debe4.field_8 = r2;
    Unk_27debe4.field_c = 0;
    Unk_27debe4.field_14 = 0xffffffff;
}
