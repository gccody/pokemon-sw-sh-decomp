// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4ffce0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4ffce0, field_18, 0x18);

struct Unk_4ff870 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4ff870, field_20, 0x20);

struct Unk_4ff880 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4ff880, field_20, 0x20);

struct Unk_4ff890 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4ff890, field_28, 0x28);

struct Unk_4ff8a0 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_4ff8a0, field_64, 0x64);

struct Unk_4ff8c0 {
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
};

struct Unk_4ff910 {
    u8 _0[0x98];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_4ff910, field_98, 0x98);

struct Unk_4ffaf0 {
    u8 _0[0x240];
    u8 field_240;
};
PKMN_OFFSET_ASSERT(Unk_4ffaf0, field_240, 0x240);

struct Unk_4ff830 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_4ff830, field_30, 0x30);

struct Unk_4ff850 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_4ff850, field_60, 0x60);

struct Unk_4ff840 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4ff840, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXFont {
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
    const u8* vf20();
    const u8* vf26();
    u32 vf27();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x71004ff830
const u8* SiSDK3::SiGfxNXFont::vf26() {
    const Unk_4ff830* self = reinterpret_cast<const Unk_4ff830*>(this);
    return &self->field_30;
}

// 0x71004ff840
const u8* SiSDK3::SiGfxNXFont::vf3() {
    const Unk_4ff840* self = reinterpret_cast<const Unk_4ff840*>(this);
    return &self->field_28;
}

// 0x71004ff850
u32 SiSDK3::SiGfxNXFont::vf27() {
    const Unk_4ff850* self = reinterpret_cast<const Unk_4ff850*>(this);
    return self->field_60;
}

// 0x71004ff870
u64 SiSDK3::SiGfxNXFont::vf5() {
    const Unk_4ff870* self = reinterpret_cast<const Unk_4ff870*>(this);
    return self->field_20;
}

// 0x71004ff880
u64 SiSDK3::SiGfxNXFont::vf6() {
    const Unk_4ff880* self = reinterpret_cast<const Unk_4ff880*>(this);
    return self->field_20;
}

// 0x71004ff890
u64 SiSDK3::SiGfxNXFont::vf7() {
    const Unk_4ff890* self = reinterpret_cast<const Unk_4ff890*>(this);
    return self->field_28;
}

// 0x71004ff8a0
const u8* SiSDK3::SiGfxNXFont::vf8() {
    const Unk_4ff8a0* self = reinterpret_cast<const Unk_4ff8a0*>(this);
    return &self->field_64;
}

// 0x71004ff8b0
void SiSDK3::SiGfxNXFont::vf9() {
}

// 0x71004ff8c0
void SiSDK3::SiGfxNXFont::vf10() {
    Unk_4ff8c0* self = reinterpret_cast<Unk_4ff8c0*>(this);
    self->vf19();
}

// 0x71004ff8d0
void SiSDK3::SiGfxNXFont::vf11() {
}

// 0x71004ff8e0
void SiSDK3::SiGfxNXFont::vf12() {
}

// 0x71004ff8f0
void SiSDK3::SiGfxNXFont::vf13() {
}

// 0x71004ff900
void SiSDK3::SiGfxNXFont::vf14() {
}

// 0x71004ff910
const u8* SiSDK3::SiGfxNXFont::vf17() {
    const Unk_4ff910* self = reinterpret_cast<const Unk_4ff910*>(this);
    return &self->field_98;
}

// 0x71004ffaf0
const u8* SiSDK3::SiGfxNXFont::vf20() {
    const Unk_4ffaf0* self = reinterpret_cast<const Unk_4ffaf0*>(this);
    return &self->field_240;
}

// 0x71004ffbf0
void SiSDK3::SiGfxNXFont::vf15() {
}

// 0x71004ffc00
u32 SiSDK3::SiGfxNXFont::vf16() {
    return 0;
}

// 0x71004ffce0
u32 SiSDK3::SiGfxNXFont::vf4() {
    const Unk_4ffce0* self = reinterpret_cast<const Unk_4ffce0*>(this);
    return self->field_18;
}
