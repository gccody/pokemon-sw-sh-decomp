// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_556c20 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_556c20, field_18, 0x18);

struct Unk_555c10 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_555c10, field_20, 0x20);

struct Unk_555c20 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_555c20, field_20, 0x20);

struct Unk_555c30 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_555c30, field_28, 0x28);

struct Unk_555c40 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_555c40, field_64, 0x64);

struct Unk_555c60 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
};

struct Unk_555cb0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_555cb0, field_78, 0x78);

struct Unk_555cc0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    u8 _8[0x349];
    u8 field_351;
};
PKMN_OFFSET_ASSERT(Unk_555cc0, field_351, 0x351);

struct Unk_556950 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_556950, field_260, 0x260);

struct Unk_556960 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_556960, field_260, 0x260);

struct Unk_5569a0 {
    u8 _0[0x350];
    u8 field_350;
};
PKMN_OFFSET_ASSERT(Unk_5569a0, field_350, 0x350);

struct Unk_5569b0 {
    u8 _0[0x298];
    u8 field_298;
};
PKMN_OFFSET_ASSERT(Unk_5569b0, field_298, 0x298);

struct Unk_556c30 {
    u8 _0[0x2c0];
    u8 field_2c0;
};
PKMN_OFFSET_ASSERT(Unk_556c30, field_2c0, 0x2c0);

struct Unk_556c40 {
    u8 _0[0x308];
    u8 field_308;
};
PKMN_OFFSET_ASSERT(Unk_556c40, field_308, 0x308);

struct Unk_556c50 {
    u8 _0[0x300];
    u64 field_300;
};
PKMN_OFFSET_ASSERT(Unk_556c50, field_300, 0x300);

struct Unk_556c60 {
    u8 _0[0x348];
    u64 field_348;
};
PKMN_OFFSET_ASSERT(Unk_556c60, field_348, 0x348);

struct Unk_555bd0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_555bd0, field_30, 0x30);

struct Unk_555bf0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_555bf0, field_60, 0x60);

struct Unk_555be0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_555be0, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXRenderTarget {
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
    const u8* vf17();
    u32 vf18();
    const u8* vf29();
    const u8* vf30();
    u32 vf31();
    u64 vf32();
    u64 vf33();
    u8 vf34();
    const u8* vf35();
    const u8* vf36();
    const u8* vf37();
    u64 vf38();
    u64 vf39();
    const u8* vf41();
    u32 vf42();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x7100555bd0
const u8* SiSDK3::SiGfxNXRenderTarget::vf41() {
    const Unk_555bd0* self = reinterpret_cast<const Unk_555bd0*>(this);
    return &self->field_30;
}

// 0x7100555be0
const u8* SiSDK3::SiGfxNXRenderTarget::vf3() {
    const Unk_555be0* self = reinterpret_cast<const Unk_555be0*>(this);
    return &self->field_28;
}

// 0x7100555bf0
u32 SiSDK3::SiGfxNXRenderTarget::vf42() {
    const Unk_555bf0* self = reinterpret_cast<const Unk_555bf0*>(this);
    return self->field_60;
}

// 0x7100555c10
u64 SiSDK3::SiGfxNXRenderTarget::vf5() {
    const Unk_555c10* self = reinterpret_cast<const Unk_555c10*>(this);
    return self->field_20;
}

// 0x7100555c20
u64 SiSDK3::SiGfxNXRenderTarget::vf6() {
    const Unk_555c20* self = reinterpret_cast<const Unk_555c20*>(this);
    return self->field_20;
}

// 0x7100555c30
u64 SiSDK3::SiGfxNXRenderTarget::vf7() {
    const Unk_555c30* self = reinterpret_cast<const Unk_555c30*>(this);
    return self->field_28;
}

// 0x7100555c40
const u8* SiSDK3::SiGfxNXRenderTarget::vf8() {
    const Unk_555c40* self = reinterpret_cast<const Unk_555c40*>(this);
    return &self->field_64;
}

// 0x7100555c50
void SiSDK3::SiGfxNXRenderTarget::vf9() {
}

// 0x7100555c60
void SiSDK3::SiGfxNXRenderTarget::vf10() {
    Unk_555c60* self = reinterpret_cast<Unk_555c60*>(this);
    self->vf26();
}

// 0x7100555c70
void SiSDK3::SiGfxNXRenderTarget::vf11() {
}

// 0x7100555c80
void SiSDK3::SiGfxNXRenderTarget::vf12() {
}

// 0x7100555c90
void SiSDK3::SiGfxNXRenderTarget::vf13() {
}

// 0x7100555ca0
void SiSDK3::SiGfxNXRenderTarget::vf14() {
}

// 0x7100555cb0
const u8* SiSDK3::SiGfxNXRenderTarget::vf17() {
    const Unk_555cb0* self = reinterpret_cast<const Unk_555cb0*>(this);
    return &self->field_78;
}

// 0x7100555cc0
u32 SiSDK3::SiGfxNXRenderTarget::vf18() {
    Unk_555cc0* self = reinterpret_cast<Unk_555cc0*>(this);
    if (self->field_351 != 0) {
        return 0;
    }
    self->vf26();
    self->field_351 = 1;
    return 1;
}

// 0x7100556950
const u8* SiSDK3::SiGfxNXRenderTarget::vf29() {
    const Unk_556950* self = reinterpret_cast<const Unk_556950*>(this);
    return &self->field_260;
}

// 0x7100556960
const u8* SiSDK3::SiGfxNXRenderTarget::vf30() {
    const Unk_556960* self = reinterpret_cast<const Unk_556960*>(this);
    return &self->field_260;
}

// 0x7100556970
u32 SiSDK3::SiGfxNXRenderTarget::vf31() {
    return 1;
}

// 0x7100556980
u64 SiSDK3::SiGfxNXRenderTarget::vf32() {
    return 0;
}

// 0x7100556990
u64 SiSDK3::SiGfxNXRenderTarget::vf33() {
    return 0;
}

// 0x71005569a0
u8 SiSDK3::SiGfxNXRenderTarget::vf34() {
    const Unk_5569a0* self = reinterpret_cast<const Unk_5569a0*>(this);
    return self->field_350;
}

// 0x71005569b0
const u8* SiSDK3::SiGfxNXRenderTarget::vf35() {
    const Unk_5569b0* self = reinterpret_cast<const Unk_5569b0*>(this);
    return &self->field_298;
}

// 0x7100556c20
u32 SiSDK3::SiGfxNXRenderTarget::vf4() {
    const Unk_556c20* self = reinterpret_cast<const Unk_556c20*>(this);
    return self->field_18;
}

// 0x7100556c30
const u8* SiSDK3::SiGfxNXRenderTarget::vf36() {
    const Unk_556c30* self = reinterpret_cast<const Unk_556c30*>(this);
    return &self->field_2c0;
}

// 0x7100556c40
const u8* SiSDK3::SiGfxNXRenderTarget::vf37() {
    const Unk_556c40* self = reinterpret_cast<const Unk_556c40*>(this);
    return &self->field_308;
}

// 0x7100556c50
u64 SiSDK3::SiGfxNXRenderTarget::vf38() {
    const Unk_556c50* self = reinterpret_cast<const Unk_556c50*>(this);
    return self->field_300;
}

// 0x7100556c60
u64 SiSDK3::SiGfxNXRenderTarget::vf39() {
    const Unk_556c60* self = reinterpret_cast<const Unk_556c60*>(this);
    return self->field_348;
}
