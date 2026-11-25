// Scope: common
// Virtual functions of a NEX protocol client and of its base at offset 0x20:
// they forward to the client's calls (lib/nex/ddl/Calls.cpp) on its
// ClientProtocol, which is at +0x28 of the class and +8 of the base. The calls
// take their scalar arguments by reference, so these take them by value and
// pass their address.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

struct Unk_158f560;

bool Unk_157b450(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158f560& arg2, void* arg3, void* arg4, const u64& arg5);
bool Unk_157b710(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const u16& arg3, void* arg4);
bool Unk_157b9b0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const nn::nex::qVector<u16>& arg3, void* arg4, void* arg5);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x710157b6a0
bool Unk_157b6a0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158f560& arg2, void* arg3, void* arg4, u64 arg5) {
    return Unk_157b450(Unk_Protocol(self, 8), ctx, arg2, arg3, arg4, arg5);
}

// 0x710157b6d0
bool Unk_157b6d0(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, u16 arg3, void* arg4) {
    return Unk_157b710(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4);
}

// 0x710157b940
bool Unk_157b940(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, u16 arg3, void* arg4) {
    return Unk_157b710(Unk_Protocol(self, 8), ctx, arg2, arg3, arg4);
}

// 0x710157b980
bool Unk_157b980(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, const nn::nex::qVector<u16>& arg3, void* arg4, void* arg5) {
    return Unk_157b9b0(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4, arg5);
}

// 0x710157bc30
bool Unk_157bc30(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, const nn::nex::qVector<u16>& arg3, void* arg4, void* arg5) {
    return Unk_157b9b0(Unk_Protocol(self, 8), ctx, arg2, arg3, arg4, arg5);
}
