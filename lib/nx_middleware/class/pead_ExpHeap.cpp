// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1718400 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1718400, field_30, 0x30);

struct Unk_1718420 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_1718420, field_38, 0x38);

struct Unk_1718f90 {
    u8 _0[0x100];
    u32 field_100;
};
PKMN_OFFSET_ASSERT(Unk_1718f90, field_100, 0x100);

struct Unk_1719140 {
    u8 _0[0xd4];
    u32 field_d4;
};
PKMN_OFFSET_ASSERT(Unk_1719140, field_d4, 0xd4);

struct Unk_1719150 {
    u8 _0[0xd4];
    u32 field_d4;
};
PKMN_OFFSET_ASSERT(Unk_1719150, field_d4, 0xd4);

namespace pead {
class ExpHeap {
public:
    u64 vf12();
    u64 vf14();
    bool vf18();
    u32 vf19();
    u32 vf20();
    u32 vf21();
    void vf25(u32 value);
    u32 vf26();
};
}  // namespace pead

// 0x7101718400
u64 pead::ExpHeap::vf12() {
    const Unk_1718400* self = reinterpret_cast<const Unk_1718400*>(this);
    return self->field_30;
}

// 0x7101718420
u64 pead::ExpHeap::vf14() {
    const Unk_1718420* self = reinterpret_cast<const Unk_1718420*>(this);
    return self->field_38;
}

// 0x7101718f90
bool pead::ExpHeap::vf18() {
    const Unk_1718f90* self = reinterpret_cast<const Unk_1718f90*>(this);
    return self->field_100 == 0;
}

// 0x7101718fa0
u32 pead::ExpHeap::vf19() {
    return 1;
}

// 0x7101718fb0
u32 pead::ExpHeap::vf20() {
    return 1;
}

// 0x7101718fc0
u32 pead::ExpHeap::vf21() {
    return 1;
}

// 0x7101719140
void pead::ExpHeap::vf25(u32 value) {
    Unk_1719140* self = reinterpret_cast<Unk_1719140*>(this);
    self->field_d4 = value;
}

// 0x7101719150
u32 pead::ExpHeap::vf26() {
    const Unk_1719150* self = reinterpret_cast<const Unk_1719150*>(this);
    return self->field_d4;
}
