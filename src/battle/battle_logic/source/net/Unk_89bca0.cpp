// Scope: common
//
// The battle's data holder channels, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h): BtlDataHolder, BtlCmdDataHolder.
// The segment 0x7100898dd0-0x710089db10 (one or more TUs). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "btl_cmd_data_holder.pb.h"
#include "btl_data_holder.pb.h"
#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

namespace pb = btl::net::protocol_buffers;

// What the The battle's channel hands the messages it receives to, with the
// peer they're from.
class Unk_23b8410_Listener {
public:
    virtual void vf0(const pb::EmptyCommand& emptyCommand, u64 peer);
    virtual void vf1(const pb::PokeParty& pokeParty, u64 peer);
    virtual void vf2(const pb::ServerVersion& serverVersion, u64 peer);
};

// The The battle's channel (vtable 0x71023b8420).
class Unk_23b8410 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BtlDataHolder>;

    ~Unk_23b8410() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_89d0e0(const pb::ServerVersion& serverVersion, Unk_239a418_Allocator* heap);
    Message Unk_89d210(const pb::EmptyCommand& emptyCommand, Unk_239a418_Allocator* heap);

    Unk_23b8410_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23b8410, field_168, 0x168);

// What the The battle's channel hands the messages it receives to, with the
// peer they're from.
class Unk_23b84d0_Listener {
public:
    virtual void vf0(const pb::BattleCommand& battleCommand, u64 peer);
    virtual void vf1(const pb::InvalidCommand& invalidCommand, u64 peer);
    virtual void vf2(const pb::RaidAction& raidAction, u64 peer);
    virtual void vf3(const pb::Timer& timer, u64 peer);
    virtual void vf4(const pb::TrainerAction& trainerAction, u64 peer);
};

// The The battle's channel (vtable 0x71023b84e0).
class Unk_23b84d0 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::BtlCmdDataHolder>;

    ~Unk_23b84d0() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_89d460(const pb::RaidAction& raidAction, Unk_239a418_Allocator* heap);
    Message Unk_89d700(const pb::TrainerAction& trainerAction, Unk_239a418_Allocator* heap);
    Message Unk_89d830(const pb::BattleCommand& battleCommand, Unk_239a418_Allocator* heap);
    Message Unk_89d960(const pb::Timer& timer, Unk_239a418_Allocator* heap);

    Unk_23b84d0_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_23b84d0, field_168, 0x168);

// 0x710089bca0
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_23b8410::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BtlDataHolder::kEmptyCommand:
            field_168->vf0(message.get()->emptycommand(), peer);
            break;
        case pb::BtlDataHolder::kPokeParty:
            field_168->vf1(message.get()->pokeparty(), peer);
            break;
        case pb::BtlDataHolder::kServerVersion:
            field_168->vf2(message.get()->serverversion(), peer);
            break;
        default:
            break;
    }
}

// 0x710089c1d0
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_23b84d0::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::BtlCmdDataHolder::kBattleCommand:
            field_168->vf0(message.get()->battlecommand(), peer);
            break;
        case pb::BtlCmdDataHolder::kInvalidCommand:
            field_168->vf1(message.get()->invalidcommand(), peer);
            break;
        case pb::BtlCmdDataHolder::kRaidAction:
            field_168->vf2(message.get()->raidaction(), peer);
            break;
        case pb::BtlCmdDataHolder::kTimer:
            field_168->vf3(message.get()->timer(), peer);
            break;
        case pb::BtlCmdDataHolder::kTrainerAction:
            field_168->vf4(message.get()->traineraction(), peer);
            break;
        default:
            break;
    }
}

// 0x710089d0e0
Unk_23b8410::Message Unk_23b8410::Unk_89d0e0(const pb::ServerVersion& serverVersion,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_serverversion()->CopyFrom(serverVersion);
    return message;
}

// 0x710089d210
Unk_23b8410::Message Unk_23b8410::Unk_89d210(const pb::EmptyCommand& emptyCommand,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_emptycommand()->CopyFrom(emptyCommand);
    return message;
}

// 0x710089d460
Unk_23b84d0::Message Unk_23b84d0::Unk_89d460(const pb::RaidAction& raidAction,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_raidaction()->CopyFrom(raidAction);
    return message;
}

// 0x710089d700
Unk_23b84d0::Message Unk_23b84d0::Unk_89d700(const pb::TrainerAction& trainerAction,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_traineraction()->CopyFrom(trainerAction);
    return message;
}

// 0x710089d830
Unk_23b84d0::Message Unk_23b84d0::Unk_89d830(const pb::BattleCommand& battleCommand,
                                             Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_battlecommand()->CopyFrom(battleCommand);
    return message;
}

// 0x710089d960
Unk_23b84d0::Message Unk_23b84d0::Unk_89d960(const pb::Timer& timer, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_timer()->CopyFrom(timer);
    return message;
}
