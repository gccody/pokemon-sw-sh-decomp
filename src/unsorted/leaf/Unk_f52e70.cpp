// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_eb6530(void*);

// 0x7100f52e70
u32 Unk_f52e70_call(void* self) {
    u32 r0 = Unk_eb6530(self);
    return ~r0 & 1;
}

struct Unk_f52f50 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f52f50, field_5cc, 0x5cc);

// 0x7100f52f50
void Unk_f52f50_clearField5cc(Unk_f52f50* self) {
    self->field_5cc = 0;
}

void Unk_f530a0(void*, u64, u64);

// 0x7100f53060
void Unk_f53060_call(void* self, bool value) {
    if ((value) != 0) {
        Unk_f530a0(self, 0x30858e87c637690c, 0x3de4ebb25b188dbc);
        return;
    }
    Unk_f530a0(self, 0x307b9c87c62f2c51, 0x3de4ebb25b188dbc);
}

struct Unk_f531c0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f531c0, field_5cc, 0x5cc);

// 0x7100f531c0
u32 Unk_f531c0_getField5cc(const Unk_f531c0* self) {
    return self->field_5cc;
}

struct Unk_27e1454_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1454_Data, field_18, 0x18);

extern Unk_27e1454_Data Unk_27e1454 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f54760
void Unk_f54760_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1454.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1454.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1454.field_18 = 0xffff;
    Unk_27e1454.field_10 = 0;
    Unk_27e1454.field_8 = r2;
    Unk_27e1454.field_c = 0;
    Unk_27e1454.field_14 = 0xffffffff;
}
