// Scope: common
//
// The battle's net peer (Unk_8974a0.h): sending a TrainerAction to every peer,
// and whether a client's came. Part of the segment 0x7100891a20-0x7100898dd0
// (one or more TUs). Placeholder names: rename once the classes are known.
#include "battle/battle_logic/source/net/Unk_8974a0.h"

#include "gflnet3/src/p2p/Unk_6b8ad0.h"

// The battle's command channel (Unk_89bca0.cpp), with what's used here.
class Unk_23b84d0 {
public:
    using Message = Unk_6b8ad0_Message<pb::BtlCmdDataHolder>;

    Message Unk_89d700(const pb::TrainerAction& trainerAction, Unk_239a418_Allocator* heap);
    bool Unk_89d340(const Message& message, u64 peer);
};

// An array of peers (pointer, count).
struct Unk_6d7ab0_Peers {
    const u64* begin() const { return field_0; }
    const u64* end() const { return field_0 + field_8; }

    const u64* field_0;
    u64 field_8;
};
PKMN_SIZE_ASSERT(Unk_6d7ab0_Peers, 0x10);

// The session's peers, at +0x40.
struct Unk_6d7ab0_120 {
    u8 _0[0x40];
    Unk_6d7ab0_Peers field_40;
};
PKMN_OFFSET_ASSERT(Unk_6d7ab0_120, field_40, 0x40);

struct Unk_6d7ab0;
Unk_6d7ab0_120* Unk_6d7ab0_getField120Ptr(Unk_6d7ab0* self);

// 0x71008969d0
bool Unk_23b7ee8::Unk_8969d0(u32 clientId) {
    if (field_148 == nullptr)
        return false;
    Unk_6b8ad0_Message<pb::TrainerAction> trainerAction(field_80);
    trainerAction->set_clientid(clientId);
    return field_148->Unk_896b10(*trainerAction.get());
}

// 0x7100896b10
bool Unk_23b7ee8_148::Unk_896b10(const pb::TrainerAction& trainerAction) {
    if (field_2b0 == nullptr)
        return false;
    const Unk_6d7ab0_120* session =
        Unk_6d7ab0_getField120Ptr(reinterpret_cast<Unk_6d7ab0*>(field_2a0));
    for (u64 peer : session->field_40) {
        Unk_23b84d0* channel = field_2b0;
        Unk_23b84d0::Message message = channel->Unk_89d700(trainerAction, field_78);
        channel->Unk_89d340(message, peer);
    }
    return true;
}

// 0x7100896c30
bool Unk_896c30(u64 peer, u32 clientId) {
    const Unk_23b7ee8* self = reinterpret_cast<const Unk_23b7ee8*>(peer);
    if (clientId < 8)
        return self->field_360[clientId] != 0;
    return false;
}
