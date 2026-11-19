// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16864d0 {
    u8 _0[0xa60];
    u32 field_a60;
};
PKMN_OFFSET_ASSERT(Unk_16864d0, field_a60, 0xa60);

struct Unk_16864e0 {
    u8 _0[0xa64];
    u32 field_a64;
};
PKMN_OFFSET_ASSERT(Unk_16864e0, field_a64, 0xa64);

struct Unk_16864f0 {
    u8 _0[0xa68];
    u16 field_a68;
};
PKMN_OFFSET_ASSERT(Unk_16864f0, field_a68, 0xa68);

struct Unk_169aca0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_169aca0, field_8, 0x8);

struct Unk_1686500 {
    u8 _0[0xa6a];
    u16 field_a6a;
};
PKMN_OFFSET_ASSERT(Unk_1686500, field_a6a, 0xa6a);

struct Unk_16865a0 {
    u8 _0[0xbda];
    u8 field_bda;
};
PKMN_OFFSET_ASSERT(Unk_16865a0, field_bda, 0xbda);

struct Unk_1686590 {
    u8 _0[0xbd4];
    u32 field_bd4;
};
PKMN_OFFSET_ASSERT(Unk_1686590, field_bd4, 0xbd4);

struct Unk_169acb0 {
    u8 _0[0x9];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_169acb0, field_9, 0x9);

struct Unk_169ad20 {
    u8 _0[0xa];
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_169ad20, field_a, 0xa);

struct Unk_1686740 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1686740, field_10, 0x10);

struct Unk_169ad30 {
    u8 _0[0xa];
    bool field_a;
};
PKMN_OFFSET_ASSERT(Unk_169ad30, field_a, 0xa);

namespace nn {
namespace pia {
namespace local {
class LdnSessionInfo {
public:
    u32 vf2();
    u32 vf3();
    u16 vf4();
    u8 vf5();
    u16 vf6();
    u8 vf7();
    u32 vf9();
    void vf11();
    u32 vf12();
    u8 vf13();
    u8 vf16();
    const u8* vf18();
    void vf20(bool value);
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x71016864d0
u32 nn::pia::local::LdnSessionInfo::vf2() {
    const Unk_16864d0* self = reinterpret_cast<const Unk_16864d0*>(this);
    return self->field_a60;
}

// 0x71016864e0
u32 nn::pia::local::LdnSessionInfo::vf3() {
    const Unk_16864e0* self = reinterpret_cast<const Unk_16864e0*>(this);
    return self->field_a64;
}

// 0x71016864f0
u16 nn::pia::local::LdnSessionInfo::vf4() {
    const Unk_16864f0* self = reinterpret_cast<const Unk_16864f0*>(this);
    return self->field_a68;
}

// 0x7101686500
u16 nn::pia::local::LdnSessionInfo::vf6() {
    const Unk_1686500* self = reinterpret_cast<const Unk_1686500*>(this);
    return self->field_a6a;
}

// 0x7101686590
u32 nn::pia::local::LdnSessionInfo::vf9() {
    const Unk_1686590* self = reinterpret_cast<const Unk_1686590*>(this);
    return self->field_bd4;
}

// 0x71016865a0
u8 nn::pia::local::LdnSessionInfo::vf7() {
    const Unk_16865a0* self = reinterpret_cast<const Unk_16865a0*>(this);
    return self->field_bda;
}

// 0x7101686740
const u8* nn::pia::local::LdnSessionInfo::vf18() {
    const Unk_1686740* self = reinterpret_cast<const Unk_1686740*>(this);
    return &self->field_10;
}

// 0x71016868d0
void nn::pia::local::LdnSessionInfo::vf11() {
}

// 0x71016868e0
u32 nn::pia::local::LdnSessionInfo::vf12() {
    return 3;
}

// 0x710169aca0
u8 nn::pia::local::LdnSessionInfo::vf5() {
    const Unk_169aca0* self = reinterpret_cast<const Unk_169aca0*>(this);
    return self->field_8;
}

// 0x710169acb0
u8 nn::pia::local::LdnSessionInfo::vf13() {
    const Unk_169acb0* self = reinterpret_cast<const Unk_169acb0*>(this);
    return self->field_9;
}

// 0x710169ad20
u8 nn::pia::local::LdnSessionInfo::vf16() {
    const Unk_169ad20* self = reinterpret_cast<const Unk_169ad20*>(this);
    return self->field_a;
}

// 0x710169ad30
void nn::pia::local::LdnSessionInfo::vf20(bool value) {
    Unk_169ad30* self = reinterpret_cast<Unk_169ad30*>(this);
    self->field_a = value;
}
