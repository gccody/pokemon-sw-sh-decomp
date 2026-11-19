// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK319SiGfxNXCommandQueueE
#include <types.h>

struct Unk_54e660 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_54e660, field_10, 0x10);

struct Unk_54e2d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54e2d0, field_18, 0x18);

struct Unk_54e2e0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54e2e0, field_18, 0x18);

struct Unk_54e590 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_54e590, field_24, 0x24);

struct Unk_54e670 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_54e670, field_50, 0x50);

namespace SiSDK3 {
class SiGfxNXCommandQueue {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    u32 vf9();
    void vf11();
    const u8* vf14();
    const u8* vf16();
};
}  // namespace SiSDK3

// 0x710054e2d0
u64 SiSDK3::SiGfxNXCommandQueue::vf5() {
    const Unk_54e2d0* self = reinterpret_cast<const Unk_54e2d0*>(this);
    return self->field_18;
}

// 0x710054e2e0
u64 SiSDK3::SiGfxNXCommandQueue::vf6() {
    const Unk_54e2e0* self = reinterpret_cast<const Unk_54e2e0*>(this);
    return self->field_18;
}

// 0x710054e2f0
u32 SiSDK3::SiGfxNXCommandQueue::vf7() {
    return 1;
}

// 0x710054e320
u32 SiSDK3::SiGfxNXCommandQueue::vf9() {
    return 1;
}

// 0x710054e490
void SiSDK3::SiGfxNXCommandQueue::vf11() {
}

// 0x710054e590
const u8* SiSDK3::SiGfxNXCommandQueue::vf14() {
    const Unk_54e590* self = reinterpret_cast<const Unk_54e590*>(this);
    return &self->field_24;
}

// 0x710054e660
u32 SiSDK3::SiGfxNXCommandQueue::vf4() {
    const Unk_54e660* self = reinterpret_cast<const Unk_54e660*>(this);
    return self->field_10;
}

// 0x710054e670
const u8* SiSDK3::SiGfxNXCommandQueue::vf16() {
    const Unk_54e670* self = reinterpret_cast<const Unk_54e670*>(this);
    return &self->field_50;
}
