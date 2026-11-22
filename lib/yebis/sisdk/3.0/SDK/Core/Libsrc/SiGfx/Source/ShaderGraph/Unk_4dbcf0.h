// SiSDK3::SiGfxShaderGraphNodeType (RTTI names the class): a type of the
// shader graph's nodes, abstract, with the types of its inputs and outputs.
// Placeholder members; the virtual functions are vf<slot>. The translation
// unit's name isn't in the executable (0x71004dbcf0 is its first function).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_IOSlotType.h>

// 0x710276d510: the class, for the reflection
extern void* Unk_276d510;

namespace SiSDK3 {

class SiGfxShaderGraphNode;

class SiGfxShaderGraphNodeType : public SiGfxShaderGraphObject {
public:
    explicit SiGfxShaderGraphNodeType(ISiAllocator* pAllocator);  // 0x71004dbcf0
    virtual ~SiGfxShaderGraphNodeType();                          // 0x71004dbdb0 (the deleting one is a trap)
    virtual bool vf7();                                           // 0x71004dc0a0
    virtual void vf8();                                           // 0x71004dc0b0
    virtual SiGfxShaderGraphNode* vf16() = 0;                     // a new node of the type
    virtual u32 vf17() = 0;                                       // 3: an operator

    bool Unk_4dc1e0(SiGfxShaderGraphIOSlotType* pSlotType);  // 0x71004dc1e0: one more input
    bool Unk_4dc290(SiGfxShaderGraphIOSlotType* pSlotType);  // 0x71004dc290: one more output

    u32 field_b8;
    SiArray<SiGfxShaderGraphIOSlotType*, 16> field_c0;   // the inputs
    SiArray<SiGfxShaderGraphIOSlotType*, 16> field_110;  // the outputs
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphNodeType, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphNodeType, field_110, 0x110);
PKMN_SIZE_ASSERT(SiGfxShaderGraphNodeType, 0x160);

}  // namespace SiSDK3
