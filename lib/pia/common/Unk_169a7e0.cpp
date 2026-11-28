// Scope: common
// local::LocalResendMessageJob's last member, local::LocalScanNetworkJob,
// and local::LocalSessionInfo's constructor and destructors
// (lib/pia/common/Unk_169a7e0.h).
#include "pia/common/Unk_169a7e0.h"

#include "pia/common/Unk_17162d0.h"

namespace nn {
namespace pia {
namespace local {

using common::Unk_165bb20_result;

// 0x710169a7e0
void LocalResendMessageJob::Unk_169a7e0(u32 station) {
    m_Stations &= ~(1 << station);
}

// 0x710169a810: data/functions.csv still has the placeholder _ZN11Unk_245b408C2Ev
// for it (no parameter; LdnScanNetworkJob's constructor, Unk_24598a8 in
// src/unsorted/ctor/Unk_1685a70.cpp, calls it so). It takes the protocol: it
// matches under this name.
LocalScanNetworkJob::LocalScanNetworkJob(LocalProtocol* protocol) : m_Context(nullptr), m_Protocol(protocol) {
    m_JobContext = new (Unk_1652bd0()) Unk_1655080();
}

// 0x710169a870 (and 0x710169a8c0, deleting)
LocalScanNetworkJob::~LocalScanNetworkJob() {
    Unk_1655080* context = m_JobContext;
    if (context != nullptr) {
        Unk_1655170_update(reinterpret_cast<u64>(context));
        Unk_1716390(context);
    }
    m_Protocol = nullptr;
}

// 0x710169a920
Unk_165e060 LocalScanNetworkJob::vf6(Unk_1655080* context) {
    Unk_165e060 result = m_Protocol->field_400->vf7(m_JobContext);
    if (result.m_Value != 0) {
        return result;
    }
    m_Context = context;
    m_Context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    m_Protocol->field_400->Unk_1655850(true);
    m_Protocol->field_47d = 0;
    SetStep(&LocalScanNetworkJob::WaitScanNetwork, "LocalScanNetworkJob::WaitScanNetwork");
    return Unk_165e060Value<0>();
}

// 0x710169a9f0
Unk_165bb20_result LocalScanNetworkJob::WaitScanNetwork() {
    Unk_1655080* context = m_Context;
    Unk_1655080* job = m_JobContext;
    if (context->field_28) {
        if (job->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(job));
        }
        SetStep(&LocalScanNetworkJob::WaitForCancel, "LocalScanNetworkJob::WaitForCancel");
        return {0};
    }
    switch (job->m_State) {
    case 1:
        return {5};
    case 2:
        m_Protocol->field_47d = 1;
        context->Unk_16551b0(job->m_Result);
        m_Context = nullptr;
        return {1};
    case 3:
        context->Unk_1655220(job->m_Result);
        m_Context = nullptr;
        return {1};
    case 4:
        context->Unk_1655220(job->m_Result);
        m_Context = nullptr;
        return {1};
    default:
        return {1};
    }
}

// 0x710169aae0
void LocalScanNetworkJob::Unk_169aae0() {
    Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x2c18>());
        }
        m_Context = nullptr;
    }
}

// 0x710169ab70
Unk_165bb20_result LocalScanNetworkJob::WaitForCancel() {
    switch (m_JobContext->m_State) {
    case 2:
    case 3:
    case 4:
        m_Context->Unk_1655220(Unk_165e060Value<0x2c18>());
        m_Context = nullptr;
        return {1};
    default:
        return {5};
    }
}

// 0x710169ac20
LocalSessionInfo::LocalSessionInfo() : field_8(0), field_9(0), field_a(0) {}

// 0x710169ac40 (and 0x710169ac50, deleting: a trap, the class is abstract)
LocalSessionInfo::~LocalSessionInfo() {}

}  // namespace local
}  // namespace pia
}  // namespace nn
