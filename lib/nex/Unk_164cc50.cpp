// Scope: common
// Virtual functions of the NEX protocol 0x75's client (vtable 0x71024564b8,
// lib/nex/Unk_164c460.cpp) that forward to the protocol's calls
// (lib/nex/ddl/Calls.cpp) on its ClientProtocol, at +0x20. Their own TU: the
// calls are defined in this segment's file.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

// The call's input (lib/nex/ddl/Calls.cpp).
struct Unk_164e020;

bool Unk_164cc50(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2);
bool Unk_164ce30(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const u32& arg3, const u32& arg4, void* arg5);
bool Unk_164d0c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3);
bool Unk_164d300(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_164e020& arg2);

static nn::nex::ClientProtocol* Unk_Protocol(void* self) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + 0x20);
}

// 0x710164cc40
bool Unk_164cc40(void* self, nn::nex::ProtocolCallContext* ctx, void* arg2) {
    return Unk_164cc50(Unk_Protocol(self), ctx, arg2);
}

// 0x710164cdf0
bool Unk_164cdf0(void* self, nn::nex::ProtocolCallContext* ctx, u32 arg2, u32 arg3, u32 arg4, void* arg5) {
    return Unk_164ce30(Unk_Protocol(self), ctx, arg2, arg3, arg4, arg5);
}

// 0x710164d0b0
bool Unk_164d0b0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3) {
    return Unk_164d0c0(Unk_Protocol(self), ctx, arg2, arg3);
}

// 0x710164d2f0
bool Unk_164d2f0(u64 self, u64 ctx, u64 arg2) {
    return Unk_164d300(Unk_Protocol(reinterpret_cast<void*>(self)),
                       reinterpret_cast<nn::nex::ProtocolCallContext*>(ctx),
                       *reinterpret_cast<const Unk_164e020*>(arg2));
}
