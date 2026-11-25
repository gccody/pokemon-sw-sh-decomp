// Scope: common
// lan::LanMatchJointSessionJob's steps from WaitLeavePreviousMesh to
// ProcessComplete (lib/pia/common/Unk_16695b0.h).
#include "pia/common/Unk_16695b0.h"

namespace nn {
namespace pia {
namespace lan {

// 0x7101669da0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitLeavePreviousMesh() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::StartLeavePreviousMatchmakeSession, "LanMatchJointSessionJob::StartLeavePreviousMatchmakeSession");
    return {0};
}

// 0x7101669e60
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartLeavePreviousMatchmakeSession() {
    SetStep(&LanMatchJointSessionJob::WaitLeavePreviousMatchmakeSession, "LanMatchJointSessionJob::WaitLeavePreviousMatchmakeSession");
    return {0};
}

// 0x7101669e80
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitLeavePreviousMatchmakeSession() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::MeshRestart, "LanMatchJointSessionJob::MeshRestart");
    return {0};
}

// 0x7101669f40
LanMatchJointSessionJob::Result LanMatchJointSessionJob::MeshRestart() {
    if (field_f5) {
        SetStep(&LanMatchJointSessionJob::StartCreateNextMesh, "LanMatchJointSessionJob::StartCreateNextMesh");
    } else {
        SetStep(&LanMatchJointSessionJob::StartGetNextMeshHostStationLocation,
                "LanMatchJointSessionJob::StartGetNextMeshHostStationLocation");
    }
    return {0};
}

// 0x7101669f80
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartCreateNextMesh() {
    SetStep(&LanMatchJointSessionJob::WaitCreateNextMesh, "LanMatchJointSessionJob::WaitCreateNextMesh");
    return {5};
}

// 0x7101669fa0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartGetNextMeshHostStationLocation() {
    SetStep(&LanMatchJointSessionJob::WaitGetNextMeshHostStationLocation, "LanMatchJointSessionJob::WaitGetNextMeshHostStationLocation");
    return {0};
}

// 0x7101669fc0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitCreateNextMesh() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitCompanionStation, "LanMatchJointSessionJob::WaitCompanionStation");
    return {0};
}

// 0x710166a080
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitCompanionStation() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitHostStationId, "LanMatchJointSessionJob::WaitHostStationId");
    return {0};
}

// 0x710166a140
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitGetNextMeshHostStationLocation() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::StartJoinNextMesh, "LanMatchJointSessionJob::StartJoinNextMesh");
    return {0};
}

// 0x710166a200
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartJoinNextMesh() {
    SetStep(&LanMatchJointSessionJob::WaitJoinNextMesh, "LanMatchJointSessionJob::WaitJoinNextMesh");
    return {0};
}

// 0x710166a220
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitJoinNextMesh() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitCompanionStation, "LanMatchJointSessionJob::WaitCompanionStation");
    return {0};
}

// 0x710166a2e0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitHostStationId() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::ProcessComplete, "LanMatchJointSessionJob::ProcessComplete");
    return {0};
}

// 0x710166a3a0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::ProcessComplete() {
    Unk_17255e0(this);
    Unk_27fc0a8->field_15d = false;
    if (m_Context != nullptr) {
        m_Context->Unk_16551b0(Unk_165e060Value<0>());
        m_Context = nullptr;
    }
    return {1};
}

}  // namespace lan
}  // namespace pia
}  // namespace nn
