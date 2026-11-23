// Scope: common
// SiSDK3::SiGfxNXVertexFormatPool: the function that makes a vertex format
// (the pool's constructor, destructor and other slots are in Unk_Pools.cpp).
// (the pools' header first: the resources' includes bring SiCore_Pool.h's
// member definitions, which the original doesn't inline here)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_VertexFormat_Impl.h>

// 0x7100564950 (leafgen's name and type): the vertex format's index in its pool
struct Unk_564950;
bool Unk_564950_update(Unk_564950* self, u64 value);

namespace SiSDK3 {

// One of the pool's own vertex formats: made with the device's allocator and
// put in the pool's item of the index (inline in its caller, which has one
// line for all of them: placeholder name).
inline void Unk_AddFormat(SiGfxNXVertexFormatPool* pool, u64 index, const char* name, s32 count,
                          const SiGfxNXVertexFormat::Unk_Element* elements) {
#line 1063
    SiGfxNXVertexFormat* format = UNK_SI_NEW(static_cast<ISiAllocator*>(pool->field_178->field_8), 0x10)
        SiGfxNXVertexFormat(pool->field_8.m_pAllocator, pool->field_178);
    Unk_564950_update(reinterpret_cast<Unk_564950*>(format), index);
    format->vf35(name);
    format->vf17(count, elements);
    pool->field_48.Unk_4fef10(index)->field_20 = reinterpret_cast<Unk_534460_Resource*>(format);
}

// 0x7100563810: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXVertexFormat* Unk_563810(SiGfxNXVertexFormatPool* pool, ISiAllocator* pAllocator, const void* index) {
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
    SiGfxNXVertexFormat* format = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXVertexFormat(pAllocator, pool->field_178);
    if (format == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_564950_update(reinterpret_cast<Unk_564950*>(format), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(format);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "VertexFormat_%d", number);
        format->vf35(name);
    }
    return format;
}

// 0x7100563a40: the pool's own vertex formats (index 15 has index 3's name)
void SiGfxNXVertexFormatPool::Unk_563a40() {
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 1, "VERTEXFORMAT_POS", 1, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 2, "VERTEXFORMAT_POS_COLOR", 2, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 3, "VERTEXFORMAT_POS_COLOR_TEX", 3, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 4, "VERTEXFORMAT_POS_NORMAL_COLOR_TEX", 4, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 5, "VERTEXFORMAT_POS_TEX", 2, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {5, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 6, "VERTEXFORMAT_POS_TEX3D", 2, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 7, "VERTEXFORMAT_POS_NORMAL", 2, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 8, "VERTEXFORMAT_POS_NORMAL_TEX", 3, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {6, 0, 6, 0, -1, 0, 0},
            {7, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 9, "VERTEXFORMAT_POS_NORMAL_TEX_TAN", 5, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {6, 0, 6, 0, -1, 0, 0},
            {7, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 10, "VERTEXFORMAT_POS_NORMAL_COLOR_TEX_TAN", 6, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {5, 1, 16, 0, -1, 0, 0},
            {6, 0, 6, 0, -1, 0, 0},
            {7, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 11, "VERTEXFORMAT_POS_NORMAL_TEX2_TAN", 6, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {5, 1, 16, 0, -1, 0, 0},
            {5, 2, 16, 0, -1, 0, 0},
            {5, 3, 16, 0, -1, 0, 0},
            {6, 0, 6, 0, -1, 0, 0},
            {7, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 12, "VERTEXFORMAT_POS_NORMAL_COLOR_TEX4_TAN", 8, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {1, 0, 28, 0, -1, 0, 0},
            {2, 0, 2, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {6, 0, 6, 0, -1, 0, 0},
            {7, 0, 6, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 13, "VERTEXFORMAT_POS_BLEND_NORMAL_COLOR_TEX_TAN", 8, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {5, 1, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 14, "VERTEXFORMAT_POS_NORMAL_COLOR_MULTITEX2", 5, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {5, 1, 16, 0, -1, 0, 0},
            {5, 2, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 15, "VERTEXFORMAT_POS_COLOR_TEX", 6, elements);
    }
    {
        SiGfxNXVertexFormat::Unk_Element elements[] = {
            {0, 0, 6, 0, -1, 0, 0},
            {3, 0, 6, 0, -1, 0, 0},
            {4, 0, 28, 0, -1, 0, 0},
            {5, 0, 16, 0, -1, 0, 0},
            {5, 1, 16, 0, -1, 0, 0},
            {5, 2, 16, 0, -1, 0, 0},
            {5, 3, 16, 0, -1, 0, 0},
        };
        Unk_AddFormat(this, 16, "VERTEXFORMAT_POS_NORMAL_COLOR_MULTITEX4", 7, elements);
    }
}

// 0x7100563a10
void SiGfxNXVertexFormatPool::vf7() {
    Unk_563a40();
    SiGfxResourcePool::vf7();
}

}  // namespace SiSDK3
