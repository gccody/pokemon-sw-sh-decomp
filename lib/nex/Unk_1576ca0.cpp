// Scope: common
// Virtual functions of a NEX protocol client (as in lib/nex/Unk_1575780.cpp):
// they forward to the client's calls (lib/nex/ddl/Calls.cpp) on its
// ClientProtocol, which is at +0x28 of the class and +8 of its base at 0x20.
#include <nn/nex/Call.h>
#include <nn/nex/RootObject.h>
#include <nn/nex/qVector.h>

struct Unk_158a0f0;
struct Unk_158a620;

// The base of Unk_158a880, after its vtable 0x71023a2800 (whose destructor
// Unk_158a880's vtable shares): it holds the version byte.
struct Unk_23a27f0 : nn::nex::RootObject {
    Unk_23a27f0() : m_version(0) {}

    u8 m_version;
};
PKMN_OFFSET_ASSERT(Unk_23a27f0, m_version, 0x8);

// A call's input (as in lib/nex/ddl/Streams.h): a NEX data object with the
// vtable 0x710244c1a8.
struct Unk_158a880 : Unk_23a27f0 {
    Unk_158a880() : field_10(0), field_18(0) {}
    // copies the fields one by one (a memcpy would make the loop in
    // 0x7101577370 reload the list's end after each store)
    Unk_158a880(const Unk_158a880& other)
        : Unk_23a27f0(other), field_10(other.field_10), field_18(other.field_18) {}

    u64 field_10;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_158a880, 0x20);
PKMN_OFFSET_ASSERT(Unk_158a880, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a880, field_18, 0x18);

bool Unk_1576ca0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a620& arg2);
bool Unk_1576ea0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a880& arg2);
bool Unk_1577110(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a880>& arg2, const bool& arg3, void* arg4);
bool Unk_15774d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a0f0& arg2);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x7101576e80
bool Unk_1576e80(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a620& arg2) {
    return Unk_1576ca0(Unk_Protocol(self, 8), ctx, arg2);
}

// 0x7101576e90
bool Unk_1576e90(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a880& arg2) {
    return Unk_1576ea0(Unk_Protocol(self, 0x28), ctx, arg2);
}

// 0x7101577080
bool Unk_1577080(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a880& arg2) {
    return Unk_1576ea0(Unk_Protocol(self, 8), ctx, arg2);
}

// 0x7101577090: the call on an input made from one ID.
bool Unk_1577090(void* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2) {
    Unk_158a880 item;
    item.field_10 = arg2;
    return Unk_1576ea0(Unk_Protocol(self, 0x28), ctx, item);
}

// 0x71015770e0
bool Unk_15770e0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a880>& arg2, bool arg3, void* arg4) {
    return Unk_1577110(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4);
}

// 0x7101577370: the call on a list of inputs made from IDs.
// NON_MATCHING: the inlined copy of each element stores its fields in another
// order (the original's vtable store comes last and takes the end pointer's
// post-increment); the loop, the frame and the calls match.
bool Unk_1577370(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, bool arg3, void* arg4) {
    nn::nex::qVector<Unk_158a880> list;
    Unk_158a880 item;
    for (nn::nex::qVector<u64>::const_iterator it = arg2.begin(); it != arg2.end(); ++it) {
        item.field_10 = *it;
        list.push_back(item);
    }
    return Unk_1577110(Unk_Protocol(self, 0x28), ctx, list, arg3, arg4);
}

// 0x71015774c0
bool Unk_15774c0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a0f0& arg2) {
    return Unk_15774d0(Unk_Protocol(self, 0x28), ctx, arg2);
}
