// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_5624e0 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5624e0, field_20, 0x20);

struct Unk_55f300 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55f300, field_28, 0x28);

struct Unk_55f310 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55f310, field_28, 0x28);

struct Unk_55f320 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_55f320, field_30, 0x30);

struct Unk_55f330 {
    u8 _0[0x1c0];
    u8 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_55f330, field_1c0, 0x1c0);

struct Unk_561d80 {
    u8 _0[0x320];
    u32 field_320;
};
PKMN_OFFSET_ASSERT(Unk_561d80, field_320, 0x320);

struct Unk_561d90 {
    u8 _0[0x320];
    u32 field_320;
};
PKMN_OFFSET_ASSERT(Unk_561d90, field_320, 0x320);

extern u8 Unk_1f0028c;

struct Unk_55f3a0 {
    u8 _0[0x1d4];
    u8 field_1d4;
};
PKMN_OFFSET_ASSERT(Unk_55f3a0, field_1d4, 0x1d4);

struct Unk_55f3b0 {
    u8 _0[0x438];
    u64 field_438;
};
PKMN_OFFSET_ASSERT(Unk_55f3b0, field_438, 0x438);

struct Unk_55f3c0 {
    u8 _0[0x438];
    u64 field_438;
};
PKMN_OFFSET_ASSERT(Unk_55f3c0, field_438, 0x438);

struct Unk_562300 {
    u8 _0[0x318];
    u64 field_318;
};
PKMN_OFFSET_ASSERT(Unk_562300, field_318, 0x318);

struct Unk_562310 {
    u8 _0[0x318];
    u64 field_318;
};
PKMN_OFFSET_ASSERT(Unk_562310, field_318, 0x318);

struct Unk_562360 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_562360, field_b0, 0xb0);

struct Unk_562520 {
    u8 _0[0x328];
    u64 field_328;
};
PKMN_OFFSET_ASSERT(Unk_562520, field_328, 0x328);

struct Unk_561da0 {
    u8 _0[0x330];
    u64 field_330;
};
PKMN_OFFSET_ASSERT(Unk_561da0, field_330, 0x330);

struct Unk_561db0 {
    u8 _0[0x338];
    u32 field_338;
};
PKMN_OFFSET_ASSERT(Unk_561db0, field_338, 0x338);

struct Unk_55f2c0 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_55f2c0, field_38, 0x38);

struct Unk_55f2e0 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_55f2e0, field_a8, 0xa8);

struct Unk_55f2d0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_55f2d0, field_30, 0x30);

namespace SiSDK3 {
class SiGfxNXTexture {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u64 vf7();
    const u8* vf8();
    void vf9();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15(u32 value);
    u32 vf16();
    u8* vf18();
    const u8* vf19();
    u64 vf20();
    u64 vf21();
    u64 vf33();
    u64 vf34();
    u32 vf35();
    u64 vf36();
    const u8* vf38();
    u64 vf40();
    u64 vf41();
    u32 vf43();
    const u8* vf46();
    u32 vf47();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x710055f2c0
const u8* SiSDK3::SiGfxNXTexture::vf46() {
    const Unk_55f2c0* self = reinterpret_cast<const Unk_55f2c0*>(this);
    return &self->field_38;
}

// 0x710055f2d0
const u8* SiSDK3::SiGfxNXTexture::vf3() {
    const Unk_55f2d0* self = reinterpret_cast<const Unk_55f2d0*>(this);
    return &self->field_30;
}

// 0x710055f2e0
u32 SiSDK3::SiGfxNXTexture::vf47() {
    const Unk_55f2e0* self = reinterpret_cast<const Unk_55f2e0*>(this);
    return self->field_a8;
}

// 0x710055f300
u64 SiSDK3::SiGfxNXTexture::vf5() {
    const Unk_55f300* self = reinterpret_cast<const Unk_55f300*>(this);
    return self->field_28;
}

// 0x710055f310
u64 SiSDK3::SiGfxNXTexture::vf6() {
    const Unk_55f310* self = reinterpret_cast<const Unk_55f310*>(this);
    return self->field_28;
}

// 0x710055f320
u64 SiSDK3::SiGfxNXTexture::vf7() {
    const Unk_55f320* self = reinterpret_cast<const Unk_55f320*>(this);
    return self->field_30;
}

// 0x710055f330
const u8* SiSDK3::SiGfxNXTexture::vf8() {
    const Unk_55f330* self = reinterpret_cast<const Unk_55f330*>(this);
    return &self->field_1c0;
}

// 0x710055f340
void SiSDK3::SiGfxNXTexture::vf9() {
}

// 0x710055f360
void SiSDK3::SiGfxNXTexture::vf11() {
}

// 0x710055f370
void SiSDK3::SiGfxNXTexture::vf12() {
}

// 0x710055f380
void SiSDK3::SiGfxNXTexture::vf13() {
}

// 0x710055f390
void SiSDK3::SiGfxNXTexture::vf14() {
}

// 0x710055f3a0
const u8* SiSDK3::SiGfxNXTexture::vf19() {
    const Unk_55f3a0* self = reinterpret_cast<const Unk_55f3a0*>(this);
    return &self->field_1d4;
}

// 0x710055f3b0
u64 SiSDK3::SiGfxNXTexture::vf20() {
    const Unk_55f3b0* self = reinterpret_cast<const Unk_55f3b0*>(this);
    return self->field_438;
}

// 0x710055f3c0
u64 SiSDK3::SiGfxNXTexture::vf21() {
    const Unk_55f3c0* self = reinterpret_cast<const Unk_55f3c0*>(this);
    return self->field_438;
}

// 0x7100561d80
void SiSDK3::SiGfxNXTexture::vf15(u32 value) {
    Unk_561d80* self = reinterpret_cast<Unk_561d80*>(this);
    self->field_320 = value;
}

// 0x7100561d90
u32 SiSDK3::SiGfxNXTexture::vf16() {
    const Unk_561d90* self = reinterpret_cast<const Unk_561d90*>(this);
    return self->field_320;
}

// 0x7100561da0
u64 SiSDK3::SiGfxNXTexture::vf41() {
    const Unk_561da0* self = reinterpret_cast<const Unk_561da0*>(this);
    return self->field_330;
}

// 0x7100561db0
u32 SiSDK3::SiGfxNXTexture::vf43() {
    const Unk_561db0* self = reinterpret_cast<const Unk_561db0*>(this);
    return self->field_338;
}

// 0x7100562300
u64 SiSDK3::SiGfxNXTexture::vf33() {
    const Unk_562300* self = reinterpret_cast<const Unk_562300*>(this);
    return self->field_318;
}

// 0x7100562310
u64 SiSDK3::SiGfxNXTexture::vf34() {
    const Unk_562310* self = reinterpret_cast<const Unk_562310*>(this);
    return self->field_318;
}

// 0x7100562320
u32 SiSDK3::SiGfxNXTexture::vf35() {
    return 1;
}

// 0x7100562330
u64 SiSDK3::SiGfxNXTexture::vf36() {
    return 0;
}

// 0x7100562360
const u8* SiSDK3::SiGfxNXTexture::vf38() {
    const Unk_562360* self = reinterpret_cast<const Unk_562360*>(this);
    return &self->field_b0;
}

// 0x71005624e0
u32 SiSDK3::SiGfxNXTexture::vf4() {
    const Unk_5624e0* self = reinterpret_cast<const Unk_5624e0*>(this);
    return self->field_20;
}

// 0x7100562510
u8* SiSDK3::SiGfxNXTexture::vf18() {
    return &Unk_1f0028c;
}

// 0x7100562520
u64 SiSDK3::SiGfxNXTexture::vf40() {
    const Unk_562520* self = reinterpret_cast<const Unk_562520*>(this);
    return self->field_328;
}
