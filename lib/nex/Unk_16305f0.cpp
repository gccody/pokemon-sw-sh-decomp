// Scope: common
// NEX 4.6.8: the data classes' base (type name "Data", lib/nex/Unk_164e150.h's
// Unk_162fa40): its stream functions and virtual functions (vtable
// 0x7102454410: clone, type name, type checks, stream-out and stream-in);
// then a message's header (the protocol's and the method's IDs), the call
// context's ID and results, and a client protocol's flag check.
#include <algorithm>

#include <nn/nex/ByteStream.h>
#include <nn/nex/Call.h>
#include <nn/nex/Message.h>
#include <nn/nex/String.h>

#include "Unk_164e150.h"
#include "Unk_16305f0.h"

using nn::nex::ReadField;
using nn::nex::ReadLength;

// 0x71015bc5d0: whether two C strings are equal (a null one is "").
bool Unk_15bc5d0(const char* a, const char* b);
// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);
// 0x71015c5370: whether the context can make a call.
bool Unk_15c5370(nn::nex::ProtocolCallContext* ctx);

// 0x7101630760: the base's stream-out: its header only (it has no fields).
void Unk_1630760_write(nn::nex::ByteStream* s, const Unk_162fa40& v) {
    if (s->m_noHeader) return;
    u8 version = v.m_baseVersion;
    s->Write(std::min(version, (u8)0));
    s->Write((u32)0);
}

// 0x71016307d0: the base's stream-in (its version, and its length skipped).
void Unk_16307d0(nn::nex::ByteStream* s, void* v) {
    Unk_162fa40& data = *static_cast<Unk_162fa40*>(v);
    data.m_baseVersion = 0;
    if (s->m_noHeader) return;
    ReadField(s, data.m_baseVersion);
    if (s->m_error) return;
    u32 length;
    ReadLength(s, length);
}

// 0x7101630860: a copy (the base's assignment, 0x7101630750, copies nothing).
// NON_MATCHING: the original inlines the constructor (0x710162fa40, defined in this TU
// originally); lib/nex/Unk_164e150.h declares it out of line, and it isn't in this file.
Unk_162fa40* Unk_1630860(const Unk_162fa40* self) {
    return new Unk_162fa40;
}

// 0x7101630890
nn::nex::String Unk_1630890(const Unk_162fa40* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, "Data", static_cast<size_t>(-1));
    return name;
}

// 0x71016308d0
bool Unk_16308d0(const Unk_162fa40* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "Data");
}

// 0x71016308f0
void Unk_16308f0(const Unk_162fa40* self, nn::nex::ByteStream* s) {
    Unk_1630760_write(s, *self);
}

// 0x7101630960
void Unk_1630960(Unk_162fa40* self, nn::nex::ByteStream* s) {
    Unk_16307d0(s, self);
}

// 0x71016309f0: the base's type check ("Data").
bool Unk_16309f0(const void* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "Data");
}

// 0x7101630a20
bool Unk_1630a20(nn::nex::Message* msg, nn::nex::ProtocolCallContext* ctx) {
    if (!Unk_15c5370(ctx)) return false;
    u32 callId = ctx->m_callId;
    msg->Write(callId);
    return true;
}

// 0x7101630a90
void nn::nex::Message::Unk_1630a90(u32 methodId) {
    Write(methodId);
}

// 0x7101630ac0
void Unk_1630ac0(nn::nex::ProtocolCallContext* ctx, void* result) {
    ctx->m_results.push_back(result);
}

// 0x7101630b10: the protocol's ID in 7 bits (0x7f: in the u16 after it), with
// the top bit set for a request.
// NON_MATCHING: the original tests all of `request`'s 32 bits (cmp w2, #0): its
// parameter is a u32, which the bool of the name (and of the calls) doesn't give.
void nn::nex::Message::Unk_1630b10(u16 protocolId, bool request) {
    u8 flag = request ? 0x80 : 0;
    if (protocolId < 0x7f) {
        Write(static_cast<u8>(flag | (protocolId & 0x7f)));
    } else {
        Write(static_cast<u8>(flag | 0x7f));
        Write(protocolId);
    }
}

// The client protocol's flags (lib/nex/include/nn/nex/Call.h's ClientProtocol
// leaves them out).
struct Unk_1630b90_ClientProtocol {
    u8 _0[0x60];
    u32 m_flags;
};
PKMN_OFFSET_ASSERT(Unk_1630b90_ClientProtocol, m_flags, 0x60);

// 0x7101630b90: whether all of `flag`'s bits are set.
bool Unk_1630b90(nn::nex::ClientProtocol* self, u32 flag) {
    const auto* protocol = reinterpret_cast<const Unk_1630b90_ClientProtocol*>(self);
    return (protocol->m_flags & flag) == flag;
}
