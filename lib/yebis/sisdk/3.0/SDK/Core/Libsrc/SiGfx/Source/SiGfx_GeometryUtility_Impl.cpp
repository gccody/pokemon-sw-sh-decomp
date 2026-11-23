// Scope: common
// SiSDK3::SiGfxGeometryUtility: their functions, so far the constructor, the
// destructors and the reference counts their header defines.
#define UNK_SIGFX_GEOMETRYUTILITY_IMPL
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_GeometryUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_VertexFormat_Impl.h>

// 0x71004ed850: writes a vertex element (four floats) in a format
s32 Unk_4ed850(u32 format, void* pElement, const f32* pValue);
// 0x71004ed0c0: a format's bytes per element
s32 Unk_4ed0c0(u32 format);

namespace SiSDK3 {

// 0x71004d3100
SiGfxGeometryUtility::SiGfxGeometryUtility(ISiAllocator* pAllocator) : field_8(pAllocator) {}

// 0x71004d3120 (D2), 0x71004d3140 (D0)
SiGfxGeometryUtility::~SiGfxGeometryUtility() {}

// 0x71004d3d00: the vectors of three are copied as their bytes (12), which is
// what gives the original's 8- and 4-byte copies
// NON_MATCHING: the normal's pointer and offset are in each other's registers
// (x21, x22), and the colour's two stores are the other way round.
void SiGfxGeometryUtility::Unk_4d3d00(u8* vertex, s32 positionOffset, u32 positionFormat, const f32* position,
                                      s32 normalOffset, u32 normalFormat, const f32* normal, s32 texCoordOffset,
                                      u32 texCoordFormat, const f32* texCoord, s32 colorOffset, u32 colorFormat,
                                      const f32* color, s32 tangentOffset, u32 tangentFormat, const f32* tangent) {
    f32 value[4];
    if (positionOffset >= 0 && positionFormat != 0) {
        memcpy(value, position, 12);
        value[3] = 1.0f;
        Unk_4ed850(positionFormat, vertex + positionOffset, value);
    }
    if (normalOffset >= 0 && normalFormat != 0) {
        memcpy(value, normal, 12);
        value[3] = 1.0f;
        Unk_4ed850(normalFormat, vertex + normalOffset, value);
    }
    if (texCoordOffset >= 0 && texCoordFormat != 0) {
        value[0] = texCoord[0];
        value[1] = texCoord[1];
        value[2] = 0.0f;
        value[3] = 1.0f;
        Unk_4ed850(texCoordFormat, vertex + texCoordOffset, value);
    }
    if (colorOffset >= 0 && colorFormat != 0) {
        memcpy(value, color, 12);
        value[3] = color[3];
        Unk_4ed850(colorFormat, vertex + colorOffset, value);
    }
    if (tangentOffset >= 0 && tangentFormat != 0) {
        memcpy(value, tangent, 12);
        value[3] = 1.0f;
        Unk_4ed850(tangentFormat, vertex + tangentOffset, value);
    }
}

// 0x71004d3e30 (the source's address is computed first: a local)
void SiGfxGeometryUtility::Unk_4d3e30(SiGfxNXVertexFormat* pFormat, s32 count, u8* vertices, u32 usage) {
    s32 offset = pFormat->vf28(usage, 0);
    u32 format = pFormat->vf29(usage, 0);
    if (offset < 0 || format == 0) {
        return;
    }
    s32 size = Unk_4ed0c0(format);
    s32 stride = pFormat->vf26(pFormat->vf27(usage, 0));
    if (stride < 1) {
        return;
    }
    for (s32 i = 1; i < 32; i++) {
        s32 otherOffset = pFormat->vf28(usage, i);
        u32 otherFormat = pFormat->vf29(usage, i);
        if (otherOffset < 0 || otherFormat != format) {
            continue;
        }
        for (s32 j = 0; j < count; j++) {
            const u8* src = vertices + j * stride + offset;
            memcpy(vertices + j * stride + otherOffset, src, size);
        }
    }
}

}  // namespace SiSDK3
