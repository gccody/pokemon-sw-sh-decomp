// SiSDK3::SiGfxNXDescriptorTable (RTTI names the class; it derives from
// ISiGfxNXDescriptorTable, ISiGfxDescriptorTable and ISiInterface): four
// lists of the resources a table of descriptors holds. Placeholder members;
// the virtual functions are vf<slot>. The reference counts are defined in
// this header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_NX_DESCRIPTORTABLE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// What a resource's slot 8 returns, as the table reads it (placeholder name).
struct Unk_NXResourceUsage {
    u32 field_0;
    u32 field_4;
    u32 field_8;  // what the resource can be used as
};

// SiSDK3::ISiGfxResource (RTTI names it: the tables' arrays are of pointers
// to it) as the table calls it: slots 2 and 3 count its references, slot 8 is
// what it can be used as. The other slots are placeholders.
class ISiGfxResource {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual const Unk_NXResourceUsage* vf8();
};

class SiGfxNXDescriptorTable : public Unk_NXInterface {
public:
    // One list of resources (placeholder name): its array's allocator is
    // SiGfx's kernel's, and it releases what it holds.
    struct Unk_List {
        Unk_List() : field_0(0), field_8(Unk_NXKernel()->vf6()) {}
        ~Unk_List() { Unk_ReleaseAll(&field_8); }

        u32 field_0;
        SiArray<ISiGfxResource*, 16> field_8;
    };

    SiGfxNXDescriptorTable(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054fa00
    ~SiGfxNXDescriptorTable() override;                                        // 0x710054fb40, 0x7100550000
    u32 vf2() override;                                                        // 0x7100550f50
    u32 vf3() override;                                                        // 0x7100550f70
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual bool vf8(u32 kind);  // 0x7100550240: starts changes, as a table of a kind
    virtual bool vf9();  // 0x71005504a0: ends the changes
    // For each list: how many resources it has (set and read), a resource of
    // an index (set while the table changes, and read).
    virtual bool vf10(s32 count);  // 0x7100550510
    virtual u32 vf11();
    virtual bool vf12(s32 index, ISiGfxResource* resource);  // 0x7100550660
    virtual ISiGfxResource* vf13(s32 index);                 // 0x7100550680
    virtual bool vf14(s32 count);                            // 0x7100550690
    virtual u32 vf15();
    virtual bool vf16(s32 index, ISiGfxResource* resource);  // 0x71005507e0
    virtual ISiGfxResource* vf17(s32 index);                 // 0x7100550800
    virtual bool vf18(s32 count);                            // 0x7100550810
    virtual u32 vf19();
    virtual bool vf20(s32 index, ISiGfxResource* resource);  // 0x7100550960
    virtual ISiGfxResource* vf21(s32 index);                 // 0x7100550980
    virtual bool vf22(s32 count);                            // 0x7100550990
    virtual u32 vf23();
    virtual bool vf24(s32 index, ISiGfxResource* resource);  // 0x7100550ae0
    virtual ISiGfxResource* vf25(s32 index);                 // 0x7100550b00
    // 0x7100550b10, 0x7100550c20, 0x7100550d30, 0x7100550e40: sets a
    // resource of a list
    virtual bool vf26(s32 index, ISiGfxResource* resource);
    virtual bool vf27(s32 index, ISiGfxResource* resource);
    virtual bool vf28(s32 index, ISiGfxResource* resource);
    virtual bool vf29(s32 index, ISiGfxResource* resource);
    virtual void vf30();  // 0x7100550f20: one change more
    virtual u64 vf31();
    virtual u32 vf32();

    // 0x710054fdc0: releases the resources
    void Unk_54fdc0();
    // 0x7100550030: what the device makes it with; its lists take the
    // table's allocator
    bool Unk_550030(u32 kind);

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    u32 field_24;  // its kind
    bool field_28;
    bool field_29;  // whether it's being changed
    Unk_List field_30;
    Unk_List field_88;
    Unk_List field_e0;
    Unk_List field_138;
    u64 field_190;  // how many times it has changed
};
PKMN_SIZE_ASSERT(SiGfxNXDescriptorTable::Unk_List, 0x58);
PKMN_OFFSET_ASSERT(SiGfxNXDescriptorTable, field_88, 0x88);
PKMN_SIZE_ASSERT(SiGfxNXDescriptorTable, 0x198);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_DESCRIPTORTABLE_IMPL
// 0x7100550f50 (vf2), 0x7100550f70 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDescriptorTable, field_8.m_pAllocator, field_8.m_count)
#endif
