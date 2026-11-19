// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

namespace nn {
namespace crypto {
u64 GenerateCryptographicallyRandomBytes(void*, u64);
}
}  // namespace nn

// 0x71007bfe50
u32 Unk_7bfe50_call() {
    u32 l4;
    nn::crypto::GenerateCryptographicallyRandomBytes(&l4, 4);
    return l4;
}

struct Unk_7bfe80 {
    u8 _0[0xa8];
    u8 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_7bfe80, field_a8, 0xa8);

// 0x71007bfe80
u8* Unk_7bfe80_getFielda8Ptr(Unk_7bfe80* self) {
    return &self->field_a8;
}

void Unk_76a5d0();
void Unk_7c2280();

// 0x71007c1af0
void Unk_7c1af0_call() {
    Unk_7c2280();
    Unk_76a5d0();
}

struct Unk_7c22a0 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_7c22a0, field_50, 0x50);

// 0x71007c22a0
u8 Unk_7c22a0_getField50(const Unk_7c22a0* self) {
    return self->field_50;
}

struct Unk_27ceb04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ceb04_Data, field_18, 0x18);

extern Unk_27ceb04_Data Unk_27ceb04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007c2d00
void Unk_7c2d00_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ceb04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ceb04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ceb04.field_18 = 0xffff;
    Unk_27ceb04.field_10 = 0;
    Unk_27ceb04.field_8 = r2;
    Unk_27ceb04.field_c = 0;
    Unk_27ceb04.field_14 = 0xffffffff;
}
