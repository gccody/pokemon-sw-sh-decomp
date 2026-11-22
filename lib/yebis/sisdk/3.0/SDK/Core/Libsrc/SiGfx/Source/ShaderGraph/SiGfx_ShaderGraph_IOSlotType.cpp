// Scope: common
// SiSDK3::SiGfxShaderGraphIOSlotType (0x71004dcbf0 to 0x71004dd020). The
// file's name is the __FILE__ of its allocation.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_IOSlotType.h>

// 0x710276d610
void* Unk_276d610;

namespace SiSDK3 {

// 0x71004dcbf0
SiGfxShaderGraphIOSlotType* SiGfxShaderGraphIOSlotType::Unk_4dcbf0(ISiAllocator* pAllocator, u32 direction) {
#line 36
    SiGfxShaderGraphIOSlotType* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphIOSlotType(pAllocator, direction);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004dcd10 (D2), 0x71004dce80 (D0); the other bases' thunks: 0x71004dce50,
// 0x71004dce60, 0x71004dce70 and 0x71004dceb0, 0x71004dcee0, 0x71004dcf10
SiGfxShaderGraphIOSlotType::~SiGfxShaderGraphIOSlotType() {
    SiGfxShaderGraphIOSlotType::vf8();
}

// 0x71004dcf40
bool SiGfxShaderGraphIOSlotType::vf7() {
    return SiGfxShaderGraphObject::vf7();
}

// 0x71004dcf50
void SiGfxShaderGraphIOSlotType::vf8() {
    if (field_c0 != nullptr) {
        field_c0->vf3();
        field_c0 = nullptr;
    }
    Unk_ReleaseItems(&field_c8);
    SiGfxShaderGraphObject::vf8();
}

}  // namespace SiSDK3
