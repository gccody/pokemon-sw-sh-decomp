// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex15NexNatTraverserE
#include <types.h>

struct Unk_16d6500_258 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct Unk_16d6500 {
    u8 _0[0x258];
    Unk_16d6500_258* field_258;
};
PKMN_OFFSET_ASSERT(Unk_16d6500, field_258, 0x258);

struct Unk_16d6a10_258 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

struct Unk_16d6a10 {
    u8 _0[0x258];
    Unk_16d6a10_258* field_258;
};
PKMN_OFFSET_ASSERT(Unk_16d6a10, field_258, 0x258);

struct Unk_16d6910_258 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u64, u64);
};

struct Unk_16d6910 {
    u8 _0[0x258];
    Unk_16d6910_258* field_258;
};
PKMN_OFFSET_ASSERT(Unk_16d6910, field_258, 0x258);

namespace nn {
namespace pia {
namespace nex {
class NexNatTraverser {
public:
    void vf5();
    void vf6();
    void vf8();
    void vf11(u64 value, u64 arg2);
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d6500
void nn::pia::nex::NexNatTraverser::vf5() {
    const Unk_16d6500* self = reinterpret_cast<const Unk_16d6500*>(this);
    if (self->field_258 != nullptr) {
        self->field_258->vf6();
    }
}

// 0x71016d6910
void nn::pia::nex::NexNatTraverser::vf11(u64 value, u64 arg2) {
    const Unk_16d6910* self = reinterpret_cast<const Unk_16d6910*>(this);
    if (self->field_258 != nullptr) {
        self->field_258->vf7(value, arg2);
    }
}

// 0x71016d6a10
void nn::pia::nex::NexNatTraverser::vf6() {
    const Unk_16d6a10* self = reinterpret_cast<const Unk_16d6a10*>(this);
    if (self->field_258 != nullptr) {
        self->field_258->vf8();
    }
}

// 0x71016d6a30
void nn::pia::nex::NexNatTraverser::vf8() {
}
