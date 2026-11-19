// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c6810 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_8c6810, field_64, 0x64);

// 0x71008c6810
u8 Unk_8c6810_getField64(const Unk_8c6810* self) {
    return self->field_64;
}

struct Unk_8c6820 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_8c6820, field_5c, 0x5c);

// 0x71008c6820
u32 Unk_8c6820_getField5c(const Unk_8c6820* self) {
    return self->field_5c;
}

struct Unk_8c2630;
struct Unk_8c82b0 {
    u8 _0[0xb8];
    Unk_8c2630* field_b8;
};
PKMN_OFFSET_ASSERT(Unk_8c82b0, field_b8, 0xb8);

u8 Unk_8c2630_getField288(const Unk_8c2630*);

// 0x71008c82b0
void Unk_8c82b0_call(const Unk_8c82b0* self) {
    Unk_8c2630_getField288(self->field_b8);
}

struct Unk_8c82c0 {
    u8 _0[0x1a1];
    u8 field_1a1;
};
PKMN_OFFSET_ASSERT(Unk_8c82c0, field_1a1, 0x1a1);

// 0x71008c82c0
u8 Unk_8c82c0_getField1a1(const Unk_8c82c0* self) {
    return self->field_1a1;
}

struct Unk_8c82d0 {
    u8 _0[0x198];
    u32 field_198;
};
PKMN_OFFSET_ASSERT(Unk_8c82d0, field_198, 0x198);

// 0x71008c82d0
u32 Unk_8c82d0_getField198(const Unk_8c82d0* self) {
    return self->field_198;
}

struct Unk_8c82e0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c82e0_arg1, field_0, 0x0);

struct Unk_8c82e0_arg2 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c82e0_arg2, field_0, 0x0);

struct Unk_8c82e0 {
    u8 _0[0x19c];
    u8 field_19c;
    u8 field_19d;
    u8 _19e[0x3];
    u8 field_1a1;
};
PKMN_OFFSET_ASSERT(Unk_8c82e0, field_19c, 0x19c);
PKMN_OFFSET_ASSERT(Unk_8c82e0, field_19d, 0x19d);
PKMN_OFFSET_ASSERT(Unk_8c82e0, field_1a1, 0x1a1);

// 0x71008c82e0
void Unk_8c82e0_set(const Unk_8c82e0* self, Unk_8c82e0_arg1* value, Unk_8c82e0_arg2* arg2) {
    if (self->field_1a1 != 0) {
        value->field_0 = self->field_19c;
        arg2->field_0 = self->field_19d;
    }
}

struct Unk_27d173c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d173c_Data, field_18, 0x18);

extern Unk_27d173c_Data Unk_27d173c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008c8300
void Unk_8c8300_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d173c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d173c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d173c.field_18 = 0xffff;
    Unk_27d173c.field_10 = 0;
    Unk_27d173c.field_8 = r2;
    Unk_27d173c.field_c = 0;
    Unk_27d173c.field_14 = 0xffffffff;
}
