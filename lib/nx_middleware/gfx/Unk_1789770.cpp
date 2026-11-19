// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: descriptor pools and memory pools.
// Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// What the descriptor pool functions take: the descriptor type (0: buffers,
// 1: textures, 2: samplers) and the number of slots.
struct Unk_1789770_Info {
    u8 field_0;
    u8 _1[0x3];
    s32 field_4;
};
PKMN_SIZE_ASSERT(Unk_1789770_Info, 0x8);

// 0x7101789770
s64 Unk_1789770(const Unk_1791080_Device* device, const Unk_1789770_Info* info) {
    switch (info->field_0) {
    case 1: {
        int reserved = 0;
        nvnDeviceGetInteger(device->field_0, 0x11, &reserved);
        int size = 0;
        nvnDeviceGetInteger(device->field_0, 0xf, &size);
        return static_cast<s64>(info->field_4) * size;
    }
    case 0:
        return static_cast<s64>(info->field_4) * 0x10;
    case 2: {
        int reserved = 0;
        nvnDeviceGetInteger(device->field_0, 0x12, &reserved);
        int size = 0;
        nvnDeviceGetInteger(device->field_0, 0x10, &size);
        return static_cast<s64>(info->field_4) * size;
    }
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

// 0x7101789860
s64 Unk_1789860(const Unk_1791080_Device* device, const Unk_1789770_Info* info) {
    switch (info->field_0) {
    case 0:
        return 4;
    case 1: {
        int alignment = 0;
        nvnDeviceGetInteger(device->field_0, 0xf, &alignment);
        return alignment;
    }
    case 2: {
        int alignment = 0;
        nvnDeviceGetInteger(device->field_0, 0x10, &alignment);
        return alignment;
    }
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

// A memory pool: its NVN memory pool (in field_10), the memory, a state and
// flags.
struct Unk_1789c10_MemoryPool {
    void* field_0;
    void* field_8;
    u8 field_10[0x100];
    u8 field_110;
    Unk_1787ac0_Flags field_111;
    u8 _112[0xe];
};
PKMN_SIZE_ASSERT(Unk_1789c10_MemoryPool, 0x120);
PKMN_OFFSET_ASSERT(Unk_1789c10_MemoryPool, field_110, 0x110);

// A descriptor pool: a state, its type, flags, the number of slots, the
// number of reserved slots and the NVN pool (in field_18), or the memory of a
// buffer pool.
struct Unk_1789940_Pool {
    u8 field_0;
    u8 field_1;
    Unk_1787ac0_Flags field_2;
    u8 _3;
    s32 field_4;
    s32 field_8;
    u8 _c[0x4];
    void* field_10;
    u8 field_18[0x20];
};
PKMN_OFFSET_ASSERT(Unk_1789940_Pool, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1789940_Pool, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1789940_Pool, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1789940_Pool, field_18, 0x18);

// 0x7101789940
void Unk_1789940(Unk_1789940_Pool* self, const Unk_1791080_Device* device,
                 const Unk_1789770_Info* info, const Unk_1789c10_MemoryPool* memoryPool,
                 s64 offset) {
    self->field_1 = info->field_0;
    self->field_4 = info->field_4;
    if (self->field_1 == 0) {
        self->field_10 = static_cast<u8*>(memoryPool->field_8) + offset;
    } else {
        self->field_10 = self->field_18;
        int reserved = 0;
        int size = 0;
        if (self->field_1 == 1) {
            nvnDeviceGetInteger(device->field_0, 0x11, &reserved);
            nvnDeviceGetInteger(device->field_0, 0x24, &size);
            nvnTexturePoolInitialize(self->field_10, memoryPool->field_0, offset, info->field_4);
        } else {
            nvnDeviceGetInteger(device->field_0, 0x12, &reserved);
            nvnDeviceGetInteger(device->field_0, 0x25, &size);
            nvnSamplerPoolInitialize(self->field_10, memoryPool->field_0, offset, info->field_4);
        }
        self->field_8 = reserved;
    }
    self->field_2.Set(1, false);
    self->field_0 = 1;
}

// A buffer descriptor: its GPU address and size.
struct Unk_1789ae0_Descriptor {
    u64 field_0;
    u64 field_8;
};

// A sampler or texture view: its NVN objects.
struct Unk_1789b30_Object {
    u8 _0[0x8];
    void* field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1789b30_Object, field_8, 0x8);

// 0x7101789b30
void Unk_1789b30(Unk_1789940_Pool* self, int index, const Unk_1789b30_Object* sampler) {
    nvnSamplerPoolRegisterSampler(self->field_10, index, sampler->field_8);
}

// 0x7101789b50
void Unk_1789b50(Unk_1789940_Pool* self, int index, const Unk_1789b30_Object* view) {
    nvnTexturePoolRegisterTexture(self->field_10, index, view->field_8, view->field_10);
}

// 0x7101789b70
void Unk_1789b70(const Unk_1789940_Pool* self, u64* slot, int index) {
    switch (self->field_1) {
    case 1:
    case 2:
        *slot = index;
        break;
    case 0:
        *slot = reinterpret_cast<u64>(static_cast<Unk_1789ae0_Descriptor*>(self->field_10) + index);
        break;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

void Unk_178da60(void* builder, const Unk_178da60_Info* info);

// 0x7101789c10
void Unk_1789c10(Unk_1789c10_MemoryPool* self, const Unk_1791080_Device* device,
                 const Unk_178da60_Info* info) {
    u8 builder[0x40];
    self->field_0 = self->field_10;
    self->field_8 = info->field_8;
    nvnMemoryPoolBuilderSetDevice(builder, device->field_0);
    Unk_178da60(builder, info);
    nvnMemoryPoolInitialize(self->field_0, builder);
    self->field_111.Set(1, false);
    self->field_110 = 1;
}

// 0x7101789ca0
void Unk_1789ca0(Unk_1789c10_MemoryPool* self, Unk_1791080_Device* device) {
    nvnMemoryPoolFinalize(self->field_0);
    self->field_8 = nullptr;
    self->field_110 = 0;
}

// 0x7101789ce0
void* Unk_1789ce0(const Unk_1789c10_MemoryPool* self) {
    return nvnMemoryPoolMap(self->field_0);
}
