// Scope: common
// A peer's removal, session::OpenParticipationJob and most of
// session::CloseParticipationJob (lib/pia/common/Unk_1730630.h).
#include "pia/common/Unk_1730630.h"

using nn::pia::Unk_165e060;
using nn::pia::Unk_165e060Value;
using nn::pia::common::Unk_165bb20_result;

// 0x7101730630
Unk_165e060 Unk_1730630(void* self, u64 id) {
    Unk_27fc0a8_type* session = Unk_27fc0a8;
    Unk_165e060 result(0);
    if (session->field_b8->Unk_1735640(id)) {
        if (session->field_a0 != nullptr) {
            session->field_a0(1, id, session->field_a8);
        }
        Unk_172c4a0(session, id);
    }
    result = Unk_16a8390_get(Unk_27fb2d8)->Unk_16c17e0(id);
    result = session->field_b8->Unk_1734fd0(id);
    return result;
}

namespace nn {
namespace pia {
namespace session {

// 0x7101730710
OpenParticipationJob::OpenParticipationJob() : field_58(nullptr), field_90(0), field_98(nullptr) {}

// 0x7101730760 (and 0x71017307a0, deleting)
OpenParticipationJob::~OpenParticipationJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x71017307e0
void OpenParticipationJob::Unk_17307e0() {
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

// 0x7101730840
CloseParticipationJob::CloseParticipationJob()
    : field_58(nullptr), field_90(0), field_98(nullptr), field_a0() {}

// 0x7101730890 (and 0x71017308d0, deleting)
CloseParticipationJob::~CloseParticipationJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x7101730910
Unk_165e060 CloseParticipationJob::Unk_1730910(Unk_1655080* caller, u32 id,
                                               Unk_1730910_arg3* target) {
    if (caller == nullptr || target == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (!target->vf28()) {
        return Unk_165e060Value<0x10c08>();
    }
    field_58 = caller;
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(caller));
    field_90 = id;
    field_98 = target;
    vf2(true);
    SetStep(&CloseParticipationJob::CloseParticipation, "CloseParticipationJob::CloseParticipation");
    return Unk_165e060Value<0>();
}

// 0x7101730a00
Unk_165bb20_result CloseParticipationJob::CloseParticipation() {
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
    if (field_58 != nullptr && field_58->field_28) {
        Unk_1655290(field_58);
        field_58 = nullptr;
        return {1};
    }
    Unk_165e060 result = field_98->vf18(&m_Context, field_90);
    if (result.m_Value != 0) {
        if (result == Unk_165e060Value<0x4c11>()) {
            return {5};
        }
        field_58->Unk_1655220(result);
        field_58 = nullptr;
        return {1};
    }
    SetStep(&CloseParticipationJob::WaitCloseParticipation,
            "CloseParticipationJob::WaitCloseParticipation");
    return {5};
}

// 0x7101730c70
Unk_165bb20_result CloseParticipationJob::WaitCloseParticipation() {
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
    if (!field_98->vf19()) {
        return {5};
    }
    if (m_Context.m_State == 2) {
        SetStep(&CloseParticipationJob::WaitP2pStable, "CloseParticipationJob::WaitP2pStable");
        Unk_165c600_call(&field_a0);
        return {0};
    }
    if (m_Context.m_State == 3) {
        field_58->Unk_1655220(m_Context.m_Result);
    }
    field_58 = nullptr;
    return {1};
}

}  // namespace session
}  // namespace pia
}  // namespace nn
