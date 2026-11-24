// Scope: common
// SiIO's file and stream helpers: the functions between SiIOMemoryStream's
// and SiIOVFSManager's (0x7100582d60 to 0x7100583760). SiIO_Utility.cpp is
// the __FILE__ of the last two (0x7100583410, 0x7100583580: a block's
// compression and decompression); placeholder names.
#include <stdio.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Codec_ZLib_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

namespace nn {
struct Result {
    u32 m_Value;
};
namespace fs {
enum DirectoryEntryType : int;
Result GetEntryType(DirectoryEntryType* outType, const char* path);
}  // namespace fs
}  // namespace nn

// 0x710057cfb0: SiIO's kernel (leafgen's name), 0x710057d840: its archive
// manager (leafgen's name and types)
struct Unk_57d840;
Unk_57d840* Unk_57cfb0();
u64 Unk_57d840_get(const Unk_57d840* self);
// 0x710057d030 (leafgen's name and type): SiIO's kernel
u64 Unk_57d030_get();
// 0x7100583b70, 0x7100583be0: the archive manager's file or directory of a path, or null
void* Unk_583b70(void* manager, const char* path);
void* Unk_583be0(void* manager, const char* path);
// 0x71004c4d00 (leafgen's name and types): a path for the file system, which
// here is the path as it is
const char* Unk_4c4d00_update(u64 path, u64 buffer, u32 size);
// 0x71004cbbb0 (leafgen's name and types)
u32 Unk_4cbbb0_get(u64 buffer, u64 path, u32 size);
// 0x71004c9eb0 (leafgen's name and type): the root directory set for files
u8* Unk_4c9eb0_get();

namespace {

inline SiSDK3::SiIOKernel* Unk_GetIOKernel() {
    return reinterpret_cast<SiSDK3::SiIOKernel*>(Unk_57d030_get());
}

inline void* Unk_GetVFSManager() {
    return reinterpret_cast<void*>(Unk_57d840_get(Unk_57cfb0()));
}

}  // namespace

// A block's header in a stream.
struct Unk_BlockHeader {
    s64 field_0;   // the data's size
    s64 field_8;   // its size in the stream, if field_10 isn't 0
    s32 field_10;  // the codec
    s32 field_14;
    s32 field_18;
    s32 field_1c;
};

// 0x7100582d60
FILE* Unk_582d60(const char* path, const char* mode) {
    return fopen(path, mode);
}

// 0x7100582d70
void Unk_582d70(FILE* file) {
    fclose(file);
}

// 0x7100582d80
bool Unk_582d80(const char* path, bool searchArchives) {
    if (path == nullptr || path[0] == 0) {
        return false;
    }
    if (searchArchives && Unk_GetVFSManager() != nullptr) {
        char buffer[0x400];
        void* manager = Unk_GetVFSManager();
        if (Unk_583b70(manager, Unk_4c4d00_update(reinterpret_cast<u64>(path), reinterpret_cast<u64>(buffer), sizeof(buffer))) != nullptr) {
            return true;
        }
    }
    if (strchr(path, ':') == nullptr) {
        return false;
    }
    nn::fs::DirectoryEntryType type;
    return nn::fs::GetEntryType(&type, path).m_Value == 0;
}

// 0x7100582e30
bool Unk_582e30(const char* path) {
    if (Unk_GetVFSManager() != nullptr) {
        char buffer[0x400];
        void* manager = Unk_GetVFSManager();
        if (Unk_583be0(manager, Unk_4c4d00_update(reinterpret_cast<u64>(path), reinterpret_cast<u64>(buffer), sizeof(buffer))) != nullptr) {
            return true;
        }
    }
    char buffer[0x400];
    Unk_4cbbb0_get(reinterpret_cast<u64>(buffer), reinterpret_cast<u64>(path), sizeof(buffer));
    return true;
}

// 0x7100582eb0
SiSDK3::SiString<char> Unk_582eb0() {
    SiSDK3::SiString<char> result(nullptr);
    const char* root = reinterpret_cast<const char*>(Unk_4c9eb0_get());
    SiSDK3::Unk_StringAssign(&result, static_cast<s32>(Unk_4c4290(root)) > 0 ? root : "/rom:");
    return result;
}

// 0x7100582f10
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment) {
    s64 pos = (alignment + stream->vf17() - 1) & -alignment;
    stream->vf18(pos, false);
    return pos;
}

// 0x7100582f70
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill) {
    s64 pos = stream->vf17();
    s64 end = (alignment + pos - 1) & -alignment;
    if (end > pos) {
        for (s64 i = 0; i < end - pos; i++) {
            stream->vf52(fill, true);
        }
    }
    return end;
}

// 0x7100582ff0
bool Unk_582ff0(SiSDK3::ISiIOStream* stream, const Unk_BlockHeader* header, const void* data, s32 alignment) {
    stream->vf51(header->field_0, true);
    stream->vf51(header->field_8, true);
    stream->vf50(header->field_10, true);
    stream->vf50(header->field_14, true);
    stream->vf50(header->field_18, true);
    stream->vf50(header->field_1c, true);
    Unk_582f70(stream, alignment, 0);
    if (header->field_10 != 0) {
        if (header->field_8 > 0) {
            stream->vf44(data, header->field_8, true);
        }
    } else {
        if (header->field_0 > 0) {
            stream->vf44(data, header->field_0, true);
        }
    }
    return true;
}

// 0x7100583140
bool Unk_583140(SiSDK3::ISiIOStream* stream, Unk_BlockHeader* header, s32 alignment) {
    header->field_0 = stream->vf28(true);
    header->field_8 = stream->vf28(true);
    header->field_10 = stream->vf27(true);
    header->field_14 = stream->vf27(true);
    header->field_18 = stream->vf27(true);
    header->field_1c = stream->vf27(true);
    Unk_582f10(stream, alignment);
    return true;
}

// 0x7100583340: skips a UTF-8 or UTF-16 byte order mark. (The two tests
// become a switch whose comparisons come in the reverse of the source's
// order: the UTF-8 mark's test is written first.)
bool Unk_583340(SiSDK3::ISiIOStream* stream) {
    u8 mark[4];
    stream->vf21(mark, sizeof(mark), false);
    if (mark[0] == 0xef && mark[1] == 0xbb && mark[2] == 0xbf) {
        stream->vf19(3);
        return true;
    }
    if (mark[0] == 0xff && mark[1] == 0xfe) {
        stream->vf19(2);
        return true;
    }
    return false;
}

// A block's data compressed with a codec, if that makes it smaller than ratio
// times its size: the compressed data (also in *buffer, to be freed), else the
// data as it is.
// 0x7100583410
const void* Unk_583410(SiSDK3::ISiAllocator* pAllocator, Unk_BlockHeader* header, const void* data, u32 codec,
                       float ratio, void** buffer) {
    *buffer = nullptr;
    if (data == nullptr || codec == 0) {
        return data;
    }
    SiSDK3::SiIOCodecZLib* pCodec = reinterpret_cast<SiSDK3::SiIOCodecZLib*>(Unk_GetIOKernel()->vf17(codec));
    void* compressed = nullptr;
    if (pCodec != nullptr) {
        s64 size = pCodec->vf5(data, header->field_0);
        if (pAllocator != nullptr) {
#line 2181
            compressed = pAllocator->vf8(1, size, -1, __FILE__, __LINE__);
            if (compressed != nullptr) {
                if (pCodec->vf6(data, header->field_0, compressed, &size)) {
                    if (static_cast<float>(size) < static_cast<float>(header->field_0) * ratio) {
                        header->field_8 = size;
                        data = compressed;
                        header->field_10 = codec;
                    } else {
                        header->field_10 = 0;
#line 2199
                        SI_FREE(pAllocator, compressed);
                        compressed = nullptr;
                    }
                } else {
                    header->field_10 = 0;
#line 2207
                    SI_FREE(pAllocator, compressed);
                    compressed = nullptr;
                }
            }
        }
    }
    *buffer = compressed;
    return data;
}

// A block's data decompressed (also in *buffer, to be freed), and its size.
// 0x7100583580
// NON_MATCHING: registers only: the codec and the result are exchanged
// (x24/x25). Tried: the declarations' order, early returns, nested tests, the
// buffer assigned first, u8*, the kind in a local, one result variable, an else.
// (Round 3: the decompression in a static or non-static inline helper, with
// an early or a nested test, the codec passed directly: no change.)
const void* Unk_583580(SiSDK3::ISiAllocator* pAllocator, const Unk_BlockHeader* header, const void* data,
                       void** buffer, s64* size) {
    *buffer = nullptr;
    *size = header->field_0;
    if (header->field_10 == 0) {
        return data;
    }
    void* decompressed = nullptr;
    SiSDK3::SiIOCodecZLib* pCodec =
        reinterpret_cast<SiSDK3::SiIOCodecZLib*>(Unk_GetIOKernel()->vf17(header->field_10));
    if (pAllocator != nullptr && pCodec != nullptr) {
#line 2257
        decompressed = pAllocator->vf8(1, header->field_0, -1, __FILE__, __LINE__);
        if (decompressed != nullptr) {
            pCodec->vf7(data, header->field_8, decompressed, header->field_0);
            *buffer = decompressed;
            *size = header->field_8;
        }
    }
    return decompressed;
}
