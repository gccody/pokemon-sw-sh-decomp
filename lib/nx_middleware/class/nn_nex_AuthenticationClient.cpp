// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20AuthenticationClientE
#include <types.h>

struct Unk_163a750_20 {
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(u64);
};

struct Unk_163a750 {
    u8 _0[0x20];
    Unk_163a750_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_163a750, field_20, 0x20);

namespace nn {
namespace nex {
class AuthenticationClient {
public:
    void vf8(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x710163a750
void nn::nex::AuthenticationClient::vf8(u64 value) {
    const Unk_163a750* self = reinterpret_cast<const Unk_163a750*>(this);
    self->field_20->vf23(value);
}
