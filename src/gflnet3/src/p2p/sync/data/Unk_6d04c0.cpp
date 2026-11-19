// Scope: common
//
// gflnet3's sync data (lib/gflnet3/src/p2p/sync/data): its channel sends and
// receives gflnet::p2p::sync::pb::SyncDataHolder messages, which hold a Data,
// and hands what it receives to its listener. The segment
// 0x71006d04c0-0x71006d3ec0 (one or more TUs). Placeholder names: rename once
// the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "sync_data_holder.pb.h"

namespace pb = gflnet::p2p::sync::pb;

// What the sync data channel hands the messages it receives to, with the
// peer they're from.
class Unk_23a4978_Listener {
public:
    virtual void vf0(const pb::Data& data, u64 peer);
};

// The sync data channel (vtable 0x71023a4988).
class Unk_23a4978 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::SyncDataHolder>;

    ~Unk_23a4978() override;
    void vf8(const void* data, int size, u64 peer) override;

    bool Unk_6d1ba0(const pb::Data& data, u64 peer);
    Message Unk_6d3970(const pb::Data& data, Unk_239a418_Allocator* heap);

    Unk_23a4978_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23a4978, field_168, 0x168);

// 0x71006d1ba0
bool Unk_23a4978::Unk_6d1ba0(const pb::Data& data, u64 peer) {
    return Unk_6b89b0(Unk_6d3970(data, field_8), peer);
}

// 0x71006d3210
void Unk_23a4978::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::SyncDataHolder::kData:
            field_168->vf0(message.get()->data(), peer);
            break;
        default:
            break;
    }
}

// 0x71006d3970
Unk_23a4978::Message Unk_23a4978::Unk_6d3970(const pb::Data& data, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_data()->CopyFrom(data);
    return message;
}
