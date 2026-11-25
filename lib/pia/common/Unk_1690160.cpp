// Scope: common
// The rest of local::LocalMatchBrowseMatchmakeJob's steps,
// local::LocalLeaveWithHostMigrationJobNew and local::LocalMatchUpdateSessionSettingJob
// (lib/pia/common/Unk_168f910.h).
#include "pia/common/Unk_165fb10.h"
#include "pia/common/Unk_168f910.h"

// The object LocalLeaveWithHostMigrationJobNew's owner points to
// (placeholder): an address at 0x2a0, and what 0x71016953a0 reads another one
// from.
struct Unk_16953a0_arg0 {
    u8 _0[0x2a0];
    nn::pia::Unk_1652c70 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_16953a0_arg0, field_2a0, 0x2a0);

bool Unk_16953a0(Unk_16953a0_arg0* self, nn::pia::Unk_1652c70* address);

// What an address is written into for a log (placeholder, as in
// lib/pia/common/Unk_16998e0.h with a larger size; Unk_1653bb0_update is
// empty).
struct Unk_1690460_text {
    Unk_1690460_text() {
        field_8 = 0;
        field_0 = 0x20;
        field_4 = 0;
    }

    u32 field_0;
    u32 field_4;
    u32 field_8;
};
void Unk_1653bb0_update(void* self, void* out);

// What the object behind the global Unk_27fc2d8 gives (placeholders): the
// host's address, and the station of an address with its value at 0x38.
struct Unk_1690460_station {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_1690460_station, field_38, 0x38);

struct Unk_1690460_host {
    u8 _0[0x18];
    nn::pia::Unk_1652c70 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1690460_host, field_18, 0x18);

class Unk_1690460_mesh {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Unk_1690460_station* vf11(const nn::pia::Unk_165fb30* address);

    u8 _8[0x98 - 0x8];
    Unk_1690460_host* field_98;
};
PKMN_OFFSET_ASSERT(Unk_1690460_mesh, field_98, 0x98);

struct Unk_174de50;
extern Unk_174de50* Unk_27fc2d8;
// Declared in lib/nx_middleware/leaf with the u64 field it returns.
Unk_1690460_mesh* Unk_174de50_get(const Unk_174de50* self);

namespace nn {
namespace pia {
namespace local {

// 0x7101690160
common::Unk_165bb20_result LocalMatchBrowseMatchmakeJob::UpdateCurrentConnectionStatus() {
    Unk_168a390_call(static_cast<const Unk_168a390*>(m_Owner), true);
    SetStep(&LocalMatchBrowseMatchmakeJob::WaitUpdateCurrentConnectionStatus,
            "LocalMatchBrowseMatchmakeJob::WaitUpdateCurrentConnectionStatus");
    return {0};
}

// 0x71016901b0
common::Unk_165bb20_result LocalMatchBrowseMatchmakeJob::WaitUpdateCurrentConnectionStatus() {
    LOCAL_MATCH_FAIL_ON_SESSION_STATE();
    if (Unk_168a380_call(static_cast<const Unk_168a380*>(m_Owner))) {
        return {5};
    }
    SetStep(&LocalMatchBrowseMatchmakeJob::UpdateSessionInfo, "LocalMatchBrowseMatchmakeJob::UpdateSessionInfo");
    return {0};
}

// 0x7101690350
common::Unk_165bb20_result LocalMatchBrowseMatchmakeJob::UpdateSessionInfo() {
    m_Matchmake->vf46();
    SetStep(&LocalMatchBrowseMatchmakeJob::CompleteProcess, "LocalMatchBrowseMatchmakeJob::CompleteProcess");
    return {0};
}

// 0x71016903a0
void LocalMatchBrowseMatchmakeJob::vf6() {
    Unk_245f0a8::vf6();
}

// 0x71016903c0
LocalLeaveWithHostMigrationJobNew::LocalLeaveWithHostMigrationJobNew(Unk_16903c0_arg1* owner) : m_Owner(owner) {}

// 0x7101690400 (and 0x7101690420, deleting)
LocalLeaveWithHostMigrationJobNew::~LocalLeaveWithHostMigrationJobNew() {
    m_Owner = nullptr;
}

// 0x7101690460
u8 LocalLeaveWithHostMigrationJobNew::vf6() {
    Unk_1690460_host* host = Unk_174de50_get(Unk_27fc2d8)->field_98;
    if (host == nullptr) {
        return 0xfd;
    }
    Unk_1652c70* hostAddress = &host->field_18;
    if (!Unk_1653890(reinterpret_cast<const Unk_1653890_arg0*>(hostAddress))) {
        return 0xfd;
    }
    Unk_1652c70 own(m_Owner->field_18->field_2a0);
    if (!Unk_1653890(reinterpret_cast<const Unk_1653890_arg0*>(&own))) {
        return 0xfd;
    }
    if (!Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&own),
                     reinterpret_cast<const Unk_1653890_arg0*>(hostAddress))) {
        {
            Unk_1690460_text text;
            Unk_1653bb0_update(&own, &text);
        }
        {
            Unk_1690460_text text;
            Unk_1653bb0_update(hostAddress, &text);
        }
        return 0xfd;
    }
    Unk_1652c70 next;
    if (!Unk_16953a0(m_Owner->field_18, &next)) {
        return 0xfd;
    }
    if (Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&next), reinterpret_cast<const Unk_1653890_arg0*>(&own))) {
        Unk_1690460_text text;
        Unk_1653bb0_update(&next, &text);
        return 0xfd;
    }
    Unk_165fb30 station;
    station.Unk_165fd90(next);
    Unk_1690460_station* found = Unk_174de50_get(Unk_27fc2d8)->vf11(&station);
    if (found == nullptr) {
        Unk_1690460_text text;
        Unk_1653bb0_update(&next, &text);
        return 0xfd;
    }
    {
        Unk_1690460_text text;
        Unk_1653bb0_update(&next, &text);
    }
    return found->field_38;
}

// 0x7101690680 (and 0x7101690690, deleting)
LocalMatchUpdateSessionSettingJob::~LocalMatchUpdateSessionSettingJob() {}

// 0x71016906c0
Unk_165e060 LocalMatchUpdateSessionSettingJob::vf7(u32 id, Unk_16906c0_arg2* session, Unk_16906c0_arg3* setting,
                                                   bool arg) {
    if (setting == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (session == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    field_98 = session;
    if (session->vf39(id)) {
        return Unk_165e060Value<0x10c08>();
    }
    field_a0 = 0;
    Unk_165e060 result(0);
    if (setting->vf7(true)) {
        result = field_98->Unk_168dec0(setting->vf10(), setting->vf4());
        if (result.m_Value != 0) {
            if (result == Unk_165e060Value<0x10c08>() || result == Unk_165e060Value<0x10c07>()) {
                return result;
            }
            m_Result = result;
            SetStep(&LocalMatchUpdateSessionSettingJob::CompleteFailure,
                    "LocalMatchUpdateSessionSettingJob::CompleteFailure");
            return Unk_165e060Value<0>();
        }
    }
    field_60.Unk_1655110();
    if (arg) {
        result = field_98->vf16(&field_60, id);
        if (result.m_Value != 0) {
            return result;
        }
        field_a0 = 1;
    }
    SetStep(&LocalMatchUpdateSessionSettingJob::SignalProcess, "LocalMatchUpdateSessionSettingJob::SignalProcess");
    return Unk_165e060Value<0>();
}

// 0x7101690930
common::Unk_165bb20_result LocalMatchUpdateSessionSettingJob::CompleteFailure() {
    m_Context->Unk_1655220(m_Result);
    m_Context = nullptr;
    vf6();
    return {1};
}

}  // namespace local
}  // namespace pia
}  // namespace nn
