// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N4PPFX11CTinyEffectE
#include <types.h>

struct Unk_44e5a0 {
    u8 _0[0x380];
    u32 field_380;
};
PKMN_OFFSET_ASSERT(Unk_44e5a0, field_380, 0x380);

struct Unk_44ea80 {
    u8 _0[0x384];
    u32 field_384;
};
PKMN_OFFSET_ASSERT(Unk_44ea80, field_384, 0x384);

namespace PPFX {
class CTinyEffect {
public:
    u32 vf2();
    u32 vf6(u32 value);
    u32 vf19();
    u32 vf23();
    u32 vf25();
};
}  // namespace PPFX

// 0x710044dd80
u32 PPFX::CTinyEffect::vf6(u32 value) {
    return value + 1;
}

// 0x710044dd90
u32 PPFX::CTinyEffect::vf2() {
    return 0;
}

// 0x710044e5a0
u32 PPFX::CTinyEffect::vf19() {
    const Unk_44e5a0* self = reinterpret_cast<const Unk_44e5a0*>(this);
    return self->field_380;
}

// 0x710044ea80
u32 PPFX::CTinyEffect::vf23() {
    Unk_44ea80* self = reinterpret_cast<Unk_44ea80*>(this);
    self->field_384 = 0;
    return 0;
}

// 0x710044f240
u32 PPFX::CTinyEffect::vf25() {
    return 0;
}
