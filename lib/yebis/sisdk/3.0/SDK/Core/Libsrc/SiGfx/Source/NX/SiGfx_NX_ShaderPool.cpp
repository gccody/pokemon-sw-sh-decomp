// Scope: common
// SiSDK3::SiGfxNXShaderPool: the function that makes a shader (the pool's
// constructor, destructor and slots are in Unk_Pools.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Shader_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

// 0x710055b100 (leafgen's name and type): the shader's index in its pool
struct Unk_55b100;
bool Unk_55b100_update(Unk_55b100* self, u64 value);

namespace SiSDK3 {

// 0x7100559500: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXShader* Unk_559500(SiGfxNXShaderPool* pool, ISiAllocator* pAllocator, u32 a1, const void* index) {
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
#line 128
    SiGfxNXShader* resource = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXShader(pAllocator, pool->field_178);
    if (resource == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_55b100_update(reinterpret_cast<Unk_55b100*>(resource), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(resource);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Shader_%d", number);
        resource->vf22(name);
    }
    return resource;
}

}  // namespace SiSDK3
