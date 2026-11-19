// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16c8430_88 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u64, u32, u64);
};

struct Unk_16c8430 {
    u8 _0[0x88];
    Unk_16c8430_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_16c8430, field_88, 0x88);

struct Unk_16c84b0_88 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64);
};

struct Unk_16c84b0 {
    u8 _0[0x88];
    Unk_16c84b0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_16c84b0, field_88, 0x88);

struct Unk_16c84f0_88 {
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
};

struct Unk_16c84f0 {
    u8 _0[0x88];
    Unk_16c84f0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_16c84f0, field_88, 0x88);

struct Unk_16c8420 {
    u8 _0[0x18c];
    u32 field_18c;
};
PKMN_OFFSET_ASSERT(Unk_16c8420, field_18c, 0x18c);

struct Unk_16c8c60 {
    u8 _0[0x210];
    u8 field_210;
};
PKMN_OFFSET_ASSERT(Unk_16c8c60, field_210, 0x210);

namespace nn {
namespace pia {
namespace nex {
class NexFacade {
public:
    u32 vf2();
    u32 vf3();
    void vf5(u64 value, bool arg2, u64 arg3);
    void vf7(u64 value, u64 arg2);
    void vf8();
    u32 vf10();
    u8 vf12();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016c8350
u32 nn::pia::nex::NexFacade::vf2() {
    return 0xc000;
}

// 0x71016c8360
u32 nn::pia::nex::NexFacade::vf3() {
    return 0xffff;
}

// 0x71016c8420
u32 nn::pia::nex::NexFacade::vf10() {
    const Unk_16c8420* self = reinterpret_cast<const Unk_16c8420*>(this);
    return self->field_18c;
}

// 0x71016c8430
void nn::pia::nex::NexFacade::vf5(u64 value, bool arg2, u64 arg3) {
    const Unk_16c8430* self = reinterpret_cast<const Unk_16c8430*>(this);
    if (self->field_88 != nullptr) {
        self->field_88->vf4(value, arg2, arg3);
    }
}

// 0x71016c84b0
void nn::pia::nex::NexFacade::vf7(u64 value, u64 arg2) {
    const Unk_16c84b0* self = reinterpret_cast<const Unk_16c84b0*>(this);
    if (self->field_88 != nullptr) {
        self->field_88->vf3(value, arg2);
    }
}

// 0x71016c84f0
void nn::pia::nex::NexFacade::vf8() {
    const Unk_16c84f0* self = reinterpret_cast<const Unk_16c84f0*>(this);
    if (self->field_88 != nullptr) {
        self->field_88->vf21();
    }
}

// 0x71016c8c60
u8 nn::pia::nex::NexFacade::vf12() {
    const Unk_16c8c60* self = reinterpret_cast<const Unk_16c8c60*>(this);
    return self->field_210;
}
