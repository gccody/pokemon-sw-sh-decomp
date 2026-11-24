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

// A heap's making (both heaps' functions: the kind of memory, NVN's name
// for the size of a descriptor, the pool's initialisation and the lines of
// the allocations and frees differ): its nodes, room for the descriptors in
// a memory heap, the NVN pool, then the nodes' numbers and the two lists.
#define UNK_MAKE(Class, Name, Kind, SizeName, Initialize, LineNodes, LinePool, LineFree1, LineFree2, LineFree3,     \
                 LineFree4)                                                                                         \
    bool Class::Name(SiGfxNXDevice* pDevice, s32 count, s32 first) {                                                \
        if (pDevice == nullptr || count == 0) {                                                                     \
            return false;                                                                                           \
        }                                                                                                           \
        Unk_596640 lock(Unk_Lock(), true);                                                                          \
        u32 n = count;                                                                                              \
        u32 total = n + 0x102;                                                                                      \
        ISiAllocator* pAllocator = Unk_NXKernel()->vf6();                                                           \
        size_t nodesSize = total * sizeof(Unk_NXDescriptorNode);                                                    \
        field_0 = static_cast<Unk_NXDescriptorNode*>(pAllocator->vf7(nodesSize, 1, __FILE__, LineNodes));           \
        if (field_0 != nullptr) {                                                                                   \
            void* device = Unk_NXDevice(pDevice)->vf85();                                                           \
            int descriptorSize = 0;                                                                                 \
            nvnDeviceGetInteger(device, SizeName, &descriptorSize);                                                 \
            size_t poolSize = Unk_NXAlign(descriptorSize * total, descriptorSize);                                  \
            field_8 = Unk_NXDevice(pDevice)->vf30(0, nullptr);                                                      \
            Unk_NXMemoryHeapDesc heapDesc(poolSize);                                                                \
            heapDesc.field_10 = 0;                                                                                  \
            heapDesc.field_30 = (Unk_563620(Kind, 0, 0, 0) & ~3) | 2;                                               \
            if (field_8->vf8(&heapDesc) &&                                                                          \
                field_8->Unk_552fc0(static_cast<s32>(poolSize), descriptorSize, &field_60)) {                       \
                field_68 = Unk_NXAlign(field_60, descriptorSize);                                                   \
                field_50 = pAllocator->vf7(0x20, 0x10, __FILE__, LinePool);                                         \
                if (field_50 == nullptr) {                                                                          \
                    pAllocator->vf9(field_0, __FILE__, LineFree1);                                                  \
                    if (field_8 != nullptr) {                                                                       \
                        field_8->vf3();                                                                             \
                        field_8 = nullptr;                                                                          \
                    }                                                                                               \
                    if (field_50 != nullptr) {                                                                      \
                        pAllocator->vf9(field_50, __FILE__, LineFree2);                                             \
                        field_50 = nullptr;                                                                         \
                    }                                                                                               \
                    field_0 = nullptr;                                                                              \
                    return false;                                                                                   \
                }                                                                                                   \
                if (Initialize(field_50, field_8->vf16(), field_68, total) != 1) {                                  \
                    pAllocator->vf9(field_0, __FILE__, LineFree3);                                                  \
                    if (field_8 != nullptr) {                                                                       \
                        field_8->vf3();                                                                             \
                        field_8 = nullptr;                                                                          \
                    }                                                                                               \
                    if (field_50 != nullptr) {                                                                      \
                        pAllocator->vf9(field_50, __FILE__, LineFree4);                                             \
                        field_50 = nullptr;                                                                         \
                    }                                                                                               \
                    field_0 = nullptr;                                                                              \
                    return false;                                                                                   \
                }                                                                                                   \
                field_74 = first;                                                                                   \
                field_5c = count;                                                                                   \
                memset(field_0, 0, nodesSize);                                                                      \
                for (u32 i = 2; i < n + 2; i++) {                                                                   \
                    Unk_NXDescriptorNode* node = &field_0[i];                                                       \
                    *node = Unk_NXDescriptorNode();                                                                 \
                    node->field_0 = first + (i - 2);                                                                \
                }                                                                                                   \
                field_10 = Unk_Node(0);                                                                             \
                field_10->field_10 = field_10;                                                                      \
                field_10->field_8 = field_10;                                                                       \
                field_10->field_0 = 0xffffffff;                                                                     \
                field_18 = Unk_Node(1);                                                                             \
                field_18->field_0 = 0xffffffff;                                                                     \
                for (u32 i = 1; i < n + 2; i++) {                                                                   \
                    Unk_NXDescriptorNode* node = Unk_Node(i);                                                       \
                    node->field_8 = nullptr;                                                                        \
                    node->field_10 = Unk_Node(i + 1);                                                               \
                }                                                                                                   \
                field_0[n + 1].field_8 = field_18;                                                                  \
                field_58 = 0;                                                                                       \
                field_70 = true;                                                                                    \
                return true;                                                                                        \
            }                                                                                                       \
        }                                                                                                           \
        return false;                                                                                               \
    }

// 0x7100551910
void Unk_5518d0_Pool::Unk_551910() {
    Unk_551940();
    Unk_Lock()->SiOSCriticalSection::~SiOSCriticalSection();
}

// 0x7100551940
#line 194
UNK_RELEASE(Unk_5518d0_Pool, Unk_551940, nvnTexturePoolFinalize, 194, 208)

// NON_MATCHING (and 0x7100552230): the numbers' loop, unrolled by two in
// both, has its trip count from count + 2 here, from count in the original
// (which tests count + 2 >= 3 for its guard and keeps count + 2 for later);
// `i - 2 < n` gives the trip count from count and the original's size, but
// not its offset induction variable; and one store of the heap's
// description is scheduled a slot later. The failures before the NVN
// pool's initialisation share one block that sets the result to false once
// the function has one `return false` after nested tests (with an early
// `return false` for each, each failure sets it before its test and the
// frame is 16 bytes larger).
// 0x7100551a50
UNK_MAKE(Unk_5518d0_Pool, Unk_551a50, 0, 0xf, nvnTexturePoolInitialize, 68, 112, 116, 118, 131, 133)

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

// 0x7100552230
UNK_MAKE(Unk_5520b0_Pool, Unk_552230, 0xc, 0x10, nvnSamplerPoolInitialize, 343, 386, 390, 392, 404, 406)

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

#undef UNK_MAKE
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
