// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_55d500 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_55d500, field_18, 0x18);

struct Unk_55cc20 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_55cc20, field_20, 0x20);

struct Unk_55cc30 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_55cc30, field_20, 0x20);

struct Unk_55cc40 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55cc40, field_28, 0x28);

struct Unk_55cc50 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_55cc50, field_64, 0x64);

struct Unk_55ccc0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_55ccc0, field_78, 0x78);

struct Unk_55ccd0 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_55ccd0, field_f0, 0xf0);

struct Unk_55cce0 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_55cce0, field_f0, 0xf0);

struct Unk_55ccf0 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_55ccf0, field_d8, 0xd8);

struct Unk_55cd00 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_55cd00, field_d8, 0xd8);

struct Unk_55cd10 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_55cd10, field_c8, 0xc8);

struct Unk_55cd20 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_55cd20, field_c8, 0xc8);

struct Unk_55d510 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_55d510, field_e0, 0xe0);

struct Unk_55d520 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_55d520, field_e8, 0xe8);

struct Unk_55cb20 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_55cb20, field_30, 0x30);

struct Unk_55cb40 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_55cb40, field_60, 0x60);

struct Unk_55cb30 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55cb30, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXSurface {
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
    u64 vf18();
    u64 vf19();
    u64 vf20();
    u64 vf21();
    u64 vf22();
    u64 vf23();
    u64 vf25();
    u64 vf26();
    const u8* vf29();
    u32 vf30();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x710055cb20
const u8* SiSDK3::SiGfxNXSurface::vf29() {
    const Unk_55cb20* self = reinterpret_cast<const Unk_55cb20*>(this);
    return &self->field_30;
}

// 0x710055cb30
const u8* SiSDK3::SiGfxNXSurface::vf3() {
    const Unk_55cb30* self = reinterpret_cast<const Unk_55cb30*>(this);
    return &self->field_28;
}

// 0x710055cb40
u32 SiSDK3::SiGfxNXSurface::vf30() {
    const Unk_55cb40* self = reinterpret_cast<const Unk_55cb40*>(this);
    return self->field_60;
}

// 0x710055cc20
u64 SiSDK3::SiGfxNXSurface::vf5() {
    const Unk_55cc20* self = reinterpret_cast<const Unk_55cc20*>(this);
    return self->field_20;
}

// 0x710055cc30
u64 SiSDK3::SiGfxNXSurface::vf6() {
    const Unk_55cc30* self = reinterpret_cast<const Unk_55cc30*>(this);
    return self->field_20;
}

// 0x710055cc40
u64 SiSDK3::SiGfxNXSurface::vf7() {
    const Unk_55cc40* self = reinterpret_cast<const Unk_55cc40*>(this);
    return self->field_28;
}

// 0x710055cc50
const u8* SiSDK3::SiGfxNXSurface::vf8() {
    const Unk_55cc50* self = reinterpret_cast<const Unk_55cc50*>(this);
    return &self->field_64;
}

// 0x710055cc60
void SiSDK3::SiGfxNXSurface::vf9() {
}

// 0x710055cc70
void SiSDK3::SiGfxNXSurface::vf10() {
}

// 0x710055cc80
void SiSDK3::SiGfxNXSurface::vf11() {
}

// 0x710055cc90
void SiSDK3::SiGfxNXSurface::vf12() {
}

// 0x710055cca0
void SiSDK3::SiGfxNXSurface::vf13() {
}

// 0x710055ccb0
void SiSDK3::SiGfxNXSurface::vf14() {
}

// 0x710055ccc0
const u8* SiSDK3::SiGfxNXSurface::vf17() {
    const Unk_55ccc0* self = reinterpret_cast<const Unk_55ccc0*>(this);
    return &self->field_78;
}

// 0x710055ccd0
u64 SiSDK3::SiGfxNXSurface::vf18() {
    const Unk_55ccd0* self = reinterpret_cast<const Unk_55ccd0*>(this);
    return self->field_f0;
}

// 0x710055cce0
u64 SiSDK3::SiGfxNXSurface::vf19() {
    const Unk_55cce0* self = reinterpret_cast<const Unk_55cce0*>(this);
    return self->field_f0;
}

// 0x710055ccf0
u64 SiSDK3::SiGfxNXSurface::vf20() {
    const Unk_55ccf0* self = reinterpret_cast<const Unk_55ccf0*>(this);
    return self->field_d8;
}

// 0x710055cd00
u64 SiSDK3::SiGfxNXSurface::vf21() {
    const Unk_55cd00* self = reinterpret_cast<const Unk_55cd00*>(this);
    return self->field_d8;
}

// 0x710055cd10
u64 SiSDK3::SiGfxNXSurface::vf22() {
    const Unk_55cd10* self = reinterpret_cast<const Unk_55cd10*>(this);
    return self->field_c8;
}

// 0x710055cd20
u64 SiSDK3::SiGfxNXSurface::vf23() {
    const Unk_55cd20* self = reinterpret_cast<const Unk_55cd20*>(this);
    return self->field_c8;
}

// 0x710055d500
u32 SiSDK3::SiGfxNXSurface::vf4() {
    const Unk_55d500* self = reinterpret_cast<const Unk_55d500*>(this);
    return self->field_18;
}

// 0x710055d510
u64 SiSDK3::SiGfxNXSurface::vf25() {
    const Unk_55d510* self = reinterpret_cast<const Unk_55d510*>(this);
    return self->field_e0;
}

// 0x710055d520
u64 SiSDK3::SiGfxNXSurface::vf26() {
    const Unk_55d520* self = reinterpret_cast<const Unk_55d520*>(this);
    return self->field_e8;
}
