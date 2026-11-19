// Scope: common
//
// The trade's Pokemon channel (prog/network/net_contents/source/trade/common/pokemon_trade): it
// sends and receives PokemonTradeDataHolder messages, on gflnet3's p2p channel
// (src/gflnet3/src/p2p/Unk_23a3578.h). The segment 0x7101038350-0x710103c3e0 (one or more TUs).
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_23a3578.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"
#include "pokemon_trade_data_holder.pb.h"

namespace pb = net_contents::trade::common::pokemon_trade::protocol_buffers;

// What the Pokemon trade channel hands the messages it receives to, with the
// peer they're from.
class Unk_240a2c8_Listener {
public:
    virtual void vf0(const pb::Pokemon& pokemon, u64 peer);
};

// The Pokemon trade channel (vtable 0x710240a2d8).
class Unk_240a2c8 : public Unk_23a3578 {
public:
    using Message = Unk_6b8ad0_Message<pb::PokemonTradeDataHolder>;

    ~Unk_240a2c8() override;
    void vf8(const void* data, int size, u64 peer) override;

    Message Unk_103c230(const pb::Pokemon& pokemon, Unk_239a418_Allocator* heap);

    Unk_240a2c8_Listener* field_168;
};
PKMN_OFFSET_ASSERT(Unk_240a2c8, field_168, 0x168);

// 0x710103b7e0
void Unk_240a2c8::vf8(const void* data, int size, u64 peer) {
    if (field_168 == nullptr)
        return;
    Message message(field_8);
    message->ParseFromArray(data, size);
    switch (message->message_case()) {
        case pb::PokemonTradeDataHolder::kPokemon:
            field_168->vf0(message.get()->pokemon(), peer);
            break;
        default:
            break;
    }
}

// 0x710103c230
Unk_240a2c8::Message Unk_240a2c8::Unk_103c230(const pb::Pokemon& pokemon,
                                              Unk_239a418_Allocator* heap) {
    Message message(heap);
    message->mutable_pokemon()->CopyFrom(pokemon);
    return message;
}
