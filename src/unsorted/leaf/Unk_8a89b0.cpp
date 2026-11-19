// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a89b0 {
    u8 _0[0x28];
    u32 field_28;
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_8a89b0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8a89b0, field_2c, 0x2c);

// 0x71008a89b0
void Unk_8a89b0_set(Unk_8a89b0* self) {
    self->field_28 = 0;
    self->field_2c = 0;
}

struct Unk_8a89c0 {
    u8 _0[0x2c];
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_8a89c0, field_2c, 0x2c);

// 0x71008a89c0
u8 Unk_8a89c0_getField2c(const Unk_8a89c0* self) {
    return self->field_2c;
}

struct Unk_8a89d0 {
    u8 _0[0x2c];
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_8a89d0, field_2c, 0x2c);

// 0x71008a89d0
void Unk_8a89d0_update(Unk_8a89d0* self) {
    if (self->field_2c != 0) {
        return;
    }
    self->field_2c = 1;
}

struct Unk_27d132c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d132c_Data, field_18, 0x18);

extern Unk_27d132c_Data Unk_27d132c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008a89f0
void Unk_8a89f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d132c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d132c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d132c.field_18 = 0xffff;
    Unk_27d132c.field_10 = 0;
    Unk_27d132c.field_8 = r2;
    Unk_27d132c.field_c = 0;
    Unk_27d132c.field_14 = 0xffffffff;
}
