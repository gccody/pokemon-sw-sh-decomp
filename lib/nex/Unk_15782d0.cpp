// Scope: common
// Thunks to NEX protocol clients' calls (lib/nex/ddl/Calls.cpp): each moves
// `this` to the ClientProtocol it holds (at 0x8 or 0x28) and tail-calls the
// call. The objects and the calls are placeholders: nothing names them.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>
#include "ddl/Streams.h"

bool Unk_15782d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<u64>& arg2, const Unk_158a970& arg3, void* arg4, void* arg5);
bool Unk_1578570(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<Unk_158a970>& arg2, void* arg3, void* arg4);
struct Unk_1590930;
bool Unk_15787e0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2,
                 void* arg3);
bool Unk_15789f0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2,
                 void* arg3);

static nn::nex::ClientProtocol* ProtocolAt(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x7101578550
bool Unk_1578550(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 const Unk_158a970& arg3, void* arg4, void* arg5) {
    return Unk_15782d0(ProtocolAt(self, 0x8), ctx, arg2, arg3, arg4, arg5);
}

// 0x7101578560
bool Unk_1578560(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a970>& arg2,
                 void* arg3, void* arg4) {
    return Unk_1578570(ProtocolAt(self, 0x28), ctx, arg2, arg3, arg4);
}

// 0x71015787c0
bool Unk_15787c0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a970>& arg2,
                 void* arg3, void* arg4) {
    return Unk_1578570(ProtocolAt(self, 0x8), ctx, arg2, arg3, arg4);
}

// 0x71015787d0
bool Unk_15787d0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2, void* arg3) {
    return Unk_15787e0(ProtocolAt(self, 0x28), ctx, arg2, arg3);
}

// 0x71015789d0
bool Unk_15789d0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2, void* arg3) {
    return Unk_15787e0(ProtocolAt(self, 0x8), ctx, arg2, arg3);
}

// 0x71015789e0
bool Unk_15789e0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2, void* arg3) {
    return Unk_15789f0(ProtocolAt(self, 0x28), ctx, arg2, arg3);
}
