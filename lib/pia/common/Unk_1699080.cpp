// Scope: common
// local::LocalAllowParticipatingJob's start, steps and cancel
// (lib/pia/common/Unk_1698930.h). Its constructor and destructors are in
// lib/pia/common/Unk_1698930.cpp, and its background job in Unk_1699470.cpp.
#include "pia/common/Unk_1698930.h"

namespace nn {
namespace pia {
namespace local {

using common::Unk_165bb20_result;

// 0x7101699080
Unk_165e060 LocalAllowParticipatingJob::Unk_1699080(Unk_1655080* context, u32 value) {
    if (!m_Protocol->Unk_1694a60()) {
        return Unk_165e060Value<0x10c08>();
    }
    Unk_165e060 result = m_Job->Unk_1699510(&m_JobContext, value);
    if (result.m_Value != 0) {
        return result;
    }
    field_98 = value;
    m_Result = Unk_165e060Value<0>();
    m_Context = context;
    m_Context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    m_Job->Unk_1655850(true);
    SetStep(&LocalAllowParticipatingJob::WaitAllowParticipating, "LocalAllowParticipatingJob::WaitAllowParticipating");
    return Unk_165e060Value<0>();
}

// 0x71016991b0
Unk_165bb20_result LocalAllowParticipatingJob::WaitAllowParticipating() {
    if (m_Context->field_28) {
        if (m_JobContext.m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(&m_JobContext));
        }
        m_Result = Unk_165e060Value<0x6c05>();
        SetStep(&LocalAllowParticipatingJob::WaitBackgroundJobEnd, "LocalAllowParticipatingJob::WaitBackgroundJobEnd");
        return {0};
    }
    switch (m_JobContext.m_State) {
    case 1:
        return {5};
    case 2:
        Unk_16928a0_set(reinterpret_cast<Unk_16928a0*>(m_Protocol), field_98);
        m_Protocol->Unk_16935a0();
        m_Result = Unk_165e060Value<0>();
        break;
    case 3: {
        Unk_165e060 result = m_JobContext.m_Result;
        m_Result = result;
        break;
    }
    case 4:
        m_Result = Unk_165e060Value<0x6c05>();
        break;
    default:
        return {1};
    }
    SetStep(&LocalAllowParticipatingJob::WaitBackgroundJobEnd, "LocalAllowParticipatingJob::WaitBackgroundJobEnd");
    return {0};
}

// 0x71016992b0
void LocalAllowParticipatingJob::Unk_16992b0() {
    if (m_Job != nullptr) {
        m_Job->Cancel(2);
        m_Job->Unk_1699740();
    }
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x6c05>());
        }
        m_Context = nullptr;
    }
    field_98 = 0;
    m_Result = Unk_165e060Value<0>();
}

// 0x7101699390
Unk_165bb20_result LocalAllowParticipatingJob::WaitBackgroundJobEnd() {
    if (m_Job->Unk_1655a80()) {
        return {5};
    }
    SetStep(&LocalAllowParticipatingJob::CompleteProcess, "LocalAllowParticipatingJob::CompleteProcess");
    return {0};
}

// 0x71016993f0
Unk_165bb20_result LocalAllowParticipatingJob::CompleteProcess() {
    if (m_Result.m_Value == 0) {
        m_Context->Unk_16551b0(m_Result);
    } else {
        m_Context->Unk_1655220(m_Result);
    }
    m_Context = nullptr;
    return {1};
}

}  // namespace local
}  // namespace pia
}  // namespace nn
