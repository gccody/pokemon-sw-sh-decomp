// Scope: common
//
// The box trade's sync state channel (prog/network/net_contents/source/trade/box/box_sync_state):
// it sends and receives BoxSyncStateDataHolder messages, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h). The segment 0x710102fff0-0x7101035760 (one or more TUs).
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "box_sync_state_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

namespace pb = net_contents::trade::box::box_sync_state::protocol_buffers;

// What the box sync state channel hands the messages it receives to, with the
// peer they're from.
class Unk_2409a48_Listener {
public:
    virtual void vf0(const pb::BoxSendPokemon& boxSendPokemon, u64 peer);
    virtual void vf1(const pb::BoxSyncStateCommand& boxSyncStateCommand, u64 peer);
};

// The box sync state channel (vtable 0x7102409a58).
class Unk_2409a48 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BoxSyncStateDataHolder>;

    ~Unk_2409a48() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_1035480(const pb::BoxSendPokemon& boxSendPokemon, Unk_239a418_Allocator* heap);
    Message Unk_10355b0(const pb::BoxSyncStateCommand& boxSyncStateCommand,
                        Unk_239a418_Allocator* heap);

    Unk_2409a48_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_2409a48, field_168, 0x168);

// 0x7101033b30
void Unk_2409a48::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BoxSyncStateDataHolder::kBoxSendPokemon:
            field_168->vf0(message.get()->boxsendpokemon(), peer);
            break;
        case pb::BoxSyncStateDataHolder::kBoxSyncStateCommand:
            field_168->vf1(message.get()->boxsyncstatecommand(), peer);
            break;
        default:
            break;
    }
}

// 0x7101035480
Unk_2409a48::Message Unk_2409a48::Unk_1035480(const pb::BoxSendPokemon& boxSendPokemon,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_boxsendpokemon()->CopyFrom(boxSendPokemon);
    return message;
}

// 0x71010355b0
Unk_2409a48::Message Unk_2409a48::Unk_10355b0(const pb::BoxSyncStateCommand& boxSyncStateCommand,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_boxsyncstatecommand()->CopyFrom(boxSyncStateCommand);
    return message;
}
