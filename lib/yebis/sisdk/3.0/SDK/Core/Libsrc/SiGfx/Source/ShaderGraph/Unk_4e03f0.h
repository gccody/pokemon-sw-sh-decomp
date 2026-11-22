// SiSDK3::SiGfxShaderGraphNode (RTTI names the class): a node of the shader
// graph, of a node type, with a slot for each of the type's inputs and
// outputs. Placeholder members; the virtual functions are vf<slot>. The
// translation unit's name isn't in the executable (0x71004e03f0 is its first
// function).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_IOSlot.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dbcf0.h>

// 0x710276db90: the class, for the reflection
extern void* Unk_276db90;

namespace SiSDK3 {

class SiGfxShaderGraphNode : public SiGfxShaderGraphObject {
public:
    SiGfxShaderGraphNode(ISiAllocator* pAllocator, SiGfxShaderGraphNodeType* pType);  // 0x71004e03f0
    virtual ~SiGfxShaderGraphNode();                                                // 0x71004e04d0, 0x71004e07a0
    virtual bool vf7();   // 0x71004e0860: the type's name and text, and the slots
    virtual void vf8();   // 0x71004e0920
    virtual bool vf16();  // 0x71004e0a70: a slot for each of the type's inputs
    virtual bool vf17();  // 0x71004e0bb0: a slot for each of its outputs

    SiGfxShaderGraphNodeType* field_b8;              // its type
    SiArray<SiGfxShaderGraphIOSlot*, 16> field_c0;   // the inputs
    SiArray<SiGfxShaderGraphIOSlot*, 16> field_110;  // the outputs
    bool field_160;
    f32 field_164[4];
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphNode, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphNode, field_110, 0x110);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphNode, field_164, 0x164);
PKMN_SIZE_ASSERT(SiGfxShaderGraphNode, 0x178);

}  // namespace SiSDK3
