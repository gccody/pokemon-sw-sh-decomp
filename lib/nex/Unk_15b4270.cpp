// Scope: common
// NEX 4.6.8's matchmaking protocols, continued (lib/nex/Unk_15b3ce0.cpp): the
// D0 and the factory (slots 1 and 22) of the clients in vtable groups
// 0x710244e370 and 0x710244e440, the type name of the "DynamicGathering"
// class in vtable group 0x710244e6f8, the D0 of "GameSession"
// (lib/nex/Unk_15b2f20.h), libc++'s assignment of a list of StationURLs, and
// the D2 of the class in vtable group 0x710244e2e8.
#include "Unk_15b3ce0.h"

// 0x7101638220: the ClientProtocol's destructor.
void Unk_1638220(nn::nex::ClientProtocol* self);

// 0x71015b4270
void Unk_15b4270(nn::nex::ClientProtocol* self) {
    Unk_1638220(self);
    Unk_15b6e10(self);
}

// 0x71015b42a0
nn::nex::ClientProtocol* Unk_15b42a0(nn::nex::ClientProtocol* self) {
    nn::nex::ClientProtocol* client = static_cast<nn::nex::ClientProtocol*>(Unk_15b6dc0(0x90));
    if (client != nullptr) {
        Unk_ClientInit(client, Unk_244e360, 0);
    }
    return client;
}

// 0x71015b42f0
void Unk_15b42f0(nn::nex::ClientProtocol* self) {
    Unk_1638220(self);
    Unk_15b6e10(self);
}

// 0x71015b4320
nn::nex::ClientProtocol* Unk_15b4320(nn::nex::ClientProtocol* self) {
    nn::nex::ClientProtocol* client = static_cast<nn::nex::ClientProtocol*>(Unk_15b6dc0(0x90));
    if (client != nullptr) {
        Unk_ClientInit(client, Unk_244e430, 0);
    }
    return client;
}

// Vtable 0x710244e6f8 (9 slots), derived from "DynamicGathering": its type
// name is a String member.
class Unk_244e6e8 : public Unk_244e598 {
public:
    u8 _98[0x8];
    nn::nex::String field_a0;
};
PKMN_OFFSET_ASSERT(Unk_244e6e8, field_a0, 0xa0);

// 0x71015b4490
nn::nex::String Unk_15b4490(const Unk_244e6e8* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, self->field_a0.m_ptr, static_cast<size_t>(-1));
    return name;
}

// 0x71015b44c0: Unk_244e758's D0. Its base's destructor (Unk_244e308's,
// 0x71015b4240) is inlined here, but lib/nex/Unk_15b2f20.h declares it out of
// line: what it does, Unk_15b2f20's, is written instead.
void Unk_15b44c0(Unk_244e758* self) {
    self->Unk_15b2f20::~Unk_15b2f20();
    Unk_15b6e10(self);
}

// 0x71015b4510: libc++'s list::assign from another list's elements.
using Unk_StationURLs = std::list<nn::nex::StationURL, nn::nex::MemAllocator<nn::nex::StationURL>>;
template void Unk_StationURLs::assign(Unk_StationURLs::const_iterator first,
                                      Unk_StationURLs::const_iterator last, void*);

// 0x71015b4680: Unk_244e2d8's D2.
void Unk_15b4680(Unk_244e2d8* self) {}
