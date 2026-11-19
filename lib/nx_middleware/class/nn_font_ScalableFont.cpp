// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_177d270 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_177d270, field_18, 0x18);

struct Unk_177d280 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_177d280, field_1c, 0x1c);

struct Unk_177d290 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_177d290, field_20, 0x20);

struct Unk_177d2a0 {
    u8 _0[0x1c];
    u32 field_1c;
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_177d2a0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_177d2a0, field_20, 0x20);

struct Unk_177d2b0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_177d2b0, field_18, 0x18);

struct Unk_177d2e0 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_177d2e0, field_28, 0x28);

struct Unk_177d300 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_177d300, field_28, 0x28);

struct Unk_177d310_arg1 {
    u16 field_0;
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_177d310_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_177d310_arg1, field_2, 0x2);

struct Unk_177d310 {
    u8 _0[0x2c];
    u16 field_2c;
    u8 field_2e;
};
PKMN_OFFSET_ASSERT(Unk_177d310, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_177d310, field_2e, 0x2e);

struct Unk_177d7c0 {
    u8 _0[0x24];
    u32 field_24;
};
PKMN_OFFSET_ASSERT(Unk_177d7c0, field_24, 0x24);

struct Unk_177d7d0 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_177d7d0, field_1c, 0x1c);

struct Unk_177d7e0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_177d7e0, field_18, 0x18);

namespace nn {
namespace font {
class ScalableFont {
public:
    u32 vf4();
    u32 vf5();
    u32 vf6();
    u32 vf7();
    u32 vf8();
    u32 vf9();
    u32 vf10();
    u32 vf11();
    void vf13(u32 value);
    void vf14(const Unk_177d310_arg1* value);
    u32 vf21();
    u32 vf22();
    u32 vf23();
    u32 vf24();
    void vf25();
    u32 vf26();
    u32 vf27();
    u32 vf28();
    u32 vf29();
    void vf30();
    u32 vf31();
};
}  // namespace font
}  // namespace nn

// 0x710177d270
u32 nn::font::ScalableFont::vf4() {
    const Unk_177d270* self = reinterpret_cast<const Unk_177d270*>(this);
    return self->field_18;
}

// 0x710177d280
u32 nn::font::ScalableFont::vf5() {
    const Unk_177d280* self = reinterpret_cast<const Unk_177d280*>(this);
    return self->field_1c;
}

// 0x710177d290
u32 nn::font::ScalableFont::vf6() {
    const Unk_177d290* self = reinterpret_cast<const Unk_177d290*>(this);
    return self->field_20;
}

// 0x710177d2a0
u32 nn::font::ScalableFont::vf7() {
    const Unk_177d2a0* self = reinterpret_cast<const Unk_177d2a0*>(this);
    return self->field_1c - self->field_20;
}

// 0x710177d2b0
u32 nn::font::ScalableFont::vf8() {
    const Unk_177d2b0* self = reinterpret_cast<const Unk_177d2b0*>(this);
    return self->field_18;
}

// 0x710177d2c0
u32 nn::font::ScalableFont::vf9() {
    return 2;
}

// 0x710177d2d0
u32 nn::font::ScalableFont::vf10() {
    return 8;
}

// 0x710177d2e0
u32 nn::font::ScalableFont::vf11() {
    const Unk_177d2e0* self = reinterpret_cast<const Unk_177d2e0*>(this);
    return self->field_28;
}

// 0x710177d300
void nn::font::ScalableFont::vf13(u32 value) {
    Unk_177d300* self = reinterpret_cast<Unk_177d300*>(this);
    self->field_28 = value;
}

// 0x710177d310
void nn::font::ScalableFont::vf14(const Unk_177d310_arg1* value) {
    Unk_177d310* self = reinterpret_cast<Unk_177d310*>(this);
    u16 v0 = value->field_0;
    self->field_2e = value->field_2;
    self->field_2c = v0;
}

// 0x710177d7b0
u32 nn::font::ScalableFont::vf21() {
    return 1;
}

// 0x710177d7c0
u32 nn::font::ScalableFont::vf22() {
    const Unk_177d7c0* self = reinterpret_cast<const Unk_177d7c0*>(this);
    return self->field_24;
}

// 0x710177d7d0
u32 nn::font::ScalableFont::vf23() {
    const Unk_177d7d0* self = reinterpret_cast<const Unk_177d7d0*>(this);
    return self->field_1c;
}

// 0x710177d7e0
u32 nn::font::ScalableFont::vf24() {
    const Unk_177d7e0* self = reinterpret_cast<const Unk_177d7e0*>(this);
    return self->field_18;
}

// 0x710177d7f0
void nn::font::ScalableFont::vf25() {
}

// 0x710177d800
u32 nn::font::ScalableFont::vf26() {
    return 1;
}

// 0x710177d810
u32 nn::font::ScalableFont::vf27() {
    return 1;
}

// 0x710177d820
u32 nn::font::ScalableFont::vf28() {
    return 0;
}

// 0x710177d830
u32 nn::font::ScalableFont::vf29() {
    return 1;
}

// 0x710177d860
void nn::font::ScalableFont::vf30() {
}

// 0x710177d920
u32 nn::font::ScalableFont::vf31() {
    return 1;
}
