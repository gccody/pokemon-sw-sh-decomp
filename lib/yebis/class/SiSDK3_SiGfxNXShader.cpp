// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_55b6a0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_55b6a0, field_18, 0x18);

struct Unk_55b1d0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_55b1d0, field_20, 0x20);

struct Unk_55b1e0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_55b1e0, field_20, 0x20);

struct Unk_55b1f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55b1f0, field_28, 0x28);

struct Unk_55b200 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_55b200, field_64, 0x64);

struct Unk_55b270 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_55b270, field_78, 0x78);

struct Unk_55b550 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_55b550, field_98, 0x98);

struct Unk_55b6b0 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_55b6b0, field_90, 0x90);

struct Unk_55b190 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_55b190, field_30, 0x30);

struct Unk_55b1b0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_55b1b0, field_60, 0x60);

struct Unk_55b1a0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55b1a0, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXShader {
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
    bool vf20();
    const u8* vf21();
    const u8* vf23();
    u32 vf24();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x710055b190
const u8* SiSDK3::SiGfxNXShader::vf23() {
    const Unk_55b190* self = reinterpret_cast<const Unk_55b190*>(this);
    return &self->field_30;
}

// 0x710055b1a0
const u8* SiSDK3::SiGfxNXShader::vf3() {
    const Unk_55b1a0* self = reinterpret_cast<const Unk_55b1a0*>(this);
    return &self->field_28;
}

// 0x710055b1b0
u32 SiSDK3::SiGfxNXShader::vf24() {
    const Unk_55b1b0* self = reinterpret_cast<const Unk_55b1b0*>(this);
    return self->field_60;
}

// 0x710055b1d0
u64 SiSDK3::SiGfxNXShader::vf5() {
    const Unk_55b1d0* self = reinterpret_cast<const Unk_55b1d0*>(this);
    return self->field_20;
}

// 0x710055b1e0
u64 SiSDK3::SiGfxNXShader::vf6() {
    const Unk_55b1e0* self = reinterpret_cast<const Unk_55b1e0*>(this);
    return self->field_20;
}

// 0x710055b1f0
u64 SiSDK3::SiGfxNXShader::vf7() {
    const Unk_55b1f0* self = reinterpret_cast<const Unk_55b1f0*>(this);
    return self->field_28;
}

// 0x710055b200
const u8* SiSDK3::SiGfxNXShader::vf8() {
    const Unk_55b200* self = reinterpret_cast<const Unk_55b200*>(this);
    return &self->field_64;
}

// 0x710055b210
void SiSDK3::SiGfxNXShader::vf9() {
}

// 0x710055b220
void SiSDK3::SiGfxNXShader::vf10() {
}

// 0x710055b230
void SiSDK3::SiGfxNXShader::vf11() {
}

// 0x710055b240
void SiSDK3::SiGfxNXShader::vf12() {
}

// 0x710055b250
void SiSDK3::SiGfxNXShader::vf13() {
}

// 0x710055b260
void SiSDK3::SiGfxNXShader::vf14() {
}

// 0x710055b270
const u8* SiSDK3::SiGfxNXShader::vf17() {
    const Unk_55b270* self = reinterpret_cast<const Unk_55b270*>(this);
    return &self->field_78;
}

// 0x710055b550
bool SiSDK3::SiGfxNXShader::vf20() {
    const Unk_55b550* self = reinterpret_cast<const Unk_55b550*>(this);
    return self->field_98 != 0;
}

// 0x710055b560
void SiSDK3::SiGfxNXShader::vf15() {
}

// 0x710055b570
u32 SiSDK3::SiGfxNXShader::vf16() {
    return 0;
}

// 0x710055b6a0
u32 SiSDK3::SiGfxNXShader::vf4() {
    const Unk_55b6a0* self = reinterpret_cast<const Unk_55b6a0*>(this);
    return self->field_18;
}

// 0x710055b6b0
const u8* SiSDK3::SiGfxNXShader::vf21() {
    const Unk_55b6b0* self = reinterpret_cast<const Unk_55b6b0*>(this);
    return &self->field_90;
}
