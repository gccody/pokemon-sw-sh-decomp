// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fd7f20 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd7f20, field_60, 0x60);

// 0x7100fd7f20
void Unk_fd7f20_setField60(Unk_fd7f20* self, u64 value) {
    self->field_60 = value;
}

struct Unk_fd7f30 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd7f30, field_68, 0x68);

// 0x7100fd7f30
void Unk_fd7f30_setField68(Unk_fd7f30* self, u64 value) {
    self->field_68 = value;
}

struct Unk_fd7fa0_68 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_fd7fa0_68, field_58, 0x58);

struct Unk_fd7fa0 {
    u8 _0[0x68];
    Unk_fd7fa0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd7fa0, field_68, 0x68);

// 0x7100fd7fa0
u64 Unk_fd7fa0_get(const Unk_fd7fa0* self) {
    return self->field_68->field_58;
}

struct Unk_fd80a0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_fd80a0, field_78, 0x78);

// 0x7100fd80a0
void Unk_fd80a0_setField78(Unk_fd80a0* self, u64 value) {
    self->field_78 = value;
}

struct Unk_fd80b0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_fd80b0, field_78, 0x78);

// 0x7100fd80b0
u64 Unk_fd80b0_getField78(const Unk_fd80b0* self) {
    return self->field_78;
}

struct Unk_fd80c0_68 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_fd80c0_68, field_90, 0x90);

struct Unk_fd80c0 {
    u8 _0[0x68];
    Unk_fd80c0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd80c0, field_68, 0x68);

// 0x7100fd80c0
void Unk_fd80c0_set(const Unk_fd80c0* self) {
    self->field_68->field_90 = 0;
}

struct Unk_fd80d0_68 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_fd80d0_68, field_90, 0x90);

struct Unk_fd80d0 {
    u8 _0[0x68];
    Unk_fd80d0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd80d0, field_68, 0x68);

// 0x7100fd80d0
u32 Unk_fd80d0_get(const Unk_fd80d0* self) {
    return self->field_68->field_90;
}

struct Unk_fd8130_60 {
    u8 _0[0x54];
    u8 field_54;
};
PKMN_OFFSET_ASSERT(Unk_fd8130_60, field_54, 0x54);

struct Unk_fd8130 {
    u8 _0[0x60];
    Unk_fd8130_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd8130, field_60, 0x60);

// 0x7100fd8130
bool Unk_fd8130_check(const Unk_fd8130* self) {
    return self->field_60->field_54 == 2;
}

struct Unk_fd8180_68 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd8180_68, field_60, 0x60);

struct Unk_fd8180 {
    u8 _0[0x68];
    Unk_fd8180_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd8180, field_68, 0x68);

// 0x7100fd8180
u8 Unk_fd8180_get(const Unk_fd8180* self) {
    return self->field_68->field_60;
}

struct Unk_fd82c0_68 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_fd82c0_68, field_a0, 0xa0);

struct Unk_fd82c0 {
    u8 _0[0x68];
    Unk_fd82c0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd82c0, field_68, 0x68);

void Unk_7f4580(void*);
void Unk_fbe550(void*, void*);

// 0x7100fd82c0
void Unk_fd82c0_call(const Unk_fd82c0* self, void* value) {
    Unk_7f4580(&self->field_68->field_a0);
    Unk_fbe550(&self->field_68->field_a0, value);
}

struct Unk_fd84e0_68 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_fd84e0_68, field_88, 0x88);

struct Unk_fd84e0 {
    u8 _0[0x68];
    Unk_fd84e0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd84e0, field_68, 0x68);

// 0x7100fd84e0
void Unk_fd84e0_set(const Unk_fd84e0* self, u32 value) {
    self->field_68->field_88 = value;
}

struct Unk_fd85c0_60 {
    u8 _0[0x18c];
    u8 field_18c;
};
PKMN_OFFSET_ASSERT(Unk_fd85c0_60, field_18c, 0x18c);

struct Unk_fd85c0 {
    u8 _0[0x60];
    Unk_fd85c0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd85c0, field_60, 0x60);

// 0x7100fd85c0
void Unk_fd85c0_set(const Unk_fd85c0* self, u8 value) {
    self->field_60->field_18c = value;
}

struct Unk_fd8650_60 {
    u8 _0[0x18d];
    bool field_18d;
};
PKMN_OFFSET_ASSERT(Unk_fd8650_60, field_18d, 0x18d);

struct Unk_fd8650 {
    u8 _0[0x60];
    Unk_fd8650_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd8650, field_60, 0x60);

// 0x7100fd8650
void Unk_fd8650_set(const Unk_fd8650* self, bool value) {
    self->field_60->field_18d = value;
}

struct Unk_fd86d0_60 {
    u8 _0[0x18e];
    bool field_18e;
};
PKMN_OFFSET_ASSERT(Unk_fd86d0_60, field_18e, 0x18e);

struct Unk_fd86d0 {
    u8 _0[0x60];
    Unk_fd86d0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd86d0, field_60, 0x60);

// 0x7100fd86d0
void Unk_fd86d0_set(const Unk_fd86d0* self, bool value) {
    self->field_60->field_18e = value;
}

struct Unk_fd8710_60 {
    u8 _0[0x197];
    bool field_197;
};
PKMN_OFFSET_ASSERT(Unk_fd8710_60, field_197, 0x197);

struct Unk_fd8710 {
    u8 _0[0x60];
    Unk_fd8710_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd8710, field_60, 0x60);

// 0x7100fd8710
void Unk_fd8710_set(const Unk_fd8710* self, bool value) {
    self->field_60->field_197 = value;
}

struct Unk_fd8770_68 {
    u8 _0[0xda0];
    u8 field_da0;
};
PKMN_OFFSET_ASSERT(Unk_fd8770_68, field_da0, 0xda0);

struct Unk_fd8770 {
    u8 _0[0x68];
    Unk_fd8770_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd8770, field_68, 0x68);

// 0x7100fd8770
u8 Unk_fd8770_get(const Unk_fd8770* self) {
    return self->field_68->field_da0;
}

struct Unk_fd87a0_68 {
    u8 _0[0xde6];
    u8 field_de6;
};
PKMN_OFFSET_ASSERT(Unk_fd87a0_68, field_de6, 0xde6);

struct Unk_fd87a0 {
    u8 _0[0x68];
    Unk_fd87a0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd87a0, field_68, 0x68);

// 0x7100fd87a0
u8* Unk_fd87a0_get(const Unk_fd87a0* self) {
    return &self->field_68->field_de6;
}

struct Unk_27e248c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e248c_Data, field_18, 0x18);

extern Unk_27e248c_Data Unk_27e248c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100fd8a40
void Unk_fd8a40_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e248c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e248c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e248c.field_18 = 0xffff;
    Unk_27e248c.field_10 = 0;
    Unk_27e248c.field_8 = r2;
    Unk_27e248c.field_c = 0;
    Unk_27e248c.field_14 = 0xffffffff;
}
