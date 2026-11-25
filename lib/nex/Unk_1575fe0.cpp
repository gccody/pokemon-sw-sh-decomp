// Scope: common
// Virtual functions of the NEX protocol client's base at offset 0x20 of vtable
// group 0x710244adf8 (vtable 0x710244b100): they forward to the client's calls
// (lib/nex/ddl/Calls.cpp) on its ClientProtocol, at +8 of the base.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

// The call's input (0x130 bytes, as in lib/nex/ddl/Calls.cpp).
struct Unk_158c660 {
    u8 _0[0x130];
};
PKMN_SIZE_ASSERT(Unk_158c660, 0x130);

bool Unk_1575fe0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2);
bool Unk_1576200(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c660& arg2, void* arg3);
bool Unk_1576400(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const Unk_158c660& arg3);

static nn::nex::ClientProtocol* Unk_Protocol(void* self) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + 8);
}

// 0x71015761f0
bool Unk_15761f0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2) {
    return Unk_1575fe0(Unk_Protocol(self), ctx, arg2);
}

// 0x71015763f0
bool Unk_15763f0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c660& arg2, void* arg3) {
    return Unk_1576200(Unk_Protocol(self), ctx, arg2, arg3);
}

// 0x7101576610
bool Unk_1576610(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, const Unk_158c660& arg3) {
    return Unk_1576400(Unk_Protocol(self), ctx, arg2, arg3);
}
