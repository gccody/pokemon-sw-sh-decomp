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
class SiGfxNXBuffer;

// What the generators tell of the shape they made (placeholder name and
// members): a box around it.
struct Unk_GeometryBounds {
    s32 field_0;  // 1: the box is set
    f32 field_4[3];   // its lowest corner
    f32 field_10[3];  // its highest corner
};
PKMN_SIZE_ASSERT(Unk_GeometryBounds, 0x1c);

class SiGfxGeometryUtility {
public:
    explicit SiGfxGeometryUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxGeometryUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    // 0x71004d3190: a box of a width, a height and a depth around the origin,
    // four vertices per face, with tangents (placeholder parameter names)
    virtual bool vf5(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                     f32 width, f32 height, f32 depth, Unk_GeometryBounds* pBounds);
    // 0x71004d41f0: an ellipsoid of three radii, slices around and stacks
    // from pole to pole, with tangents (placeholder parameter names)
    virtual bool vf6(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                     f32 radiusX, f32 radiusY, f32 radiusZ, s32 slices, s32 stacks, Unk_GeometryBounds* pBounds);
    // 0x71004d4bd0: the lines of an ellipsoid of three radii, slices
    // meridians and stacks - 1 circles of latitude (placeholder parameter names)
    virtual bool vf7(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                     f32 radiusX, f32 radiusY, f32 radiusZ, s32 slices, s32 stacks, Unk_GeometryBounds* pBounds);
    // 0x71004d55e0: a cylinder or truncated cone of a bottom and a top radius
    // and a height, slices around and stacks up, closed by a disc where a
    // radius is positive (placeholder parameter names)
    virtual bool vf8(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                     f32 bottomRadius, f32 topRadius, f32 height, s32 slices, s32 stacks,
                     Unk_GeometryBounds* pBounds);
    // 0x71004d64d0: a torus of a radius and a tube radius, sides around the
    // tube and rings around the axis (placeholder parameter names)
    virtual bool vf9(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                     f32 radius, f32 tubeRadius, s32 sides, s32 rings, Unk_GeometryBounds* pBounds);
    // 0x71004d6cb0: a rectangle of a width and a height around the origin
    // in the xy plane, facing z
    virtual bool vf10(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                      f32 width, f32 height, Unk_GeometryBounds* pBounds);
    // 0x71004d7330: a cone: a ring of a number of segments at a radius
    // and a height around a vertex at the origin (placeholder parameter names)
    virtual bool vf11(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                      f32 radius, f32 height, s32 segments, Unk_GeometryBounds* pBounds);
    // 0x71004d7a50: a half sphere of a radius, a number of slices around and
    // of stacks from its rim to its top (placeholder parameter names)
    virtual bool vf12(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                      f32 radius, s32 slices, s32 stacks, Unk_GeometryBounds* pBounds);
    // 0x71004d8260: the lines of a circle of a radius in the xz plane, of a
    // number of segments (placeholder parameter names)
    virtual bool vf13(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                      f32 radius, s32 segments, Unk_GeometryBounds* pBounds);
    // 0x71004d8c70: a capsule of a radius and a height between its two half
    // spheres' centres, slices around and stacks per half sphere (placeholder
    // parameter names)
    virtual bool vf14(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer, SiGfxNXBuffer* pIndexBuffer,
                      f32 radius, f32 height, s32 slices, s32 stacks, Unk_GeometryBounds* pBounds);

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
