// Scope: common
// SiSDK3::SiDirectLinkedList<T*>'s destructors (its virtual D1 and D0), one
// explicit instantiation per element type that the executable has them for
// (the vtables' RTTI names). The elements link themselves: these declarations
// give each the links where its destructor finds them, and nothing else.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>

#define LINKS(T)   \
    T* m_pPrev;    \
    T* m_pNext

namespace SiSDK3 {
class SiFixedHeapAllocator2 {
public:
    struct MemoryBlockPtr {
        LINKS(MemoryBlockPtr);
    };
    struct MemoryBlockHeader {
        LINKS(MemoryBlockHeader);
    };
};
struct SiMemoryBlock {
    LINKS(SiMemoryBlock);
};
struct SiReflectionPropertyBase {
    void* field_0;  // its vtable
    LINKS(SiReflectionPropertyBase);
};
class SiGfxResourcePool {
public:
    struct ResourceItem {
        LINKS(ResourceItem);
    };
};
struct SiGfxFreeTypeGlyph {
    LINKS(SiGfxFreeTypeGlyph);
};
class SiGfxFreeTypeFaceCache {
public:
    struct CacheData;
};
template <class T>
class SiGfxQuadTree {
public:
    struct QuadNode {
        LINKS(QuadNode);
    };
};
class ISiGfxShaderEffectVariationList {
public:
    struct ShaderVariationItem {
        LINKS(ShaderVariationItem);
    };
    struct RequestNotFoundEntry {
        LINKS(RequestNotFoundEntry);
    };
};
class SiIOKernel {
public:
    struct ChunkHandlerTypeInfo {
        LINKS(ChunkHandlerTypeInfo);
    };
};
class ISiIOBinaryArchive {
public:
    struct ChunkHandler {
        u8 field_0[0x18];
        LINKS(ChunkHandler);
    };
};
}  // namespace SiSDK3

using namespace SiSDK3;

// 0x71004bcd40 (D1), 0x71004bf580 (D0)
template SiDirectLinkedList<SiFixedHeapAllocator2::MemoryBlockPtr*>::~SiDirectLinkedList();
// 0x71004beec0 (D1), 0x71004bef20 (D0)
template SiDirectLinkedList<SiFixedHeapAllocator2::MemoryBlockHeader*>::~SiDirectLinkedList();
// 0x71004c3950 (D1), 0x71004c40a0 (D0)
template SiDirectLinkedList<SiMemoryBlock*>::~SiDirectLinkedList();
// 0x71004cb380 (D1), 0x71004cb800 (D0)
template SiDirectLinkedList<SiReflectionPropertyBase*>::~SiDirectLinkedList();
// 0x7100501480 (D1), 0x71005014e0 (D0)
template SiDirectLinkedList<SiGfxFreeTypeGlyph*>::~SiDirectLinkedList();
// 0x7100532570 (D1), 0x71005325d0 (D0)
template SiDirectLinkedList<SiGfxQuadTree<SiGfxFreeTypeFaceCache::CacheData>::QuadNode*>::~SiDirectLinkedList();
// 0x7100536740 (D1), 0x71005367a0 (D0)
template SiDirectLinkedList<SiGfxResourcePool::ResourceItem*>::~SiDirectLinkedList();
// 0x71005711d0 (D1), 0x7100573930 (D0)
template SiDirectLinkedList<ISiGfxShaderEffectVariationList::RequestNotFoundEntry*>::~SiDirectLinkedList();
// 0x71005713b0 (D1), 0x7100573780 (D0)
template SiDirectLinkedList<ISiGfxShaderEffectVariationList::ShaderVariationItem*>::~SiDirectLinkedList();
// 0x710057a510 (D1), 0x710057c760 (D0)
template SiDirectLinkedList<ISiIOBinaryArchive::ChunkHandler*>::~SiDirectLinkedList();
// 0x710057d1b0 (D1), 0x710057dd40 (D0)
template SiDirectLinkedList<SiIOKernel::ChunkHandlerTypeInfo*>::~SiDirectLinkedList();
