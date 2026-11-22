// Scope: common
// SiSDK3::SiGfxNXFont: its construction and destruction, its name, its small
// functions, and the reference counts its header defines. (Its other small
// accessors are lib/yebis/class's; slot 18, which makes the face, isn't
// written yet.)
#define UNK_SIGFX_NX_FONT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Font_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c9090: formats into a string
void Unk_4c9090(SiSDK3::SiString<char>* self, const char* format, ...);
// 0x7100500530 (leafgen's name and type: the face and a value of the device)
struct Unk_500530;
void Unk_500530_set(Unk_500530* self, u64 value);

namespace SiSDK3 {

// 0x71004ff510
SiGfxNXFont::SiGfxNXFont(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0), field_78(pAllocator),
      field_268(nullptr), field_270(0) {
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 2;
}

// 0x71004ff5b0 (D2), 0x71004ff670 (D0); 0x71004ff660 and 0x71004ff6a0 are
// their thunks for the second base
SiGfxNXFont::~SiGfxNXFont() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf19();
}

// 0x71004ff6d0
bool SiGfxNXFont::Unk_4ff6d0(size_t index) {
    field_28 = index;
    u64 manager = reinterpret_cast<u64>(field_20->field_398);
    Unk_500530_set(reinterpret_cast<Unk_500530*>(&field_78), manager);
    return true;
}

// 0x71004ff700 (0x71004ff810: its thunk)
bool SiGfxNXFont::vf25(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    if (field_268 != nullptr && field_30.field_10 != 0) {
        Unk_NXString<0x400> cacheName(field_10.m_pAllocator);
        Unk_4c9090(&cacheName, "%s_FontCache", field_30.m_pBuffer);
        field_268->Unk_5316f0(Unk_StringCStr(&cacheName));
    }
    return true;
}

// 0x71004ff830 (0x71004ff840: its thunk)
const SiString<char>* SiGfxNXFont::vf26() {
    return &field_30;
}

// 0x71004ff850 (0x71004ff860: its thunk)
u32 SiGfxNXFont::vf27() {
    return field_60;
}

// 0x71004ffab0
void SiGfxNXFont::vf19() {
    if (field_268 != nullptr) {
        field_268->vf3();
        field_268 = nullptr;
    }
    field_78.Unk_500810();
}

// 0x71004ffb00
bool SiGfxNXFont::vf21(const char* text) {
    Unk_NXFontCache* pCache = field_268;
    if (text == nullptr || pCache == nullptr) {
        return false;
    }
    Unk_596640 lock(&field_270, true);
    for (const char* p = text; *p != 0; p++) {
        vf22(*p);
    }
    return true;
}

// 0x71004ffb80
bool SiGfxNXFont::vf22(char character) {
    return field_78.Unk_500890(character) != nullptr;
}

// 0x71004ffbb0
Unk_NXFontCacheSecond* SiGfxNXFont::vf23() {
    return field_268;
}

// 0x71004ffbe0
void* SiGfxNXFont::Unk_4ffbe0(u32 character) {
    return field_78.Unk_500890(character);
}

// 0x71004ffc10
void SiGfxNXFont::vf24() {
    if (field_268 != nullptr) {
        field_268->Unk_531710();
    }
    field_78.Unk_500da0();
}

}  // namespace SiSDK3
