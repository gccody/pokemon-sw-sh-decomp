// Scope: common
// SiSDK3::SiGfxShaderGraphObject: the functions of its own translation unit
// (0x71004dc730 to 0x71004dcb70). Its inline ones are the header's; its two
// empty event handlers (vf14, vf15) are lib/yebis/class's.
#define UNK_SIGFX_SHADERGRAPH_OBJECT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>

// 0x710276d590
void* Unk_276d590;

namespace SiSDK3 {

// 0x71004dc730
SiGfxShaderGraphObject::SiGfxShaderGraphObject(ISiAllocator* pAllocator)
    : field_30(pAllocator), field_40(), field_50(pAllocator), field_80(0), field_88(pAllocator) {
    field_8 = this;
    field_10 = Unk_276d590;
}

// 0x71004dc7f0 (D2), 0x71004dc920 (D0); the other bases' thunks: 0x71004dc8f0,
// 0x71004dc900, 0x71004dc910 and 0x71004dc950, 0x71004dc980, 0x71004dc9b0
SiGfxShaderGraphObject::~SiGfxShaderGraphObject() {
    SiGfxShaderGraphObject::vf8();
}

// 0x71004dc9e0
bool SiGfxShaderGraphObject::vf7() {
    field_40 = Unk_4c8f70();
    return true;
}

// 0x71004dca10
void SiGfxShaderGraphObject::vf8() {
    field_50.Unk_Clear();
    field_88.Unk_Clear();
}

// 0x71004dcab0; the named object's thunk has it inline: 0x71004dcaf0
bool SiGfxShaderGraphObject::vf18(const char* name) {
    Unk_StringAssign(&field_50, name);
    field_80 = Unk_4c3510(&field_50);
    return true;
}

// 0x71004dcb30
bool SiGfxShaderGraphObject::vf12(const char* text) {
    Unk_StringAssign(&field_88, text);
    return true;
}

}  // namespace SiSDK3
