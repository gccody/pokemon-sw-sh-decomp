// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: shader stages and samplers. Placeholder
// names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// A shader's program data, one per stage.
struct Unk_178e4a0_Shader {
    u8 _0[0x8];
    void* field_8;
    void* field_10;
    void* field_18;
    void* field_20;
    void* field_28;
    void* field_30;
};
PKMN_OFFSET_ASSERT(Unk_178e4a0_Shader, field_30, 0x30);

// The stages' members.
static void* Unk_178e4a0_Shader::*const Unk_1f48ea0[] = {
    &Unk_178e4a0_Shader::field_8,  &Unk_178e4a0_Shader::field_10, &Unk_178e4a0_Shader::field_18,
    &Unk_178e4a0_Shader::field_20, &Unk_178e4a0_Shader::field_28, &Unk_178e4a0_Shader::field_30,
};

// 0x710178e4a0
void* Unk_178e4a0(const Unk_178e4a0_Shader* self, u32 stage) {
    return self->*Unk_1f48ea0[stage];
}

// A sampler: a state, flags and its NVN sampler (in field_10).
struct Unk_178e500_Sampler {
    u8 field_0;
    Unk_1787ac0_Flags field_1;
    u8 _2[0x6];
    void* field_8;
    u8 field_10[0x60];
};
PKMN_OFFSET_ASSERT(Unk_178e500_Sampler, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_178e500_Sampler, field_10, 0x10);

struct Unk_178dd30_Info;
void Unk_178dd30(void* builder, const Unk_178dd30_Info& info);

// 0x710178e500
void Unk_178e500(Unk_178e500_Sampler* self, const Unk_1791080_Device* device,
                 const Unk_178dd30_Info& info) {
    u8 builder[0x60];
    nvnSamplerBuilderSetDevice(builder, device->field_0);
    Unk_178dd30(builder, info);
    if (!(device->field_300c & 1)) {
        nvnSamplerBuilderSetReductionFilter(builder, 0);
    }
    self->field_8 = self->field_10;
    nvnSamplerInitialize(self->field_8, builder);
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// 0x710178e5b0
void Unk_178e5b0(Unk_178e500_Sampler* self, const Unk_1791080_Device* device) {
    nvnSamplerFinalize(self->field_8);
    self->field_8 = nullptr;
    self->field_0 = 0;
}
