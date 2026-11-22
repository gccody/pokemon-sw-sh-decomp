// SiSDK3::SiGfxShaderGraphDataValue (RTTI names the class): a value of the
// shader graph, of a data type; the scalar, vector and matrix values derive
// from it. Placeholder members; the virtual functions are vf<slot>. The
// translation unit's name isn't in the executable (0x71004ddcf0 is its first
// function).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

// 0x710276d810: the class, for the reflection
extern void* Unk_276d810;

namespace SiSDK3 {

class SiGfxShaderGraphDataValue : public SiGfxShaderGraphObject {
public:
    SiGfxShaderGraphDataValue(ISiAllocator* pAllocator, SiGfxShaderGraphDataType* pType);  // 0x71004ddcf0
    virtual ~SiGfxShaderGraphDataValue();                                                 // 0x71004ddd90, 0x71004ddf70
    virtual bool vf7();  // 0x71004de030: the type's name and text, and a value for each of its parts
    virtual void vf8();  // 0x71004de240

    u32 field_b8;
    SiGfxShaderGraphDataType* field_c0;                 // its type
    SiArray<SiGfxShaderGraphDataValue*, 16> field_c8;  // its parts
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataValue, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphDataValue, field_c8, 0xc8);
PKMN_SIZE_ASSERT(SiGfxShaderGraphDataValue, 0x118);

}  // namespace SiSDK3
