// Scope: common
// SiSDK3::SiGfxNXBufferPool: the function that makes a buffer and its slot 7
// (the pool's constructor, destructor and other slots are in Unk_Pools.cpp).
// (the pools' header first: the buffer's includes SiCore_Pool.h's member
// definitions, which the original doesn't inline here)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>

// 0x7100537550 (leafgen's name and type): the buffer's index in its pool
struct Unk_537550;
bool Unk_537550_update(Unk_537550* self, u64 value);

namespace SiSDK3 {

// 0x7100536dc0: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXBuffer* Unk_536dc0(SiGfxNXBufferPool* pool, ISiAllocator* pAllocator, const void* index) {
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
#line 105
    SiGfxNXBuffer* buffer = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXBuffer(pAllocator, pool->field_178);
    if (buffer == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_537550_update(reinterpret_cast<Unk_537550*>(buffer), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(buffer);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Buffer_%d", number);
        buffer->vf30(name);
    }
    return buffer;
}

// 0x7100537000: the device's own buffers
void SiGfxNXBufferPool::Unk_537000() {
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    SiGfxNXBuffer* buffer = Unk_536dc0(this, pAllocator, reinterpret_cast<const void*>(1));
    if (buffer != nullptr) {
        SiGfxNXBuffer::Unk_MakeDesc desc(0x29, 4, 4, 1, 8, 0x20);
        buffer->vf21(&desc);
    }
    buffer = Unk_536dc0(this, pAllocator, reinterpret_cast<const void*>(2));
    if (buffer != nullptr) {
        SiGfxNXBuffer::Unk_MakeDesc desc(0x29, 4, 4, 1, 4, 0x20);
        buffer->vf21(&desc);
    }
    buffer = Unk_536dc0(this, pAllocator, reinterpret_cast<const void*>(3));
    if (buffer != nullptr) {
        SiGfxNXBuffer::Unk_MakeDesc desc(0x29, 4, 4, 1, 8, 0x40);
        buffer->vf21(&desc);
    }
}

// 0x7100536fc0
void SiGfxNXBufferPool::vf7() {
    if (Unk_NXDevice(field_178)->vf11()->field_52) {
        Unk_537000();
    }
    SiGfxResourcePool::vf7();
}

}  // namespace SiSDK3
