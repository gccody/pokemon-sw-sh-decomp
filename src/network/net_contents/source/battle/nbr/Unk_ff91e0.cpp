// Scope: common
//
// The link battle's channels (prog/network/net_contents/source/battle/nbr): one for NbrDataHolder
// messages and one for NbrAsyncDataHolder messages, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h). The segment 0x7100ff91e0-0x710100abf0 (one or more TUs).
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "nbr_async_data_holder.pb.h"
#include "nbr_data_holder.pb.h"

namespace pb = net_contents::battle::nbr::protocol_buffers;

// What the link battle's channel hands the messages it receives to, with the
// peer they're from.
class Unk_24071f8_Listener {
public:
    virtual void vf0(const pb::AcceptPrivilege& acceptPrivilege, u64 peer);
    virtual void vf1(const pb::SendBattleTeam& sendBattleTeam, u64 peer);
    virtual void vf2(const pb::BattleTeamCheckResult& battleTeamCheckResult, u64 peer);
    virtual void vf3(const pb::Bgm& bgm, u64 peer);
    virtual void vf4(const pb::ContinueRequest& continueRequest, u64 peer);
    virtual void vf5(const pb::Empty& empty, u64 peer);
    virtual void vf6(const pb::PassAction& passAction, u64 peer);
    virtual void vf7(const pb::PlayerPosition& playerPosition, u64 peer);
    virtual void vf8(const pb::ConfirmPlayerPosition& confirmPlayerPosition, u64 peer);
    virtual void vf9(const pb::WaitConfirmPlayerPosition& waitConfirmPlayerPosition, u64 peer);
    virtual void vf10(const pb::SendRefusalForRegulation& sendRefusalForRegulation, u64 peer);
    virtual void vf11(const pb::AcceptRefusalForRegulation& acceptRefusalForRegulation, u64 peer);
    virtual void vf12(const pb::RegulationCheckResult& regulationCheckResult, u64 peer);
    virtual void vf13(const pb::ShareRegulation& shareRegulation, u64 peer);
};

// The link battle's channel (vtable 0x7102407208).
class Unk_24071f8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::NbrDataHolder>;

    ~Unk_24071f8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_1009710(const pb::Empty& empty, Unk_239a418_Allocator* heap);
    Message Unk_1009840(const pb::AcceptPrivilege& acceptPrivilege, Unk_239a418_Allocator* heap);
    Message Unk_1009970(const pb::ShareRegulation& shareRegulation, Unk_239a418_Allocator* heap);
    Message Unk_1009aa0(const pb::PassAction& passAction, Unk_239a418_Allocator* heap);
    Message Unk_1009bd0(const pb::RegulationCheckResult& regulationCheckResult,
                        Unk_239a418_Allocator* heap);
    Message Unk_1009d00(const pb::SendBattleTeam& sendBattleTeam, Unk_239a418_Allocator* heap);
    Message Unk_1009e30(const pb::SendRefusalForRegulation& sendRefusalForRegulation,
                        Unk_239a418_Allocator* heap);
    Message Unk_1009f60(const pb::AcceptRefusalForRegulation& acceptRefusalForRegulation,
                        Unk_239a418_Allocator* heap);
    Message Unk_100a090(const pb::BattleTeamCheckResult& battleTeamCheckResult,
                        Unk_239a418_Allocator* heap);
    Message Unk_100a580(const pb::WaitConfirmPlayerPosition& waitConfirmPlayerPosition,
                        Unk_239a418_Allocator* heap);
    Message Unk_100a6b0(const pb::ConfirmPlayerPosition& confirmPlayerPosition,
                        Unk_239a418_Allocator* heap);
    Message Unk_100a910(const pb::Bgm& bgm, Unk_239a418_Allocator* heap);
    Message Unk_100aa40(const pb::ContinueRequest& continueRequest, Unk_239a418_Allocator* heap);

    Unk_24071f8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_24071f8, field_168, 0x168);

// What the link battle's async channel hands the messages it receives to, with the
// peer they're from.
class Unk_24072b8_Listener {
public:
    virtual void vf0(const pb::PlayerPositionAsync& playerPositionAsync, u64 peer);
    virtual void vf1(const pb::PlayerReadyAsync& playerReadyAsync, u64 peer);
    virtual void vf2(const pb::WillLeftAsync& willLeftAsync, u64 peer);
};

// The link battle's async channel (vtable 0x71024072c8).
class Unk_24072b8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::NbrAsyncDataHolder>;

    ~Unk_24072b8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_100a2e0(const pb::PlayerReadyAsync& playerReadyAsync, Unk_239a418_Allocator* heap);
    Message Unk_100a7e0(const pb::PlayerPositionAsync& playerPositionAsync,
                        Unk_239a418_Allocator* heap);

    Unk_24072b8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_24072b8, field_168, 0x168);

// 0x71010086a0
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_24071f8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::NbrDataHolder::kAcceptPrivilege:
            field_168->vf0(message.get()->acceptprivilege(), peer);
            break;
        case pb::NbrDataHolder::kSendBattleTeam:
            field_168->vf1(message.get()->sendbattleteam(), peer);
            break;
        case pb::NbrDataHolder::kBattleTeamCheckResult:
            field_168->vf2(message.get()->battleteamcheckresult(), peer);
            break;
        case pb::NbrDataHolder::kBgm:
            field_168->vf3(message.get()->bgm(), peer);
            break;
        case pb::NbrDataHolder::kContinueRequest:
            field_168->vf4(message.get()->continuerequest(), peer);
            break;
        case pb::NbrDataHolder::kEmpty:
            field_168->vf5(message.get()->empty(), peer);
            break;
        case pb::NbrDataHolder::kPassAction:
            field_168->vf6(message.get()->passaction(), peer);
            break;
        case pb::NbrDataHolder::kPlayerPosition:
            field_168->vf7(message.get()->playerposition(), peer);
            break;
        case pb::NbrDataHolder::kConfirmPlayerPosition:
            field_168->vf8(message.get()->confirmplayerposition(), peer);
            break;
        case pb::NbrDataHolder::kWaitConfirmPlayerPosition:
            field_168->vf9(message.get()->waitconfirmplayerposition(), peer);
            break;
        case pb::NbrDataHolder::kSendRefusalForRegulation:
            field_168->vf10(message.get()->sendrefusalforregulation(), peer);
            break;
        case pb::NbrDataHolder::kAcceptRefusalForRegulation:
            field_168->vf11(message.get()->acceptrefusalforregulation(), peer);
            break;
        case pb::NbrDataHolder::kRegulationCheckResult:
            field_168->vf12(message.get()->regulationcheckresult(), peer);
            break;
        case pb::NbrDataHolder::kShareRegulation:
            field_168->vf13(message.get()->shareregulation(), peer);
            break;
        default:
            break;
    }
}

// 0x7101008dc0
// NON_MATCHING: the paths for the kinds are placed in another order (they
// load the listener's slots in another order); the original's comes from no
// order of the cases (see Unk_23a3660::vf8, src/gflnet3/src/p2p/sync/ping).
void Unk_24072b8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::NbrAsyncDataHolder::kPlayerPositionAsync:
            field_168->vf0(message.get()->playerpositionasync(), peer);
            break;
        case pb::NbrAsyncDataHolder::kPlayerReadyAsync:
            field_168->vf1(message.get()->playerreadyasync(), peer);
            break;
        case pb::NbrAsyncDataHolder::kWillLeftAsync:
            field_168->vf2(message.get()->willleftasync(), peer);
            break;
        default:
            break;
    }
}

// 0x7101009710
Unk_24071f8::Message Unk_24071f8::Unk_1009710(const pb::Empty& empty, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_empty()->CopyFrom(empty);
    return message;
}

// 0x7101009840
Unk_24071f8::Message Unk_24071f8::Unk_1009840(const pb::AcceptPrivilege& acceptPrivilege,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_acceptprivilege()->CopyFrom(acceptPrivilege);
    return message;
}

// 0x7101009970
Unk_24071f8::Message Unk_24071f8::Unk_1009970(const pb::ShareRegulation& shareRegulation,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_shareregulation()->CopyFrom(shareRegulation);
    return message;
}

// 0x7101009aa0
Unk_24071f8::Message Unk_24071f8::Unk_1009aa0(const pb::PassAction& passAction,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_passaction()->CopyFrom(passAction);
    return message;
}

// 0x7101009bd0
Unk_24071f8::Message Unk_24071f8::Unk_1009bd0(
    const pb::RegulationCheckResult& regulationCheckResult,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_regulationcheckresult()->CopyFrom(regulationCheckResult);
    return message;
}

// 0x7101009d00
Unk_24071f8::Message Unk_24071f8::Unk_1009d00(const pb::SendBattleTeam& sendBattleTeam,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_sendbattleteam()->CopyFrom(sendBattleTeam);
    return message;
}

// 0x7101009e30
Unk_24071f8::Message Unk_24071f8::Unk_1009e30(
    const pb::SendRefusalForRegulation& sendRefusalForRegulation,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_sendrefusalforregulation()->CopyFrom(sendRefusalForRegulation);
    return message;
}

// 0x7101009f60
Unk_24071f8::Message Unk_24071f8::Unk_1009f60(
    const pb::AcceptRefusalForRegulation& acceptRefusalForRegulation,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_acceptrefusalforregulation()->CopyFrom(acceptRefusalForRegulation);
    return message;
}

// 0x710100a090
Unk_24071f8::Message Unk_24071f8::Unk_100a090(
    const pb::BattleTeamCheckResult& battleTeamCheckResult,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_battleteamcheckresult()->CopyFrom(battleTeamCheckResult);
    return message;
}

// 0x710100a2e0
Unk_24072b8::Message Unk_24072b8::Unk_100a2e0(const pb::PlayerReadyAsync& playerReadyAsync,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_playerreadyasync()->CopyFrom(playerReadyAsync);
    return message;
}

// 0x710100a580
Unk_24071f8::Message Unk_24071f8::Unk_100a580(
    const pb::WaitConfirmPlayerPosition& waitConfirmPlayerPosition,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_waitconfirmplayerposition()->CopyFrom(waitConfirmPlayerPosition);
    return message;
}

// 0x710100a6b0
Unk_24071f8::Message Unk_24071f8::Unk_100a6b0(
    const pb::ConfirmPlayerPosition& confirmPlayerPosition,
    Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_confirmplayerposition()->CopyFrom(confirmPlayerPosition);
    return message;
}

// 0x710100a7e0
Unk_24072b8::Message Unk_24072b8::Unk_100a7e0(const pb::PlayerPositionAsync& playerPositionAsync,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_playerpositionasync()->CopyFrom(playerPositionAsync);
    return message;
}

// 0x710100a910
Unk_24071f8::Message Unk_24071f8::Unk_100a910(const pb::Bgm& bgm, Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_bgm()->CopyFrom(bgm);
    return message;
}

// 0x710100aa40
Unk_24071f8::Message Unk_24071f8::Unk_100aa40(const pb::ContinueRequest& continueRequest,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_continuerequest()->CopyFrom(continueRequest);
    return message;
}
