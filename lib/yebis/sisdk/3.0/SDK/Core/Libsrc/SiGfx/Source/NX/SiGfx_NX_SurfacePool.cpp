// Scope: common
// SiSDK3::SiGfxNXSurfacePool: the function that makes a surface (the pool's
// constructor, destructor and slots are in Unk_Pools.cpp).
// (the pools' header first: it keeps SiCore_Pool.h's member definitions,
// which the original doesn't inline here, out of this translation unit)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Surface_Impl.h>

// 0x710055c990 (leafgen's name and type): the surface's index in its pool
struct Unk_55c990;
bool Unk_55c990_update(Unk_55c990* self, u64 value);

namespace SiSDK3 {

// 0x710055c330: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXSurface* Unk_55c330(SiGfxNXSurfacePool* pool, ISiAllocator* pAllocator, const void* index) {
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
#line 103
    SiGfxNXSurface* surface = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXSurface(pAllocator, pool->field_178);
    if (surface == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_55c990_update(reinterpret_cast<Unk_55c990*>(surface), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(surface);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Surface_%d", number);
        surface->vf28(name);
    }
    return surface;
}

}  // namespace SiSDK3
