// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_830df0_arg1 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_830df0_arg1, field_2, 0x2);

struct Unk_830df0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_830df0, field_8, 0x8);

u32 Unk_816460(u64, u32);

// 0x7100830df0
void Unk_830df0_call(const Unk_830df0* self, Unk_830df0_arg1* value) {
    u32 r0 = Unk_816460(self->field_8, 0xb8);
    value->field_2 = r0;
}

struct Unk_831020 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_831020, field_0, 0x0);

// 0x7100831020
void Unk_831020_set(Unk_831020* self) {
    self->field_0 = 0xffffffff;
}

struct Unk_831030 {
    u8 _0[0x2];
    s16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_831030, field_2, 0x2);

// 0x7100831030
bool Unk_831030_check(const Unk_831030* self) {
    return self->field_2 != -1;
}

struct Unk_831040 {
    u16 field_0;
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_831040, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_831040, field_2, 0x2);

u32 Unk_816460(u64, u32);

// 0x7100831040
void Unk_831040_call(Unk_831040* self, u64 value) {
    u32 r0 = Unk_816460(value, 0x97);
    self->field_0 = r0;
    u32 r1 = Unk_816460(value, 0x86);
    self->field_2 = r1;
}
