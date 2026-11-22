// SiSDK3::SiGfxShaderGraphOperatorNode (RTTI names the class): an operator
// node of the shader graph. The virtual functions are vf<slot>. The
// translation unit's name isn't in the executable (0x71004e0050 is its first
// function).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_NodeType_Operator.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4e03f0.h>

// 0x710276db10: the class, for the reflection
extern void* Unk_276db10;

namespace SiSDK3 {

class SiGfxShaderGraphOperatorNode : public SiGfxShaderGraphNode {
public:
    SiGfxShaderGraphOperatorNode(ISiAllocator* pAllocator, SiGfxShaderGraphOperatorNodeType* pType);  // 0x71004e0050
    virtual ~SiGfxShaderGraphOperatorNode();  // 0x71004e00a0, 0x71004e01e0
    virtual bool vf7();                       // 0x71004e0350
    virtual void vf8();                       // 0x71004e0360
};
PKMN_SIZE_ASSERT(SiGfxShaderGraphOperatorNode, 0x178);

}  // namespace SiSDK3
