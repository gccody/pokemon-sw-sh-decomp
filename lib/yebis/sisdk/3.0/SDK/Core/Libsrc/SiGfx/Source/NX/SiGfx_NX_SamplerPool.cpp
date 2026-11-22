// Scope: common
// SiSDK3::SiGfxNXSamplerPool: the function that makes a sampler (the pool's
// constructor, destructor and slots are in Unk_Pools.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Sampler_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

namespace SiSDK3 {

// 0x71005589e0: under the name and type the device's translation unit calls
// it by (index is the pool's item to take, 0 for any).
SiGfxNXSampler* Unk_5589e0(SiGfxNXSamplerPool* pool, ISiAllocator* pAllocator, const void* desc, u64 index) {
    Unk_596640 lock(pool->field_18.Unk_Get(), true);
    SiGfxResourcePool::ResourceItem* item;
    if (index != 0) {
        item = pool->field_48.Unk_4fef10(index);
    } else {
        item = pool->field_48.Unk_Alloc();
    }
    if (item == nullptr) {
        return nullptr;
    }
#line 130
    SiGfxNXSampler* sampler = UNK_SI_NEW(pAllocator, 0x10)
        SiGfxNXSampler(pAllocator, pool->field_178, *static_cast<const SiGfxNXSampler::Unk_Desc*>(desc));
    if (sampler == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!sampler->Unk_558e90(item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(sampler);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Sampler_%d", number);
        sampler->vf20(name);
    }
    return sampler;
}

}  // namespace SiSDK3
