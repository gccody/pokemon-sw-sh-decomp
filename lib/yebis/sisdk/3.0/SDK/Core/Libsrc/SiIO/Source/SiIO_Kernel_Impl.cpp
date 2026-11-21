// Scope: common
// SiSDK3::SiIOKernel: the factory methods (the constructor, the destructors,
// the initialisation and the chunk handler types aren't written yet).
#define UNK_SIIO_KERNEL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/NX/SiIO_NX_FileStream_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/NX/SiIO_NX_MemoryMappedFile_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_BinaryArchive_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Codec_ZLib_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_MemoryStream_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFSManager_Impl.h>

// 0x710057e080: a new CSV document
void* Unk_57e080(SiSDK3::ISiAllocator* pAllocator);

// 0x71004c8f80: whether two identifiers are the same
bool Unk_4c8f80(const void* a, const void* b);

namespace SiSDK3 {

// 0x710057d590
void SiIOKernel::vf5(ISiAllocator* pAllocator) {
    if (pAllocator != nullptr) {
        pAllocator->vf2();
    }
    if (field_18 != nullptr) {
        field_18->vf3();
    }
    field_18 = pAllocator;
}

// 0x710057d600
ISiIOStream* SiIOKernel::vf8(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
#line 263
    return reinterpret_cast<ISiIOStream*>(UNK_SI_NEW(pAllocator, 0x10) SiIOMemoryStream(pAllocator));
}

// 0x710057d670
ISiIOStream* SiIOKernel::vf9(const char* path, u32 mode, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
#line 291
    SiIONXFileStream* stream = UNK_SI_NEW(pAllocator, 0x10) SiIONXFileStream(pAllocator);
    if (stream == nullptr) {
        return nullptr;
    }
    if (path != nullptr) {
        if (!stream->vf6(path, mode == 0 ? 9 : mode, 0)) {
            stream->vf3();
            stream = nullptr;
        }
    }
    return reinterpret_cast<ISiIOStream*>(stream);
}

// 0x710057d730
void* SiIOKernel::vf10(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
    return nullptr;
}

// 0x710057d760
SiIONXMemoryMappedFile* SiIOKernel::vf11(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
#line 362
    return UNK_SI_NEW(pAllocator, 0x10) SiIONXMemoryMappedFile(pAllocator);
}

// 0x710057d7d0
SiIOBinaryArchive* SiIOKernel::vf12(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
#line 383
    return UNK_SI_NEW(pAllocator, 0x10) SiIOBinaryArchive(pAllocator);
}

// 0x710057d870
// (the result is the archive as its interface: with a pointer of another
// type between the call and the return, the call isn't a tail call)
ISiIOVFS* SiIOKernel::vf15(ISiAllocator* pAllocator) {
    if (field_40 == nullptr) {
        return nullptr;
    }
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
    return reinterpret_cast<ISiIOVFS*>(field_40->Unk_583980(pAllocator));
}

// 0x710057d8c0
SiIOCodecZLib* SiIOKernel::vf16(s32 type, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
    if (type != 1) {
        return nullptr;
    }
#line 504
    return UNK_SI_NEW(pAllocator, 0x10) SiIOCodecZLib(pAllocator);
}

// 0x710057d970
void* SiIOKernel::vf18(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
    return Unk_57e080(pAllocator);
}

// 0x710057d9a0
void SiIOKernel::vf19(const ISiIOBinaryArchive::Unk_Id* id, const char* name, const Unk_567750_Version* version) {
#line 588
    ChunkHandlerTypeInfo* info = UNK_SI_NEW(vf6(), 0x10) ChunkHandlerTypeInfo(vf6(), *id, name, *version);
    field_50.AddTail(info);
}

inline SiIOKernel::ChunkHandlerTypeInfo* SiIOKernel::Unk_FindType(const ISiIOBinaryArchive::Unk_Id* id) {
    for (ChunkHandlerTypeInfo* info = field_50.m_pHead; info != nullptr; info = info->m_pNext) {
        if (Unk_4c8f80(&info->field_10, id)) {
            return info;
        }
    }
    return nullptr;
}

// 0x710057dad0
void SiIOKernel::vf20(const ISiIOBinaryArchive::Unk_Id* id) {
    ChunkHandlerTypeInfo* info = Unk_FindType(id);
    if (info != nullptr) {
        field_50.Remove(info);
#line 610
        SI_DELETE(vf6(), info);
    }
}

// 0x710057dc10
bool SiIOKernel::vf21(const ISiIOBinaryArchive::Unk_Id* id, SiString<char>* name, Unk_567750_Version* version) {
    bool result = false;
    for (ChunkHandlerTypeInfo* info = field_50.m_pHead; info != nullptr; info = info->m_pNext) {
        if (Unk_4c8f80(&info->field_10, id)) {
            *name = info->field_30;
            *version = info->field_20;
            result = true;
            break;
        }
    }
    return result;
}

}  // namespace SiSDK3
