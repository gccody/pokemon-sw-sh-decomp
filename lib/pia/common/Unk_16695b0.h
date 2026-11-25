#pragma once
// lan::LanMatchJointSessionJob (RTTI N2nn3pia3lan23LanMatchJointSessionJobE),
// a common::StepSequenceJob (lib/pia/common/Unk_16998e0.h). Its small virtual
// functions are in lib/nx_middleware/class and lib/pia/gen. Its steps are
// named after the strings stored with them ("LanMatchJointSessionJob::<step>");
// 0x71016695b0-0x710166a3a0 are in Unk_16695b0.cpp and Unk_1669da0.cpp
// (WaitNextSessionId, 0x71016694f0, isn't decompiled yet). Most of them first check whether the session is gone
// (Unk_172be20 is 5) and then fail the job's context with 0xc406; that check is
// written out in each (clang keeps a shared inline helper out of line). Other
// names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_16998e0.h"

// The object behind the global Unk_27fc0a8 (as lib/pia/common/Unk_1734ed0.h's
// Unk_172c3e0_arg0; placeholder, only what the steps touch).
struct Unk_172be20_arg0 {
    u8 _0[0x15d];
    bool field_15d;
};
PKMN_OFFSET_ASSERT(Unk_172be20_arg0, field_15d, 0x15d);

extern Unk_172be20_arg0* Unk_27fc0a8;

s32 Unk_172be20(void* self);  // its state (5: the session is gone)
void Unk_17259c0(void* job);
void Unk_17255e0(void* job);

namespace nn {
namespace pia {
namespace lan {

class LanMatchJointSessionJob : public common::StepSequenceJob {
public:
    typedef common::Unk_165bb20_result Result;

    Result StartJoinMatchmakeSession();
    Result StartRandomMatchmake();
    Result SendInvitationAsCompanion();
    Result SendAnswerToInvitation();
    Result WaitNextSessionId();
    Result WaitForAnswerToInvitation();
    Result WaitRandomMatchmake();
    Result SendNextSessionId();
    Result WaitJoinMatchmakeSession();
    Result WaitCompanionStationPrepared();
    Result StartLeavePreviousMesh();
    Result StartUpdateSessionKey();
    Result WaitUpdateSessionKey();
    Result SendPreparedForMigrateSession();
    Result WaitUntilLeaderLeavesMesh();
    Result WaitLeavePreviousMesh();
    Result StartLeavePreviousMatchmakeSession();
    Result WaitLeavePreviousMatchmakeSession();
    Result MeshRestart();
    Result StartCreateNextMesh();
    Result StartGetNextMeshHostStationLocation();
    Result WaitCreateNextMesh();
    Result WaitCompanionStation();
    Result WaitGetNextMeshHostStationLocation();
    Result StartJoinNextMesh();
    Result WaitJoinNextMesh();
    Result WaitHostStationId();
    Result ProcessComplete();

    Unk_1655080* m_Context;
    u8 _60[0xf4 - 0x60];
    bool field_f4;  // picks SendInvitationAsCompanion over SendAnswerToInvitation
    bool field_f5;  // picks StartCreateNextMesh over StartGetNextMeshHostStationLocation
};
PKMN_OFFSET_ASSERT(LanMatchJointSessionJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LanMatchJointSessionJob, field_f4, 0xf4);
PKMN_OFFSET_ASSERT(LanMatchJointSessionJob, field_f5, 0xf5);

}  // namespace lan
}  // namespace pia
}  // namespace nn
