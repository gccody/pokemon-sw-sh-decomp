// Scope: common
// local::LocalEjectClientBackgroundJob's constructor, destructors and its step
// (lib/pia/common/Unk_16998e0.h): it asks the owner to eject one client.
#include "pia/common/Unk_16998e0.h"

namespace nn {
namespace pia {
namespace local {

// 0x7101699e40
LocalEjectClientBackgroundJob::LocalEjectClientBackgroundJob(Unk_16997e0_arg1* owner)
    : m_Context(nullptr), m_Owner(owner) {}

// 0x7101699e90 (and 0x7101699ee0, deleting)
LocalEjectClientBackgroundJob::~LocalEjectClientBackgroundJob() {
    m_Owner = nullptr;
}

// 0x7101699f40
Unk_165e060 LocalEjectClientBackgroundJob::Unk_1699f40(Unk_1655080* context, const Unk_165fb30& target) {
    {
        Unk_1653bb0_arg1 text;
        Unk_1653bb0_update(const_cast<Unk_1652c70*>(&target.field_8), &text);
    }
    vf2(false);
    m_Context = context;
    context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    m_Target = target;
    SetStep(&LocalEjectClientBackgroundJob::EjectClient, "LocalEjectClientBackgroundJob::EjectClient");
    return Unk_165e060Value<0>();
}

// 0x710169a020
common::Unk_165bb20_result LocalEjectClientBackgroundJob::EjectClient() {
    Unk_165e060 result = m_Owner->vf35(&m_Target.field_8);
    if (result.m_Value == 0) {
        m_Context->Unk_16551b0(Unk_165e060Value<0>());
    } else {
        m_Context->Unk_1655220(result);
    }
    m_Context = nullptr;
    return {1};
}

// 0x710169a0d0
void LocalEjectClientBackgroundJob::Unk_169a0d0() {
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x6c05>());
        }
        m_Context = nullptr;
    }
    Unk_1653900(&m_Target.field_8);
}

}  // namespace local
}  // namespace pia
}  // namespace nn
