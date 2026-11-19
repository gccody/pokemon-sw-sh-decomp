// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex24JobConnectSecureEndPointE
#include <types.h>

struct Unk_1648be0_3f0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

struct Unk_1648be0 {
    u8 _0[0x3f0];
    Unk_1648be0_3f0* field_3f0;
};
PKMN_OFFSET_ASSERT(Unk_1648be0, field_3f0, 0x3f0);

namespace nn {
namespace nex {
class JobConnectSecureEndPoint {
public:
    void vf9();
};
}  // namespace nex
}  // namespace nn

// 0x7101648be0
void nn::nex::JobConnectSecureEndPoint::vf9() {
    const Unk_1648be0* self = reinterpret_cast<const Unk_1648be0*>(this);
    if (self->field_3f0 != nullptr) {
        self->field_3f0->vf9();
    }
}
