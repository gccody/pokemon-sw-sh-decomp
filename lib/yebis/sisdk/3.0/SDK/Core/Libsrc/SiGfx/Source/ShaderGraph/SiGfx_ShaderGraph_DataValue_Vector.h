// SiSDK3::SiGfxShaderGraphDataValueVector (RTTI names the class): a vector
// value of the shader graph. Placeholder members; the virtual functions are
// vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_DataValue_Vector.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_Vector.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4ddcf0.h>

// 0x710276d890: the class, for the reflection
extern void* Unk_276d890;

namespace SiSDK3 {

class SiGfxShaderGraphDataValueVector : public SiGfxShaderGraphDataValue {
public:
    // (inline in 0x71004de570)
    SiGfxShaderGraphDataValueVector(ISiAllocator* pAllocator, SiGfxShaderGraphDataTypeVector* pType)
        : SiGfxShaderGraphDataValue(pAllocator, pType), field_118(pType) {
        field_8 = this;
        field_10 = Unk_276d890;
    }
    virtual ~SiGfxShaderGraphDataValueVector();  // 0x71004de630, 0x71004de770
    virtual bool vf7();                          // 0x71004de8e0
    virtual void vf8();                          // 0x71004de8f0

    // 0x71004de570: a new one, or null if it can't be set up
    static SiGfxShaderGraphDataValueVector* Unk_4de570(ISiAllocator* pAllocator,
                                                       SiGfxShaderGraphDataTypeVector* pType);

    SiGfxShaderGraphDataTypeVector* field_118;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataValueVector, field_118, 0x118);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataValueVector, 0x120);

}  // namespace SiSDK3
