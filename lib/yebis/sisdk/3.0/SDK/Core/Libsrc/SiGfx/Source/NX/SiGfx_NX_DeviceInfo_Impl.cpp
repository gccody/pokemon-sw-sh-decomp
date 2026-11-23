// Scope: common
// SiSDK3::SiGfxNXDeviceInfo: its construction and destruction, slot 9, the
// versions from the device, and the reference counts its header defines.
// (Its small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_DEVICEINFO_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DeviceInfo_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

namespace SiSDK3 {

// 0x7100539270
SiGfxNXDeviceInfo::SiGfxNXDeviceInfo(SiGfxNXDevice* pDevice)
    : field_8(pDevice->Unk_Allocator()), field_18(pDevice), field_20(pDevice->Unk_Allocator()) {
    for (int i = 0; i < 5; i++) {
        field_50[i] = Unk_Version(5, 0);
    }
    field_78.field_0 = 5;
    for (int i = 0; i < 11; i++) {
        field_78.field_4[i] = 0;
    }
}

// 0x7100539310 (D2), 0x7100539380 (D0)
SiGfxNXDeviceInfo::~SiGfxNXDeviceInfo() {}

// 0x7100539440
const SiGfxNXDeviceInfo::Unk_Version* SiGfxNXDeviceInfo::vf9(s32 kind) {
    switch (kind) {
    case 1:
        return &field_50[0];
    case 2:
        return &field_50[1];
    case 3:
        return &field_50[2];
    case 4:
        return &field_50[4];
    case 5:
        return &field_50[3];
    case 6:
        return reinterpret_cast<const Unk_Version*>(&field_78);
    }
    static Unk_Version none;
    return &none;
}

// 0x7100539650
void SiGfxNXDeviceInfo::Unk_539650() {
    u32 major;
    u32 minor;
    if (static_cast<s32>(field_18->vf16()) >= 0xc000) {
        major = 5;
        minor = 0;
    } else if (static_cast<s32>(field_18->vf16()) >= 0xb000) {
        major = 5;
        minor = 0;
    } else if (static_cast<s32>(field_18->vf16()) > 0xa0ff) {
        major = 4;
        minor = 1;
    } else if (static_cast<s32>(field_18->vf16()) >= 0xa000) {
        major = 4;
        minor = 0;
    } else {
        return;
    }
    field_50[0].field_0 = major;
    field_50[0].field_4 = minor;
    field_50[1].field_0 = major;
    field_50[1].field_4 = minor;
}

}  // namespace SiSDK3
