// Scope: common
// SiSDK3::SiGfxNXVolume: its construction and destruction, its name, and the
// reference counts its header defines. (Its small accessors are
// lib/yebis/class's.)
#define UNK_SIGFX_NX_VOLUME_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Volume_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x7100565c80 (leafgen's name and type: the volume and a flag)
void Unk_565c80(void* volume, u32 a1);

namespace SiSDK3 {

// 0x71005656f0
SiGfxNXVolume::SiGfxNXVolume()
    : field_10(nullptr), field_20(nullptr), field_28(0), field_30(nullptr), field_60(0), field_64(), field_78(),
      field_b8(0), field_c0(nullptr) {
    field_64.field_0 = 4;
}

// 0x7100565780 (D2), 0x71005658a0 (D0); 0x7100565810 and 0x7100565930 are
// their thunks for the second base
SiGfxNXVolume::~SiGfxNXVolume() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
}

// 0x71005659c0 (0x7100565a00: its thunk)
bool SiGfxNXVolume::vf20(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    return true;
}

// 0x7100565a40 (0x7100565a50: its thunk)
const SiString<char>* SiGfxNXVolume::vf21() {
    return &field_30;
}

// 0x7100565a60 (0x7100565a70: its thunk)
u32 SiGfxNXVolume::vf22() {
    return field_60;
}

// 0x7100565ab0
void SiGfxNXVolume::Unk_565ab0(SiGfxNXDevice* pDevice) {
    field_10.m_pAllocator = pDevice->field_8.m_pAllocator;
    field_30.Unk_SetAllocator(pDevice->field_8.m_pAllocator);
    field_20 = pDevice;
}

// 0x7100565c10
bool SiGfxNXVolume::Unk_565c10(void* data, u32 a2) {
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 4;
    field_b8 = 0;
    field_c0 = nullptr;
    field_78 = Unk_78();
    if (data == nullptr) {
        return false;
    }
    field_c0 = data;
    Unk_565c80(this, 1);
    field_c8 = a2;
    return true;
}

}  // namespace SiSDK3
