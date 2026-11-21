// Scope: common
// SiSDK3::SiIOBinaryArchive: its construction, its header's and chunks'
// writers and its small functions (the readers and the destructor aren't
// written yet).
#define UNK_SIIO_BINARYARCHIVE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_BinaryArchive_Impl.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/NX/SiIO_NX_MemoryMappedFile_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x71004c5520: copies a string into a buffer, 0x71004c5630: compares
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);
s64 Unk_4c5630(const char* a, const char* b, bool);
// 0x71004c9090: formats a string
void Unk_4c9090(SiSDK3::SiString<char>* self, const char* format, ...);
// 0x71004c8f80: whether two identifiers are the same
bool Unk_4c8f80(const void* a, const void* b);
// 0x7100582f70: fills up to a multiple of alignment
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);
// 0x710057d030: SiIO's kernel as a number (leafgen's name and type)
u64 Unk_57d030_get();
// 0x71027705c8: how many archives were made
static s32 Unk_27705c8;

namespace SiSDK3 {

namespace {

// the index of an identifier among count chunk types (inline in its callers:
// placeholder name)
inline s32 Unk_FindType(ISiIOBinaryArchive::ChunkTypeInfo* infos, s32 count, const ISiIOBinaryArchive::Unk_Id* id) {
    for (s32 i = 0; i < count; i++) {
        if (Unk_4c8f80(&infos[i], id)) {
            return i;
        }
    }
    return -1;
}

}  // namespace

// 0x710057a650
SiIOBinaryArchive::SiIOBinaryArchive(ISiAllocator* pAllocator)
    : field_18(pAllocator), field_28(0x10), field_e0(7), field_e8(nullptr), field_f0(nullptr), field_f8(false),
      field_f9(false), field_100(nullptr), field_108(pAllocator), field_130(pAllocator), field_160(0),
      field_168(nullptr), field_170(pAllocator), field_1c0(0) {
    field_1c0 = __atomic_add_fetch(&Unk_27705c8, 1, __ATOMIC_SEQ_CST);
    memset(field_fa, 0, sizeof(field_fa));
    memset(&field_30, 0, sizeof(field_30));
    Unk_4c5520(field_30.field_0, sizeof(field_30.field_0), "SSKKArchive", -1);
    field_30.field_40 = 1;
    field_30.field_60.field_0 = 3;
    field_30.field_60.field_4 = 0;
    field_30.field_60.field_8 = 0;
    field_30.field_60.field_c = 0x9d;
    field_30.field_44 = field_28;
}

// 0x710057a7f0 (D2), 0x710057aac0 (D0)
SiIOBinaryArchive::~SiIOBinaryArchive() {
    SiIOBinaryArchive::vf8();
    while (field_108.m_count != 0) {
        ChunkHandler* handler = field_108.m_pHead;
        if (handler != nullptr) {
            field_108.Remove(handler);
            handler->vf3();
        }
    }
}

// 0x710057aaf0
bool SiIOBinaryArchive::vf5(const char* path, u32 platform) {
    Unk_StringAssign(&field_130, "");
    SiIONXMemoryMappedFile* file = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf11(nullptr);
    if (file == nullptr) {
        Unk_4c9090(&field_130, "SiIOBinaryArchive::Open --> Failed to create MemoryMapped file %s", path);
        return false;
    }
    if (!file->vf5(path, 9)) {
        file->vf3();
        Unk_4c9090(&field_130, "SiIOBinaryArchive::Open --> Failed to open file %s", path);
        return false;
    }
    if (!vf7(file, platform)) {
        file->vf3();
        Unk_4c9090(&field_130, "SiIOBinaryArchive::Open --> Failed to open file as BinaryArchive %s", path);
        return false;
    }
    field_f9 = true;
    field_100 = file;
    return true;
}

// 0x710057af40
bool SiIOBinaryArchive::vf8() {
    if (field_e8 != nullptr) {
        if (field_f8) {
#line 650
            SI_FREE(field_18.m_pAllocator, field_e8);
            field_e8 = nullptr;
            field_f8 = false;
        }
        if (field_f9 && field_100 != nullptr) {
            field_100->vf3();
            field_100 = nullptr;
        }
        field_f0 = nullptr;
    }
    field_168 = nullptr;
    return true;
}

// 0x710057afe0
u8* SiIOBinaryArchive::vf12(Unk_ChunkHeader* header) {
    if (header == nullptr) {
        return nullptr;
    }
    if (header->field_38 < 1) {
        return nullptr;
    }
    return field_e8 + header->field_38;
}

// 0x710057b010
u8* SiIOBinaryArchive::vf13(Unk_ChunkHeader* header) {
    if (header == nullptr) {
        return nullptr;
    }
    if (header->field_40 < 1) {
        return nullptr;
    }
    return field_e8 + header->field_40;
}

// 0x710057b040
u8* SiIOBinaryArchive::vf14(Unk_ChunkHeader* header) {
    if (header == nullptr) {
        return nullptr;
    }
    if (header->field_50 < 1) {
        return nullptr;
    }
    return field_e8 + header->field_50;
}

// 0x710057b470
bool SiIOBinaryArchive::vf21(const char* name, const char* name2, const char* name3, u8 byteOrder) {
    Unk_4c5520(field_30.field_0, sizeof(field_30.field_0) - 1, name, -1);
    Unk_4c5520(field_30.field_48, sizeof(field_30.field_48) - 1, name3, -1);
    Unk_4c5520(field_30.field_98, sizeof(field_30.field_98) - 1, name2, -1);
    field_30.field_40 = byteOrder;
    return true;
}

// 0x710057b500
bool SiIOBinaryArchive::vf22(ChunkHandler* handler) {
    if (handler == nullptr) {
        return false;
    }
    field_108.AddTail(handler);
    handler->vf2();
    return true;
}

// 0x710057b560
bool SiIOBinaryArchive::vf23(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x15, nullptr);
    if (stream == nullptr) {
        Unk_4c9090(&field_130, "SiIOBinaryArchive::Save --> Failed to open file", path);
        return false;
    }
    bool result = vf24(stream);
    stream->vf3();
    return result;
}

// 0x710057b600
bool SiIOBinaryArchive::vf24(ISiIOStream* stream) {
    stream->vf18(0, false);
    s64 start = stream->vf17();
    Unk_57b7d0(stream);
    field_30.field_80 = Unk_582f70(stream, field_28, 0);
    for (ChunkHandler* handler = field_108.m_pHead; handler != nullptr; handler = handler->m_pNext) {
        if (!Unk_57b9c0(stream, handler, true)) {
            Unk_4c9090(&field_130, "SiIOBinaryArchive::Save --> Failed to save chunk");
            return false;
        }
        if (handler->m_pNext != nullptr) {
            handler->field_28.field_40 = Unk_582f70(stream, field_28, 0);
        }
    }
    s64 end = stream->vf17();
    stream->vf18(0, false);
    if (field_108.m_count != 0) {
        for (ChunkHandler* handler = field_108.m_pHead; handler != nullptr; handler = handler->m_pNext) {
            Unk_57c090(handler);
        }
    }
    field_30.field_88 = end;
    field_30.field_90 = field_170.m_itemCount;
    field_30.field_70 = end - start + field_170.m_itemCount * sizeof(ChunkTypeInfo);
    Unk_57b7d0(stream);
    stream->vf18(field_30.field_80, false);
    for (ChunkHandler* handler = field_108.m_pHead; handler != nullptr; handler = handler->m_pNext) {
        if (!Unk_57b9c0(stream, handler, false)) {
            Unk_4c9090(&field_130, "SiIOBinaryArchive::Save --> Failed to save chunk");
            return false;
        }
        if (handler->m_pNext != nullptr) {
            stream->vf18(handler->field_28.field_40, false);
        }
    }
    stream->vf18(end, false);
    Unk_57bb60(stream);
    return true;
}

// 0x710057b7d0
bool SiIOBinaryArchive::Unk_57b7d0(ISiIOStream* stream) {
    stream->vf13(field_30.field_40);
    stream->vf44(field_30.field_0, sizeof(field_30.field_0), true);
    stream->vf52(field_30.field_40, true);
    stream->vf44(field_30.field_41, sizeof(field_30.field_41), true);
    stream->vf50(field_30.field_44, true);
    stream->vf44(field_30.field_48, sizeof(field_30.field_48), true);
    stream->vf51(field_30.field_58, true);
    stream->vf50(field_30.field_60.field_0, true);
    stream->vf50(field_30.field_60.field_4, true);
    stream->vf50(field_30.field_60.field_8, true);
    stream->vf50(field_30.field_60.field_c, true);
    stream->vf51(field_30.field_70, true);
    stream->vf51(field_30.field_78, true);
    stream->vf51(field_30.field_80, true);
    stream->vf51(field_30.field_88, true);
    stream->vf51(field_30.field_90, true);
    stream->vf44(field_30.field_98, sizeof(field_30.field_98), true);
    stream->vf44(field_30.field_a8, sizeof(field_30.field_a8), true);
    return true;
}

// 0x710057b9c0
// NON_MATCHING: the original passes the header writer its last argument (`mov w3, wzr`),
// which that function doesn't use in the end: here its callers leave it out.
bool SiIOBinaryArchive::Unk_57b9c0(ISiIOStream* stream, ChunkHandler* handler, bool first) {
    Unk_57bd30(stream, handler, false);
    if (first) {
        s64 start = Unk_582f70(stream, field_28, 0);
        if (!handler->vf6(this, stream)) {
            Unk_4c9090(&field_130, "SiIOBinaryArchive::WriteChunkHandler --> Failed to write chunk header");
            return false;
        }
        s64 size = stream->vf17() - start;
        handler->field_28.field_28 = size;
        if (size >= 1) {
            handler->field_28.field_38 = start;
        }
        if (handler->field_88.m_count >= 1) {
            handler->field_28.field_50 = Unk_582f70(stream, field_28, 0);
            for (ChunkHandler* child = handler->field_88.m_pHead; child != nullptr; child = child->m_pNext) {
                Unk_57b9c0(stream, child, true);
                if (child->m_pNext != nullptr) {
                    child->field_28.field_40 = Unk_582f70(stream, field_28, 0);
                }
            }
        }
        handler->field_28.field_30 = stream->vf17() - start;
    } else {
        if (handler->field_28.field_48 >= 1) {
            stream->vf18(handler->field_28.field_50, false);
            for (ChunkHandler* child = handler->field_88.m_pHead; child != nullptr; child = child->m_pNext) {
                Unk_57b9c0(stream, child, false);
                if (child->m_pNext != nullptr) {
                    stream->vf18(child->field_28.field_40, false);
                }
            }
        }
    }
    return true;
}

// 0x710057bb60
bool SiIOBinaryArchive::Unk_57bb60(ISiIOStream* stream) {
    for (s64 i = 0; i < static_cast<s32>(field_170.m_itemCount); i++) {
        ChunkTypeInfo* info = &field_170.m_pData[i];
        stream->vf54(info->field_0.field_0, true);
        stream->vf53(info->field_0.field_4, true);
        stream->vf53(info->field_0.field_6, true);
        stream->vf52(info->field_0.field_8[0], true);
        stream->vf52(info->field_0.field_8[1], true);
        stream->vf52(info->field_0.field_8[2], true);
        stream->vf52(info->field_0.field_8[3], true);
        stream->vf52(info->field_0.field_8[4], true);
        stream->vf52(info->field_0.field_8[5], true);
        stream->vf52(info->field_0.field_8[6], true);
        stream->vf52(info->field_0.field_8[7], true);
        stream->vf50(info->field_10.field_0, true);
        stream->vf50(info->field_10.field_4, true);
        stream->vf50(info->field_10.field_8, true);
        stream->vf50(info->field_10.field_c, true);
    }
    return true;
}

// 0x710057bd30
bool SiIOBinaryArchive::Unk_57bd30(ISiIOStream* stream, ChunkHandler* handler, bool flag) {
    handler->field_28.field_20 = sizeof(Unk_ChunkHeader);
    handler->field_28.field_48 = handler->field_88.m_count;
    stream->vf54(handler->field_28.field_0.field_0, true);
    stream->vf53(handler->field_28.field_0.field_4, true);
    stream->vf53(handler->field_28.field_0.field_6, true);
    stream->vf44(handler->field_28.field_0.field_8, sizeof(handler->field_28.field_0.field_8), true);
    stream->vf50(handler->field_28.field_10.field_0, true);
    stream->vf50(handler->field_28.field_10.field_4, true);
    stream->vf50(handler->field_28.field_10.field_8, true);
    stream->vf50(handler->field_28.field_10.field_c, true);
    stream->vf51(handler->field_28.field_20, true);
    stream->vf51(handler->field_28.field_28, true);
    stream->vf51(handler->field_28.field_30, true);
    stream->vf51(handler->field_28.field_38, true);
    stream->vf51(handler->field_28.field_40, true);
    stream->vf51(handler->field_28.field_48, true);
    stream->vf51(handler->field_28.field_50, true);
    stream->vf51(handler->field_28.field_58, true);
    return true;
}

// 0x710057bf00
bool SiIOBinaryArchive::vf25(const char* name) {
    return Unk_4c5630(field_30.field_98, name, true) == 0;
}

// 0x710057bf80
ISiIOBinaryArchive::ChunkTypeInfo* SiIOBinaryArchive::vf31(s64 index) {
    if (field_168 != nullptr) {
        return &field_168[index];
    }
    if (field_170.m_itemCount != 0) {
        return &field_170.m_pData[index];
    }
    return nullptr;
}

// 0x710057bfb0
ISiIOBinaryArchive::ChunkTypeInfo* SiIOBinaryArchive::vf32(const Unk_Id* id) {
    if (field_168 != nullptr) {
        s32 index = Unk_FindType(field_168, field_30.field_90, id);
        if (index >= 0) {
            return &field_168[index];
        }
    } else if (field_170.m_itemCount != 0) {
        s32 index = Unk_FindType(field_170.m_pData, field_170.m_itemCount, id);
        if (index >= 0) {
            return &field_170.m_pData[index];
        }
    }
    return nullptr;
}

// 0x710057c090
void SiIOBinaryArchive::Unk_57c090(ChunkHandler* handler) {
    if (Unk_FindType(field_170.m_pData, field_170.m_itemCount, &handler->field_28.field_0) < 0) {
        ChunkTypeInfo info;
        info.field_0 = handler->field_28.field_0;
        info.field_10 = handler->field_28.field_10;
        field_170.Unk_Add(info);
    }
    for (ChunkHandler* child = handler->field_88.m_pHead; child != nullptr; child = child->m_pNext) {
        Unk_57c090(child);
    }
}

}  // namespace SiSDK3
