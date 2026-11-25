// Scope: common
// Virtual functions of a NEX protocol client: they forward to the client's
// calls (lib/nex/ddl/Calls.cpp) on its ClientProtocol, which is at +0x28 of
// the class and +8 of its base.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>
#include "ddl/Streams.h"

bool Unk_1577970(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158a0f0>& arg3, const bool& arg4,
                 void* arg5);
bool Unk_1577d20(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158a2d0>& arg3, const bool& arg4,
                 void* arg5);
bool Unk_15780c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a970& arg2,
                 void* arg3);
bool Unk_15782d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<u64>& arg2, const Unk_158a970& arg3, void* arg4, void* arg5);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// NON_MATCHING: the original destroys the vector's elements through their
// vtables (slot 0); Unk_158a2d0 in the generated lib/nex/ddl/Streams.h isn't
// declared polymorphic, so here the destructor is a direct call.
// 0x7101577c60
bool Unk_1577c60(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 const Unk_158a2d0& arg3, bool arg4, void* arg5) {
    nn::nex::qVector<Unk_158a2d0> items;
    items.push_back(arg3);
    return Unk_1577d20(Unk_Protocol(self, 0x28), ctx, arg2, items, arg4, arg5);
}

// NON_MATCHING: the original has no destructor call for the empty vector:
// its callee was in the same TU, so clang could see it doesn't change the
// vector. Here the callee is in lib/nex/ddl/Calls.cpp.
// 0x7101578010
bool Unk_1578010(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a0f0>& arg2,
                 bool arg3, void* arg4) {
    return Unk_1577970(Unk_Protocol(self, 0x28), ctx, nn::nex::qVector<u64>(), arg2, arg3, arg4);
}

// NON_MATCHING: the original has no destructor call for the empty vector:
// its callee was in the same TU, so clang could see it doesn't change the
// vector. Here the callee is in lib/nex/ddl/Calls.cpp.
// 0x7101578060
bool Unk_1578060(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a2d0>& arg2,
                 bool arg3, void* arg4) {
    return Unk_1577d20(Unk_Protocol(self, 0x28), ctx, nn::nex::qVector<u64>(), arg2, arg3, arg4);
}

// 0x71015780b0
bool Unk_15780b0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a970& arg2, void* arg3) {
    return Unk_15780c0(Unk_Protocol(self, 0x28), ctx, arg2, arg3);
}

// 0x71015782b0
bool Unk_15782b0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a970& arg2, void* arg3) {
    return Unk_15780c0(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x71015782c0
bool Unk_15782c0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 const Unk_158a970& arg3, void* arg4, void* arg5) {
    return Unk_15782d0(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4, arg5);
}
