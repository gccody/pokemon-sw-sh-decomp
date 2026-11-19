// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK319SiGfxNXCommandCacheE
#include <types.h>

struct Unk_54d920 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_54d920, field_10, 0x10);

struct Unk_54d850 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54d850, field_18, 0x18);

struct Unk_54d860 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54d860, field_18, 0x18);

struct Unk_54d870 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_54d870, field_20, 0x20);

struct Unk_54d930 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_54d930, field_28, 0x28);

struct Unk_54d940 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_54d940, field_c8, 0xc8);

namespace SiSDK3 {
class SiGfxNXCommandCache {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    const u8* vf8();
    u64 vf9();
};
}  // namespace SiSDK3

// 0x710054d850
u64 SiSDK3::SiGfxNXCommandCache::vf5() {
    const Unk_54d850* self = reinterpret_cast<const Unk_54d850*>(this);
    return self->field_18;
}

// 0x710054d860
u64 SiSDK3::SiGfxNXCommandCache::vf6() {
    const Unk_54d860* self = reinterpret_cast<const Unk_54d860*>(this);
    return self->field_18;
}

// 0x710054d870
u32 SiSDK3::SiGfxNXCommandCache::vf7() {
    const Unk_54d870* self = reinterpret_cast<const Unk_54d870*>(this);
    return self->field_20;
}

// 0x710054d920
u32 SiSDK3::SiGfxNXCommandCache::vf4() {
    const Unk_54d920* self = reinterpret_cast<const Unk_54d920*>(this);
    return self->field_10;
}

// 0x710054d930
const u8* SiSDK3::SiGfxNXCommandCache::vf8() {
    const Unk_54d930* self = reinterpret_cast<const Unk_54d930*>(this);
    return &self->field_28;
}

// 0x710054d940
u64 SiSDK3::SiGfxNXCommandCache::vf9() {
    const Unk_54d940* self = reinterpret_cast<const Unk_54d940*>(this);
    return self->field_c8;
}
