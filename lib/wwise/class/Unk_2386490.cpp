// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_402550_a8_8 {
    u64 field_0;
    u8 _8[0x10];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_402550_a8_8, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_402550_a8_8, field_18, 0x18);
struct Unk_402550_c0_8 {
    u64 field_0;
    u8 _8[0x10];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_402550_c0_8, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_402550_c0_8, field_18, 0x18);
struct Unk_402550_a8 {
    u8 _0[0x8];
    Unk_402550_a8_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_402550_a8, field_8, 0x8);
struct Unk_402550_c0 {
    u8 _0[0x8];
    Unk_402550_c0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_402550_c0, field_8, 0x8);
struct Unk_402550 {
    u8 _0[0x78];
    u64 field_78;
    u8 _80[0x20];
    u32 field_a0;
    u8 _a4[0x4];
    Unk_402550_a8* field_a8;
    u8 _b0[0x8];
    u8 field_b8;
    u8 _b9[0x7];
    Unk_402550_c0* field_c0;
};
PKMN_OFFSET_ASSERT(Unk_402550, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_402550, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_402550, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_402550, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_402550, field_c0, 0xc0);

class Unk_2386490 {
public:
    u64 vf29();
};

// 0x7100402550
u64 Unk_2386490::vf29() {
    const Unk_402550* self = reinterpret_cast<const Unk_402550*>(this);
    if (self->field_c0 == nullptr) {
        if (self->field_a0 > self->field_b8) {
            return self->field_a8->field_8->field_0 + self->field_a8->field_8->field_18;
        }
        return self->field_78;
    }
    return self->field_c0->field_8->field_0 + self->field_c0->field_8->field_18;
}
