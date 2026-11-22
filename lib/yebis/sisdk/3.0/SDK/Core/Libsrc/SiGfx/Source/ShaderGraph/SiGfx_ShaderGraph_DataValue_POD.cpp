// Scope: common
// SiSDK3::SiGfxShaderGraphDataValuePOD (0x71004dd820 to 0x71004ddc70), and the
// function of its type that makes one. The file's name is the __FILE__ of its
// allocation.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataValue_POD.h>

// 0x710276d790
void* Unk_276d790;

namespace SiSDK3 {

// 0x71004dd820
SiGfxShaderGraphDataValuePOD* SiGfxShaderGraphDataValuePOD::Unk_4dd820(ISiAllocator* pAllocator,
                                                                       SiGfxShaderGraphDataTypePOD* pType) {
#line 36
    SiGfxShaderGraphDataValuePOD* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphDataValuePOD(pAllocator, pType);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004dd8e0 (D2), 0x71004dda20 (D0); the other bases' thunks: 0x71004dd930,
// 0x71004dd980, 0x71004dd9d0 and 0x71004dda70, 0x71004ddad0, 0x71004ddb30
SiGfxShaderGraphDataValuePOD::~SiGfxShaderGraphDataValuePOD() {
    SiGfxShaderGraphDataValuePOD::vf8();
}

// 0x71004ddb90
bool SiGfxShaderGraphDataValuePOD::vf7() {
    return SiGfxShaderGraphDataValue::vf7();
}

// 0x71004ddba0
void SiGfxShaderGraphDataValuePOD::vf8() {
    SiGfxShaderGraphDataValue::vf8();
}

// 0x71004ddbb0
SiGfxShaderGraphDataValue* SiGfxShaderGraphDataTypePOD::vf17() {
    return SiGfxShaderGraphDataValuePOD::Unk_4dd820(Unk_Allocator(), this);
}

}  // namespace SiSDK3
