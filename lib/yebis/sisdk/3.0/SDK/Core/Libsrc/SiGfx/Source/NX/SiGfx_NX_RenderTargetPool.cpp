// Scope: common
// SiSDK3::SiGfxNXRenderTargetPool: the function that makes a render target (the pool's
// constructor, destructor and slots are in Unk_Pools.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RenderTarget_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

// 0x7100555b40 (leafgen's name and type): the render target's index in its pool
struct Unk_555b40;
bool Unk_555b40_update(Unk_555b40* self, u64 value);

namespace SiSDK3 {

// 0x7100555450: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXRenderTarget* Unk_555450(SiGfxNXRenderTargetPool* pool, ISiAllocator* pAllocator, const void* index) {
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
#line 104
    SiGfxNXRenderTarget* resource = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXRenderTarget(pAllocator, pool->field_178);
    if (resource == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_555b40_update(reinterpret_cast<Unk_555b40*>(resource), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(resource);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "RenderTarget_%d", number);
        resource->vf40(name);
    }
    return resource;
}

}  // namespace SiSDK3
