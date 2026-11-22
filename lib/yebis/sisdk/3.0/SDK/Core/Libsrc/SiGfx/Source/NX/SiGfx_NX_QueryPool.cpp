// Scope: common
// SiSDK3::SiGfxNXQueryPool: the function that makes a query (the pool's
// constructor, destructor and slots are in Unk_Pools.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Query_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

// 0x7100554b80 (leafgen's name and type): the query's index in its pool
struct Unk_554b80;
bool Unk_554b80_update(Unk_554b80* self, u64 value);

namespace SiSDK3 {

// 0x71005545f0: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXQuery* Unk_5545f0(SiGfxNXQueryPool* pool, ISiAllocator* pAllocator, const void* index) {
    Unk_596640 lock(pool->field_18.Unk_Get(), true);
    SiGfxResourcePool::ResourceItem* item;
    if (index != nullptr) {
        item = pool->field_48.Unk_4fef10(reinterpret_cast<size_t>(index));
    } else {
        item = pool->field_48.Unk_Alloc();
    }
    if (item == nullptr) {
        return nullptr;
    }
#line 109
    SiGfxNXQuery* query = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXQuery(pAllocator, pool->field_178);
    if (query == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_554b80_update(reinterpret_cast<Unk_554b80*>(query), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(query);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Query_%d", number);
        query->vf20(name);
    }
    return query;
}

}  // namespace SiSDK3
