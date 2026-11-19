// Scope: common
//
// gflnet3's block session (lib/gflnet3/src/p2p/session/block): its channel
// sends and receives gflnet::p2p::block::pb::BlockDataHolder messages, a
// Result or an ImReady, and hands what it receives to its listener.
// The segment 0x71006b6550-0x71006b9030 (one or more TUs, before the block
// messages' generated code). Placeholder names: rename once the classes are
// known.
#include <algorithm>
#include <vector>

#include <types.h>

#include "block_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "gflnet3/src/p2p/sync/ping/Unk_23a3638.h"
#include "unsorted/Unk_2771620.h"

namespace pb = gflnet::p2p::block::pb;

// What the block channel hands the messages it receives to, with the peer
// they're from (the block session's interface at +0x68).
class Unk_23a34b8_Listener {
public:
    virtual void vf0(const pb::Result& result, u64 peer);
    virtual void vf1(const pb::ImReady& imReady, u64 peer);
};

// The block channel (vtable 0x71023a34c8).
class Unk_23a34b8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BlockDataHolder>;

    ~Unk_23a34b8() override;
    void vf8(const void* data, int size, u64 peer) override;

    bool Unk_6b7820(const pb::Result& result, u64 peer);
    Message Unk_6b8ad0(const pb::Result& result, Unk_239a418_Allocator* heap);
    Message Unk_6b8e80(const pb::ImReady& imReady, Unk_239a418_Allocator* heap);

    Unk_23a34b8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23a34b8, field_168, 0x168);

// What the block session hears about peers (its interface at +0x60): one
// joined (0) or left (1).
class Unk_23a3480 {
public:
    virtual void vf0(s32 event, u64 peer);
};

// What the block session keeps for each peer. Its members are initialised
// (not a POD), so assigning one copies 0x1e bytes, not the tail padding.
struct Unk_23a33b8_Peer {
    u64 field_0 = 0;  // the peer
    u8 _8[0x12] = {};
    bool field_1a = false;  // its ImReady's isReady
    u8 field_1b = 0;
    bool field_1c = false;  // a Result came
    bool field_1d = false;  // its Result's isBlocking
};
PKMN_SIZE_ASSERT(Unk_23a33b8_Peer, 0x20);
PKMN_OFFSET_ASSERT(Unk_23a33b8_Peer, field_1a, 0x1a);
PKMN_OFFSET_ASSERT(Unk_23a33b8_Peer, field_1d, 0x1d);

// The block session (vtable 0x71023a33c8): listens to its channel and to
// the peers coming and going.
class Unk_23a33b8 : public Unk_239a418, public Unk_23a3480, public Unk_23a34b8_Listener {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf0(const pb::Result& result, u64 peer) override;
    void vf1(const pb::ImReady& imReady, u64 peer) override;
    void vf0(s32 event, u64 peer) override;

    void Unk_6b6d70(const u64& peer, bool arg2);

    u8 _70[0xc0];
    std::vector<Unk_23a33b8_Peer, Unk_2771620_Allocator<Unk_23a33b8_Peer>> field_130;
    u8 _160[0x8];
    Unk_23a3638* field_168;  // the ping listener
};
PKMN_OFFSET_ASSERT(Unk_23a33b8, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_23a33b8, field_168, 0x168);

// 0x71006b7820
bool Unk_23a34b8::Unk_6b7820(const pb::Result& result, u64 peer) {
    return Unk_6b89b0(Unk_6b8ad0(result, field_8), peer);
}

// 0x71006b8020
void Unk_23a34b8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BlockDataHolder::kResult:
            field_168->vf0(message.get()->result(), peer);
            break;
        case pb::BlockDataHolder::kImReady:
            field_168->vf1(message.get()->imready(), peer);
            break;
        default:
            break;
    }
}

// 0x71006b8ad0
Unk_23a34b8::Message Unk_23a34b8::Unk_6b8ad0(const pb::Result& result,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_result()->CopyFrom(result);
    return message;
}

// 0x71006b8d70
template bool Unk_23a3578::Unk_6b8d70(const Unk_23a34b8::Message& message);

// 0x71006b8e80
Unk_23a34b8::Message Unk_23a34b8::Unk_6b8e80(const pb::ImReady& imReady,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_imready()->CopyFrom(imReady);
    return message;
}

// 0x71006b79c0
void Unk_23a33b8::vf0(const pb::Result& result, u64 peer) {
    auto it = std::find_if(field_130.begin(), field_130.end(),
                           [peer](const Unk_23a33b8_Peer& p) { return p.field_0 == peer; });
    if (it == field_130.end())
        return;
    it->field_1d = result.isblocking();
    it->field_1c = true;
}

// 0x71006b7a60
void Unk_23a33b8::vf1(const pb::ImReady& imReady, u64 peer) {
    auto it = std::find_if(field_130.begin(), field_130.end(),
                           [peer](const Unk_23a33b8_Peer& p) { return p.field_0 == peer; });
    if (it == field_130.end())
        return;
    it->field_1a = imReady.isready();
}

// 0x71006b7b00
void Unk_23a33b8::vf0(s32 event, u64 peer) {
    switch (event) {
        case 0:
            Unk_6b6d70(peer, true);
            break;
        case 1:
            if (field_168 != nullptr)
                field_168->Unk_6b9f50(peer);
            field_130.erase(
                std::remove_if(field_130.begin(), field_130.end(),
                               [&](const Unk_23a33b8_Peer& p) { return p.field_0 == peer; }),
                field_130.end());
            break;
    }
}
