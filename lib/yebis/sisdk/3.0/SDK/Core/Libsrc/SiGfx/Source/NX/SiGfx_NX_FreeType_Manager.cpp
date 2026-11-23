// Scope: common
// SiSDK3::SiGfxNXFreeTypeManager: its construction and destruction and the
// slots that add to its base's, and the vertex format and index buffer it
// draws text with (the file's name is their allocations' __FILE__).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_551300.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>

// Drops a reference and clears the pointer (placeholder name).
#define UNK_SAFE_RELEASE(p)   \
    if ((p) != nullptr) {     \
        (p)->vf3();           \
        (p) = nullptr;        \
    }

namespace SiSDK3 {

// 0x7100551300
SiGfxNXFreeTypeManager::SiGfxNXFreeTypeManager(SiGfxNXDevice* pDevice)
    : SiGfxFreeTypeManager(pDevice), field_58(nullptr), field_60(0), field_68(nullptr), field_70(nullptr) {}

// 0x7100551340 (D2), 0x71005513c0 (D0)
SiGfxNXFreeTypeManager::~SiGfxNXFreeTypeManager() {
    SiGfxNXFreeTypeManager::vf6();
    vf14();
    field_58 = nullptr;
}

// 0x7100551450
void SiGfxNXFreeTypeManager::vf5() {
    SiGfxFreeTypeManager::vf5();
}

// 0x7100551460
void SiGfxNXFreeTypeManager::vf6() {
    UNK_SAFE_RELEASE(field_70);
    UNK_SAFE_RELEASE(field_68);
    field_58 = nullptr;
    SiGfxFreeTypeManager::vf6();
}

// NON_MATCHING: the same calls and stores; the original keeps the
// description's 2 and 1 (its element size and count) in callee-saved
// registers from the vertex format's calls on (`mov w24, #2` before the
// first slot 19), and tests the indices' flag before the buffer's result
// (`tbnz w25 ; tbnz w0`), where here the result comes first. Tried: the
// description built before the vertex format, the free's test of the
// pointer instead of the flag.
// 0x71005514c0
bool SiGfxNXFreeTypeManager::Unk_5514c0() {
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    SiGfxNXDevice* pDevice = field_18;
#line 115
    SiGfxNXVertexFormat* format = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXVertexFormat(pAllocator, pDevice);
    format->vf18();
    format->vf19(0, 0, 2, 0, -1, 0, 0);
    format->vf19(4, 0, 2, 0, -1, 0, 0);
    format->vf19(5, 0, 0x10, 0, -1, 0, 0);
    format->vf20();
    field_70 = format;
#line 138
    u16* indices = UNK_ALLOC_ARRAY(pAllocator, u16, 0x6000, 0xffffffff);
    bool failed = indices == nullptr;
    if (!failed) {
        for (s64 i = 0; i < 0x1000; i++) {
            u16 first = static_cast<u16>(i * 4);
            indices[i * 6 + 0] = first;
            indices[i * 6 + 1] = first + 1;
            indices[i * 6 + 2] = first + 2;
            indices[i * 6 + 3] = first + 2;
            indices[i * 6 + 4] = first + 1;
            indices[i * 6 + 5] = first + 3;
        }
    }
#line 173
    SiGfxNXBuffer* buffer = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXBuffer(pAllocator, pDevice);
    SiGfxNXBuffer::Unk_MakeDesc desc(0x39, 0xc000, 2, 1, 2, 0);
    desc.field_18 = 1;
    desc.field_28 = 0xc000;
    desc.field_30 = indices;
    if (!buffer->vf21(&desc)) {
        if (!failed) {
#line 199
            SI_FREE(pAllocator, indices);
        }
        field_68 = buffer;
        return true;
    }
    field_68 = buffer;
    if (!failed) {
#line 205
        SI_FREE(pAllocator, indices);
    }
    return true;
}

// 0x7100551770
void SiGfxNXFreeTypeManager::vf7() {
    SiGfxFreeTypeManager::vf7();
    field_58 = nullptr;
    field_58 = Unk_NXDevice(field_18)->vf46(0x44);
    Unk_5514c0();
}

// 0x71005517b0
void SiGfxNXFreeTypeManager::vf8() {
    UNK_SAFE_RELEASE(field_70);
    UNK_SAFE_RELEASE(field_68);
    field_58 = nullptr;
    SiGfxFreeTypeManager::vf8();
}

// 0x7100551810
void SiGfxNXFreeTypeManager::vf9() {
    SiGfxFreeTypeManager::vf9();
}

// 0x7100551820
void SiGfxNXFreeTypeManager::vf10() {
    SiGfxFreeTypeManager::vf10();
}

// 0x7100551830
void SiGfxNXFreeTypeManager::vf11() {
    SiGfxFreeTypeManager::vf11();
}

// 0x7100551840
void SiGfxNXFreeTypeManager::vf12() {
    SiGfxFreeTypeManager::vf12();
}

}  // namespace SiSDK3
