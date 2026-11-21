// SiSDK3::ISiIOBinaryArchive, SiSDK3::ISiIOBinaryArchive::ChunkHandler and
// SiSDK3::ISiIOBinaryArchive::ChunkTypeInfo (RTTI names the classes), as far
// as SiIOBinaryArchive's functions show them, with placeholder members; the
// virtual functions are vf<slot>. The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the translation unit
// that has them (UNK_ISIIO_BINARYARCHIVE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Version.h>

namespace SiSDK3 {

class ISiIOStream;
class SiIONXMemoryMappedFile;
template <class T>
class SiString;

class ISiIOBinaryArchive {
public:
    // A chunk's or a chunk type's identifier (placeholder name): 16 bytes,
    // written as a number, two short ones and eight bytes.
    struct Unk_Id {
        u32 field_0;
        u16 field_4;
        u16 field_6;
        u8 field_8[8];
    };

    // A chunk's header in the file (placeholder name): field_20 is its own
    // size, the numbers from field_28 on are sizes and offsets in the file.
    struct Unk_ChunkHeader {
        Unk_Id field_0;
        Unk_567750_Version field_10;
        s64 field_20;
        s64 field_28;
        s64 field_30;
        s64 field_38;
        s64 field_40;
        s64 field_48;  // the number of chunks inside it
        s64 field_50;
        s64 field_58;
    };

    // A chunk type of an archive (RTTI: the element of the archive's array).
    struct ChunkTypeInfo {
        Unk_Id field_0;
        Unk_567750_Version field_10;
    };

    // A chunk: its links in the list it's in, its header and the chunks
    // inside it. Slot 6 writes its data; slots 7 to 9 read it from an archive
    // (7 checks its header, 8 reads its data, 9 the chunks inside it). Its
    // destructor releases the chunks inside it; the class is abstract (its
    // deleting destructor is a trap).
    class ChunkHandler {
    public:
        virtual ~ChunkHandler() {
            while (field_88.m_count != 0) {
                ChunkHandler* handler = field_88.m_pHead;
                if (handler != nullptr) {
                    field_88.Remove(handler);
                    handler->vf3();
                }
            }
        }
        UNK_REFCOUNT_DECLARE;
        virtual u32 vf4();
        virtual void vf5() = 0;
        virtual bool vf6(ISiIOBinaryArchive* archive, ISiIOStream* stream) = 0;
        virtual bool vf7(ISiIOBinaryArchive* archive, Unk_ChunkHeader* header, SiString<char>* error) = 0;
        virtual bool vf8(ISiIOBinaryArchive* archive, Unk_ChunkHeader* header, ISiIOStream* stream) = 0;
        virtual bool vf9(ISiIOBinaryArchive* archive, Unk_ChunkHeader* header, ISiIOStream* stream) = 0;

        Unk_4bf660 field_8;
        ChunkHandler* m_pPrev;
        ChunkHandler* m_pNext;
        Unk_ChunkHeader field_28;
        SiDirectLinkedList<ChunkHandler*> field_88;
        s32 field_b0;  // the number of the archive it was read from
    };

    ISiIOBinaryArchive() : field_8(nullptr) {}
    virtual ~ISiIOBinaryArchive() {}
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(const char* path, u32 platform) = 0;                  // opens a file
    virtual bool vf6(ISiIOStream* stream, u32 platform) = 0;               // opens a stream
    virtual bool vf7(SiIONXMemoryMappedFile* file, u32 platform) = 0;      // opens a mapped file
    virtual bool vf8() = 0;                                             // closes
    virtual const u8* vf9() = 0;                                        // the header
    virtual u64 vf10() = 0;
    virtual Unk_ChunkHeader* vf11() = 0;  // the first chunk
    // a chunk's data, the chunk after it and the first one inside it
    virtual u8* vf12(Unk_ChunkHeader* header) = 0;
    virtual Unk_ChunkHeader* vf13(Unk_ChunkHeader* header) = 0;
    virtual Unk_ChunkHeader* vf14(Unk_ChunkHeader* header) = 0;
    // the chunk of an identifier, or of one of count, after start (among the
    // chunks inside them too if inside)
    virtual Unk_ChunkHeader* vf15(const Unk_Id* id, Unk_ChunkHeader* start, bool inside) = 0;
    virtual Unk_ChunkHeader* vf16(s32 count, const Unk_Id* ids, Unk_ChunkHeader* start, bool inside) = 0;
    virtual bool vf17(Unk_ChunkHeader* header, ChunkHandler* handler) = 0;  // reads a chunk
    virtual const u8* vf18() = 0;  // the last error
    virtual bool vf19() = 0;
    virtual u32 vf20() = 0;
    virtual bool vf21(const char* name, const char* name2, const char* name3, u8 byteOrder) = 0;
    virtual bool vf22(ChunkHandler* handler) = 0;  // adds a chunk
    virtual bool vf23(const char* path) = 0;       // writes a file
    virtual bool vf24(ISiIOStream* stream) = 0;    // writes to a stream
    virtual bool vf25(const char* name) = 0;
    virtual void vf26(u32 value) = 0;
    virtual u32 vf27() = 0;
    virtual void vf28(u32 value) = 0;
    virtual u32 vf29() = 0;
    virtual u64 vf30() = 0;
    virtual ChunkTypeInfo* vf31(s64 index) = 0;  // a chunk type
    virtual ChunkTypeInfo* vf32(const Unk_Id* id) = 0;  // the chunk type of an identifier
    virtual void vf33() = 0;
    virtual u32 vf34() = 0;

    Unk_4bf660 field_8;
};
PKMN_SIZE_ASSERT(ISiIOBinaryArchive::Unk_ChunkHeader, 0x60);
PKMN_SIZE_ASSERT(ISiIOBinaryArchive::ChunkTypeInfo, 0x20);
PKMN_SIZE_ASSERT(ISiIOBinaryArchive::ChunkHandler, 0xb8);

}  // namespace SiSDK3

#ifdef UNK_ISIIO_BINARYARCHIVE_IMPL
// 0x71004f1020 (vf2), 0x71004f1040 (vf3)
#line 211
UNK_REFCOUNT_DEFINE(SiSDK3::ISiIOBinaryArchive::ChunkHandler, field_8.m_pAllocator, field_8.m_count)

// 0x710057c6b0 (vf2), 0x710057c6d0 (vf3)
#line 112
UNK_REFCOUNT_DEFINE(SiSDK3::ISiIOBinaryArchive, field_8.m_pAllocator, field_8.m_count)
#endif
