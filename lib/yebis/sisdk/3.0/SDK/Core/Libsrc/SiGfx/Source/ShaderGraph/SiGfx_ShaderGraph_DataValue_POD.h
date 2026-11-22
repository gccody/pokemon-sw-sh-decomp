// SiSDK3::SiGfxShaderGraphDataValuePOD (RTTI names the class): a scalar value
// of the shader graph. Placeholder members; the virtual functions are
// vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_DataValue_POD.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_POD.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4ddcf0.h>

// 0x710276d790: the class, for the reflection
extern void* Unk_276d790;

namespace SiSDK3 {

class SiGfxShaderGraphDataValuePOD : public SiGfxShaderGraphDataValue {
public:
    // (inline in 0x71004dd820 and 0x71004ddbb0)
    SiGfxShaderGraphDataValuePOD(ISiAllocator* pAllocator, SiGfxShaderGraphDataTypePOD* pType)
        : SiGfxShaderGraphDataValue(pAllocator, pType), field_118(pType) {
        field_8 = this;
        field_10 = Unk_276d790;
    }
    virtual ~SiGfxShaderGraphDataValuePOD();  // 0x71004dd8e0, 0x71004dda20
    virtual bool vf7();                       // 0x71004ddb90
    virtual void vf8();                       // 0x71004ddba0

    // 0x71004dd820: a new one, or null if it can't be set up
    static SiGfxShaderGraphDataValuePOD* Unk_4dd820(ISiAllocator* pAllocator, SiGfxShaderGraphDataTypePOD* pType);

    SiGfxShaderGraphDataTypePOD* field_118;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataValuePOD, field_118, 0x118);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataValuePOD, 0x120);

}  // namespace SiSDK3
