// SiSDK3::SiGfxShaderGraphOperatorNodeType (RTTI names the class): the type
// of an operator node. Placeholder members; the virtual functions are
// vf<slot>. The header's name is its translation unit's
// (SiGfx_ShaderGraph_NodeType_Operator.cpp, the __FILE__ of its allocations).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dbcf0.h>

// 0x710276da90: the class, for the reflection
extern void* Unk_276da90;

namespace SiSDK3 {

class SiGfxShaderGraphOperatorNodeType : public SiGfxShaderGraphNodeType {
public:
    // (inline in 0x71004df9b0)
    explicit SiGfxShaderGraphOperatorNodeType(ISiAllocator* pAllocator)
        : SiGfxShaderGraphNodeType(pAllocator), field_160(pAllocator) {
        field_8 = this;
        field_10 = Unk_276da90;
    }
    virtual ~SiGfxShaderGraphOperatorNodeType();  // 0x71004dfab0, 0x71004dfce0
    virtual bool vf7();                           // 0x71004dff20
    virtual void vf8();                           // 0x71004dff30
    virtual SiGfxShaderGraphNode* vf16();         // 0x71004dff40: a new operator node
    virtual u32 vf17();                           // 0x71004dffc0 (lib/yebis/class): 3

    // 0x71004df9b0: a new one, or null if it can't be set up
    static SiGfxShaderGraphOperatorNodeType* Unk_4df9b0(ISiAllocator* pAllocator);

    SiString<char> field_160;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphOperatorNodeType, field_160, 0x160);
PKMN_SIZE_ASSERT(SiGfxShaderGraphOperatorNodeType, 0x190);

}  // namespace SiSDK3
