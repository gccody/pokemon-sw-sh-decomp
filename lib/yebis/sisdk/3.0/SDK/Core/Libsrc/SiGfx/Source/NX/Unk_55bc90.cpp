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

// field_4 is cleared before field_0 is set: a zero stored right before the
// loop's memset (the six words from field_8) is merged into it by MemCpyOpt,
// and field_0's store between them keeps the two words one 8-byte store
// (`stp x9, xzr, [x19]`, with the memset's first word).
// NON_MATCHING: the ranges' resets are scheduled in another order (the
// original computes every range's lowest slot first, field_2760's last, with
// the first ranges' bits' zeros among them, then stores the -1s and the other
// zeros in pairs). Tried: the 120 orders of the first five statements, the
// reset's three stores in all six orders (a local helper), one loop or four,
// field_2760's reset before or after the loop.
// 0x710055ba30
void Unk_55ba30(void* p) {
    SiSDK3::SiGfxNXDrawContext::Unk_States* states = static_cast<SiSDK3::SiGfxNXDrawContext::Unk_States*>(p);
    memset(&states->field_20, 0, sizeof(states->field_20));
    Unk_55bc90(reinterpret_cast<Unk_55bc90_States*>(&states->field_508));
    states->field_4 = 0;
    states->field_0 = 0x7fffffff;
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
