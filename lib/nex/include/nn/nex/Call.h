#pragma once
// What NEX's protocol client calls use (lib/nex/ddl/Calls.cpp): the classes are
// NEX's (RTTI names); the functions, members and structs without a name in the
// executable are placeholders.
#include <nn/nex/InstanceTable.h>
#include <nn/nex/Message.h>
#include <nn/nex/String.h>

namespace nn {
namespace nex {

class ProtocolCallContext;

// N2nn3nex14ClientProtocolE: the base of the protocols' clients (the calls
// read these members of every client).
class ClientProtocol {
public:
    u8 _0[0x48];
    u16 m_protocolId;
    u8 _4a[0x26];
    bool m_canDefer;  // the protocol can send a call once the lock is released
};
PKMN_OFFSET_ASSERT(ClientProtocol, m_protocolId, 0x48);
PKMN_OFFSET_ASSERT(ClientProtocol, m_canDefer, 0x70);

}  // namespace nex
}  // namespace nn

// 0x71015bbc10: a call's result code (with where it was made).
struct Unk_15bbc10 {
    Unk_15bbc10(const u32& code);

    u32 m_code;
    const char* m_file;
    u32 m_line;
};
PKMN_SIZE_ASSERT(Unk_15bbc10, 0x18);

// 0x7101630a20: gives the message the context's call ID (false: no context).
bool Unk_1630a20(nn::nex::Message* msg, nn::nex::ProtocolCallContext* ctx);
// 0x7101630ac0: one of the call's results, where the response's is copied.
void Unk_1630ac0(nn::nex::ProtocolCallContext* ctx, void* result);
// 0x7101630b90
bool Unk_1630b90(nn::nex::ClientProtocol* self, u32 flag);
// 0x710162f1a0: sends the message.
bool Unk_162f1a0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, nn::nex::Message* msg);
// 0x71015c9360: ends the call with a result.
void Unk_15c9360(nn::nex::ProtocolCallContext* ctx, Unk_15bbc10 result);

void Unk_162cec0_write(nn::nex::ByteStream* s, const nn::nex::String& v);
void Unk_15c8ca0_write(nn::nex::ByteStream* s, const bool& v);

// A protocol's result handlers, one per method (indexed by method ID - 1).
struct Unk_Handlers {
    void (*m_handlers[128])();
};
