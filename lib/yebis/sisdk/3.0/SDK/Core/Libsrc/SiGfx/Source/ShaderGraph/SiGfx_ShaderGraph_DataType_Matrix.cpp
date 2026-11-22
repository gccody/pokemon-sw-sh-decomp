// Scope: common
// SiSDK3::SiGfxShaderGraphDataTypeMatrix (0x71004de980 to 0x71004ded30). The
// file's name is the __FILE__ of its allocation. vf16 is lib/yebis/class's,
// vf17 the value's translation unit's (SiGfx_ShaderGraph_DataValue_Matrix.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_Matrix.h>

// 0x710276d910
void* Unk_276d910;

namespace SiSDK3 {

// 0x71004de980
SiGfxShaderGraphDataTypeMatrix* SiGfxShaderGraphDataTypeMatrix::Unk_4de980(ISiAllocator* pAllocator, u32 kind,
                                                                           u32 rows, u32 columns) {
    SiGfxShaderGraphDataTypeMatrix* p;
#line 40
    p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphDataTypeMatrix(pAllocator, kind, rows, columns);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004dea50 (D2), 0x71004deb90 (D0); the other bases' thunks: 0x71004deaa0,
// 0x71004deaf0, 0x71004deb40 and 0x71004debe0, 0x71004dec40, 0x71004deca0
SiGfxShaderGraphDataTypeMatrix::~SiGfxShaderGraphDataTypeMatrix() {
    SiGfxShaderGraphDataTypeMatrix::vf8();
}

// 0x71004ded00
bool SiGfxShaderGraphDataTypeMatrix::vf7() {
    return SiGfxShaderGraphDataType::vf7();
}

// 0x71004ded10
void SiGfxShaderGraphDataTypeMatrix::vf8() {
    SiGfxShaderGraphDataType::vf8();
}

}  // namespace SiSDK3
