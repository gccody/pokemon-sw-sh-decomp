// Scope: common
// SiSDK3::SiGfxGeometryUtility: its constructor and destructors, the
// generators of its virtual functions 5 to 14 (they fill a vertex buffer and
// an index buffer with a shape) and their helpers; the reference counts are
// its header's.
#define UNK_SIGFX_GEOMETRYUTILITY_IMPL
#include <math.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_GeometryUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_VertexFormat_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiMath/Unk_Matrix.h>

// 0x71004ed850: writes a vertex element (four floats) in a format
s32 Unk_4ed850(u32 format, void* pElement, const f32* pValue);
// 0x71004ed0c0: a format's bytes per element
s32 Unk_4ed0c0(u32 format);
// 0x71004ed780: writes a primitive's indices
void Unk_4ed780(u32 kind, bool is32, void* pIndices, s32 index, u32 a, u32 b, u32 c);

// 0x7101f072dc: the smallest length a vector is scaled from (placeholder name)
extern const f32 Unk_1f072dc;

// The free of a buffer that may be null (placeholder name)
#define UNK_SAFE_FREE(allocator, p) if ((p) != nullptr) { UNK_FREE(allocator, p); }

namespace SiSDK3 {
// Where a vertex has an attribute and in which format (placeholder name). A
// generator's attribute it doesn't look up stays 0, 0 (no attribute); written
// through these, the calls of Unk_4d3d00 aren't inlined where they pass those.
struct Unk_VertexAttribute {
    s32 offset;
    u32 format;
    Unk_VertexAttribute() : offset(0), format(0) {}
};
PKMN_SIZE_ASSERT(Unk_VertexAttribute, 0x8);

// A vector of three scaled by its largest component and then to a length of
// one (placeholder name; inline in the generators). Taking the array by
// reference lets the loads of its elements be forwarded from the caller's
// stores early, which keeps vf13's loop small enough to be unswitched.
static inline void Unk_Normalize(f32 (&v)[4]) {
    f32 x = v[0] > 0.0f ? v[0] : -v[0];
    f32 y = v[1] > 0.0f ? v[1] : -v[1];
    f32 z = v[2] > 0.0f ? v[2] : -v[2];
    f32 m = x > y ? x : y;
    m = m > z ? m : z;
    if (m == 0.0f || m < Unk_1f072dc) {
        return;
    }
    f32 inverse = 1.0f / m;
    v[0] *= inverse;
    v[1] *= inverse;
    v[2] *= inverse;
    f32 length = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (length == 0.0f) {
        return;
    }
    inverse = 1.0f / length;
    v[0] *= inverse;
    v[1] *= inverse;
    v[2] *= inverse;
}

// 0x71004d3100
SiGfxGeometryUtility::SiGfxGeometryUtility(ISiAllocator* pAllocator) : field_8(pAllocator) {}

// 0x71004d3120 (D2), 0x71004d3140 (D0)
SiGfxGeometryUtility::~SiGfxGeometryUtility() {}

// 0x71004d3190: the corners, the faces' normals and tangents and the corners'
// texture coordinates are local tables; the faces' corners are a constant one
// NON_MATCHING: the registers and the spill slots differ (the original keeps
// other values in the callee-saved registers), and the faces' loop's two
// versions (with and without the tangent) are laid out otherwise.
bool SiGfxGeometryUtility::vf5(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                               SiGfxNXBuffer* pIndexBuffer, f32 width, f32 height, f32 depth,
                               Unk_GeometryBounds* pBounds) {
    static const s32 faces[6][4] = {{0, 1, 2, 3}, {4, 5, 1, 0}, {7, 6, 5, 4}, {3, 2, 6, 7}, {4, 0, 3, 7}, {1, 5, 6, 2}};
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    s32 tangentOffset = pFormat->vf28(6, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    u32 tangentFormat = pFormat->vf29(6, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    f32 right = width * 0.5f;
    f32 top = height * 0.5f;
    f32 front = depth * 0.5f;
    f32 left = width * -0.5f;
    f32 bottom = height * -0.5f;
    f32 back = depth * -0.5f;
    f32 corners[8][3] = {{right, top, back},  {right, bottom, back},  {left, bottom, back},  {left, top, back},
                         {right, top, front}, {right, bottom, front}, {left, bottom, front}, {left, top, front}};
    f32 normals[6][3];
    normals[0][0] = 0.0f;
    normals[0][1] = 0.0f;
    normals[0][2] = -1.0f;
    normals[1][0] = 1.0f;
    normals[1][1] = 0.0f;
    normals[1][2] = 0.0f;
    normals[2][0] = 0.0f;
    normals[2][1] = 0.0f;
    normals[2][2] = 1.0f;
    normals[3][0] = -1.0f;
    normals[3][1] = 0.0f;
    normals[3][2] = 0.0f;
    normals[4][0] = 0.0f;
    normals[4][1] = 1.0f;
    normals[4][2] = 0.0f;
    normals[5][0] = 0.0f;
    normals[5][1] = -1.0f;
    normals[5][2] = 0.0f;
    f32 tangents[6][3];
    tangents[0][0] = -1.0f;
    tangents[0][1] = 0.0f;
    tangents[0][2] = 0.0f;
    tangents[1][0] = 0.0f;
    tangents[1][1] = 0.0f;
    tangents[1][2] = -1.0f;
    tangents[2][0] = 1.0f;
    tangents[2][1] = 0.0f;
    tangents[2][2] = 0.0f;
    tangents[3][0] = 0.0f;
    tangents[3][1] = 0.0f;
    tangents[3][2] = 1.0f;
    tangents[4][0] = -1.0f;
    tangents[4][1] = 0.0f;
    tangents[4][2] = 0.0f;
    tangents[5][0] = 1.0f;
    tangents[5][1] = 0.0f;
    tangents[5][2] = 0.0f;
    f32 texCoords[4][2];
    texCoords[0][0] = 0.0f;
    texCoords[0][1] = 0.0f;
    texCoords[1][0] = 0.0f;
    texCoords[1][1] = 1.0f;
    texCoords[2][0] = 1.0f;
    texCoords[2][1] = 1.0f;
    texCoords[3][0] = 1.0f;
    texCoords[3][1] = 0.0f;
    f32 color[4];
    color[0] = 1.0f;
    color[1] = 1.0f;
    color[2] = 1.0f;
    color[3] = 1.0f;
    s32 size = stride * 24;
#line 183
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    memset(vertices, 0, size);
    u8* vertex = vertices;
    for (s32 i = 0; i < 6; i++) {
        for (s32 j = 0; j < 4; j++) {
            f32 tangent[4];
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            const f32* position = corners[faces[i][j]];
            const f32* normal = normals[i];
            const f32* texCoord = texCoords[j];
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            if (tangentOffset >= 0 && tangentFormat != 0) {
                tangent[0] = tangents[i][0];
                tangent[1] = tangents[i][1];
                tangent[2] = tangents[i][2];
                tangent[3] = 1.0f;
                Unk_4ed850(tangentFormat, vertex + tangentOffset, tangent);
            }
            vertex += stride;
        }
    }
    Unk_4d3e30(pFormat, 24, vertices, 5);
#line 235
    u16* indices = static_cast<u16*>(UNK_ALLOC(field_8.m_pAllocator, 36 * sizeof(u16)));
    for (s32 i = 0; i < 6; i++) {
        indices[i * 6 + 0] = i * 4;
        indices[i * 6 + 1] = i * 4 + 1;
        indices[i * 6 + 2] = i * 4 + 2;
        indices[i * 6 + 3] = i * 4;
        indices[i * 6 + 4] = i * 4 + 2;
        indices[i * 6 + 5] = i * 4 + 3;
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 290
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = 0x39;
    indexDesc.field_4 = 36 * sizeof(u16);
    indexDesc.field_8 = sizeof(u16);
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = 36 * sizeof(u16);
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 323
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 330
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = left;
        pBounds->field_4[1] = bottom;
        pBounds->field_4[2] = back;
        pBounds->field_10[0] = right;
        pBounds->field_10[1] = top;
        pBounds->field_10[2] = front;
    }
    return true;
}

// 0x71004d3d00: the vectors of three are copied as their bytes (12), which is
// what gives the original's 8- and 4-byte copies
// The normal's destination is a local computed first (that puts its pointer
// and offset in the original's registers, x21 and x22).
// NON_MATCHING: scheduling: the normal's first store comes after the call's
// argument moves here, and the colour's two stores are the other way round
// (tried: every block's destination as a local before/inside its test, one
// array per block, the colour's alpha first/through a local, 8+8 or 16-byte
// copies).
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
        u8* p = vertex + normalOffset;
        memcpy(value, normal, 12);
        value[3] = 1.0f;
        Unk_4ed850(normalFormat, p, value);
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

// 0x71004d41f0: rings of slices + 1 vertices (the last at the first's place)
// from the top pole to the bottom one; one triangle per slice at the poles,
// two in the stacks between. The tangent is written after the vertex's other
// attributes.
// NON_MATCHING: the same blocks; the registers and the spill slots differ
// throughout (which values the original keeps in callee-saved registers).
bool SiGfxGeometryUtility::vf6(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                               SiGfxNXBuffer* pIndexBuffer, f32 radiusX, f32 radiusY, f32 radiusZ, s32 slices,
                               s32 stacks, Unk_GeometryBounds* pBounds) {
    if (slices < 3 || stacks < 2) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    s32 tangentOffset = pFormat->vf28(6, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    u32 tangentFormat = pFormat->vf29(6, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = (stacks + 1) * (slices + 1);
    s32 size = stride * vertexCount;
#line 439
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 indexCount = ((stacks - 2) * slices * 2 + slices * 2) * 3;
    {
        f32 tangent[4];
        f32 position[4];
        f32 color[4];
        f32 normal[4];
        f32 texCoord[2];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        for (s32 i = 0; i <= stacks; i++) {
            f32 v = static_cast<f32>(i) / static_cast<f32>(stacks);
            f32 phi = v * 3.1415927f;
            f32 c = cosf(phi);
            f32 s = sinf(phi);
            f32 y = c * radiusY;
            for (s32 j = 0; j <= slices; j++) {
                f32 u = static_cast<f32>(j) / static_cast<f32>(slices);
                f32 theta = j == slices ? 0.0f : u * -6.2831855f;
                f32 cosTheta = cosf(theta);
                f32 sinTheta = sinf(theta);
                f32 x = cosTheta * radiusX;
                f32 z = sinTheta * radiusZ;
                position[0] = s * x;
                position[1] = y;
                position[2] = s * z;
                normal[0] = position[0];
                normal[1] = position[1];
                normal[2] = position[2];
                Unk_Normalize(normal);
                texCoord[0] = u;
                texCoord[1] = v;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                f32 tangentX = sinf(phi + 1.5707964f) * cosf(theta);
                f32 tangentY = sinf(phi + 1.5707964f) * sinf(theta);
                f32 tangentZ = cosf(phi + 1.5707964f);
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                if (tangentOffset >= 0 && tangentFormat != 0) {
                    tangent[0] = tangentX;
                    tangent[1] = tangentY;
                    tangent[2] = tangentZ;
                    tangent[3] = 1.0f;
                    Unk_4ed850(tangentFormat, vertex + tangentOffset, tangent);
                }
                vertex += stride;
            }
        }
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    s32 indexSize = (indexCount >= 0x10000 ? 4 : 2) * indexCount;
#line 517
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    s32 triangle = 0;
    for (s32 j = 0; j < slices; j++) {
        Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, j, slices + j + 1, slices + j + 2);
        triangle++;
    }
    for (s32 i = 1; i < stacks - 1; i++) {
        for (s32 j = 0; j < slices; j++) {
            s32 first = i * (slices + 1) + j;
            s32 second = (i + 1) * (slices + 1) + j;
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, first, second + 1, first + 1);
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, first, second, second + 1);
            triangle += 2;
        }
    }
    for (s32 j = 0; j < slices; j++) {
        s32 first = (stacks - 1) * (slices + 1) + j;
        Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, first, first + slices + 1, first + 1);
        triangle++;
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 589
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indexCount >= 0x10000 ? 0x2a : 0x39;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indexCount >= 0x10000 ? 4 : 2;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 622
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 629
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radiusX;
        pBounds->field_4[1] = -radiusY;
        pBounds->field_4[2] = -radiusZ;
        pBounds->field_10[0] = radiusX;
        pBounds->field_10[1] = radiusY;
        pBounds->field_10[2] = radiusZ;
    }
    return true;
}

// 0x71004d4bd0: the meridians' vertices (the last one of each at the bottom
// pole), then the circles' (each closed by a vertex at its start); a line
// between each vertex and the one before it on its meridian or circle
// NON_MATCHING: the same blocks; the registers and the spill slots differ.
bool SiGfxGeometryUtility::vf7(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                               SiGfxNXBuffer* pIndexBuffer, f32 radiusX, f32 radiusY, f32 radiusZ, s32 slices,
                               s32 stacks, Unk_GeometryBounds* pBounds) {
    if (slices < 3 || stacks < 2) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = (stacks + 1) * slices + (stacks - 1) * (slices + 1);
    s32 size = stride * vertexCount;
#line 733
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 lineCount = slices * stacks + (stacks - 1) * slices;
    s32 indexSize = lineCount * 2 * (vertexCount >= 0x10000 ? 4 : 2);
#line 745
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    if (indices == nullptr) {
        return false;
    }
    u16* indices16 = vertexCount >= 0x10000 ? nullptr : static_cast<u16*>(indices);
    u32* indices32 = vertexCount >= 0x10000 ? static_cast<u32*>(indices) : nullptr;
    {
        f32 position[4];
        f32 normal[4];
        f32 color[4];
        f32 texCoord[2];
        f32 tangent[4];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        s32 index = 0;
        s32 count = 0;
        for (s32 i = 0; i < slices; i++) {
            f32 u = static_cast<f32>(i) / static_cast<f32>(slices);
            f32 theta = u * -6.2831855f;
            f32 cosTheta = cosf(theta);
            f32 sinTheta = sinf(theta);
            f32 x = cosTheta * radiusX;
            f32 z = sinTheta * radiusZ;
            s32 previous = -1;
            for (s32 j = 0; j <= stacks; j++) {
                f32 v = static_cast<f32>(j) / static_cast<f32>(stacks);
                f32 phi = j == stacks ? 3.1415927f : v * 3.1415927f;
                f32 c = cosf(phi);
                f32 s = sinf(phi);
                position[0] = x * s;
                position[1] = c * radiusY;
                position[2] = z * s;
                normal[0] = position[0];
                normal[1] = position[1];
                normal[2] = position[2];
                Unk_Normalize(normal);
                texCoord[0] = u;
                texCoord[1] = v;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                if (previous >= 0) {
                    if (indices16 != nullptr) {
                        indices16[count] = previous;
                        indices16[count + 1] = index;
                    } else if (indices32 != nullptr) {
                        indices32[count] = previous;
                        indices32[count + 1] = index;
                    }
                    count += 2;
                }
                previous = index;
                index++;
                vertex += stride;
            }
        }
        for (s32 k = 1; k < stacks; k++) {
            f32 v = static_cast<f32>(k) / static_cast<f32>(stacks);
            f32 phi = v * 3.1415927f;
            f32 c = cosf(phi);
            f32 s = sinf(phi);
            f32 y = c * radiusY;
            s32 previous = -1;
            for (s32 j = 0; j <= slices; j++) {
                f32 u = static_cast<f32>(j) / static_cast<f32>(slices);
                f32 theta = j == slices ? 0.0f : u * -6.2831855f;
                f32 cosTheta = cosf(theta);
                f32 sinTheta = sinf(theta);
                f32 x = cosTheta * radiusX;
                f32 z = sinTheta * radiusZ;
                position[0] = s * x;
                position[1] = y;
                position[2] = s * z;
                normal[0] = position[0];
                normal[1] = position[1];
                normal[2] = position[2];
                Unk_Normalize(normal);
                texCoord[0] = u;
                texCoord[1] = v;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                if (previous >= 0) {
                    if (indices16 != nullptr) {
                        indices16[count] = previous;
                        indices16[count + 1] = index;
                    } else if (indices32 != nullptr) {
                        indices32[count] = previous;
                        indices32[count + 1] = index;
                    }
                    count += 2;
                }
                previous = index;
                index++;
                vertex += stride;
            }
        }
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 914
        UNK_FREE(field_8.m_pAllocator, vertices);
        UNK_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indices32 == nullptr ? 0x39 : 0x2a;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indices32 == nullptr ? 2 : 4;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 947
        UNK_FREE(field_8.m_pAllocator, vertices);
        UNK_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 954
    UNK_FREE(field_8.m_pAllocator, vertices);
    UNK_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radiusX;
        pBounds->field_4[1] = -radiusY;
        pBounds->field_4[2] = -radiusZ;
        pBounds->field_10[0] = radiusX;
        pBounds->field_10[1] = radiusY;
        pBounds->field_10[2] = radiusZ;
    }
    return true;
}

// 0x71004d55e0: the bottom disc's centre and rim, the side's rings from the
// bottom up, then the top disc's centre and rim (its normals are its
// positions normalised, the bottom's point down). The top disc's indices start
// one vertex early, as the original has them.
// NON_MATCHING: the registers, the spill slots, some of the arrays' stack
// slots and the order of some blocks differ (not looked into further).
bool SiGfxGeometryUtility::vf8(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                               SiGfxNXBuffer* pIndexBuffer, f32 bottomRadius, f32 topRadius, f32 height,
                               s32 slices, s32 stacks, Unk_GeometryBounds* pBounds) {
    if (slices < 3 || stacks < 1) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = (stacks + 1) * (slices + 1);
    s32 triangleCount = slices * 2 * stacks;
    if (bottomRadius > 0.0f) {
        vertexCount += slices + 2;
        triangleCount += slices;
    }
    if (topRadius > 0.0f) {
        vertexCount += slices + 2;
        triangleCount += slices;
    }
    s32 size = stride * vertexCount;
#line 1066
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    f32 color[4];
    color[0] = 1.0f;
    color[1] = 1.0f;
    color[2] = 1.0f;
    color[3] = 1.0f;
    u8* vertex = vertices;
    if (bottomRadius > 0.0f) {
        {
            f32 position[4];
            f32 normal[4];
            f32 texCoord[2];
            f32 tangent[4];
            position[0] = 0.0f;
            position[1] = 0.0f;
            position[2] = height * -0.5f;
            normal[0] = 0.0f;
            normal[1] = 0.0f;
            normal[2] = -1.0f;
            texCoord[0] = 0.5f;
            texCoord[1] = 0.0f;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            vertex += stride;
        }
        for (s32 j = 0; j <= slices; j++) {
            f32 position[4];
            f32 normal[4];
            f32 texCoord[2];
            f32 tangent[4];
            f32 angle = j == slices ? 0.0f : static_cast<f32>(-j) / static_cast<f32>(slices) * 6.2831855f;
            f32 c = cosf(angle);
            f32 s = sinf(angle);
            position[0] = c * bottomRadius;
            position[1] = s * bottomRadius;
            position[2] = height * -0.5f;
            normal[0] = 0.0f;
            normal[1] = 0.0f;
            normal[2] = -1.0f;
            Unk_Normalize(normal);
            texCoord[0] = static_cast<f32>(j) / static_cast<f32>(slices);
            texCoord[1] = 0.0f;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            vertex += stride;
        }
    }
    for (s32 i = 0; i <= stacks; i++) {
        f32 v = static_cast<f32>(i) / static_cast<f32>(stacks);
        f32 z = v * height - height * 0.5f;
        f32 radius = v * topRadius + (1.0f - v) * bottomRadius;
        for (s32 j = 0; j <= slices; j++) {
            f32 position[4];
            f32 normal[4];
            f32 texCoord[2];
            f32 tangent[4];
            f32 angle = j == slices ? 0.0f : static_cast<f32>(-j) / static_cast<f32>(slices) * 6.2831855f;
            f32 c = cosf(angle);
            f32 s = sinf(angle);
            position[0] = radius * c;
            position[1] = radius * s;
            position[2] = z;
            normal[0] = radius * c;
            normal[1] = radius * s;
            normal[2] = 0.0f;
            if (radius <= 0.0f) {
                normal[0] = 0.0f;
                normal[1] = 0.0f;
                normal[2] = z;
            }
            Unk_Normalize(normal);
            texCoord[0] = static_cast<f32>(j) / static_cast<f32>(slices);
            texCoord[1] = v;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            vertex += stride;
        }
    }
    if (topRadius > 0.0f) {
        {
            f32 position[4];
            f32 normal[4];
            f32 texCoord[2];
            f32 tangent[4];
            position[0] = 0.0f;
            position[1] = 0.0f;
            position[2] = height * 0.5f;
            normal[0] = 0.0f;
            normal[1] = 0.0f;
            normal[2] = 1.0f;
            texCoord[0] = 0.5f;
            texCoord[1] = 0.0f;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            vertex += stride;
        }
        for (s32 j = 0; j <= slices; j++) {
            f32 position[4];
            f32 normal[4];
            f32 texCoord[2];
            f32 tangent[4];
            f32 angle = j == slices ? 0.0f : static_cast<f32>(-j) / static_cast<f32>(slices) * 6.2831855f;
            f32 c = cosf(angle);
            f32 s = sinf(angle);
            position[0] = c * topRadius;
            position[1] = s * topRadius;
            position[2] = height * 0.5f;
            normal[0] = position[0];
            normal[1] = position[1];
            normal[2] = position[2];
            Unk_Normalize(normal);
            texCoord[0] = static_cast<f32>(j) / static_cast<f32>(slices);
            texCoord[1] = 0.0f;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            vertex += stride;
        }
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    s32 indexCount = triangleCount * 3;
    s32 indexSize = (indexCount >= 0x10000 ? 4 : 2) * indexCount;
#line 1238
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    s32 triangle = 0;
    s32 first = 0;
    if (bottomRadius > 0.0f) {
        for (s32 j = 0; j < slices; j++) {
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, 0, j + 1, j + 2);
            triangle++;
        }
        first = slices + 2;
    }
    for (s32 i = 0; i < stacks; i++) {
        for (s32 j = 0; j < slices; j++) {
            s32 a = first + i * (slices + 1) + j;
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, a, a + slices + 2, a + 1);
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, a, a + slices + 1, a + slices + 2);
            triangle += 2;
        }
    }
    if (topRadius > 0.0f) {
        s32 centre = vertexCount - (slices + 1) - 2;
        for (s32 j = 0; j < slices; j++) {
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, centre, centre + j + 2, centre + j + 1);
            triangle++;
        }
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 1341
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indexCount >= 0x10000 ? 0x2a : 0x39;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indexCount >= 0x10000 ? 4 : 2;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 1374
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 1381
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        f32 radius = bottomRadius > topRadius ? bottomRadius : topRadius;
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radius;
        pBounds->field_4[1] = -radius;
        pBounds->field_4[2] = height * -0.5f;
        pBounds->field_10[0] = radius;
        pBounds->field_10[1] = radius;
        pBounds->field_10[2] = height * 0.5f;
    }
    return true;
}

// 0x71004d64d0: for each ring, the rotation about the x axis by its angle
// (the general axis and angle form with the axis 1, 0, 0: the products with
// its zeros stay) gives the plane of its circle of sides + 1 vertices
// NON_MATCHING: written from the original's operations, not matched yet (the
// rotation and the products of the matrices are a guess at the inline
// functions)
bool SiGfxGeometryUtility::vf9(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                               SiGfxNXBuffer* pIndexBuffer, f32 radius, f32 tubeRadius, s32 sides, s32 rings,
                               Unk_GeometryBounds* pBounds) {
    if (sides < 3 || rings < 1) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = (rings + 1) * (sides + 1);
    s32 size = stride * vertexCount;
#line 1476
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 indexCount = sides * rings * 3 * 2;
    {
        f32 position[4];
        f32 normal[4];
        f32 color[4];
        f32 texCoord[2];
        f32 tangent[4];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        const f32 x = 1.0f;
        const f32 y = 0.0f;
        const f32 z = 0.0f;
        for (s32 i = 0; i <= rings; i++) {
            f32 v = static_cast<f32>(i) / static_cast<f32>(rings);
            f32 angle = v * 6.2831855f;
            f32 c = cosf(angle);
            f32 s = sinf(angle);
            f32 t = 1.0f - c;
            Unk_Matrix44 rotation;
            rotation.r[0] = float32x4_t{1.0f - t * (y * y + z * z), t * x * y + s * z, t * x * z - s * y, 0.0f};
            rotation.r[1] = float32x4_t{t * x * y - s * z, 1.0f - t * (x * x + z * z), t * y * z + s * x, 0.0f};
            rotation.r[2] = float32x4_t{t * x * z + s * y, t * y * z - s * x, 1.0f - t * (x * x + y * y), 0.0f};
            rotation.r[3] = float32x4_t{0.0f, 0.0f, 0.0f, 0.0f};
            Unk_Matrix44 m = Unk_Multiply(Unk_Identity(), rotation);
            for (s32 j = 0; j <= sides; j++) {
                f32 phi = j == sides ? 0.0f : static_cast<f32>(-j) / static_cast<f32>(sides) * 6.2831855f;
                f32 cosPhi = cosf(phi);
                f32 sinPhi = sinf(phi);
                float32x4_t p = m.r[3] + (m.r[0] * (cosPhi * tubeRadius) + m.r[1] * (sinPhi * tubeRadius + radius));
                float32x4_t n = m.r[3] + (m.r[0] * cosPhi + m.r[1] * sinPhi);
                position[0] = p[0];
                position[1] = p[1];
                position[2] = p[2];
                normal[0] = n[0];
                normal[1] = n[1];
                normal[2] = n[2];
                if (tubeRadius <= 0.0f) {
                    normal[0] = 1.0f;
                    normal[1] = 0.0f;
                    normal[2] = 0.0f;
                }
                texCoord[0] = static_cast<f32>(j) / static_cast<f32>(sides);
                texCoord[1] = v;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                vertex += stride;
            }
        }
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    s32 indexSize = (indexCount >= 0x10000 ? 4 : 2) * indexCount;
#line 1546
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    s32 triangle = 0;
    for (s32 i = 0; i < rings; i++) {
        for (s32 j = 0; j < sides; j++) {
            s32 a = i * (sides + 1) + j;
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, a, a + sides + 2, a + 1);
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, a, a + sides + 1, a + sides + 2);
            triangle += 2;
        }
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 1606
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indexCount >= 0x10000 ? 0x2a : 0x39;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indexCount >= 0x10000 ? 4 : 2;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    indexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 1639
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 1646
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radius - tubeRadius;
        pBounds->field_4[1] = -radius - tubeRadius;
        pBounds->field_4[2] = -tubeRadius;
        pBounds->field_10[0] = radius + tubeRadius;
        pBounds->field_10[1] = radius + tubeRadius;
        pBounds->field_10[2] = tubeRadius;
    }
    return true;
}

// 0x71004d6cb0: four vertices and two triangles. The buffers' descriptions
// are made with the defaults and then every member set (the index buffer's
// sets the vertex buffer's field_18 where its own would be: the original's
// store to the vertex buffer's description after its buffer is made says so).
// NON_MATCHING: after the first vertex, the colour's offset and format are
// reloaded into each other's registers (w19, w21) and spill slots.
// (Tried: every declaration order of the attributes and of the arrays,
// separate declarations, an attribute array.)
bool SiGfxGeometryUtility::vf10(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                                SiGfxNXBuffer* pIndexBuffer, f32 width, f32 height, Unk_GeometryBounds* pBounds) {
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    tangentAttribute.offset = pFormat->vf28(6, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    tangentAttribute.format = pFormat->vf29(6, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 size = stride * 4;
#line 1731
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    f32 position[4];
    f32 normal[4];
    f32 texCoord[2];
    f32 tangent[4];
    f32 color[4];
    position[0] = width * -0.5f;
    position[1] = height * -0.5f;
    position[2] = 0.0f;
    normal[0] = 0.0f;
    normal[1] = 0.0f;
    normal[2] = 1.0f;
    tangent[0] = 1.0f;
    tangent[1] = 0.0f;
    tangent[2] = 0.0f;
    color[0] = 1.0f;
    color[1] = 1.0f;
    color[2] = 1.0f;
    color[3] = 1.0f;
    texCoord[0] = 0.0f;
    texCoord[1] = 0.0f;
    u8* vertex = vertices;
    Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
               normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
               colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset, tangentAttribute.format,
               tangent);
    vertex += stride;
    position[0] = width * -0.5f;
    position[1] = height * 0.5f;
    position[2] = 0.0f;
    texCoord[0] = 0.0f;
    texCoord[1] = 1.0f;
    Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
               normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
               colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset, tangentAttribute.format,
               tangent);
    vertex += stride;
    position[0] = width * 0.5f;
    position[1] = height * 0.5f;
    position[2] = 0.0f;
    texCoord[0] = 1.0f;
    texCoord[1] = 1.0f;
    Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
               normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
               colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset, tangentAttribute.format,
               tangent);
    vertex += stride;
    position[0] = width * 0.5f;
    position[1] = height * -0.5f;
    position[2] = 0.0f;
    texCoord[0] = 1.0f;
    texCoord[1] = 0.0f;
    Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
               normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
               colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset, tangentAttribute.format,
               tangent);
    Unk_4d3e30(pFormat, 4, vertices, 5);
#line 1807
    u16* indices = static_cast<u16*>(UNK_ALLOC(field_8.m_pAllocator, 6 * sizeof(u16)));
    Unk_4ed780(4, false, indices, 0, 0, 2, 1);
    Unk_4ed780(4, false, indices, 1, 0, 3, 2);
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 1837
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = 0x39;
    indexDesc.field_4 = 6 * sizeof(u16);
    indexDesc.field_8 = sizeof(u16);
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = 6 * sizeof(u16);
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 1870
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 1877
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = width * -0.5f;
        pBounds->field_4[1] = height * -0.5f;
        pBounds->field_4[2] = 0.0f;
        pBounds->field_10[0] = width * 0.5f;
        pBounds->field_10[1] = height * 0.5f;
        pBounds->field_10[2] = 0.0f;
    }
    return true;
}

// 0x71004d7330: the ring's vertices, then the centre's; a triangle per
// segment
// NON_MATCHING: the registers differ (the original keeps the height in v9 and
// spills the radius, -radius and the index buffer), and the index buffer's
// description has more stores in the original (its field_1c is 8 before it is
// 2, and the zeros of 0x20 to 0x3f stay: not reproduced yet).
bool SiGfxGeometryUtility::vf11(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                                SiGfxNXBuffer* pIndexBuffer, f32 radius, f32 height, s32 segments,
                                Unk_GeometryBounds* pBounds) {
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = segments + 1;
    s32 size = stride * vertexCount;
#line 1964
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 indexCount = segments * 3;
    {
        f32 position[4];
        f32 normal[4];
        f32 color[4];
        f32 texCoord[2];
        f32 tangent[4];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        for (s32 i = 0; i < segments; i++) {
            f32 angle = static_cast<f32>(i) / static_cast<f32>(segments) * 6.2831855f;
            f32 c = cosf(angle);
            f32 s = sinf(angle);
            position[0] = c * radius;
            position[1] = s * radius;
            position[2] = height;
            normal[0] = c * height;
            normal[1] = s * height;
            normal[2] = -radius;
            Unk_Normalize(normal);
            texCoord[0] = c * 0.5f + 0.5f;
            texCoord[1] = s * 0.5f + 0.5f;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            vertex += stride;
        }
        position[0] = 0.0f;
        position[1] = 0.0f;
        position[2] = 0.0f;
        normal[0] = 0.0f;
        normal[1] = 0.0f;
        normal[2] = 1.0f;
        texCoord[0] = 0.5f;
        texCoord[1] = 0.5f;
        tangent[0] = 0.0f;
        tangent[1] = 0.0f;
        tangent[2] = 0.0f;
        Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                   normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                   colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset, tangentAttribute.format,
                   tangent);
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    s32 indexSize = (indexCount >= 0x10000 ? 4 : 2) * indexCount;
#line 2030
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    for (s32 i = 0; i < segments; i++) {
        Unk_4ed780(4, indexCount >= 0x10000, indices, i, segments, i == segments - 1 ? 0 : i + 1, i);
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 2078
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indexCount >= 0x10000 ? 0x2a : 0x39;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indexCount >= 0x10000 ? 4 : 2;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 2111
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 2118
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radius;
        pBounds->field_4[1] = -radius;
        pBounds->field_4[2] = -height;
        pBounds->field_10[0] = radius;
        pBounds->field_10[1] = radius;
        pBounds->field_10[2] = 0.0f;
    }
    return true;
}

// 0x71004d7a50: rings of slices vertices from the rim (z 0) to the top, their
// normals the positions normalised; two triangles per slice and stack
// NON_MATCHING: the loops are the original's; the registers and spill slots
// differ, and the index loop compares j with slices - 1 in the original. The
// index buffer's description has the extra stores vf11's note describes.
bool SiGfxGeometryUtility::vf12(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                                SiGfxNXBuffer* pIndexBuffer, f32 radius, s32 slices, s32 stacks,
                                Unk_GeometryBounds* pBounds) {
    if (slices < 3 || stacks < 2) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = (stacks + 1) * slices;
    s32 size = stride * vertexCount;
#line 2211
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 indexCount = slices * stacks * 3 * 2;
    {
        f32 position[4];
        f32 normal[4];
        f32 color[4];
        f32 texCoord[2];
        f32 tangent[4];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        for (s32 i = 0; i <= stacks; i++) {
            f32 phi = static_cast<f32>(i) / static_cast<f32>(stacks) * 0.5f * 3.1415927f;
            f32 cosPhi = cosf(phi);
            f32 z = sinf(phi) * radius;
            for (s32 j = 0; j < slices; j++) {
                f32 theta = static_cast<f32>(j) / static_cast<f32>(slices) * 6.2831855f;
                f32 c = cosf(theta);
                f32 s = sinf(theta);
                position[0] = cosPhi * (c * radius);
                position[1] = cosPhi * (s * radius);
                position[2] = z;
                normal[0] = position[0];
                normal[1] = position[1];
                normal[2] = position[2];
                Unk_Normalize(normal);
                texCoord[0] = c * 0.5f + 0.5f;
                texCoord[1] = s * 0.5f + 0.5f;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                vertex += stride;
            }
        }
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    s32 indexSize = (indexCount >= 0x10000 ? 4 : 2) * indexCount;
#line 2275
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    for (s32 i = 0; i < stacks; i++) {
        for (s32 j = 0; j < slices; j++) {
            s32 next = j == slices - 1 ? 0 : j + 1;
            s32 triangle = (i * slices + j) * 2;
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, i * slices + j, i * slices + next,
                       (i + 1) * slices + next);
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, i * slices + j, (i + 1) * slices + next,
                       (i + 1) * slices + j);
        }
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 2323
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indexCount >= 0x10000 ? 0x2a : 0x39;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indexCount >= 0x10000 ? 4 : 2;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 2356
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 2363
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radius;
        pBounds->field_4[1] = -radius;
        pBounds->field_4[2] = -radius;
        pBounds->field_10[0] = radius;
        pBounds->field_10[1] = radius;
    }
    return true;
}

// 0x71004d8260: a vertex per segment and a line from each to the next
// NON_MATCHING: the loop is unswitched on the 16-bit indices and its first
// iteration peeled, as in the original (that needed the previous index as a
// variable and the normal's normalisation through a reference to the array);
// the registers and the spill slots differ.
bool SiGfxGeometryUtility::vf13(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                                SiGfxNXBuffer* pIndexBuffer, f32 radius, s32 segments, Unk_GeometryBounds* pBounds) {
    if (segments < 3) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 size = stride * segments;
#line 2457
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 indexSize = segments * (segments >= 0x10000 ? 4 : 2) * 2;
#line 2469
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    if (indices == nullptr) {
        return false;
    }
    u16* indices16 = segments >= 0x10000 ? nullptr : static_cast<u16*>(indices);
    u32* indices32 = segments >= 0x10000 ? static_cast<u32*>(indices) : nullptr;
    s32 count = 0;
    s32 previous = -1;
    {
        f32 position[4];
        f32 normal[4];
        f32 color[4];
        f32 texCoord[2];
        f32 tangent[4];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        for (s32 i = 0; i < segments; i++) {
            f32 u = static_cast<f32>(i) / static_cast<f32>(segments);
            f32 angle = u * -6.2831855f;
            f32 c = cosf(angle);
            f32 s = sinf(angle);
            f32 x = c * radius;
            f32 z = s * radius;
            position[0] = x;
            position[1] = 0.0f;
            position[2] = z;
            normal[0] = x;
            normal[1] = 0.0f;
            normal[2] = z;
            Unk_Normalize(normal);
            texCoord[0] = u;
            texCoord[1] = 0.0f;
            tangent[0] = 0.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
            Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                       normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                       colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                       tangentAttribute.format, tangent);
            if (previous >= 0) {
                if (indices16 != nullptr) {
                    indices16[count] = previous;
                    indices16[count + 1] = i;
                } else if (indices32 != nullptr) {
                    indices32[count] = previous;
                    indices32[count + 1] = i;
                }
                count += 2;
            }
            previous = i;
            vertex += stride;
        }
    }
    if (indices16 != nullptr) {
        indices16[count] = previous;
        indices16[count + 1] = 0;
    } else if (indices32 != nullptr) {
        indices32[count] = previous;
        indices32[count + 1] = 0;
    }
    Unk_4d3e30(pFormat, segments, vertices, 5);
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 2579
        UNK_FREE(field_8.m_pAllocator, vertices);
        UNK_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indices32 == nullptr ? 0x39 : 0x2a;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indices32 == nullptr ? 2 : 4;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 2612
        UNK_FREE(field_8.m_pAllocator, vertices);
        UNK_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 2619
    UNK_FREE(field_8.m_pAllocator, vertices);
    UNK_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radius;
        pBounds->field_4[1] = 0.0f;
        pBounds->field_4[2] = -radius;
        pBounds->field_10[0] = radius;
        pBounds->field_10[1] = 0.0f;
        pBounds->field_10[2] = radius;
    }
    return true;
}

// 0x71004d8c70: the upper half sphere's rings from its rim up, then the lower
// one's from its rim down; two triangles per slice and stack in each, and two
// per slice between the rims. The second triangle of each pair shares the
// first's second corner, as the original has it.
// NON_MATCHING: the registers and the spill slots differ, and the index loops'
// induction variables are arranged otherwise.
bool SiGfxGeometryUtility::vf14(SiGfxNXVertexFormat* pFormat, SiGfxNXBuffer* pVertexBuffer,
                                SiGfxNXBuffer* pIndexBuffer, f32 radius, f32 height, s32 slices, s32 stacks,
                                Unk_GeometryBounds* pBounds) {
    if (slices < 3 || stacks < 2) {
        return false;
    }
    if (static_cast<s32>(pFormat->vf22()) < 0) {
        return false;
    }
    s32 stride = pFormat->vf26(0);
    if (stride == 0) {
        return false;
    }
    Unk_VertexAttribute positionAttribute, normalAttribute, texCoordAttribute, colorAttribute, tangentAttribute;
    positionAttribute.offset = pFormat->vf28(0, 0);
    normalAttribute.offset = pFormat->vf28(3, 0);
    texCoordAttribute.offset = pFormat->vf28(5, 0);
    colorAttribute.offset = pFormat->vf28(4, 0);
    positionAttribute.format = pFormat->vf29(0, 0);
    normalAttribute.format = pFormat->vf29(3, 0);
    texCoordAttribute.format = pFormat->vf29(5, 0);
    colorAttribute.format = pFormat->vf29(4, 0);
    if (positionAttribute.offset < 0) {
        return false;
    }
    s32 vertexCount = slices * 2 * (stacks + 1);
    s32 size = stride * vertexCount;
#line 2724
    u8* vertices = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (vertices == nullptr) {
        return false;
    }
    s32 indexCount = (stacks * 12 + 6) * slices;
    f32 halfHeight = height * 0.5f;
    {
        f32 position[4];
        f32 normal[4];
        f32 color[4];
        f32 texCoord[2];
        f32 tangent[4];
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        u8* vertex = vertices;
        for (s32 i = 0; i <= stacks; i++) {
            f32 phi = static_cast<f32>(i) / static_cast<f32>(stacks) * 0.5f * 3.1415927f;
            f32 cosPhi = cosf(phi);
            f32 z = halfHeight + sinf(phi) * radius;
            for (s32 j = 0; j < slices; j++) {
                f32 theta = static_cast<f32>(j) / static_cast<f32>(slices) * 6.2831855f;
                f32 c = cosf(theta);
                f32 s = sinf(theta);
                position[0] = cosPhi * (c * radius);
                position[1] = cosPhi * (s * radius);
                position[2] = z;
                normal[0] = position[0];
                normal[1] = position[1];
                normal[2] = position[2];
                Unk_Normalize(normal);
                texCoord[0] = c * 0.5f + 0.5f;
                texCoord[1] = s * 0.5f + 0.5f;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                vertex += stride;
            }
        }
        for (s32 i = 0; i <= stacks; i++) {
            f32 phi = static_cast<f32>(i) / static_cast<f32>(stacks) * 0.5f * 3.1415927f;
            f32 cosPhi = cosf(phi);
            f32 z = -(halfHeight + sinf(phi) * radius);
            for (s32 j = 0; j < slices; j++) {
                f32 theta = static_cast<f32>(j) / static_cast<f32>(slices) * 6.2831855f;
                f32 c = cosf(theta);
                f32 s = sinf(theta);
                position[0] = cosPhi * (c * radius);
                position[1] = cosPhi * (s * radius);
                position[2] = z;
                normal[0] = position[0];
                normal[1] = position[1];
                normal[2] = position[2];
                Unk_Normalize(normal);
                texCoord[0] = c * 0.5f + 0.5f;
                texCoord[1] = s * 0.5f + 0.5f;
                tangent[0] = 0.0f;
                tangent[1] = 0.0f;
                tangent[2] = 0.0f;
                Unk_4d3d00(vertex, positionAttribute.offset, positionAttribute.format, position, normalAttribute.offset,
                           normalAttribute.format, normal, texCoordAttribute.offset, texCoordAttribute.format, texCoord,
                           colorAttribute.offset, colorAttribute.format, color, tangentAttribute.offset,
                           tangentAttribute.format, tangent);
                vertex += stride;
            }
        }
    }
    Unk_4d3e30(pFormat, vertexCount, vertices, 5);
    s32 indexSize = (indexCount >= 0x10000 ? 4 : 2) * indexCount;
#line 2827
    void* indices = UNK_ALLOC(field_8.m_pAllocator, indexSize);
    s32 triangle = 0;
    for (s32 i = 0; i < stacks; i++) {
        for (s32 j = 0; j < slices; j++) {
            s32 next = j == slices - 1 ? 0 : j + 1;
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, i * slices + j, i * slices + next,
                       (i + 1) * slices + next);
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, i * slices + j, i * slices + next,
                       (i + 1) * slices + j);
            triangle += 2;
        }
    }
    s32 lower = slices * (stacks + 1);
    for (s32 i = 0; i < stacks; i++) {
        for (s32 j = 0; j < slices; j++) {
            s32 next = j == slices - 1 ? 0 : j + 1;
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, lower + i * slices + j,
                       lower + i * slices + next, lower + (i + 1) * slices + next);
            Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, lower + i * slices + j,
                       lower + i * slices + next, lower + (i + 1) * slices + j);
            triangle += 2;
        }
    }
    for (s32 j = 0; j < slices; j++) {
        s32 next = j == slices - 1 ? 0 : j + 1;
        Unk_4ed780(4, indexCount >= 0x10000, indices, triangle, j, next, lower + next);
        Unk_4ed780(4, indexCount >= 0x10000, indices, triangle + 1, j, next, lower + j);
        triangle += 2;
    }
    SiGfxNXBuffer::Unk_MakeDesc vertexDesc(0, 0, 0, 1, 1, 0);
    vertexDesc.field_0 = 0;
    vertexDesc.field_4 = size;
    vertexDesc.field_8 = stride;
    vertexDesc.field_1c = 1;
    vertexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    vertexDesc.field_24 = 0;
    vertexDesc.field_28 = size;
    vertexDesc.field_30 = vertices;
    if (!pVertexBuffer->vf21(&vertexDesc)) {
#line 2955
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
    SiGfxNXBuffer::Unk_MakeDesc indexDesc(0, 0, 0, 1, 1, 0);
    indexDesc.field_0 = indexCount >= 0x10000 ? 0x2a : 0x39;
    indexDesc.field_4 = indexSize;
    indexDesc.field_8 = indexCount >= 0x10000 ? 4 : 2;
    indexDesc.field_1c = 2;
    indexDesc.field_20 = 0;
    vertexDesc.field_18 = 1;
    indexDesc.field_24 = 0;
    indexDesc.field_28 = indexSize;
    indexDesc.field_30 = indices;
    if (!pIndexBuffer->vf21(&indexDesc)) {
#line 2988
        UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
        UNK_SAFE_FREE(field_8.m_pAllocator, indices);
        return false;
    }
#line 2995
    UNK_SAFE_FREE(field_8.m_pAllocator, vertices);
    UNK_SAFE_FREE(field_8.m_pAllocator, indices);
    if (pBounds != nullptr) {
        pBounds->field_0 = 1;
        pBounds->field_4[0] = -radius;
        pBounds->field_4[1] = -radius;
        pBounds->field_4[2] = -radius;
        pBounds->field_10[0] = radius;
        pBounds->field_10[1] = radius;
        pBounds->field_10[2] = 0.0f;
    }
    return true;
}

}  // namespace SiSDK3
