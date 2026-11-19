// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: swap chains, fences, semaphores and
// textures. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// A fence or semaphore: the device, its NVN sync object (in field_10) and a
// state.
struct Unk_17908d0_Sync {
    Unk_1791080_Device* field_0;
    void* field_8;
    u8 field_10[0x40];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_17908d0_Sync, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17908d0_Sync, field_50, 0x50);

// A swap chain: its NVN window, flags (bit 1: a texture was acquired with a
// fence) and the acquired texture's index.
struct Unk_1790820_SwapChain {
    u8 _0[0x8];
    void* field_8;
    u8 _10[0x181];
    Unk_1787ac0_Flags field_191;
    u8 _192[0x2];
    s32 field_194;
};
PKMN_OFFSET_ASSERT(Unk_1790820_SwapChain, field_191, 0x191);
PKMN_OFFSET_ASSERT(Unk_1790820_SwapChain, field_194, 0x194);

// 0x7101790820
int Unk_1790820(Unk_1790820_SwapChain* self, int* index, const Unk_17908d0_Sync* semaphore,
                Unk_17908d0_Sync* fence) {
    int result = nvnWindowAcquireTexture(self->field_8, semaphore->field_8, index);
    self->field_194 = *index;
    if (fence != nullptr) {
        fence->field_8 = semaphore->field_8;
    }
    self->field_191.Set(2, true);
    return result != 0;
}

// 0x71017908d0
void Unk_17908d0(Unk_17908d0_Sync* self, Unk_1791080_Device* device) {
    self->field_0 = device;
    self->field_8 = self->field_10;
    nvnSyncInitialize(self->field_8, device->field_0);
    self->field_50 = 1;
}

// 0x7101790910
void Unk_1790910(Unk_17908d0_Sync* self, Unk_1791080_Device* device) {
    nvnSyncFinalize(self->field_10);
    self->field_8 = nullptr;
    self->field_50 = 0;
}

// 0x7101790950
int Unk_1790950(const Unk_17908d0_Sync* self, u64 timeout) {
    switch (nvnSyncWait(self->field_8, timeout)) {
    case 0:
        return 0;
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

// 0x71017909d0
void Unk_17909d0(Unk_17908d0_Sync* self, Unk_1791080_Device* device) {
    self->field_0 = device;
    self->field_8 = self->field_10;
    nvnSyncInitialize(self->field_8, device->field_0);
    self->field_50 = 1;
}

// 0x7101790a10
void Unk_1790a10(Unk_17908d0_Sync* self, Unk_1791080_Device* device) {
    nvnSyncFinalize(self->field_8);
    self->field_8 = nullptr;
    self->field_50 = 0;
}

void Unk_178dac0(void* builder, const Unk_178dac0_Info& info);

// 0x7101790a50
size_t Unk_1790a50(const Unk_1791080_Device* device, const Unk_178dac0_Info& info) {
    u8 builder[0x80];
    nvnTextureBuilderSetDevice(builder, device->field_0);
    Unk_178dac0(builder, info);
    return nvnTextureBuilderGetStorageAlignment(builder);
}

// 0x7101790ab0
size_t Unk_1790ab0(const Unk_1791080_Device* device, const Unk_178dac0_Info& info) {
    u8 builder[0x80];
    nvnTextureBuilderSetDevice(builder, device->field_0);
    Unk_178dac0(builder, info);
    return nvnTextureBuilderGetStorageSize(builder);
}

// A texture: a state, flags and its NVN texture (in field_10).
struct Unk_1790b60_Texture {
    u8 field_0;
    Unk_1787ac0_Flags field_1;
    u8 _2[0x6];
    void* field_8;
    u8 field_10[0xc0];
};
PKMN_OFFSET_ASSERT(Unk_1790b60_Texture, field_8, 0x8);

struct Unk_1789c10_MemoryPool;
struct Unk_1790b60_Pool {
    void* field_0;
};

// 0x71017911a0: does nothing in this build.
void Unk_17911a0(void* builder, const Unk_1790b60_Pool* pool, s64 offset, size_t size);

// 0x7101790b60
void Unk_1790b60(Unk_1790b60_Texture* self, const Unk_1791080_Device* device,
                 const Unk_178dac0_Info& info, const Unk_1790b60_Pool* pool, s64 offset,
                 size_t size) {
    u8 builder[0x80];
    nvnTextureBuilderSetDevice(builder, device->field_0);
    Unk_178dac0(builder, info);
    nvnTextureBuilderSetStorage(builder, pool->field_0, offset);
    if (info.field_10 & 0x20) {
        Unk_17911a0(builder, pool, offset, size);
    }
    self->field_8 = self->field_10;
    nvnTextureInitialize(self->field_8, builder);
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// 0x7101790c30
void Unk_1790c30(Unk_1790b60_Texture* self, const Unk_1791080_Device* device) {
    nvnTextureFinalize(self->field_8);
    self->field_8 = nullptr;
    self->field_0 = 0;
}
