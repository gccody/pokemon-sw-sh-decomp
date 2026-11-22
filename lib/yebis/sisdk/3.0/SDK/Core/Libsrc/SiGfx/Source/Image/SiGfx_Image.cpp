// Scope: common
// SiSDK3::SiGfxImage: an image's pixels in memory. Its constructor and
// destructors, its name, the functions that give a mip level's description
// and the ones that pass the image to SiGfx's image utility. (The functions
// that make the image of each kind, slots 9 to 14, and the conversions aren't
// written yet.) The reference counts are its header's.
#define UNK_SIGFX_IMAGE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>

// 0x71004c3510: a string's hash
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);
// 0x71004c4700: assigns a string (Unk_StringFuncs.h's declaration)
void Unk_4c4700(void*, void*);
// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004ee110: flips an image's rows
void Unk_4ee110(u32 format, u8* data, s32 width, s32 height, s32 rowSize);

// 0x71004f4850, 0x71004f4b30, 0x71004f4d90
template bool SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData1D, 16>::Unk_4bf190(size_t, bool);
template bool SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData2D, 16>::Unk_4bf190(size_t, bool);
template bool SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData3D, 16>::Unk_4bf190(size_t, bool);

namespace SiSDK3 {

// SiGfx's image utility as the image uses it: slots 16 and 17 save an image.
class Unk_4f3c00_Utility {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual bool vf16(SiGfxImage* image, u64 a2, const void* options);
    virtual bool vf17(SiGfxImage* image, u64 a2, const void* options);
};
// SiGfx's kernel as the image uses it: slot 22 is the image utility.
class Unk_4f3c00_Kernel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual Unk_4f3c00_Utility* vf22();
};
inline Unk_4f3c00_Kernel* Unk_GfxKernel() {
    return reinterpret_cast<Unk_4f3c00_Kernel*>(Unk_4cbf40_get());
}

// What slot 21 passes on when it is given no options (placeholder name).
struct Unk_4f3c00_Options {
    Unk_4f3c00_Options() : field_0(false), field_1(false), field_2(true), field_4(0), field_8(0) {}

    bool field_0;
    bool field_1;
    bool field_2;
    u32 field_4;
    u32 field_8;
    SiString<char> field_10;
};
PKMN_SIZE_ASSERT(Unk_4f3c00_Options, 0x40);

// What slot 22 passes on when it is given no options (placeholder name).
struct Unk_4f3cf0_Options {
    Unk_4f3cf0_Options() : field_0(0) {}

    u32 field_0;
    u32 field_4;
};

// 0x71004f1290
SiGfxImage::SiGfxImage(ISiAllocator* pAllocator)
    : field_10(pAllocator), field_20(pAllocator), field_50(0), field_54(0), field_58{2, 0, 0, 0, 0, 0, 0}, field_78(0), field_80(true),
      field_88(nullptr), field_e0(pAllocator), field_130(pAllocator) {}

// 0x71004f13c0 (D2), 0x71004f1790 (D0); 0x71004f1780 and 0x71004f17c0 are
// their thunks for the second base
SiGfxImage::~SiGfxImage() {
    SiGfxImage::vf15();
}

// 0x71004f17f0 (0x71004f1830: its thunk)
bool SiGfxImage::vf5(const char* name) {
    Unk_4c4700(&field_20, const_cast<char*>(name));
    field_50 = Unk_4c3510(&field_20);
    return true;
}

// 0x71004f1870 (0x71004f1880: its thunk)
const SiString<char>* SiGfxImage::vf6() {
    return &field_20;
}

// 0x71004f1890 (0x71004f18a0: its thunk)
u32 SiGfxImage::vf7() {
    return field_50;
}

// 0x71004f18b0
bool SiGfxImage::vf8(const Unk_Info* info) {
    switch (info->field_0) {
    case 1:
        return vf9(info->field_4, info->field_8, info->field_14);
    case 2:
        return vf10(info->field_4, info->field_8, info->field_c, info->field_14);
    case 3:
        return vf14(info->field_4, info->field_8, info->field_c, info->field_10, info->field_14);
    case 4:
        return vf12(info->field_4, info->field_8, info->field_14);
    case 5:
        return vf11(info->field_4, info->field_8, info->field_c, info->field_14, info->field_18);
    case 6:
        return vf13(info->field_4, info->field_8, info->field_14, info->field_18 / 6);
    default:
        return false;
    }
}

// 0x71004f3330
void SiGfxImage::vf15() {
    if (field_88 != nullptr) {
#line 1147
        UNK_FREE(field_10.m_pAllocator, field_88);
    }
    field_58.Unk_Reset();
    field_78 = 0;
    field_80 = true;
    field_90.Unk_4e3050();
    field_e0.Unk_4e3050();
    field_130.Unk_4e3050();
}

// 0x71004f34e0
SiGfxImage::ImageData1D* SiGfxImage::vf16(s32 level) {
    if (field_58.field_0 != 3 || level < 0) {
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    return &field_90.m_pData[level];
}

// 0x71004f3520
SiGfxImage::ImageData2D* SiGfxImage::vf17(s32 index, s32 level) {
    switch (field_58.field_0) {
    case 2:
        if (index > 0 || level < 0) {
            return nullptr;
        }
        break;
    case 4:
        if (index > 5 || level < 0) {
            return nullptr;
        }
        break;
    case 5:
        if (index < 0 || index >= field_58.field_18) {
            return nullptr;
        }
        if (level < 0) {
            return nullptr;
        }
        break;
    case 6:
        if (index < 0 || index >= field_58.field_18 * 6) {
            return nullptr;
        }
        if (level < 0) {
            return nullptr;
        }
        break;
    default:
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    s32 i = field_58.field_14 * index + level;
    return &field_e0.m_pData[i];
}

// 0x71004f35e0
SiGfxImage::ImageData2D* SiGfxImage::vf18(s32 index, s32 face, s32 level) {
    if (field_58.field_0 != 4 && field_58.field_0 != 6) {
        return nullptr;
    }
    if (level < 0) {
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    s32 i = field_58.field_14 * (index * 6 + face) + level;
    return &field_e0.m_pData[i];
}

// 0x71004f3640
SiGfxImage::ImageData3D* SiGfxImage::vf19(s32 level) {
    if (field_58.field_0 != 3 || level < 0) {
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    return &field_130.m_pData[level];
}

// 0x71004f3680
bool SiGfxImage::Unk_4f3680() {
    for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
        ImageData2D* data = &field_e0.m_pData[i];
        Unk_4ee110(data->field_10, data->field_0, data->field_14, data->field_18, data->field_1c);
    }
    field_80 = !field_80;
    return true;
}

// 0x71004f3c00
bool SiGfxImage::vf21(u64 a1, const void* options) {
    Unk_4f3c00_Options defaults;
    Unk_4f3c00_Utility* utility = Unk_GfxKernel()->vf22();
    if (utility == nullptr) {
        return false;
    }
    return utility->vf16(this, a1, options == nullptr ? &defaults : options);
}

// 0x71004f3cf0
bool SiGfxImage::vf22(u64 a1, const void* options) {
    Unk_4f3cf0_Options defaults;
    Unk_4f3c00_Utility* utility = Unk_GfxKernel()->vf22();
    if (utility == nullptr) {
        return false;
    }
    return utility->vf17(this, a1, options == nullptr ? &defaults : options);
}

// 0x71004f3d60
bool SiGfxImage::vf23(SiGfxImage* other) {
    if (!other->vf8(&field_58)) {
        return false;
    }
    memcpy(other->field_88, field_88, field_78);
    return true;
}

// 0x71004f4320
bool SiGfxImage::vf26(s32 kind) {
    if (kind == 0 || field_58.field_0 == kind || field_58.field_0 == 0) {
        return true;
    }
    if (kind == 5 && field_58.field_0 == 3) {
        vf25();
        return true;
    }
    if (kind == 6 && field_58.field_0 == 4) {
        field_58.field_0 = 6;
    }
    return true;
}

}  // namespace SiSDK3
