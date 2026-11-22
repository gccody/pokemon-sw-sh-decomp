// Scope: common
// SiSDK3::SiGfxNXBuffer: its construction and destruction, its name, its
// release, and the reference counts its header defines. (Its small accessors
// are lib/yebis/class's; the functions that make and map it aren't written
// yet.)
#define UNK_SIGFX_NX_BUFFER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace SiSDK3 {

// 0x7100537200
SiGfxNXBuffer::SiGfxNXBuffer(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_a0(0), field_100(0),
      field_108(nullptr), field_110(true), field_111(false), field_118(0), field_120(0), field_128(false), field_12c(1),
      field_130(-1), field_150(0), field_154(0), field_170(pAllocator) {
    memset(&field_a4, 0, sizeof(field_a4) + sizeof(field_b8) + sizeof(field_d0));
    field_a4.field_0 = 10;
    memset(field_158, 0, sizeof(field_158));
    field_170.Unk_SetBuffer(field_158, 3);
}

// 0x7100537370 (D2), 0x71005374f0 (D0); 0x71005374e0 and 0x7100537520 are
// their thunks for the second base
SiGfxNXBuffer::~SiGfxNXBuffer() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf22();
}

// 0x7100537560 (0x71005375d0: its thunk)
bool SiGfxNXBuffer::vf30(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_a0 = Unk_4c3510(&field_30);
    if (field_128) {
        nvnBufferSetDebugLabel(field_d0, Unk_StringCStr(&field_30));
    }
    return true;
}

// 0x7100537640 (0x7100537650: its thunk)
const SiString<char>* SiGfxNXBuffer::vf31() {
    return &field_30;
}

// 0x7100537660 (0x7100537670: its thunk)
u32 SiGfxNXBuffer::vf32() {
    return field_a0;
}

// 0x7100538620
void SiGfxNXBuffer::vf22() {
    if (field_128) {
        nvnBufferFinalize(field_d0);
        field_128 = false;
        memset(field_d0, 0, sizeof(field_d0) + sizeof(field_100));
    }
    if (field_130 != -1) {
        field_20->Unk_4fb290(field_130);
    }
    if (field_108 != nullptr) {
        if (field_111) {
            field_108->Unk_553010(field_118);
            field_111 = false;
            field_118 = 0;
            field_120 = 0;
        }
        if (field_108 != nullptr) {
            field_108->vf3();
            field_108 = nullptr;
        }
    }
    memset(&field_a4, 0, sizeof(field_a4) + sizeof(field_b8));
    field_a4.field_0 = 10;
}

// 0x7100538910
void SiGfxNXBuffer::Unk_538910() {
    nvnBufferFlushMappedRange(field_d0, 0, field_b8.field_4);
}

// 0x71005389a0
void SiGfxNXBuffer::vf24(unsigned long long value) {
    s32 index = field_150;
    field_170.m_pData[index] = value;
}

// 0x71005389b0
unsigned long long SiGfxNXBuffer::vf25() {
    s32 index = field_150;
    return field_170.m_pData[index];
}

}  // namespace SiSDK3
