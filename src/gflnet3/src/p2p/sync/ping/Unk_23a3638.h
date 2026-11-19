#pragma once
// gflnet3's sync ping listener (src/gflnet3/src/p2p/sync/ping/Unk_6b9030.cpp):
// it answers Pings through its channel and keeps, per peer, which ping
// messages came. The block session (src/gflnet3/src/p2p/session/block) tells
// it when a peer leaves. Placeholder names: rename once the classes are known.
#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "sync_ping_data_holder.pb.h"
#include "unsorted/Unk_2771620.h"

class Unk_23a3660;

// What the ping channel hands the messages it receives to, with the peer
// they're from.
class Unk_23a3660_Listener {
public:
    virtual void vf0(const gflnet::p2p::sync::ping::pb::Ping& ping, u64 peer);
    virtual void vf1(const gflnet::p2p::sync::ping::pb::PingReply& pingReply, u64 peer);
    virtual void vf2(const gflnet::p2p::sync::ping::pb::PingSynced& pingSynced, u64 peer);
};

// What the ping listener keeps for each peer. Its members are initialised
// (not a POD), so assigning one copies 0xe bytes, not the tail padding.
struct Unk_23a3638_Peer {
    u64 field_0 = 0;       // the peer
    bool field_8 = false;  // a PingReply came
    bool field_9 = false;  // a Ping came (and was answered)
    bool field_a = false;  // a PingSynced came
    u8 field_b = 0;
    u16 field_c = 0;
};
PKMN_SIZE_ASSERT(Unk_23a3638_Peer, 0x10);

// The ping channel's listener (vtable 0x71023a3648).
class Unk_23a3638 : public Unk_23a3660_Listener {
public:
    void vf0(const gflnet::p2p::sync::ping::pb::Ping& ping, u64 peer) override;
    void vf1(const gflnet::p2p::sync::ping::pb::PingReply& pingReply, u64 peer) override;
    void vf2(const gflnet::p2p::sync::ping::pb::PingSynced& pingSynced, u64 peer) override;

    bool Unk_6b9910(const u64& peer);
    void Unk_6b9f50(const u64& peer);
    bool Unk_6ba2b0(const u64& peer);

    Unk_239a418_Allocator* field_8;
    u8 _10[0x8];
    Unk_23a3660* field_18;
    std::vector<u64, Unk_2771620_Allocator<u64>> field_20;
    std::vector<Unk_23a3638_Peer, Unk_2771620_Allocator<Unk_23a3638_Peer>> field_50;
};
PKMN_OFFSET_ASSERT(Unk_23a3638, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_23a3638, field_50, 0x50);
