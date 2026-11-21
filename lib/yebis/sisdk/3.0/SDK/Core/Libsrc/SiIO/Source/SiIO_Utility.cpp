// Scope: common
// SiIO's file and stream helpers: the functions between SiIOMemoryStream's
// and SiIOVFSManager's (0x7100582d60 to 0x7100583760). SiIO_Utility.cpp is
// the __FILE__ of the last two, which aren't written yet (0x7100583410,
// 0x7100583580: a block's compression and decompression); placeholder names.
#include <stdio.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

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

// 0x7100583340
// NON_MATCHING: the original tests the first byte against 0xff, then against 0xef; here the two
// tests become a switch, which compares in the cases' order (0xef first).
bool Unk_583340(SiSDK3::ISiIOStream* stream) {
    u8 mark[4];
    stream->vf21(mark, sizeof(mark), false);
    if (mark[0] == 0xff && mark[1] == 0xfe) {
        stream->vf19(2);
        return true;
    }
    if (mark[0] == 0xef && mark[1] == 0xbb && mark[2] == 0xbf) {
        stream->vf19(3);
        return true;
    }
    return false;
}
