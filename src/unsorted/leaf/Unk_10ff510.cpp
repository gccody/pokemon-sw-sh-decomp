// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10ff510 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_10ff510, field_8, 0x8);

void Unk_15c90e0(void*);

// 0x71010ff510
void Unk_10ff510_call(const Unk_10ff510* self) {
    if (self->field_8 != nullptr) {
        Unk_15c90e0(self->field_8);
    }
}

struct Unk_10ff520 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10ff520, field_8, 0x8);

// 0x71010ff520
bool Unk_10ff520_check(const Unk_10ff520* self) {
    return self->field_8 != 0;
}

struct Unk_27e505c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e505c_Data, field_18, 0x18);

extern Unk_27e505c_Data Unk_27e505c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010ff780
void Unk_10ff780_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e505c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e505c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e505c.field_10 = 0xffff;
    Unk_27e505c.field_8 = r2;
    Unk_27e505c.field_c = 0xffffffff;
    Unk_27e505c.field_18 = 0;
    Unk_27e505c.field_14 = 0;
}
