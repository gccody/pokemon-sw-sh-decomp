#pragma once
// The battle's net peer (vtable 0x71023b7ef8, class Unk_23b7ee8): a class on
// gflib3's reference-counted object that listens to both of the battle's
// data holder channels (Unk_89bca0.cpp) and keeps, for each of the eight
// clients, the station that serves it, its version and the commands it sent.
//
// Its other vtables are those of its bases: two interfaces of its own (+0x60,
// 0x71023b8038, and +0x68, 0x71023b8088) and the listeners of the two
// channels (+0x70, 0x71023b80d8, and +0x78, 0x71023b8100: their slot 1 is
// the listener's own empty handler). The functions it overrides fill those
// vtables with thunks, emitted after each function (the small ones with the
// body inlined), so the class is declared here with its bases.
// src/unsorted/virtual/Unk_8923e0.cpp and src/unsorted/types/Unk_898c10.cpp
// declare it without them (and name the EmptyCommand handler, 0x7100897d20,
// vf16). Placeholder names: rename once the classes are known.
#include <cstring>
#include <memory>

#include <types.h>

#include "btl_cmd_data_holder.pb.h"
#include "btl_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f4660.h"

namespace pb = btl::net::protocol_buffers;

namespace nn {
namespace pia {
class Unk_165e060;
}  // namespace pia
}  // namespace nn

// The channels' listeners (Unk_89bca0.cpp).
class Unk_23b8410_Listener {
public:
    virtual void vf0(const pb::EmptyCommand& emptyCommand, u64 peer);
    virtual void vf1(const pb::PokeParty& pokeParty, u64 peer);
    virtual void vf2(const pb::ServerVersion& serverVersion, u64 peer);
};

class Unk_23b84d0_Listener {
public:
    virtual void vf0(const pb::BattleCommand& battleCommand, u64 peer);
    virtual void vf1(const pb::InvalidCommand& invalidCommand, u64 peer);
    virtual void vf2(const pb::RaidAction& raidAction, u64 peer);
    virtual void vf3(const pb::Timer& timer, u64 peer);
    virtual void vf4(const pb::TrainerAction& trainerAction, u64 peer);
};

// The interfaces at +0x60 and +0x68, named after the primary vtable's slots
// that override them (every slot of +0x60's; +0x68's other four are its own
// empty functions). Signatures are what the overrides show.
class Unk_23b7ee8_60 {
public:
    virtual void vf7();
    virtual void vf9();
    virtual void vf10();
    virtual void vf8();
    virtual void vf11(u64 stationId);
    virtual void vf12();
    virtual u8 vf13(u64 stationId);
    virtual u8 vf14();
};

class Unk_23b7ee8_68 {
public:
    virtual void vf21(u16 kind);
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
};

// A client's station: its id, the client, its version and whether the entry
// is set. The station objects keep the one they were told (vf15) in the same
// shape.
struct Unk_23b7ee8_Peer {
    u64 field_0;  // station id
    u8 field_8;   // client id
    u8 field_9;   // version
    bool field_a;
};
PKMN_SIZE_ASSERT(Unk_23b7ee8_Peer, 0x10);

// The stations of the eight clients, the highest version among them and the
// client of the first station with it.
struct Unk_23b7ee8_Peers {
    // Clears the entry of a station.
    void Remove(u64 stationId) {
        if (stationId != 0) {
            for (s32 i = 0; i < 8; ++i) {
                if (field_0[i].field_0 == stationId) {
                    field_0[i].field_a = false;
                    break;
                }
            }
        }
        Unk_897640();
    }

    void Unk_897640();

    Unk_23b7ee8_Peer field_0[8];
    u8 field_80;  // the highest version
    u8 field_81;  // the client of the first station with it
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8_Peers, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23b7ee8_Peers, field_81, 0x81);

// A station and its client, in the array at +0x120.
struct Unk_23b7ee8_Station {
    u64 field_0;
    u8 field_8;
};
PKMN_SIZE_ASSERT(Unk_23b7ee8_Station, 0x10);

// The member at +0xa0: an array of stations at +0x80 (pointer, count).
struct Unk_23b7ee8_a0 {
    void Unk_898380(u64 stationId, u8 clientId);

    u8 _0[0x80];
    Unk_23b7ee8_Station* field_80;
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8_a0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23b7ee8_a0, field_88, 0x88);

struct Unk_23b7ee8_88 {
    u8 _0[0x4];
    u32 field_4;
    u8 _8[0x39d];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8_88, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_23b7ee8_88, field_3a5, 0x3a5);

struct Unk_23b7ee8_148 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8_148, field_2a0, 0x2a0);

// A client's last BattleCommand: its type, client, sequence number and body.
struct Unk_23b7ee8_Command {
    void Set(const pb::BattleCommand& battleCommand) {
        field_0 = battleCommand.commandtype();
        field_4 = battleCommand.clientid();
        field_8 = battleCommand.cmdseqno();
        field_2720 = battleCommand.body().size();
        std::memset(field_c, 0, sizeof(field_c));
        std::memcpy(field_c, battleCommand.body().data(), battleCommand.body().size());
    }

    u32 field_0;
    u8 field_4;
    u32 field_8;
    u8 field_c[0x2714];
    u64 field_2720;  // the body's size
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8_Command, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23b7ee8_Command, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_23b7ee8_Command, field_2720, 0x2720);

// A client's Timer.
struct Unk_23b7ee8_Timer {
    u32 field_0;  // focus mode
    u32 field_4;  // timer
};
PKMN_SIZE_ASSERT(Unk_23b7ee8_Timer, 0x8);

// The ping listener (src/gflnet3/src/p2p/sync/ping/Unk_23a3638.h), with the
// destructor that header leaves implicit: the original's is out of line
// (0x71006b90e0).
class Unk_23a3638 {
public:
    ~Unk_23a3638();
    void Unk_6b9260();
};

// What 0x710089b8a0's classes copy at +0x88 (Unk_23b8348).
struct Unk_23b7ee8_Info {
    u8 field_0[0x15];
};
PKMN_SIZE_ASSERT(Unk_23b7ee8_Info, 0x15);

class Unk_23b7ee8 : public Unk_239a418,
                    public Unk_23b7ee8_60,
                    public Unk_23b7ee8_68,
                    public Unk_23b8410_Listener,
                    public Unk_23b84d0_Listener {
public:
    using Unk_239a418::vf2;
    using Unk_239a418::vf3;
    using Unk_239a418::vf4;

    ~Unk_23b7ee8() override;
    void vf7() override;
    void vf8() override;
    void vf9() override;
    void vf10() override;
    void vf11(u64 stationId) override;
    void vf12() override;
    u8 vf13(u64 stationId) override;
    u8 vf14() override;
    void vf2(const pb::ServerVersion& serverVersion, u64 peer) override;
    void vf0(const pb::EmptyCommand& emptyCommand, u64 peer) override;
    void vf0(const pb::BattleCommand& battleCommand, u64 peer) override;
    void vf2(const pb::RaidAction& raidAction, u64 peer) override;
    void vf4(const pb::TrainerAction& trainerAction, u64 peer) override;
    void vf3(const pb::Timer& timer, u64 peer) override;
    void vf21(u16 kind) override;
    void vf22() override;
    void vf23() override;
    void vf24() override;

    void Unk_897f70();
    void Unk_898100();

    u8 _80[0x8];
    Unk_23b7ee8_88* field_88;
    u8 field_90;
    u8 _91[0xf];
    Unk_23b7ee8_a0 field_a0;
    u8 _130[0x18];
    Unk_23b7ee8_148* field_148;
    Unk_239a418_Handle* field_150[8];  // the clients' stations (Unk_23b8280)
    Unk_23b7ee8_Peers field_190;
    Unk_239a418_Handle* field_218;  // Unk_23b8348
    Unk_23b7ee8_Info field_220;
    // this client's command, then each client's
    std::unique_ptr<Unk_23b7ee8_Command, Unk_23f4660_Deleter> field_238[9];
    u8 field_358[8];    // each client's RaidAction
    bool field_360[8];  // each client's TrainerAction came
    Unk_23b7ee8_Timer field_368[8];
    u8 _3a8[0x10];
    void* field_3b8;
    std::unique_ptr<Unk_23a3638, Unk_23f4660_Deleter> field_3c0;
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_220, 0x220);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_238, 0x238);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_3b8, 0x3b8);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_3c0, 0x3c0);
