// Scope: common
// SiSDK3::SiPool<SiGfxResourcePool::ResourceItem, 16>'s members (SiCore_Pool.h)
// and its blocks' array's reserve: explicit instantiations, in a file of
// their own (SiGfxResourcePool's translation unit calls them; with their
// definitions there, one would be inlined in its caller).
#define UNK_SIPOOL_WHOLE_ELEMENT
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ResourcePool.h>

using namespace SiSDK3;

// 0x7100534070 = _ZN6SiSDK36SiPoolINS_17SiGfxResourcePool12ResourceItemELi16EEC1EPNS_12ISiAllocatorEb
template SiPool<SiGfxResourcePool::ResourceItem, 16>::SiPool(ISiAllocator*, bool);
// 0x71004fe710 = _ZN6SiSDK36SiPoolINS_17SiGfxResourcePool12ResourceItemELi16EE3vf2Em
template bool SiPool<SiGfxResourcePool::ResourceItem, 16>::vf2(size_t);
// 0x7100536a10 = _ZN6SiSDK37SiArrayIPNS_6SiPoolINS_17SiGfxResourcePool12ResourceItemELi16EE9DataArrayELi16EE10Unk_4bf190Emb
template bool SiArray<SiPool<SiGfxResourcePool::ResourceItem, 16>::DataArray*, 16>::Unk_4bf190(size_t, bool);
// 0x71005364d0 = _ZN6SiSDK36SiPoolINS_17SiGfxResourcePool12ResourceItemELi16EE3vf5Em
template bool SiPool<SiGfxResourcePool::ResourceItem, 16>::vf5(size_t);
// 0x71004ff090 = _ZN6SiSDK36SiPoolINS_17SiGfxResourcePool12ResourceItemELi16EE10Unk_4be3f0EPS2_
template void SiPool<SiGfxResourcePool::ResourceItem, 16>::Unk_4be3f0(SiGfxResourcePool::ResourceItem*);
