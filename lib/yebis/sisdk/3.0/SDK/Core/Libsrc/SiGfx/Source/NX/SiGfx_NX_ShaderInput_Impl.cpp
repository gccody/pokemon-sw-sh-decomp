// Scope: common
// SiSDK3::SiGfxNXShaderInput: its construction and destruction, its entries,
// and the reference counts its header defines. (Its small accessors are
// lib/yebis/class's.)
#define UNK_SIGFX_NX_SHADERINPUT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_ShaderInput_Impl.h>

namespace SiSDK3 {

// 0x710055abb0
SiGfxNXShaderInput::SiGfxNXShaderInput(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_224(0), field_228(0), field_22c(0), field_230(0) {}

// 0x710055ac00 (D2), 0x710055ac20 (D0)
SiGfxNXShaderInput::~SiGfxNXShaderInput() {
    field_18 = nullptr;
}

// 0x710055ac60
bool SiGfxNXShaderInput::Unk_55ac60(const void* program) {
    return program != nullptr;
}

// 0x710055ac90
const SiGfxNXShaderInput::Unk_Entry* SiGfxNXShaderInput::vf7(s32 index) {
    if (static_cast<u32>(index) >= 32) {
        return &field_24[0];
    }
    return &field_24[index];
}

}  // namespace SiSDK3
