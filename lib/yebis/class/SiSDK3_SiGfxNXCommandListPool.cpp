// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_54f770 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_54f770, field_10, 0x10);

struct Unk_54f430 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54f430, field_18, 0x18);

struct Unk_54f440 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54f440, field_18, 0x18);

struct Unk_54f450 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_54f450, field_20, 0x20);

struct Unk_54f610 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_54f610, field_78, 0x78);

struct Unk_54f6c0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_54f6c0, field_78, 0x78);

namespace SiSDK3 {
class SiGfxNXCommandListPool {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    u32 vf10();
    void vf13();
};
}  // namespace SiSDK3

// 0x710054f430
u64 SiSDK3::SiGfxNXCommandListPool::vf5() {
    const Unk_54f430* self = reinterpret_cast<const Unk_54f430*>(this);
    return self->field_18;
}

// 0x710054f440
u64 SiSDK3::SiGfxNXCommandListPool::vf6() {
    const Unk_54f440* self = reinterpret_cast<const Unk_54f440*>(this);
    return self->field_18;
}

// 0x710054f450
u32 SiSDK3::SiGfxNXCommandListPool::vf7() {
    const Unk_54f450* self = reinterpret_cast<const Unk_54f450*>(this);
    return self->field_20;
}

// 0x710054f610
u32 SiSDK3::SiGfxNXCommandListPool::vf10() {
    const Unk_54f610* self = reinterpret_cast<const Unk_54f610*>(this);
    return self->field_78;
}

// 0x710054f6c0
void SiSDK3::SiGfxNXCommandListPool::vf13() {
    Unk_54f6c0* self = reinterpret_cast<Unk_54f6c0*>(this);
    self->field_78 = 0;
}

// 0x710054f770
u32 SiSDK3::SiGfxNXCommandListPool::vf4() {
    const Unk_54f770* self = reinterpret_cast<const Unk_54f770*>(this);
    return self->field_10;
}
