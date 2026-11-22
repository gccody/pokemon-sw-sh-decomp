// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_55c990 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55c990, field_28, 0x28);

// 0x710055c990
u32 Unk_55c990_update(Unk_55c990* self, u64 value) {
    self->field_28 = value;
    return 1;
}

struct Unk_55cd30 {
    u8 _0[0xc8];
    u64 field_c8;
    u32 field_d0;
    u8 _d4[0xc];
    u64 field_e0;
    u64 field_e8;
    u8 _f0[0x1c];
    u8 field_10c;
};
PKMN_OFFSET_ASSERT(Unk_55cd30, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_55cd30, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_55cd30, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_55cd30, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_55cd30, field_10c, 0x10c);

// 0x710055cd70: SiGfxNXSurface's (SiGfx_NX_Surface_Impl.cpp)
namespace SiSDK3 {
class SiGfxNXSurface {
public:
    void Unk_55cd70(u32 a1, u32 level, u32 layer);
};
}  // namespace SiSDK3

// 0x710055cd30
u32 Unk_55cd30_call(Unk_55cd30* self, u64 value, u32 arg2, u64 arg3, u64 arg4) {
    self->field_c8 = value;
    self->field_d0 = arg2;
    self->field_e0 = arg3;
    self->field_e8 = arg4;
    self->field_10c = 0;
    reinterpret_cast<SiSDK3::SiGfxNXSurface*>(self)->Unk_55cd70(3, 0, 0);
    return 1;
}

struct Unk_55d3b0 {
    u8 _0[0x108];
    u32 field_108;
};
PKMN_OFFSET_ASSERT(Unk_55d3b0, field_108, 0x108);

// 0x710055d3b0
u32 Unk_55d3b0_get(const Unk_55d3b0* self) {
    return self->field_108;
}
