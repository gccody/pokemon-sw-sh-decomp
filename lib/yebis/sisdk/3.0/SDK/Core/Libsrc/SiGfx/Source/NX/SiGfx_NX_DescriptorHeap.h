// The device's two heaps of NVN descriptors (placeholder names, after their
// constructors, which lib/yebis/leaf has as Unk_5518d0_call and
// Unk_5520b0_call; the device's translation unit calls them Unk_5518d0_Pool
// and Unk_5520b0_Pool): an NVN texture pool and an NVN sampler pool, each
// with a list of the numbers that are free and one of those in use. Their
// translation unit is SiGfx_NX_DescriptorHeap.cpp (its __FILE__).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

// A descriptor's number and its links in the list it's in (placeholder name).
struct Unk_NXDescriptorNode {
    u32 field_0;
    Unk_NXDescriptorNode* field_8;
    Unk_NXDescriptorNode* field_10;
};
PKMN_SIZE_ASSERT(Unk_NXDescriptorNode, 0x18);

#define UNK_NX_DESCRIPTOR_HEAP_MEMBERS                                                         \
    SiOSCriticalSection* Unk_Lock() { return reinterpret_cast<SiOSCriticalSection*>(field_20); } \
                                                                                               \
    Unk_NXDescriptorNode* field_0; /* the nodes */                                             \
    SiGfxNXMemoryHeap* field_8;    /* where the NVN pool's memory is */                        \
    Unk_NXDescriptorNode* field_10; /* the list of the numbers in use */                       \
    Unk_NXDescriptorNode* field_18; /* the list of the free ones */                            \
    u64 field_20[6];                /* a SiOSCriticalSection */                                \
    void* field_50;                 /* the NVN pool */                                         \
    u32 field_58;                   /* how many numbers are in use */                          \
    u32 field_5c;                   /* how many there are */                                   \
    s64 field_60;                   /* the memory's room in the heap */                        \
    s64 field_68;                                                                              \
    bool field_70; /* whether the NVN pool is made */                                          \
    u32 field_74;  /* the first number */

class Unk_5518d0_Pool {
public:
    // 0x7100551910: the destructor, under the name the device's translation
    // unit calls it by
    void Unk_551910();
    // 0x7100551940: releases the texture pool
    void Unk_551940();
    // 0x7100551a50: makes it (not written yet)
    bool Unk_551a50(SiGfxNXDevice* pDevice, s32 a2, s32 a3);
    // 0x7100551ed0: a number for a texture and its view (-1: none), as an
    // image if a3; 0x7100551fd0: gives a number back
    s32 Unk_551ed0(u64 a1, u64 a2, bool a3);
    void Unk_551fd0(u32 id);

    UNK_NX_DESCRIPTOR_HEAP_MEMBERS
};
PKMN_SIZE_ASSERT(Unk_5518d0_Pool, 0x78);

class Unk_5520b0_Pool {
public:
    // 0x71005520f0: the destructor, under the name the device's translation
    // unit calls it by
    void Unk_5520f0();
    // 0x7100552120: releases the sampler pool
    void Unk_552120();
    // 0x7100552230: makes it (not written yet)
    bool Unk_552230(SiGfxNXDevice* pDevice, s32 a2, s32 a3);
    // 0x71005526b0: a number for a sampler (-1: none); 0x7100552790: gives a
    // number back
    s32 Unk_5526b0(u64 a1);
    void Unk_552790(u32 id);

    UNK_NX_DESCRIPTOR_HEAP_MEMBERS
};
PKMN_SIZE_ASSERT(Unk_5520b0_Pool, 0x78);

#undef UNK_NX_DESCRIPTOR_HEAP_MEMBERS

}  // namespace SiSDK3

// 0x7100552090, 0x7100552850: gives a command buffer the heap's NVN pool
// (free functions under the names and types their callers have)
void Unk_552090(void* self, u64 commandBuffer);
void Unk_552850(void* self, u64 commandBuffer);
