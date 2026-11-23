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

// The release is written out, with the buffer freed through Unk_FreeAll (one
// inline function more than Unk_ReleaseAll's direct Unk_4e3050): with
// Unk_ReleaseAll the reserve's failure stores share the array's addresses with
// the release (two registers exchanged, the failure's zero stores through them
// instead of `this`).
// 0x710054f460
bool SiGfxNXCommandListPool::vf8(s32 count) {
    for (size_t i = 0; i < field_28.m_itemCount; i++) {
        SiGfxNXCommandList* item = field_28.m_pData[i];
        if (item != nullptr) {
            field_28.m_pData[i] = nullptr;
            item->vf3();
        }
    }
    field_28.Unk_FreeAll();
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
