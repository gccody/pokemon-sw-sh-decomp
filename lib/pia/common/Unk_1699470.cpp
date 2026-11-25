// Scope: common
// local::LocalAllowParticipatingBackgroundJob (lib/pia/common/Unk_1698930.h):
// a TU of its own, as LocalAllowParticipatingJob calls its members instead of
// inlining them.
#include "pia/common/Unk_1698930.h"

namespace nn {
namespace pia {
namespace local {

using common::Unk_165bb20_result;

// 0x7101699470
LocalAllowParticipatingBackgroundJob::LocalAllowParticipatingBackgroundJob(LocalProtocol* protocol)
    : m_Context(nullptr), field_60(0), m_Protocol(protocol) {}

// 0x71016994b0 (and 0x71016994d0, deleting)
LocalAllowParticipatingBackgroundJob::~LocalAllowParticipatingBackgroundJob() {
    m_Protocol = nullptr;
}

// 0x7101699510
Unk_165e060 LocalAllowParticipatingBackgroundJob::Unk_1699510(Unk_1655080* context, u32 value) {
    if (Unk_16559c0()) {
        return Unk_165e060Value<0x10c08>();
    }
    vf2(false);
    m_Context = context;
    m_Context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    field_60 = value;
    SetStep(&LocalAllowParticipatingBackgroundJob::AllowParticipating,
            "LocalAllowParticipatingBackgroundJob::AllowParticipating");
    return Unk_165e060Value<0>();
}

// 0x71016995e0
Unk_165bb20_result LocalAllowParticipatingBackgroundJob::AllowParticipating() {
    Unk_165e060 result(0);
    switch (field_60) {
    case 1:
        result = m_Protocol->vf34();
        break;
    case 2:
        result = m_Protocol->vf33(true);
        break;
    case 3:
        result = m_Protocol->vf33(false);
        break;
    default:
        result = Unk_165e060Value<0x10c08>();
        break;
    }
    if (result.m_Value == 0) {
        m_Context->Unk_16551b0(Unk_165e060Value<0>());
    } else {
        m_Context->Unk_1655220(result);
    }
    m_Context = nullptr;
    return {1};
}

// 0x7101699740
void LocalAllowParticipatingBackgroundJob::Unk_1699740() {
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x6c05>());
        }
        m_Context = nullptr;
    }
    field_60 = 0;
}

}  // namespace local
}  // namespace pia
}  // namespace nn
