// SiSDK3::SiGfxShaderGraphDataTypeMatrix (RTTI names the class): a matrix
// type of the shader graph's values. Placeholder members; the virtual
// functions are vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_DataType_Matrix.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

// 0x710276d910: the class, for the reflection
extern void* Unk_276d910;

namespace SiSDK3 {

class SiGfxShaderGraphDataTypeMatrix : public SiGfxShaderGraphDataType {
public:
    // (inline in 0x71004de980)
    SiGfxShaderGraphDataTypeMatrix(ISiAllocator* pAllocator, u32 kind, u32 rows, u32 columns)
        : SiGfxShaderGraphDataType(pAllocator), field_108(kind), field_10c(rows), field_110(columns) {
        field_8 = this;
        field_10 = Unk_276d910;
    }
    virtual ~SiGfxShaderGraphDataTypeMatrix();  // 0x71004dea50, 0x71004deb90
    virtual bool vf7();                         // 0x71004ded00
    virtual void vf8();                         // 0x71004ded10
    virtual u32 vf16();                         // 0x71004ded20 (lib/yebis/class): 3
    virtual SiGfxShaderGraphDataValue* vf17();  // 0x71004df080, in the value's translation unit

    // 0x71004de980: a new one, or null if it can't be set up
    static SiGfxShaderGraphDataTypeMatrix* Unk_4de980(ISiAllocator* pAllocator, u32 kind, u32 rows, u32 columns);

    u32 field_108;  // the elements' scalar type
    u32 field_10c;
    u32 field_110;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataTypeMatrix, field_108, 0x108);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataTypeMatrix, 0x118);

}  // namespace SiSDK3
