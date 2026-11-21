// SiSDK3::SiIOKernel (RTTI names the class): SiIO's factory of streams,
// archives and codecs. Placeholder members; the virtual functions are
// vf<slot>. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIIO_KERNEL_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>

namespace SiSDK3 {

class ISiIOStream;
class ISiIOVFS;  // SiIOVFS's interface (RTTI)
class SiIOBinaryArchive;
class SiIOCodecZLib;
class SiIONXMemoryMappedFile;
class SiIOVFS;
class SiIOVFSManager;

class SiIOKernel {
public:
    SiIOKernel();
    virtual ~SiIOKernel();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5(ISiAllocator* pAllocator);  // sets the allocator
    virtual ISiAllocator* vf6();                 // the allocator
    virtual u64 vf7();
    virtual ISiIOStream* vf8(ISiAllocator* pAllocator);                                 // a memory stream
    virtual ISiIOStream* vf9(const char* path, u32 mode, ISiAllocator* pAllocator);     // a file's stream
    virtual void* vf10(ISiAllocator* pAllocator);
    virtual SiIONXMemoryMappedFile* vf11(ISiAllocator* pAllocator);  // a mapped file
    virtual SiIOBinaryArchive* vf12(ISiAllocator* pAllocator);       // a binary archive
    virtual u32 vf13(u64);
    virtual u64 vf14();
    virtual ISiIOVFS* vf15(ISiAllocator* pAllocator);                  // a mounted archive
    virtual SiIOCodecZLib* vf16(s32 type, ISiAllocator* pAllocator);  // a codec (1: zlib)
    virtual u64 vf17(u32);
    virtual void* vf18(ISiAllocator* pAllocator);  // a CSV document
    // add a chunk handler's type, remove it, and its name and version
    virtual void vf19(const ISiIOBinaryArchive::Unk_Id* id, const char* name, const Unk_567750_Version* version);
    virtual void vf20(const ISiIOBinaryArchive::Unk_Id* id);
    virtual bool vf21(const ISiIOBinaryArchive::Unk_Id* id, SiString<char>* name, Unk_567750_Version* version);

    // A chunk handler's type (RTTI: SiIOKernel::ChunkHandlerTypeInfo), listed
    // in field_50: its identifier, its version and its name (a view of the
    // string it's made with).
    struct ChunkHandlerTypeInfo {
        ChunkHandlerTypeInfo(ISiAllocator* pAllocator, const ISiIOBinaryArchive::Unk_Id& id, const char* name,
                             const Unk_567750_Version& version)
            : m_pPrev(nullptr), m_pNext(nullptr), field_10(id), field_20(version), field_30(pAllocator) {
            field_30.Unk_SetExternal(name);
        }

        ChunkHandlerTypeInfo* m_pPrev;
        ChunkHandlerTypeInfo* m_pNext;
        ISiIOBinaryArchive::Unk_Id field_10;
        Unk_567750_Version field_20;
        SiString<char> field_30;
    };

    Unk_4bf660 field_8;
    ISiAllocator* field_18;
    u32 field_20;  // how many times it was initialised
    u64 field_28;
    u64 field_30;
    u64 field_38;
    SiIOVFSManager* field_40;
    SiIOCodecZLib* field_48;
    // the chunk handler type of an identifier (inline in its callers:
    // placeholder name)
    ChunkHandlerTypeInfo* Unk_FindType(const ISiIOBinaryArchive::Unk_Id* id);

    SiDirectLinkedList<ChunkHandlerTypeInfo*> field_50;
};
PKMN_SIZE_ASSERT(SiIOKernel, 0x78);

}  // namespace SiSDK3

#ifdef UNK_SIIO_KERNEL_IMPL
// 0x710057dc90 (vf2), 0x710057dcb0 (vf3)
#line 35
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOKernel, field_8.m_pAllocator, field_8.m_count)
#endif
