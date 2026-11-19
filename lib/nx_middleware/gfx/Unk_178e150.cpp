// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: shaders. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// A shader stage's program data: its scratch memory sizes.
struct Unk_178e150_Stage {
    u8 _0[0x28];
    u32 field_28;
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_178e150_Stage, field_28, 0x28);

// A shader: its six stages.
struct Unk_178e150_Shader {
    u8 _0[0x8];
    const Unk_178e150_Stage* field_8[6];
};
PKMN_OFFSET_ASSERT(Unk_178e150_Shader, field_8, 0x8);

static inline u32 Unk_178e150_Max(u32 a, u32 b) {
    return a < b ? b : a;
}

// 0x710178e150: the scratch memory the shader needs, aligned for the device.
size_t Unk_178e150(const Unk_178e150_Shader* self, const Unk_1791080_Device* device) {
    u32 sizePerWarp = 0;
    u32 size = 0;
    for (int i = 0; i < 6; ++i) {
        const Unk_178e150_Stage* stage = self->field_8[i];
        if (stage != nullptr) {
            size = Unk_178e150_Max(size, stage->field_28);
            sizePerWarp = Unk_178e150_Max(sizePerWarp, stage->field_2c);
        }
    }
    if (size == 0) {
        if (sizePerWarp == 0) {
            return 0;
        }
        int warps;
        nvnDeviceGetInteger(device->field_0, 0x18, &warps);
        size = warps * sizePerWarp;
    }
    int alignment;
    nvnDeviceGetInteger(device->field_0, 0x1a, &alignment);
    return (size + alignment - 1) / alignment * alignment;
}

struct Unk_1789c10_MemoryPool;
void Unk_1789ca0(Unk_1789c10_MemoryPool* self, Unk_1791080_Device* device);

// What a shader keeps of its code's memory pool.
struct Unk_178e450_Code {
    u8 _0[0x20];
    Unk_1789c10_MemoryPool* field_20;
    u8 _28[0x8];
    Unk_1789c10_MemoryPool* field_30;
};
PKMN_OFFSET_ASSERT(Unk_178e450_Code, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_178e450_Code, field_30, 0x30);

struct Unk_178e450_Shader {
    u8 _0[0x28];
    Unk_178e450_Code* field_28;
};
PKMN_OFFSET_ASSERT(Unk_178e450_Shader, field_28, 0x28);

// 0x710178e450
void Unk_178e450(const Unk_178e450_Shader* self, Unk_1791080_Device* device) {
    Unk_178e450_Code* code = self->field_28;
    if (code->field_30 == code->field_20) {
        Unk_1789ca0(code->field_30, device);
    }
    code->field_30 = nullptr;
}
