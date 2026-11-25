// Scope: common
// local::LocalMatchJoinSessionJob's steps, local::LocalMatchLeaveSessionJob's
// constructor and destructors, and local::LocalMatchCreateSessionJob
// (lib/pia/common/Unk_168ef00.h).
#include "pia/common/Unk_168ef00.h"

namespace nn {
namespace pia {
namespace local {

// 0x710168ef00
common::Unk_165bb20_result LocalMatchJoinSessionJob::LeaveMatchmakeSession() {
    Unk_27fc0a8_type* session = Unk_27fc0a8;
    u8 index = session->field_162;
    Unk_165e060 result = session->field_168[index]->vf12(&field_60, field_114);
    if (result.m_Value == 0) {
        SetStep(&LocalMatchJoinSessionJob::WaitLeaveMatchmake, "LocalMatchJoinSessionJob::WaitLeaveMatchmake");
        return {5};
    }
    SetStep(&LocalMatchJoinSessionJob::CompleteFailure, "LocalMatchJoinSessionJob::CompleteFailure");
    return {0};
}

// 0x710168efa0
common::Unk_165bb20_result LocalMatchJoinSessionJob::WaitLeaveMatchmake() {
    Unk_27fc0a8_type* session = Unk_27fc0a8;
    if (!session->field_168[session->field_162]->vf13()) {
        return {5};
    }
    field_60.Unk_1655110();
    SetStep(&LocalMatchJoinSessionJob::CompleteFailure, "LocalMatchJoinSessionJob::CompleteFailure");
    return {0};
}

// 0x710168f020
void LocalMatchJoinSessionJob::vf14() {
    m_Network->vf46();
    SetStep(&Unk_245f3e8::CompleteProcess, "JoinSessionJob::CompleteProcess");
}

// 0x710168f070
common::Unk_165bb20_result LocalMatchJoinSessionJob::vf15(const Unk_165e060& result) {
    field_120 = result;
    SetStep(&LocalMatchJoinSessionJob::MeshCleanup, "LocalMatchJoinSessionJob::MeshCleanup");
    return {0};
}

// 0x710168f0b0
common::Unk_165bb20_result LocalMatchJoinSessionJob::vf16() {
    SetStep(&LocalMatchJoinSessionJob::MeshCleanup, "LocalMatchJoinSessionJob::MeshCleanup");
    return {0};
}

// 0x710168f0d0
common::Unk_165bb20_result LocalMatchJoinSessionJob::vf17() {
    SetStep(&LocalMatchJoinSessionJob::LeaveMatchmakeSession, "LocalMatchJoinSessionJob::LeaveMatchmakeSession");
    return {0};
}

// 0x710168f110
LocalMatchLeaveSessionJob::LocalMatchLeaveSessionJob(void* owner) : m_Owner(owner) {}

// 0x710168f150 (and 0x710168f170, deleting)
LocalMatchLeaveSessionJob::~LocalMatchLeaveSessionJob() {
    m_Owner = nullptr;
}

// 0x710168f1e0
LocalMatchCreateSessionJob::LocalMatchCreateSessionJob(Unk_168f1e0_arg1* owner)
    : m_Network(nullptr), m_Owner(owner), m_Result(Unk_165e060Value<0>()) {}

// 0x710168f260 (and 0x710168f280, deleting)
LocalMatchCreateSessionJob::~LocalMatchCreateSessionJob() {
    m_Owner = nullptr;
}

// 0x710168f2c0
Unk_165e060 LocalMatchCreateSessionJob::vf7(const Unk_1723380* setting) {
    m_Network = Unk_27fc0a8->field_168[Unk_27fc0a8->field_162];
    m_Network->vf40();
    u16 id = Unk_1723380_get(setting);
    Unk_172e150(Unk_27fc0a8, id);
    SetStep(&LocalMatchCreateSessionJob::CreateLocalNetwork, "LocalMatchCreateSessionJob::CreateLocalNetwork");
    return Unk_165e060Value<0>();
}

// 0x710168f380
common::Unk_165bb20_result LocalMatchCreateSessionJob::CreateLocalNetwork() {
    if (m_Context != nullptr && m_Context->field_28) {
        vf6();
        return {1};
    }
    Unk_165e060 result = m_Network->vf8(&field_60);
    if (result.m_Value != 0) {
        m_Context->Unk_1655220(result);
        m_Context = nullptr;
        return {1};
    }
    SetStep(&LocalMatchCreateSessionJob::WaitCreateLocalNetwork, "LocalMatchCreateSessionJob::WaitCreateLocalNetwork");
    return {5};
}

// 0x710168f450
common::Unk_165bb20_result LocalMatchCreateSessionJob::WaitCreateLocalNetwork() {
    if (m_Context != nullptr && m_Context->field_28) {
        vf6();
        return {1};
    }
    u32 value = 0;
    if (!m_Network->vf9(&value)) {
        return {5};
    }
    if (field_60.m_State == 3) {
        m_Context->Unk_1655220(field_60.m_Result);
        m_Context = nullptr;
        return {1};
    }
    if (field_60.m_State == 2) {
        Unk_172e100(Unk_27fc0a8, value);
        Unk_172e0d0(Unk_27fc0a8, 1);
        Unk_17231d0(1);
        SetStep(&LocalMatchCreateSessionJob::StartLocalSession, "LocalMatchCreateSessionJob::StartLocalSession");
        return {0};
    }
    return {5};
}

// 0x710168f580
common::Unk_165bb20_result LocalMatchCreateSessionJob::StartLocalSession() {
    Unk_168f1e0_arg1* owner = m_Owner;
    if (!owner->Unk_1689af0() && !owner->Unk_1689b10()) {
        m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
        m_Context = nullptr;
        return {1};
    }
    Unk_165e060 result = m_Owner->Unk_168a020();
    if (result.m_Value != 0) {
        m_Context->Unk_1655220(result);
        m_Context = nullptr;
        return {1};
    }
    SetStep(&Unk_245f278::MeshStartup, "CreateSessionJob::MeshStartup");
    return {0};
}

// 0x710168f660
common::Unk_165bb20_result LocalMatchCreateSessionJob::StopLocalSession() {
    m_Owner->Unk_168a370();
    SetStep(&LocalMatchCreateSessionJob::DestroyLocalNetwork, "LocalMatchCreateSessionJob::DestroyLocalNetwork");
    return {0};
}

// 0x710168f6a0
common::Unk_165bb20_result LocalMatchCreateSessionJob::DestroyLocalNetwork() {
    Unk_165e060 result = m_Network->vf14(&field_60, 0);
    if (result.m_Value == 0) {
        SetStep(&LocalMatchCreateSessionJob::WaitDestroyLocalNetwork,
                "LocalMatchCreateSessionJob::WaitDestroyLocalNetwork");
        return {5};
    }
    SetStep(&LocalMatchCreateSessionJob::CompleteFailure, "LocalMatchCreateSessionJob::CompleteFailure");
    return {0};
}

// 0x710168f720
common::Unk_165bb20_result LocalMatchCreateSessionJob::CompleteFailure() {
    m_Context->Unk_1655220(m_Result);
    m_Context = nullptr;
    return {1};
}

// 0x710168f770
common::Unk_165bb20_result LocalMatchCreateSessionJob::WaitDestroyLocalNetwork() {
    if (!m_Network->vf15()) {
        return {5};
    }
    if (field_60.m_State == 3) {
        SetStep(&LocalMatchCreateSessionJob::CompleteFailure, "LocalMatchCreateSessionJob::CompleteFailure");
        return {0};
    }
    if (field_60.m_State == 2) {
        SetStep(&LocalMatchCreateSessionJob::CompleteFailure, "LocalMatchCreateSessionJob::CompleteFailure");
        return {0};
    }
    return {5};
}

// 0x710168f7f0
void LocalMatchCreateSessionJob::vf8() {
    m_Network->vf46();
    SetStep(&Unk_245f278::CompleteProcess, "CreateSessionJob::CompleteProcess");
}

// 0x710168f840
common::Unk_165bb20_result LocalMatchCreateSessionJob::vf9(const Unk_165e060& result) {
    m_Result = result;
    SetStep(&LocalMatchCreateSessionJob::StopLocalSession, "LocalMatchCreateSessionJob::StopLocalSession");
    return {0};
}

// 0x710168f880
void LocalMatchCreateSessionJob::vf6() {
    Unk_245f278::vf6();
}

}  // namespace local
}  // namespace pia
}  // namespace nn
