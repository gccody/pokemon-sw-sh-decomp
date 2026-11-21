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
    virtual void vf19();
    virtual const u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();

    Unk_4bf660 field_8;
    bool field_18;
    bool field_19;
    ISiIOStream* field_20;  // the archive's stream
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
