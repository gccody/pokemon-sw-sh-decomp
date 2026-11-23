// SiSDK3::SiGfxGeometryUtility: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
// The virtual functions declared and not defined here or in the .cpp are
// lib/yebis/class's or not decompiled yet (placeholder signatures).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxNXVertexFormat;

class SiGfxGeometryUtility {
public:
    explicit SiGfxGeometryUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxGeometryUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();

    // 0x71004d3d00: writes a vertex's position, normal, texture coordinate,
    // colour and tangent (those with an offset and a format) in their formats
    // (placeholder names; it doesn't read this)
    void Unk_4d3d00(u8* vertex, s32 positionOffset, u32 positionFormat, const f32* position, s32 normalOffset,
                    u32 normalFormat, const f32* normal, s32 texCoordOffset, u32 texCoordFormat,
                    const f32* texCoord, s32 colorOffset, u32 colorFormat, const f32* color, s32 tangentOffset,
                    u32 tangentFormat, const f32* tangent);
    // 0x71004d3e30: copies the vertices' attribute of a usage's first set
    // into its other sets of the same format (placeholder names; it doesn't
    // read this)
    void Unk_4d3e30(SiGfxNXVertexFormat* pFormat, s32 count, u8* vertices, u32 usage);

    Unk_4bf660 field_8;
};

}  // namespace SiSDK3

#ifdef UNK_SIGFX_GEOMETRYUTILITY_IMPL
// 0x71004d9920 (vf2), 0x71004d9940 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxGeometryUtility, field_8.m_pAllocator, field_8.m_count)
#endif
