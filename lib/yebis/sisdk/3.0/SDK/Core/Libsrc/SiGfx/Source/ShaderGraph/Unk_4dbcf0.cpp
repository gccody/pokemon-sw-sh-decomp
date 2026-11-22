// Scope: common
// SiSDK3::SiGfxShaderGraphNodeType (0x71004dbcf0 to 0x71004dc6b0). The
// object's inline functions (0x71004dc340 to 0x71004dc4b0) are in this
// translation unit's range: it is the first that has a vtable with them.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dbcf0.h>

// 0x710276d510
void* Unk_276d510;

namespace SiSDK3 {

// 0x71004dbcf0
SiGfxShaderGraphNodeType::SiGfxShaderGraphNodeType(ISiAllocator* pAllocator)
    : SiGfxShaderGraphObject(pAllocator), field_b8(0x3f), field_c0(pAllocator), field_110(pAllocator) {
    field_8 = this;
    field_10 = Unk_276d510;
}

// 0x71004dbdb0 (D2); the deleting destructor of an abstract class is a trap:
// 0x71004dc060. The other bases' thunks: 0x71004dc030, 0x71004dc040,
// 0x71004dc050 and 0x71004dc070, 0x71004dc080, 0x71004dc090
// (vf8's statements, not a call of it: with two arrays vf8 is too large to be
// inlined, and the original has its code here)
SiGfxShaderGraphNodeType::~SiGfxShaderGraphNodeType() {
    Unk_ReleaseItems(&field_c0);
    Unk_ReleaseItems(&field_110);
    SiGfxShaderGraphObject::vf8();
}

// 0x71004dc0a0
bool SiGfxShaderGraphNodeType::vf7() {
    return SiGfxShaderGraphObject::vf7();
}

// 0x71004dc0b0
void SiGfxShaderGraphNodeType::vf8() {
    Unk_ReleaseItems(&field_c0);
    Unk_ReleaseItems(&field_110);
    SiGfxShaderGraphObject::vf8();
}

// 0x71004dc1e0
bool SiGfxShaderGraphNodeType::Unk_4dc1e0(SiGfxShaderGraphIOSlotType* pSlotType) {
    if (pSlotType->field_b8 != 1) {
        return false;
    }
    field_c0.Unk_Add(pSlotType);
    pSlotType->vf2();
    return true;
}

// 0x71004dc290
bool SiGfxShaderGraphNodeType::Unk_4dc290(SiGfxShaderGraphIOSlotType* pSlotType) {
    if (pSlotType->field_b8 != 2) {
        return false;
    }
    field_110.Unk_Add(pSlotType);
    pSlotType->vf2();
    return true;
}

}  // namespace SiSDK3
