// Scope: common
// local::LocalDestroyNetworkJob (lib/pia/common/Unk_1697a00.h): its
// constructor, destructors, start, cancel and steps. Its vf5 is in
// lib/nx_middleware/class/nn_pia_local_LocalDestroyNetworkJob.cpp, and its
// WaitForCancel (0x7101698540) in lib/nx_middleware/leaf/Unk_168ab60.cpp,
// under a leaf's placeholder name.
#include "pia/common/Unk_1697a00.h"

#include "pia/common/Unk_17162d0.h"

// Inline: the milliseconds since a tick (as lib/pia/common/Unk_1730e60.cpp has
// it).
static inline s64 MillisecondsSince(const Unk_165c600& start) {
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    return (static_cast<s64>(now.field_0) - static_cast<s64>(start.field_0)) / *Unk_165c6b0();
}

namespace nn {
namespace pia {
namespace local {

using common::Unk_165bb20_result;

// 0x71016981b0
LocalDestroyNetworkJob::LocalDestroyNetworkJob(LocalProtocol* protocol)
    : m_Context(nullptr), field_68(), field_70(), field_78(), field_80(false), m_Protocol(protocol) {
    m_JobContext = new (Unk_1652bd0()) Unk_1655080();
}

// 0x7101698220 (and 0x7101698270, deleting)
LocalDestroyNetworkJob::~LocalDestroyNetworkJob() {
    Unk_1655080* context = m_JobContext;
    if (context != nullptr) {
        Unk_1655170_update(reinterpret_cast<u64>(context));
        Unk_1716390(context);
    }
    m_Protocol = nullptr;
}

// 0x71016982d0
Unk_165e060 LocalDestroyNetworkJob::Unk_16982d0(Unk_1655080* context, bool arg) {
    if (m_Protocol->field_474 != 1) {
        return Unk_165e060Value<0x10c08>();
    }
    m_Context = context;
    m_Context->Unk_1655110();
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(m_Context));
    field_80 = arg;
    if (arg) {
        LocalProtocol* protocol = m_Protocol;
        protocol->field_418 = 1;
        protocol->field_468 = 1;
    }
    SetStep(&LocalDestroyNetworkJob::TryPrepareDestroyNetwork, "LocalDestroyNetworkJob::TryPrepareDestroyNetwork");
    return Unk_165e060Value<0>();
}

// 0x71016983a0
Unk_165bb20_result LocalDestroyNetworkJob::TryPrepareDestroyNetwork() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        SetStep(&LocalDestroyNetworkJob::WaitForCancel, "LocalDestroyNetworkJob::WaitForCancel");
        return {0};
    }
    Unk_165e060 result = m_Protocol->field_400->Unk_1687580();
    if (result.m_Value != 0) {
        return {5};
    }
    if (field_80) {
        m_Protocol->Unk_16935a0();
        Unk_165c600_call(&field_78);
        SetStep(&LocalDestroyNetworkJob::WaitUntilAllClientsReceiveUpdateSessionMessage,
                "LocalDestroyNetworkJob::WaitUntilAllClientsReceiveUpdateSessionMessage");
        return {0};
    }
    Unk_165c600_call(&field_70);
    SetStep(&LocalDestroyNetworkJob::SendDestroyNetworkMessage, "LocalDestroyNetworkJob::SendDestroyNetworkMessage");
    return {0};
}

// 0x7101698490
void LocalDestroyNetworkJob::Unk_1698490() {
    Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
    if (m_Context != nullptr) {
        if (m_Context->m_State == 1) {
            m_Context->Unk_1655220(Unk_165e060Value<0x6c05>());
        }
        m_Context = nullptr;
    }
    if (field_80) {
        LocalProtocol* protocol = m_Protocol;
        if (protocol != nullptr) {
            protocol->field_418 = 0;
            protocol->field_468 = 0;
        }
    }
}

// 0x7101698590
Unk_165bb20_result LocalDestroyNetworkJob::WaitUntilAllClientsReceiveUpdateSessionMessage() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        SetStep(&LocalDestroyNetworkJob::WaitForCancel, "LocalDestroyNetworkJob::WaitForCancel");
        return {0};
    }
    if (!Unk_1695d90_check(reinterpret_cast<const Unk_1695d90*>(m_Protocol)) ||
        MillisecondsSince(field_78) > 10000) {
        Unk_165c600_call(&field_70);
        SetStep(&LocalDestroyNetworkJob::SendDestroyNetworkMessage,
                "LocalDestroyNetworkJob::SendDestroyNetworkMessage");
        return {0};
    }
    return {5};
}

// 0x7101698670
Unk_165bb20_result LocalDestroyNetworkJob::SendDestroyNetworkMessage() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        SetStep(&LocalDestroyNetworkJob::WaitForCancel, "LocalDestroyNetworkJob::WaitForCancel");
        return {0};
    }
    if (!m_Protocol->Unk_1694a60()) {
        SetStep(&LocalDestroyNetworkJob::StartDestroyNetwork, "LocalDestroyNetworkJob::StartDestroyNetwork");
        return {0};
    }
    if (field_80) {
        LocalProtocol* protocol = m_Protocol;
        protocol->field_468 = 0;
        protocol->Unk_1694650();
    } else {
        m_Protocol->Unk_16945d0();
    }
    Unk_165c600_call(&field_68);
    SetStep(&LocalDestroyNetworkJob::WaitUntilAllClientsDisconnection,
            "LocalDestroyNetworkJob::WaitUntilAllClientsDisconnection");
    return {5};
}

// 0x7101698740
Unk_165bb20_result LocalDestroyNetworkJob::StartDestroyNetwork() {
    Unk_165e060 result = m_Protocol->field_400->Unk_1687630(m_JobContext);
    if (result.m_Value != 0) {
        m_Context->Unk_1655220(m_JobContext->m_Result);
        m_Context = nullptr;
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        return {1};
    }
    m_Protocol->field_400->Unk_1655850(true);
    SetStep(&LocalDestroyNetworkJob::WaitDestroyNetwork, "LocalDestroyNetworkJob::WaitDestroyNetwork");
    return {5};
}

// 0x7101698810
Unk_165bb20_result LocalDestroyNetworkJob::WaitUntilAllClientsDisconnection() {
    if (m_Context->field_28) {
        if (m_JobContext->m_State == 1) {
            Unk_1655330_set(reinterpret_cast<Unk_1655330*>(m_JobContext));
        }
        if (field_80) {
            m_Protocol->field_418 = 0;
        }
        SetStep(&LocalDestroyNetworkJob::WaitForCancel, "LocalDestroyNetworkJob::WaitForCancel");
        return {0};
    }
    if (m_Protocol->Unk_16955c0() == 1 || MillisecondsSince(field_70) > 10000) {
        SetStep(&LocalDestroyNetworkJob::StartDestroyNetwork, "LocalDestroyNetworkJob::StartDestroyNetwork");
        return {0};
    }
    if (MillisecondsSince(field_68) > 300) {
        SetStep(&LocalDestroyNetworkJob::SendDestroyNetworkMessage,
                "LocalDestroyNetworkJob::SendDestroyNetworkMessage");
        return {0};
    }
    return {5};
}

}  // namespace local
}  // namespace pia
}  // namespace nn
