// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3fd890 {
    u8 _0[0x94];
    u32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_3fd890, field_94, 0x94);

struct Unk_3fe090 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3fe090, field_20, 0x20);

struct Unk_3fcf10 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_3fcf10, field_60, 0x60);

class Unk_2385cf8 {
public:
    u32 vf10();
    u64 vf16();
    u32 vf21();
};

// 0x71003fcf10
u32 Unk_2385cf8::vf21() {
    const Unk_3fcf10* self = reinterpret_cast<const Unk_3fcf10*>(this);
    return self->field_60;
}

// 0x71003fd890
u32 Unk_2385cf8::vf10() {
    const Unk_3fd890* self = reinterpret_cast<const Unk_3fd890*>(this);
    return self->field_94;
}

// 0x71003fe090
u64 Unk_2385cf8::vf16() {
    const Unk_3fe090* self = reinterpret_cast<const Unk_3fe090*>(this);
    return self->field_20;
}
