// Scope: common
// SiSDK3::SiGfxPrimitiveDrawHelper: its construction and destruction, its
// event handler's destructor, and the reference counts its header defines.
#define UNK_SIGFX_PRIMITIVEDRAWHELPER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_PrimitiveDrawHelper.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>

// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004c9380: copies bytes
void* Unk_4c9380(void* dst, const void* src, size_t size);
// 0x71004ed0c0: a format's bytes per pixel
s32 Unk_4ed0c0(u32 format);
// 0x71004ecf40: the program of a kind of primitive's index (Unk_4ecbc0.cpp)
u32 Unk_4ecf40(s32 kind, s32 index);

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
// the memset (524).
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

// NON_MATCHING: the original places the test of the primitives' count
// right after case 1, which falls into the part after the switch (`b.lt` to
// the return); here that part comes after case 5 and every case jumps to it
// (592 bytes for 600).
// 0x7100547500
bool SiGfxPrimitiveDrawHelper::Unk_547500(bool last, const u8* pData) {
    if (!field_184) {
        return false;
    }
    if (pData == nullptr) {
        pData = field_160;
    }
    void* pVertices = field_490->vf74(0, field_178, field_174);
    Unk_4c9380(pVertices, pData, static_cast<s64>(field_178) * field_174);
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
    if (kept != 0 && !last) {
        const u8* pKept = pData + static_cast<s64>(field_178 - kept) * field_174;
        switch (kept) {
        case 1:
            Unk_4c9380(field_190.field_100, pKept, field_174);
            break;
        case 2:
            Unk_4c9380(&field_190.field_100[field_174], pKept, field_174);
            Unk_4c9380(field_190.field_100, pKept + field_174, field_174);
            break;
        }
    }
    field_490->vf85()->field_16c = 4;
    field_490->vf85()->field_16c = field_180;
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

// NON_MATCHING: the same instructions with the vertex size and the count of
// the loop's step in each other's registers (`madd x19, x9, x8, x19`).
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
        pVertices += static_cast<s64>(n) * field_174;
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

// NON_MATCHING (and slots 0x7100547b60, 0x7100547df0 to 0x71005484f0, the
// setters whose formats 28 and 87 both end in the store of byte 3): the
// original shares those two cases' last store (case 87 branches into case
// 28's, its products all computed before their conversions); here each case
// keeps its own. Slots 0x7100547a40 and 0x7100547ca0 match with the same
// switch.
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
    case 28:
        p[0] = static_cast<u8>(x * 255.0f);
        p[1] = static_cast<u8>(y * 255.0f);
        p[2] = static_cast<u8>(z * 255.0f);
        p[3] = static_cast<u8>(w * 255.0f);
        break;
    case 41:
        f[0] = x;
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

// NON_MATCHING: see 0x7100547930
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
    case 28:
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = static_cast<u8>(pValues[2] * 255.0f);
        p[3] = 0;
        break;
    case 41:
        f[0] = pValues[0];
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

// NON_MATCHING: see 0x7100547930
// 0x7100547df0
bool SiGfxPrimitiveDrawHelper::Unk_547df0(u32 row, s32 column, u8 r, u8 g, u8 b, u8 a) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = static_cast<f32>(r) / 255.0f;
        f[1] = static_cast<f32>(g) / 255.0f;
        f[2] = static_cast<f32>(b) / 255.0f;
        f[3] = static_cast<f32>(a) / 255.0f;
        break;
    case 6:
        f[0] = static_cast<f32>(r) / 255.0f;
        f[1] = static_cast<f32>(g) / 255.0f;
        f[2] = static_cast<f32>(b) / 255.0f;
        break;
    case 16:
        f[0] = static_cast<f32>(r) / 255.0f;
        f[1] = static_cast<f32>(g) / 255.0f;
        break;
    case 28:
        p[0] = r;
        p[1] = g;
        p[2] = b;
        p[3] = a;
        break;
    case 87:
        p[2] = r;
        p[1] = g;
        p[0] = b;
        p[3] = a;
        break;
    default:
        return false;
    }
    return true;
}

// NON_MATCHING: see 0x7100547930
// 0x7100547f50
bool SiGfxPrimitiveDrawHelper::Unk_547f50(u32 row, s32 column, const u8* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        f[3] = static_cast<f32>(pValues[3]) / 255.0f;
        break;
    case 6:
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        break;
    case 16:
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        break;
    case 28:
        p[0] = pValues[0];
        p[1] = pValues[1];
        p[2] = pValues[2];
        p[3] = pValues[3];
        break;
    case 87:
        p[2] = pValues[0];
        p[1] = pValues[1];
        p[0] = pValues[2];
        p[3] = pValues[3];
        break;
    default:
        return false;
    }
    return true;
}

// NON_MATCHING: see 0x7100547930
// 0x71005480c0
bool SiGfxPrimitiveDrawHelper::Unk_5480c0(u32 row, s32 column, const u8* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        f[3] = static_cast<f32>(pValues[3]) / 255.0f;
        break;
    case 6:
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[2]) / 255.0f;
        break;
    case 16:
        f[0] = static_cast<f32>(pValues[0]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        break;
    case 28:
        p[0] = pValues[0];
        p[1] = pValues[1];
        p[2] = pValues[2];
        p[3] = pValues[3];
        break;
    case 87:
        p[2] = pValues[0];
        p[1] = pValues[1];
        p[0] = pValues[2];
        p[3] = pValues[3];
        break;
    default:
        return false;
    }
    return true;
}

// NON_MATCHING: see 0x7100547930
// 0x7100548230
bool SiGfxPrimitiveDrawHelper::Unk_548230(u32 row, s32 column, const f32* pValues) {
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

// NON_MATCHING: see 0x7100547930
// 0x7100548380
bool SiGfxPrimitiveDrawHelper::Unk_548380(u32 row, s32 column, const u8* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = static_cast<f32>(pValues[2]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[0]) / 255.0f;
        f[3] = static_cast<f32>(pValues[3]) / 255.0f;
        break;
    case 6:
        f[0] = static_cast<f32>(pValues[2]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        f[2] = static_cast<f32>(pValues[0]) / 255.0f;
        break;
    case 16:
        f[0] = static_cast<f32>(pValues[2]) / 255.0f;
        f[1] = static_cast<f32>(pValues[1]) / 255.0f;
        break;
    case 28:
        p[0] = pValues[2];
        p[1] = pValues[1];
        p[2] = pValues[0];
        p[3] = pValues[3];
        break;
    case 87:
        p[2] = pValues[2];
        p[1] = pValues[1];
        p[0] = pValues[0];
        p[3] = pValues[3];
        break;
    default:
        return false;
    }
    return true;
}

// NON_MATCHING: see 0x7100547930
// 0x71005484f0
bool SiGfxPrimitiveDrawHelper::Unk_5484f0(u32 row, s32 column, const f32* pValues) {
    u8 format = field_c0[row][column];
    if (format == 0) {
        return false;
    }
    u8* p = &field_190.field_0[field_20[row][column]];
    f32* f = reinterpret_cast<f32*>(p);
    switch (format) {
    case 2:
        f[0] = pValues[2];
        f[1] = pValues[1];
        f[2] = pValues[0];
        f[3] = pValues[3];
        break;
    case 6:
        f[0] = pValues[2];
        f[1] = pValues[1];
        f[2] = pValues[0];
        break;
    case 16:
        f[0] = pValues[2];
        f[1] = pValues[1];
        break;
    case 28:
        p[0] = static_cast<u8>(pValues[2] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[2] = static_cast<u8>(pValues[0] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    case 87:
        p[2] = static_cast<u8>(pValues[2] * 255.0f);
        p[1] = static_cast<u8>(pValues[1] * 255.0f);
        p[0] = static_cast<u8>(pValues[0] * 255.0f);
        p[3] = static_cast<u8>(pValues[3] * 255.0f);
        break;
    default:
        return false;
    }
    return true;
}

}  // namespace SiSDK3
