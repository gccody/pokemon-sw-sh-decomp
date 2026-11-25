// Scope: common
// Virtual functions of a NEX protocol client: they forward to the client's
// calls (lib/nex/ddl/Calls.cpp) on its ClientProtocol, which is at +0x28 of
// the class and +8 of its base.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>
#include "ddl/Streams.h"

bool Unk_15774d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a0f0& arg2);
bool Unk_15776d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a2d0& arg2);
bool Unk_1577970(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158a0f0>& arg3, const bool& arg4,
                 void* arg5);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x71015776b0
bool Unk_15776b0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a0f0& arg2) {
    return Unk_15774d0(Unk_Protocol(self, 8), ctx, arg2);
}

// 0x71015776c0
bool Unk_15776c0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a2d0& arg2) {
    return Unk_15776d0(Unk_Protocol(self, 0x28), ctx, arg2);
}

// NON_MATCHING: the original destroys the vector's elements through their
// vtables (slot 0); Unk_158a0f0 in the generated lib/nex/ddl/Streams.h isn't
// declared polymorphic, so here the destructor is a direct call.
// 0x71015778b0
bool Unk_15778b0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 const Unk_158a0f0& arg3, bool arg4, void* arg5) {
    nn::nex::qVector<Unk_158a0f0> items;
    items.push_back(arg3);
    return Unk_1577970(Unk_Protocol(self, 0x28), ctx, arg2, items, arg4, arg5);
}
