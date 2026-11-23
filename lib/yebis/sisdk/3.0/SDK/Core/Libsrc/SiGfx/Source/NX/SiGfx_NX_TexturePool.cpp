// Scope: common
// SiSDK3::SiGfxNXTexturePool: the function that makes a texture and its slot
// 7 (the pool's constructor, destructor and other slots are in Unk_Pools.cpp;
// the function that makes the device's own textures, 0x710055d900, isn't
// written yet).
// (the pools' header first: it keeps SiCore_Pool.h's member definitions,
// which the original doesn't inline here, out of this translation unit)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Texture_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

// 0x710055f1c0 (leafgen's name and type): the texture's index in its pool
struct Unk_55f1c0;
bool Unk_55f1c0_update(Unk_55f1c0* self, u64 value);

namespace SiSDK3 {

// 0x710055d6c0: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXTexture* Unk_55d6c0(SiGfxNXTexturePool* pool, ISiAllocator* pAllocator, u32 kind, const void* index) {
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
#line 127
    SiGfxNXTexture* texture = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXTexture(pAllocator, pool->field_178, kind);
    if (texture == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_55f1c0_update(reinterpret_cast<Unk_55f1c0*>(texture), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(texture);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Texture_%d", number);
        texture->vf45(name);
    }
    return texture;
}

// 0x710055d8c0
void SiGfxNXTexturePool::vf7() {
    if (Unk_NXDevice(field_178)->vf11()->field_52) {
        Unk_55d900();
    }
    SiGfxResourcePool::vf7();
}

}  // namespace SiSDK3
