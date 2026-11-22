// Scope: common
// SiSDK3::SiGfxShaderGraphOperatorNodeType (0x71004df9b0 to 0x71004dffd0). The
// file's name is the __FILE__ of its allocations. vf17 is lib/yebis/class's.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_NodeType_Operator.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4e0050.h>

// 0x710276da90
void* Unk_276da90;

namespace SiSDK3 {

// 0x71004df9b0
SiGfxShaderGraphOperatorNodeType* SiGfxShaderGraphOperatorNodeType::Unk_4df9b0(ISiAllocator* pAllocator) {
    SiGfxShaderGraphOperatorNodeType* p;
#line 34
    p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphOperatorNodeType(pAllocator);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004dfab0 (D2), 0x71004dfce0 (D0); the other bases' thunks: 0x71004dfb30,
// 0x71004dfbc0, 0x71004dfc50 and 0x71004dfd70, 0x71004dfe00, 0x71004dfe90
SiGfxShaderGraphOperatorNodeType::~SiGfxShaderGraphOperatorNodeType() {
    SiGfxShaderGraphOperatorNodeType::vf8();
}

// 0x71004dff20 (the object's, not the node type's)
bool SiGfxShaderGraphOperatorNodeType::vf7() {
    return SiGfxShaderGraphObject::vf7();
}

// 0x71004dff30 (the object's, not the node type's)
void SiGfxShaderGraphOperatorNodeType::vf8() {
    SiGfxShaderGraphObject::vf8();
}

// 0x71004dff40
SiGfxShaderGraphNode* SiGfxShaderGraphOperatorNodeType::vf16() {
    SiGfxShaderGraphOperatorNode* p;
#line 100
    p = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxShaderGraphOperatorNode(Unk_Allocator(), this);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

}  // namespace SiSDK3
