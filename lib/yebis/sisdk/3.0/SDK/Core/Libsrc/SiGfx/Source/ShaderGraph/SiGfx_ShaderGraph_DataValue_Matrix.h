// SiSDK3::SiGfxShaderGraphDataValueMatrix (RTTI names the class): a matrix
// value of the shader graph. Placeholder members; the virtual functions are
// vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_DataValue_Matrix.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_Matrix.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4ddcf0.h>

// 0x710276d990: the class, for the reflection
extern void* Unk_276d990;

namespace SiSDK3 {

class SiGfxShaderGraphDataValueMatrix : public SiGfxShaderGraphDataValue {
public:
    // (inline in 0x71004df080)
    SiGfxShaderGraphDataValueMatrix(ISiAllocator* pAllocator, SiGfxShaderGraphDataTypeMatrix* pType)
        : SiGfxShaderGraphDataValue(pAllocator, pType), field_118(pType) {
        field_8 = this;
        field_10 = Unk_276d990;
    }
    virtual ~SiGfxShaderGraphDataValueMatrix();  // 0x71004dedb0, 0x71004deef0
    virtual bool vf7();                          // 0x71004df060
    virtual void vf8();                          // 0x71004df070

    SiGfxShaderGraphDataTypeMatrix* field_118;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataValueMatrix, field_118, 0x118);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataValueMatrix, 0x120);

}  // namespace SiSDK3
