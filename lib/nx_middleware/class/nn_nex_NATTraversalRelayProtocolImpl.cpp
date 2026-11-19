// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_15b4c10_88_20 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64);
};

struct Unk_15b4c10_88 {
    u8 _0[0x20];
    Unk_15b4c10_88_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_15b4c10_88, field_20, 0x20);

struct Unk_15b4c10 {
    u8 _0[0x88];
    Unk_15b4c10_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_15b4c10, field_88, 0x88);

namespace nn {
namespace nex {
class NATTraversalRelayProtocolImpl {
public:
    void vf25(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x71015b4c10
void nn::nex::NATTraversalRelayProtocolImpl::vf25(u64 value) {
    const Unk_15b4c10* self = reinterpret_cast<const Unk_15b4c10*>(this);
    if (self->field_88 != nullptr) {
        self->field_88->field_20->vf8(value);
    }
}
