// Scope: common
// lan::LanMatchJointSessionJob's steps from StartJoinMatchmakeSession to
// WaitUntilLeaderLeavesMesh (lib/pia/common/Unk_16695b0.h).
#include "pia/common/Unk_16695b0.h"

namespace nn {
namespace pia {
namespace lan {

// 0x71016695b0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartJoinMatchmakeSession() {
    SetStep(&LanMatchJointSessionJob::WaitJoinMatchmakeSession, "LanMatchJointSessionJob::WaitJoinMatchmakeSession");
    return {0};
}

// 0x71016695d0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartRandomMatchmake() {
    SetStep(&LanMatchJointSessionJob::WaitRandomMatchmake, "LanMatchJointSessionJob::WaitRandomMatchmake");
    return {5};
}

// 0x71016695f0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::SendInvitationAsCompanion() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitForAnswerToInvitation, "LanMatchJointSessionJob::WaitForAnswerToInvitation");
    return {0};
}

// 0x71016696b0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::SendAnswerToInvitation() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitNextSessionId, "LanMatchJointSessionJob::WaitNextSessionId");
    return {5};
}

// 0x7101669770
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitForAnswerToInvitation() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    return {0};
}

// 0x7101669820
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitRandomMatchmake() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::SendNextSessionId, "LanMatchJointSessionJob::SendNextSessionId");
    return {0};
}

// 0x71016698e0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::SendNextSessionId() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitCompanionStationPrepared, "LanMatchJointSessionJob::WaitCompanionStationPrepared");
    return {0};
}

// 0x71016699a0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitJoinMatchmakeSession() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::SendNextSessionId, "LanMatchJointSessionJob::SendNextSessionId");
    return {0};
}

// 0x7101669a60
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitCompanionStationPrepared() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::StartLeavePreviousMesh, "LanMatchJointSessionJob::StartLeavePreviousMesh");
    return {0};
}

// 0x7101669b20
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartLeavePreviousMesh() {
    SetStep(&LanMatchJointSessionJob::WaitLeavePreviousMesh, "LanMatchJointSessionJob::WaitLeavePreviousMesh");
    return {5};
}

// 0x7101669b40
LanMatchJointSessionJob::Result LanMatchJointSessionJob::StartUpdateSessionKey() {
    SetStep(&LanMatchJointSessionJob::WaitUpdateSessionKey, "LanMatchJointSessionJob::WaitUpdateSessionKey");
    return {5};
}

// 0x7101669b60
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitUpdateSessionKey() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::SendPreparedForMigrateSession, "LanMatchJointSessionJob::SendPreparedForMigrateSession");
    return {0};
}

// 0x7101669c20
LanMatchJointSessionJob::Result LanMatchJointSessionJob::SendPreparedForMigrateSession() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::WaitUntilLeaderLeavesMesh, "LanMatchJointSessionJob::WaitUntilLeaderLeavesMesh");
    return {0};
}

// 0x7101669ce0
LanMatchJointSessionJob::Result LanMatchJointSessionJob::WaitUntilLeaderLeavesMesh() {
    if (Unk_172be20(Unk_27fc0a8) == 5) {
        Unk_17259c0(this);
        if (m_Context != nullptr) {
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());
            m_Context = nullptr;
        }
        return {1};
    }
    SetStep(&LanMatchJointSessionJob::StartLeavePreviousMesh, "LanMatchJointSessionJob::StartLeavePreviousMesh");
    return {0};
}

}  // namespace lan
}  // namespace pia
}  // namespace nn
