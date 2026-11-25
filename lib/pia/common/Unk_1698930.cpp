// Scope: common
// local::LocalDestroyNetworkJob's WaitDestroyNetwork, local::LocalDisconnectNetworkJob,
// and local::LocalAllowParticipatingJob's constructor and destructors
// (lib/pia/common/Unk_1698930.h). LocalAllowParticipatingJob's steps and its
// background job are in lib/pia/common/Unk_1699080.cpp.
#include "pia/common/Unk_1698930.h"

#include "pia/common/Unk_17162d0.h"

namespace nn {
namespace pia {
namespace local {

using common::Unk_165bb20_result;

// 0x7101698930
Unk_165bb20_result LocalDestroyNetworkJob::WaitDestroyNetwork() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        SetStep(&LocalDestroyNetworkJob::WaitForCancel, "LocalDestroyNetworkJob::WaitForCancel");
        return {0};
    }
    switch (m_JobContext->m_State) {
    case 1:
        return {5};
    case 2:
        m_Context->Unk_16551b0(m_JobContext->m_Result);
        m_Context = nullptr;
        m_Protocol->Unk_1692780();
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        return {1};
    case 3:
        m_Context->Unk_1655220(m_JobContext->m_Result);
        m_Context = nullptr;
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        return {1};
    case 4:
        m_Context->Unk_1655220(m_JobContext->m_Result);
        m_Context = nullptr;
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        return {1};
    default:
        return {1};
    }
}

// 0x7101698a60
LocalDisconnectNetworkJob::LocalDisconnectNetworkJob(LocalProtocol* protocol)
    : m_Context(nullptr), m_Protocol(protocol) {
    m_JobContext = new (Unk_1652bd0()) Unk_1655080();
}

// 0x7101698ac0 (and 0x7101698b10, deleting)
LocalDisconnectNetworkJob::~LocalDisconnectNetworkJob() {
    Unk_1655080* context = m_JobContext;
    if (context != nullptr) {
        Unk_1655170_update(reinterpret_cast<u64>(context));
        Unk_1716390(context);
    }
    m_Protocol = nullptr;
}

// 0x7101698b70
Unk_165e060 LocalDisconnectNetworkJob::Unk_1698b70(Unk_1655080* context) {
    if (m_Protocol->field_474 != 2) {
        return Unk_165e060Value<0x10c08>();
    }
    m_Context = context;
    m_Context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    SetStep(&LocalDisconnectNetworkJob::TryPrepareDisconnectNetwork,
            "LocalDisconnectNetworkJob::TryPrepareDisconnectNetwork");
    return Unk_165e060Value<0>();
}

// 0x7101698c20
Unk_165bb20_result LocalDisconnectNetworkJob::TryPrepareDisconnectNetwork() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        SetStep(&LocalDisconnectNetworkJob::WaitForCancel, "LocalDisconnectNetworkJob::WaitForCancel");
        return {0};
    }
    Unk_165e060 result = m_Protocol->field_400->Unk_16877d0();
    if (result.m_Value != 0) {
        return {5};
    }
    result = m_Protocol->field_400->Unk_1687880(m_JobContext);
    if (result.m_Value != 0) {
        m_Context->Unk_1655220(m_JobContext->m_Result);
        m_Context = nullptr;
        return {1};
    }
    m_Protocol->field_400->Unk_1655850(true);
    SetStep(&LocalDisconnectNetworkJob::WaitDisconnectNetwork, "LocalDisconnectNetworkJob::WaitDisconnectNetwork");
    return {0};
}

// 0x7101698d30
void LocalDisconnectNetworkJob::Unk_1698d30() {
    Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x6c05>());
        }
        m_Context = nullptr;
    }
}

// 0x7101698e10
Unk_165bb20_result LocalDisconnectNetworkJob::WaitDisconnectNetwork() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        SetStep(&LocalDisconnectNetworkJob::WaitForCancel, "LocalDisconnectNetworkJob::WaitForCancel");
        return {0};
    }
    switch (m_JobContext->m_State) {
    case 1:
        return {5};
    case 2:
        m_Context->Unk_16551b0(m_JobContext->m_Result);
        m_Context = nullptr;
        m_Protocol->Unk_1692780();
        return {1};
    case 3:
        m_Context->Unk_1655220(m_JobContext->m_Result);
        m_Context = nullptr;
        return {1};
    case 4:
        m_Context->Unk_1655220(m_JobContext->m_Result);
        m_Context = nullptr;
        return {1};
    default:
        return {1};
    }
}

// 0x7101698f10
LocalAllowParticipatingJob::LocalAllowParticipatingJob(LocalProtocol* protocol)
    : m_Context(nullptr), field_98(0), m_Result(0), m_Protocol(protocol) {
    m_Job = new (Unk_1652bd0()) LocalAllowParticipatingBackgroundJob(protocol);
}

// 0x7101698fb0 (and 0x7101699010, deleting)
LocalAllowParticipatingJob::~LocalAllowParticipatingJob() {
    LocalAllowParticipatingBackgroundJob* job = m_Job;
    if (job != nullptr) {
        job->~LocalAllowParticipatingBackgroundJob();
        Unk_1716390(job);
        m_Job = nullptr;
    }
    m_Protocol = nullptr;
    Unk_1655170_update(reinterpret_cast<u64>(&m_JobContext));
}

}  // namespace local
}  // namespace pia
}  // namespace nn
