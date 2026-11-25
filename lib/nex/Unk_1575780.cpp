// Scope: common
// Virtual functions of the NEX protocol client in vtable group 0x710244adf8
// (and of its base at offset 0x20, vtable 0x710244b100): they forward to the
// client's calls (lib/nex/ddl/Calls.cpp) on its ClientProtocol, which is at
// +0x28 of the class and +8 of the base.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

struct Unk_158a460;
struct Unk_158a540;
struct Unk_158c980;

// The call's input (0x130 bytes, as in lib/nex/ddl/Calls.cpp); 0x7101574e80
// resizes the list at 0x118 before it's sent.
struct Unk_158c660 {
    u8 _0[0x118];
    u8 field_118[0x18];
};
PKMN_SIZE_ASSERT(Unk_158c660, 0x130);

bool Unk_1575780(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c660& arg2, void* arg3);
bool Unk_15759d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c980& arg2, void* arg3);
bool Unk_1575be0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a460& arg2);
bool Unk_1575de0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a540& arg2);
bool Unk_1575fe0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2);
void Unk_1574e80(void* self, void* list);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x7101575970
bool Unk_1575970(void* self, nn::nex::ProtocolCallContext* ctx, Unk_158c660& arg2, void* arg3) {
    Unk_1574e80(self, arg2.field_118);
    return Unk_1575780(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x71015759c0
bool Unk_15759c0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c980& arg2, void* arg3) {
    return Unk_15759d0(Unk_Protocol(self, 0x28), ctx, arg2, arg3);
}

// 0x7101575bc0
bool Unk_1575bc0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c980& arg2, void* arg3) {
    return Unk_15759d0(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x7101575bd0
bool Unk_1575bd0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a460& arg2) {
    return Unk_1575be0(Unk_Protocol(self, 0x28), ctx, arg2);
}

// 0x7101575dc0
bool Unk_1575dc0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a460& arg2) {
    return Unk_1575be0(Unk_Protocol(self, 8), ctx, arg2);
}

// 0x7101575dd0
bool Unk_1575dd0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a540& arg2) {
    return Unk_1575de0(Unk_Protocol(self, 0x28), ctx, arg2);
}

// 0x7101575fc0
bool Unk_1575fc0(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a540& arg2) {
    return Unk_1575de0(Unk_Protocol(self, 8), ctx, arg2);
}

// 0x7101575fd0
bool Unk_1575fd0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2) {
    return Unk_1575fe0(Unk_Protocol(self, 0x28), ctx, arg2);
}
