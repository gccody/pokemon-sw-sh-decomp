// Scope: common
// SiSDK3::SiGfxPrimitiveDrawHelper: its construction and destruction, its
// event handler's destructor, and the reference counts its header defines.
#define UNK_SIGFX_PRIMITIVEDRAWHELPER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_PrimitiveDrawHelper.h>

#include <math.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiMath/Unk_Matrix.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>

// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004c9380: copies bytes
void* Unk_4c9380(void* dst, const void* src, size_t size);
// 0x71004ed0c0: a format's bytes per pixel
s32 Unk_4ed0c0(u32 format);
// 0x71004ecf40: the program of a kind of primitive's index (Unk_4ecbc0.cpp)
u32 Unk_4ecf40(s32 kind, s32 index);
// 0x71004ee020: an orthographic projection of a target's size, SiMath's
// matrix of four NEON rows (its temporary is 16-aligned), which a uniform
// block takes as sixteen floats
struct Unk_PrimitiveMatrix {
    // (copied as bytes)
    void operator=(const Unk_Matrix44& m) { memcpy(field_0, &m, sizeof(field_0)); }

    f32 field_0[16];
};
Unk_Matrix44 Unk_4ee020(f32 width, f32 height, f32 zNear, f32 zFar);
// 0x71004ed720 (SiGfx_Utility.cpp): what a texel's coordinates are moved by
// for a texture, as this file reads its result (placeholder type: two
// floats, returned in memory)
class Unk_4ed720_Context;
struct Unk_PrimitiveTexelOffset {
    Unk_PrimitiveTexelOffset(const Unk_PrimitiveTexelOffset& other);

    f32 field_0;
    f32 field_4;
};
Unk_PrimitiveTexelOffset Unk_4ed720(Unk_4ed720_Context* context);

namespace SiSDK3 {

// 0x7100546770, 0x7100546790 (deleting)
SiGfxPrimitiveDrawHelper::GfxEventHandler::~GfxEventHandler() {}

// 0x71005467d0
void SiGfxPrimitiveDrawHelper::GfxEventHandler::vf5() {
    if (field_18 != nullptr) {
        field_18->Unk_Reset();
    }
}

// 0x71005468b0
void SiGfxPrimitiveDrawHelper::GfxEventHandler::vf6() {
    if (field_18 != nullptr) {
        field_18->Unk_Reset();
    }
}

inline void SiGfxPrimitiveDrawHelper::Unk_FreeBuffer() {
    if (!field_184) {
        if (field_160 != nullptr) {
            if (field_8.m_pAllocator != nullptr) {
#line 1355
                SI_FREE(field_8.m_pAllocator, field_160);
            }
            field_160 = nullptr;
        }
        field_160 = nullptr;
    }
}

// 0x7100546990
SiGfxPrimitiveDrawHelper::SiGfxPrimitiveDrawHelper(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_490(nullptr), field_ae0(nullptr), field_ae8(pAllocator) {
    memset(&field_160, 0, 0x330);
    field_174 = 0x10;
    field_170 = 0;
    field_178 = 0;
    field_17c = 0;
    field_184 = false;
    field_180 = 4;
    memset(&field_820, 0, sizeof(field_820));
    field_ae8.field_18 = this;
}

// 0x7100546a40 (D2), 0x7100546b90 (D0)
SiGfxPrimitiveDrawHelper::~SiGfxPrimitiveDrawHelper() {
    Unk_546b00();
}

// 0x7100546b00
void SiGfxPrimitiveDrawHelper::Unk_546b00() {
    if (field_ae0 != nullptr) {
        field_ae0->vf3();
        field_ae0 = nullptr;
    }
    memset(&field_820, 0, sizeof(field_820));
    Unk_FreeBuffer();
    reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf34(&field_ae8);
}

// NON_MATCHING: the original threads the free's test of a null allocator
// through the zeroing into the allocation's failure (a second copy of the
// memset, 544 bytes); here the null allocator path joins the others before
// the memset (524). Tried: the allocator read again at the allocation, the
// free's allocator in a local, the free's flag test as an early return.
// 0x7100546c60
bool SiGfxPrimitiveDrawHelper::Unk_546c60(Unk_PrimitiveContext* pContext) {
    field_490 = pContext;
    Unk_PrimitiveDevice* pDevice = pContext->vf5();
    Unk_FreeBuffer();
    if (field_184) {
        return false;
    }
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    memset(&field_190, 0, sizeof(field_190));
#line 1324
    field_160 = static_cast<u8*>(UNK_ALLOC(pAllocator, 0x10000));
    if (field_160 == nullptr) {
        return false;
    }
    memset(field_160, 0, 0x10000);
    field_168 = field_160;
    field_170 = 0x10000;
    field_174 = 0;
    field_178 = 0;
    Unk_Setup();
    Unk_546c60_Desc desc;
    desc.field_10 = 0;
    desc.field_18 = 100.0f;
    desc.field_1c = 1;
    desc.field_20 = 8;
    for (int i = 0; i < 7; i++) {
        desc.field_24[i] = 0;
    }
    desc.field_0 = 3;
    desc.field_4 = 3;
    desc.field_8 = 3;
    desc.field_c = 3;
    field_ae0 = pDevice->vf52(&desc, nullptr, 0, nullptr);
    reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf33(&field_ae8);
    return true;
}

// Each case of the vertex format's switch is a statement of its own: LLVM's
// switch lowering then sees four destinations for kinds 2 to 6 and makes a
// jump table (the identical blocks are merged only after it), and
// LoopUnswitch takes kind 1 out of the loop alone.
// 0x7100546e80
bool SiGfxPrimitiveDrawHelper::Unk_546e80() {
    for (s32 i = 0; i < 6; i++) {
        for (s32 j = 0; j < 7; j++) {
            Unk_PrimitiveDevice* pDevice = field_490->vf5();
            u32 id = Unk_4ecf40(i, j);
            if (id != 0) {
                void* program = pDevice->vf46(id);
                if (program != nullptr) {
                    void* format = nullptr;
                    Unk_PrimitiveDevice* pFormats = field_490->vf5();
                    switch (i) {
                    case 1:
                        format = pFormats->vf39(5);
                        break;
                    case 2:
                        format = pFormats->vf39(5);
                        break;
                    case 3:
                        format = pFormats->vf39(6);
                        break;
                    case 4:
                        format = pFormats->vf39(6);
                        break;
                    case 5:
                        format = pFormats->vf39(6);
                        break;
                    case 6:
                        format = pFormats->vf39(6);
                        break;
                    }
                    if (format != nullptr) {
                        field_820.field_0[i][j] = program;
                        field_820.field_150[i][j] = format;
                    }
                }
            }
        }
    }
    return true;
}

// 0x71005472d0
bool SiGfxPrimitiveDrawHelper::Unk_5472d0(u32 mode) {
    if (field_184) {
        return false;
    }
    Unk_547360();
    field_17c = field_174 > 0 ? field_170 / field_174 : 0;
    field_180 = mode;
    field_184 = true;
    if (field_160 != nullptr) {
        field_168 = field_160;
        field_178 = 0;
        return true;
    }
    field_184 = false;
    return false;
}

// 0x7100547360
void SiGfxPrimitiveDrawHelper::Unk_547360() {
    const Unk_NXVertexLayout* pLayout;
    if (field_490->vf84()) {
        Unk_PrimitiveFormat* pFormat = field_490->vf85()->field_8;
        if (pFormat == nullptr) {
            return;
        }
        pLayout = pFormat->vf32();
    } else {
        if (field_490->vf33()->field_0 == nullptr) {
            return;
        }
        pLayout = &field_490->vf33()->field_0->vf10()->field_168;
    }
    if (memcmp(pLayout, &field_498, sizeof(field_498)) == 0) {
        return;
    }
    memset(field_20, 0xff, sizeof(field_20));
    memset(field_c0, 0xff, sizeof(field_c0));
    s32 size = 0;
    for (s64 i = 0; i < pLayout->field_380; i++) {
        const Unk_NXVertexLayout::Element& element = pLayout->field_0[i];
        field_20[element.field_0][element.field_4] = element.field_10;
        field_c0[element.field_0][element.field_4] = element.field_8;
        s32 end = element.field_10 + Unk_4ed0c0(element.field_8);
        if (end > size) {
            size = end;
        }
    }
    field_174 = size;
}

// 0x71005474b0
bool SiGfxPrimitiveDrawHelper::Unk_5474b0() {
    if (field_184) {
        Unk_547500(true, nullptr);
        field_184 = false;
        return true;
    }
    return false;
}

// The copy of the kept vertices is under a test of `last` of its own, with
// the source's address computed before the count is tested: the two tests
// stay apart (`last` first) and every case reaches the part after the
// switch through the first case's block. The kind of what is drawn is
// assigned with the word after it (an 8-byte store) before the kind is set.
// The vertices' copy is a plain `memcpy`.
// 0x7100547500
bool SiGfxPrimitiveDrawHelper::Unk_547500(bool last, const u8* pData) {
    if (!field_184) {
        return false;
    }
    if (pData == nullptr) {
        pData = field_160;
    }
    void* pVertices = field_490->vf74(0, field_178, field_174);
    memcpy(pVertices, pData, static_cast<s64>(field_178) * field_174);
    field_490->vf75();
    s32 primitives;
    s32 kept;
    switch (field_180) {
    case 1:
        primitives = field_178;
        kept = 0;
        break;
    case 2:
        primitives = field_178 / 2;
        kept = 0;
        break;
    case 3:
        primitives = field_178 - 1;
        kept = 1;
        break;
    case 4:
        primitives = field_178 / 3;
        kept = 0;
        break;
    case 5:
        primitives = field_178 - 2;
        kept = 2;
        break;
    default:
        return true;
    }
    if (primitives < 1) {
        return true;
    }
    if (!last) {
        const u8* pKept = pData + static_cast<s64>(field_178 - kept) * field_174;
        u8* pBuffer = field_190.field_100;
        if (kept != 0) {
            switch (kept) {
            case 1:
                Unk_4c9380(pBuffer, pKept, field_174);
                break;
            case 2:
                Unk_4c9380(&pBuffer[field_174], pKept, field_174);
                Unk_4c9380(pBuffer, pKept + field_174, field_174);
                break;
            }
        }
    }
    Unk_PrimitiveStates::Unk_DrawKind kind = {4, 0};
    field_490->vf85()->field_16c = kind;
    field_490->vf85()->field_16c.field_0 = field_180;
    field_490->vf85()->field_188 |= 4;
    field_490->vf24(field_178, 0, 1, 0);
    if (last) {
        return true;
    }
    if (field_160 == nullptr) {
        return false;
    }
    field_168 = field_160;
    field_178 = 0;
    if (kept != 0) {
        Unk_4c9380(field_160, field_190.field_100, field_174 * kept);
        field_178 += kept;
        field_168 += field_174 * kept;
    }
    return true;
}

// 0x7100547760
bool SiGfxPrimitiveDrawHelper::Unk_547760() {
    if (!field_184) {
        return false;
    }
    if (field_168 == nullptr) {
        return false;
    }
    if (field_168 >= field_160 + field_170) {
        return false;
    }
    Unk_4c9380(field_168, field_190.field_0, field_174);
    field_168 += field_174;
    if (++field_178 >= field_17c) {
        Unk_547500(false, nullptr);
    }
    return true;
}

// (The step is an int product, widened by the signed overflow rule: with
// the count widened first the two factors swap registers.)
// 0x7100547810
bool SiGfxPrimitiveDrawHelper::Unk_547810(s32 count, const u8* pVertices) {
    if (!field_184) {
        return false;
    }
    if (field_178 != 0) {
        return false;
    }
    while (count > 0) {
        s32 room = field_17c - field_178;
        s32 n = count < room ? count : room;
        count -= n;
        field_178 += n;
        Unk_547500(count == 0, pVertices);
        pVertices += n * field_174;
    }
    return true;
}

// 0x71005478f0
bool SiGfxPrimitiveDrawHelper::Unk_5478f0(const void* pVertex) {
    if (!field_184) {
        return false;
    }
    Unk_4c9380(field_190.field_0, pVertex, field_174);
    return true;
}

// The setters' switches: the order of the cases decides which tails the
// branch folder merges (case 41 before 28 here: 87 branches into 28's last
// store). Where the cases store through single stores the element's address
// is computed in each case (`add x8, x0, x9` with the field's offset in the
// stores), which also keeps the result out of w0 until the return.
// 0x7100547930
bool SiGfxPrimitiveDrawHelper::Unk_547930(u32 row, s32 column, f32 x, f32 y, f32 z, f32 w) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = x;
        f[1] = y;
        f[2] = z;
        f[3] = w;
        return true;
    case 6:
        f[0] = x;
        f[1] = y;
        f[2] = z;
        break;
    case 16:
        f[0] = x;
        f[1] = y;
        break;
    case 41:
        f[0] = x;
        break;
    case 28:
        p[0] = static_cast<u8>(x * 255.0f);
        p[1] = static_cast<u8>(y * 255.0f);
        p[2] = static_cast<u8>(z * 255.0f);
        p[3] = static_cast<u8>(w * 255.0f);
        break;
    case 87:
        p[2] = static_cast<u8>(x * 255.0f);
        p[1] = static_cast<u8>(y * 255.0f);
        p[0] = static_cast<u8>(z * 255.0f);
        p[3] = static_cast<u8>(w * 255.0f);
        break;
    default:
        return false;
    }
    return true;
}

// 0x7100547a40
bool SiGfxPrimitiveDrawHelper::Unk_547a40(u32 row, s32 column, const f32* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = 0.0f;
        f[3] = 0.0f;
        break;
    case 6:
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = 0.0f;
        break;
    case 16:
        f[0] = pValues[0];
        f[1] = pValues[1];
        break;
    case 28:
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = 0;
        p[3] = 0;
        break;
    case 41:
        f[0] = pValues[0];
        break;
    case 87:
        p[2] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[0] = 0;
        p[3] = 0;
        break;
    default:
        return false;
    }
    return true;
}

// 0x7100547b60
bool SiGfxPrimitiveDrawHelper::Unk_547b60(u32 row, s32 column, const f32* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = pValues[2];
        f[3] = 0.0f;
        break;
    case 6:
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = pValues[2];
        break;
    case 16:
        f[0] = pValues[0];
        f[1] = pValues[1];
        break;
    case 41:
        f[0] = pValues[0];
        break;
    case 28:
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = 0;
        break;
    case 87:
        p[2] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[0] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = 0;
        break;
    default:
        return false;
    }
    return true;
}

// 0x7100547ca0
bool SiGfxPrimitiveDrawHelper::Unk_547ca0(u32 row, s32 column, const f32* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = pValues[2];
        f[3] = pValues[3];
        break;
    case 6:
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = pValues[2];
        break;
    case 16:
        f[0] = pValues[0];
        f[1] = pValues[1];
        break;
    case 28:
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    case 41:
        f[0] = pValues[0];
        break;
    case 87:
        p[2] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[0] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    default:
        return false;
    }
    return true;
}

// 0x7100547df0
bool SiGfxPrimitiveDrawHelper::Unk_547df0(u32 row, s32 column, u8 r, u8 g, u8 b, u8 a) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8 offset = field_20[row][column];
    switch (format) {
    case 2: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(r) / 255.0f;
        f[1] = static_cast<f32>(g) / 255.0f;
        f[2] = static_cast<f32>(b) / 255.0f;
        f[3] = static_cast<f32>(a) / 255.0f;
        break;
    }
    case 6: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(r) / 255.0f;
        f[1] = static_cast<f32>(g) / 255.0f;
        f[2] = static_cast<f32>(b) / 255.0f;
        break;
    }
    case 28: {
        u8* p = &field_190.field_0[offset];
        p[0] = r;
        p[1] = g;
        p[2] = b;
        p[3] = a;
        break;
    }
    case 16: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(r) / 255.0f;
        f[1] = static_cast<f32>(g) / 255.0f;
        break;
    }
    case 87: {
        u8* p = &field_190.field_0[offset];
        p[2] = r;
        p[1] = g;
        p[0] = b;
        p[3] = a;
        break;
    }
    default:
        return false;
    }
    return true;
}

// 0x7100547f50
bool SiGfxPrimitiveDrawHelper::Unk_547f50(u32 row, s32 column, const u8* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8 offset = field_20[row][column];
    switch (format) {
    case 2: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        f[3] = static_cast<f32>(pValues[3]) / 255.0f;
        break;
    }
    case 6: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        break;
    }
    case 16: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        break;
    }
    case 28: {
        u8* p = &field_190.field_0[offset];
        p[0] = pValues[0];
        p[1] = pValues[1];
        p[2] = pValues[2];
        p[3] = pValues[3];
        break;
    }
    case 87: {
        u8* p = &field_190.field_0[offset];
        p[2] = pValues[0];
        p[1] = pValues[1];
        p[0] = pValues[2];
        p[3] = pValues[3];
        break;
    }
    default:
        return false;
    }
    return true;
}

// 0x71005480c0
bool SiGfxPrimitiveDrawHelper::Unk_5480c0(u32 row, s32 column, const u8* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8 offset = field_20[row][column];
    switch (format) {
    case 2: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        f[3] = static_cast<f32>(pValues[3]) / 255.0f;
        break;
    }
    case 6: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        break;
    }
    case 16: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        break;
    }
    case 28: {
        u8* p = &field_190.field_0[offset];
        p[0] = pValues[0];
        p[1] = pValues[1];
        p[2] = pValues[2];
        p[3] = pValues[3];
        break;
    }
    case 87: {
        u8* p = &field_190.field_0[offset];
        p[2] = pValues[0];
        p[1] = pValues[1];
        p[0] = pValues[2];
        p[3] = pValues[3];
        break;
    }
    default:
        return false;
    }
    return true;
}

// 0x7100548230
bool SiGfxPrimitiveDrawHelper::Unk_548230(u32 row, s32 column, const f32* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8 offset = field_20[row][column];
    switch (format) {
    case 2: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = pValues[2];
        f[3] = pValues[3];
        break;
    }
    case 6: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = pValues[0];
        f[1] = pValues[1];
        f[2] = pValues[2];
        break;
    }
    case 16: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = pValues[0];
        f[1] = pValues[1];
        break;
    }
    case 28: {
        u8* p = &field_190.field_0[offset];
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    }
    case 87: {
        u8* p = &field_190.field_0[offset];
        p[2] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[0] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    }
    default:
        return false;
    }
    return true;
}

// 0x7100548380
bool SiGfxPrimitiveDrawHelper::Unk_548380(u32 row, s32 column, const u8* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8 offset = field_20[row][column];
    switch (format) {
    case 2: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[2]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[0]) / 255.0f;
        f[3] = static_cast<f32>(pValues[3]) / 255.0f;
        break;
    }
    case 6: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[2]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[0]) / 255.0f;
        break;
    }
    case 16: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = static_cast<f32>(pValues[2]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        break;
    }
    case 28: {
        u8* p = &field_190.field_0[offset];
        p[0] = pValues[2];
        p[1] = pValues[1];
        p[2] = pValues[0];
        p[3] = pValues[3];
        break;
    }
    case 87: {
        u8* p = &field_190.field_0[offset];
        p[2] = pValues[2];
        p[1] = pValues[1];
        p[0] = pValues[0];
        p[3] = pValues[3];
        break;
    }
    default:
        return false;
    }
    return true;
}

// 0x71005484f0
bool SiGfxPrimitiveDrawHelper::Unk_5484f0(u32 row, s32 column, const f32* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8 offset = field_20[row][column];
    switch (format) {
    case 2: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = pValues[2];
        f[1] = pValues[1];
        f[2] = pValues[0];
        f[3] = pValues[3];
        break;
    }
    case 6: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = pValues[2];
        f[1] = pValues[1];
        f[2] = pValues[0];
        break;
    }
    case 16: {
        f32* f = reinterpret_cast<f32*>(&field_190.field_0[offset]);
        f[0] = pValues[2];
        f[1] = pValues[1];
        break;
    }
    case 28: {
        u8* p = &field_190.field_0[offset];
        p[0] = static_cast<u8>(pValues[2] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = static_cast<u8>(pValues[0] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    }
    case 87: {
        u8* p = &field_190.field_0[offset];
        p[2] = static_cast<u8>(pValues[2] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    }
    default:
        return false;
    }
    return true;
}


// The uniforms slot 58 draws a texture with (placeholder name and members).
struct Unk_PrimitiveTextureUniforms {
    Unk_PrimitiveMatrix field_0;   // the projection
    Unk_PrimitiveMatrix field_40;  // the description's matrix
    u32 field_80[4];               // its colours
    f32 field_90;                  // the level
    u32 field_94[3];
    f32 field_a0;
    u32 field_a4[3];
    f32 field_b0;
    u32 field_b4;
    u32 field_b8;
    u32 field_bc;
};
PKMN_SIZE_ASSERT(Unk_PrimitiveTextureUniforms, 0xc0);

// What slot 58 gives the context's slot 18 (placeholder name and members).
struct Unk_PrimitiveTextureState {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
};


// 0x7100548a70
bool SiGfxPrimitiveDrawHelper::Unk_548a70(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc,
                                          const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    if (pTexture == nullptr) {
        return false;
    }
    Unk_PrimitiveStates* states = field_490->vf85();
    states->field_0 = field_820.field_0[2][desc->field_80];
    states->field_8 = static_cast<Unk_PrimitiveFormat*>(field_820.field_150[2][desc->field_80]);
    states->field_188 |= 0xffff;
    Unk_PrimitiveTexelOffset offset = Unk_4ed720(reinterpret_cast<Unk_4ed720_Context*>(pTexture));
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    if (source != nullptr) {
        if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
            return false;
        }
        left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
        top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
        right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
        bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
    } else {
        left = 0.0f;
        top = 0.0f;
        right = 1.0f;
        bottom = 1.0f;
    }
    left += offset.field_0;
    right += offset.field_0;
    top += offset.field_4;
    bottom += offset.field_4;
    f32 x0 = dest->field_0;
    f32 x1 = dest->field_4;
    f32 y0 = dest->field_8;
    f32 y1 = dest->field_c;
    bool upright = !pTexture->vf19()->field_38;
    f32 v0 = upright ? top : bottom;
    f32 v1 = upright ? bottom : top;
    top = v0;
    bottom = v1;
    Unk_5472d0(5);
    Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
    Unk_547930(5, 0, left, bottom, 0.0f, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
    Unk_547930(5, 0, right, bottom, 0.0f, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
    Unk_547930(5, 0, left, top, 0.0f, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
    Unk_547930(5, 0, right, top, 0.0f, 1.0f);
    Unk_547760();
    Unk_5474b0();
    return true;
}


// The cube's arrays stay in memory as the original's do: the faces' margins
// and the corners' coordinates are set in loops (unrolled after SROA ran),
// and the corners' defaults are stored by a loop over the axes (a whole
// initializer becomes a copy from rodata). The begin, vertex and end calls
// are inlined here, as in the original.
// NON_MATCHING: registers only, in the one-face cases: the original spills
// the destination's bottom in cases 1 and 4 where this spills the texture's
// top (as both do in case 3), which changes two shared tails (12 bytes
// short); the offset's last add of each axis has its operands the other way
// round. Tried: the offsets' four adds in every order and as `x = x + o` or
// `x = o + x`, the cases in reverse order, the destination's four locals in
// every order, the texture coordinates declared once before the switch.
// 0x7100548f70: a cube's six faces unfolded into a cross, or one face
bool SiGfxPrimitiveDrawHelper::Unk_548f70(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc,
                                          const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    if (!desc->field_54) {
        return Unk_548a70(pTexture, desc, dest, source);
    }
    if (pTexture == nullptr) {
        return false;
    }
    Unk_PrimitiveStates* states = field_490->vf85();
    states->field_0 = field_820.field_0[4][desc->field_80];
    states->field_8 = static_cast<Unk_PrimitiveFormat*>(field_820.field_150[4][desc->field_80]);
    states->field_188 |= 0xffff;
    Unk_PrimitiveTexelOffset offset = Unk_4ed720(reinterpret_cast<Unk_4ed720_Context*>(pTexture));
    if (desc->field_54) {
        f32 faces[6][4] = {};  // each face's left, top, right and bottom
        f32 width = dest->field_4 - dest->field_0;
        f32 height = dest->field_c - dest->field_8;
        f32 cellWidth = width / 4.0f;
        f32 cellHeight = height / 3.0f;
        if (cellWidth < cellHeight) {
            cellHeight = cellWidth;
        } else if (cellHeight < cellWidth) {
            cellWidth = cellHeight;
        }
        f32 marginX = (width - cellWidth * 4.0f) * 0.5f;
        f32 marginY = (height - cellHeight * 3.0f) * 0.5f;
        faces[0][0] = dest->field_0 + cellWidth * 2.0f;
        faces[0][1] = dest->field_8 + cellHeight;
        faces[0][2] = dest->field_0 + cellWidth * 3.0f;
        faces[0][3] = dest->field_8 + cellHeight * 2.0f;
        faces[1][0] = dest->field_0;
        faces[1][1] = dest->field_8 + cellHeight;
        faces[1][2] = dest->field_0 + cellWidth;
        faces[1][3] = dest->field_8 + cellHeight * 2.0f;
        faces[2][0] = dest->field_0 + cellWidth;
        faces[2][1] = dest->field_8;
        faces[2][2] = dest->field_0 + cellWidth * 2.0f;
        faces[2][3] = dest->field_8 + cellHeight;
        faces[3][0] = dest->field_0 + cellWidth;
        faces[3][1] = dest->field_8 + cellHeight * 2.0f;
        faces[3][2] = dest->field_0 + cellWidth * 2.0f;
        faces[3][3] = dest->field_8 + cellHeight * 3.0f;
        faces[4][0] = dest->field_0 + cellWidth;
        faces[4][1] = dest->field_8 + cellHeight;
        faces[4][2] = dest->field_0 + cellWidth * 2.0f;
        faces[4][3] = dest->field_8 + cellHeight * 2.0f;
        faces[5][0] = dest->field_0 + cellWidth * 3.0f;
        faces[5][1] = dest->field_8 + cellHeight;
        faces[5][2] = dest->field_0 + cellWidth * 4.0f;
        faces[5][3] = dest->field_8 + cellHeight * 2.0f;
        for (s32 i = 0; i < 6; i++) {
            faces[i][0] = marginX + faces[i][0];
            faces[i][1] = marginY + faces[i][1];
            faces[i][2] = marginX + faces[i][2];
            faces[i][3] = marginY + faces[i][3];
        }
        // the cube's coordinates at the corners of the faces across each axis:
        // the lowest and the highest
        f32 corners[3][2][3];
        for (s32 axis = 0; axis < 3; axis++) {
            corners[axis][0][0] = -1.0f;
            corners[axis][0][1] = -1.0f;
            corners[axis][0][2] = -1.0f;
            corners[axis][1][0] = 1.0f;
            corners[axis][1][1] = 1.0f;
            corners[axis][1][2] = 1.0f;
        }
        if (source != nullptr) {
            if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                return false;
            }
            for (s32 axis = 0; axis < 3; axis++) {
                s32 u = axis == 0 ? 2 : 0;
                s32 v = axis == 1 ? 2 : 1;
                corners[axis][0][u] = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                corners[axis][0][v] = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                corners[axis][1][u] = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                corners[axis][1][v] = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
                corners[axis][0][u] += offset.field_0;
                corners[axis][0][v] += offset.field_4;
                corners[axis][1][u] += offset.field_0;
                corners[axis][1][v] += offset.field_4;
            }
        }
        Unk_5472d0(5);
        Unk_547930(0, 0, faces[0][0], faces[0][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][1][0], corners[0][1][1], corners[0][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[0][2], faces[0][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][1][0], corners[0][1][1], corners[0][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[0][0], faces[0][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][1][0], corners[0][0][1], corners[0][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[0][2], faces[0][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][1][0], corners[0][0][1], corners[0][0][2], 1.0f);
        Unk_547760();
        Unk_5474b0();
        Unk_5472d0(5);
        Unk_547930(0, 0, faces[1][0], faces[1][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][0][0], corners[0][1][1], corners[0][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[1][2], faces[1][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][0][0], corners[0][1][1], corners[0][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[1][0], faces[1][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][0][0], corners[0][0][1], corners[0][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[1][2], faces[1][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[0][0][0], corners[0][0][1], corners[0][1][2], 1.0f);
        Unk_547760();
        Unk_5474b0();
        Unk_5472d0(5);
        Unk_547930(0, 0, faces[2][0], faces[2][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][0][0], corners[1][1][1], corners[1][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[2][2], faces[2][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][1][0], corners[1][1][1], corners[1][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[2][0], faces[2][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][0][0], corners[1][1][1], corners[1][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[2][2], faces[2][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][1][0], corners[1][1][1], corners[1][1][2], 1.0f);
        Unk_547760();
        Unk_5474b0();
        Unk_5472d0(5);
        Unk_547930(0, 0, faces[3][0], faces[3][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][0][0], corners[1][0][1], corners[1][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[3][2], faces[3][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][1][0], corners[1][0][1], corners[1][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[3][0], faces[3][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][0][0], corners[1][0][1], corners[1][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[3][2], faces[3][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[1][1][0], corners[1][0][1], corners[1][0][2], 1.0f);
        Unk_547760();
        Unk_5474b0();
        Unk_5472d0(5);
        Unk_547930(0, 0, faces[4][0], faces[4][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][0][0], corners[2][1][1], corners[2][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[4][2], faces[4][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][1][0], corners[2][1][1], corners[2][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[4][0], faces[4][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][0][0], corners[2][0][1], corners[2][1][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[4][2], faces[4][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][1][0], corners[2][0][1], corners[2][1][2], 1.0f);
        Unk_547760();
        Unk_5474b0();
        Unk_5472d0(5);
        Unk_547930(0, 0, faces[5][0], faces[5][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][1][0], corners[2][1][1], corners[2][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[5][2], faces[5][1], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][0][0], corners[2][1][1], corners[2][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[5][0], faces[5][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][1][0], corners[2][0][1], corners[2][0][2], 1.0f);
        Unk_547760();
        Unk_547930(0, 0, faces[5][2], faces[5][3], 0.0f, 1.0f);
        Unk_547930(5, 0, corners[2][0][0], corners[2][0][1], corners[2][0][2], 1.0f);
        Unk_547760();
        Unk_5474b0();
    } else {
        f32 x0 = dest->field_0;
        f32 x1 = dest->field_4;
        f32 y0 = dest->field_8;
        f32 y1 = dest->field_c;
        switch (desc->field_58) {
        case 0: {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            if (source != nullptr) {
                if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                    return false;
                }
                left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
            } else {
                left = -1.0f;
                top = -1.0f;
                right = 1.0f;
                bottom = 1.0f;
            }
            left += offset.field_0;
            right += offset.field_0;
            top += offset.field_4;
            bottom += offset.field_4;
            Unk_5472d0(5);
            Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, 1.0f, bottom, right, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, 1.0f, bottom, left, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, 1.0f, top, right, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, 1.0f, top, left, 1.0f);
            Unk_547760();
            Unk_5474b0();
            break;
        }
        case 1: {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            if (source != nullptr) {
                if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                    return false;
                }
                left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
            } else {
                left = -1.0f;
                top = -1.0f;
                right = 1.0f;
                bottom = 1.0f;
            }
            left += offset.field_0;
            right += offset.field_0;
            top += offset.field_4;
            bottom += offset.field_4;
            Unk_5472d0(5);
            Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, -1.0f, bottom, left, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, -1.0f, bottom, right, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, -1.0f, top, left, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, -1.0f, top, right, 1.0f);
            Unk_547760();
            Unk_5474b0();
            break;
        }
        case 2: {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            if (source != nullptr) {
                if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                    return false;
                }
                left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
            } else {
                left = -1.0f;
                top = -1.0f;
                right = 1.0f;
                bottom = 1.0f;
            }
            left += offset.field_0;
            right += offset.field_0;
            top += offset.field_4;
            bottom += offset.field_4;
            Unk_5472d0(5);
            Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, left, 1.0f, top, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, right, 1.0f, top, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, left, 1.0f, bottom, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, right, 1.0f, bottom, 1.0f);
            Unk_547760();
            Unk_5474b0();
            break;
        }
        case 3: {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            if (source != nullptr) {
                if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                    return false;
                }
                left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
            } else {
                left = -1.0f;
                top = -1.0f;
                right = 1.0f;
                bottom = 1.0f;
            }
            left += offset.field_0;
            right += offset.field_0;
            top += offset.field_4;
            bottom += offset.field_4;
            Unk_5472d0(5);
            Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, left, -1.0f, bottom, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, right, -1.0f, bottom, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, left, -1.0f, top, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, right, -1.0f, top, 1.0f);
            Unk_547760();
            Unk_5474b0();
            break;
        }
        case 4: {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            if (source != nullptr) {
                if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                    return false;
                }
                left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
            } else {
                left = -1.0f;
                top = -1.0f;
                right = 1.0f;
                bottom = 1.0f;
            }
            left += offset.field_0;
            right += offset.field_0;
            top += offset.field_4;
            bottom += offset.field_4;
            Unk_5472d0(5);
            Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, left, bottom, 1.0f, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, right, bottom, 1.0f, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, left, top, 1.0f, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, right, top, 1.0f, 1.0f);
            Unk_547760();
            Unk_5474b0();
            break;
        }
        case 5: {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            if (source != nullptr) {
                if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                    return false;
                }
                left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
                top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
                right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
                bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
            } else {
                left = -1.0f;
                top = -1.0f;
                right = 1.0f;
                bottom = 1.0f;
            }
            left += offset.field_0;
            right += offset.field_0;
            top += offset.field_4;
            bottom += offset.field_4;
            Unk_5472d0(5);
            Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, right, bottom, -1.0f, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
            Unk_547930(5, 0, left, bottom, -1.0f, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, right, top, -1.0f, 1.0f);
            Unk_547760();
            Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
            Unk_547930(5, 0, left, top, -1.0f, 1.0f);
            Unk_547760();
            Unk_5474b0();
            break;
        }
        }
    }
    return true;
}

// 0x710054bb60
bool SiGfxPrimitiveDrawHelper::Unk_54bb60(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc,
                                          const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    if (pTexture == nullptr) {
        return false;
    }
    Unk_PrimitiveStates* states = field_490->vf85();
    states->field_0 = field_820.field_0[3][desc->field_80];
    states->field_8 = static_cast<Unk_PrimitiveFormat*>(field_820.field_150[3][desc->field_80]);
    states->field_188 |= 0xffff;
    Unk_PrimitiveTexelOffset offset = Unk_4ed720(reinterpret_cast<Unk_4ed720_Context*>(pTexture));
    f32 slice = desc->field_5c;
    f32 depth = static_cast<f32>(pTexture->vf19()->field_1c);
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    if (source != nullptr) {
        if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
            return false;
        }
        left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
        top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
        right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
        bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
    } else {
        left = 0.0f;
        top = 0.0f;
        right = 1.0f;
        bottom = 1.0f;
    }
    f32 w = slice / depth;
    left += offset.field_0;
    right += offset.field_0;
    top += offset.field_4;
    bottom += offset.field_4;
    f32 x0 = dest->field_0;
    f32 x1 = dest->field_4;
    f32 y0 = dest->field_8;
    f32 y1 = dest->field_c;
    Unk_5472d0(5);
    Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
    Unk_547930(5, 0, left, top, w, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
    Unk_547930(5, 0, right, top, w, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
    Unk_547930(5, 0, left, bottom, w, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
    Unk_547930(5, 0, right, bottom, w, 1.0f);
    Unk_547760();
    Unk_5474b0();
    return true;
}


// NON_MATCHING: the grid's loops are laid out differently: the original
// tests the next cell against the last at the end of each column (`cmp w28,
// w24 ; b.ge`) and keeps the row's first cell in a register of its own; the
// clamps of the layers and the single layer's path are the original's.
// 0x710054c070: all layers of the array in a grid, or one
bool SiGfxPrimitiveDrawHelper::Unk_54c070(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc,
                                          const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    if (pTexture == nullptr) {
        return false;
    }
    Unk_PrimitiveStates* states = field_490->vf85();
    states->field_0 = field_820.field_0[5][desc->field_80];
    states->field_8 = static_cast<Unk_PrimitiveFormat*>(field_820.field_150[5][desc->field_80]);
    states->field_188 |= 0xffff;
    if (desc->field_60) {
        Unk_PrimitiveTexelOffset offset = Unk_4ed720(reinterpret_cast<Unk_4ed720_Context*>(pTexture));
        s32 count = pTexture->vf19()->field_24;
        s32 first = 0;
        if (desc->field_68 >= 0 && desc->field_68 < count) {
            first = desc->field_68;
        }
        s32 last = count - 1;
        if (desc->field_6c >= first && desc->field_6c < count) {
            last = desc->field_6c;
        }
        s32 n = last - first;
        s32 cells = n < 1 ? 1 : static_cast<s32>(ceilf(sqrtf(static_cast<f32>(n + 1))));
        f32 left;
        f32 top;
        f32 right;
        f32 bottom;
        if (source != nullptr) {
            if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                return false;
            }
            left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
            top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
            right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
            bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
        } else {
            left = 0.0f;
            top = 0.0f;
            right = 1.0f;
            bottom = 1.0f;
        }
        left += offset.field_0;
        right += offset.field_0;
        top += offset.field_4;
        bottom += offset.field_4;
        f32 cellWidth = (dest->field_4 - dest->field_0) / static_cast<f32>(cells);
        f32 cellHeight = (dest->field_c - dest->field_8) / static_cast<f32>(cells);
        f32 y0 = dest->field_8;
        f32 y1 = y0;
        for (s32 row = 0; row < cells; row++) {
            f32 x0 = dest->field_0;
            f32 x1 = x0;
            y1 += cellHeight;
            s32 cell = row * cells;
            for (s32 column = 0; column < cells; column++, cell++) {
                if (cell > n) {
                    break;
                }
                f32 layer = static_cast<f32>(first + cell);
                x1 += cellWidth;
                Unk_5472d0(5);
                Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
                Unk_547930(5, 0, left, top, layer, 1.0f);
                Unk_547760();
                Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
                Unk_547930(5, 0, right, top, layer, 1.0f);
                Unk_547760();
                Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
                Unk_547930(5, 0, left, bottom, layer, 1.0f);
                Unk_547760();
                Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
                Unk_547930(5, 0, right, bottom, layer, 1.0f);
                Unk_547760();
                Unk_5474b0();
                x0 += cellWidth;
            }
            y0 += cellHeight;
        }
    } else {
        Unk_PrimitiveTexelOffset offset = Unk_4ed720(reinterpret_cast<Unk_4ed720_Context*>(pTexture));
        f32 left;
        f32 top;
        f32 right;
        f32 bottom;
        if (source != nullptr) {
            if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
                return false;
            }
            left = source->field_0 / static_cast<f32>(pTexture->vf19()->field_14);
            top = source->field_8 / static_cast<f32>(pTexture->vf19()->field_18);
            right = source->field_4 / static_cast<f32>(pTexture->vf19()->field_14);
            bottom = source->field_c / static_cast<f32>(pTexture->vf19()->field_18);
        } else {
            left = 0.0f;
            top = 0.0f;
            right = 1.0f;
            bottom = 1.0f;
        }
        left += offset.field_0;
        right += offset.field_0;
        top += offset.field_4;
        bottom += offset.field_4;
        f32 x0 = dest->field_0;
        f32 x1 = dest->field_4;
        f32 y0 = dest->field_8;
        f32 y1 = dest->field_c;
        bool upright = !pTexture->vf19()->field_38;
        f32 v0 = upright ? top : bottom;
        f32 v1 = upright ? bottom : top;
        top = v0;
        bottom = v1;
        f32 layer = static_cast<f32>(desc->field_64);
        Unk_5472d0(5);
        Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
        Unk_547930(5, 0, left, bottom, layer, 1.0f);
        Unk_547760();
        Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
        Unk_547930(5, 0, right, bottom, layer, 1.0f);
        Unk_547760();
        Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
        Unk_547930(5, 0, left, top, layer, 1.0f);
        Unk_547760();
        Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
        Unk_547930(5, 0, right, top, layer, 1.0f);
        Unk_547760();
        Unk_5474b0();
    }
    return true;
}

// NON_MATCHING: for a cube's level that isn't a whole number the original
// gives the copy of the texture into the view's register a block of its own
// after the call's (a split edge); here it is put before the branch, as for
// the two tests before it (5 lines). Tried: if/else forms, the tests nested
// or in one condition, the level's test negated, the call in each branch.
// 0x7100548640
bool SiGfxPrimitiveDrawHelper::Unk_548640(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc,
                                          const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    if (pTexture == nullptr) {
        return false;
    }
    if (desc->field_85) {
        if (dest->field_0 > desc->field_8c || dest->field_4 < desc->field_88 || dest->field_8 > desc->field_94 ||
            dest->field_c < desc->field_90) {
            return true;
        }
    }
    Unk_PrimitiveContext* pContext = field_490;
    pContext->vf83(true);
    Unk_PrimitiveStates* states = pContext->vf85();
    states->field_10 = 1;
    states->field_2d = desc->field_85;
    states->field_14 = 3;
    states->field_34 = false;
    states->field_35 = false;
    states->field_16c.field_0 = 5;
    states->field_60[0].field_0 = desc->field_84;
    states->field_60[0].field_c = 1;
    states->field_60[0].field_10 = 5;
    states->field_60[0].field_4 = 5;
    states->field_60[0].field_8 = 6;
    states->field_60[0].field_14 = 6;
    states->field_60[0].field_18 = 1;
    if (desc->field_85) {
        s32 scissor[4];
        scissor[0] = desc->field_88;
        scissor[1] = desc->field_8c;
        scissor[2] = desc->field_90;
        scissor[3] = desc->field_94;
        pContext->vf15(1, scissor);
    }
    Unk_PrimitiveTextureState state;
    state.field_10 = 0;
    state.field_14 = 0x3f;
    state.field_0 = 1;
    state.field_4 = 3;
    state.field_8 = 1;
    state.field_c = 2;
    state.field_18 = 1;
    state.field_1c = 2;
    pContext->vf18(1, &state);
    Unk_PrimitiveTexture* pView = pTexture;
    if (pTexture->vf19()->field_0 == 4 && !desc->field_54) {
        f32 level = desc->field_40;
        pView = floorf(level) == level ? pTexture->vf26(desc->field_58, static_cast<s32>(level)) : pTexture;
    }
    pContext->vf92(1, 2, 0, pView);
    pContext->vf94(1, 2, 0, field_ae0);
    Unk_PrimitiveTextureUniforms* uniforms = reinterpret_cast<Unk_PrimitiveTextureUniforms*>(pContext->vf72(1, 3, 0, 0xc0));
    f32 width = pContext->vf33()->field_34;
    f32 height = pContext->vf33()->field_38;
    uniforms->field_0 = Unk_4ee020(width, height, 1.0f, 2.0f);
    uniforms->field_40 = *reinterpret_cast<const Unk_PrimitiveMatrix*>(desc->field_0);
    uniforms->field_80[0] = desc->field_44[0];
    uniforms->field_80[1] = desc->field_44[1];
    uniforms->field_80[2] = desc->field_44[2];
    uniforms->field_80[3] = desc->field_44[3];
    uniforms->field_90 = desc->field_40;
    uniforms->field_94[0] = 0;
    uniforms->field_94[1] = 0;
    uniforms->field_94[2] = 0;
    uniforms->field_a0 = static_cast<f32>(desc->field_64);
    uniforms->field_a4[0] = 0;
    uniforms->field_a4[1] = 0;
    uniforms->field_a4[2] = 0;
    uniforms->field_b0 = desc->field_70 ? 1.0f : 0.0f;
    uniforms->field_b4 = desc->field_74;
    uniforms->field_b8 = desc->field_78;
    uniforms->field_bc = 0;
    pContext->vf73();
    bool result;
    switch (pTexture->vf19()->field_0) {
    case 2:
        result = Unk_548a70(pTexture, desc, dest, source);
        break;
    case 3:
        result = Unk_54bb60(pTexture, desc, dest, source);
        break;
    case 4:
        result = Unk_548f70(pTexture, desc, dest, source);
        break;
    case 5:
        result = Unk_54c070(pTexture, desc, dest, source);
        break;
    default:
        return false;
    }
    pContext->vf83(false);
    return result;
}


// 0x710054cab0
bool SiGfxPrimitiveDrawHelper::Unk_54cab0(Unk_PrimitiveTexture* pPlane0, Unk_PrimitiveTexture* pPlane1,
                                          Unk_PrimitiveTexture* pPlane2, Unk_PrimitiveTexture* pPlane3,
                                          const Unk_PrimitiveTextureDesc* desc, const Unk_PrimitiveRect* dest,
                                          const Unk_PrimitiveRect* source) {
    if (desc->field_85) {
        if (dest->field_0 > desc->field_8c || dest->field_4 < desc->field_88 || dest->field_8 > desc->field_94 ||
            dest->field_c < desc->field_90) {
            return true;
        }
    }
    Unk_PrimitiveContext* pContext = field_490;
    pContext->vf83(true);
    Unk_PrimitiveStates* states = pContext->vf85();
    states->field_10 = 1;
    states->field_2d = desc->field_85;
    states->field_34 = false;
    states->field_35 = false;
    states->field_16c.field_0 = 5;
    states->field_60[0].field_0 = desc->field_84;
    states->field_60[0].field_c = 1;
    states->field_60[0].field_10 = 5;
    states->field_60[0].field_4 = 5;
    states->field_60[0].field_8 = 6;
    states->field_60[0].field_14 = 6;
    states->field_60[0].field_18 = 1;
    if (desc->field_85) {
        s32 scissor[4];
        scissor[0] = desc->field_88;
        scissor[1] = desc->field_8c;
        scissor[2] = desc->field_90;
        scissor[3] = desc->field_94;
        pContext->vf15(1, scissor);
    }
    Unk_PrimitiveTextureState state;
    state.field_10 = 0;
    state.field_14 = 0x3f;
    state.field_0 = 1;
    state.field_4 = 3;
    state.field_8 = pPlane3 != nullptr ? 4 : 3;
    state.field_c = 2;
    state.field_18 = 1;
    state.field_1c = 2;
    pContext->vf18(1, &state);
    pContext->vf92(1, 2, 0, pPlane0);
    pContext->vf92(1, 2, 1, pPlane1);
    pContext->vf92(1, 2, 2, pPlane2);
    // (the original binds the third plane again in the fourth's slot)
    if (pPlane3 != nullptr) {
        pContext->vf92(1, 2, 3, pPlane2);
    }
    pContext->vf94(1, 2, 0, field_ae0);
    Unk_PrimitiveTextureUniforms* uniforms = reinterpret_cast<Unk_PrimitiveTextureUniforms*>(pContext->vf72(1, 3, 0, 0xc0));
    f32 width = static_cast<f32>(pContext->vf33()->field_20->vf17()->field_0);
    f32 height = static_cast<f32>(pContext->vf33()->field_20->vf17()->field_4);
    uniforms->field_0 = Unk_4ee020(width, height, 1.0f, 2.0f);
    uniforms->field_40 = *reinterpret_cast<const Unk_PrimitiveMatrix*>(desc->field_0);
    uniforms->field_80[0] = desc->field_44[0];
    uniforms->field_80[1] = desc->field_44[1];
    uniforms->field_80[2] = desc->field_44[2];
    uniforms->field_80[3] = desc->field_44[3];
    uniforms->field_90 = desc->field_40;
    uniforms->field_94[0] = 0;
    uniforms->field_94[1] = 0;
    uniforms->field_94[2] = 0;
    uniforms->field_a0 = static_cast<f32>(desc->field_64);
    uniforms->field_a4[0] = 0;
    uniforms->field_a4[1] = 0;
    uniforms->field_a4[2] = 0;
    uniforms->field_b0 = desc->field_70 ? 1.0f : 0.0f;
    uniforms->field_b4 = desc->field_74;
    uniforms->field_b8 = desc->field_78;
    uniforms->field_bc = 0;
    pContext->vf73();
    if (pPlane3 != nullptr) {
        states->field_0 = field_820.field_2a0[1];
        states->field_8 = static_cast<Unk_PrimitiveFormat*>(field_820.field_2b0[1]);
    } else {
        states->field_0 = field_820.field_2a0[0];
        states->field_8 = static_cast<Unk_PrimitiveFormat*>(field_820.field_2b0[0]);
    }
    states->field_188 |= 0xffff;
    Unk_PrimitiveTexelOffset offset = Unk_4ed720(reinterpret_cast<Unk_4ed720_Context*>(pPlane0));
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    if (source != nullptr) {
        if (source->field_4 - source->field_0 <= 0.0f || source->field_c - source->field_8 <= 0.0f) {
            return false;
        }
        left = source->field_0 / static_cast<f32>(pPlane0->vf19()->field_14);
        top = source->field_8 / static_cast<f32>(pPlane0->vf19()->field_18);
        right = source->field_4 / static_cast<f32>(pPlane0->vf19()->field_14);
        bottom = source->field_c / static_cast<f32>(pPlane0->vf19()->field_18);
    } else {
        left = 0.0f;
        top = 0.0f;
        right = 1.0f;
        bottom = 1.0f;
    }
    left += offset.field_0;
    right += offset.field_0;
    top += offset.field_4;
    bottom += offset.field_4;
    f32 x0 = dest->field_0;
    f32 x1 = dest->field_4;
    f32 y0 = dest->field_8;
    f32 y1 = dest->field_c;
    bool upright = !pPlane0->vf19()->field_38;
    f32 v0 = upright ? top : bottom;
    f32 v1 = upright ? bottom : top;
    top = v0;
    bottom = v1;
    Unk_5472d0(5);
    Unk_547930(0, 0, x0, y0, 0.0f, 1.0f);
    Unk_547930(5, 0, left, bottom, 0.0f, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x1, y0, 0.0f, 1.0f);
    Unk_547930(5, 0, right, bottom, 0.0f, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x0, y1, 0.0f, 1.0f);
    Unk_547930(5, 0, left, top, 0.0f, 1.0f);
    Unk_547760();
    Unk_547930(0, 0, x1, y1, 0.0f, 1.0f);
    Unk_547930(5, 0, right, top, 0.0f, 1.0f);
    Unk_547760();
    Unk_5474b0();
    pContext->vf83(false);
    return false;
}

}  // namespace SiSDK3
