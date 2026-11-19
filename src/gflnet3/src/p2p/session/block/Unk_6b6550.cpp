// Scope: common
//
// gflnet3's block session (lib/gflnet3/src/p2p/session/block): its channel
// sends and receives gflnet::p2p::block::pb::BlockDataHolder messages, a
// Result or an ImReady, and hands what it receives to its listener.
// The segment 0x71006b6550-0x71006b9030 (one or more TUs, before the block
// messages' generated code). Placeholder names: rename once the classes are
// known.
#include <types.h>

#include "block_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

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
