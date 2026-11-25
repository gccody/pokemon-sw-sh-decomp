// Scope: common
// session::CloseParticipationJob's last step, and the constructors,
// destructors and resets of session::CommunityManagementJob,
// ClearMatchmakeSystemPasswordJob and GenerateMatchmakeSystemPasswordJob
// (lib/pia/common/Unk_1730630.h).
#include "pia/common/Unk_1730630.h"

using nn::pia::Unk_165e060Value;
using nn::pia::common::Unk_165bb20_result;

// Inline: the milliseconds since a tick.
static inline s64 MillisecondsSince(const Unk_165c600& start) {
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    return (static_cast<s64>(now.field_0) - static_cast<s64>(start.field_0)) / *Unk_165c6b0();
}

namespace nn {
namespace pia {
namespace session {

// 0x7101730e60
Unk_165bb20_result CloseParticipationJob::WaitP2pStable() {
    switch (Unk_172be20(Unk_27fc0a8)) {
    case 5:
        field_58->Unk_1655220(Unk_165e060Value<0xc406>());
        field_58 = nullptr;
        return {1};
    case 6:
        field_58->Unk_1655220(Unk_165e060Value<0xa471>());
        field_58 = nullptr;
        return {1};
    case 7:
        field_58->Unk_1655220(Unk_165e060Value<0xc420>());
        field_58 = nullptr;
        return {1};
    case 8:
        field_58->Unk_1655220(Unk_165e060Value<0xc421>());
        field_58 = nullptr;
        return {1};
    }
    if (Unk_172be20(Unk_27fc0a8) == 4) {
        field_58->Unk_1655220(Unk_165e060Value<0x8c56>());
        field_58 = nullptr;
        return {1};
    }
    if (MillisecondsSince(field_a0) > 1000 && Unk_27fc0a8->field_8->vf20(field_90)) {
        Unk_27fc0a8_type* session = Unk_27fc0a8;
        if (session->field_180[session->field_162] == field_90) {
            Unk_172e0d0(session, 2);
        } else if (session->field_180[session->field_162 == 0] == field_90) {
            Unk_172e0e0(session, 2);
        }
        field_58->Unk_16551b0(Unk_165e060Value<0>());
        field_58 = nullptr;
        return {1};
    }
    if (MillisecondsSince(field_a0) > 15000) {
        field_58->Unk_1655220(Unk_165e060Value<0x2c18>());
        field_58 = nullptr;
        return {1};
    }
    return {5};
}

// 0x7101731170
void CloseParticipationJob::Unk_1731170() {
    if (field_58 != nullptr) {
        if (field_58->m_State == 1) {
            Unk_1655290(field_58);
        }
        field_58 = nullptr;
    }
    if (m_Context.m_State == 1) {
        Unk_1655290(&m_Context);
    }
    m_Context.Unk_1655110();
}

// 0x71017311d0
CommunityManagementJob::CommunityManagementJob() : field_58(nullptr) {}

// 0x7101731210 (and 0x7101731250, deleting: a trap, the class is abstract)
CommunityManagementJob::~CommunityManagementJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x7101731260
void CommunityManagementJob::vf6() {
    if (field_58 != nullptr) {
        if (field_58->m_State == 1) {
            Unk_1655290(field_58);
        }
        field_58 = nullptr;
    }
    if (m_Context.m_State == 1) {
        Unk_1655290(&m_Context);
    }
    m_Context.Unk_1655110();
}

// 0x71017312c0
ClearMatchmakeSystemPasswordJob::ClearMatchmakeSystemPasswordJob() : field_58(0), field_60(nullptr) {}

// 0x7101731300 (and 0x7101731340, deleting: a trap, the class is abstract)
ClearMatchmakeSystemPasswordJob::~ClearMatchmakeSystemPasswordJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x7101731350
Unk_165bb20_result ClearMatchmakeSystemPasswordJob::Unk_1731350() {
    field_60->Unk_16551b0(Unk_165e060Value<0>());
    field_60 = nullptr;
    return {1};
}

// 0x71017313d0
void ClearMatchmakeSystemPasswordJob::vf6() {
    if (field_60 != nullptr) {
        if (field_60->m_State == 1) {
            Unk_1655290(field_60);
        }
        field_60 = nullptr;
    }
    if (m_Context.m_State == 1) {
        Unk_1655290(&m_Context);
    }
    m_Context.Unk_1655110();
    field_58 = 0;
}

// 0x7101731440
GenerateMatchmakeSystemPasswordJob::GenerateMatchmakeSystemPasswordJob()
    : field_58(0), field_60(nullptr) {}

// 0x7101731480 (0x71017314c0, deleting, is a trap: the class is abstract)
GenerateMatchmakeSystemPasswordJob::~GenerateMatchmakeSystemPasswordJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

}  // namespace session
}  // namespace pia
}  // namespace nn
