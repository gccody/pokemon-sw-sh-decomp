// SiSDK3::SiGfxShaderGraphDataTypePOD (RTTI names the class): a scalar type
// of the shader graph's values. Placeholder members; the virtual functions are
// vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_DataType_POD.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

// 0x710276d690: the class, for the reflection
extern void* Unk_276d690;

namespace SiSDK3 {

class SiGfxShaderGraphDataTypePOD : public SiGfxShaderGraphDataType {
public:
    // (inline in 0x71004dd0a0)
    SiGfxShaderGraphDataTypePOD(ISiAllocator* pAllocator, u32 kind)
        : SiGfxShaderGraphDataType(pAllocator), field_108(kind) {
        field_8 = this;
        field_10 = Unk_276d690;
    }
    virtual ~SiGfxShaderGraphDataTypePOD();     // 0x71004dd150, 0x71004dd290
    virtual bool vf7();                         // 0x71004dd400
    virtual void vf8();                         // 0x71004dd410
    virtual u32 vf16();                         // 0x71004dd420 (lib/yebis/class): 1
    virtual SiGfxShaderGraphDataValue* vf17();  // 0x71004ddbb0, in the value's translation unit

    // 0x71004dd0a0: a new one, or null if it can't be set up
    static SiGfxShaderGraphDataTypePOD* Unk_4dd0a0(ISiAllocator* pAllocator, u32 kind);

    u32 field_108;  // which scalar: 0 "bool", 1 "int", 2 "float" (the utility's three)
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataTypePOD, field_108, 0x108);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataTypePOD, 0x110);

}  // namespace SiSDK3
