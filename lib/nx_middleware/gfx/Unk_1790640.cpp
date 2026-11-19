// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: swap chains. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

struct Unk_1790ca0_View;
struct Unk_1790b60_Texture;
void Unk_1790f00(Unk_1790ca0_View* self, const Unk_1791080_Device* device);
void Unk_1790c30(Unk_1790b60_Texture* self, const Unk_1791080_Device* device);

// A scan buffer: a texture and its color target view.
struct Unk_1790640_Texture {
    u8 field_0[0xd8];
};
struct Unk_1790640_View {
    u8 field_0[0x48];
};

// A swap chain: its NVN window (in field_10), a state, flags, the acquired
// texture's index and its scan buffers.
struct Unk_1790640_SwapChain {
    u8 _0[0x8];
    void* field_8;
    u8 _10[0x180];
    u8 field_190;
    u8 field_191;
    u8 _192[0x6];
    s32 field_198;
    u8 _19c[0x4];
    Unk_1790640_Texture field_1a0[4];
    Unk_1790640_View field_500[4];
    u8 _620[0x8];
};
PKMN_OFFSET_ASSERT(Unk_1790640_SwapChain, field_198, 0x198);
PKMN_OFFSET_ASSERT(Unk_1790640_SwapChain, field_1a0, 0x1a0);
PKMN_OFFSET_ASSERT(Unk_1790640_SwapChain, field_500, 0x500);
PKMN_SIZE_ASSERT(Unk_1790640_SwapChain, 0x628);

// 0x7101790640
void Unk_1790640(Unk_1790640_SwapChain* self, const Unk_1791080_Device* device) {
    nvnWindowFinalize(self->field_8);
    self->field_8 = nullptr;
    for (int i = 0; i < self->field_198; ++i) {
        Unk_1790640_Texture* texture = &self->field_1a0[i];
        Unk_1790640_View* view = &self->field_500[i];
        Unk_1790f00(reinterpret_cast<Unk_1790ca0_View*>(view), device);
        Unk_1790c30(reinterpret_cast<Unk_1790b60_Texture*>(texture), device);
    }
    self->field_190 = 0;
}

static inline int Unk_17906e0_Min(int a, int b) {
    return a < b ? a : b;
}

// 0x71017906e0
// NON_MATCHING (this and Unk_1790780): the unrolled loop's remainder keeps the
// pointer and the destination in the other two registers.
int Unk_17906e0(Unk_1790640_SwapChain* self, Unk_1790640_View** views, int count) {
    int scanBufferCount = self->field_198;
    if (views != nullptr) {
        scanBufferCount = Unk_17906e0_Min(scanBufferCount, count);
        for (int i = 0; i < scanBufferCount; ++i) {
            views[i] = &self->field_500[i];
        }
    }
    return scanBufferCount;
}

// 0x7101790780
int Unk_1790780(Unk_1790640_SwapChain* self, Unk_1790640_Texture** textures, int count) {
    int scanBufferCount = self->field_198;
    if (textures != nullptr) {
        scanBufferCount = Unk_17906e0_Min(scanBufferCount, count);
        for (int i = 0; i < scanBufferCount; ++i) {
            textures[i] = &self->field_1a0[i];
        }
    }
    return scanBufferCount;
}
