// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK314SiGfxNXSamplerE
#include <types.h>

struct Unk_559340 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_559340, field_18, 0x18);

struct Unk_5591d0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5591d0, field_20, 0x20);

struct Unk_5591e0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5591e0, field_20, 0x20);

struct Unk_5591f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5591f0, field_28, 0x28);

struct Unk_559200 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_559200, field_64, 0x64);

struct Unk_559270 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_559270, field_78, 0x78);

struct Unk_559350 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_559350, field_c0, 0xc0);

struct Unk_559360 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_559360, field_120, 0x120);

namespace SiSDK3 {
class SiGfxNXSampler {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u64 vf7();
    const u8* vf8();
    void vf9();
    void vf10();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15();
    u32 vf16();
    const u8* vf17();
    const u8* vf18();
    u32 vf19();
};
}  // namespace SiSDK3

// 0x71005591d0
u64 SiSDK3::SiGfxNXSampler::vf5() {
    const Unk_5591d0* self = reinterpret_cast<const Unk_5591d0*>(this);
    return self->field_20;
}

// 0x71005591e0
u64 SiSDK3::SiGfxNXSampler::vf6() {
    const Unk_5591e0* self = reinterpret_cast<const Unk_5591e0*>(this);
    return self->field_20;
}

// 0x71005591f0
u64 SiSDK3::SiGfxNXSampler::vf7() {
    const Unk_5591f0* self = reinterpret_cast<const Unk_5591f0*>(this);
    return self->field_28;
}

// 0x7100559200
const u8* SiSDK3::SiGfxNXSampler::vf8() {
    const Unk_559200* self = reinterpret_cast<const Unk_559200*>(this);
    return &self->field_64;
}

// 0x7100559210
void SiSDK3::SiGfxNXSampler::vf9() {
}

// 0x7100559220
void SiSDK3::SiGfxNXSampler::vf10() {
}

// 0x7100559230
void SiSDK3::SiGfxNXSampler::vf11() {
}

// 0x7100559240
void SiSDK3::SiGfxNXSampler::vf12() {
}

// 0x7100559250
void SiSDK3::SiGfxNXSampler::vf13() {
}

// 0x7100559260
void SiSDK3::SiGfxNXSampler::vf14() {
}

// 0x7100559270
const u8* SiSDK3::SiGfxNXSampler::vf17() {
    const Unk_559270* self = reinterpret_cast<const Unk_559270*>(this);
    return &self->field_78;
}

// 0x7100559280
void SiSDK3::SiGfxNXSampler::vf15() {
}

// 0x7100559290
u32 SiSDK3::SiGfxNXSampler::vf16() {
    return 0;
}

// 0x7100559340
u32 SiSDK3::SiGfxNXSampler::vf4() {
    const Unk_559340* self = reinterpret_cast<const Unk_559340*>(this);
    return self->field_18;
}

// 0x7100559350
const u8* SiSDK3::SiGfxNXSampler::vf18() {
    const Unk_559350* self = reinterpret_cast<const Unk_559350*>(this);
    return &self->field_c0;
}

// 0x7100559360
u32 SiSDK3::SiGfxNXSampler::vf19() {
    const Unk_559360* self = reinterpret_cast<const Unk_559360*>(this);
    return self->field_120;
}
