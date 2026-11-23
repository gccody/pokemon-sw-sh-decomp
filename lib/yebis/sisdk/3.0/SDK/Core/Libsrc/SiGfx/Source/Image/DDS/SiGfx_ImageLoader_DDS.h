// SiSDK3::SiGfxImageLoaderDDS (RTTI: SiGfxImageLoaderDDS : ISiGfxImageLoader :
// ISiInterface; written as one class): what loads an image from a DDS file.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit (UNK_SIGFX_IMAGELOADER_DDS_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiIOStream;
class SiGfxImage;

// A DDS file's header after its magic number (the file format's DDS_HEADER,
// 124 bytes) and the one that follows it for the "DX10" code (placeholder
// names).
struct Unk_4f5870_Header {
    u32 field_0;   // the structure's size
    u32 field_4;   // flags
    s32 field_8;   // the height
    s32 field_c;   // the width
    u32 field_10;
    u32 field_14;  // the depth
    s32 field_18;  // how many mip levels
    u32 field_1c[11];
    u32 field_48[8];  // the pixel format (Unk_4f66b0_PixelFormat)
    u32 field_68;     // what the surface is
    u32 field_6c;     // 0x200: a cube, 0x200000: a volume
    u32 field_70[3];
};
PKMN_SIZE_ASSERT(Unk_4f5870_Header, 0x7c);
struct Unk_4f5870_HeaderDX10 {
    u32 field_0;  // the format
    u32 field_4;  // 2: 1D, 3: 2D, 4: 3D
    u32 field_8;  // 4: a cube
    u32 field_c;  // how many images
    u32 field_10;
};
PKMN_SIZE_ASSERT(Unk_4f5870_HeaderDX10, 0x14);

// What the image utility gives a loader besides the file (placeholder name):
// the kind to make the image and the text of what went wrong.
struct Unk_4f5570_Options {
    u64 field_0;
    s32 field_8;
    SiString<char> field_10;
};

class SiGfxImageLoaderDDS {
public:
    explicit SiGfxImageLoaderDDS(ISiAllocator* pAllocator) : field_8(pAllocator) {}
    virtual ~SiGfxImageLoaderDDS();  // 0x71004f50a0, 0x71004f50c0
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    // 0x71004f5100: whether a file is a DDS file, by its name's extension
    virtual bool vf5(const char* path, SiGfxImage* image);
    // 0x71004f5570: loads one into the image
    virtual bool vf6(const char* path, SiGfxImage* image, Unk_4f5570_Options* options);

    // 0x71004f5870: reads the headers; 0x71004f5ae0: makes the image they
    // tell (this isn't used: the callers don't pass it)
    bool Unk_4f5870(ISiIOStream* stream, const char* path, Unk_4f5570_Options* options, Unk_4f5870_Header* header,
                    Unk_4f5870_HeaderDX10* headerDX10, bool* isDX10);
    bool Unk_4f5ae0(SiGfxImage* image, const char* path, Unk_4f5570_Options* options, const Unk_4f5870_Header* header,
                    const Unk_4f5870_HeaderDX10* headerDX10, const bool* isDX10);

    // 0x71004f5d90: reads the pixels of an image of a kind; 0x71004f5dd0 2D,
    // 0x71004f5f80 an array, 0x71004f6180 a cube, 0x71004f6370 3D
    bool Unk_4f5d90(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result, const Unk_4f5870_Header* header,
                    const Unk_4f5870_HeaderDX10* headerDX10, const bool* isDX10);
    bool Unk_4f5dd0(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result, const Unk_4f5870_Header* header,
                    const Unk_4f5870_HeaderDX10* headerDX10, const bool* isDX10);
    bool Unk_4f5f80(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result, const Unk_4f5870_Header* header,
                    const Unk_4f5870_HeaderDX10* headerDX10, const bool* isDX10);
    bool Unk_4f6180(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result, const Unk_4f5870_Header* header,
                    const Unk_4f5870_HeaderDX10* headerDX10, const bool* isDX10);
    bool Unk_4f6370(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result, const Unk_4f5870_Header* header,
                    const Unk_4f5870_HeaderDX10* headerDX10, const bool* isDX10);

    Unk_4bf660 field_8;
};
PKMN_SIZE_ASSERT(SiGfxImageLoaderDDS, 0x18);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_IMAGELOADER_DDS_IMPL
// 0x71004f6580 (vf2), 0x71004f65a0 (vf3)
#line 26
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxImageLoaderDDS, field_8.m_pAllocator, field_8.m_count)
#endif
