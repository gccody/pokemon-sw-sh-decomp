// SiSDK3::SiIOVFSEntry (RTTI names the class): a file or a directory of a
// mounted archive (SiIOVFS). Placeholder members; the virtual functions are
// vf<slot>. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIIO_VFSENTRY_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

namespace SiSDK3 {

class SiIOVFS;

class SiIOVFSEntry {
public:
    SiIOVFSEntry(ISiAllocator* pAllocator, SiIOVFS* pVFS);
    virtual ~SiIOVFSEntry();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u64 vf5();
    virtual u64 vf6();
    virtual u64 vf7();
    virtual u64 vf8();
    virtual const u8* vf9();
    virtual const u8* vf10();
    virtual bool vf11();  // whether it's a directory
    virtual s64 vf12();                    // the number of entries in field_c8
    virtual SiIOVFSEntry* vf13(s64 index);  // one of them
    virtual SiIOVFSEntry* vf14(s64 index);
    virtual s64 vf15();  // the number of entries in field_118
    virtual SiIOVFSEntry* vf16(s64 index);  // one of them
    virtual SiIOVFSEntry* vf17(s64 index);
    virtual u64 vf18();
    virtual ISiIOStream* vf19();  // a file's stream
    virtual bool vf20(const char* name);  // makes it a directory
    virtual bool vf21(SiIOVFSEntry* entry);  // adds to field_c8
    virtual bool vf22(SiIOVFSEntry* entry);  // adds to field_118
    virtual bool vf23(const char* name, s32 valueB0, u64 value168, s64 size, s64 valueA0);  // makes it a file

    // 0x7100587520: releases the entries below it
    void Unk_587520();

    Unk_4bf660 field_8;
    SiIOVFS* field_18;        // the archive
    SiIOVFSEntry* field_20;   // the directory it's in
    SiString<char> field_28;  // the name
    SiString<char> field_58;
    u32 field_88;
    bool field_8c;
    bool field_8d;
    bool field_8e;
    bool field_8f;
    s64 field_90;  // where the data starts in the archive's stream
    s64 field_98;
    s64 field_a0;
    s64 field_a8;
    s32 field_b0;
    s32 field_b4;
    s64 field_b8;  // its index in the archive's entries
    s64 field_c0;                      // its index in the archive's pointers
    SiArray<SiIOVFSEntry*> field_c8;   // a directory's entries, of one kind
    SiArray<SiIOVFSEntry*> field_118;  // and of the other
    u64 field_168;
};
PKMN_SIZE_ASSERT(SiIOVFSEntry, 0x170);
PKMN_OFFSET_ASSERT(SiIOVFSEntry, field_88, 0x88);
PKMN_OFFSET_ASSERT(SiIOVFSEntry, field_c8, 0xc8);

}  // namespace SiSDK3

#ifdef UNK_SIIO_VFSENTRY_IMPL
// 0x71005879b0 (vf2), 0x71005879d0 (vf3)
#line 33
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOVFSEntry, field_8.m_pAllocator, field_8.m_count)
#endif
