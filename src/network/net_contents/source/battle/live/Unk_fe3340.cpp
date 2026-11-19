// Scope: common
//
// The live battle's channels (prog/network/net_contents/source/battle/live):
// one for NetLiveDataHolder messages (a LiveEmpty or a LiveRegulation) and
// one for NetLiveAsyncDataHolder messages (a LiveStartSync), on gflnet3's p2p
// channel (src/gflnet3/src/p2p/Unk_23a3578.h). The segment
// 0x7100fe3340-0x7100fea950 (one or more TUs, before the live messages'
// generated code). Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "net_live_async_data_holder.pb.h"
#include "net_live_data_holder.pb.h"

namespace pb = net_contents::battle::live::protocol_buffers;

// What the async channel hands the messages it receives to, with the peer
// they're from.
class Unk_24056f8_Listener {
public:
    virtual void vf0(const pb::LiveStartSync& liveStartSync, u64 peer);
};

// The live battle's async channel (vtable 0x7102405708).
class Unk_24056f8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::NetLiveAsyncDataHolder>;

    ~Unk_24056f8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_fea630(const pb::LiveStartSync& liveStartSync, Unk_239a418_Allocator* heap);

    Unk_24056f8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_24056f8, field_168, 0x168);

// What the live battle's channel hands the messages it receives to.
class Unk_24059d8_Listener {
public:
    virtual void vf0(const pb::LiveEmpty& liveEmpty, u64 peer);
    virtual void vf1(const pb::LiveRegulation& liveRegulation, u64 peer);
};

// The live battle's channel (vtable 0x71024059e8).
class Unk_24059d8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::NetLiveDataHolder>;

    ~Unk_24059d8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_fea2c0(const pb::LiveRegulation& liveRegulation, Unk_239a418_Allocator* heap);
    Message Unk_fea3f0(const pb::LiveEmpty& liveEmpty, Unk_239a418_Allocator* heap);

    Unk_24059d8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_24059d8, field_168, 0x168);

// 0x7100fe7cc0
void Unk_24056f8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::NetLiveAsyncDataHolder::kLiveStartSync:
            field_168->vf0(message.get()->livestartsync(), peer);
            break;
        default:
            break;
    }
}

// 0x7100fe9e60
void Unk_24059d8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::NetLiveDataHolder::kLiveEmpty:
            field_168->vf0(message.get()->liveempty(), peer);
            break;
        case pb::NetLiveDataHolder::kLiveRegulation:
            field_168->vf1(message.get()->liveregulation(), peer);
            break;
        default:
            break;
    }
}

// 0x7100fea2c0
Unk_24059d8::Message Unk_24059d8::Unk_fea2c0(const pb::LiveRegulation& liveRegulation,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_liveregulation()->CopyFrom(liveRegulation);
    return message;
}

// 0x7100fea3f0
Unk_24059d8::Message Unk_24059d8::Unk_fea3f0(const pb::LiveEmpty& liveEmpty,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_liveempty()->CopyFrom(liveEmpty);
    return message;
}

// 0x7100fea520
template bool Unk_23a3578::Unk_6b8d70(const Unk_24056f8::Message& message);

// 0x7100fea630
Unk_24056f8::Message Unk_24056f8::Unk_fea630(const pb::LiveStartSync& liveStartSync,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_livestartsync()->CopyFrom(liveStartSync);
    return message;
}
