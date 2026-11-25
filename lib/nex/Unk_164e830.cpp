// Scope: common
// NEX 4.6.8: the D0s of the "LocationData" and "SubscriptionData" data
// classes' fields classes (lib/nex/Unk_164e150.h; vtables 0x71024566e8,
// 0x7102456638, and 0x7102456798, a class derived from SubscriptionData's
// fields), and the D0, the result dispatch (slot 21) and the factory (slot
// 22) of their protocol's client (vtable 0x7102456528).
#include "Unk_164e150.h"

// 0x7101630ba0: the method ID of a response.
u32 Unk_1630ba0(nn::nex::ByteStream* stream);
// 0x7101638220: the ClientProtocol's destructor.
void Unk_1638220(nn::nex::ClientProtocol* self);
// 0x710162efb0: reports an unexpected result.
void Unk_162efb0(const Unk_15bbc10& result);

// The protocol's result handlers (lib/nex/ddl/Calls.cpp stores them), each
// called with the response and the client's argument.
extern Unk_Handlers Unk_27f9b68;
using Unk_Handler = void (*)(nn::nex::ByteStream* response, void* arg);

// 0x710164ec40
void Unk_164ec40(Unk_164da60* self) {
    self->~Unk_164da60();
    Unk_15b6e10(self);
}

// 0x710164ec80
void Unk_164ec80(Unk_164e020* self) {
    self->~Unk_164e020();
    Unk_15b6e10(self);
}

// 0x710164ecc0
void Unk_164ecc0(nn::nex::ClientProtocol* self) {
    Unk_1638220(self);
    Unk_15b6e10(self);
}

// 0x710164ed40
void Unk_164ed40(Unk_164da60* self) {
    self->~Unk_164da60();
    Unk_15b6e10(self);
}

// 0x710164eb80: calls the handler of the response's method.
void Unk_164eb80(nn::nex::ClientProtocol* self, nn::nex::ByteStream* response, void* arg) {
    int method = Unk_1630ba0(response) & 0x7fff;
    if (method < 1 || method > 17) {
        Unk_162efb0(Unk_15bbc10(0x80010002));
        return;
    }
    Unk_Handler handler = reinterpret_cast<Unk_Handler>(Unk_27f9b68.m_handlers[method - 1]);
    if (handler != nullptr) {
        handler(response, arg);
    }
}

// 0x710164ecf0
nn::nex::ClientProtocol* Unk_164ecf0(nn::nex::ClientProtocol* self) {
    nn::nex::ClientProtocol* client = static_cast<nn::nex::ClientProtocol*>(Unk_15b6dc0(0x90));
    if (client != nullptr) {
        Unk_164e720_init(client, 0);
    }
    return client;
}
