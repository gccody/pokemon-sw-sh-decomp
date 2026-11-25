#pragma once
// What lib/nex/Unk_15b3ce0.cpp and Unk_15b4270.cpp share: StationURL, the
// constructor of the matchmaking protocols' clients, and the class in vtable
// group 0x710244e2e8.
#include "Unk_15b2f20.h"
#include "Unk_164e150.h"

#include <nn/nex/qList.h>

namespace nn {
namespace nex {

// N2nn3nex10StationURLE (0x70 bytes), as lib/nex/Unk_15b36f0.cpp declares it,
// and its copy assignment (0x71015e47e0, which libc++'s list::assign calls for
// each element it overwrites: lib/nex/Unk_15b4270.cpp).
class StationURL : public RootObject {
public:
    StationURL();
    StationURL(const StationURL& other);
    virtual ~StationURL();
    StationURL& operator=(const StationURL& other);
    u8 _8[0x68];
};
PKMN_SIZE_ASSERT(StationURL, 0x70);

}  // namespace nex
}  // namespace nn

// A protocol client's constructor (like 0x710164e720): the base's, the
// client's vtable (its address point two words into `vtable`), and with a
// protocol ID, registering the client under it. The factories (slot 22)
// inline it without an ID.
inline void Unk_ClientInit(nn::nex::ClientProtocol* self, void** vtable, u16 protocolId) {
    Unk_162eed0(self, 1);
    *reinterpret_cast<void***>(self) = vtable + 2;
    if (protocolId != 0) {
        Unk_1630a10_set(reinterpret_cast<Unk_1630a10*>(self), protocolId);
        Unk_1647560(GetProtocols()->m_holder->m_registry, self->m_protocolId,
                    reinterpret_cast<Unk_164e720_Client*>(self)->vf22());
    }
}

// The clients' vtables (vtable groups 0x710244e360 and 0x710244e430).
extern void* Unk_244e360[];
extern void* Unk_244e430[];

// Vtable 0x710244e2e8 (4 slots): a class with an empty destructor, freed with
// the global operator delete (not NEX's allocator).
struct Unk_244e2d8;
