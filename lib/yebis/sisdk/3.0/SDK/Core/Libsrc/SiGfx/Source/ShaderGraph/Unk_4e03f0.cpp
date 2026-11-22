// Scope: common
// SiSDK3::SiGfxShaderGraphNode (0x71004e03f0 to 0x71004e0ef0).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4e03f0.h>

// 0x710276db90
void* Unk_276db90;

namespace SiSDK3 {

// 0x71004e03f0
SiGfxShaderGraphNode::SiGfxShaderGraphNode(ISiAllocator* pAllocator, SiGfxShaderGraphNodeType* pType)
    : SiGfxShaderGraphObject(pAllocator), field_b8(pType), field_c0(pAllocator), field_110(pAllocator),
      field_160(true), field_164() {
    field_8 = this;
    field_10 = Unk_276db90;
    field_b8->vf2();
}

// 0x71004e04d0 (D2), 0x71004e07a0 (D0); the other bases' thunks: 0x71004e0770,
// 0x71004e0780, 0x71004e0790 and 0x71004e07d0, 0x71004e0800, 0x71004e0830
// (vf8's statements, not a call of it: with two arrays vf8 is too large to be
// inlined, and the original has its code here)
SiGfxShaderGraphNode::~SiGfxShaderGraphNode() {
    Unk_ReleaseItems(&field_c0);
    Unk_ReleaseItems(&field_110);
    if (field_b8 != nullptr) {
        field_b8->vf3();
        field_b8 = nullptr;
    }
    SiGfxShaderGraphObject::vf8();
}

// 0x71004e0860
bool SiGfxShaderGraphNode::vf7() {
    if (!SiGfxShaderGraphObject::vf7()) {
        return false;
    }
    vf18(Unk_StringCStr(field_b8->vf19()));
    vf12(Unk_StringCStr(field_b8->vf13()));
    if (!vf16()) {
        return false;
    }
    return vf17();
}

// 0x71004e0920
void SiGfxShaderGraphNode::vf8() {
    Unk_ReleaseItems(&field_c0);
    Unk_ReleaseItems(&field_110);
    if (field_b8 != nullptr) {
        field_b8->vf3();
        field_b8 = nullptr;
    }
    SiGfxShaderGraphObject::vf8();
}

// 0x71004e0a70
bool SiGfxShaderGraphNode::vf16() {
    s32 count = static_cast<s32>(field_b8->field_c0.m_itemCount);
    field_c0.Unk_ReserveAtLeast(count);
    for (s32 i = 0; i < count; i++) {
        SiGfxShaderGraphIOSlot* pSlot =
            SiGfxShaderGraphIOSlot::Unk_4e0f70(Unk_Allocator(), field_b8->field_c0.m_pData[i]);
        field_c0.Unk_Add(pSlot);
    }
    return true;
}

// 0x71004e0bb0
bool SiGfxShaderGraphNode::vf17() {
    s32 count = static_cast<s32>(field_b8->field_110.m_itemCount);
    field_110.Unk_ReserveAtLeast(count);
    for (s32 i = 0; i < count; i++) {
        SiGfxShaderGraphIOSlot* pSlot =
            SiGfxShaderGraphIOSlot::Unk_4e0f70(Unk_Allocator(), field_b8->field_110.m_pData[i]);
        field_110.Unk_Add(pSlot);
    }
    return true;
}

}  // namespace SiSDK3
