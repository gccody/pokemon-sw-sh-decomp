// Scope: common
// Virtual functions of a NEX protocol client and of its base at offset 0x20:
// they forward to the client's calls (lib/nex/ddl/Calls.cpp) on its
// ClientProtocol, which is at +0x28 of the class and +8 of the base.
#include <nn/nex/Call.h>

struct Unk_158ac40;
struct Unk_158ad60;
struct Unk_1591630;

bool Unk_157ae40(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ac40& arg2, void* arg3);
bool Unk_157b050(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ad60& arg2, void* arg3);
bool Unk_157b260(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591630& arg2);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x710157b030
bool Unk_157b030(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ac40& arg2, void* arg3) {
    return Unk_157ae40(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x710157b040
bool Unk_157b040(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ad60& arg2, void* arg3) {
    return Unk_157b050(Unk_Protocol(self, 0x28), ctx, arg2, arg3);
}

// 0x710157b240
bool Unk_157b240(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ad60& arg2, void* arg3) {
    return Unk_157b050(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x710157b250
bool Unk_157b250(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591630& arg2) {
    return Unk_157b260(Unk_Protocol(self, 0x28), ctx, arg2);
}

// 0x710157b440
bool Unk_157b440(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591630& arg2) {
    return Unk_157b260(Unk_Protocol(self, 8), ctx, arg2);
}
