// SiSDK3::SiGfxShaderGraphIOSlotType (RTTI names the class): what an input or
// an output of a node type is. Placeholder members; the virtual functions are
// vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_IOSlotType.cpp, the __FILE__ of its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

// 0x710276d610: the class, for the reflection
extern void* Unk_276d610;

namespace SiSDK3 {

class SiGfxShaderGraphIOSlotType : public SiGfxShaderGraphObject {
public:
    // (inline in 0x71004dcbf0)
    SiGfxShaderGraphIOSlotType(ISiAllocator* pAllocator, u32 direction)
        : SiGfxShaderGraphObject(pAllocator), field_b8(direction), field_bc(false), field_bd(false), field_be(false),
          field_c0(nullptr), field_c8(pAllocator) {
        field_8 = this;
        field_10 = Unk_276d610;
    }
    virtual ~SiGfxShaderGraphIOSlotType();  // 0x71004dcd10, 0x71004dce80
    virtual bool vf7();                     // 0x71004dcf40
    virtual void vf8();                     // 0x71004dcf50

    // 0x71004dcbf0: a new one, or null if it can't be set up
    static SiGfxShaderGraphIOSlotType* Unk_4dcbf0(ISiAllocator* pAllocator, u32 direction);

    u32 field_b8;  // 1: an input, 2: an output (the node type's two arrays)
    bool field_bc;
    bool field_bd;
    bool field_be;
    SiGfxShaderGraphDataType* field_c0;                 // the type of its value (a slot makes one)
    SiArray<SiGfxShaderGraphIOSlotType*, 16> field_c8;  // its parts (a slot makes one of each)
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphIOSlotType, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphIOSlotType, field_c8, 0xc8);
PKMN_SIZE_ASSERT(SiGfxShaderGraphIOSlotType, 0x118);

}  // namespace SiSDK3
