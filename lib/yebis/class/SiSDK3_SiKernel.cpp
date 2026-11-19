// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4c23c0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4c23c0, field_10, 0x10);

struct Unk_4c07c0 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_4c07c0, field_48, 0x48);

struct Unk_4c0800 {
    u8 _0[0x484];
    bool field_484;
};
PKMN_OFFSET_ASSERT(Unk_4c0800, field_484, 0x484);

struct Unk_4c0810 {
    u8 _0[0x484];
    u8 field_484;
};
PKMN_OFFSET_ASSERT(Unk_4c0810, field_484, 0x484);

struct Unk_4c08f0 {
    u8 _0[0x488];
    u64 field_488;
};
PKMN_OFFSET_ASSERT(Unk_4c08f0, field_488, 0x488);

struct Unk_4c0900 {
    u8 _0[0x490];
    u8 field_490;
};
PKMN_OFFSET_ASSERT(Unk_4c0900, field_490, 0x490);

struct Unk_4c17f0 {
    u8 _0[0x450];
    u8 field_450;
};
PKMN_OFFSET_ASSERT(Unk_4c17f0, field_450, 0x450);

struct Unk_4c1870 {
    u8 _0[0x668];
    u8 field_668;
};
PKMN_OFFSET_ASSERT(Unk_4c1870, field_668, 0x668);

struct Unk_4c1880 {
    u8 _0[0x670];
    u8 field_670;
};
PKMN_OFFSET_ASSERT(Unk_4c1880, field_670, 0x670);

struct Unk_4c2080 {
    u8 _0[0xfe8];
    u8 field_fe8;
};
PKMN_OFFSET_ASSERT(Unk_4c2080, field_fe8, 0xfe8);

struct Unk_4c20c0 {
    u8 _0[0x1018];
    u8 field_1018;
};
PKMN_OFFSET_ASSERT(Unk_4c20c0, field_1018, 0x1018);

struct Unk_4c2200 {
    u8 _0[0xf30];
    u32 field_f30;
};
PKMN_OFFSET_ASSERT(Unk_4c2200, field_f30, 0xf30);

namespace SiSDK3 {
class SiKernel {
public:
    u32 vf4();
    u64 vf5();
    void vf9(bool value);
    u8 vf10();
    u64 vf12();
    const u8* vf15();
    u32 vf16();
    u32 vf17();
    u32 vf18();
    const u8* vf22();
    const u8* vf24();
    const u8* vf25();
    const u8* vf37();
    const u8* vf39();
    u32 vf41();
};
}  // namespace SiSDK3

// 0x71004c07c0
u64 SiSDK3::SiKernel::vf5() {
    const Unk_4c07c0* self = reinterpret_cast<const Unk_4c07c0*>(this);
    return self->field_48;
}

// 0x71004c0800
void SiSDK3::SiKernel::vf9(bool value) {
    Unk_4c0800* self = reinterpret_cast<Unk_4c0800*>(this);
    self->field_484 = value;
}

// 0x71004c0810
u8 SiSDK3::SiKernel::vf10() {
    const Unk_4c0810* self = reinterpret_cast<const Unk_4c0810*>(this);
    return self->field_484;
}

// 0x71004c08f0
u64 SiSDK3::SiKernel::vf12() {
    const Unk_4c08f0* self = reinterpret_cast<const Unk_4c08f0*>(this);
    return self->field_488;
}

// 0x71004c0900
const u8* SiSDK3::SiKernel::vf15() {
    const Unk_4c0900* self = reinterpret_cast<const Unk_4c0900*>(this);
    return &self->field_490;
}

// 0x71004c1770
u32 SiSDK3::SiKernel::vf16() {
    return 1;
}

// 0x71004c1780
u32 SiSDK3::SiKernel::vf17() {
    return 1;
}

// 0x71004c1790
u32 SiSDK3::SiKernel::vf18() {
    return 1;
}

// 0x71004c17f0
const u8* SiSDK3::SiKernel::vf22() {
    const Unk_4c17f0* self = reinterpret_cast<const Unk_4c17f0*>(this);
    return &self->field_450;
}

// 0x71004c1870
const u8* SiSDK3::SiKernel::vf24() {
    const Unk_4c1870* self = reinterpret_cast<const Unk_4c1870*>(this);
    return &self->field_668;
}

// 0x71004c1880
const u8* SiSDK3::SiKernel::vf25() {
    const Unk_4c1880* self = reinterpret_cast<const Unk_4c1880*>(this);
    return &self->field_670;
}

// 0x71004c2080
const u8* SiSDK3::SiKernel::vf37() {
    const Unk_4c2080* self = reinterpret_cast<const Unk_4c2080*>(this);
    return &self->field_fe8;
}

// 0x71004c20c0
const u8* SiSDK3::SiKernel::vf39() {
    const Unk_4c20c0* self = reinterpret_cast<const Unk_4c20c0*>(this);
    return &self->field_1018;
}

// 0x71004c2200
u32 SiSDK3::SiKernel::vf41() {
    const Unk_4c2200* self = reinterpret_cast<const Unk_4c2200*>(this);
    return self->field_f30;
}

// 0x71004c23c0
u32 SiSDK3::SiKernel::vf4() {
    const Unk_4c23c0* self = reinterpret_cast<const Unk_4c23c0*>(this);
    return self->field_10;
}
