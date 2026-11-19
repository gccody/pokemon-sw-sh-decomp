// Scope: common
//
// gflnet3's sync ping (lib/gflnet3/src/p2p/sync/ping): its channel sends and
// receives gflnet::p2p::sync::ping::pb::SyncPingDataHolder messages, a Ping,
// a PingReply or a PingSynced, and hands what it receives to its listener.
// The segment 0x71006b9030-0x71006bc100 (one or more TUs, before the ping
// messages' generated code). Placeholder names: rename once the classes are
// known.
#include <algorithm>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "gflnet3/src/p2p/sync/ping/Unk_23a3638.h"
#include "sync_ping_data_holder.pb.h"

namespace pb = gflnet::p2p::sync::ping::pb;

// The ping channel (vtable 0x71023a3670).
class Unk_23a3660 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::SyncPingDataHolder>;

    ~Unk_23a3660() override;
    void vf8(const void* data, int size, u64 peer) override;

    bool Unk_6ba1e0(const pb::Ping& ping, u64 peer);
    bool Unk_6ba3c0(const pb::PingReply& pingReply, u64 peer);
    Message Unk_6bb510(const pb::Ping& ping, Unk_239a418_Allocator* heap);
    Message Unk_6bb7b0(const pb::PingReply& pingReply, Unk_239a418_Allocator* heap);
    bool Unk_6bba00(const pb::PingSynced& pingSynced, u64 peer);
    Message Unk_6bbad0(const pb::PingSynced& pingSynced, Unk_239a418_Allocator* heap);

    Unk_23a3660_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23a3660, field_168, 0x168);

// 0x71006ba1e0
bool Unk_23a3660::Unk_6ba1e0(const pb::Ping& ping, u64 peer) {
    return Unk_6b89b0(Unk_6bb510(ping, field_8), peer);
}

// 0x71006ba3c0
bool Unk_23a3660::Unk_6ba3c0(const pb::PingReply& pingReply, u64 peer) {
    return Unk_6b89b0(Unk_6bb7b0(pingReply, field_8), peer);
}

// 0x71006bada0
// NON_MATCHING: the paths that call the three default_instance()s are placed
// PingReply, Ping, PingSynced; the original places Ping last (one load of the
// listener's slot differs). Case order, if chains and a default don't move it.
void Unk_23a3660::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::SyncPingDataHolder::kPing:
            field_168->vf0(message.get()->ping(), peer);
            break;
        case pb::SyncPingDataHolder::kPingReply:
            field_168->vf1(message.get()->pingreply(), peer);
            break;
        case pb::SyncPingDataHolder::kPingSynced:
            field_168->vf2(message.get()->pingsynced(), peer);
            break;
        default:
            break;
    }
}

// 0x71006bb510
Unk_23a3660::Message Unk_23a3660::Unk_6bb510(const pb::Ping& ping, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_ping()->CopyFrom(ping);
    return message;
}

// 0x71006bb7b0
Unk_23a3660::Message Unk_23a3660::Unk_6bb7b0(const pb::PingReply& pingReply,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_pingreply()->CopyFrom(pingReply);
    return message;
}

// 0x71006bba00
bool Unk_23a3660::Unk_6bba00(const pb::PingSynced& pingSynced, u64 peer) {
    return Unk_6b89b0(Unk_6bbad0(pingSynced, field_8), peer);
}

// 0x71006bbad0
Unk_23a3660::Message Unk_23a3660::Unk_6bbad0(const pb::PingSynced& pingSynced,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_pingsynced()->CopyFrom(pingSynced);
    return message;
}

// 0x71006ba490
void Unk_23a3638::vf0(const pb::Ping& ping, u64 peer) {
    auto it = std::find_if(field_50.begin(), field_50.end(),
                           [&](const Unk_23a3638_Peer& p) { return p.field_0 == peer; });
    if (it == field_50.end())
        return;
    if (Unk_6ba2b0(peer))
        it->field_9 = true;
}

// 0x71006ba500
void Unk_23a3638::vf1(const pb::PingReply& pingReply, u64 peer) {
    auto it = std::find_if(field_50.begin(), field_50.end(),
                           [&](const Unk_23a3638_Peer& p) { return p.field_0 == peer; });
    if (it == field_50.end())
        return;
    it->field_8 = true;
}

// 0x71006ba550
void Unk_23a3638::vf2(const pb::PingSynced& pingSynced, u64 peer) {
    auto it = std::find_if(field_50.begin(), field_50.end(),
                           [&](const Unk_23a3638_Peer& p) { return p.field_0 == peer; });
    if (it == field_50.end())
        return;
    it->field_a = true;
}

// 0x71006b9910
bool Unk_23a3638::Unk_6b9910(const u64& peer) {
    if (field_18.m_ptr == nullptr)
        return false;
    Unk_6b8ad0_Message<pb::Ping> ping(field_8);
    return field_18.m_ptr->Unk_6ba1e0(*ping.get(), peer);
}

// 0x71006ba2b0
bool Unk_23a3638::Unk_6ba2b0(const u64& peer) {
    if (field_18.m_ptr == nullptr)
        return false;
    Unk_6b8ad0_Message<pb::PingReply> reply(field_8);
    return field_18.m_ptr->Unk_6ba3c0(*reply.get(), peer);
}

// 0x71006b9f50
void Unk_23a3638::Unk_6b9f50(const u64& peer) {
    field_20.erase(std::remove(field_20.begin(), field_20.end(), peer), field_20.end());
    field_50.erase(std::remove_if(field_50.begin(), field_50.end(),
                                  [peer](const Unk_23a3638_Peer& p) { return p.field_0 == peer; }),
                   field_50.end());
}

// 0x71006b9260
void Unk_23a3638::Unk_6b9260() {
    if (field_18.m_ptr != nullptr)
        field_18.m_ptr->field_168 = nullptr;
    field_18.Reset();
    field_50.clear();
    field_80 = false;
}
