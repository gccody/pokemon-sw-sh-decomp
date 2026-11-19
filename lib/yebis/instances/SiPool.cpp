// Scope: common
// SiSDK3::SiPool<T, 16>'s destructors (its virtual D1 and D0) and its reset
// (vtable slot 4), one explicit instantiation per instance the executable has
// (the vtables' RTTI names). The element types get what these read: their
// links, their index and in-use flag, their size where the destructor loops.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>

#define POOL_ITEM(T)         \
    T* m_pPrev;              \
    T* m_pNext;              \
    size_t field_10;         \
    bool field_18

namespace SiSDK3 {
class SiFixedHeapAllocator2 {
public:
    struct MemoryBlockHeader {
        POOL_ITEM(MemoryBlockHeader);
    };
};
class SiGfxFreeTypeGlyph {
public:
    ~SiGfxFreeTypeGlyph();

    POOL_ITEM(SiGfxFreeTypeGlyph);
    u8 field_19[0x7f];
};
PKMN_SIZE_ASSERT(SiGfxFreeTypeGlyph, 0x98);
class SiGfxFreeTypeFaceCache {
public:
    struct CacheData;
};
template <class T>
class SiGfxQuadTree {
public:
    struct QuadNode {
        POOL_ITEM(QuadNode);
    };
};
class SiGfxResourcePool {
public:
    struct ResourceItem {
        POOL_ITEM(ResourceItem);
    };
};
}  // namespace SiSDK3

using namespace SiSDK3;

// 0x71004bea80 (D1), 0x71004bec20 (D0), 0x71004bd7e0 (Unk_4bd7e0)
template SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::~SiPool();
template void SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::Unk_4bd7e0();
// 0x7100500300 (D1), 0x71005011e0 (D0), 0x7100500de0 (Unk_4bd7e0)
template SiPool<SiGfxFreeTypeGlyph, 16>::~SiPool();
template void SiPool<SiGfxFreeTypeGlyph, 16>::Unk_4bd7e0();
// 0x7100531c20 (D1), 0x7100531dc0 (D0), 0x7100532220 (Unk_4bd7e0)
template SiPool<SiGfxQuadTree<SiGfxFreeTypeFaceCache::CacheData>::QuadNode, 16>::~SiPool();
template void SiPool<SiGfxQuadTree<SiGfxFreeTypeFaceCache::CacheData>::QuadNode, 16>::Unk_4bd7e0();
// 0x7100534210 (D1), 0x71005363c0 (D0), 0x71005363f0 (Unk_4bd7e0)
template SiPool<SiGfxResourcePool::ResourceItem, 16>::~SiPool();
template void SiPool<SiGfxResourcePool::ResourceItem, 16>::Unk_4bd7e0();
