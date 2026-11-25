#pragma once
// nn::pia::nex::NexCommunityInfoList (RTTI N2nn3pia3nex20NexCommunityInfoListE):
// an array of NexCommunityInfo pointers, all allocated by the constructor.
// Its members are 0x71016d8020-0x71016d82d0 (lib/pia/common/Unk_16d8140.cpp);
// NexNetworkFactory's vf82 creates one (lib/pia/common/Unk_16d7bb0.cpp).
// Member names are placeholders (vf<slot>, lib/pia/README.md).
#include <types.h>

namespace pead {
class Heap;
}

namespace nn {
namespace pia {
namespace nex {

// RTTI N2nn3pia3nex16NexCommunityInfoE (0x688 bytes, the size its list
// allocates). Its small members are in
// lib/nx_middleware/class/nn_pia_nex_NexCommunityInfo.cpp.
class NexCommunityInfo {
public:
    NexCommunityInfo();  // 0x71016d8a40
    virtual ~NexCommunityInfo();

    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();  // 0x71016d8bb0: its list's vf8 calls it on every entry

    u8 _8[0x688 - 0x8];
};
PKMN_SIZE_ASSERT(NexCommunityInfo, 0x688);

class NexCommunityInfoList {
public:
    explicit NexCommunityInfoList(u8 capacity);
    virtual ~NexCommunityInfoList();

    virtual NexCommunityInfo** vf2();  // m_Array
    virtual NexCommunityInfo** vf3();  // m_Array
    virtual NexCommunityInfo** vf4();  // the end of the m_Count entries
    virtual NexCommunityInfo** vf5();  // the end of the m_Count entries
    virtual u32 vf6();                 // m_Count
    virtual u32 vf7();                 // m_Capacity
    virtual void vf8();                // empties the list, calls each entry's vf16

    u32 m_Count;
    u32 m_Capacity;
    NexCommunityInfo** m_Array;
};
PKMN_OFFSET_ASSERT(NexCommunityInfoList, m_Count, 0x8);
PKMN_OFFSET_ASSERT(NexCommunityInfoList, m_Capacity, 0xc);
PKMN_OFFSET_ASSERT(NexCommunityInfoList, m_Array, 0x10);
PKMN_SIZE_ASSERT(NexCommunityInfoList, 0x18);

}  // namespace nex
}  // namespace pia
}  // namespace nn

// Called on an array before it's freed (0x71017163e0): reads a field of the
// heap block that holds it. Its result isn't used.
u64 Unk_17163e0(void* memory);
