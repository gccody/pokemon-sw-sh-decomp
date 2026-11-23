// SiSDK3::SiGfxNXDeviceInfo (RTTI names the class; it derives from
// ISiGfxNXDeviceInfo, ISiGfxDeviceInfo and ISiInterface, written as one
// class): what the device tells about itself, as far as the executable's
// functions show it. Placeholder members; the virtual functions are
// vf<slot>. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_DEVICEINFO_IMPL). (Unk_DeviceObjects.h has the class as the
// device's translation unit needs it.)
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxNXDevice;

class SiGfxNXDeviceInfo : public ISiInterface {
public:
    // Two numbers (placeholder name): a version, major and minor, of each
    // kind of shader slot 9 is asked for.
    struct Unk_Version {
        Unk_Version() : field_0(0), field_4(0) {}
        Unk_Version(u32 major, u32 minor) : field_0(major), field_4(minor) {}

        u32 field_0;
        u32 field_4;
    };

    explicit SiGfxNXDeviceInfo(SiGfxNXDevice* pDevice);  // 0x7100539270
    ~SiGfxNXDeviceInfo() override;                       // 0x7100539310, 0x7100539380
    u32 vf2() override;                                  // 0x7100539710
    u32 vf3() override;                                  // 0x7100539730
    u32 vf4() override;
    virtual u64 vf5();
    virtual u64 vf6();
    virtual const u8* vf7();
    virtual u32 vf8();
    virtual const Unk_Version* vf9(s32 kind);  // 0x7100539440
    virtual u64 vf10();
    virtual void vf11();
    virtual const u8* vf12();
    virtual u32 vf13();
    virtual u32 vf14();
    virtual u32 vf15();
    virtual u32 vf16();
    virtual u32 vf17();
    virtual u32 vf18();
    virtual u32 vf19();
    virtual u32 vf20();
    virtual f32 vf21();
    virtual u32 vf22();
    virtual u32 vf23();
    virtual u32 vf24();
    virtual u32 vf25();
    virtual const u8* vf26();

    // 0x7100539650: the versions from the device's
    void Unk_539650();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    SiString<char> field_20;
    Unk_Version field_50[5];
    // the sixth version (its major number) and what follows it: its minor
    // number is cleared with the rest of the zeros (placeholder name)
    struct Unk_78 {
        u32 field_0;
        u32 field_4[11];
    } field_78;
};
PKMN_OFFSET_ASSERT(SiGfxNXDeviceInfo, field_50, 0x50);
PKMN_SIZE_ASSERT(SiGfxNXDeviceInfo, 0xa8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_DEVICEINFO_IMPL
// 0x7100539710 (vf2), 0x7100539730 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDeviceInfo, field_8.m_pAllocator, field_8.m_count)
#endif
