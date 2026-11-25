// Scope: common
// A NEX protocol client for protocol 0x75 (vtable 0x71024564b8, derived from
// the protocol clients' base at 0x710244d6a8): its constructor and destructors,
// and its virtual functions that forward to the protocol's calls
// (lib/nex/ddl/Calls.cpp) on its ClientProtocol, at +0x20.
#include <nn/nex/Call.h>

// The calls' input (lib/nex/ddl/Calls.cpp).
struct Unk_164da60;

// The class's vtable (data: the vptr is its address point, two words in).
extern void* Unk_24564b8[];

// 0x710163a1b0: the protocol clients' base constructor, with the protocol's ID.
void Unk_163a1b0(void* self, u32 protocolId);
// 0x710163a360: the protocol clients' base destructor.
void Unk_163a360(void* self);
// 0x710164e720: the ClientProtocol's constructor, with the protocol's ID.
void Unk_164e720(nn::nex::ClientProtocol* self, u32 protocolId);
// 0x7101638220: the ClientProtocol's destructor.
void Unk_1638220(nn::nex::ClientProtocol* self);
void Unk_15b6e10(void* p);
void Unk_162f760(nn::nex::ClientProtocol* self, void* arg1);

bool Unk_164c530(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const Unk_164da60& arg3, const bool& arg4);
bool Unk_164c7c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const Unk_164da60& arg3);
bool Unk_164c9d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const Unk_164da60& arg3);

static nn::nex::ClientProtocol* Unk_Protocol(void* self) {
    return reinterpret_cast<nn::nex::ClientProtocol*>(static_cast<u8*>(self) + 0x20);
}

static void Unk_SetVtable(void* self) {
    *static_cast<void***>(self) = Unk_24564b8 + 2;
}

// 0x710164c460
void Unk_164c460(void* self) {
    const u32 protocolId = 0x75;
    Unk_163a1b0(self, protocolId);
    Unk_SetVtable(self);
    Unk_164e720(Unk_Protocol(self), protocolId);
}

// 0x710164c4a0
void Unk_164c4a0(void* self) {
    Unk_SetVtable(self);
    Unk_1638220(Unk_Protocol(self));
    Unk_163a360(self);
}

// 0x710164c4e0
void Unk_164c4e0(void* self) {
    Unk_SetVtable(self);
    Unk_1638220(Unk_Protocol(self));
    Unk_163a360(self);
    Unk_15b6e10(self);
}

// 0x710164c520
void Unk_164c520(void* self, void* arg1) {
    Unk_162f760(Unk_Protocol(self), arg1);
}

// 0x710164c780
bool Unk_164c780(u64 self, u64 ctx, u32 arg2, u64 arg3) {
    return Unk_164c530(Unk_Protocol(reinterpret_cast<void*>(self)),
                       reinterpret_cast<nn::nex::ProtocolCallContext*>(ctx), arg2,
                       *reinterpret_cast<const Unk_164da60*>(arg3), true);
}

// 0x710164cbe0
bool Unk_164cbe0(u64 self, u64 ctx, u32 arg2, u64 arg3) {
    return Unk_164c9d0(Unk_Protocol(reinterpret_cast<void*>(self)),
                       reinterpret_cast<nn::nex::ProtocolCallContext*>(ctx), arg2,
                       *reinterpret_cast<const Unk_164da60*>(arg3));
}

// 0x710164cc10
bool Unk_164cc10(u64 self, u64 ctx, u32 arg2, u64 arg3) {
    return Unk_164c7c0(Unk_Protocol(reinterpret_cast<void*>(self)),
                       reinterpret_cast<nn::nex::ProtocolCallContext*>(ctx), arg2,
                       *reinterpret_cast<const Unk_164da60*>(arg3));
}
