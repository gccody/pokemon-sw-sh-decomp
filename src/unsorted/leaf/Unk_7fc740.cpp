// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7fc740 {
    u32 field_0;
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc740, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc740, field_4, 0x4);

// 0x71007fc740
void Unk_7fc740_set(Unk_7fc740* self) {
    self->field_4 = 0;
    self->field_0 = 0;
}

struct Unk_7fc750_arg1 {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc750_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc750_arg1, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_7fc750_arg1, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_7fc750_arg1, field_3, 0x3);
PKMN_OFFSET_ASSERT(Unk_7fc750_arg1, field_4, 0x4);

struct Unk_7fc750 {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc750, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc750, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_7fc750, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_7fc750, field_3, 0x3);
PKMN_OFFSET_ASSERT(Unk_7fc750, field_4, 0x4);

// 0x71007fc750
void Unk_7fc750_set(Unk_7fc750* self, const Unk_7fc750_arg1* value) {
    self->field_0 = value->field_0;
    self->field_1 = value->field_1;
    self->field_2 = value->field_2;
    self->field_3 = value->field_3;
    self->field_4 = value->field_4;
}

struct Unk_7fc7d0 {
    u8 _0[0x4];
    u8 field_4;
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_7fc7d0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7fc7d0, field_5, 0x5);

// 0x71007fc7d0
void Unk_7fc7d0_set(Unk_7fc7d0* self) {
    self->field_4 = self->field_5;
}

struct Unk_7fc7e0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7fc7e0, field_0, 0x0);

// 0x71007fc7e0
void Unk_7fc7e0_set(Unk_7fc7e0* self) {
    self->field_0 = 1;
}

struct Unk_7fc7f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7fc7f0, field_0, 0x0);

// 0x71007fc7f0
u8 Unk_7fc7f0_getField0(const Unk_7fc7f0* self) {
    return self->field_0;
}

struct Unk_7fc800 {
    u8 field_0;
    u8 _1[0x1];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc800, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc800, field_2, 0x2);

// 0x71007fc800
bool Unk_7fc800_check(const Unk_7fc800* self) {
    if (self->field_0 == 0) {
        return false;
    }
    return self->field_2 != 0;
}

struct Unk_7fc820 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc820, field_2, 0x2);

// 0x71007fc820
bool Unk_7fc820_check(const Unk_7fc820* self) {
    return self->field_2 == 0;
}

struct Unk_7fc830 {
    u8 field_0;
    u8 _1[0x1];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc830, field_2, 0x2);

// 0x71007fc830
bool Unk_7fc830_check(const Unk_7fc830* self) {
    if (self->field_0 == 0) {
        return false;
    }
    return self->field_2 == 0;
}

struct Unk_7fc850 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_7fc850, field_1, 0x1);

// 0x71007fc850
u8 Unk_7fc850_getField1(const Unk_7fc850* self) {
    return self->field_1;
}

struct Unk_7fc860 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc860, field_2, 0x2);

// 0x71007fc860
u8 Unk_7fc860_getField2(const Unk_7fc860* self) {
    return self->field_2;
}

struct Unk_7fc870 {
    u8 _0[0x1];
    u8 field_1;
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc870, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_7fc870, field_2, 0x2);

// 0x71007fc870
void Unk_7fc870_set(Unk_7fc870* self, u8 value) {
    self->field_2 = self->field_1 < (value) ? self->field_1 : value;
}

struct Unk_7fc8b0 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc8b0, field_2, 0x2);

// 0x71007fc8b0
void Unk_7fc8b0_set(Unk_7fc8b0* self, u8 value) {
    self->field_2 = (self->field_2 < (value) ? value : self->field_2) - value;
}

struct Unk_7fc8d0 {
    u8 _0[0x1];
    u8 field_1;
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc8d0, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_7fc8d0, field_2, 0x2);

// 0x71007fc8d0
bool Unk_7fc8d0_check(const Unk_7fc8d0* self) {
    return self->field_1 <= self->field_2;
}

struct Unk_7fc8f0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc8f0, field_4, 0x4);

// 0x71007fc8f0
u8 Unk_7fc8f0_getField4(const Unk_7fc8f0* self) {
    return self->field_4;
}

struct Unk_7fc900 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc900, field_4, 0x4);

// 0x71007fc900
void Unk_7fc900_set(Unk_7fc900* self) {
    if (self->field_4 != 0) {
        self->field_4 = self->field_4 - 1;
    }
}

struct Unk_7fc920 {
    u8 _0[0x5];
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_7fc920, field_5, 0x5);

// 0x71007fc920
void Unk_7fc920_set(Unk_7fc920* self) {
    if (self->field_5 != 0) {
        self->field_5 = self->field_5 - 1;
    }
}

struct Unk_27ced94_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ced94_Data, field_18, 0x18);

extern Unk_27ced94_Data Unk_27ced94 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007fcf80
void Unk_7fcf80_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ced94.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ced94.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ced94.field_18 = 0xffff;
    Unk_27ced94.field_10 = 0;
    Unk_27ced94.field_8 = r2;
    Unk_27ced94.field_c = 0;
    Unk_27ced94.field_14 = 0xffffffff;
}
