// Scope: common
// NEX 4.6.8's matchmaking protocols, continued (lib/nex/Unk_15b36f0.cpp):
// three result handlers of their calls (lib/nex/ddl/Calls.cpp stores them),
// the result dispatch (slot 21) of the clients in vtable groups 0x710244e370
// and 0x710244e440, the second one's constructor, and destructors of the
// "Gathering" class (lib/nex/Unk_15b2f20.h; vtable 0x710244e510) and of the
// class in vtable group 0x710244e2e8.
#include "Unk_15b3ce0.h"

// 0x71016340b0: where the call's result `index` goes (null when the caller
// doesn't want it).
void* Unk_16340b0(nn::nex::ProtocolCallContext* ctx, u32 index);
// 0x7101630ba0: the method ID of a response.
u32 Unk_1630ba0(nn::nex::ByteStream* stream);
// 0x710162efb0: reports an unexpected result.
void Unk_162efb0(const Unk_15bbc10& result);

// 0x71015b3a80 (lib/nex/Unk_15b36f0.cpp)
void Unk_15b3a80_read(nn::nex::ByteStream* s, nn::nex::qList<nn::nex::StationURL>& v);

// The protocols' result handlers (lib/nex/ddl/Calls.cpp stores them), each
// called with the response and the client's argument.
extern Unk_Handlers Unk_27f26f8;
extern Unk_Handlers Unk_27f2860;
using Unk_Handler = void (*)(nn::nex::ByteStream* response, void* arg);

// A result read into where the call wants it, or into a temporary that is
// thrown away.
template <class T, class F>
static inline void ReadResult(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx, F read) {
    T* out = static_cast<T*>(Unk_16340b0(ctx, 0));
    if (out != nullptr) {
        read(s, *out);
    } else {
        T result;
        read(s, result);
    }
}

// The same for a scalar result (the temporary is declared first: the reads
// are then one call).
template <class T, class F>
static inline void ReadScalarResult(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx, F read) {
    T* out = static_cast<T*>(Unk_16340b0(ctx, 0));
    T result;
    if (out != nullptr) {
        read(s, *out);
    } else {
        read(s, result);
    }
}

// 0x71015b3ce0
void Unk_15b3ce0(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx) {
    ReadScalarResult<bool>(s, ctx, Unk_15c8ce0_read);
}

// 0x71015b3d20
void Unk_15b3d20(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx) {
    ReadResult<nn::nex::qList<nn::nex::StationURL>>(s, ctx, Unk_15b3a80_read);
}

// 0x71015b3e10: calls the handler of the response's method.
void Unk_15b3e10(nn::nex::ClientProtocol* self, nn::nex::ByteStream* response, void* arg) {
    int method = Unk_1630ba0(response) & 0x7fff;
    if (method < 1 || method > 44) {
        Unk_162efb0(Unk_15bbc10(0x80010002));
        return;
    }
    Unk_Handler handler = reinterpret_cast<Unk_Handler>(Unk_27f26f8.m_handlers[method - 1]);
    if (handler != nullptr) {
        handler(response, arg);
    }
}

// 0x71015b3ea0
void Unk_15b3ea0(nn::nex::ClientProtocol* self, u32 protocolId) {
    Unk_ClientInit(self, Unk_244e430, protocolId);
}

// 0x71015b3fa0
void Unk_15b3fa0(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx) {
    ReadScalarResult<bool>(s, ctx, Unk_15c8ce0_read);
}

// 0x71015b3fe0: calls the handler of the response's method.
void Unk_15b3fe0(nn::nex::ClientProtocol* self, nn::nex::ByteStream* response, void* arg) {
    int method = Unk_1630ba0(response) & 0x7fff;
    if (method < 1 || method > 6) {
        Unk_162efb0(Unk_15bbc10(0x80010002));
        return;
    }
    Unk_Handler handler = reinterpret_cast<Unk_Handler>(Unk_27f2860.m_handlers[method - 1]);
    if (handler != nullptr) {
        handler(response, arg);
    }
}

// 0x71015b40f0: Unk_15b2f20's D2.
void Unk_15b40f0(Unk_15b2f20* self) {
    self->Unk_15b2f20::~Unk_15b2f20();
}

// 0x71015b4120: Unk_15b2f20's D0.
void Unk_15b4120(Unk_15b2f20* self) {
    self->Unk_15b2f20::~Unk_15b2f20();
    Unk_15b6e10(self);
}

// 0x71015b4170: Unk_244e2d8's D0.
void Unk_15b4170(Unk_244e2d8* self) {
    ::operator delete(self);
}
