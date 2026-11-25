// Scope: common
// Forwarders from an object that holds a NEX protocol client at +0x140 to
// that client's calls (lib/nex/ddl/Calls.cpp).
#include <nn/nex/Call.h>

struct Unk_15a2850;

bool Unk_15a1b40(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3);
bool Unk_15a1d40(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a2850& arg2, void* arg3);

static nn::nex::ClientProtocol* Unk_15a1920_client(void* self) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + 0x140);
}

// 0x71015a1b10
bool Unk_15a1b10(void* self, nn::nex::ProtocolCallContext* ctx, u32 arg2, void* arg3) {
    return Unk_15a1b40(Unk_15a1920_client(self), ctx, arg2, arg3);
}

// 0x71015a1d30
bool Unk_15a1d30(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a2850& arg2, void* arg3) {
    return Unk_15a1d40(Unk_15a1920_client(self), ctx, arg2, arg3);
}
