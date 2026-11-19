// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1713bb0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1713bb0, field_8, 0x8);

struct Unk_1713bc0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1713bc0, field_c, 0xc);

struct Unk_1713bd0 {
    u8 _0[0x10];
    u16 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1713bd0, field_10, 0x10);

struct Unk_1713be0 {
    u8 _0[0x12];
    u16 field_12;
};
PKMN_OFFSET_ASSERT(Unk_1713be0, field_12, 0x12);

struct Unk_1713bf0 {
    u8 _0[0x14];
    u16 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1713bf0, field_14, 0x14);

struct Unk_1713c00 {
    u8 _0[0x16];
    u8 field_16;
};
PKMN_OFFSET_ASSERT(Unk_1713c00, field_16, 0x16);

struct Unk_1713db0 {
    u8 _0[0x230];
    u32 field_230;
};
PKMN_OFFSET_ASSERT(Unk_1713db0, field_230, 0x230);

namespace nn {
namespace pia {
namespace nex {
class NexSessionInfoPrivate {
public:
    u32 vf2();
    u32 vf3();
    u16 vf4();
    u16 vf5();
    u16 vf6();
    u8 vf7();
    u32 vf9();
    void vf11();
    u32 vf12();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x7101713bb0
u32 nn::pia::nex::NexSessionInfoPrivate::vf2() {
    const Unk_1713bb0* self = reinterpret_cast<const Unk_1713bb0*>(this);
    return self->field_8;
}

// 0x7101713bc0
u32 nn::pia::nex::NexSessionInfoPrivate::vf3() {
    const Unk_1713bc0* self = reinterpret_cast<const Unk_1713bc0*>(this);
    return self->field_c;
}

// 0x7101713bd0
u16 nn::pia::nex::NexSessionInfoPrivate::vf4() {
    const Unk_1713bd0* self = reinterpret_cast<const Unk_1713bd0*>(this);
    return self->field_10;
}

// 0x7101713be0
u16 nn::pia::nex::NexSessionInfoPrivate::vf5() {
    const Unk_1713be0* self = reinterpret_cast<const Unk_1713be0*>(this);
    return self->field_12;
}

// 0x7101713bf0
u16 nn::pia::nex::NexSessionInfoPrivate::vf6() {
    const Unk_1713bf0* self = reinterpret_cast<const Unk_1713bf0*>(this);
    return self->field_14;
}

// 0x7101713c00
u8 nn::pia::nex::NexSessionInfoPrivate::vf7() {
    const Unk_1713c00* self = reinterpret_cast<const Unk_1713c00*>(this);
    return self->field_16;
}

// 0x7101713db0
u32 nn::pia::nex::NexSessionInfoPrivate::vf9() {
    const Unk_1713db0* self = reinterpret_cast<const Unk_1713db0*>(this);
    return self->field_230;
}

// 0x7101713e60
u32 nn::pia::nex::NexSessionInfoPrivate::vf12() {
    return 1;
}

// 0x7101713e70
void nn::pia::nex::NexSessionInfoPrivate::vf11() {
}
