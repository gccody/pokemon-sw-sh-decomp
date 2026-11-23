// Scope: common
// SiSDK3::SiArray<T, 16>'s destructors (its virtual D1 and D0), one explicit
// instantiation per element type that the executable has them for. The types
// are the vtables' RTTI names; these declarations give them only what the
// destructors need (a pointer's or a trivially destructible class's array frees
// its buffer and nothing else). Element types with destructors of their own are
// in SiArray_Destructible.cpp.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>

struct NVNsync {};
class NVNtexture;
class NVNtextureView;

// The element types of the copies of Unk_4bf190 that no caller ties to a type
// (placeholders named after each copy: the code doesn't depend on the type).
struct Unk_4f6f70;
struct Unk_4fb4b0;
struct Unk_536a10;
struct Unk_56f0a0;
struct Unk_56f240;
struct Unk_56f3e0;

namespace SiSDK3 {
class ISiAllocator;
class ISiGfxDevice;
class ISiGfxImageLoader;
class ISiGfxImageSaver;
class ISiGfxKernel {
public:
    struct EventHandler;
};
class ISiGfxResource;
class ISiGfxShader;
class ISiGfxShaderBinaryCachePackage;
class ISiGfxShaderEffectDefinition;
class ISiGfxShaderEffectPackage {
public:
    struct ShaderEffectData;
    struct ShaderProgramData;
    struct TechniqueData;
};
class ISiGfxShaderEffectVariation;
class ISiGfxShaderEffectVariationList {
public:
    struct RequestNotFoundEntry;
    struct ShaderVariationItem;
};
class ISiGfxShaderGraphFactory;
class ISiIOBinaryArchive {
public:
    struct ChunkTypeInfo {};
};
class ISiKernel {
public:
    struct IReportUserHandler;
};
struct SIGFX_TEXTURE_INITDATA {};
class SiFixedHeapAllocator2 {
public:
    struct MemoryBlockHeader {};
};
class SiGfxDisplayAdapter;
class SiGfxFontDrawHelper {
public:
    struct FontVertex {};
    struct GlyphRenderData {};
    struct TextLineData {};
};
class SiGfxFreeTypeFaceCache {
public:
    struct CacheData;
};
class SiGfxFreeTypeGlyph;
class SiGfxImage {
public:
    struct ImageData1D {};
    struct ImageData2D {};
    struct ImageData3D {};
};
class SiGfxKernel {
public:
    struct DelayedDeletionEntry {};
};
class SiGfxNXCommandList {
public:
    struct DiscontinuedEntry {};
    struct OverwrittenEntry {};
};
class SiGfxNXDescriptorSet {
public:
    struct ParameterEntry {};
};
class SiGfxNXDevice;
class SiGfxNXDrawContext {
public:
    struct DirectBuffer;
};
class SiGfxNXMemoryHeap;
class SiGfxNXRootSignature {
public:
    struct DescriptorRangeEntry {};
};
class SiGfxPerformanceUtility {
public:
    struct RenderPerfBarSegmentData {};
    struct RenderPerfBarTextData {};
};
class SiGfxResourcePool {
public:
    struct ResourceItem {};
};
class SiGfxShaderBinaryCachePackage {
public:
    struct EditEntry;
    struct Entry {};
};
class SiGfxShaderEffect {
public:
    struct ShaderProgramCompileEntry;
    struct ShaderProgramData;
    struct TechniqueData;
};
class SiGfxShaderEffectVariation {
public:
    struct VariationItem {};
};
class SiGfxShaderGraphConnectionLink;
class SiGfxShaderGraphDataType;
class SiGfxShaderGraphDataValue;
class SiGfxShaderGraphIOSlot;
class SiGfxShaderGraphIOSlotType;
class SiGfxShaderGraphIntrinsicNodeType;
class SiGfxShaderGraphNodeType;
class SiGfxShaderGraphOperatorNodeType;
class SiIOVFSEntry;
class SiReflectionObject;
class SiReflectionPropertyBase;
class SiStringTable {
public:
    struct Entry;
};
template <class T, int ALIGN>
class SiPool {
public:
    struct DataArray;
};
template <class T>
class SiGfxQuadTree {
public:
    struct QuadNode {};
};
}  // namespace SiSDK3

namespace PPFX {
class IGPUDevice {
public:
    struct PipelineStateData {};
};
}  // namespace PPFX

// 0x7100442e30 (D1), 0x7100442ed0 (D0)
template SiSDK3::SiArray<PPFX::IGPUDevice::PipelineStateData, 16>::~SiArray();
// 0x71004bef80 (D1), 0x71004bf000 (D0)
template SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiFixedHeapAllocator2::MemoryBlockHeader, 16>::DataArray*, 16>::~SiArray();
// 0x71004bf060 (D1), 0x71004bf100 (D0)
template SiSDK3::SiArray<SiSDK3::SiFixedHeapAllocator2::MemoryBlockHeader, 16>::~SiArray();
// 0x71004bfd30 (D1), 0x71004c2540 (D0)
template SiSDK3::SiArray<SiSDK3::SiReflectionObject*, 16>::~SiArray();
// 0x71004bfe10 (D1), 0x71004c2490 (D0)
template SiSDK3::SiArray<SiSDK3::ISiAllocator*, 16>::~SiArray();
// 0x71004bfe90 (D1), 0x71004c2430 (D0)
template SiSDK3::SiArray<SiSDK3::ISiKernel::IReportUserHandler*, 16>::~SiArray();
// 0x71004bff10 (D1), 0x71004c23d0 (D0)
template SiSDK3::SiArray<SiSDK3::SiStringTable*, 16>::~SiArray();
// 0x71004c6f40 (D1), 0x71004c81b0 (D0)
template SiSDK3::SiArray<SiSDK3::SiStringTable::Entry*, 16>::~SiArray();
// 0x71004cb300 (D1), 0x71004cb860 (D0)
template SiSDK3::SiArray<SiSDK3::SiReflectionPropertyBase*, 16>::~SiArray();
// 0x71004cc860 (D1), 0x71004d0780 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxKernel::DelayedDeletionEntry, 16>::~SiArray();
// 0x71004cc900 (D1), 0x71004d0720 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxKernel::EventHandler*, 16>::~SiArray();
// 0x71004cca80 (D1), 0x71004d06c0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxDevice*, 16>::~SiArray();
// 0x71004d1020 (D1), 0x71004d2780 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxImageSaver*, 16>::~SiArray();
// 0x71004d10a0 (D1), 0x71004d2720 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxImageLoader*, 16>::~SiArray();
// 0x71004d2cf0 (D1), 0x71004d3020 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxDisplayAdapter*, 16>::~SiArray();
// 0x71004da1d0 (D1), 0x71004db590 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphNodeType*, 16>::~SiArray();
// 0x71004da250 (D1), 0x71004db530 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphIntrinsicNodeType*, 16>::~SiArray();
// 0x71004da2d0 (D1), 0x71004db4d0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphOperatorNodeType*, 16>::~SiArray();
// 0x71004da350 (D1), 0x71004db470 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphDataType*, 16>::~SiArray();
// 0x71004da3d0 (D1), 0x71004db410 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderGraphFactory*, 16>::~SiArray();
// 0x71004dbfb0 (D1), 0x71004dc4b0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphIOSlotType*, 16>::~SiArray();
// 0x71004ddec0 (D1), 0x71004de2f0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphDataValue*, 16>::~SiArray();
// 0x71004e06f0 (D1), 0x71004e0cf0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphIOSlot*, 16>::~SiArray();
// 0x71004e1280 (D1), 0x71004e16f0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphConnectionLink*, 16>::~SiArray();
// 0x71004e2290 (D1), 0x71004e2f40 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxPerformanceUtility::RenderPerfBarTextData, 16>::~SiArray();
// 0x71004e2330 (D1), 0x71004e2eb0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxPerformanceUtility::RenderPerfBarSegmentData, 16>::~SiArray();
// 0x71004e3160 (D1), 0x71004e31e0 (D0)
template SiSDK3::SiArray<float, 16>::~SiArray();
// 0x71004e3350 (D1), 0x71004e33d0 (D0)
template SiSDK3::SiArray<int, 16>::~SiArray();
// 0x71004e3a80 (D1), 0x71004e79e0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderBinaryCachePackage*, 16>::~SiArray();
// 0x71004e3b00 (D1), 0x71004e7980 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage*, 16>::~SiArray();
// 0x71004e3b80 (D1), 0x71004e7920 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectDefinition*, 16>::~SiArray();
// 0x71004e5c80 (D1), 0x71004e7de0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectVariationList::RequestNotFoundEntry*, 16>::~SiArray();
// 0x71004e5d00 (D1), 0x71004e7be0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectVariationList*, 16>::~SiArray();
// 0x71004e88d0 (D1), 0x71004ea1a0 (D0)
template SiSDK3::SiArray<unsigned char, 16>::~SiArray();
// 0x71004e8950 (D1), 0x71004ea480 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderBinaryCachePackage::Entry*, 16>::~SiArray();
// 0x71004e89d0 (D1), 0x71004ea3f0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderBinaryCachePackage::Entry, 16>::~SiArray();
// 0x71004e8a70 (D1), 0x71004ea390 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderBinaryCachePackage::EditEntry*, 16>::~SiArray();
// 0x71004f10e0 (D1), 0x71004f1180 (D0)
template SiSDK3::SiArray<SiSDK3::SIGFX_TEXTURE_INITDATA, 16>::~SiArray();
// 0x71004f15a0 (D1), 0x71004f4730 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData3D, 16>::~SiArray();
// 0x71004f1640 (D1), 0x71004f46a0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData2D, 16>::~SiArray();
// 0x71004f16e0 (D1), 0x71004f47c0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData1D, 16>::~SiArray();
// 0x71004f6a70 (D1), 0x71004f6f10 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXDevice*, 16>::~SiArray();
// 0x71004f7810 (D1), 0x71004fb450 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXMemoryHeap*, 16>::~SiArray();
// 0x71004fb9a0 (D1), 0x71004fe1f0 (D0)
template SiSDK3::SiArray<NVNtextureView*, 16>::~SiArray();
// 0x71004fba20 (D1), 0x71004fe190 (D0)
template SiSDK3::SiArray<NVNtexture*, 16>::~SiArray();
// 0x7100501540 (D1), 0x71005015c0 (D0)
template SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiGfxFreeTypeGlyph, 16>::DataArray*, 16>::~SiArray();
// 0x7100532630 (D1), 0x71005326b0 (D0)
template SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiGfxQuadTree<SiSDK3::SiGfxFreeTypeFaceCache::CacheData>::QuadNode, 16>::DataArray*, 16>::~SiArray();
// 0x7100532710 (D1), 0x71005327b0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxQuadTree<SiSDK3::SiGfxFreeTypeFaceCache::CacheData>::QuadNode, 16>::~SiArray();
// 0x7100536800 (D1), 0x7100536880 (D0)
template SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiGfxResourcePool::ResourceItem, 16>::DataArray*, 16>::~SiArray();
// 0x71005368e0 (D1), 0x7100536980 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxResourcePool::ResourceItem, 16>::~SiArray();
// 0x7100537460 (D1), 0x7100538af0 (D0)
template SiSDK3::SiArray<unsigned long long, 16>::~SiArray();
// 0x7100539e90 (D1), 0x710053ac80 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXCommandList::DiscontinuedEntry, 16>::~SiArray();
// 0x7100539f30 (D1), 0x710053abf0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXCommandList::OverwrittenEntry, 16>::~SiArray();
// 0x7100542da0 (D1), 0x7100542e20 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXDrawContext::DirectBuffer*, 16>::~SiArray();
// 0x7100543710 (D1), 0x7100546170 (D0)
template SiSDK3::SiArray<unsigned short, 16>::~SiArray();
// 0x7100543790 (D1), 0x71005460e0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxFontDrawHelper::FontVertex, 16>::~SiArray();
// 0x7100543830 (D1), 0x7100546050 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxFontDrawHelper::TextLineData, 16>::~SiArray();
// 0x71005438d0 (D1), 0x7100545fc0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxFontDrawHelper::GlyphRenderData, 16>::~SiArray();
// 0x710054dcc0 (D1), 0x710054e680 (D0)
template SiSDK3::SiArray<NVNsync, 16>::~SiArray();
// 0x710054e8c0 (D1), 0x710054edd0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXDescriptorSet::ParameterEntry, 16>::~SiArray();
// 0x710054f2c0 (D1), 0x710054f780 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXCommandList*, 16>::~SiArray();
// 0x7100551000 (D1), 0x7100551080 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxResource*, 16>::~SiArray();
// 0x7100557d30 (D1), 0x7100557dd0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxNXRootSignature::DescriptorRangeEntry, 16>::~SiArray();
// 0x710055eed0 (D1), 0x71005626e0 (D0)
template SiSDK3::SiArray<unsigned long, 16>::~SiArray();
// 0x7100566b30 (D1), 0x710056e980 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage::ShaderProgramData*, 16>::~SiArray();
// 0x71005676d0 (D1), 0x710056e9e0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage::TechniqueData*, 16>::~SiArray();
// 0x71005682e0 (D1), 0x710056eb60 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShader*, 16>::~SiArray();
// 0x7100568360 (D1), 0x710056eb00 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectVariation*, 16>::~SiArray();
// 0x71005683e0 (D1), 0x710056eaa0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderEffect*, 16>::~SiArray();
// 0x7100568460 (D1), 0x710056ea40 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage::ShaderEffectData*, 16>::~SiArray();
// 0x710056e740 (D1), 0x710056e7c0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderEffect::ShaderProgramData*, 16>::~SiArray();
// 0x7100571330 (D1), 0x71005737e0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectVariationList::ShaderVariationItem*, 16>::~SiArray();
// 0x7100574b90 (D1), 0x7100575d60 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderEffectVariation::VariationItem, 16>::~SiArray();
// 0x7100576650 (D1), 0x71005799e0 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderEffect::ShaderProgramCompileEntry*, 16>::~SiArray();
// 0x71005766d0 (D1), 0x7100579980 (D0)
template SiSDK3::SiArray<SiSDK3::SiGfxShaderEffect::TechniqueData*, 16>::~SiArray();
// 0x710057aa20 (D1), 0x710057c7c0 (D0)
template SiSDK3::SiArray<SiSDK3::ISiIOBinaryArchive::ChunkTypeInfo, 16>::~SiArray();
// 0x710057e7e0 (D1), 0x71005800a0 (D0)
template SiSDK3::SiArray<char, 16>::~SiArray();
// 0x710057e860 (D1), 0x7100580040 (D0)
template SiSDK3::SiArray<wchar_t, 16>::~SiArray();
// 0x7100584290 (D1), 0x7100586bc0 (D0)
template SiSDK3::SiArray<SiSDK3::SiIOVFSEntry*, 16>::~SiArray();

// Unk_4bf190 (8-byte elements), for the element types its callers show: a
// caller in a class's vtable calls it on this + N, and a function of that
// vtable group stores SiArray<T>'s vtable at this + N (the other 24 copies of
// this code are called from inline Adds of no class, and aren't named).
// 0x71004bf190
template bool SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiFixedHeapAllocator2::MemoryBlockHeader, 16>::DataArray*, 16>::Unk_4bf190(size_t, bool);
// 0x71004c27f0
template bool SiSDK3::SiArray<SiSDK3::SiStringTable*, 16>::Unk_4bf190(size_t, bool);
// 0x71004c2990
template bool SiSDK3::SiArray<SiSDK3::ISiKernel::IReportUserHandler*, 16>::Unk_4bf190(size_t, bool);
// 0x71004c2b30
template bool SiSDK3::SiArray<SiSDK3::ISiAllocator*, 16>::Unk_4bf190(size_t, bool);
// 0x71004c8210
template bool SiSDK3::SiArray<SiSDK3::SiStringTable::Entry*, 16>::Unk_4bf190(size_t, bool);
// 0x71004d0810
template bool SiSDK3::SiArray<SiSDK3::ISiGfxDevice*, 16>::Unk_4bf190(size_t, bool);
// 0x71004d0bd0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxKernel::EventHandler*, 16>::Unk_4bf190(size_t, bool);
// 0x71004d27e0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxImageLoader*, 16>::Unk_4bf190(size_t, bool);
// 0x71004d2980
template bool SiSDK3::SiArray<SiSDK3::ISiGfxImageSaver*, 16>::Unk_4bf190(size_t, bool);
// 0x71004db930
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphNodeType*, 16>::Unk_4bf190(size_t, bool);
// 0x71004dbad0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderGraphFactory*, 16>::Unk_4bf190(size_t, bool);
// 0x71004e8240
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderBinaryCachePackage*, 16>::Unk_4bf190(size_t, bool);
// 0x71004ea5e0
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderBinaryCachePackage::EditEntry*, 16>::Unk_4bf190(size_t, bool);
// 0x71004fe250
template bool SiSDK3::SiArray<NVNtexture*, 16>::Unk_4bf190(size_t, bool);
// 0x71004fe3f0
template bool SiSDK3::SiArray<NVNtextureView*, 16>::Unk_4bf190(size_t, bool);
// 0x7100501790
template bool SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiGfxFreeTypeGlyph, 16>::DataArray*, 16>::Unk_4bf190(size_t, bool);
// 0x7100532840
template bool SiSDK3::SiArray<SiSDK3::SiPool<SiSDK3::SiGfxQuadTree<SiSDK3::SiGfxFreeTypeFaceCache::CacheData>::QuadNode, 16>::DataArray*, 16>::Unk_4bf190(size_t, bool);
// 0x7100538b50
template bool SiSDK3::SiArray<unsigned long long, 16>::Unk_4bf190(size_t, bool);
// 0x71005510e0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxResource*, 16>::Unk_4bf190(size_t, bool);
// 0x710056ebc0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage::ShaderEffectData*, 16>::Unk_4bf190(size_t, bool);
// 0x710056f580
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderEffect*, 16>::Unk_4bf190(size_t, bool);
// 0x7100573990
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectVariationList::ShaderVariationItem*, 16>::Unk_4bf190(size_t, bool);
// 0x7100587040
template bool SiSDK3::SiArray<SiSDK3::SiIOVFSEntry*, 16>::Unk_4bf190(size_t, bool);

// 0x71004c2650 (SiKernel's array of the reflected classes: its vf20 calls it)
template bool SiSDK3::SiArray<SiSDK3::SiReflectionObject*, 16>::Unk_4bf190(size_t, bool);

// The other copies of Unk_4bf190: called only from inline Adds of no known
// class, so their element types aren't known; each gets a placeholder. (Five
// of the shader graph's are among them under their real types now.)
// 0x71004db5f0 (the utility's arrays of data types: lib/yebis/sisdk's shader graph classes call it)
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphDataType*, 16>::Unk_4bf190(size_t, bool);
// 0x71004db790 (the utility's array of operator node types: lib/yebis/sisdk's shader graph classes call it)
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphOperatorNodeType*, 16>::Unk_4bf190(size_t, bool);
// 0x71004dc510 (the node type's inputs and outputs: lib/yebis/sisdk's shader graph classes call it)
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphIOSlotType*, 16>::Unk_4bf190(size_t, bool);
// 0x71004de350 (a data value's parts: lib/yebis/sisdk's shader graph classes call it)
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphDataValue*, 16>::Unk_4bf190(size_t, bool);
// 0x71004e0d50 (a node's slots, a slot's parts: lib/yebis/sisdk's shader graph classes call it)
template bool SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphIOSlot*, 16>::Unk_4bf190(size_t, bool);
// (0x71004e7c40 is SiArray<ISiGfxShaderEffectVariationList*>'s: SiGfx_ShaderUtility_Impl.cpp instantiates it)
// (0x71004ea9b0 is SiArray<SiGfxShaderBinaryCachePackage::Entry*>'s: SiGfx_ShaderCache_BinaryPackage_Impl.cpp instantiates it)
// (0x71004f6f70 is SiArray<SiGfxNXDevice*>'s: SiGfx_NX_Manager_Impl.cpp instantiates it)
// (0x71004fb4b0 is SiArray<SiGfxNXMemoryHeap*>'s: SiGfx_NX_Device_Impl.cpp instantiates it)
// (0x7100542aa0 is SiArray<SiGfxNXDrawContext::DirectBuffer*>'s: SiGfx_NX_DrawContext_Impl.cpp instantiates it)
// (0x710054f7e0 is SiArray<SiGfxNXCommandList*>'s: SiGfx_NX_CommandListPool_Impl.cpp instantiates it)
// 0x710056ed60 (SiGfxShaderEffectPackage's functions call it on its array of
// definitions, and the next one on its array of variations)
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectDefinition*, 16>::Unk_4bf190(size_t, bool);
// 0x710056ef00
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectVariation*, 16>::Unk_4bf190(size_t, bool);
// 0x710056f0a0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShader*, 16>::Unk_4bf190(size_t, bool);
// 0x710056f240
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage::TechniqueData*, 16>::Unk_4bf190(size_t, bool);
// 0x710056f3e0
template bool SiSDK3::SiArray<SiSDK3::ISiGfxShaderEffectPackage::ShaderProgramData*, 16>::Unk_4bf190(size_t, bool);
// (0x710056f720 and 0x710056fb40, SiArray<SiGfxShaderEffect::TechniqueData*>'s
// and SiArray<SiGfxShaderEffect::ShaderProgramData*>'s, are instantiated by
// their caller, the package's Unk_56ca20)
// (0x71005744f0, SiArray<ISiGfxShaderEffectVariationList::RequestNotFoundEntry*>'s, is
// instantiated by its caller, SiGfxShaderEffectVariationList's slot 22)
// (0x7100579a40, SiArray<SiGfxShaderEffect::ShaderProgramCompileEntry*>'s, is
// instantiated by its caller, SiGfxShaderEffect's slot 12)
