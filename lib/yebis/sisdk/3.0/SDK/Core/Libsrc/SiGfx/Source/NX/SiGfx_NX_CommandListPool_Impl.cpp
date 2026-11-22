// Scope: common
// SiSDK3::SiGfxNXCommandListPool: its construction and destruction, its
// command lists, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_COMMANDLISTPOOL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandListPool_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXCommandList.h>

// 0x7100596760: lets other threads run
void Unk_596760();

namespace SiSDK3 {

// 0x710054f170
SiGfxNXCommandListPool::SiGfxNXCommandListPool(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_28(pAllocator), field_78(0) {}

// 0x710054f1f0 (D2), 0x710054f340 (D0)
SiGfxNXCommandListPool::~SiGfxNXCommandListPool() {
    Unk_ReleaseAll(&field_28);
    field_78 = 0;
}

// NON_MATCHING: the same instructions with two registers exchanged (the
// addresses of the array's count and of its buffer, x21 and x22), and the
// failure's three zero stores through those registers where the original has
// them through `this` (`str xzr, [x19, #0x38] ; stp xzr, xzr, [x19, #0x58]`).
// 0x710054f460
bool SiGfxNXCommandListPool::vf8(s32 count) {
    Unk_ReleaseAll(&field_28);
    if (!field_28.Unk_SetCount(count)) {
        return false;
    }
    for (s64 i = 0; i < static_cast<s32>(field_28.m_itemCount); i++) {
#line 140
        SiGfxNXCommandList* list = UNK_SI_NEW(field_8.m_pAllocator, 0x10)
            SiGfxNXCommandList(field_8.m_pAllocator, field_18, this);
        list->Unk_53a000(field_20);
        field_28.m_pData[i] = list;
    }
    return true;
}

// 0x710054f5d0
SiGfxNXCommandList* SiGfxNXCommandListPool::vf9() {
    if (field_78 >= static_cast<s32>(field_28.m_itemCount)) {
        return nullptr;
    }
    SiGfxNXCommandList* list = field_28.m_pData[field_78];
    field_78++;
    list->field_14c = 1;
    return list;
}

// 0x710054f650
void SiGfxNXCommandListPool::vf12() {
    for (s64 i = 0; i < field_78; i++) {
        SiGfxNXCommandList* list = field_28.m_pData[i];
        while (list->field_14c > 0) {
            Unk_596760();
        }
    }
}

}  // namespace SiSDK3
