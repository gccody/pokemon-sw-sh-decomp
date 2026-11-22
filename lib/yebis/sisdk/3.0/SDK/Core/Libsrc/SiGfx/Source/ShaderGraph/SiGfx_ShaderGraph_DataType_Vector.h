// SiSDK3::SiGfxShaderGraphDataTypeVector (RTTI names the class): a vector
// type of the shader graph's values. Placeholder members; the virtual
// functions are vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_DataType_Vector.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

// 0x710276da10: the class, for the reflection
extern void* Unk_276da10;

namespace SiSDK3 {

class SiGfxShaderGraphDataTypeVector : public SiGfxShaderGraphDataType {
public:
    // (inline in 0x71004df1c0)
    SiGfxShaderGraphDataTypeVector(ISiAllocator* pAllocator, u32 kind, s32 count)
        : SiGfxShaderGraphDataType(pAllocator), field_108(kind), field_10c(count) {
        field_8 = this;
        field_10 = Unk_276da10;
    }
    virtual ~SiGfxShaderGraphDataTypeVector();  // 0x71004df280, 0x71004df3c0
    virtual bool vf7();                         // 0x71004df530: its name, and a scalar type for each element
    virtual void vf8();                         // 0x71004df900
    virtual u32 vf16();                         // 0x71004df920 (lib/yebis/class): 2
    virtual SiGfxShaderGraphDataValue* vf17();  // 0x71004df910

    // 0x71004df1c0: a new one, or null if it can't be set up
    static SiGfxShaderGraphDataTypeVector* Unk_4df1c0(ISiAllocator* pAllocator, u32 kind, s32 count);

    u32 field_108;  // the elements' scalar type
    s32 field_10c;  // how many elements
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataTypeVector, field_108, 0x108);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataTypeVector, 0x110);

}  // namespace SiSDK3
