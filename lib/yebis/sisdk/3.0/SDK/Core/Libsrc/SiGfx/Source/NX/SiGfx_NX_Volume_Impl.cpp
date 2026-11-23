// Scope: common
// SiSDK3::SiGfxNXVolume: its construction and destruction, its name, and the
// reference counts its header defines. (Its small accessors are
// lib/yebis/class's.)
#define UNK_SIGFX_NX_VOLUME_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Volume_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004ed0c0, 0x71004ed0f0: what a format's size is (placeholder names)
u32 Unk_4ed0c0(u32 format);
u32 Unk_4ed0f0(u32 format);

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
    Unk_565c80(1, a2);
    field_c8 = a2;
    return true;
}

// The data's description as the volume reads it (placeholders).
struct Unk_565c80_Desc {
    u32 field_0;
    u32 field_4;
    u8 _8[0xc];
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    u8 _20[0x10];
    u32 field_30;
    u32 field_34;
    u8 _38[2];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_565c80_Desc, field_3a, 0x3a);

class Unk_565c80_Data {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual const Unk_NXResourceInfo* vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual const Unk_565c80_Desc* vf19();
};

// (a macro: its argument is evaluated again when it's the greater)
#define UNK_MAX(a, b) ((a) > (b) ? (a) : (b))

// 0x7100565c80
void SiGfxNXVolume::Unk_565c80(u32 a1, u32 level) {
    if (field_c0 == nullptr) {
        return;
    }
    field_78.field_0 = a1;
    field_b8 = level;
    field_78.field_4 = static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_4;
    field_78.field_14 = UNK_MAX(static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_14 >> level, 1);
    field_78.field_18 = UNK_MAX(static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_18 >> level, 1);
    field_78.field_1c = UNK_MAX(static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_1c >> level, 1);
    field_78.field_20 = static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_30;
    field_78.field_24 = static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_34;
    field_78.field_2c = true;
    field_78.field_28 = Unk_4ed0c0(field_78.field_4);
    field_78.field_2d = static_cast<Unk_565c80_Data*>(field_c0)->vf19()->field_3a;
    if (field_78.field_2d) {
        field_78.field_30 = (field_78.field_14 + 3) / 4;
        field_78.field_34 = (field_78.field_18 + 3) / 4;
        field_78.field_3c = Unk_4ed0f0(field_78.field_4);
    }
    field_64.field_4[1] = static_cast<Unk_565c80_Data*>(field_c0)->vf8()->field_4[1];
    field_64.field_4[2] = static_cast<Unk_565c80_Data*>(field_c0)->vf8()->field_4[2];
    field_64.field_4[3] = static_cast<Unk_565c80_Data*>(field_c0)->vf8()->field_4[3];
    field_64.field_4[0] = static_cast<Unk_565c80_Data*>(field_c0)->vf8()->field_4[0];
    field_64.field_0 = 4;
}

}  // namespace SiSDK3
