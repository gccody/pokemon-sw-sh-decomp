// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_5552b0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5552b0, field_10, 0x10);

struct Unk_555170 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_555170, field_18, 0x18);

struct Unk_555180 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_555180, field_18, 0x18);

struct Unk_555190 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_555190, field_20, 0x20);

struct Unk_5551e0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5551e0, field_28, 0x28);

struct Unk_5551f0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5551f0, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXRenderPassState {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    const u8* vf10();
    const u8* vf11();
    u32 vf12();
};
}  // namespace SiSDK3

// 0x7100555170
u64 SiSDK3::SiGfxNXRenderPassState::vf5() {
    const Unk_555170* self = reinterpret_cast<const Unk_555170*>(this);
    return self->field_18;
}

// 0x7100555180
u64 SiSDK3::SiGfxNXRenderPassState::vf6() {
    const Unk_555180* self = reinterpret_cast<const Unk_555180*>(this);
    return self->field_18;
}

// 0x7100555190
u32 SiSDK3::SiGfxNXRenderPassState::vf7() {
    const Unk_555190* self = reinterpret_cast<const Unk_555190*>(this);
    return self->field_20;
}

// 0x71005551e0
const u8* SiSDK3::SiGfxNXRenderPassState::vf10() {
    const Unk_5551e0* self = reinterpret_cast<const Unk_5551e0*>(this);
    return &self->field_28;
}

// 0x71005551f0
const u8* SiSDK3::SiGfxNXRenderPassState::vf11() {
    const Unk_5551f0* self = reinterpret_cast<const Unk_5551f0*>(this);
    return &self->field_28;
}

// 0x7100555200
u32 SiSDK3::SiGfxNXRenderPassState::vf12() {
    return 0;
}

// 0x71005552b0
u32 SiSDK3::SiGfxNXRenderPassState::vf4() {
    const Unk_5552b0* self = reinterpret_cast<const Unk_5552b0*>(this);
    return self->field_10;
}
