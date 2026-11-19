// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: buffers. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

static int Unk_1787970_Max(int a, int b) {
    return a < b ? b : a;
}

// 0x7101787970
size_t Unk_1787970(void* device, u32 gpuAccess) {
    int alignment = 8;
    if (gpuAccess & 0x10) {
        int value;
        nvnDeviceGetInteger(static_cast<Unk_1791080_Device*>(device)->field_0, 4, &value);
        alignment = Unk_1787970_Max(alignment, value);
    }
    if (gpuAccess & 0x200) {
        int value;
        nvnDeviceGetInteger(static_cast<Unk_1791080_Device*>(device)->field_0, 0xd, &value);
        alignment = Unk_1787970_Max(alignment, value);
        nvnDeviceGetInteger(static_cast<Unk_1791080_Device*>(device)->field_0, 0x35, &value);
        alignment = Unk_1787970_Max(alignment, value);
    }
    if (gpuAccess & 0x800) {
        int value;
        nvnDeviceGetInteger(static_cast<Unk_1791080_Device*>(device)->field_0, 0xa, &value);
        alignment = Unk_1787970_Max(alignment, value);
    }
    if (gpuAccess & 0x40) {
        alignment = Unk_1787970_Max(alignment, 0x20);
    }
    if (gpuAccess & 0x1a0) {
        alignment = Unk_1787970_Max(alignment, 0x200);
    }
    return alignment;
}

struct Unk_1787ac0_Info {
    u32 field_0;
};

// 0x7101787ac0
void Unk_1787ac0(Unk_1787ac0_Buffer* self, Unk_1791080_Device* device, const Unk_1787ac0_Info* info,
                 Unk_1787ac0_Pool* pool, s64 offset) {
    u8 builder[0x40];
    nvnBufferBuilderSetDefaults(builder);
    nvnBufferBuilderSetDevice(builder, device->field_0);
    nvnBufferBuilderSetStorage(builder, pool->field_0, offset, info->field_0);
    self->field_8 = self->field_10;
    nvnBufferInitialize(self->field_8, builder);
    int flags = nvnMemoryPoolGetFlags(pool->field_0);
    self->field_1.Set(2, (flags & 4) != 0);
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// 0x7101787bb0
void Unk_1787bb0(Unk_1787ac0_Buffer* self, Unk_1791080_Device* device) {
    nvnBufferFinalize(self->field_8);
    self->field_8 = nullptr;
    self->field_0 = 0;
}

// 0x7101787c20
void Unk_1787c20(const Unk_1787ac0_Buffer* self, s64 offset, size_t size) {
    if (self->field_1.Test(2)) {
        nvnBufferFlushMappedRange(self->field_8, offset, size);
    }
}

// 0x7101787c40
void Unk_1787c40(const Unk_1787ac0_Buffer* self, s64 offset, size_t size) {
    if (self->field_1.Test(2)) {
        nvnBufferInvalidateMappedRange(self->field_8, offset, size);
    }
}

// 0x7101787cb0
s64 Unk_17911c0(s64 size);

s64 Unk_1787cb0(const void* begin, const void* end) {
    return Unk_17911c0(static_cast<const u8*>(end) - static_cast<const u8*>(begin));
}

// 0x7101787cc0
s64 Unk_1787cc0(const Unk_1791080_Device* device) {
    int value;
    nvnDeviceGetInteger(device->field_0, 0x13, &value);
    return value;
}

// 0x7101787d00
s64 Unk_1787d00(const Unk_1791080_Device* device) {
    int value;
    nvnDeviceGetInteger(device->field_0, 0x14, &value);
    return value;
}
