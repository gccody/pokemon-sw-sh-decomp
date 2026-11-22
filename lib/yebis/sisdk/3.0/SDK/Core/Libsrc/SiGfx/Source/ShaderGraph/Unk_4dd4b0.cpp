// Scope: common
// SiSDK3::SiGfxShaderGraphDataType (0x71004dd4b0 to 0x71004dd7a0).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

// 0x710276d710
void* Unk_276d710;

namespace SiSDK3 {

// 0x71004dd4b0
SiGfxShaderGraphDataType::SiGfxShaderGraphDataType(ISiAllocator* pAllocator)
    : SiGfxShaderGraphObject(pAllocator), field_b8(pAllocator) {
    field_8 = this;
    field_10 = Unk_276d710;
}

// 0x71004dd540 (D2); the deleting destructor of an abstract class is a trap:
// 0x71004dd6a0. The other bases' thunks: 0x71004dd670, 0x71004dd680,
// 0x71004dd690 and 0x71004dd6b0, 0x71004dd6c0, 0x71004dd6d0
SiGfxShaderGraphDataType::~SiGfxShaderGraphDataType() {
    SiGfxShaderGraphDataType::vf8();
}

// 0x71004dd6e0
bool SiGfxShaderGraphDataType::vf7() {
    return SiGfxShaderGraphObject::vf7();
}

// 0x71004dd6f0
void SiGfxShaderGraphDataType::vf8() {
    Unk_ReleaseItems(&field_b8);
    SiGfxShaderGraphObject::vf8();
}

}  // namespace SiSDK3
