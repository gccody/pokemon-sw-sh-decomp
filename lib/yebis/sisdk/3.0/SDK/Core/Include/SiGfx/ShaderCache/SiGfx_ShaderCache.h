// SiSDK3::ISiGfxShaderCache::CompileRequest: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit (UNK_SIGFX_SHADERCACHE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiGfxShaderCache {
public:
    // What a shader's compilation is asked with: its strings (the layout is
    // the destructor's).
    class CompileRequest {
    public:
        virtual ~CompileRequest();
        UNK_REFCOUNT_DECLARE;
        virtual u32 vf4();

        Unk_4bf660 field_8;
        u8 field_18[0x50];
        SiString<char> field_68;
        SiString<char> field_98;
        SiString<char> field_c8;
        SiString<char> field_f8;
        SiString<char> field_128;
        SiString<char> field_158;
        SiArray<SiString<char> > field_188;
        SiArray<SiString<char> > field_1d8;
        u64 field_228;
        SiString<char> field_230;
        SiString<char> field_260;
        SiString<char> field_290;
        SiArray<u8> field_2c0;
        u8 field_310[0x18];
        SiString<char> field_328;
    };
    PKMN_SIZE_ASSERT(CompileRequest, 0x358);
};

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADERCACHE_IMPL
// 0x71005798d0 (vf2), 0x71005798f0 (vf3)
#line 86
UNK_REFCOUNT_DEFINE(SiSDK3::ISiGfxShaderCache::CompileRequest, field_8.m_pAllocator, field_8.m_count)
#endif
