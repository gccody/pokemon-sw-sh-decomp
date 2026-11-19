// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a5900_8 {
    virtual void vf0();
    virtual void vf1();
};

struct Unk_6a5900 {
    u8 _0[0x8];
    Unk_6a5900_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_6a5900, field_8, 0x8);

// 0x71006a5900
void Unk_6a5900_call(Unk_6a5900* self) {
    if (self->field_8 != nullptr) {
        self->field_8->vf1();
        self->field_8 = nullptr;
    }
}

struct Unk_2778d4c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2778d4c_Data, field_18, 0x18);

extern Unk_2778d4c_Data Unk_2778d4c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006a60a0
void Unk_6a60a0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2778d4c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2778d4c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2778d4c.field_10 = 0xffff;
    Unk_2778d4c.field_8 = r2;
    Unk_2778d4c.field_c = 0xffffffff;
    Unk_2778d4c.field_18 = 0;
    Unk_2778d4c.field_14 = 0;
}
