// Scope: common
// SiSDK3::SiGfxNXSurface: its construction and destruction, its name, what it
// is a surface of, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_SURFACE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Surface_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x7100562f10: an NVN texture format as SiGfx numbers it
u32 Unk_562f10(u32 format);
// 0x71004ed0c0: a format's pixel size, 0x71004ed0f0: its block's size,
// 0x71004ed120: whether it's one of blocks
s32 Unk_4ed0c0(u32 format);
s32 Unk_4ed0f0(u32 format);
bool Unk_4ed120(u32 format);
// 0x71004ed180: a number of samples (none for fewer than 2), 0x71004ed6e0
s32 Unk_4ed180(s32 samples);
bool Unk_4ed6e0(u32 format);

namespace SiSDK3 {

// 0x710055c5b0
SiGfxNXSurface::SiGfxNXSurface(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0), field_64(), field_78(),
      field_d0(0), field_d8(nullptr), field_e0(nullptr), field_e8(nullptr), field_f0(nullptr), field_f8(0),
      field_100(0), field_108(0), field_10c(false), field_110(0) {
    field_64.field_0 = 3;
}

// 0x710055c660: for the elements of a texture's array, with the kernel's
// allocator
SiGfxNXSurface::SiGfxNXSurface()
    : field_10(Unk_NXKernel()->vf6()), field_20(nullptr), field_28(0), field_30(Unk_NXKernel()->vf6()), field_60(0),
      field_64(), field_78(), field_d0(0), field_d8(nullptr), field_e0(nullptr), field_e8(nullptr), field_f0(nullptr),
      field_108(0), field_10c(false), field_110(0) {
    field_64.field_0 = 3;
}

// 0x710055c730 (D2), 0x710055c850 (D0); 0x710055c7c0 and 0x710055c8f0 are
// their thunks for the second base
SiGfxNXSurface::~SiGfxNXSurface() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    Unk_55c9a0();
}

// 0x710055c9a0
void SiGfxNXSurface::Unk_55c9a0() {
    if (field_10c) {
        if (field_e0 != nullptr) {
            nvnTextureFinalize(field_e0);
            if (field_e0 != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 541
                    SI_FREE(field_10.m_pAllocator, field_e0);
                }
                field_e0 = nullptr;
            }
        }
        if (field_e8 != nullptr) {
            if (field_10.m_pAllocator != nullptr) {
#line 545
                SI_FREE(field_10.m_pAllocator, field_e8);
            }
            field_e8 = nullptr;
        }
    }
    field_e0 = nullptr;
    field_e8 = nullptr;
    if (field_f0 != nullptr) {
        field_f0->Unk_553010(field_f8);
        field_f8 = 0;
        field_100 = 0;
        if (field_f0 != nullptr) {
            field_f0->vf3();
            field_f0 = nullptr;
        }
    }
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 3;
    field_d8 = nullptr;
    field_110 = 0;
    field_10c = false;
    field_78 = Unk_Desc();
}

// 0x710055caa0 (0x710055cae0: its thunk)
bool SiGfxNXSurface::vf28(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    return true;
}

// 0x710055cb20 (0x710055cb30: its thunk)
const SiString<char>* SiGfxNXSurface::vf29() {
    return &field_30;
}

// 0x710055cb40 (0x710055cb50: its thunk)
u32 SiGfxNXSurface::vf30() {
    return field_60;
}

// 0x710055cb60
void SiGfxNXSurface::Unk_55cb60(SiGfxNXDevice* pDevice) {
    field_10.m_pAllocator = pDevice->field_8.m_pAllocator;
    field_30.Unk_SetAllocator(pDevice->field_8.m_pAllocator);
    field_20 = pDevice;
}

// 0x710055d300
bool SiGfxNXSurface::Unk_55d300(Unk_NXSurfaceTexture* pTexture, u32 level, u32 layer) {
    Unk_55c9a0();
    if (pTexture == nullptr) {
        return false;
    }
    field_d8 = pTexture;
    field_e0 = pTexture->vf40();
    field_e8 = field_d8->vf42(level, layer);
    field_10c = false;
    Unk_55cd70(1, level, layer);
    field_108 = field_d8->vf19()->field_20 * layer + level;
    return true;
}

// 0x710055cd70 (a member with its own `this`: with the surface as an untyped
// pointer the stores of the texture's branch and of the other owner's are
// merged into one)
void SiGfxNXSurface::Unk_55cd70(u32 a1, u32 level, u32 layer) {
    s32 format = nvnTextureGetFormat(field_e0);
    field_78.field_0 = a1;
    field_78.field_44 = 0;
    field_78.field_4 = Unk_562f10(format);
    field_78.field_14 = nvnTextureGetWidth(field_e0);
    field_78.field_18 = nvnTextureGetHeight(field_e0);
    field_78.field_48 = level;
    if (field_d8 != nullptr) {
        field_78.field_8 = field_d8->vf19()->field_8;
        field_78.field_10 = field_d8->vf19()->field_10;
        field_78.field_c = field_d8->vf19()->field_c;
        s32 width = field_d8->vf19()->field_14 >> level;
        field_78.field_14 = width > 1 ? width : 1;
        s32 height = field_d8->vf19()->field_18 >> level;
        field_78.field_18 = height > 1 ? height : 1;
        if (field_d8->vf19()->field_0 == 4 || field_d8->vf19()->field_0 == 6) {
            field_78.field_40 = static_cast<s32>(layer) % 6;
        } else {
            field_78.field_40 = 4;
        }
    } else if (field_78.field_50 != nullptr) {
        field_78.field_10 = field_78.field_50->vf20()->field_20;
    }
    field_78.field_24 = true;
    field_78.field_1c = Unk_4ed180(nvnTextureGetSamples(field_e0));
    field_78.field_2c = Unk_4ed120(field_78.field_4);
    if (field_78.field_2c) {
        field_78.field_30 = (field_78.field_14 + 3) / 4;
        field_78.field_34 = (field_78.field_18 + 3) / 4;
        field_78.field_38 = Unk_4ed0f0(field_78.field_4);
    }
    field_78.field_25 = Unk_4ed6e0(field_78.field_4);
    s32 size = Unk_4ed0c0(field_78.field_4);
    field_110 = field_78.field_14 * size;
    field_78.field_28 = size;
    if (field_78.field_2c) {
        field_110 = field_78.field_38 * field_78.field_30;
    }
}

}  // namespace SiSDK3
