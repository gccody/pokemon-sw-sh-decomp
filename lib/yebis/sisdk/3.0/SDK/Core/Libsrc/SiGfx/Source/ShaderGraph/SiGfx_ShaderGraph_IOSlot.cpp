// Scope: common
// SiSDK3::SiGfxShaderGraphIOSlot (0x71004e0f70 to 0x71004e1750). The file's
// name is the __FILE__ of its allocation.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_IOSlot.h>

// 0x710276dc10
void* Unk_276dc10;

namespace SiSDK3 {

// 0x71004e0f70
SiGfxShaderGraphIOSlot* SiGfxShaderGraphIOSlot::Unk_4e0f70(ISiAllocator* pAllocator,
                                                           SiGfxShaderGraphIOSlotType* pType) {
    SiGfxShaderGraphIOSlot* p;
#line 36
    p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphIOSlot(pAllocator, pType);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004e1090 (D2), 0x71004e1330 (D0); the other bases' thunks: 0x71004e1300,
// 0x71004e1310, 0x71004e1320 and 0x71004e1360, 0x71004e1390, 0x71004e13c0
// (vf8's statements, not a call of it: vf8 is too large to be inlined, and the
// original has its code here)
SiGfxShaderGraphIOSlot::~SiGfxShaderGraphIOSlot() {
    field_168 = nullptr;
    field_118.Unk_FreeAll();
    if (field_c0 != nullptr) {
        field_c0->vf3();
        field_c0 = nullptr;
    }
    Unk_ReleaseItems(&field_c8);
    SiGfxShaderGraphObject::vf8();
}

// 0x71004e13f0
bool SiGfxShaderGraphIOSlot::vf7() {
    if (!SiGfxShaderGraphObject::vf7()) {
        return false;
    }
    vf18(Unk_StringCStr(field_b8->vf19()));
    vf12(Unk_StringCStr(field_b8->vf13()));
    if (field_c0 != nullptr) {
        field_c0->vf3();
        field_c0 = nullptr;
    }
    if (field_b8->field_c0 != nullptr) {
        field_c0 = field_b8->field_c0->vf17();
    }
    s32 count = static_cast<s32>(field_b8->field_c8.m_itemCount);
    if (count > 0) {
        field_c8.Unk_ReserveAtLeast(count);
        for (s64 i = 0; i < static_cast<s32>(field_b8->field_c8.m_itemCount); i++) {
            SiGfxShaderGraphIOSlotType* pType = field_b8->field_c8.m_pData[i];
            SiGfxShaderGraphIOSlot* pSlot = Unk_4e0f70(Unk_Allocator(), pType);
            field_c8.Unk_Add(pSlot);
        }
    }
    return true;
}

// 0x71004e15e0
void SiGfxShaderGraphIOSlot::vf8() {
    field_168 = nullptr;
    field_118.Unk_FreeAll();
    if (field_c0 != nullptr) {
        field_c0->vf3();
        field_c0 = nullptr;
    }
    Unk_ReleaseItems(&field_c8);
    SiGfxShaderGraphObject::vf8();
}

}  // namespace SiSDK3
