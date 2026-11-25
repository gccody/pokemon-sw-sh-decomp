// Scope: common
// Virtual functions of a NEX protocol client: they forward to the client's
// calls (lib/nex/ddl/Calls.cpp) on its ClientProtocol, which is at +0x28 of
// the class and +8 of its base.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

struct Unk_1591a00;

bool Unk_157c430(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 void* arg3, void* arg4);
bool Unk_157c690(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2,
                 void* arg3, void* arg4);
bool Unk_157c8f0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591a00& arg2);
bool Unk_157cae0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx,
                 const nn::nex::qVector<Unk_1591a00>& arg2);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x710157c670
bool Unk_157c670(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3,
                 void* arg4) {
    return Unk_157c430(Unk_Protocol(self, 8), ctx, arg2, arg3, arg4);
}

// 0x710157c680
bool Unk_157c680(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3,
                 void* arg4) {
    return Unk_157c690(Unk_Protocol(self, 0x28), ctx, arg2, arg3, arg4);
}

// 0x710157c8d0
bool Unk_157c8d0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3,
                 void* arg4) {
    return Unk_157c690(Unk_Protocol(self, 8), ctx, arg2, arg3, arg4);
}

// 0x710157c8e0
bool Unk_157c8e0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591a00& arg2) {
    return Unk_157c8f0(Unk_Protocol(self, 0x28), ctx, arg2);
}

// 0x710157cad0
bool Unk_157cad0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_1591a00>& arg2) {
    return Unk_157cae0(Unk_Protocol(self, 0x28), ctx, arg2);
}
