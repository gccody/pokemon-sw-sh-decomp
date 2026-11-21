// SiSDK3::SiIOBinaryArchive (RTTI names the class): a file of chunks. Its
// layout is its constructor's; placeholder members, the virtual functions are
// vf<slot>. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIIO_BINARYARCHIVE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Version.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>

namespace SiSDK3 {

class SiIOBinaryArchive : public ISiIOBinaryArchive {
public:
    // The file's header (placeholder name).
    struct Unk_Header {
        char field_0[0x40];  // "SSKKArchive"
        u8 field_40;         // the byte order
        u8 field_41[3];
        s32 field_44;        // what the file's parts are aligned to
        char field_48[0x10];
        s64 field_58;  // the header's size
        Unk_567750_Version field_60;
        s64 field_70;
        s64 field_78;
        s64 field_80;
        s64 field_88;
        s64 field_90;
        char field_98[0x10];
        u8 field_a8[8];
    };

    // 0x710057a650
    explicit SiIOBinaryArchive(ISiAllocator* pAllocator);
    ~SiIOBinaryArchive();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(const char* path, u32 platform);
    virtual bool vf6(ISiIOStream* stream, u32 platform);
    virtual bool vf7(SiIONXMemoryMappedFile* file, u32 platform);
    virtual bool vf8();
    virtual const u8* vf9();
    virtual u64 vf10();
    virtual u64 vf11();
    virtual u8* vf12(Unk_ChunkHeader* header);
    virtual u8* vf13(Unk_ChunkHeader* header);
    virtual u8* vf14(Unk_ChunkHeader* header);
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual const u8* vf18();
    virtual bool vf19();
    virtual u32 vf20();
    virtual bool vf21(const char* name, const char* name2, const char* name3, u8 byteOrder);
    virtual bool vf22(ChunkHandler* handler);
    virtual bool vf23(const char* path);
    virtual bool vf24(ISiIOStream* stream);
    virtual bool vf25(const char* name);
    virtual void vf26(u32 value);
    virtual u32 vf27();
    virtual void vf28(u32 value);
    virtual u32 vf29();
    virtual u64 vf30();
    virtual ChunkTypeInfo* vf31(s64 index);
    virtual ChunkTypeInfo* vf32(const Unk_Id* id);
    virtual void vf33();
    virtual u32 vf34();

    // 0x710057b7d0: writes the header, 0x710057bb60: the chunk types
    bool Unk_57b7d0(ISiIOStream* stream);
    bool Unk_57bb60(ISiIOStream* stream);
    // 0x710057bd30: writes a chunk's header, 0x710057b9c0: a chunk and the
    // chunks inside it (first their data, then their headers again)
    bool Unk_57bd30(ISiIOStream* stream, ChunkHandler* handler, bool flag);
    bool Unk_57b9c0(ISiIOStream* stream, ChunkHandler* handler, bool first);
    // 0x710057c090: adds the types of a chunk and of the chunks inside it
    void Unk_57c090(ChunkHandler* handler);

    Unk_4bf660 field_18;
    s64 field_28;  // what the file's parts are aligned to
    Unk_Header field_30;
    u32 field_e0;
    u8* field_e8;   // the file's bytes
    u8* field_f0;
    bool field_f8;  // whether field_e8 is the archive's own
    bool field_f9;  // whether field_100 is
    u8 field_fa[5];
    SiIONXMemoryMappedFile* field_100;
    SiDirectLinkedList<ChunkHandler*> field_108;  // the chunks
    SiString<char> field_130;                     // the last error
    u32 field_160;
    ChunkTypeInfo* field_168;  // the chunk types of an opened file
    SiArray<ChunkTypeInfo> field_170;
    s32 field_1c0;  // its number
};
PKMN_SIZE_ASSERT(SiIOBinaryArchive, 0x1c8);
PKMN_SIZE_ASSERT(SiIOBinaryArchive::Unk_Header, 0xb0);
PKMN_OFFSET_ASSERT(SiIOBinaryArchive, field_108, 0x108);
PKMN_OFFSET_ASSERT(SiIOBinaryArchive, field_170, 0x170);

}  // namespace SiSDK3

#ifdef UNK_SIIO_BINARYARCHIVE_IMPL
// 0x710057c5d0 (vf2), 0x710057c5f0 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOBinaryArchive, field_18.m_pAllocator, field_18.m_count)
#endif
