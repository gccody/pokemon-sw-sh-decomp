// Scope: common
//
// The trade's sync save channel (prog/network/net_contents/source/trade/common/sync_save): it sends
// and receives SyncSaveDataHolder messages, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h). The segment 0x710103da00-0x7101041bc0 (one or more TUs).
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "sync_save_data_holder.pb.h"

namespace pb = net_contents::trade::common::sync_save::protocol_buffers;

// What the sync save channel hands the messages it receives to, with the
// peer they're from.
class Unk_240a7e0_Listener {
public:
    virtual void vf0(const pb::SyncCommand& syncCommand, u64 peer);
};

// The sync save channel (vtable 0x710240a7f0).
class Unk_240a7e0 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::SyncSaveDataHolder>;

    ~Unk_240a7e0() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_1041a10(const pb::SyncCommand& syncCommand, Unk_239a418_Allocator* heap);

    Unk_240a7e0_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_240a7e0, field_168, 0x168);

// 0x7101041130
void Unk_240a7e0::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::SyncSaveDataHolder::kSyncCommand:
            field_168->vf0(message.get()->synccommand(), peer);
            break;
        default:
            break;
    }
}

// 0x7101041a10
Unk_240a7e0::Message Unk_240a7e0::Unk_1041a10(const pb::SyncCommand& syncCommand,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_synccommand()->CopyFrom(syncCommand);
    return message;
}
