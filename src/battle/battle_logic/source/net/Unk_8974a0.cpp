// Scope: common
//
// The battle's net peer (Unk_8974a0.h): the slots of 0x7100897580-0x7100898318
// and their thunks. Part of the segment 0x7100891a20-0x7100898dd0 (one or more
// TUs). Placeholder names: rename once the classes are known.
#include "battle/battle_logic/source/net/Unk_8974a0.h"

#include <algorithm>
#include <cstring>

#include <nn/err.h>

#include "gflib3/Unk_Lock.h"
#include "pia/common/Unk_165e060.h"

u8 Unk_6ae9d0(u64 peer);  // the client of a peer (0xfd: none)
bool Unk_8a7000(void* self, u32 clientId);
void Unk_6d7ac0(u64 arg0, u64 peer, u32 arg2);

struct Unk_1652250;
u64 Unk_1652250_get(const Unk_1652250* self);

// An error to report, if there is one.
struct Unk_23a24f0_Error {
    explicit Unk_23a24f0_Error(const nn::pia::Unk_165e060& result)
        : field_0(false), field_4(result) {
        field_0 = true;
    }
    ~Unk_23a24f0_Error() {
        if (field_0)
            field_0 = false;
    }

    bool field_0;
    nn::pia::Unk_165e060 field_4;
};
PKMN_OFFSET_ASSERT(Unk_23a24f0_Error, field_4, 0x4);

// The object Unk_24ba160 points to (src/gflib3/families/Unk_7c20.cpp), with
// the two functions used here.
class Unk_23a24f0 {
public:
    const Unk_1652250* Unk_6ac290();
    void Unk_6abee0(const Unk_23a24f0_Error& error);
};
extern Unk_23a24f0* Unk_24ba160;

// A class on Unk_239a418 whose type getter (0x710089b390) is out of line.
struct Unk_27d1078 {
    static const Unk_239a418_Type* Unk_GetType();
};

// What a station object sends its data with.
class Unk_23b8280_Sender {
public:
    virtual bool vf0(const void* data, u32 size, u64 arg2, u16 arg3, u64 arg4);
    virtual bool vf1();
};

// A client's station (src/unsorted/virtual/Unk_89b040.cpp).
class Unk_23b8280 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d1078::Unk_GetType());
        return &type;
    }

    bool Send() {
        if ((field_80 == nullptr || !field_80->vf1()) && !field_70)
            return false;
        if (field_80 == nullptr)
            return false;
        return field_80->vf0(&field_88, sizeof(field_88), field_78, field_62, field_68);
    }

    void Unk_897bf0(const Unk_23b7ee8_Peer& peer);

    bool field_60;  // the last send failed
    bool field_61;
    u16 field_62;
    u8 _64[0x4];
    u64 field_68;
    bool field_70;
    u8 _71[0x7];
    u64 field_78;
    Unk_23b8280_Sender* field_80;
    Unk_23b7ee8_Peer field_88;
};
PKMN_OFFSET_ASSERT(Unk_23b8280, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23b8280, field_62, 0x62);
PKMN_OFFSET_ASSERT(Unk_23b8280, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_23b8280, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23b8280, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_23b8280, field_88, 0x88);

// src/unsorted/virtual/Unk_89b8a0.cpp
class Unk_23b8348 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d1078::Unk_GetType());
        return &type;
    }

    u8 _60[0x1];
    bool field_61;
    u8 _62[0x26];
    Unk_23b7ee8_Info field_88;
};
PKMN_OFFSET_ASSERT(Unk_23b8348, field_61, 0x61);
PKMN_OFFSET_ASSERT(Unk_23b8348, field_88, 0x88);

template <class T>
static Unk_239a418_Ref<T> Unk_LockOrNone(Unk_239a418_Handle* handle) {
    return handle != nullptr ? Unk_Lock<T>(handle) : Unk_239a418_Ref<T>();
}

// 0x7100897580, its thunk from +0x60 0x7100897750
// NON_MATCHING: the thunk (0x7100897750). It subtracts 0x60 from `this` up
// front and loads the entries at their offsets from the object; here the
// subtraction is folded into the loads' offsets and done for the store alone.
// The function itself matches.
void Unk_23b7ee8::vf11(u64 stationId) {
    field_190.Remove(stationId);
}

// 0x7100897640
void Unk_23b7ee8_Peers::Unk_897640() {
    for (s32 i = 0; i < 8; ++i) {
        if (field_0[i].field_a && field_80 == field_0[i].field_9) {
            field_81 = field_0[i].field_8;
            return;
        }
    }
}

// 0x7100897810, its thunk from +0x60 0x7100897880
void Unk_23b7ee8::vf12() {
    if (field_3c0 != nullptr)
        field_3c0->Unk_6b9260();
    field_3c0.reset();
    field_190.field_81 = field_90;
}

// 0x71008978f0, its thunk from +0x60 0x7100897960
// NON_MATCHING: the original tests the first station before the loop (the
// search's first iteration is peeled); the rest is the same. A loop that
// returns from inside, a while loop with both tests and std::find_if (end
// computed once or twice) don't peel it.
u8 Unk_23b7ee8::vf13(u64 stationId) {
    const Unk_23b7ee8_Station* end = field_a0.field_80.end();
    const Unk_23b7ee8_Station* it =
        std::find_if(field_a0.field_80.begin(), end,
                     [stationId](const Unk_23b7ee8_Station& s) { return s.field_0 == stationId; });
    if (it != end)
        return it->field_8;
    return 5;
}

// 0x71008979d0, its thunk from +0x60 0x7100897a10
u8 Unk_23b7ee8::vf14() {
    if (field_88->field_4 == 2) {
        switch (field_88->field_3a5) {
            case 0:
                return 4;
            case 1:
                return 3;
            case 2:
                return 2;
            case 3:
            case 4:
            case 5:
                return 1;
            case 6:
                return 2;
            case 7:
                return 3;
        }
    }
    return 1;
}

// 0x7100897a50, its thunk from +0x70 0x7100897d10
void Unk_23b7ee8::vf2(const pb::ServerVersion& serverVersion, u64 peer) {
    if (field_148 == nullptr)
        return;
    u8 client = Unk_6ae9d0(peer);
    Unk_23b7ee8_Peer station;
    station.field_9 = serverVersion.version();
    station.field_8 = serverVersion.clientid();
    station.field_0 = serverVersion.stationid();
    station.field_a = true;
    {
        Unk_239a418_Ref<Unk_23b8280> object = Unk_LockOrNone<Unk_23b8280>(field_150[client]);
        if (object.m_ptr != nullptr)
            object.m_ptr->Unk_897bf0(station);
    }
    Unk_6d7ac0(field_148->field_2a0, peer, 1);
}

// 0x7100897bf0
void Unk_23b8280::Unk_897bf0(const Unk_23b7ee8_Peer& peer) {
    Unk_23a24f0* net = Unk_24ba160;
    field_78 = Unk_1652250_get(net->Unk_6ac290());
    if (field_78 == static_cast<u64>(-1)) {
        net->Unk_6abee0(Unk_23a24f0_Error(nn::pia::Unk_165e060(0x2c27)));
        return;
    }
    field_88 = peer;
    field_60 = !Send();
}

// 0x7100897dc0, its thunk from +0x78 0x7100897ec0
void Unk_23b7ee8::vf0(const pb::BattleCommand& battleCommand, u64 peer) {
    u8 client = Unk_6ae9d0(peer);
    if (client == 0xfd)
        return;
    u32 type = battleCommand.commandtype();
    u32 clientId = battleCommand.clientid();
    if (!Unk_8a7000(field_3b8, clientId))
        return;
    if (type == 1) {
        if (battleCommand.clientid() == field_190.field_81)
            field_238[0]->Set(battleCommand);
    } else if (type == 2) {
        field_238[client + 1]->Set(battleCommand);
    }
}

// 0x7100897ed0, its thunk from +0x78 0x7100897ef0
void Unk_23b7ee8::vf2(const pb::RaidAction& raidAction, u64 /*peer*/) {
    if (raidAction.clientid() < 8)
        field_358[raidAction.clientid()] = raidAction.action();
}

// 0x7100897f10, its thunk from +0x78 0x7100897f30
void Unk_23b7ee8::vf4(const pb::TrainerAction& trainerAction, u64 /*peer*/) {
    if (trainerAction.clientid() < 8)
        field_360[trainerAction.clientid()] = true;
}

// 0x7100897f50, its thunk from +0x68 0x7100898250
void Unk_23b7ee8::vf21(u16 kind) {
    switch (kind) {
        case 1:
            Unk_897f70();
            break;
        case 2:
            Unk_898100();
            break;
    }
}

// 0x7100897f70
void Unk_23b7ee8::Unk_897f70() {
    for (s32 i = 0; i < 8; ++i) {
        Unk_239a418_Ref<Unk_23b8280> object = Unk_LockOrNone<Unk_23b8280>(field_150[i]);
        if (object.m_ptr == nullptr || !object.m_ptr->field_61)
            continue;
        const Unk_23b7ee8_Peer& station = object.m_ptr->field_88;
        u64 stationId = station.field_0;
        u8 clientId = station.field_8;
        Unk_23b7ee8_Peer& entry = field_190.field_0[i];
        if (!entry.field_a) {
            u8 version = station.field_9;
            entry.field_8 = clientId;
            entry.field_0 = stationId;
            entry.field_9 = version;
            entry.field_a = true;
            if (version > field_190.field_80)
                field_190.field_80 = version;
        }
        field_a0.Unk_898380(stationId, clientId);
    }
    field_190.Unk_897640();
}

// 0x7100898100
void Unk_23b7ee8::Unk_898100() {
    Unk_239a418_Ref<Unk_23b8348> object = Unk_LockOrNone<Unk_23b8348>(field_218);
    if (object.m_ptr != nullptr && object.m_ptr->field_61)
        field_220 = object.m_ptr->field_88;
}

// 0x7100898280, its thunk from +0x78 0x71008982d0
void Unk_23b7ee8::vf3(const pb::Timer& timer, u64 peer) {
    u8 client = Unk_6ae9d0(peer);
    if (client < 8) {
        Unk_23b7ee8_Timer value = {timer.focusmode(), timer.timer()};
        field_368[client] = value;
    }
}
