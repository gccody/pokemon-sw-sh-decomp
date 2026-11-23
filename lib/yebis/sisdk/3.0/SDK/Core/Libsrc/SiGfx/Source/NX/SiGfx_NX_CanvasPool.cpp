// Scope: common
// SiSDK3::SiGfxNXCanvasPool: the functions that make a canvas and find one
// (the pool's constructor, destructor and slots are in Unk_Pools.cpp).
// (the pools' header first: it keeps SiCore_Pool.h's member definitions,
// which the original doesn't inline here, out of this translation unit)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Canvas_Impl.h>

// 0x71004fbb10 (leafgen's name and type): the canvas's index in its pool
struct Unk_4fbb10;
bool Unk_4fbb10_update(Unk_4fbb10* self, u64 value);

namespace SiSDK3 {

// 0x7100538f60: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXCanvas* Unk_538f60(SiGfxNXCanvasPool* pool, ISiAllocator* pAllocator, const void* index) {
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
#line 107
    SiGfxNXCanvas* canvas = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXCanvas(pAllocator, pool->field_178);
    if (canvas == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_4fbb10_update(reinterpret_cast<Unk_4fbb10*>(canvas), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(canvas);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Canvas_%d", number);
        canvas->vf51(name);
    }
    return canvas;
}

// 0x7100539160: the canvas of a window
SiGfxNXCanvas* Unk_539160(SiGfxNXCanvasPool* pool, u64 window) {
    Unk_596640 lock(pool->field_18.Unk_Get(), true);
    Unk_534460_Resource* resource;
    for (resource = pool->Unk_534810(); resource != nullptr; resource = pool->Unk_534870(resource)) {
        if (reinterpret_cast<SiGfxNXCanvas*>(resource)->vf21() == window) {
            break;
        }
    }
    return reinterpret_cast<SiGfxNXCanvas*>(resource);
}

}  // namespace SiSDK3
