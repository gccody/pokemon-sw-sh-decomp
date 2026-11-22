// Scope: common
// The device's heaps of NVN texture and sampler descriptors: their release,
// the numbers they hand out and take back. (Their constructors and counts are
// lib/yebis/leaf's; the functions that make them aren't written yet.)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DescriptorHeap.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>

// 0x7100596760: lets other threads run
void Unk_596760();

// NVN's entry points that only the heaps call (nvn.h has them without their
// types).
inline void Unk_nvnTexturePoolRegisterImage(void* pool, int id, const void* texture, const void* view) {
    reinterpret_cast<void (*)(void*, int, const void*, const void*)>(Unk_27fc9f8)(pool, id, texture, view);
}
inline void Unk_nvnCommandBufferSetSamplerPool(void* commandBuffer, const void* pool) {
    reinterpret_cast<void (*)(void*, const void*)>(Unk_27fd508)(commandBuffer, pool);
}

namespace SiSDK3 {

// A heap's release: once it has the lock, its nodes, its memory's room and
// its NVN pool go. (The lines are the two frees'.)
#define UNK_RELEASE(Class, Name, Finalize, Line1, Line2)                \
    void Class::Name() {                                                \
        if (!field_70) {                                                \
            return;                                                     \
        }                                                               \
        ISiAllocator* pAllocator = Unk_NXKernel()->vf6();               \
        while (!Unk_Lock()->SiOSCriticalSection::vf4()) {               \
            Unk_596760();                                               \
        }                                                               \
        if (field_0 != nullptr) {                                       \
            pAllocator->vf9(field_0, __FILE__, Line1);                  \
            field_0 = nullptr;                                          \
        }                                                               \
        if (field_8 != nullptr) {                                       \
            field_8->Unk_553010(field_60);                              \
            if (field_8 != nullptr) {                                   \
                field_8->vf3();                                         \
                field_8 = nullptr;                                      \
            }                                                           \
            field_60 = 0;                                               \
            field_68 = 0;                                               \
        }                                                               \
        Finalize(field_50);                                             \
        if (field_50 != nullptr) {                                      \
            if (pAllocator != nullptr) {                                \
                pAllocator->vf9(field_50, __FILE__, Line2);             \
            }                                                           \
            field_50 = nullptr;                                         \
        }                                                               \
        field_58 = 0;                                                   \
        field_5c = 0;                                                   \
        field_74 = 0;                                                   \
        field_70 = false;                                               \
    }

// The first free node goes to the end of the list of those in use (in both
// heaps' functions: placeholder name); no number if there's none left.
#define UNK_TAKE_NODE(node)                                             \
    Unk_NXDescriptorNode* node = field_18->field_10;                    \
    if (node == field_18 || field_58 + 1 >= field_5c) {                 \
        return -1;                                                      \
    }                                                                   \
    field_18->field_10 = node->field_10;                                \
    node->field_8 = field_10->field_8;                                  \
    node->field_10 = field_10;                                          \
    node->field_10->field_8 = node;                                     \
    node->field_8->field_10 = node;

// A number's node goes back to the free ones.
#define UNK_GIVE_BACK(Class, Name)                                      \
    void Class::Name(u32 id) {                                          \
        if (id == 0xffffffff) {                                         \
            return;                                                     \
        }                                                               \
        Unk_596640 lock(Unk_Lock(), true);                              \
        u32 index = id - field_74 + 2;                                  \
        Unk_NXDescriptorNode* node = field_5c + 2 > index ? &field_0[index] : nullptr; \
        node->field_8->field_10 = node->field_10;                       \
        node->field_10->field_8 = node->field_8;                        \
        node->field_10 = field_18->field_10;                            \
        node->field_8 = nullptr;                                        \
        field_18->field_10 = node;                                      \
        field_58--;                                                     \
    }

// 0x7100551910
void Unk_5518d0_Pool::Unk_551910() {
    Unk_551940();
    Unk_Lock()->SiOSCriticalSection::~SiOSCriticalSection();
}

// 0x7100551940
#line 194
UNK_RELEASE(Unk_5518d0_Pool, Unk_551940, nvnTexturePoolFinalize, 194, 208)

// 0x7100551ed0
s32 Unk_5518d0_Pool::Unk_551ed0(u64 a1, u64 a2, bool a3) {
    if (a1 == 0 || a2 == 0) {
        return -1;
    }
    Unk_596640 lock(Unk_Lock(), true);
    UNK_TAKE_NODE(node)
    if (a3) {
        Unk_nvnTexturePoolRegisterImage(field_50, node->field_0, reinterpret_cast<const void*>(a1),
                                        reinterpret_cast<const void*>(a2));
    } else {
        nvnTexturePoolRegisterTexture(field_50, node->field_0, reinterpret_cast<const void*>(a1),
                                      reinterpret_cast<const void*>(a2));
    }
    field_58++;
    return node->field_0;
}

// 0x7100551fd0
UNK_GIVE_BACK(Unk_5518d0_Pool, Unk_551fd0)

// 0x71005520f0
void Unk_5520b0_Pool::Unk_5520f0() {
    Unk_552120();
    Unk_Lock()->SiOSCriticalSection::~SiOSCriticalSection();
}

// 0x7100552120
UNK_RELEASE(Unk_5520b0_Pool, Unk_552120, nvnSamplerPoolFinalize, 467, 481)

// 0x71005526b0
s32 Unk_5520b0_Pool::Unk_5526b0(u64 a1) {
    if (a1 == 0) {
        return -1;
    }
    Unk_596640 lock(Unk_Lock(), true);
    UNK_TAKE_NODE(node)
    nvnSamplerPoolRegisterSampler(field_50, node->field_0, reinterpret_cast<const void*>(a1));
    field_58++;
    return node->field_0;
}

// 0x7100552790
UNK_GIVE_BACK(Unk_5520b0_Pool, Unk_552790)

#undef UNK_RELEASE
#undef UNK_TAKE_NODE
#undef UNK_GIVE_BACK

}  // namespace SiSDK3

// 0x7100552090
void Unk_552090(void* self, u64 commandBuffer) {
    nvnCommandBufferSetTexturePool(reinterpret_cast<void*>(commandBuffer),
                                   static_cast<SiSDK3::Unk_5518d0_Pool*>(self)->field_50);
}

// 0x7100552850
void Unk_552850(void* self, u64 commandBuffer) {
    Unk_nvnCommandBufferSetSamplerPool(reinterpret_cast<void*>(commandBuffer),
                                       static_cast<SiSDK3::Unk_5520b0_Pool*>(self)->field_50);
}
