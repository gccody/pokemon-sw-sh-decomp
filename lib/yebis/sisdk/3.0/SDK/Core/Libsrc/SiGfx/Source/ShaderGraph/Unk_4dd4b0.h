// SiSDK3::SiGfxShaderGraphDataType (RTTI names the class): a type of the
// shader graph's values, abstract; the scalar, vector and matrix types derive
// from it. Placeholder members; the virtual functions are vf<slot>. The
// translation unit's name isn't in the executable (0x71004dd4b0 is its first
// function).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>

// 0x710276d710: the class, for the reflection
extern void* Unk_276d710;

namespace SiSDK3 {

class SiGfxShaderGraphDataValue;

class SiGfxShaderGraphDataType : public SiGfxShaderGraphObject {
public:
    explicit SiGfxShaderGraphDataType(ISiAllocator* pAllocator);  // 0x71004dd4b0
    virtual ~SiGfxShaderGraphDataType();                          // 0x71004dd540 (the deleting one is a trap)
    virtual bool vf7();                                           // 0x71004dd6e0
    virtual void vf8();                                           // 0x71004dd6f0
    virtual u32 vf16() = 0;                                       // 1: a scalar, 2: a vector, 3: a matrix
    virtual SiGfxShaderGraphDataValue* vf17() = 0;                // a new value of the type

    SiArray<SiGfxShaderGraphDataType*, 16> field_b8;  // the types of its parts
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataType, field_b8, 0xb8);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataType, 0x108);

}  // namespace SiSDK3
