// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern void* Unk_27fc0a8;
struct Unk_6d1360 {
    u8 _0[0x110];
    void* field_110;
};
PKMN_OFFSET_ASSERT(Unk_6d1360, field_110, 0x110);

u32 Unk_172bd80(void*);
void Unk_6d4140(void*);

// 0x71006d1360
void Unk_6d1360_call(const Unk_6d1360* self) {
    u32 r0 = Unk_172bd80(Unk_27fc0a8);
    if ((r0 & 1) != 0) {
        if (self->field_110 == nullptr)
            return;
        Unk_6d4140(self->field_110);
    }
}

struct Unk_6d1530 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_6d1530, field_a0, 0xa0);

// 0x71006d1530
void Unk_6d1530_setFielda0(Unk_6d1530* self, u64 value) {
    self->field_a0 = value;
}

struct Unk_2779274_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2779274_Data, field_18, 0x18);

extern Unk_2779274_Data Unk_2779274 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006d3e40
void Unk_6d3e40_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2779274.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2779274.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2779274.field_10 = 0xffff;
    Unk_2779274.field_8 = r2;
    Unk_2779274.field_c = 0xffffffff;
    Unk_2779274.field_18 = 0;
    Unk_2779274.field_14 = 0;
}
