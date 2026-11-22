// SiSDK3::SiGfxNXDescriptorSet (RTTI names the class and its ParameterEntry;
// it derives from ISiGfxNXDescriptorSet, ISiGfxDescriptorSet and
// ISiInterface): the parameters given to a root signature's slots.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit
// (UNK_SIGFX_NX_DESCRIPTORSET_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

class SiGfxNXDescriptorSet : public Unk_NXInterface {
public:
    // A parameter: its kind (1 to 4), and what it is.
    struct ParameterEntry {
        ParameterEntry() : field_0(0), field_4(0), field_8(0), field_10(false), field_18(0), field_20(0) {}

        u32 field_0;
        u32 field_4;
        u64 field_8;
        bool field_10;
        u64 field_18;
        u64 field_20;
    };

    SiGfxNXDescriptorSet(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054e790
    ~SiGfxNXDescriptorSet() override;                                        // 0x710054e810, 0x710054e960
    u32 vf2() override;                                                      // 0x710054ed20
    u32 vf3() override;                                                      // 0x710054ed40
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual u32 vf8();  // one change more going on
    virtual bool vf9(s32 count);  // 0x710054ea80: how many parameters there are
    // 0x710054eb30, 0x710054eb80, 0x710054ebd0, 0x710054ec20: a parameter of
    // each kind
    virtual bool vf10(s32 index, u32 a2, u64 a3);
    virtual bool vf11(s32 index, u32 a2, u64 a3);
    virtual bool vf12(s32 index, u32 a2, u64 a3);
    virtual bool vf13(s32 index, u32 a2, u64 a3);
    virtual bool vf14(s32 index, bool flag);  // 0x710054ec70
    virtual bool vf15(s32 index);             // 0x710054ec90
    virtual bool vf16();                      // 0x710054ecb0: one change less
    virtual void vf17();
    virtual u64 vf18();
    virtual u32 vf19();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    s32 field_24;  // how many changes are going on
    SiArray<ParameterEntry, 16> field_28;
    u64 field_78;  // how many times it has changed
};
PKMN_SIZE_ASSERT(SiGfxNXDescriptorSet::ParameterEntry, 0x28);
PKMN_SIZE_ASSERT(SiGfxNXDescriptorSet, 0x80);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_DESCRIPTORSET_IMPL
// 0x710054ed20 (vf2), 0x710054ed40 (vf3)
#line 40
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDescriptorSet, field_8.m_pAllocator, field_8.m_count)
#endif
