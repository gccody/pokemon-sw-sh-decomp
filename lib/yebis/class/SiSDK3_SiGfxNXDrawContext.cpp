// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_542920 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_542920, field_10, 0x10);

struct Unk_53bb50 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_53bb50, field_18, 0x18);

struct Unk_53bb60 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_53bb60, field_18, 0x18);

struct Unk_53bb70 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_53bb70, field_20, 0x20);

struct Unk_53be30 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_53be30, field_28, 0x28);

struct Unk_540740 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_540740, field_50, 0x50);

struct Unk_540950_arg1 {
    u8 _0[0xd8];
    u8 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_540950_arg1, field_d8, 0xd8);

struct Unk_5422a0 {
    u8 _0[0x3a70];
    u8 field_3a70;
};
PKMN_OFFSET_ASSERT(Unk_5422a0, field_3a70, 0x3a70);

struct Unk_5422b0 {
    u8 _0[0x3a70];
    u8 field_3a70;
};
PKMN_OFFSET_ASSERT(Unk_5422b0, field_3a70, 0x3a70);

struct Unk_540720 {
    u8 _0[0x538];
    u8 field_538;
};
PKMN_OFFSET_ASSERT(Unk_540720, field_538, 0x538);

struct Unk_540730 {
    u8 _0[0x538];
    u8 field_538;
};
PKMN_OFFSET_ASSERT(Unk_540730, field_538, 0x538);

struct Unk_541e50 {
    u8 _0[0x3a60];
    u64 field_3a60;
};
PKMN_OFFSET_ASSERT(Unk_541e50, field_3a60, 0x3a60);

namespace SiSDK3 {
class SiGfxNXDrawContext {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    u64 vf10();
    void vf13();
    void vf18();
    u32 vf27();
    u32 vf29();
    void vf32();
    const u8* vf33();
    u32 vf60();
    const u8* vf65(const Unk_540950_arg1* value);
    u32 vf66();
    u32 vf67();
    u32 vf68();
    void vf79();
    void vf80();
    void vf81();
    void vf82();
    const u8* vf85();
    const u8* vf86();
    void vf87();
    void vf88();
    void vf89();
    void vf90();
    void vf93();
    const u8* vf96();
    const u8* vf97();
    u64 vf102();
};
}  // namespace SiSDK3

// 0x710053bb50
u64 SiSDK3::SiGfxNXDrawContext::vf5() {
    const Unk_53bb50* self = reinterpret_cast<const Unk_53bb50*>(this);
    return self->field_18;
}

// 0x710053bb60
u64 SiSDK3::SiGfxNXDrawContext::vf6() {
    const Unk_53bb60* self = reinterpret_cast<const Unk_53bb60*>(this);
    return self->field_18;
}

// 0x710053bb70
u32 SiSDK3::SiGfxNXDrawContext::vf7() {
    const Unk_53bb70* self = reinterpret_cast<const Unk_53bb70*>(this);
    return self->field_20;
}

// 0x710053be30
u64 SiSDK3::SiGfxNXDrawContext::vf10() {
    const Unk_53be30* self = reinterpret_cast<const Unk_53be30*>(this);
    return self->field_28;
}

// 0x710053cfb0
void SiSDK3::SiGfxNXDrawContext::vf18() {
}

// 0x7100540430
u32 SiSDK3::SiGfxNXDrawContext::vf29() {
    return 1;
}

// 0x7100540620
void SiSDK3::SiGfxNXDrawContext::vf32() {
}

// 0x7100540720
const u8* SiSDK3::SiGfxNXDrawContext::vf96() {
    const Unk_540720* self = reinterpret_cast<const Unk_540720*>(this);
    return &self->field_538;
}

// 0x7100540730
const u8* SiSDK3::SiGfxNXDrawContext::vf97() {
    const Unk_540730* self = reinterpret_cast<const Unk_540730*>(this);
    return &self->field_538;
}

// 0x7100540740
const u8* SiSDK3::SiGfxNXDrawContext::vf33() {
    const Unk_540740* self = reinterpret_cast<const Unk_540740*>(this);
    return &self->field_50;
}

// 0x7100540830
u32 SiSDK3::SiGfxNXDrawContext::vf60() {
    return 1;
}

// 0x7100540950
const u8* SiSDK3::SiGfxNXDrawContext::vf65(const Unk_540950_arg1* value) {
    return &value->field_d8;
}

// 0x7100540960
u32 SiSDK3::SiGfxNXDrawContext::vf66() {
    return 1;
}

// 0x7100540970
u32 SiSDK3::SiGfxNXDrawContext::vf67() {
    return 1;
}

// 0x7100540980
u32 SiSDK3::SiGfxNXDrawContext::vf68() {
    return 1;
}

// 0x7100541e50
u64 SiSDK3::SiGfxNXDrawContext::vf102() {
    const Unk_541e50* self = reinterpret_cast<const Unk_541e50*>(this);
    return self->field_3a60;
}

// 0x7100542220
void SiSDK3::SiGfxNXDrawContext::vf79() {
}

// 0x7100542230
void SiSDK3::SiGfxNXDrawContext::vf80() {
}

// 0x7100542240
void SiSDK3::SiGfxNXDrawContext::vf81() {
}

// 0x7100542250
void SiSDK3::SiGfxNXDrawContext::vf82() {
}

// 0x71005422a0
const u8* SiSDK3::SiGfxNXDrawContext::vf85() {
    const Unk_5422a0* self = reinterpret_cast<const Unk_5422a0*>(this);
    return &self->field_3a70;
}

// 0x71005422b0
const u8* SiSDK3::SiGfxNXDrawContext::vf86() {
    const Unk_5422b0* self = reinterpret_cast<const Unk_5422b0*>(this);
    return &self->field_3a70;
}

// 0x71005422c0
void SiSDK3::SiGfxNXDrawContext::vf87() {
}

// 0x71005422d0
void SiSDK3::SiGfxNXDrawContext::vf88() {
}

// 0x71005422e0
void SiSDK3::SiGfxNXDrawContext::vf89() {
}

// 0x71005422f0
void SiSDK3::SiGfxNXDrawContext::vf90() {
}

// 0x7100542790
void SiSDK3::SiGfxNXDrawContext::vf93() {
}

// 0x7100542920
u32 SiSDK3::SiGfxNXDrawContext::vf4() {
    const Unk_542920* self = reinterpret_cast<const Unk_542920*>(this);
    return self->field_10;
}

// 0x7100542930
void SiSDK3::SiGfxNXDrawContext::vf13() {
}

// 0x7100542940
u32 SiSDK3::SiGfxNXDrawContext::vf27() {
    return 1;
}
