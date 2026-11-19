// Scope: common
//
// The battle team selection's channel
// (prog/network/net_contents/source/battle/poke_select): it sends and receives
// PokeSelectAsyncDataHolder messages (Datas or an Enter) on gflnet3's p2p
// channel (src/gflnet3/src/p2p/Unk_23a3578.h). The segment
// 0x7100fee160-0x7100fefcb0 (one or more TUs, before the messages' generated
// code). Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "poke_select_async_data_holder.pb.h"

namespace pb = net_contents::battle::poke_select::protocol_buffers;

// What the team selection's channel hands the messages it receives to, with the
// peer they're from.
class Unk_2405fd0_Listener {
public:
    virtual void vf0(const pb::Datas& datas, u64 peer);
    virtual void vf1(const pb::Enter& enter, u64 peer);
};

// The team selection's channel (vtable 0x7102405fe0).
class Unk_2405fd0 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::PokeSelectAsyncDataHolder>;

    ~Unk_2405fd0() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_fef660(const pb::Enter& enter, Unk_239a418_Allocator* heap);
    Message Unk_fef900(const pb::Datas& datas, Unk_239a418_Allocator* heap);

    Unk_2405fd0_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_2405fd0, field_168, 0x168);

// 0x7100fef000
void Unk_2405fd0::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::PokeSelectAsyncDataHolder::kDatas:
            field_168->vf0(message.get()->datas(), peer);
            break;
        case pb::PokeSelectAsyncDataHolder::kEnter:
            field_168->vf1(message.get()->enter(), peer);
            break;
        default:
            break;
    }
}

// 0x7100fef550
template bool Unk_23a3578::Unk_6b8d70(const Unk_2405fd0::Message& message);

// 0x7100fef660
Unk_2405fd0::Message Unk_2405fd0::Unk_fef660(const pb::Enter& enter, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_enter()->CopyFrom(enter);
    return message;
}

// 0x7100fef900
Unk_2405fd0::Message Unk_2405fd0::Unk_fef900(const pb::Datas& datas, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_datas()->CopyFrom(datas);
    return message;
}
