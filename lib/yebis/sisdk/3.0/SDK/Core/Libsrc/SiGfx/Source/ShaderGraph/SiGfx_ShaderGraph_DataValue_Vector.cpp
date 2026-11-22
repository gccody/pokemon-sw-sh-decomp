// Scope: common
// SiSDK3::SiGfxShaderGraphDataValueVector (0x71004de570 to 0x71004de900). The
// file's name is the __FILE__ of its allocation.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataValue_Vector.h>

// 0x710276d890
void* Unk_276d890;

namespace SiSDK3 {

// 0x71004de570
SiGfxShaderGraphDataValueVector* SiGfxShaderGraphDataValueVector::Unk_4de570(ISiAllocator* pAllocator,
                                                                             SiGfxShaderGraphDataTypeVector* pType) {
    SiGfxShaderGraphDataValueVector* p;
#line 36
    p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphDataValueVector(pAllocator, pType);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004de630 (D2), 0x71004de770 (D0); the other bases' thunks: 0x71004de680,
// 0x71004de6d0, 0x71004de720 and 0x71004de7c0, 0x71004de820, 0x71004de880
SiGfxShaderGraphDataValueVector::~SiGfxShaderGraphDataValueVector() {
    SiGfxShaderGraphDataValueVector::vf8();
}

// 0x71004de8e0
bool SiGfxShaderGraphDataValueVector::vf7() {
    return SiGfxShaderGraphDataValue::vf7();
}

// 0x71004de8f0
void SiGfxShaderGraphDataValueVector::vf8() {
    SiGfxShaderGraphDataValue::vf8();
}

}  // namespace SiSDK3
