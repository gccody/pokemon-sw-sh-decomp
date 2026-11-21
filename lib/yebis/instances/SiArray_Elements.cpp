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

struct Unk_4f4850 {
    Unk_4f4850() : field_0(0), field_8(0), field_10(0), field_18(0) {}
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u32 field_18;
};
PKMN_SIZE_ASSERT(Unk_4f4850, 0x20);

// Zero from its constructor.
struct Unk_4f4b30 {
    Unk_4f4b30() : field_0(0), field_8(0), field_10(0), field_18(0) {}
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
struct Unk_4f4d90 {
    Unk_4f4d90() : field_0(0), field_8(0), field_10(0), field_18(0), field_20(0) {}
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};

struct Unk_53ad10 {
    u64 field_0[10];
};
struct Unk_53af60 {
    u64 field_0[2];
};

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

struct Unk_54ee60 {
    Unk_54ee60() : field_0(0), field_8(0), field_10(false), field_18(0), field_20(0) {}
    u64 field_0;
    u64 field_8;
    bool field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_SIZE_ASSERT(Unk_54ee60, 0x28);

struct Unk_557e60 {
    Unk_557e60() : field_0(1), field_4(0), field_8(0), field_c(0), field_10(0) {}
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_SIZE_ASSERT(Unk_557e60, 0x14);

struct Unk_562770 {
    u64 field_0;
};

struct Unk_575df0 {
    Unk_575df0() : field_0(0), field_4(0), field_8(0), field_c(0), field_10(0x7fffffff), field_14(0), field_1c(0), field_20(1) {}
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    s32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
};
PKMN_SIZE_ASSERT(Unk_575df0, 0x24);

struct Unk_57c850 {
    Unk_57c850() : field_10(0), field_18(0) {}
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
struct Unk_57cae0 {
    u64 field_0[2];
};
// Zero from its constructor.
struct Unk_57cd00 {
    Unk_57cd00() : field_0(0), field_8(0) {}
    u64 field_0;
    u64 field_8;
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
// (The quad tree nodes' copy, 0x71005329e0, isn't instantiated: it copies a
// node as two runs of bytes, its links and index and then the rest, which a
// trivially copyable class's assignment doesn't.)

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

// 0x71004f4850 = _ZN6SiSDK37SiArrayI10Unk_4f4850Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_4f4850, 16>::Unk_4bf190(size_t, bool);
// 0x71004f4b30 = _ZN6SiSDK37SiArrayI10Unk_4f4b30Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_4f4b30, 16>::Unk_4bf190(size_t, bool);
// 0x71004f4d90 = _ZN6SiSDK37SiArrayI10Unk_4f4d90Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_4f4d90, 16>::Unk_4bf190(size_t, bool);
// 0x71004ff210 = _ZN6SiSDK37SiArrayINS_17SiGfxResourcePool12ResourceItemELi16EE10Unk_4bf190Emb
template bool SiArray<SiGfxResourcePool::ResourceItem, 16>::Unk_4bf190(size_t, bool);
// 0x7100501930 = _ZN6SiSDK37SiArrayINS_18SiGfxFreeTypeGlyphELi16EE10Unk_4bf190Emb
template bool SiArray<SiGfxFreeTypeGlyph, 16>::Unk_4bf190(size_t, bool);
// 0x710053ad10 = _ZN6SiSDK37SiArrayI10Unk_53ad10Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_53ad10, 16>::Unk_4bf190(size_t, bool);
// 0x710053af60 = _ZN6SiSDK37SiArrayI10Unk_53af60Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_53af60, 16>::Unk_4bf190(size_t, bool);
// 0x71005461d0 = _ZN6SiSDK37SiArrayI10Unk_5461d0Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_5461d0, 16>::Unk_4bf190(size_t, bool);
// 0x7100546490 = _ZN6SiSDK37SiArrayI10Unk_546490Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_546490, 16>::Unk_4bf190(size_t, bool);
// 0x710054ee60 = _ZN6SiSDK37SiArrayI10Unk_54ee60Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_54ee60, 16>::Unk_4bf190(size_t, bool);
// 0x7100557e60 = _ZN6SiSDK37SiArrayI10Unk_557e60Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_557e60, 16>::Unk_4bf190(size_t, bool);
// 0x7100562770 = _ZN6SiSDK37SiArrayI10Unk_562770Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_562770, 16>::Unk_4bf190(size_t, bool);
// 0x7100574090 = _ZN6SiSDK37SiArrayINS_31ISiGfxShaderEffectVariationList16ShaderEffectDataELi16EE10Unk_4bf190Emb
template bool SiArray<ISiGfxShaderEffectVariationList::ShaderEffectData, 16>::Unk_4bf190(size_t, bool);
// 0x7100575df0 = _ZN6SiSDK37SiArrayI10Unk_575df0Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_575df0, 16>::Unk_4bf190(size_t, bool);
// 0x710057c850 = _ZN6SiSDK37SiArrayI10Unk_57c850Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_57c850, 16>::Unk_4bf190(size_t, bool);
// 0x710057cae0 = _ZN6SiSDK37SiArrayI10Unk_57cae0Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_57cae0, 16>::Unk_4bf190(size_t, bool);
// 0x710057cd00 = _ZN6SiSDK37SiArrayI10Unk_57cd00Li16EE10Unk_4bf190Emb
template bool SiArray<Unk_57cd00, 16>::Unk_4bf190(size_t, bool);
