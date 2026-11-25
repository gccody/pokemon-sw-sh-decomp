// Scope: common
// nex::NexCommunityInfoList's members (lib/pia/common/Unk_16d8140.h), then
// nex::NexJoinMeshJob's (RTTI N2nn3pia3nex14NexJoinMeshJobE, derived from
// mesh::JoinMeshJob). Member names are placeholders (vf<slot>,
// lib/pia/README.md), except the steps a job stores with their names.
#include "pia/common/Unk_16d8140.h"

// Pia's allocation (pia/common/Unk_17162d0.h), except that this file's operator
// new isn't noexcept: the constructor's `new` isn't checked for null here.
pead::Heap* Unk_1652bd0();
void* operator new(size_t size, pead::Heap* heap);
void Unk_1716390(void* memory);

namespace nn {
namespace pia {
namespace nex {

// 0x71016d8020
NexCommunityInfoList::NexCommunityInfoList(u8 capacity) : m_Capacity(capacity) {
    pead::Heap* heap = Unk_1652bd0();
    NexCommunityInfo** array =
        static_cast<NexCommunityInfo**>(operator new(sizeof(NexCommunityInfo*) * capacity, heap));
    if (array != nullptr) {
        for (size_t i = 0; i < capacity; i++) {
            array[i] = nullptr;
        }
    }
    m_Array = array;
    for (u32 i = 0; i < m_Capacity; i++) {
        NexCommunityInfo* info = new (Unk_1652bd0()) NexCommunityInfo();
        info->vf16();
        m_Array[i] = info;
    }
    vf8();
}

// 0x71016d8140 (and 0x71016d81e0, deleting)
NexCommunityInfoList::~NexCommunityInfoList() {
    for (u32 i = 0; i < m_Capacity; i++) {
        NexCommunityInfo* info = m_Array[i];
        if (info != nullptr) {
            info->~NexCommunityInfo();
            Unk_1716390(info);
        }
    }
    NexCommunityInfo** array = m_Array;
    if (array != nullptr) {
        Unk_17163e0(array);
        Unk_1716390(array);
    }
}

// 0x71016d8290
NexCommunityInfo** NexCommunityInfoList::vf4() {
    return m_Array + m_Count;
}

// 0x71016d82a0
NexCommunityInfo** NexCommunityInfoList::vf5() {
    return m_Array + m_Count;
}

// 0x71016d82d0
void NexCommunityInfoList::vf8() {
    m_Count = 0;
    for (u32 i = 0; i < m_Capacity; i++) {
        m_Array[i]->vf16();
    }
}

}  // namespace nex

namespace mesh {

// RTTI N2nn3pia4mesh11JoinMeshJobE. A job runs one step at a time: the member
// function at field_30, whose name (as "Class::Function") is at field_40.
class JoinMeshJob {
public:
    typedef u64 (JoinMeshJob::*Step)();

    virtual ~JoinMeshJob();  // 0x710169e170
    virtual void vf2(bool value);
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u64 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();

    // JoinMeshJob's vf6 and vf8 store them, named "JoinMeshJob::...".
    u64 SetupLocalPlayerInfo();  // 0x710169e430
    u64 SetupLocalStation();     // 0x710169e5a0

    u8 _8[0x30 - 0x8];
    Step field_30;
    const char* field_40;
};
PKMN_OFFSET_ASSERT(JoinMeshJob, field_30, 0x30);
PKMN_OFFSET_ASSERT(JoinMeshJob, field_40, 0x40);

}  // namespace mesh

namespace nex {

// The object behind the global Unk_27fb310 (no RTTI name known).
class Unk_27fb310_type {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual bool vf11();
};

struct Unk_27fa8b8_type {
    u8 _0[0x60];
    s64 field_60;
    s32 field_68;
    u8 field_6c[0x10];
    u8 _7c[0xd8 - 0x7c];
    s32 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_27fa8b8_type, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_27fa8b8_type, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_27fa8b8_type, field_d8, 0xd8);

class NexJoinMeshJob : public mesh::JoinMeshJob {
public:
    ~NexJoinMeshJob() override;
    u64 vf6() override;
    void vf7() override;  // lib/nx_middleware/class/nn_pia_nex_NexJoinMeshJob.cpp
    void vf8() override;

    u64 StartMonitoringServerAddressResolution();
};

}  // namespace nex
}  // namespace pia
}  // namespace nn

extern nn::pia::nex::Unk_27fb310_type* Unk_27fb310;
extern nn::pia::nex::Unk_27fa8b8_type Unk_27fa8b8;

namespace nn {
namespace pia {
namespace nex {

// 0x71016d8350 (and 0x71016d8360, deleting)
NexJoinMeshJob::~NexJoinMeshJob() {}

// 0x71016d8390
u64 NexJoinMeshJob::vf6() {
    vf2(true);
    field_30 = &NexJoinMeshJob::SetupLocalPlayerInfo;
    field_40 = "NexJoinMeshJob::SetupLocalPlayerInfo";
    if (Unk_27fb310->vf11()) {
        Unk_27fa8b8.field_d8 = -1;
        Unk_27fa8b8.field_60 = -1;
        Unk_27fa8b8.field_68 = -1;
        for (int i = 0; i < 0x10; i++) {
            Unk_27fa8b8.field_6c[i] = 0xff;
        }
    }
    return 1;
}

// 0x71016d8430
void NexJoinMeshJob::vf8() {
    field_30 = static_cast<Step>(&NexJoinMeshJob::StartMonitoringServerAddressResolution);
    field_40 = "NexJoinMeshJob::StartMonitoringServerAddressResolution";
}

// 0x71016d8450
u64 NexJoinMeshJob::StartMonitoringServerAddressResolution() {
    field_30 = &NexJoinMeshJob::SetupLocalStation;
    field_40 = "NexJoinMeshJob::SetupLocalStation";
    return 0;
}

}  // namespace nex
}  // namespace pia
}  // namespace nn
