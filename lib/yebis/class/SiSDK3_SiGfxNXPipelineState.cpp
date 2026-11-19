// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_554390 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_554390, field_10, 0x10);

struct Unk_553690 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_553690, field_18, 0x18);

struct Unk_5536a0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5536a0, field_18, 0x18);

struct Unk_5536b0 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5536b0, field_20, 0x20);

struct Unk_5536c0 {
    u8 _0[0x24];
    u32 field_24;
};
PKMN_OFFSET_ASSERT(Unk_5536c0, field_24, 0x24);

struct Unk_5542c0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5542c0, field_28, 0x28);

struct Unk_5542d0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5542d0, field_28, 0x28);

struct Unk_5543a0 {
    u8 _0[0x558];
    u8 field_558;
};
PKMN_OFFSET_ASSERT(Unk_5543a0, field_558, 0x558);

struct Unk_5543b0 {
    u8 _0[0x598];
    u8 field_598;
};
PKMN_OFFSET_ASSERT(Unk_5543b0, field_598, 0x598);

struct Unk_5543c0 {
    u8 _0[0x5a0];
    u8 field_5a0;
};
PKMN_OFFSET_ASSERT(Unk_5543c0, field_5a0, 0x5a0);

struct Unk_5543d0 {
    u8 _0[0x5a8];
    u8 field_5a8;
};
PKMN_OFFSET_ASSERT(Unk_5543d0, field_5a8, 0x5a8);

struct Unk_5543e0 {
    u8 _0[0x5c0];
    u8 field_5c0;
};
PKMN_OFFSET_ASSERT(Unk_5543e0, field_5c0, 0x5c0);

struct Unk_5543f0 {
    u8 _0[0x5c4];
    u8 field_5c4;
};
PKMN_OFFSET_ASSERT(Unk_5543f0, field_5c4, 0x5c4);

struct Unk_554400 {
    u8 _0[0x5c8];
    u8 field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_554400, field_5c8, 0x5c8);

struct Unk_554410 {
    u8 _0[0x648];
    u8 field_648;
};
PKMN_OFFSET_ASSERT(Unk_554410, field_648, 0x648);

struct Unk_554420 {
    u8 _0[0x6c8];
    u32 field_6c8;
};
PKMN_OFFSET_ASSERT(Unk_554420, field_6c8, 0x6c8);

struct Unk_554430 {
    u8 _0[0x6cc];
    u32 field_6cc;
};
PKMN_OFFSET_ASSERT(Unk_554430, field_6cc, 0x6cc);

struct Unk_554440 {
    u8 _0[0x6d0];
    u32 field_6d0;
};
PKMN_OFFSET_ASSERT(Unk_554440, field_6d0, 0x6d0);

struct Unk_554450 {
    u8 _0[0x6d4];
    u32 field_6d4;
};
PKMN_OFFSET_ASSERT(Unk_554450, field_6d4, 0x6d4);

namespace SiSDK3 {
class SiGfxNXPipelineState {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    u32 vf8();
    const u8* vf10();
    const u8* vf11();
    u32 vf12();
    const u8* vf13();
    const u8* vf14();
    const u8* vf15();
    const u8* vf16();
    const u8* vf17();
    const u8* vf18();
    const u8* vf19();
    const u8* vf20();
    u32 vf21();
    u32 vf22();
    u32 vf23();
    u32 vf24();
};
}  // namespace SiSDK3

// 0x7100553690
u64 SiSDK3::SiGfxNXPipelineState::vf5() {
    const Unk_553690* self = reinterpret_cast<const Unk_553690*>(this);
    return self->field_18;
}

// 0x71005536a0
u64 SiSDK3::SiGfxNXPipelineState::vf6() {
    const Unk_5536a0* self = reinterpret_cast<const Unk_5536a0*>(this);
    return self->field_18;
}

// 0x71005536b0
u32 SiSDK3::SiGfxNXPipelineState::vf7() {
    const Unk_5536b0* self = reinterpret_cast<const Unk_5536b0*>(this);
    return self->field_20;
}

// 0x71005536c0
u32 SiSDK3::SiGfxNXPipelineState::vf8() {
    Unk_5536c0* self = reinterpret_cast<Unk_5536c0*>(this);
    self->field_24 = self->field_24 + 1;
    return 1;
}

// 0x71005542c0
const u8* SiSDK3::SiGfxNXPipelineState::vf10() {
    const Unk_5542c0* self = reinterpret_cast<const Unk_5542c0*>(this);
    return &self->field_28;
}

// 0x71005542d0
const u8* SiSDK3::SiGfxNXPipelineState::vf11() {
    const Unk_5542d0* self = reinterpret_cast<const Unk_5542d0*>(this);
    return &self->field_28;
}

// 0x71005542e0
u32 SiSDK3::SiGfxNXPipelineState::vf12() {
    return 1;
}

// 0x7100554390
u32 SiSDK3::SiGfxNXPipelineState::vf4() {
    const Unk_554390* self = reinterpret_cast<const Unk_554390*>(this);
    return self->field_10;
}

// 0x71005543a0
const u8* SiSDK3::SiGfxNXPipelineState::vf13() {
    const Unk_5543a0* self = reinterpret_cast<const Unk_5543a0*>(this);
    return &self->field_558;
}

// 0x71005543b0
const u8* SiSDK3::SiGfxNXPipelineState::vf14() {
    const Unk_5543b0* self = reinterpret_cast<const Unk_5543b0*>(this);
    return &self->field_598;
}

// 0x71005543c0
const u8* SiSDK3::SiGfxNXPipelineState::vf15() {
    const Unk_5543c0* self = reinterpret_cast<const Unk_5543c0*>(this);
    return &self->field_5a0;
}

// 0x71005543d0
const u8* SiSDK3::SiGfxNXPipelineState::vf16() {
    const Unk_5543d0* self = reinterpret_cast<const Unk_5543d0*>(this);
    return &self->field_5a8;
}

// 0x71005543e0
const u8* SiSDK3::SiGfxNXPipelineState::vf17() {
    const Unk_5543e0* self = reinterpret_cast<const Unk_5543e0*>(this);
    return &self->field_5c0;
}

// 0x71005543f0
const u8* SiSDK3::SiGfxNXPipelineState::vf18() {
    const Unk_5543f0* self = reinterpret_cast<const Unk_5543f0*>(this);
    return &self->field_5c4;
}

// 0x7100554400
const u8* SiSDK3::SiGfxNXPipelineState::vf19() {
    const Unk_554400* self = reinterpret_cast<const Unk_554400*>(this);
    return &self->field_5c8;
}

// 0x7100554410
const u8* SiSDK3::SiGfxNXPipelineState::vf20() {
    const Unk_554410* self = reinterpret_cast<const Unk_554410*>(this);
    return &self->field_648;
}

// 0x7100554420
u32 SiSDK3::SiGfxNXPipelineState::vf21() {
    const Unk_554420* self = reinterpret_cast<const Unk_554420*>(this);
    return self->field_6c8;
}

// 0x7100554430
u32 SiSDK3::SiGfxNXPipelineState::vf22() {
    const Unk_554430* self = reinterpret_cast<const Unk_554430*>(this);
    return self->field_6cc;
}

// 0x7100554440
u32 SiSDK3::SiGfxNXPipelineState::vf23() {
    const Unk_554440* self = reinterpret_cast<const Unk_554440*>(this);
    return self->field_6d0;
}

// 0x7100554450
u32 SiSDK3::SiGfxNXPipelineState::vf24() {
    const Unk_554450* self = reinterpret_cast<const Unk_554450*>(this);
    return self->field_6d4;
}
