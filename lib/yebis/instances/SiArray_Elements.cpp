// Scope: common
// SiSDK3::SiArray<T, 16>'s reserve (Unk_4bf190) for element types that aren't
// pointers: one explicit instantiation per copy the executable has. Where no
// caller ties a copy to a type yet, its element type is a placeholder named
// after the copy, with the size the copy allocates and what its code shows of
// the type: what its constructor sets (the reserve constructs the new
// elements), and how the elements are copied (a trivially copyable class is
// copied as bytes, so only its size and alignment show). A pool's items are
// its blocks' elements (SiPool<T, 16>::DataArray), so those copies have their
// types' names.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>

struct Unk_5461d0 {
    Unk_5461d0() : field_10(0), field_18(0), field_20(0), field_28(0), field_30(0) {}
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u32 field_30;
};
PKMN_SIZE_ASSERT(Unk_5461d0, 0x38);

struct Unk_546490 {
    Unk_546490() : field_0(0), field_4(0), field_8(0), field_c(0) {}
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_SIZE_ASSERT(Unk_546490, 0x14);

struct Unk_562770 {
    u64 field_0;
};


namespace SiSDK3 {

// A pool's item (SiCore_Pool.h): its links, its index in the pool, whether
// it's in use.
#define POOL_ITEM(T) \
    T* m_pPrev;      \
    T* m_pNext;      \
    s64 field_10;    \
    bool field_18

class SiGfxResourcePool {
public:
    struct ResourceItem {
        ResourceItem() : m_pPrev(nullptr), m_pNext(nullptr), field_10(-1), field_18(false), field_20(0) {}
        POOL_ITEM(ResourceItem);
        u64 field_20;
    };
};
PKMN_SIZE_ASSERT(SiGfxResourcePool::ResourceItem, 0x28);

// A variation list's effect: its name and three zeroed words.
class ISiGfxShaderEffectVariationList {
public:
    struct ShaderEffectData {
        ShaderEffectData() : field_30(0), field_38(0), field_40(0) {}
        SiString<char> field_0;
        u64 field_30;
        u64 field_38;
        u64 field_40;
    };
};
PKMN_SIZE_ASSERT(ISiGfxShaderEffectVariationList::ShaderEffectData, 0x48);
// (The quad tree nodes' copy, 0x71005329e0, is in SiPool_QuadNode.cpp, with
// the node's two base classes.)

// SiGfx's FreeType glyph, a pool's item: its constructor (0x710050ae10) and
// its destructor (0x710050ae50) are out of line.
class SiGfxFreeTypeGlyph {
public:
    SiGfxFreeTypeGlyph();
    ~SiGfxFreeTypeGlyph();

    POOL_ITEM(SiGfxFreeTypeGlyph);
    u8 field_19[0x7f];
};
PKMN_SIZE_ASSERT(SiGfxFreeTypeGlyph, 0x98);

}  // namespace SiSDK3

using namespace SiSDK3;

// (0x71004f4850, 0x71004f4b30 and 0x71004f4d90 are the arrays of SiGfxImage's
// ImageData1D, ImageData2D and ImageData3D: SiGfx_Image.cpp instantiates them.)
// 0x71004ff210 = _ZN6SiSDK37SiArrayINS_17SiGfxResourcePool12ResourceItemELi16EE10Unk_4bf190Emb
template bool SiArray<SiGfxResourcePool::ResourceItem, 16>::Unk_4bf190(size_t, bool);
// 0x7100501930 = _ZN6SiSDK37SiArrayINS_18SiGfxFreeTypeGlyphELi16EE10Unk_4bf190Emb
template bool SiArray<SiGfxFreeTypeGlyph, 16>::Unk_4bf190(size_t, bool);
// (0x710053ad10 and 0x710053af60 are SiArray<SiGfxNXCommandList::DiscontinuedEntry>'s and
// SiArray<SiGfxNXCommandList::OverwrittenEntry>'s: SiGfx_NX_CommandList_Impl.cpp instantiates them.)
// 0x71005461d0 = _ZN6SiSDK37SiArrayI10Unk_5461d0Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_5461d0, 16>::Unk_4bf190(size_t, bool);
// 0x7100546490 = _ZN6SiSDK37SiArrayI10Unk_546490Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_546490, 16>::Unk_4bf190(size_t, bool);
// (0x7100557e60 is SiArray<SiGfxNXRootSignature::DescriptorRangeEntry>'s: SiGfx_NX_RootSignature_Impl.cpp instantiates it.)
// 0x7100562770 = _ZN6SiSDK37SiArrayI10Unk_562770Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_562770, 16>::Unk_4bf190(size_t, bool);
// 0x7100574090 = _ZN6SiSDK37SiArrayINS_31ISiGfxShaderEffectVariationList16ShaderEffectDataELi16EE10Unk_4bf190Emb
template bool SiArray<ISiGfxShaderEffectVariationList::ShaderEffectData, 16>::Unk_4bf190(size_t, bool);

// The assignment's copy for strings (the copies for pointers, 0x7100542fe0
// and 0x7100586ea0, come from their callers' translation units).
// 0x710056e140 = _ZN6SiSDK37SiArrayINS_8SiStringIcEELi16EEaSERKS3_
template void SiArray<SiString<char>, 16>::operator=(const SiArray&);
