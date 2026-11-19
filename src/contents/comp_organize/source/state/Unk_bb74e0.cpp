// Scope: common
//
// The competition organizer's data holder channels, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h): CompOrganizeDataHolder.
// The segment 0x7100ba5d90-0x7100bb8060 (one or more TUs). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "comp_organize_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

// The data holder is in ontents (sic), its messages in contents.
namespace pb = ontents::comp_organize::protocol_buffers;
namespace messages = contents::comp_organize::protocol_buffers;

// What the The competition organizer's channel hands the messages it receives to, with the
// peer they're from.
class Unk_23d3a80_Listener {
public:
    virtual void vf0(const messages::EmptyCmd& emptyCmd, u64 peer);
    virtual void vf1(const messages::Regulation& regulation, u64 peer);
};

// The The competition organizer's channel (vtable 0x71023d3a90).
class Unk_23d3a80 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::CompOrganizeDataHolder>;

    ~Unk_23d3a80() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_bb7eb0(const messages::Regulation& regulation, Unk_239a418_Allocator* heap);
    Message Unk_f49010(const messages::EmptyCmd& emptyCmd, Unk_239a418_Allocator* heap);

    Unk_23d3a80_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23d3a80, field_168, 0x168);

// 0x7100bb74e0
void Unk_23d3a80::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::CompOrganizeDataHolder::kEmptyCmd:
            field_168->vf0(message.get()->emptycmd(), peer);
            break;
        case pb::CompOrganizeDataHolder::kRegulation:
            field_168->vf1(message.get()->regulation(), peer);
            break;
        default:
            break;
    }
}

// 0x7100bb7eb0
Unk_23d3a80::Message Unk_23d3a80::Unk_bb7eb0(const messages::Regulation& regulation,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_regulation()->CopyFrom(regulation);
    return message;
}

// 0x7100f49010
Unk_23d3a80::Message Unk_23d3a80::Unk_f49010(const messages::EmptyCmd& emptyCmd,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_emptycmd()->CopyFrom(emptyCmd);
    return message;
}
