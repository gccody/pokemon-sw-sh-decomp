// Scope: common
// SiGfx's NVN draw state's reset (placeholder file and names): clears an
// object that holds every NVN state of a draw, gives the states their
// defaults and numbers six tables of 64 slots; and the destructor of the
// draw context's states, which hold that object.
#include <nx_middleware/gfx/nvn.h>
#include <string.h>
#include <types.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DrawContext_Impl.h>

// 0x710055b740
SiSDK3::SiGfxNXDrawContext::Unk_States::Unk_States() : field_2760(16) {
    memset(&field_8, 0, 0x2760 - 8);
    for (s32 i = 0; i < 6; i++) {
        field_2778[i] = Unk_SlotRange(14);
        field_2808[i] = Unk_SlotRange(64);
        field_2898[i] = Unk_SlotRange(14);
        field_2928[i] = Unk_SlotRange(64);
    }
    field_29b8 = Unk_SlotRange(64);
    memset(field_29d0, 0, 0x2c40 - 0x29d0);
}

// 0x710055ba20
SiSDK3::SiGfxNXDrawContext::Unk_States::~Unk_States() {}

// NON_MATCHING: the same instructions in another order, and field_0 stored
// alone where the original stores it with field_4 as one word (`stp x9,
// xzr, [x19]`; here field_4 to field_18 are one memset). The original
// schedules the zeros of the first ranges' bits and of field_8 to field_18
// before the lowest slots, and the first range's lowest last. Tried: the 120
// orders of the five first stores with the 6 orders of the reset's three, the
// reset as an assignment, the first range's reset after the others.
// 0x710055ba30
void Unk_55ba30(void* p) {
    SiSDK3::SiGfxNXDrawContext::Unk_States* states = static_cast<SiSDK3::SiGfxNXDrawContext::Unk_States*>(p);
    memset(&states->field_20, 0, sizeof(states->field_20));
    Unk_55bc90(reinterpret_cast<Unk_55bc90_States*>(&states->field_508));
    states->field_0 = 0x7fffffff;
    states->field_4 = 0;
    for (s32 i = 0; i < 6; i++) {
        states->field_8[i] = 0;
    }
    states->field_2760.Unk_Reset();
    for (s32 i = 0; i < 6; i++) {
        states->field_2778[i].Unk_Reset();
        states->field_2808[i].Unk_Reset();
        states->field_2898[i].Unk_Reset();
        states->field_2928[i].Unk_Reset();
    }
    states->field_29b8.Unk_Reset();
    memset(states->field_29d0, 0, 0x2c40 - 0x29d0);
}

// The object (placeholder name), as far as this function shows it.
struct Unk_55bc90_States {
    u8 field_0[0x3b8];
    u64 field_3b8[8];   // NVNblendState
    u64 field_3f8;      // NVNpolygonState
    u64 field_400;      // NVNdepthStencilState
    u8 field_408[0x18];  // NVNmultisampleState
    u32 field_420;      // NVNcolorState
    u32 field_424;      // NVNchannelMaskState
    u32 field_428;
    u32 field_42c[32];  // NVNvertexAttribState
    u32 field_4ac;
    u64 field_4b0[16];  // NVNvertexStreamState
    u8 field_530[0x18];
    u32 field_548;
    u8 field_54c[0x904];
    u8 field_e50[0x200];
    u8 field_1050[0xc00];
    u32 field_1c50[6][64];
    u8 field_2250[8];
};
PKMN_SIZE_ASSERT(Unk_55bc90_States, 0x2258);
PKMN_OFFSET_ASSERT(Unk_55bc90_States, field_42c, 0x42c);
PKMN_OFFSET_ASSERT(Unk_55bc90_States, field_e50, 0xe50);
PKMN_OFFSET_ASSERT(Unk_55bc90_States, field_1c50, 0x1c50);

namespace {

// nvn.h declares these two without their types
inline void Unk_VertexAttribStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd118)(state);
}
inline void Unk_VertexStreamStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd140)(state);
}

}  // namespace

// 0x710055bc90
// (The last loop becomes a memset after TailCallElim has run, which is why
// the original calls it with `bl` instead of a tail call.)
void Unk_55bc90(Unk_55bc90_States* self) {
    memset(self, 0, sizeof(*self));
    self->field_548 = 0x1f;
    nvnPolygonStateSetDefaults(&self->field_3f8);
    nvnMultisampleStateSetDefaults(&self->field_408);
    nvnDepthStencilStateSetDefaults(&self->field_400);
    nvnColorStateSetDefaults(&self->field_420);
    nvnChannelMaskStateSetDefaults(&self->field_424);
    for (s32 i = 0; i < 8; i++) {
        nvnBlendStateSetDefaults(&self->field_3b8[i]);
    }
    for (s32 i = 0; i < 32; i++) {
        Unk_VertexAttribStateSetDefaults(&self->field_42c[i]);
    }
    for (s32 i = 0; i < 16; i++) {
        Unk_VertexStreamStateSetDefaults(&self->field_4b0[i]);
    }
    for (s32 i = 0; i < 6; i++) {
        for (s32 j = 0; j < 64; j++) {
            self->field_1c50[i][j] = j;
        }
    }
    for (s32 i = 0; i < 0x200; i++) {
        self->field_e50[i] = 0xff;
    }
}
