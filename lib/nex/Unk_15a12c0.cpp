// Scope: common
// Forwarders from an object that holds a NEX protocol client at +0x140 to
// that client's calls (lib/nex/ddl/Calls.cpp).
#include <nn/nex/Call.h>

struct Unk_15a2c60;
struct Unk_15a8db0;

bool Unk_15a1500(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a2c60& arg2, void* arg3);
bool Unk_15a1720(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3);
bool Unk_15a1920(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a8db0& arg2, void* arg3);

static nn::nex::ClientProtocol* Unk_15a12c0_client(void* self) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + 0x140);
}

// 0x71015a14f0
bool Unk_15a14f0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a2c60& arg2, void* arg3) {
    return Unk_15a1500(Unk_15a12c0_client(self), ctx, arg2, arg3);
}

// 0x71015a16f0
bool Unk_15a16f0(void* self, nn::nex::ProtocolCallContext* ctx, u32 arg2, void* arg3) {
    return Unk_15a1720(Unk_15a12c0_client(self), ctx, arg2, arg3);
}

// 0x71015a1910
bool Unk_15a1910(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a8db0& arg2, void* arg3) {
    return Unk_15a1920(Unk_15a12c0_client(self), ctx, arg2, arg3);
}
