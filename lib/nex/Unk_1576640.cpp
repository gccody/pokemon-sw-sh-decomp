// Scope: common
// Virtual functions of a NEX protocol client (as in lib/nex/Unk_1575780.cpp):
// they forward to the client's calls (lib/nex/ddl/Calls.cpp) on its
// ClientProtocol, which is at +0x28 of the class and +8 of its base at 0x20.
#include <nn/nex/Call.h>
#include <nn/nex/String.h>
#include <nn/nex/qVector.h>

struct Unk_158a620;

// A call's input (0x130 bytes, as in lib/nex/ddl/Calls.cpp): a NEX data
// object, destroyed through its vtable's slot 0.
struct Unk_158c660 {
    Unk_158c660(const Unk_158c660& other);
    virtual ~Unk_158c660();

    u8 _8[0x128];
};
PKMN_SIZE_ASSERT(Unk_158c660, 0x130);

// A call's input (as in lib/nex/ddl/Streams.h); 0x7101574e80 resizes the list
// at 0x28 before it's sent.
struct Unk_158cb70 {
    u8 _0[0x28];
    nn::nex::qVector<nn::nex::String> field_28;
};
PKMN_SIZE_ASSERT(Unk_158cb70, 0x40);
PKMN_OFFSET_ASSERT(Unk_158cb70, field_28, 0x28);

bool Unk_15724c0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, bool arg3, void* arg4);
bool Unk_1576640(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158c660>& arg3, const bool& arg4, void* arg5);
bool Unk_1576a50(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158cb70& arg2, void* arg3);
bool Unk_1576ca0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a620& arg2);
void Unk_1574e80(void* self, void* list);

static nn::nex::ClientProtocol* Unk_Protocol(void* self, u32 offset) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + offset);
}

// 0x7101576930: the call on a list of one input.
bool Unk_1576930(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const Unk_158c660& arg3, bool arg4, void* arg5) {
    nn::nex::qVector<Unk_158c660> list;
    list.push_back(arg3);
    return Unk_1576640(Unk_Protocol(self, 8), ctx, arg2, list, arg4, arg5);
}

// 0x71015769f0: the base at 0x20's entry to the class's 0x71015724c0.
bool Unk_15769f0(void* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, bool arg3, void* arg4) {
    return Unk_15724c0(static_cast<u8*>(self) - 0x20, ctx, arg2, arg3, arg4);
}

// 0x7101576a00
bool Unk_1576a00(void* self, nn::nex::ProtocolCallContext* ctx, Unk_158cb70& arg2, void* arg3) {
    Unk_1574e80(self, &arg2.field_28);
    return Unk_1576a50(Unk_Protocol(self, 0x28), ctx, arg2, arg3);
}

// 0x7101576c40
bool Unk_1576c40(void* self, nn::nex::ProtocolCallContext* ctx, Unk_158cb70& arg2, void* arg3) {
    Unk_1574e80(self, &arg2.field_28);
    return Unk_1576a50(Unk_Protocol(self, 8), ctx, arg2, arg3);
}

// 0x7101576c90
bool Unk_1576c90(void* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a620& arg2) {
    return Unk_1576ca0(Unk_Protocol(self, 0x28), ctx, arg2);
}
