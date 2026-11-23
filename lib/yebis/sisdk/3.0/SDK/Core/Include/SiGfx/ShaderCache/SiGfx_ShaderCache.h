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
    // the destructor's and the constructor's).
    class CompileRequest {
    public:
        // 0x7100577990 (inline: the effect's translation unit has its copy)
        explicit CompileRequest(ISiAllocator* pAllocator)
            : field_8(pAllocator), field_18(0), field_20(0), field_28(0), field_30(0), field_38(0), field_3c(3),
              field_40(0), field_48(0), field_4c(3), field_50(0), field_58(1), field_5c(0), field_60(3),
              field_68(pAllocator), field_98(pAllocator), field_c8(pAllocator), field_f8(pAllocator),
              field_128(pAllocator), field_158(pAllocator), field_188(pAllocator), field_1d8(pAllocator),
              field_228(1), field_230(pAllocator), field_260(pAllocator), field_290(pAllocator),
              field_2c0(pAllocator), field_310(0), field_314(1), field_318(0), field_320(0),
              field_328(pAllocator) {}
        virtual ~CompileRequest();
        UNK_REFCOUNT_DECLARE;
        virtual u32 vf4();

        Unk_4bf660 field_8;
        u64 field_18;
        u64 field_20;
        u64 field_28;
        u64 field_30;
        u32 field_38;
        u32 field_3c;
        u64 field_40;
        u32 field_48;
        u32 field_4c;
        u64 field_50;
        u32 field_58;
        u32 field_5c;
        u32 field_60;
        SiString<char> field_68;
        SiString<char> field_98;
        SiString<char> field_c8;
        SiString<char> field_f8;
        SiString<char> field_128;
        SiString<char> field_158;
        SiArray<SiString<char> > field_188;
        SiArray<SiString<char> > field_1d8;
        u32 field_228;
        SiString<char> field_230;
        SiString<char> field_260;
        SiString<char> field_290;
        SiArray<u8> field_2c0;
        u32 field_310;
        u32 field_314;
        u16 field_318;
        u64 field_320;
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
