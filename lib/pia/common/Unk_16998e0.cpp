// Scope: common
// local::LocalEjectClientListCheckJob's destructors and steps
// (lib/pia/common/Unk_16998e0.h). Its constructor (0x71016997e0) isn't
// decompiled yet.
#include "pia/common/Unk_16998e0.h"

#include "pia/common/Unk_17162d0.h"

namespace nn {
namespace pia {
namespace local {

// 0x71016998e0 (and 0x71016999a0, deleting)
LocalEjectClientListCheckJob::~LocalEjectClientListCheckJob() {
    LocalEjectClientBackgroundJob* job = m_BackgroundJob;
    if (job != nullptr) {
        job->~LocalEjectClientBackgroundJob();
        Unk_1716390(job);
        m_BackgroundJob = nullptr;
    }
    m_Owner = nullptr;
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x71016999d0
Unk_165e060 LocalEjectClientListCheckJob::Unk_16999d0() {
    m_Queue.Clear();
    SetStep(&LocalEjectClientListCheckJob::CheckTargetList, "LocalEjectClientListCheckJob::CheckTargetList");
    return Unk_165e060Value<0>();
}

// 0x7101699a50
common::Unk_165bb20_result LocalEjectClientListCheckJob::CheckTargetList() {
    if (m_Queue.m_Count == 0) {
        return {5};
    }
    SetStep(&LocalEjectClientListCheckJob::EjectTargetClient, "LocalEjectClientListCheckJob::EjectTargetClient");
    return {0};
}

// 0x7101699a90
void LocalEjectClientListCheckJob::Unk_1699a90() {
    if (m_BackgroundJob != nullptr) {
        m_BackgroundJob->Cancel(2);
        m_BackgroundJob->Unk_169a0d0();
    }
    m_Queue.Clear();
}

// 0x7101699ae0
bool LocalEjectClientListCheckJob::Unk_1699ae0(const Unk_165fb30& address) {
    {
        Unk_1653bb0_arg1 text;
        Unk_1653bb0_update(const_cast<Unk_1652c70*>(&address.field_8), &text);
    }
    Unk_1699ae0_list* list = m_Owner->field_308;
    list->vf6(&address.field_8);
    s32 count = m_Queue.m_Count;
    for (s32 i = 0; i < count; i++) {
        Unk_165fb30 entry(m_Queue.Front());
        m_Queue.PopFront();
        if (list->vf6(&entry.field_8)) {
            m_Queue.PushBack(entry);
        }
    }
    return m_Queue.PushBack(address);
}

// 0x7101699ca0
common::Unk_165bb20_result LocalEjectClientListCheckJob::EjectTargetClient() {
    Unk_165fb30 target(m_Queue.Front());
    m_Queue.PopFront();
    m_BackgroundJob->Unk_1699f40(&m_Context, target);
    m_BackgroundJob->Unk_1655850(true);
    SetStep(&LocalEjectClientListCheckJob::WaitEjectTargetClient,
            "LocalEjectClientListCheckJob::WaitEjectTargetClient");
    return {5};
}

// 0x7101699d80
common::Unk_165bb20_result LocalEjectClientListCheckJob::WaitEjectTargetClient() {
    switch (m_Context.m_State) {
    case 1:
        return {5};
    case 2:
        SetStep(&LocalEjectClientListCheckJob::WaitBackgroundJobEnd,
                "LocalEjectClientListCheckJob::WaitBackgroundJobEnd");
        return {0};
    case 3:
        SetStep(&LocalEjectClientListCheckJob::WaitBackgroundJobEnd,
                "LocalEjectClientListCheckJob::WaitBackgroundJobEnd");
        return {0};
    case 4:
        return {1};
    default:
        return {1};
    }
}

// 0x7101699de0
common::Unk_165bb20_result LocalEjectClientListCheckJob::WaitBackgroundJobEnd() {
    if (!m_BackgroundJob->Unk_1655a80()) {
        SetStep(&LocalEjectClientListCheckJob::CheckTargetList, "LocalEjectClientListCheckJob::CheckTargetList");
    }
    return {5};
}

}  // namespace local
}  // namespace pia
}  // namespace nn
