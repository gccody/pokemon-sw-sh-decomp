// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8503e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8503e0, field_0, 0x0);

// 0x71008503e0
bool Unk_8503e0_check(const Unk_8503e0* self) {
    return (self->field_0 & 0xf) == 1;
}

struct Unk_850400 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850400, field_0, 0x0);

// 0x7100850400
bool Unk_850400_check(const Unk_850400* self) {
    return (self->field_0 & (0x80000001 + 0xe)) == 0x80000001;
}

struct Unk_850420 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850420, field_0, 0x0);

// 0x7100850420
bool Unk_850420_check(const Unk_850420* self) {
    return (self->field_0 & 0xf) == 2;
}

struct Unk_850440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850440, field_0, 0x0);

// 0x7100850440
bool Unk_850440_check(const Unk_850440* self) {
    return (self->field_0 & 0xf) == 7;
}

struct Unk_850460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850460, field_0, 0x0);

// 0x7100850460
u32 Unk_850460_get(const Unk_850460* self) {
    return (self->field_0 & 0xf) == 1 ? ((self->field_0 >> 0xd) & 0xffff) : 0;
}

struct Unk_850480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850480, field_0, 0x0);

// 0x7100850480
u32 Unk_850480_get(const Unk_850480* self) {
    return (self->field_0 & 0xf) == 1 ? ((self->field_0 >> 9) & 0xf) : 5;
}

struct Unk_8504f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8504f0, field_0, 0x0);

// 0x71008504f0
void Unk_8504f0_set(Unk_8504f0* self) {
    self->field_0 = 0x81f3;
}

struct Unk_850500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850500, field_0, 0x0);

// 0x7100850500
bool Unk_850500_check(const Unk_850500* self) {
    return (self->field_0 & 0x800f) == 0x8003;
}

struct Unk_850540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850540, field_0, 0x0);

// 0x7100850540
void Unk_850540_set(Unk_850540* self) {
    self->field_0 = (self->field_0 & 0xfffffffffffffe00) | (0x1f7 & 0x1ff);
}

struct Unk_850560 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850560, field_0, 0x0);

// 0x7100850560
void Unk_850560_clearField0(Unk_850560* self) {
    self->field_0 = 0;
}

struct Unk_850590 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850590, field_0, 0x0);

// 0x7100850590
u32 Unk_850590_get(const Unk_850590* self) {
    return self->field_0 & 0xf;
}

struct Unk_8505a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8505a0, field_0, 0x0);

// 0x71008505a0
void Unk_8505a0_set(Unk_8505a0* self) {
    self->field_0 = (self->field_0 & 0x1f0) | 8;
}

struct Unk_8505c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8505c0, field_0, 0x0);

// 0x71008505c0
void Unk_8505c0_set(Unk_8505c0* self) {
    self->field_0 = (self->field_0 & 0x1f0) | 9;
}

struct Unk_27d0584_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d0584_Data, field_18, 0x18);

extern Unk_27d0584_Data Unk_27d0584 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008507d0
void Unk_8507d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d0584.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d0584.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d0584.field_18 = 0xffff;
    Unk_27d0584.field_10 = 0;
    Unk_27d0584.field_8 = r2;
    Unk_27d0584.field_c = 0;
    Unk_27d0584.field_14 = 0xffffffff;
}
