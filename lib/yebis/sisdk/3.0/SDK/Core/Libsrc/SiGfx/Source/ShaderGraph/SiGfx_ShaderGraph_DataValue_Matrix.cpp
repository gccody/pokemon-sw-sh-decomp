// Scope: common
// SiSDK3::SiGfxShaderGraphDataValueMatrix (0x71004dedb0 to 0x71004df140), and
// the function of its type that makes one (the only place one is made: the
// scalar and the vector values have a function for it that others call too).
// The file's name is the __FILE__ of its allocation.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataValue_Matrix.h>

// 0x710276d990
void* Unk_276d990;

namespace SiSDK3 {

// 0x71004dedb0 (D2), 0x71004deef0 (D0); the other bases' thunks: 0x71004dee00,
// 0x71004dee50, 0x71004deea0 and 0x71004def40, 0x71004defa0, 0x71004df000
SiGfxShaderGraphDataValueMatrix::~SiGfxShaderGraphDataValueMatrix() {
    SiGfxShaderGraphDataValueMatrix::vf8();
}

// 0x71004df060
bool SiGfxShaderGraphDataValueMatrix::vf7() {
    return SiGfxShaderGraphDataValue::vf7();
}

// 0x71004df070
void SiGfxShaderGraphDataValueMatrix::vf8() {
    SiGfxShaderGraphDataValue::vf8();
}

// 0x71004df080
SiGfxShaderGraphDataValue* SiGfxShaderGraphDataTypeMatrix::vf17() {
    ISiAllocator* pAllocator = Unk_Allocator();
    SiGfxShaderGraphDataValueMatrix* p;
#line 37
    p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphDataValueMatrix(pAllocator, this);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

}  // namespace SiSDK3
