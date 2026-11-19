// Scope: common
//
// The battle's sequence's data holder channels, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h): SequenceDataHolder.
// The segment 0x7100898dd0-0x710089db10 (one or more TUs). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "sequence_data_holder.pb.h"

namespace pb = gflnet::p2p::framework::pb;

// What the The battle's sequence channel hands the messages it receives to, with the
// peer they're from.
class Unk_23b8590_Listener {
public:
    virtual void vf0(const pb::CancelAccepted& cancelAccepted, u64 peer);
    virtual void vf1(const pb::RequestCancel& requestCancel, u64 peer);
    virtual void vf2(const pb::RequestCancelAll& requestCancelAll, u64 peer);
    virtual void vf3(const pb::RequestForcedProceed& requestForcedProceed, u64 peer);
};

// The The battle's sequence channel (vtable 0x71023b85a0).
class Unk_23b8590 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::SequenceDataHolder>;

    ~Unk_23b8590() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_89a920(const pb::CancelAccepted& cancelAccepted, Unk_239a418_Allocator* heap);

    Unk_23b8590_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23b8590, field_168, 0x168);

// 0x710089a920
Unk_23b8590::Message Unk_23b8590::Unk_89a920(const pb::CancelAccepted& cancelAccepted,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_cancelaccepted()->CopyFrom(cancelAccepted);
    return message;
}

// 0x710089c760
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_23b8590::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::SequenceDataHolder::kCancelAccepted:
            field_168->vf0(message.get()->cancelaccepted(), peer);
            break;
        case pb::SequenceDataHolder::kRequestCancel:
            field_168->vf1(message.get()->requestcancel(), peer);
            break;
        case pb::SequenceDataHolder::kRequestCancelAll:
            field_168->vf2(message.get()->requestcancelall(), peer);
            break;
        case pb::SequenceDataHolder::kRequestForcedProceed:
            field_168->vf3(message.get()->requestforcedproceed(), peer);
            break;
        default:
            break;
    }
}
