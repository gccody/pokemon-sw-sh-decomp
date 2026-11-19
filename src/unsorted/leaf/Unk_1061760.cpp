// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24ba170;
void Unk_6aed00(u64);

// 0x7101061760
void Unk_1061760_call() {
    if (Unk_24ba170 != 0) {
        Unk_6aed00(Unk_24ba170);
    }
}

extern u64 Unk_24ba170;
void Unk_6aed80(u64);

// 0x7101061780
void Unk_1061780_call() {
    if (Unk_24ba170 != 0) {
        Unk_6aed80(Unk_24ba170);
    }
}

extern u64 Unk_24ba170;
void Unk_6ae810(u64);

// 0x71010617c0
void Unk_10617c0_call() {
    if (Unk_24ba170 != 0) {
        Unk_6ae810(Unk_24ba170);
    }
}

void Unk_6ae9d0(u64);

// 0x7101061800
void Unk_1061800_call(void* /*unused*/, u64 value) {
    Unk_6ae9d0(value);
}

extern u64 Unk_24ba170;
void Unk_6ae840(u64);

// 0x71010619d0
void Unk_10619d0_call() {
    if (Unk_24ba170 != 0) {
        Unk_6ae840(Unk_24ba170);
    }
}

struct Unk_27e3b34_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3b34_Data, field_18, 0x18);

extern Unk_27e3b34_Data Unk_27e3b34 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101061e10
void Unk_1061e10_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3b34.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3b34.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3b34.field_10 = 0xffff;
    Unk_27e3b34.field_8 = r2;
    Unk_27e3b34.field_c = 0xffffffff;
    Unk_27e3b34.field_18 = 0;
    Unk_27e3b34.field_14 = 0;
}
