// Scope: common
// local::LocalMatchDestroySessionJob's steps and local::LocalMatchBrowseMatchmakeJob's
// constructor, destructors and first steps (lib/pia/common/Unk_168f910.h).
#include "pia/common/Unk_168f910.h"

namespace nn {
namespace pia {
namespace local {

// 0x710168f970
common::Unk_165bb20_result LocalMatchDestroySessionJob::DestroyLocalNetwork() {
    Unk_27fc0a8_type* session = Unk_27fc0a8;
    u8 index = session->field_162;
    Unk_165e060 result = session->field_168[index]->vf14(&field_60, session->field_180[index]);
    if (result.m_Value == 0) {
        SetStep(&LocalMatchDestroySessionJob::WaitDestroyLocalNetwork,
                "LocalMatchDestroySessionJob::WaitDestroyLocalNetwork");
        return {5};
    }
    SetStep(&LocalMatchDestroySessionJob::SendMonitoringData, "LocalMatchDestroySessionJob::SendMonitoringData");
    return {0};
}

// 0x710168fa10
common::Unk_165bb20_result LocalMatchDestroySessionJob::WaitDestroyLocalNetwork() {
    Unk_27fc0a8_type* session = Unk_27fc0a8;
    if (!session->field_168[session->field_162]->vf15()) {
        return {5};
    }
    Unk_172e100(Unk_27fc0a8, 0);
    if (field_60.m_State == 3) {
        SetStep(&LocalMatchDestroySessionJob::SendMonitoringData, "LocalMatchDestroySessionJob::SendMonitoringData");
        return {0};
    }
    if (field_60.m_State == 2) {
        SetStep(&LocalMatchDestroySessionJob::SendMonitoringData, "LocalMatchDestroySessionJob::SendMonitoringData");
        return {0};
    }
    return {5};
}

// 0x710168fab0
void LocalMatchDestroySessionJob::vf8() {
    SetStep(&Unk_245f368::MeshCleanup, "DestroySessionJob::MeshCleanup");
}

// 0x710168fad0
void LocalMatchDestroySessionJob::vf9() {
    SetStep(&LocalMatchDestroySessionJob::DestroyLocalNetwork, "LocalMatchDestroySessionJob::DestroyLocalNetwork");
}

// 0x710168faf0
void LocalMatchDestroySessionJob::vf6() {
    Unk_245f368::vf6();
}

// 0x710168fb10
LocalMatchBrowseMatchmakeJob::LocalMatchBrowseMatchmakeJob(void* owner) : m_Owner(owner) {}

// 0x710168fb50 (and 0x710168fb90, deleting)
LocalMatchBrowseMatchmakeJob::~LocalMatchBrowseMatchmakeJob() {
    m_Owner = nullptr;
    Unk_1655170_update(reinterpret_cast<u64>(&m_BrowseContext));
}

// 0x710168fbe0
Unk_165e060 LocalMatchBrowseMatchmakeJob::vf7(Unk_168fbe0_arg1* matchmake, void* arg) {
    m_Matchmake = matchmake;
    matchmake->vf45(arg);
    SetStep(&LocalMatchBrowseMatchmakeJob::BrowseMatchmake, "LocalMatchBrowseMatchmakeJob::BrowseMatchmake");
    return Unk_165e060Value<0>();
}

// 0x710168fc70
common::Unk_165bb20_result LocalMatchBrowseMatchmakeJob::BrowseMatchmake() {
    if (m_Context->m_State == 4) {
        vf6();
        return {1};
    }
    Unk_165e060 result = m_Matchmake->vf5(&m_BrowseContext);
    if (result.m_Value != 0) {
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(result);
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LocalMatchBrowseMatchmakeJob::WaitBrowseMatchmake, "LocalMatchBrowseMatchmakeJob::WaitBrowseMatchmake");
    return {0};
}

// 0x710168fd50
common::Unk_165bb20_result LocalMatchBrowseMatchmakeJob::WaitBrowseMatchmake() {
    LOCAL_MATCH_FAIL_ON_SESSION_STATE();
    if (m_Context->m_State == 4) {
        vf6();
        return {1};
    }
    if (!m_Matchmake->vf6()) {
        return {5};
    }
    if (m_BrowseContext.m_State == 3) {
        m_Context->Unk_1655220(m_BrowseContext.m_Result);
        m_Context = nullptr;
        return {1};
    }
    if (m_BrowseContext.m_State == 2) {
        SetStep(&Unk_245f0a8::CompleteProcess, "session::BrowseMatchmakeJob::CompleteProcess");
        return {0};
    }
    return {5};
}

// 0x710168ff50
Unk_165e060 LocalMatchBrowseMatchmakeJob::vf8(Unk_168fbe0_arg1* matchmake) {
    m_Matchmake = matchmake;
    SetStep(&LocalMatchBrowseMatchmakeJob::WaitHostMigration, "LocalMatchBrowseMatchmakeJob::WaitHostMigration");
    return Unk_165e060Value<0>();
}

// 0x710168ffc0
common::Unk_165bb20_result LocalMatchBrowseMatchmakeJob::WaitHostMigration() {
    LOCAL_MATCH_FAIL_ON_SESSION_STATE();
    if (Unk_16898a0_check(static_cast<const Unk_16898a0*>(m_Owner))) {
        return {5};
    }
    SetStep(&LocalMatchBrowseMatchmakeJob::UpdateCurrentConnectionStatus,
            "LocalMatchBrowseMatchmakeJob::UpdateCurrentConnectionStatus");
    return {0};
}

}  // namespace local
}  // namespace pia
}  // namespace nn
