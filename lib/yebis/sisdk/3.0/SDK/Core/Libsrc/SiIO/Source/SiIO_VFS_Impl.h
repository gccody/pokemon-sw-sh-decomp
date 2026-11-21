// SiSDK3::SiIOVFS (RTTI names the class): a mounted archive, the entries of
// the file "SiIOVFS" over a stream. Placeholder members; the virtual
// functions are vf<slot>. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIIO_VFS_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFSEntry_Impl.h>

namespace SiSDK3 {

// A file mapped to memory (SiIONXMemoryMappedFile's interface).
class Unk_MappedFileInterface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();  // releases
    virtual void vf4();
    virtual bool vf5(const char* path, u32 mode);  // opens
    virtual void vf6();                            // closes
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u64 vf10();
};

class SiIOVFS {
public:
    explicit SiIOVFS(ISiAllocator* pAllocator);
    virtual ~SiIOVFS();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(const char* path, const char* root);  // mounts
    virtual void vf6();                                    // unmounts
    virtual u8 vf7();
    virtual u32 vf8();
    virtual u32 vf9();
    virtual bool vf10();  // mounted
    virtual u64 vf11();
    virtual u64 vf12();
    virtual SiIOVFSEntry* vf13(const char* path);  // the file of a path, or null
    virtual SiIOVFSEntry* vf14(const char* path);  // the directory of a path, or null
    virtual u64 vf15();
    virtual u64 vf16();
    virtual void vf17(bool);
    virtual u8 vf18();
    virtual void vf19(const char* s);
    virtual const u8* vf20();
    virtual SiIOVFSEntry* vf21();  // a new entry
    virtual void vf22();
    virtual bool vf23();
    virtual bool vf24();

    // The archive's header.
    struct Unk_Header {
        char field_0[8];  // "SiIOVFS"
        u8 field_8;       // the byte order
        u8 field_9;
        u8 field_a;
        u8 field_b;
        u32 field_c;
        s32 field_10;
        s32 field_14;
        s64 field_18;  // the number of entries
        s64 field_20;
        s64 field_28;
    };

    // 0x71005845e0: reads the header
    bool Unk_5845e0(ISiIOStream* stream, Unk_Header* header);
    // 0x7100584750: reads the entries
    bool Unk_584750(ISiIOStream* stream, Unk_Header* header);
    // 0x71005848c0: reads an entry
    void Unk_5848c0(ISiIOStream* stream, Unk_Header* header, SiIOVFSEntry* entry);
    // 0x7100586260: the number of entries below a directory
    s32 Unk_586260(SiIOVFSEntry* entry);
    // 0x7100586310
    void Unk_586310(SiIOVFSEntry* entry);

    Unk_4bf660 field_8;
    bool field_18;
    bool field_19;
    u16 field_1a;
    s32 field_1c;
    Unk_MappedFileInterface* field_20;  // the archive's file
    SiString<char> field_28;
    SiString<char> field_58;
    SiString<char> field_88;
    SiString<char> field_b8;
    SiIOVFSEntry* field_e8;  // the root directory
    s64 field_f0;
    SiArray<SiIOVFSEntry> field_f8;
    SiArray<SiIOVFSEntry*> field_148;
};
PKMN_SIZE_ASSERT(SiIOVFS, 0x198);
PKMN_OFFSET_ASSERT(SiIOVFS, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(SiIOVFS, field_148, 0x148);

}  // namespace SiSDK3

#ifdef UNK_SIIO_VFS_IMPL
// 0x7100586a50 (vf2), 0x7100586a70 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOVFS, field_8.m_pAllocator, field_8.m_count)
#endif
