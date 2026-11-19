// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK317SiGfxNXDeviceInfoE
#include <types.h>

struct Unk_5397b0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5397b0, field_10, 0x10);

struct Unk_539400 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_539400, field_18, 0x18);

struct Unk_539410 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_539410, field_18, 0x18);

struct Unk_539420 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_539420, field_20, 0x20);

struct Unk_539560 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_539560, field_80, 0x80);

struct Unk_539640 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_539640, field_a0, 0xa0);

namespace SiSDK3 {
class SiGfxNXDeviceInfo {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    const u8* vf7();
    u32 vf8();
    u64 vf10();
    void vf11();
    const u8* vf12();
    u32 vf13();
    u32 vf14();
    u32 vf15();
    u32 vf16();
    u32 vf17();
    u32 vf18();
    u32 vf19();
    u32 vf20();
    u32 vf22();
    u32 vf23();
    u32 vf24();
    u32 vf25();
    const u8* vf26();
};
}  // namespace SiSDK3

// 0x7100539400
u64 SiSDK3::SiGfxNXDeviceInfo::vf5() {
    const Unk_539400* self = reinterpret_cast<const Unk_539400*>(this);
    return self->field_18;
}

// 0x7100539410
u64 SiSDK3::SiGfxNXDeviceInfo::vf6() {
    const Unk_539410* self = reinterpret_cast<const Unk_539410*>(this);
    return self->field_18;
}

// 0x7100539420
const u8* SiSDK3::SiGfxNXDeviceInfo::vf7() {
    const Unk_539420* self = reinterpret_cast<const Unk_539420*>(this);
    return &self->field_20;
}

// 0x7100539430
u32 SiSDK3::SiGfxNXDeviceInfo::vf8() {
    return 0;
}

// 0x7100539540
u64 SiSDK3::SiGfxNXDeviceInfo::vf10() {
    return 0;
}

// 0x7100539550
void SiSDK3::SiGfxNXDeviceInfo::vf11() {
}

// 0x7100539560
const u8* SiSDK3::SiGfxNXDeviceInfo::vf12() {
    const Unk_539560* self = reinterpret_cast<const Unk_539560*>(this);
    return &self->field_80;
}

// 0x7100539570
u32 SiSDK3::SiGfxNXDeviceInfo::vf13() {
    return 0;
}

// 0x7100539580
u32 SiSDK3::SiGfxNXDeviceInfo::vf14() {
    return 1;
}

// 0x7100539590
u32 SiSDK3::SiGfxNXDeviceInfo::vf15() {
    return 6;
}

// 0x71005395a0
u32 SiSDK3::SiGfxNXDeviceInfo::vf16() {
    return 1;
}

// 0x71005395b0
u32 SiSDK3::SiGfxNXDeviceInfo::vf17() {
    return 1;
}

// 0x71005395c0
u32 SiSDK3::SiGfxNXDeviceInfo::vf18() {
    return 0x10;
}

// 0x71005395d0
u32 SiSDK3::SiGfxNXDeviceInfo::vf19() {
    return 1;
}

// 0x71005395e0
u32 SiSDK3::SiGfxNXDeviceInfo::vf20() {
    return 0;
}

// 0x7100539600
u32 SiSDK3::SiGfxNXDeviceInfo::vf22() {
    return 1;
}

// 0x7100539610
u32 SiSDK3::SiGfxNXDeviceInfo::vf23() {
    return 1;
}

// 0x7100539620
u32 SiSDK3::SiGfxNXDeviceInfo::vf24() {
    return 0;
}

// 0x7100539630
u32 SiSDK3::SiGfxNXDeviceInfo::vf25() {
    return 0;
}

// 0x7100539640
const u8* SiSDK3::SiGfxNXDeviceInfo::vf26() {
    const Unk_539640* self = reinterpret_cast<const Unk_539640*>(this);
    return &self->field_a0;
}

// 0x71005397b0
u32 SiSDK3::SiGfxNXDeviceInfo::vf4() {
    const Unk_5397b0* self = reinterpret_cast<const Unk_5397b0*>(this);
    return self->field_10;
}
