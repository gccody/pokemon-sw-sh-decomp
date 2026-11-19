// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14cc8d0;
struct Unk_1456cc0_0 {
    u8 _0[0x708];
    Unk_14cc8d0* field_708;
};
PKMN_OFFSET_ASSERT(Unk_1456cc0_0, field_708, 0x708);

struct Unk_1456cc0 {
    Unk_1456cc0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456cc0, field_0, 0x0);

void Unk_14cc8d0_call(const Unk_14cc8d0*);

// 0x7101456cc0
void Unk_1456cc0_call(const Unk_1456cc0* self) {
    Unk_14cc8d0_call(self->field_0->field_708);
}

// 0x7101456cd0
void Unk_1456cd0_update() {}

struct Unk_1456ce0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456ce0_arg1, field_0, 0x0);

struct Unk_1456ce0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456ce0, field_0, 0x0);

// 0x7101456ce0
void Unk_1456ce0_set(const Unk_1456ce0* self, Unk_1456ce0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1456cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456cf0_arg1, field_0, 0x0);

struct Unk_1456cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456cf0, field_0, 0x0);

// 0x7101456cf0
void Unk_1456cf0_set(const Unk_1456cf0* self, Unk_1456cf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27f0c4c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f0c4c_Data, field_18, 0x18);

extern Unk_27f0c4c_Data Unk_27f0c4c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101457eb0
void Unk_1457eb0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f0c4c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f0c4c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f0c4c.field_18 = 0xffff;
    Unk_27f0c4c.field_10 = 0;
    Unk_27f0c4c.field_8 = r2;
    Unk_27f0c4c.field_c = 0;
    Unk_27f0c4c.field_14 = 0xffffffff;
}
