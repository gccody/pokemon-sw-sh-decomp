// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16d3b40 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d3b40, field_8, 0x8);

struct Unk_16d3b50 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d3b50, field_8, 0x8);

struct Unk_16d3da0_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64);
};

struct Unk_16d3da0 {
    u8 _0[0x10];
    Unk_16d3da0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_16d3da0, field_10, 0x10);

namespace nn {
namespace pia {
namespace nex {
class NexNatRelayInterface {
public:
    void vf2(u64 value);
    void vf3();
    void vf4();
    void vf6();
    void vf7();
    void vf12();
    void vf13(u64 value);
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d3b40
void nn::pia::nex::NexNatRelayInterface::vf2(u64 value) {
    Unk_16d3b40* self = reinterpret_cast<Unk_16d3b40*>(this);
    if (value != 0) {
        self->field_8 = value;
    }
}

// 0x71016d3b50
void nn::pia::nex::NexNatRelayInterface::vf3() {
    Unk_16d3b50* self = reinterpret_cast<Unk_16d3b50*>(this);
    self->field_8 = 0;
}

// 0x71016d3da0
void nn::pia::nex::NexNatRelayInterface::vf13(u64 value) {
    const Unk_16d3da0* self = reinterpret_cast<const Unk_16d3da0*>(this);
    if (self->field_10 != nullptr) {
        self->field_10->vf6(value);
    }
}

// 0x71016d5cd0
void nn::pia::nex::NexNatRelayInterface::vf4() {
}

// 0x71016d5ce0
void nn::pia::nex::NexNatRelayInterface::vf6() {
}

// 0x71016d5cf0
void nn::pia::nex::NexNatRelayInterface::vf7() {
}

// 0x71016d5d00
void nn::pia::nex::NexNatRelayInterface::vf12() {
}
