// Scope: common
//
// The battle watch's data holder channels, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h): BtlwatchDataHolder, BtlwatchAsyncDataHolder.
// The segment 0x71008adb30-0x71008b4b10 (one or more TUs). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "btlwatch_async_data_holder.pb.h"
#include "btlwatch_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

namespace pb = btl::net::watch::protocol_buffers;

// What the The battle watch's channel hands the messages it receives to, with the
// peer they're from.
class Unk_23b9f40_Listener {
public:
    virtual void vf0(const pb::WatchCmd& watchCmd, u64 peer);
};

// The The battle watch's channel (vtable 0x71023b9f50).
class Unk_23b9f40 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BtlwatchDataHolder>;

    ~Unk_23b9f40() override;
    void vf8(const void* data, int size, u64 peer) override;

    Unk_23b9f40_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23b9f40, field_168, 0x168);

// What the The battle watch's channel hands the messages it receives to, with the
// peer they're from.
class Unk_23ba000_Listener {
public:
    virtual void vf0(const pb::WatchBody& watchBody, u64 peer);
    virtual void vf1(const pb::WatchClientTimer& watchClientTimer, u64 peer);
    virtual void vf2(const pb::WatchCommand& watchCommand, u64 peer);
    virtual void vf3(const pb::WatchParty& watchParty, u64 peer);
    virtual void vf4(const pb::WatchSeq& watchSeq, u64 peer);
    virtual void vf5(const pb::WatchTargetParty& watchTargetParty, u64 peer);
    virtual void vf6(const pb::WatchTimer& watchTimer, u64 peer);
    virtual void vf7(const pb::WatchWinLose& watchWinLose, u64 peer);
};

// The The battle watch's channel (vtable 0x71023ba010).
class Unk_23ba000 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BtlwatchAsyncDataHolder>;

    ~Unk_23ba000() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_8b3fb0(const pb::WatchSeq& watchSeq, Unk_239a418_Allocator* heap);
    Message Unk_8b4250(const pb::WatchBody& watchBody, Unk_239a418_Allocator* heap);
    Message Unk_8b4380(const pb::WatchParty& watchParty, Unk_239a418_Allocator* heap);
    Message Unk_8b44b0(const pb::WatchTargetParty& watchTargetParty, Unk_239a418_Allocator* heap);
    Message Unk_8b45e0(const pb::WatchCommand& watchCommand, Unk_239a418_Allocator* heap);
    Message Unk_8b4710(const pb::WatchTimer& watchTimer, Unk_239a418_Allocator* heap);
    Message Unk_8b4840(const pb::WatchClientTimer& watchClientTimer, Unk_239a418_Allocator* heap);
    Message Unk_8b4970(const pb::WatchWinLose& watchWinLose, Unk_239a418_Allocator* heap);

    Unk_23ba000_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23ba000, field_168, 0x168);

// 0x71008b2fa0
void Unk_23b9f40::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BtlwatchDataHolder::kWatchCmd:
            field_168->vf0(message.get()->watchcmd(), peer);
            break;
        default:
            break;
    }
}

// 0x71008b3460
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_23ba000::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BtlwatchAsyncDataHolder::kWatchBody:
            field_168->vf0(message.get()->watchbody(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchClientTimer:
            field_168->vf1(message.get()->watchclienttimer(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchCommand:
            field_168->vf2(message.get()->watchcommand(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchParty:
            field_168->vf3(message.get()->watchparty(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchSeq:
            field_168->vf4(message.get()->watchseq(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchTargetParty:
            field_168->vf5(message.get()->watchtargetparty(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchTimer:
            field_168->vf6(message.get()->watchtimer(), peer);
            break;
        case pb::BtlwatchAsyncDataHolder::kWatchWinLose:
            field_168->vf7(message.get()->watchwinlose(), peer);
            break;
        default:
            break;
    }
}

// 0x71008b3fb0
Unk_23ba000::Message Unk_23ba000::Unk_8b3fb0(const pb::WatchSeq& watchSeq,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchseq()->CopyFrom(watchSeq);
    return message;
}

// 0x71008b4250
Unk_23ba000::Message Unk_23ba000::Unk_8b4250(const pb::WatchBody& watchBody,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchbody()->CopyFrom(watchBody);
    return message;
}

// 0x71008b4380
Unk_23ba000::Message Unk_23ba000::Unk_8b4380(const pb::WatchParty& watchParty,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchparty()->CopyFrom(watchParty);
    return message;
}

// 0x71008b44b0
Unk_23ba000::Message Unk_23ba000::Unk_8b44b0(const pb::WatchTargetParty& watchTargetParty,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchtargetparty()->CopyFrom(watchTargetParty);
    return message;
}

// 0x71008b45e0
Unk_23ba000::Message Unk_23ba000::Unk_8b45e0(const pb::WatchCommand& watchCommand,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchcommand()->CopyFrom(watchCommand);
    return message;
}

// 0x71008b4710
Unk_23ba000::Message Unk_23ba000::Unk_8b4710(const pb::WatchTimer& watchTimer,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchtimer()->CopyFrom(watchTimer);
    return message;
}

// 0x71008b4840
Unk_23ba000::Message Unk_23ba000::Unk_8b4840(const pb::WatchClientTimer& watchClientTimer,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchclienttimer()->CopyFrom(watchClientTimer);
    return message;
}

// 0x71008b4970
Unk_23ba000::Message Unk_23ba000::Unk_8b4970(const pb::WatchWinLose& watchWinLose,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_watchwinlose()->CopyFrom(watchWinLose);
    return message;
}
