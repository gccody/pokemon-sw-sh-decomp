// Scope: common
// SiSDK3::SiGfxShaderGraphDataTypePOD (0x71004dd0a0 to 0x71004dd430). The
// file's name is the __FILE__ of its allocation. vf16 is lib/yebis/class's,
// vf17 the value's translation unit's (SiGfx_ShaderGraph_DataValue_POD.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_POD.h>

// 0x710276d690
void* Unk_276d690;

namespace SiSDK3 {

// 0x71004dd0a0
SiGfxShaderGraphDataTypePOD* SiGfxShaderGraphDataTypePOD::Unk_4dd0a0(ISiAllocator* pAllocator, u32 kind) {
#line 36
    SiGfxShaderGraphDataTypePOD* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphDataTypePOD(pAllocator, kind);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004dd150 (D2), 0x71004dd290 (D0); the other bases' thunks: 0x71004dd1a0,
// 0x71004dd1f0, 0x71004dd240 and 0x71004dd2e0, 0x71004dd340, 0x71004dd3a0
SiGfxShaderGraphDataTypePOD::~SiGfxShaderGraphDataTypePOD() {
    SiGfxShaderGraphDataTypePOD::vf8();
}

// 0x71004dd400
bool SiGfxShaderGraphDataTypePOD::vf7() {
    return SiGfxShaderGraphDataType::vf7();
}

// 0x71004dd410
void SiGfxShaderGraphDataTypePOD::vf8() {
    SiGfxShaderGraphDataType::vf8();
}

}  // namespace SiSDK3
