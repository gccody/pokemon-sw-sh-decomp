// Scope: common
// SiSDK3::SiGfxShaderGraphOperatorNode (0x71004e0050 to 0x71004e0370).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4e0050.h>

// 0x710276db10
void* Unk_276db10;

namespace SiSDK3 {

// 0x71004e0050
SiGfxShaderGraphOperatorNode::SiGfxShaderGraphOperatorNode(ISiAllocator* pAllocator,
                                                           SiGfxShaderGraphOperatorNodeType* pType)
    : SiGfxShaderGraphNode(pAllocator, pType) {
    field_8 = this;
    field_10 = Unk_276db10;
}

// 0x71004e00a0 (D2), 0x71004e01e0 (D0); the other bases' thunks: 0x71004e00f0,
// 0x71004e0140, 0x71004e0190 and 0x71004e0230, 0x71004e0290, 0x71004e02f0
SiGfxShaderGraphOperatorNode::~SiGfxShaderGraphOperatorNode() {
    SiGfxShaderGraphOperatorNode::vf8();
}

// 0x71004e0350
bool SiGfxShaderGraphOperatorNode::vf7() {
    return SiGfxShaderGraphNode::vf7();
}

// 0x71004e0360
void SiGfxShaderGraphOperatorNode::vf8() {
    SiGfxShaderGraphNode::vf8();
}

}  // namespace SiSDK3
