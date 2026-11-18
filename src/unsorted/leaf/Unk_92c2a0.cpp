// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_92c2a0_0_88 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_92c2a0_0_88, field_5cc, 0x5cc);

struct Unk_92c2a0_0 {
    u8 _0[0x88];
    Unk_92c2a0_0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_92c2a0_0, field_88, 0x88);

struct Unk_92c2a0 {
    Unk_92c2a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c2a0, field_0, 0x0);

// 0x710092c2a0
bool Unk_92c2a0_check(const Unk_92c2a0* self) {
    return self->field_0->field_88->field_5cc == 2;
}

// 0x710092c2c0
void Unk_92c2c0_update() {}

struct Unk_92c2d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c2d0_arg1, field_0, 0x0);

struct Unk_92c2d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c2d0, field_0, 0x0);

// 0x710092c2d0
void Unk_92c2d0_set(const Unk_92c2d0* self, Unk_92c2d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c2e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c2e0_arg1, field_0, 0x0);

struct Unk_92c2e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c2e0, field_0, 0x0);

// 0x710092c2e0
void Unk_92c2e0_set(const Unk_92c2e0* self, Unk_92c2e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c2f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c2f0, field_0, 0x0);

void Unk_92b890(u64);

// 0x710092c2f0
void Unk_92c2f0_call(const Unk_92c2f0* self) {
    Unk_92b890(self->field_0);
}

// 0x710092c300
void Unk_92c300_update() {}

struct Unk_92c310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c310_arg1, field_0, 0x0);

struct Unk_92c310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c310, field_0, 0x0);

// 0x710092c310
void Unk_92c310_set(const Unk_92c310* self, Unk_92c310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c320_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c320_arg1, field_0, 0x0);

struct Unk_92c320 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c320, field_0, 0x0);

// 0x710092c320
void Unk_92c320_set(const Unk_92c320* self, Unk_92c320_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710092c370
void Unk_92c370_update() {}

struct Unk_92c380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c380_arg1, field_0, 0x0);

struct Unk_92c380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c380, field_0, 0x0);

// 0x710092c380
void Unk_92c380_set(const Unk_92c380* self, Unk_92c380_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c390_arg1, field_0, 0x0);

struct Unk_92c390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c390, field_0, 0x0);

// 0x710092c390
void Unk_92c390_set(const Unk_92c390* self, Unk_92c390_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710092c590
void Unk_92c590_update() {}

struct Unk_92c650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c650_arg1, field_0, 0x0);

struct Unk_92c650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c650, field_0, 0x0);

// 0x710092c650
void Unk_92c650_set(const Unk_92c650* self, Unk_92c650_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c660_arg1, field_0, 0x0);

struct Unk_92c660 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c660, field_0, 0x0);

// 0x710092c660
void Unk_92c660_set(const Unk_92c660* self, Unk_92c660_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c670_0_88 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_92c670_0_88, field_5cc, 0x5cc);

struct Unk_92c670_0 {
    u8 _0[0x88];
    Unk_92c670_0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_92c670_0, field_88, 0x88);

struct Unk_92c670 {
    Unk_92c670_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c670, field_0, 0x0);

// 0x710092c670
bool Unk_92c670_check(const Unk_92c670* self) {
    return self->field_0->field_88->field_5cc == 2;
}

// 0x710092c690
void Unk_92c690_update() {}

struct Unk_92c6a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c6a0_arg1, field_0, 0x0);

struct Unk_92c6a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c6a0, field_0, 0x0);

// 0x710092c6a0
void Unk_92c6a0_set(const Unk_92c6a0* self, Unk_92c6a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c6b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c6b0_arg1, field_0, 0x0);

struct Unk_92c6b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c6b0, field_0, 0x0);

// 0x710092c6b0
void Unk_92c6b0_set(const Unk_92c6b0* self, Unk_92c6b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710092c760
void Unk_92c760_update() {}

struct Unk_92c770_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c770_arg1, field_0, 0x0);

struct Unk_92c770 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c770, field_0, 0x0);

// 0x710092c770
void Unk_92c770_set(const Unk_92c770* self, Unk_92c770_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c780_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c780_arg1, field_0, 0x0);

struct Unk_92c780 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c780, field_0, 0x0);

// 0x710092c780
void Unk_92c780_set(const Unk_92c780* self, Unk_92c780_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710092c7e0
void Unk_92c7e0_update() {}

struct Unk_92c7f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c7f0_arg1, field_0, 0x0);

struct Unk_92c7f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c7f0, field_0, 0x0);

// 0x710092c7f0
void Unk_92c7f0_set(const Unk_92c7f0* self, Unk_92c7f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c800_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c800_arg1, field_0, 0x0);

struct Unk_92c800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c800, field_0, 0x0);

// 0x710092c800
void Unk_92c800_set(const Unk_92c800* self, Unk_92c800_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710092c980
void Unk_92c980_update() {}

struct Unk_92c990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c990_arg1, field_0, 0x0);

struct Unk_92c990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c990, field_0, 0x0);

// 0x710092c990
void Unk_92c990_set(const Unk_92c990* self, Unk_92c990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92c9a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c9a0_arg1, field_0, 0x0);

struct Unk_92c9a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92c9a0, field_0, 0x0);

// 0x710092c9a0
void Unk_92c9a0_set(const Unk_92c9a0* self, Unk_92c9a0_arg1* value) {
    value->field_0 = self->field_0;
}
