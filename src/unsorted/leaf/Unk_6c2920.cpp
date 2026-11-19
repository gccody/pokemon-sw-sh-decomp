// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6c2920_0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_6c2920_0 {
    virtual void vf0();
    Unk_6c2920_0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_6c2920_0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_6c2920_0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6c2920_0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_6c2920_0, field_20, 0x20);

struct Unk_6c2920 {
    Unk_6c2920_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_6c2920, field_0, 0x0);

// 0x71006c2920
void Unk_6c2920_call(Unk_6c2920* self) {
    Unk_6c2920_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        Unk_6c2920_0_8* v1 = v0->field_8;
        u64 v2 = v0->field_10;
        u64 v3 = v0->field_18;
        u64 v4 = v0->field_20;
        v0->vf0();
        v1->vf3(v2, v3, v4);
    }
}

extern u16 Unk_27790e8;
struct Unk_2779104_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2779104_Data, field_18, 0x18);

extern Unk_2779104_Data Unk_2779104 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006c2980
void Unk_6c2980_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2779104.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2779104.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2779104.field_10 = 0xffff;
    Unk_2779104.field_8 = r2;
    Unk_2779104.field_c = 0xffffffff;
    Unk_2779104.field_18 = 0;
    Unk_2779104.field_14 = 0;
    Unk_27790e8 = Unk_27790e8 | 0xfff;
}
