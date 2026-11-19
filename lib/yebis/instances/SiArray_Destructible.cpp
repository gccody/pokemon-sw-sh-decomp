// Scope: common
// SiSDK3::SiArray<T, 16>'s destructors (its virtual D1 and D0) for element
// types with destructors of their own, one explicit instantiation per type
// (the vtables' RTTI names). The array delete destroys each element: a
// SiString's destructor is inline, a polymorphic element's is a virtual call,
// SiGfxFreeTypeGlyph's is out of line
// (lib/yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Unk_50ae50.cpp). These declarations give each
// type its size and what its destructor destroys; the rest is placeholder.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>

namespace SiSDK3 {

class SiStringTable {
public:
    struct StringPerLanguage {
        u64 field_0;
        SiString<char> field_8;
        u8 field_38[0x80];
    };
};
PKMN_SIZE_ASSERT(SiStringTable::StringPerLanguage, 0xb8);

class ISiGfxShaderEffectVariationList {
public:
    struct ShaderEffectData {
        SiString<char> field_0;
        u8 field_30[0x18];
    };
};
PKMN_SIZE_ASSERT(ISiGfxShaderEffectVariationList::ShaderEffectData, 0x48);

struct SIGFX_SHADER_PREPROCESSOR {
    SiString<char> field_0;
    SiString<char> field_30;
};
PKMN_SIZE_ASSERT(SIGFX_SHADER_PREPROCESSOR, 0x60);

class SiGfxNXSurface {
public:
    virtual ~SiGfxNXSurface();
    u8 field_8[0x110];
};
PKMN_SIZE_ASSERT(SiGfxNXSurface, 0x118);

class SiGfxNXVolume {
public:
    virtual ~SiGfxNXVolume();
    u8 field_8[0xc8];
};
PKMN_SIZE_ASSERT(SiGfxNXVolume, 0xd0);

class SiIOVFSEntry {
public:
    virtual ~SiIOVFSEntry();
    u8 field_8[0x168];
};
PKMN_SIZE_ASSERT(SiIOVFSEntry, 0x170);

class SiGfxFreeTypeGlyph {
public:
    ~SiGfxFreeTypeGlyph();
    u8 field_0[0x98];
};
PKMN_SIZE_ASSERT(SiGfxFreeTypeGlyph, 0x98);

}  // namespace SiSDK3

using namespace SiSDK3;

// 0x71004c6580 (D1), 0x71004c7c80 (D0)
template SiArray<SiStringTable::StringPerLanguage, 16>::~SiArray();
// 0x71004cc980 (D1), 0x71004d0330 (D0)
template SiArray<SiString<char>, 16>::~SiArray();
// 0x7100501620 (D1), 0x71005016e0 (D0)
template SiArray<SiGfxFreeTypeGlyph, 16>::~SiArray();
// 0x710055ef70 (D1), 0x7100562620 (D0)
template SiArray<SiGfxNXVolume, 16>::~SiArray();
// 0x710055f040 (D1), 0x7100562560 (D0)
template SiArray<SiGfxNXSurface, 16>::~SiArray();
// 0x710056dd60 (D1), 0x710056dde0 (D0), and its array delete 0x710056de40
template SiArray<SIGFX_SHADER_PREPROCESSOR, 16>::~SiArray();
// 0x7100571230 (D1), 0x7100573840 (D0)
template SiArray<ISiGfxShaderEffectVariationList::ShaderEffectData, 16>::~SiArray();
// 0x710057e8e0 (D1), 0x710057ff80 (D0)
template SiArray<SiArray<SiString<char>, 16>, 16>::~SiArray();
// 0x7100584310 (D1), 0x7100586b00 (D0)
template SiArray<SiIOVFSEntry, 16>::~SiArray();
