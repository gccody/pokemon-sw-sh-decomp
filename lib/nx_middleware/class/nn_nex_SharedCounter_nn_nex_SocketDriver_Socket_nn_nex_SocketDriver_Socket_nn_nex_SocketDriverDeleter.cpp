// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex13SharedCounterINS0_12SocketDriver6SocketES3_NS0_19SocketDriverDeleterEEE
#include <types.h>

struct Unk_1622bc0_18 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64);
};

struct Unk_1622bc0 {
    u8 _0[0x10];
    u64 field_10;
    Unk_1622bc0_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_1622bc0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1622bc0, field_18, 0x18);

namespace nn { namespace nex { namespace SocketDriver { class Socket; } } }
namespace nn { namespace nex { namespace SocketDriver { class Socket; } } }
namespace nn { namespace nex { class SocketDriverDeleter; } }
namespace nn { namespace nex { template <class T0, class T1, class T2> class SharedCounter; } }

namespace nn {
namespace nex {
template <> class SharedCounter<nn::nex::SocketDriver::Socket, nn::nex::SocketDriver::Socket, nn::nex::SocketDriverDeleter> {
public:
    void vf2();
};
}  // namespace nex
}  // namespace nn

// 0x7101622bc0
void nn::nex::SharedCounter<nn::nex::SocketDriver::Socket, nn::nex::SocketDriver::Socket, nn::nex::SocketDriverDeleter>::vf2() {
    const Unk_1622bc0* self = reinterpret_cast<const Unk_1622bc0*>(this);
    self->field_18->vf3(self->field_10);
}
