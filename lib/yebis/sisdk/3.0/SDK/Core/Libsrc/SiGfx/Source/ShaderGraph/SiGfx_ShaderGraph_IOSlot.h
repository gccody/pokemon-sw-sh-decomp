// SiSDK3::SiGfxShaderGraphIOSlot (RTTI names the class): an input or an
// output of a node, of a slot type, with its value, its parts and its links.
// Placeholder members; the virtual functions are vf<slot>. The header's name
// is its translation unit's (SiGfx_ShaderGraph_IOSlot.cpp, the __FILE__ of
// its allocation).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_IOSlotType.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4ddcf0.h>

// 0x710276dc10: the class, for the reflection
extern void* Unk_276dc10;

namespace SiSDK3 {

// RTTI: SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphConnectionLink*, 16>
class SiGfxShaderGraphConnectionLink;

class SiGfxShaderGraphIOSlot : public SiGfxShaderGraphObject {
public:
    // (inline in 0x71004e0f70; the parts' array has no allocator of its own)
    SiGfxShaderGraphIOSlot(ISiAllocator* pAllocator, SiGfxShaderGraphIOSlotType* pType)
        : SiGfxShaderGraphObject(pAllocator), field_b8(pType), field_c0(nullptr), field_c8(), field_118(pAllocator),
          field_168(nullptr) {
        field_8 = this;
        field_10 = Unk_276dc10;
    }
    virtual ~SiGfxShaderGraphIOSlot();  // 0x71004e1090, 0x71004e1330
    virtual bool vf7();                 // 0x71004e13f0: the type's name and text, its value, a slot for each part
    virtual void vf8();                 // 0x71004e15e0

    // 0x71004e0f70: a new one, or null if it can't be set up
    static SiGfxShaderGraphIOSlot* Unk_4e0f70(ISiAllocator* pAllocator, SiGfxShaderGraphIOSlotType* pType);

    SiGfxShaderGraphIOSlotType* field_b8;                    // its type
    SiGfxShaderGraphDataValue* field_c0;                     // its value
    SiArray<SiGfxShaderGraphIOSlot*, 16> field_c8;           // its parts
    SiArray<SiGfxShaderGraphConnectionLink*, 16> field_118;  // not released with the slot
    void* field_168;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphIOSlot, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphIOSlot, field_118, 0x118);
PKMN_SIZE_ASSERT(SiGfxShaderGraphIOSlot, 0x170);

}  // namespace SiSDK3
