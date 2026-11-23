// Scope: common
// SiSDK3::SiGfxImageLoaderDDS: the function that makes one, its destructors,
// what tells a DDS file by its name, the loading (the headers, the image they
// describe and the pixels of each kind of image). The reference counts are
// its header's.
#define UNK_SIGFX_IMAGELOADER_DDS_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/Image/DDS/SiGfx_ImageLoader_DDS.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringAssign.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringCompare.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/Image/DDS/Unk_4f66b0.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x710057d030 (leafgen's name and type): SiIO's kernel
u64 Unk_57d030_get();

// 0x71004ed0c0: how many bytes a pixel of a format is; 0x71004ed0f0: how many
// a block of a compressed one; 0x71004ed120: whether a format is compressed
s32 Unk_4ed0c0(u32 format);
s32 Unk_4ed0f0(u32 format);
bool Unk_4ed120(u32 format);

// 0x71004f5040: a new loader
SiSDK3::SiGfxImageLoaderDDS* Unk_4f5040(SiSDK3::ISiAllocator* pAllocator) {
#line 37
    return UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxImageLoaderDDS(pAllocator);
}

namespace SiSDK3 {

// 0x71004f50a0 (D2), 0x71004f50c0 (D0)
SiGfxImageLoaderDDS::~SiGfxImageLoaderDDS() {}

// The larger of two numbers (placeholder name).
inline s32 Unk_Max(s32 a, s32 b) {
    return a > b ? a : b;
}

// The last position of one of the characters of set in a string, or -1
// (inline: placeholder name).
inline s64 Unk_FindLastOf(const SiString<char>* self, const char* set) {
    if (self->field_10 == 0) {
        return -1;
    }
    s64 count = Unk_StringLength(set);
    s64 i = static_cast<s64>(self->field_10) - 1;
    if (i >= 0 && count != 0) {
        const char* buffer = self->m_pBuffer;
        do {
            char c = buffer[i];
            for (s64 j = 0; j < count; j++) {
                if (c == set[j]) {
                    return i;
                }
            }
        } while (i-- > 0);
    }
    return -1;
}

// The last position of a character in a string, or -1 (inline: placeholder
// name). It counts the characters of a set of the one character, as the
// other does, but compares with the character itself: the original's search
// for the dot has the count's loop and test and no loop over the set.
inline s64 Unk_FindLastOf(const SiString<char>* self, char c) {
    char set[] = {c, 0};
    if (self->field_10 == 0) {
        return -1;
    }
    s64 count = Unk_StringLength(set);
    s64 i = static_cast<s64>(self->field_10) - 1;
    if (i >= 0 && count != 0) {
        const char* buffer = self->m_pBuffer;
        do {
            if (buffer[i] == c) {
                return i;
            }
        } while (i-- > 0);
    }
    return -1;
}

// Copies count characters (all of them for a negative count) and terminates
// them (inline: placeholder name).
inline void Unk_CopyChars(char* dst, const char* src, s64 count) {
    if (count < 0) {
        if (src == nullptr) {
            return;
        }
        count = 0;
        while (src[count] != 0) {
            count++;
        }
    }
    if (dst == nullptr || count < 1) {
        return;
    }
    for (s64 i = 0; i < count; i++) {
        dst[i] = src[i];
    }
    dst[count] = 0;
}

// Makes a string the characters of another from start on (inline:
// placeholder name).
inline void Unk_AssignFrom(SiString<char>* self, const SiString<char>* other, size_t start) {
    if (other->field_10 == 0) {
        if (self->m_pBuffer != nullptr) {
            self->m_pBuffer[0] = 0;
        }
        self->field_10 = 0;
        return;
    }
    if (other->field_10 <= start) {
        return;
    }
    size_t count = other->field_10 - start;
    if (self->field_20 <= count) {
        size_t length = count + 1;
        size_t capacity;
        if (self->field_18 != 0) {
            capacity = self->field_18 + length;
        } else {
            capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
        }
        Unk_StringSetCapacity(self, capacity, false);
    }
    Unk_CopyChars(self->m_pBuffer, other->m_pBuffer + start, count);
    self->field_10 = count;
}

}  // namespace SiSDK3

// NON_MATCHING: the same size; the search for the separators is the
// original's (the helper written as SiGfx_ShaderUtility_Impl.cpp's for the
// directory, 0x71004e4230, which matches), but in the search for the dot
// clang folds the set's count: the original keeps the count's loop and its
// `cbz` (here the count is known to be 1). Tried: the count as a pointer
// difference, `size_t`, an index loop, Unk_StringLength, the null test
// before or after the count, `count > 0`, the dot's search through the set
// version (the set's count is folded too).
// 0x71004f52b0: a path's extension (after the last '.' of its file name)
inline SiSDK3::SiString<char> Unk_4f52b0(const SiSDK3::SiString<char>& path) {
    SiSDK3::SiString<char> extension(path.m_pAllocator);
    char separators[] = "/:\\";
    s64 separator = SiSDK3::Unk_FindLastOf(&path, separators);
    s64 position = SiSDK3::Unk_FindLastOf(&path, '.');
    position = position < separator ? -1 : position;
    if (position > 0) {
        SiSDK3::Unk_AssignFrom(&extension, &path, position + 1);
    }
    return extension;
}

namespace SiSDK3 {

// 0x71004f5100
bool SiGfxImageLoaderDDS::vf5(const char* path, SiGfxImage* image) {
    SiString<char> name(nullptr, path);
    SiString<char> extension = Unk_4f52b0(name);
    return Unk_CompareNoCase(&extension, "dds") == 0;
}

// Appends a file's path to what went wrong (inline: placeholder name).
inline void Unk_AppendPath(Unk_4f5570_Options* options, const char* text, const char* path) {
    Unk_StringAssign(&options->field_10, text);
    Unk_StringAppendGrow(&options->field_10, path);
}

// 0x71004f5570: the file is read into a memory stream first
bool SiGfxImageLoaderDDS::vf6(const char* path, SiGfxImage* image, Unk_4f5570_Options* options) {
    SiIOKernel* kernel = reinterpret_cast<SiIOKernel*>(Unk_57d030_get());
    ISiIOStream* memory = kernel->vf8(nullptr);
    if (memory == nullptr) {
        Unk_StringAssign(&options->field_10, "SiGfxImageLoaderDDS::Load --> Failed to create memory stream");
        return false;
    }
    memory->vf13(1);
    ISiIOStream* file = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 9, nullptr);
    if (file != nullptr) {
        if (memory->vf6(path, 0x18, file->vf10())) {
            void* data = reinterpret_cast<void*>(memory->vf76());
            bool read = file->vf21(data, memory->vf10(), true);
            file->vf9();
            file->vf3();
            if (read) {
                Unk_4f5870_Header header;
                Unk_4f5870_HeaderDX10 headerDX10;
                bool isDX10;
                if (!Unk_4f5870(memory, path, options, &header, &headerDX10, &isDX10)) {
                    memory->vf3();
                    return false;
                }
                if (!Unk_4f5ae0(image, path, options, &header, &headerDX10, &isDX10)) {
                    memory->vf3();
                    return false;
                }
                bool result = Unk_4f5d90(memory, image, path, options, &header, &headerDX10, &isDX10);
                memory->vf3();
                return result;
            }
        } else {
            file->vf3();
        }
    }
    Unk_StringAssign(&options->field_10, "SiGfxImageLoaderDDS::Load --> Failed to read memory stream");
    Unk_StringAppendGrow(&options->field_10, " : ");
    Unk_StringAppendGrow(&options->field_10, path);
    memory->vf3();
    return false;
}

// 0x71004f5870
bool SiGfxImageLoaderDDS::Unk_4f5870(ISiIOStream* stream, const char* path, Unk_4f5570_Options* options,
                                     Unk_4f5870_Header* header, Unk_4f5870_HeaderDX10* headerDX10, bool* isDX10) {
    *isDX10 = false;
    memset(header, 0, sizeof(*header));
    memset(headerDX10, 0, sizeof(*headerDX10));
    if (stream->vf31(true) != 0x20534444) {
        Unk_AppendPath(options, "This is not valid DDS file : ", path);
        return false;
    }
    if (!stream->vf21(header, sizeof(*header), true)) {
        Unk_AppendPath(options, "Failed to read DDS header : ", path);
        return false;
    }
    if (header->field_0 != 0x7c) {
        Unk_AppendPath(options, "Header Size is not 124  : ", path);
        return false;
    }
    if ((header->field_48[1] & 4) && header->field_48[2] == 0x30315844) {
        *isDX10 = true;
        if (!stream->vf21(headerDX10, sizeof(*headerDX10), true)) {
            Unk_AppendPath(options, "Failed to read DDS header DXT10 : ", path);
            return false;
        }
    }
    return true;
}

// What an image is made with here (placeholder name): the image's
// description and more that isn't used.
struct Unk_4f5ae0_Desc {
    SiGfxImage::Unk_Info field_0;
    u32 field_1c;
    u64 field_20;
    u64 field_28;
};
PKMN_SIZE_ASSERT(Unk_4f5ae0_Desc, 0x30);

// 0x71004f5ae0
bool SiGfxImageLoaderDDS::Unk_4f5ae0(SiGfxImage* image, const char* path, Unk_4f5570_Options* options,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    u32 format = 0;
    if (*isDX10) {
        if (!Unk_4f6890(headerDX10->field_0, &format)) {
            Unk_AppendPath(options, "Invalid format : ", path);
            return false;
        }
    } else if (!Unk_4f66b0(reinterpret_cast<const Unk_4f66b0_PixelFormat*>(header->field_48), &format)) {
        Unk_AppendPath(options, "Invalid format : ", path);
        return false;
    }
    s32 kind;
    if (*isDX10) {
        switch (headerDX10->field_4) {
        case 2:
            kind = 1;
            break;
        case 3:
            if (headerDX10->field_8 & 4) {
                kind = 4;
            } else {
                kind = headerDX10->field_c > 1 ? 5 : 2;
            }
            break;
        case 4:
            kind = 3;
            break;
        default:
            Unk_AppendPath(options, "Invalid image type : ", path);
            return false;
        }
    } else if (header->field_6c & 0x200) {
        kind = 4;
    } else if (header->field_6c & 0x200000) {
        kind = 3;
    } else {
        kind = header->field_14 > 1 ? 3 : 2;
    }
    s32 mipCount = Unk_Max(header->field_18, 1);
    Unk_4f5ae0_Desc desc = {};
    desc.field_0.field_0 = kind;
    desc.field_0.field_4 = format;
    desc.field_0.field_14 = mipCount;
    desc.field_0.field_8 = header->field_c;
    desc.field_0.field_c = header->field_8;
    if (kind == 3) {
        desc.field_0.field_10 = header->field_14;
    }
    if (*isDX10) {
        desc.field_0.field_18 = headerDX10->field_c;
    }
    if (!image->vf8(&desc.field_0)) {
        Unk_AppendPath(options, "Failed to create image : ", path);
        return false;
    }
    return true;
}

// 0x71004f5dd0: a 2D image's pixels, a row (of blocks) at a time
bool SiGfxImageLoaderDDS::Unk_4f5dd0(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    s32 mipCount = Unk_Max(header->field_18, 1);
    s32 width = header->field_c;
    s32 height = header->field_8;
    for (s32 level = 0; level < mipCount; level++) {
        if (image->field_58.field_14 <= level) {
            break;
        }
        SiGfxImage::ImageData2D* data = image->vf17(0, level);
        if (data == nullptr) {
            return false;
        }
        if (data->field_0 == nullptr) {
            return false;
        }
        if (Unk_4ed120(image->field_58.field_4)) {
            s32 blockSize = Unk_4ed0f0(image->field_58.field_4);
            s32 blocksWide = width > 0 ? (width + 3) / 4 : 1;
            s32 blocksHigh = height < 4 ? 1 : height / 4;
            u8* p = data->field_0;
            for (s32 y = 0; y < blocksHigh; y++) {
                stream->vf21(p, blocksWide * blockSize, true);
                p += blocksWide * blockSize;
            }
        } else {
            s32 pixelSize = Unk_4ed0c0(image->field_58.field_4);
            u8* p = data->field_0;
            for (s32 y = 0; y < height; y++) {
                stream->vf21(p, pixelSize * width, true);
                p += pixelSize * width;
            }
        }
        width >>= 1;
        height >>= 1;
        width = Unk_Max(width, 1);
        height = Unk_Max(height, 1);
    }
    return true;
}

// 0x71004f5f80: an array of 2D images' pixels, image by image (an
// uncompressed level is read with the header's size)
bool SiGfxImageLoaderDDS::Unk_4f5f80(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    s32 mipCount = Unk_Max(header->field_18, 1);
    for (s32 i = 0; i < image->field_58.field_18; i++) {
        s32 width = header->field_c;
        s32 height = header->field_8;
        for (s32 level = 0; level < mipCount; level++) {
            if (image->field_58.field_14 <= level) {
                return true;
            }
            SiGfxImage::ImageData2D* data = image->vf17(i, level);
            if (data == nullptr) {
                return false;
            }
            if (data->field_0 == nullptr) {
                return false;
            }
            if (Unk_4ed120(image->field_58.field_4)) {
                s32 blockSize = Unk_4ed0f0(image->field_58.field_4);
                s32 blocksWide = width > 0 ? (width + 3) / 4 : 1;
                s32 blocksHigh = height < 4 ? 1 : height / 4;
                u8* p = data->field_0;
                for (s32 y = 0; y < blocksHigh; y++) {
                    stream->vf21(p, blocksWide * blockSize, true);
                    p += blocksWide * blockSize;
                }
            } else {
                s32 pixelSize = Unk_4ed0c0(image->field_58.field_4);
                s32 rowWidth = header->field_c;
                u8* p = data->field_0;
                for (s32 y = 0; y < header->field_8; y++) {
                    stream->vf21(p, static_cast<s64>(rowWidth) * pixelSize, true);
                    p += static_cast<s64>(rowWidth) * pixelSize;
                }
            }
            width >>= 1;
            height >>= 1;
            width = Unk_Max(width, 1);
            height = Unk_Max(height, 1);
        }
    }
    return true;
}

// 0x71004f6180
// a cube's pixels, face by face
bool SiGfxImageLoaderDDS::Unk_4f6180(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    s32 mipCount = Unk_Max(header->field_18, 1);
    for (s32 face = 0; face < 6; face++) {
        s32 width = header->field_c;
        s32 height = header->field_8;
        for (s32 level = 0; level < mipCount; level++) {
            if (image->field_58.field_14 <= level) {
                return true;
            }
            SiGfxImage::ImageData2D* data = image->vf18(0, face, level);
            if (data == nullptr) {
                return false;
            }
            if (data->field_0 == nullptr) {
                return false;
            }
            if (Unk_4ed120(image->field_58.field_4)) {
                s32 blockSize = Unk_4ed0f0(image->field_58.field_4);
                s32 blocksWide = width > 0 ? (width + 3) / 4 : 1;
                s32 blocksHigh = height < 4 ? 1 : height / 4;
                u8* p = data->field_0;
                for (s32 y = 0; y < blocksHigh; y++) {
                    stream->vf21(p, blocksWide * blockSize, true);
                    p += blocksWide * blockSize;
                }
            } else {
                s32 pixelSize = Unk_4ed0c0(image->field_58.field_4);
                s32 rowWidth = header->field_c;
                u8* p = data->field_0;
                for (s32 y = 0; y < header->field_8; y++) {
                    stream->vf21(p, static_cast<s64>(rowWidth) * pixelSize, true);
                    p += static_cast<s64>(rowWidth) * pixelSize;
                }
            }
            width >>= 1;
            height >>= 1;
            width = Unk_Max(width, 1);
            height = Unk_Max(height, 1);
        }
    }
    return true;
}

// 0x71004f6370: a 3D image's pixels, slice by slice (each level is read with
// the header's size)
bool SiGfxImageLoaderDDS::Unk_4f6370(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    s32 mipCount = Unk_Max(header->field_18, 1);
    for (s32 level = 0; level < mipCount; level++) {
        if (image->field_58.field_14 <= level) {
            return true;
        }
        s32 depth = header->field_14;
        s32 height = header->field_8;
        s32 width = header->field_c;
        SiGfxImage::ImageData3D* data = image->vf19(level);
        if (data == nullptr) {
            return false;
        }
        if (data->field_0 == nullptr) {
            return false;
        }
        if (Unk_4ed120(image->field_58.field_4)) {
            s32 blockSize = Unk_4ed0f0(image->field_58.field_4);
            s32 blocksWide = width > 0 ? (width + 3) / 4 : 1;
            s32 blocksHigh = height < 4 ? 1 : height / 4;
            u8* p = data->field_0;
            for (s32 z = 0; z < depth; z++) {
                for (s32 y = 0; y < blocksHigh; y++) {
                    stream->vf21(p, blocksWide * blockSize, true);
                    p += blocksWide * blockSize;
                }
            }
        } else {
            s32 pixelSize = Unk_4ed0c0(image->field_58.field_4);
            s32 rowWidth = header->field_c;
            u8* p = data->field_0;
            for (s32 z = 0; z < depth; z++) {
                for (s32 y = 0; y < header->field_8; y++) {
                    stream->vf21(p, static_cast<s64>(rowWidth) * pixelSize, true);
                    p += static_cast<s64>(rowWidth) * pixelSize;
                }
            }
        }
    }
    return true;
}

// 0x71004f5d90
bool SiGfxImageLoaderDDS::Unk_4f5d90(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    switch (image->field_58.field_0) {
    case 2:
        return Unk_4f5dd0(stream, image, path, result, header, headerDX10, isDX10);
    case 3:
        return Unk_4f6370(stream, image, path, result, header, headerDX10, isDX10);
    case 4:
        return Unk_4f6180(stream, image, path, result, header, headerDX10, isDX10);
    case 5:
        return Unk_4f5f80(stream, image, path, result, header, headerDX10, isDX10);
    default:
        return false;
    }
}

}  // namespace SiSDK3
