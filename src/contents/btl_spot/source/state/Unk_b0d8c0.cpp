// Scope: common
//
// The battle spot's data holder channels, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h): BtlSpotDataHolder.
// The segment 0x7100b0a9b0-0x7100b0e7e0 (one or more TUs). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "btl_spot_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

namespace pb = contents::btl_spot::protocol_buffers;

// What the The battle spot's channel hands the messages it receives to, with the
// peer they're from.
class Unk_23cdab8_Listener {
public:
    virtual void vf0(const pb::BtlSpotMathingOK& btlSpotMathingOK, u64 peer);
};

// The The battle spot's channel (vtable 0x71023cdac8).
class Unk_23cdab8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BtlSpotDataHolder>;

    ~Unk_23cdab8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_b0ddf0(const pb::BtlSpotMathingOK& btlSpotMathingOK, Unk_239a418_Allocator* heap);

    Unk_23cdab8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23cdab8, field_168, 0x168);

// 0x7100b0d8c0
void Unk_23cdab8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BtlSpotDataHolder::kBtlSpotMathingOK:
            field_168->vf0(message.get()->btlspotmathingok(), peer);
            break;
        default:
            break;
    }
}

// 0x7100b0dce0
template bool Unk_23a3578::Unk_6b8d70(const Unk_23cdab8::Message& message);

// 0x7100b0ddf0
Unk_23cdab8::Message Unk_23cdab8::Unk_b0ddf0(const pb::BtlSpotMathingOK& btlSpotMathingOK,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_btlspotmathingok()->CopyFrom(btlSpotMathingOK);
    return message;
}
