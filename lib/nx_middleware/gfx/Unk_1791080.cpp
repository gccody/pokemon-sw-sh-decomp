// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: the device. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// The NVN bootstrap loader, an import of `main`.
extern "C" NvnProc nvnBootstrapLoader(const char* name);

using Unk_1789d10_GetProc = NvnProc (*)(void* device, const char* name);
void Unk_1789d10(void* device, Unk_1789d10_GetProc getProc);
void Unk_1787740();
void Unk_178d530(int major, int minor);
u32 Unk_178d780(void* device);

// 0x7101791080
void Unk_1791080(Unk_1791080_Device* self) {
    Unk_1787740();
    Unk_1789d10_GetProc getProc =
        reinterpret_cast<Unk_1789d10_GetProc>(nvnBootstrapLoader("nvnDeviceGetProcAddress"));
    Unk_1789d10(nullptr, getProc);
    Unk_178d530(0x35, 0x137);
    u8 builder[0x40];
    nvnDeviceBuilderSetDefaults(builder);
    nvnDeviceBuilderSetFlags(builder, 0);
    self->field_0 = self->field_8;
    nvnDeviceInitialize(self->field_0, builder);
    Unk_1789d10(self->field_0, getProc);
    self->field_300c = Unk_178d780(self->field_0);
    self->field_3009.Set(1, false);
    self->field_3008 = 1;
}

// 0x7101791150
void Unk_1791150(Unk_1791080_Device* self) {
    nvnDeviceFinalize(self->field_0);
    self->field_0 = nullptr;
    self->field_3008 = 0;
}

// 0x71017911c0: GPU timestamp ticks to nanoseconds.
s64 Unk_17911c0(s64 ticks) {
    return ticks * 625 / 384;
}

// 0x7101791360
void Unk_1791360(const Unk_1787ac0_Pool* self, const char* label) {
    nvnMemoryPoolSetDebugLabel(self->field_0, label);
}

// 0x7101791380
void Unk_1791380(const Unk_1787ac0_Buffer* self, const char* label) {
    nvnBufferSetDebugLabel(self->field_8, label);
}

// A sampler: its NVN sampler at field_8.
struct Unk_17913a0_Sampler {
    u8 _0[0x8];
    void* field_8;
};

// 0x71017913a0
void Unk_17913a0(const Unk_17913a0_Sampler* self, const char* label) {
    nvnSamplerSetDebugLabel(self->field_8, label);
}
