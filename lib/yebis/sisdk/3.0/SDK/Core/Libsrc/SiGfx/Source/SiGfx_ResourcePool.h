// SiSDK3::SiGfxResourcePool (RTTI names the class): a pool of items for a
// kind of resource, the base of the device's pools. Placeholder members; the
// virtual functions are vf<slot>. The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_RESOURCEPOOL_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

// A resource as its pool uses it (placeholder name): slot 3 releases it, slot
// 7 is its index in the pool, slots 9 to 14 are what the pool's slots 7 to 12
// call on every resource.
class Unk_534460_Resource {
public:
    virtual ~Unk_534460_Resource();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual size_t vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

class SiGfxResourcePool {
public:
    // A pool's item (SiCore_Pool.h): its links, its index in the pool,
    // whether it's in use, and its resource.
    struct ResourceItem {
        ResourceItem* m_pPrev;
        ResourceItem* m_pNext;
        size_t field_10;
        bool field_18;
        Unk_534460_Resource* field_20;
    };

    explicit SiGfxResourcePool(ISiAllocator* pAllocator);
    virtual ~SiGfxResourcePool();
    UNK_REFCOUNT_DECLARE;
    virtual void vf4();
    virtual bool vf5(s32 count);  // makes room for count resources
    virtual void vf6();           // releases the resources
    virtual void vf7();           // these six call a slot of every resource
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(Unk_534460_Resource* resource);  // takes a resource's item back

    // the first resource in use and the one after another (inline in their
    // callers: placeholder names)
    Unk_534460_Resource* Unk_First() {
        Unk_596640 lock(field_18.Unk_Get(), true);
        return field_48.m_usedList.m_count != 0 ? field_48.m_usedList.m_pHead->field_20 : nullptr;
    }
    Unk_534460_Resource* Unk_Next(Unk_534460_Resource* resource) {
        Unk_596640 lock(field_18.Unk_Get(), true);
        ResourceItem* next = field_48.Unk_Get(resource->vf7())->m_pNext;
        return next != nullptr ? next->field_20 : nullptr;
    }

    // 0x7100534420 (leafgen's name and type): what the pools' vf5 call first
    u32 vf5();
    // 0x7100534460: releases every resource
    void Unk_534460();

    Unk_4bf660 field_8;
    Unk_CriticalSection field_18;
    SiPool<ResourceItem, 16> field_48;
    bool field_170;
};
PKMN_SIZE_ASSERT(SiGfxResourcePool, 0x178);
PKMN_OFFSET_ASSERT(SiGfxResourcePool, field_48, 0x48);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_RESOURCEPOOL_IMPL
// 0x71004ff160 (vf2), 0x71004ff180 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxResourcePool, field_8.m_pAllocator, field_8.m_count)
#endif
