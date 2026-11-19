// Scope: common
//
// The Max Raid den's channel (prog/network/net_contents/source/nesthole): it sends and receives
// NestholeAsyncDataHolder messages, on gflnet3's p2p channel (src/gflnet3/src/p2p/Unk_23a3578.h).
// The segment 0x710101b780-0x7101021420 (one or more TUs). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "nesthole_async_data_holder.pb.h"

namespace pb = net_contents::nesthole::protocol_buffers;

// What the den's channel hands the messages it receives to, with the
// peer they're from.
class Unk_24086f8_Listener {
public:
    virtual void vf0(const pb::NestholeTimeLimit& nestholeTimeLimit, u64 peer);
    virtual void vf1(const pb::NestholePlayerInfo& nestholePlayerInfo, u64 peer);
    virtual void vf2(const pb::NestholeBattleReady& nestholeBattleReady, u64 peer);
    virtual void vf3(const pb::NestholeSelectPokemon& nestholeSelectPokemon, u64 peer);
    virtual void vf4(const pb::NestholeBattleStart& nestholeBattleStart, u64 peer);
    virtual void vf5(const pb::NestholeBossPokemon& nestholeBossPokemon, u64 peer);
    virtual void vf6(const pb::NestholeRewards& nestholeRewards, u64 peer);
    virtual void vf7(const pb::NestholeBattleSeed& nestholeBattleSeed, u64 peer);
};

// The den's channel (vtable 0x7102408708).
class Unk_24086f8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::NestholeAsyncDataHolder>;

    ~Unk_24086f8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_10202d0(const pb::NestholeTimeLimit& nestholeTimeLimit,
                        Unk_239a418_Allocator* heap);
    Message Unk_1020570(const pb::NestholePlayerInfo& nestholePlayerInfo,
                        Unk_239a418_Allocator* heap);
    Message Unk_10206a0(const pb::NestholeBattleReady& nestholeBattleReady,
                        Unk_239a418_Allocator* heap);
    Message Unk_10207d0(const pb::NestholeSelectPokemon& nestholeSelectPokemon,
                        Unk_239a418_Allocator* heap);
    Message Unk_1020900(const pb::NestholeBattleStart& nestholeBattleStart,
                        Unk_239a418_Allocator* heap);
    Message Unk_1020a30(const pb::NestholeBossPokemon& nestholeBossPokemon,
                        Unk_239a418_Allocator* heap);
    Message Unk_1020b60(const pb::NestholeRewards& nestholeRewards, Unk_239a418_Allocator* heap);
    Message Unk_1020c90(const pb::NestholeBattleSeed& nestholeBattleSeed,
                        Unk_239a418_Allocator* heap);

    Unk_24086f8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_24086f8, field_168, 0x168);

// 0x710101fb60
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_24086f8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::NestholeAsyncDataHolder::kNestholeTimeLimit:
            field_168->vf0(message.get()->nestholetimelimit(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholePlayerInfo:
            field_168->vf1(message.get()->nestholeplayerinfo(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholeBattleReady:
            field_168->vf2(message.get()->nestholebattleready(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholeSelectPokemon:
            field_168->vf3(message.get()->nestholeselectpokemon(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholeBattleStart:
            field_168->vf4(message.get()->nestholebattlestart(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholeBossPokemon:
            field_168->vf5(message.get()->nestholebosspokemon(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholeRewards:
            field_168->vf6(message.get()->nestholerewards(), peer);
            break;
        case pb::NestholeAsyncDataHolder::kNestholeBattleSeed:
            field_168->vf7(message.get()->nestholebattleseed(), peer);
            break;
        default:
            break;
    }
}

// 0x71010201c0
template bool Unk_23a3578::Unk_6b8d70(const Unk_24086f8::Message& message);

// 0x71010202d0
Unk_24086f8::Message Unk_24086f8::Unk_10202d0(const pb::NestholeTimeLimit& nestholeTimeLimit,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholetimelimit()->CopyFrom(nestholeTimeLimit);
    return message;
}

// 0x7101020570
Unk_24086f8::Message Unk_24086f8::Unk_1020570(const pb::NestholePlayerInfo& nestholePlayerInfo,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholeplayerinfo()->CopyFrom(nestholePlayerInfo);
    return message;
}

// 0x71010206a0
Unk_24086f8::Message Unk_24086f8::Unk_10206a0(const pb::NestholeBattleReady& nestholeBattleReady,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholebattleready()->CopyFrom(nestholeBattleReady);
    return message;
}

// 0x71010207d0
Unk_24086f8::Message Unk_24086f8::Unk_10207d0(
    const pb::NestholeSelectPokemon& nestholeSelectPokemon,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholeselectpokemon()->CopyFrom(nestholeSelectPokemon);
    return message;
}

// 0x7101020900
Unk_24086f8::Message Unk_24086f8::Unk_1020900(const pb::NestholeBattleStart& nestholeBattleStart,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholebattlestart()->CopyFrom(nestholeBattleStart);
    return message;
}

// 0x7101020a30
Unk_24086f8::Message Unk_24086f8::Unk_1020a30(const pb::NestholeBossPokemon& nestholeBossPokemon,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholebosspokemon()->CopyFrom(nestholeBossPokemon);
    return message;
}

// 0x7101020b60
Unk_24086f8::Message Unk_24086f8::Unk_1020b60(const pb::NestholeRewards& nestholeRewards,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholerewards()->CopyFrom(nestholeRewards);
    return message;
}

// 0x7101020c90
Unk_24086f8::Message Unk_24086f8::Unk_1020c90(const pb::NestholeBattleSeed& nestholeBattleSeed,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_nestholebattleseed()->CopyFrom(nestholeBattleSeed);
    return message;
}
