// Scope: common
// SiGfx's NVN draw state's reset (placeholder file and names): clears an
// object that holds every NVN state of a draw, gives the states their
// defaults and numbers six tables of 64 slots.
#include <nx_middleware/gfx/nvn.h>
#include <string.h>
#include <types.h>

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
// NON_MATCHING: the same instructions up to the last call, which the original makes with `bl`
// and returns from, and this makes as a tail call (4 bytes less).
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
    memset(self->field_e50, 0xff, sizeof(self->field_e50));
}
