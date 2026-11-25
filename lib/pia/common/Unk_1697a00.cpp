// Scope: common
// local::LocalEventJob's steps, and local::LocalConnectNetworkJob
// (lib/pia/common/Unk_1697a00.h). Their vf5 are in
// lib/nx_middleware/class/nn_pia_local_Local*Job.cpp, and
// LocalConnectNetworkJob::WaitForCancel (0x71016980a0) in
// lib/nx_middleware/leaf/Unk_168ab60.cpp, under a leaf's placeholder name.
#include "pia/common/Unk_1697a00.h"

#include "pia/common/Unk_17162d0.h"

namespace nn {
namespace pia {
namespace local {

using common::Unk_165bb20_result;

// 0x7101697a00
Unk_165e060 LocalEventJob::Unk_1697a00() {
    SetStep(&LocalEventJob::WatchUpdateEvent, "LocalEventJob::WatchUpdateEvent");
    return Unk_165e060Value<0>();
}

// 0x7101697a70
Unk_165bb20_result LocalEventJob::WatchUpdateEvent() {
    if ((m_Protocol->Unk_1692ea0() || m_Protocol->field_418 != 0) && !m_Protocol->vf55() &&
        !Unk_1693c90(m_Protocol)) {
        return {5};
    }
    m_Job->Unk_1688b10(&m_Context);
    m_Job->Unk_1655850(true);
    SetStep(&LocalEventJob::WaitConnectionStatusUpdated, "LocalEventJob::WaitConnectionStatusUpdated");
    return {5};
}

// 0x7101697b10
void LocalEventJob::Unk_1697b10() {
    if (m_Job != nullptr) {
        m_Job->Cancel(2);
        m_Job->Unk_1688c40();
    }
}

// 0x7101697b60
Unk_165bb20_result LocalEventJob::WaitConnectionStatusUpdated() {
    switch (m_Context.m_State) {
    case 1:
        return {5};
    case 2:
        SetStep(&LocalEventJob::ProcessUpdateEvent, "LocalEventJob::ProcessUpdateEvent");
        return {0};
    case 3:
        SetStep(&LocalEventJob::WaitBackgroundJobEnd, "LocalEventJob::WaitBackgroundJobEnd");
        return {0};
    case 4:
        return {1};
    }
    return {1};
}

// 0x7101697be0
Unk_165bb20_result LocalEventJob::ProcessUpdateEvent() {
    m_Protocol->vf49();
    m_Protocol->Unk_1692fb0();
    SetStep(&LocalEventJob::WaitBackgroundJobEnd, "LocalEventJob::WaitBackgroundJobEnd");
    return {0};
}

// 0x7101697c30
Unk_165bb20_result LocalEventJob::WaitBackgroundJobEnd() {
    if (m_Job->Unk_1655a80()) {
        return {5};
    }
    Unk_1693c80(m_Protocol, false);
    SetStep(&LocalEventJob::WatchUpdateEvent, "LocalEventJob::WatchUpdateEvent");
    return {5};
}

// 0x7101697c90
LocalConnectNetworkJob::LocalConnectNetworkJob(LocalProtocol* protocol)
    : m_Context(nullptr), m_Protocol(protocol) {
    m_JobContext = new (Unk_1652bd0()) Unk_1655080();
}

// 0x7101697cf0 (and 0x7101697d40, deleting)
LocalConnectNetworkJob::~LocalConnectNetworkJob() {
    Unk_1655080* context = m_JobContext;
    if (context != nullptr) {
        Unk_1655170_update(reinterpret_cast<u64>(context));
        Unk_1716390(context);
    }
    m_Protocol = nullptr;
}

// 0x7101697da0
Unk_165e060 LocalConnectNetworkJob::Unk_1697da0(Unk_1655080* context, const Unk_1697da0_arg2* arg) {
    const Unk_1695fb0_result* found = m_Protocol->Unk_1695fb0(arg->field_0);
    if (found->field_8 >= 6) {
        return Unk_165e060Value<0x641e>();
    }
    if (found->field_8 != 5) {
        return Unk_165e060Value<0x641f>();
    }
    if (found->field_4 != arg->field_8) {
        return Unk_165e060Value<0x6c51>();
    }
    Unk_165e060 result = m_Protocol->field_400->vf8(m_JobContext, arg);
    if (result.m_Value != 0) {
        return result;
    }
    m_Context = context;
    m_Context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    m_Protocol->field_400->Unk_1655850(true);
    LocalProtocol* protocol = m_Protocol;
    protocol->field_47d = 0;
    protocol->field_569 = 1;
    SetStep(&LocalConnectNetworkJob::WaitConnectNetwork, "LocalConnectNetworkJob::WaitConnectNetwork");
    return Unk_165e060Value<0>();
}

// 0x7101697ef0
Unk_165bb20_result LocalConnectNetworkJob::WaitConnectNetwork() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        SetStep(&LocalConnectNetworkJob::WaitForCancel, "LocalConnectNetworkJob::WaitForCancel");
        return {0};
    }
    switch (m_JobContext->m_State) {
    case 1:
        return {5};
    case 2:
        if (m_Protocol->field_400->Unk_16559c0()) {
            return {5};
        }
        SetStep(&LocalConnectNetworkJob::ProcessSucceeded, "LocalConnectNetworkJob::ProcessSucceeded");
        return {0};
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

// 0x7101698010
void LocalConnectNetworkJob::Unk_1698010() {
    Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x6c05>());
        }
        m_Context = nullptr;
    }
}

// 0x71016980f0
Unk_165bb20_result LocalConnectNetworkJob::ProcessSucceeded() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        SetStep(&LocalConnectNetworkJob::WaitForCancel, "LocalConnectNetworkJob::WaitForCancel");
        return {0};
    }
    m_Context->Unk_16551b0(Unk_165e060Value<0>());
    m_Context = nullptr;
    return {1};
}

}  // namespace local
}  // namespace pia
}  // namespace nn
