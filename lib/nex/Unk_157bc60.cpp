// Scope: common
// Virtual functions of a NEX protocol client: they forward to the client's
// calls (lib/nex/ddl/Calls.cpp) on its ClientProtocol, which is at +0x28 of
// the class and +8 of its base.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

bool Unk_157bca0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u16& arg2, const u64& arg3,
                 const bool& arg4);
bool Unk_157bf80(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u16& arg2, const bool& arg3);
bool Unk_157c200(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, void* arg3);
bool Unk_157c430(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 void* arg3, void* arg4);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x710157bc60
bool Unk_157bc60(void* self, nn::nex::ProtocolCallContext* ctx, u16 arg2, u64 arg3, bool arg4) {
    return Unk_157bca0(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4);
}

// 0x710157bf00
bool Unk_157bf00(void* self, nn::nex::ProtocolCallContext* ctx, u16 arg2, u64 arg3, bool arg4) {
    return Unk_157bca0(Unk_Protocol(self, 8), ctx, arg2, arg3, arg4);
}

// 0x710157bf40
bool Unk_157bf40(void* self, nn::nex::ProtocolCallContext* ctx, u16 arg2, bool arg3) {
    return Unk_157bf80(Unk_Protocol(self, 0x28), ctx, arg2, arg3);
}

// 0x710157c190
bool Unk_157c190(void* self, nn::nex::ProtocolCallContext* ctx, u16 arg2, bool arg3) {
    return Unk_157bf80(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x710157c1d0
bool Unk_157c1d0(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, void* arg3) {
    return Unk_157c200(Unk_Protocol(self, 0x28), ctx, arg2, arg3);
}

// 0x710157c3f0
bool Unk_157c3f0(void* self, nn::nex::ProtocolCallContext* ctx, u64 arg2, void* arg3) {
    return Unk_157c200(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x710157c420
bool Unk_157c420(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3,
                 void* arg4) {
    return Unk_157c430(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4);
}
