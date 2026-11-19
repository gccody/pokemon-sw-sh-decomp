// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u64 Unk_d1f140();

// 0x71013bd640
u64 Unk_13bd640_call() {
    u64 r0 = Unk_d1f140();
    return r0 & 1;
}

struct Unk_13bd660_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bd660_arg1, field_8, 0x8);

u64 Unk_d1ef70(void*);

// 0x71013bd660
u64 Unk_13bd660_call(void* /*unused*/, const Unk_13bd660_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d1ef70(&l8);
    return r0 & 1;
}

struct Unk_13bd750_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bd750_arg1, field_8, 0x8);

u64 Unk_d1f1b0(void*);

// 0x71013bd750
u64 Unk_13bd750_call(void* /*unused*/, const Unk_13bd750_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d1f1b0(&l8);
    return r0 & 1;
}

struct Unk_13be830_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13be830_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13be830_arg1, field_10, 0x10);

u64 Unk_d20270(void*, bool);

// 0x71013be830
u64 Unk_13be830_call(void* /*unused*/, const Unk_13be830_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d20270(&l8, value->field_10 != 0);
    return r0 & 1;
}

struct Unk_13be870_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13be870_arg1, field_8, 0x8);

u64 Unk_d20350(void*);

// 0x71013be870
u64 Unk_13be870_call(void* /*unused*/, const Unk_13be870_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d20350(&l8);
    return r0 & 1;
}

struct Unk_13be8a0_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13be8a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13be8a0_arg1, field_10, 0x10);

u64 Unk_d20430(void*, bool);

// 0x71013be8a0
u64 Unk_13be8a0_call(void* /*unused*/, const Unk_13be8a0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d20430(&l8, value->field_10 != 0);
    return r0 & 1;
}

struct Unk_13be8e0_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13be8e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13be8e0_arg1, field_10, 0x10);

u64 Unk_d20520(void*, bool);

// 0x71013be8e0
u64 Unk_13be8e0_call(void* /*unused*/, const Unk_13be8e0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d20520(&l8, value->field_10 != 0);
    return r0 & 1;
}

struct Unk_13be920_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13be920_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13be920_arg1, field_10, 0x10);

u64 Unk_d205e0(void*, bool);

// 0x71013be920
u64 Unk_13be920_call(void* /*unused*/, const Unk_13be920_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d205e0(&l8, value->field_10 != 0);
    return r0 & 1;
}

struct Unk_13bebd0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bebd0_arg1, field_8, 0x8);

void Unk_d2b000(void*);

// 0x71013bebd0
u32 Unk_13bebd0_call(void* /*unused*/, const Unk_13bebd0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    Unk_d2b000(&l8);
    return 1;
}

u64 Unk_d634d0();

// 0x71013bec00
u64 Unk_13bec00_call() {
    u64 r0 = Unk_d634d0();
    return r0 & 1;
}

struct Unk_13bedc0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bedc0_arg1, field_8, 0x8);

void Unk_d28300(bool);

// 0x71013bedc0
u32 Unk_13bedc0_call(void* /*unused*/, const Unk_13bedc0_arg1* value) {
    Unk_d28300(value->field_8 != 0);
    return 1;
}

struct Unk_13bf6e0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bf6e0_arg1, field_8, 0x8);

u64 Unk_d25930(void*);

// 0x71013bf6e0
u64 Unk_13bf6e0_call(void* /*unused*/, const Unk_13bf6e0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d25930(&l8);
    return r0 & 1;
}

// 0x71013bf710
u32 Unk_13bf710_get() {
    return 1;
}

struct Unk_13bfd60_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bfd60_arg1, field_8, 0x8);

u64 Unk_d22fd0(void*);

// 0x71013bfd60
u64 Unk_13bfd60_call(void* /*unused*/, const Unk_13bfd60_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d22fd0(&l8);
    return r0 & 1;
}

struct Unk_13bfd90_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bfd90_arg1, field_8, 0x8);

u64 Unk_d23530(void*);

// 0x71013bfd90
u64 Unk_13bfd90_call(void* /*unused*/, const Unk_13bfd90_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d23530(&l8);
    return r0 & 1;
}

struct Unk_13c4960_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13c4960_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13c4960_arg1, field_10, 0x10);

void Unk_d261a0(void*, u32);

// 0x71013c4960
u64 Unk_13c4960_call(void* /*unused*/, const Unk_13c4960_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    Unk_d261a0(&l8, value->field_10);
    return 0;
}

struct Unk_13c4990_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c4990_arg1, field_8, 0x8);

void Unk_d265b0(void*);

// 0x71013c4990
u64 Unk_13c4990_call(void* /*unused*/, const Unk_13c4990_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    Unk_d265b0(&l8);
    return 0;
}

struct Unk_13c49c0_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13c49c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13c49c0_arg1, field_10, 0x10);

void Unk_d268d0(void*, u32);

// 0x71013c49c0
u64 Unk_13c49c0_call(void* /*unused*/, const Unk_13c49c0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    Unk_d268d0(&l8, value->field_10);
    return 0;
}

struct Unk_13c49f0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c49f0_arg1, field_8, 0x8);

void Unk_d26ce0(void*);

// 0x71013c49f0
u64 Unk_13c49f0_call(void* /*unused*/, const Unk_13c49f0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    Unk_d26ce0(&l8);
    return 0;
}

void Unk_d2af10();

// 0x71013c4b50
u32 Unk_13c4b50_call() {
    Unk_d2af10();
    return 1;
}

struct Unk_13c4e20_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c4e20_arg1, field_8, 0x8);

u64 Unk_d25790(void*);

// 0x71013c4e20
u64 Unk_13c4e20_call(void* /*unused*/, const Unk_13c4e20_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d25790(&l8);
    return r0 & 1;
}

struct Unk_13c4e50_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c4e50_arg1, field_8, 0x8);

u64 Unk_d25860(void*);

// 0x71013c4e50
u64 Unk_13c4e50_call(void* /*unused*/, const Unk_13c4e50_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d25860(&l8);
    return r0 & 1;
}

struct Unk_13c4e80_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c4e80_arg1, field_8, 0x8);

u64 Unk_d281f0(void*);

// 0x71013c4e80
u64 Unk_13c4e80_call(void* /*unused*/, const Unk_13c4e80_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d281f0(&l8);
    return r0 & 1;
}

struct Unk_13c4eb0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c4eb0_arg1, field_8, 0x8);

u64 Unk_d2a060(void*);

// 0x71013c4eb0
u64 Unk_13c4eb0_call(void* /*unused*/, const Unk_13c4eb0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d2a060(&l8);
    return r0 & 1;
}

struct Unk_13c5670_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c5670_arg1, field_8, 0x8);

void Unk_d29c40_set(bool);

// 0x71013c5670
u32 Unk_13c5670_call(void* /*unused*/, const Unk_13c5670_arg1* value) {
    Unk_d29c40_set(value->field_8 != 0);
    return 1;
}

struct Unk_13c56a0_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13c56a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13c56a0_arg1, field_10, 0x10);

u64 Unk_d29c60(void*, bool);

// 0x71013c56a0
u64 Unk_13c56a0_call(void* /*unused*/, const Unk_13c56a0_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d29c60(&l8, value->field_10 != 0);
    return r0 & 1;
}

struct Unk_13c56e0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c56e0_arg1, field_8, 0x8);

void Unk_d29e50_set(bool);

// 0x71013c56e0
u32 Unk_13c56e0_call(void* /*unused*/, const Unk_13c56e0_arg1* value) {
    Unk_d29e50_set(value->field_8 != 0);
    return 1;
}

struct Unk_13c5710_arg1 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13c5710_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13c5710_arg1, field_10, 0x10);

u64 Unk_d29e70(void*, bool);

// 0x71013c5710
u64 Unk_13c5710_call(void* /*unused*/, const Unk_13c5710_arg1* value) {
    u64 l8;
    l8 = value->field_8;
    u64 r0 = Unk_d29e70(&l8, value->field_10 != 0);
    return r0 & 1;
}

struct Unk_13c67e0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c67e0_arg1, field_8, 0x8);

void Unk_e38bb0(bool);

// 0x71013c67e0
u32 Unk_13c67e0_call(void* /*unused*/, const Unk_13c67e0_arg1* value) {
    Unk_e38bb0(value->field_8 != 0);
    return 1;
}

struct Unk_13cdb30 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_13cdb30, field_120, 0x120);

// 0x71013cdb30
void Unk_13cdb30_update(Unk_13cdb30* self) {
    if (self->field_120 != 0) {
        return;
    }
    self->field_120 = 3;
}

// 0x71013cee80
void Unk_13cee80_update() {}

struct Unk_13cee90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13cee90_arg1, field_0, 0x0);

struct Unk_13cee90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13cee90, field_0, 0x0);

// 0x71013cee90
void Unk_13cee90_set(const Unk_13cee90* self, Unk_13cee90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_13ceea0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13ceea0_arg1, field_0, 0x0);

struct Unk_13ceea0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13ceea0, field_0, 0x0);

// 0x71013ceea0
void Unk_13ceea0_set(const Unk_13ceea0* self, Unk_13ceea0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27f0214_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f0214_Data, field_18, 0x18);

extern Unk_27f0214_Data Unk_27f0214 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71013d0460
void Unk_13d0460_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f0214.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f0214.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f0214.field_18 = 0xffff;
    Unk_27f0214.field_10 = 0;
    Unk_27f0214.field_8 = r2;
    Unk_27f0214.field_c = 0;
    Unk_27f0214.field_14 = 0xffffffff;
}
