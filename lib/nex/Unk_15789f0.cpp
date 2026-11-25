// Scope: common
// Thunks to NEX protocol clients' calls (lib/nex/ddl/Calls.cpp): each moves
// `this` to the ClientProtocol it holds (at 0x8 or 0x28) and tail-calls the
// call. The objects and the calls are placeholders: nothing names them.
#include <nn/nex/Call.h>
#include "ddl/Streams.h"

struct Unk_1590930;
struct Unk_158ab60;
bool Unk_15789f0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2,
                 void* arg3);
bool Unk_1578c00(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ab60& arg2,
                 void* arg3);
bool Unk_1578e10(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2,
                 void* arg3, void* arg4);
bool Unk_1579030(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2,
                 void* arg3, void* arg4);

static nn::nex::ClientProtocol* ProtocolAt(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x7101578be0
bool Unk_1578be0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2, void* arg3) {
    return Unk_15789f0(ProtocolAt(self, 0x8), ctx, arg2, arg3);
}

// 0x7101578bf0
bool Unk_1578bf0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ab60& arg2, void* arg3) {
    return Unk_1578c00(ProtocolAt(self, 0x28), ctx, arg2, arg3);
}

// 0x7101578df0
bool Unk_1578df0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ab60& arg2, void* arg3) {
    return Unk_1578c00(ProtocolAt(self, 0x8), ctx, arg2, arg3);
}

// 0x7101578e00
bool Unk_1578e00(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2, void* arg3, void* arg4) {
    return Unk_1578e10(ProtocolAt(self, 0x28), ctx, arg2, arg3, arg4);
}

// 0x7101579010
bool Unk_1579010(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2, void* arg3, void* arg4) {
    return Unk_1578e10(ProtocolAt(self, 0x8), ctx, arg2, arg3, arg4);
}

// 0x7101579020
bool Unk_1579020(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2, void* arg3, void* arg4) {
    return Unk_1579030(ProtocolAt(self, 0x28), ctx, arg2, arg3, arg4);
}
