// SiSDK3::SiIONXMemoryMappedFile: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiIONXMemoryMappedFile {
public:
    explicit SiIONXMemoryMappedFile(ISiAllocator* pAllocator);
    virtual ~SiIONXMemoryMappedFile();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(const char* path, u32 mode);  // opens a file
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u8* vf10();  // the file's bytes

    Unk_4bf660 field_8;
    u64 field_18;
    u64 field_20;
    SiString<char> field_28;
    SiString<char> field_58;
    u64 field_88;
};
PKMN_SIZE_ASSERT(SiIONXMemoryMappedFile, 0x90);

}  // namespace SiSDK3

#ifdef UNK_SIIO_NX_MEMORYMAPPEDFILE_IMPL
// 0x710058bd20 (vf2), 0x710058bd40 (vf3)
#line 30
UNK_REFCOUNT_DEFINE(SiSDK3::SiIONXMemoryMappedFile, field_8.m_pAllocator, field_8.m_count)
#endif
