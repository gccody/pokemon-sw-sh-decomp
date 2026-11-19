// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_16d64e0 {
    u8 _0[0x258];
    u64 field_258;
};
PKMN_OFFSET_ASSERT(Unk_16d64e0, field_258, 0x258);

// 0x71016d64e0
void Unk_16d64e0_set(Unk_16d64e0* self, u64 value) {
    self->field_258 = value;
}

struct Unk_16d8c60 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d8c60, field_8, 0x8);

// 0x71016d8c60
void Unk_16d8c60_set(Unk_16d8c60* self, u32 value) {
    self->field_8 = value;
}

struct Unk_16d8c80 {
    u8 _0[0xc];
    bool field_c;
};
PKMN_OFFSET_ASSERT(Unk_16d8c80, field_c, 0xc);

// 0x71016d8c80
void Unk_16d8c80_set(Unk_16d8c80* self, bool value) {
    self->field_c = value;
}

struct Unk_16d8ca0 {
    u8 _0[0xd];
    bool field_d;
};
PKMN_OFFSET_ASSERT(Unk_16d8ca0, field_d, 0xd);

// 0x71016d8ca0
void Unk_16d8ca0_set(Unk_16d8ca0* self, bool value) {
    self->field_d = value;
}

struct Unk_16d8cc0_arg1 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
    u8 field_b;
    u8 field_c;
    u8 field_d;
    u8 field_e;
    u8 field_f;
};
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_b, 0xb);
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_d, 0xd);
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_16d8cc0_arg1, field_f, 0xf);

struct Unk_16d8cc0 {
    u8 _0[0x670];
    u16 field_670;
    u8 field_672;
    u8 field_673;
    u8 field_674;
    u8 field_675;
    u8 field_676;
    u8 field_677;
};
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_670, 0x670);
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_672, 0x672);
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_673, 0x673);
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_674, 0x674);
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_675, 0x675);
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_676, 0x676);
PKMN_OFFSET_ASSERT(Unk_16d8cc0, field_677, 0x677);

// 0x71016d8cc0
void Unk_16d8cc0_set(Unk_16d8cc0* self, const Unk_16d8cc0_arg1* value) {
    self->field_670 = value->field_8;
    self->field_672 = value->field_a;
    self->field_673 = value->field_b;
    self->field_674 = value->field_c;
    self->field_675 = value->field_d;
    self->field_676 = value->field_e;
    self->field_677 = value->field_f;
}

struct Unk_16d8d10_arg1 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
    u8 field_b;
    u8 field_c;
    u8 field_d;
    u8 field_e;
    u8 field_f;
};
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_b, 0xb);
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_d, 0xd);
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_16d8d10_arg1, field_f, 0xf);

struct Unk_16d8d10 {
    u8 _0[0x680];
    u16 field_680;
    u8 field_682;
    u8 field_683;
    u8 field_684;
    u8 field_685;
    u8 field_686;
    u8 field_687;
};
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_680, 0x680);
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_682, 0x682);
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_683, 0x683);
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_684, 0x684);
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_685, 0x685);
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_686, 0x686);
PKMN_OFFSET_ASSERT(Unk_16d8d10, field_687, 0x687);

// 0x71016d8d10
void Unk_16d8d10_set(Unk_16d8d10* self, const Unk_16d8d10_arg1* value) {
    self->field_680 = value->field_8;
    self->field_682 = value->field_a;
    self->field_683 = value->field_b;
    self->field_684 = value->field_c;
    self->field_685 = value->field_d;
    self->field_686 = value->field_e;
    self->field_687 = value->field_f;
}

struct Unk_16d8d60 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_16d8d60, field_28, 0x28);

// 0x71016d8d60
void Unk_16d8d60_set(Unk_16d8d60* self, u32 value) {
    self->field_28 = value;
}

struct Unk_16d8e10 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_16d8e10, field_30, 0x30);

// 0x71016d8e10
void Unk_16d8e10_set(Unk_16d8e10* self, u64 value) {
    self->field_30 = value;
}

struct Unk_16d8e30 {
    u8 _0[0x2c];
    u16 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_16d8e30, field_2c, 0x2c);

// 0x71016d8e30
void Unk_16d8e30_set(Unk_16d8e30* self, u16 value) {
    self->field_2c = value;
}

struct Unk_16d8e50 {
    u8 _0[0x38];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_16d8e50, field_38, 0x38);

// 0x71016d8e50
void Unk_16d8e50_set(Unk_16d8e50* self, u16 value) {
    self->field_38 = value;
}

struct Unk_16d8e70 {
    u8 _0[0x3a];
    u16 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_16d8e70, field_3a, 0x3a);

// 0x71016d8e70
void Unk_16d8e70_set(Unk_16d8e70* self, u16 value) {
    self->field_3a = value;
}

struct Unk_16da980 {
    u8 _0[0x2c8];
    u8 field_2c8;
};
PKMN_OFFSET_ASSERT(Unk_16da980, field_2c8, 0x2c8);

// 0x71016da980
u8 Unk_16da980_get(const Unk_16da980* self) {
    return self->field_2c8;
}

struct Unk_16ee090 {
    u8 _0[0x554];
    u8 field_554;
};
PKMN_OFFSET_ASSERT(Unk_16ee090, field_554, 0x554);

// 0x71016ee090
u8 Unk_16ee090_get(const Unk_16ee090* self) {
    return self->field_554;
}

struct Unk_16ee0a0 {
    u8 _0[0x550];
    u32 field_550;
};
PKMN_OFFSET_ASSERT(Unk_16ee0a0, field_550, 0x550);

// 0x71016ee0a0
u32 Unk_16ee0a0_get(const Unk_16ee0a0* self) {
    return self->field_550;
}

struct Unk_16ee0b0 {
    u8 _0[0x555];
    u8 field_555;
};
PKMN_OFFSET_ASSERT(Unk_16ee0b0, field_555, 0x555);

// 0x71016ee0b0
u8 Unk_16ee0b0_get(const Unk_16ee0b0* self) {
    return self->field_555;
}

struct Unk_16ee0c0 {
    u8 _0[0x558];
    u32 field_558;
    u8 _55c[0x4];
    u64 field_560;
};
PKMN_OFFSET_ASSERT(Unk_16ee0c0, field_558, 0x558);
PKMN_OFFSET_ASSERT(Unk_16ee0c0, field_560, 0x560);

// 0x71016ee0c0
void Unk_16ee0c0_set(Unk_16ee0c0* self, u32 value, u64 arg2) {
    self->field_558 = value;
    self->field_560 = arg2;
}

struct Unk_16ee570 {
    u8 _0[0x2d0];
    u8 field_2d0;
};
PKMN_OFFSET_ASSERT(Unk_16ee570, field_2d0, 0x2d0);

// 0x71016ee570
u8 Unk_16ee570_get(const Unk_16ee570* self) {
    return self->field_2d0;
}

struct Unk_16ef590_2d8 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x644];
    u32 field_658;
    u8 _65c[0x644];
    u32 field_ca0;
    u8 _ca4[0x644];
    u32 field_12e8;
};
PKMN_OFFSET_ASSERT(Unk_16ef590_2d8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_16ef590_2d8, field_658, 0x658);
PKMN_OFFSET_ASSERT(Unk_16ef590_2d8, field_ca0, 0xca0);
PKMN_OFFSET_ASSERT(Unk_16ef590_2d8, field_12e8, 0x12e8);
struct Unk_16ef590 {
    u8 _0[0x2d8];
    Unk_16ef590_2d8* field_2d8;
};
PKMN_OFFSET_ASSERT(Unk_16ef590, field_2d8, 0x2d8);

// 0x71016ef590
bool Unk_16ef590_get(const Unk_16ef590* self, u32 value) {
    if (self->field_2d8 != nullptr) {
        if (self->field_2d8->field_10 == value) {
            return 1;
        }
        if (self->field_2d8->field_658 == value) {
            return 1;
        }
        if (self->field_2d8->field_ca0 == value) {
            return 1;
        }
        return self->field_2d8->field_12e8 == value;
    }
    return 0;
}

struct Unk_16ef5f0 {
    u8 _0[0x2d8];
    u64 field_2d8;
};
PKMN_OFFSET_ASSERT(Unk_16ef5f0, field_2d8, 0x2d8);

void Unk_16ef600(u64);

// 0x71016ef5f0
void Unk_16ef5f0_call(const Unk_16ef5f0* self) {
    if (self->field_2d8 != 0) {
        Unk_16ef600(self->field_2d8);
    }
}

struct Unk_16ef860 {
    u8 _0[0x2d8];
    u64 field_2d8;
};
PKMN_OFFSET_ASSERT(Unk_16ef860, field_2d8, 0x2d8);

// 0x71016ef860
u32 Unk_16ef860_get(const Unk_16ef860* self) {
    return self->field_2d8 == 0 ? 0 : 4;
}

struct Unk_16f1420 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16f1420, field_10, 0x10);

// 0x71016f1420
const u8* Unk_16f1420_get(const Unk_16f1420* self) {
    return &self->field_10;
}

struct Unk_16f1430 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16f1430, field_10, 0x10);

// 0x71016f1430
const u8* Unk_16f1430_get(const Unk_16f1430* self) {
    return &self->field_10;
}

struct Unk_16f1440 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_16f1440, field_20, 0x20);

// 0x71016f1440
const u8* Unk_16f1440_get(const Unk_16f1440* self) {
    return &self->field_20;
}

struct Unk_16f14a0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_16f14a0, field_30, 0x30);

// 0x71016f14a0
const u8* Unk_16f14a0_get(const Unk_16f14a0* self) {
    return &self->field_30;
}

struct Unk_16f14b0 {
    u8 _0[0x670];
    u8 field_670;
};
PKMN_OFFSET_ASSERT(Unk_16f14b0, field_670, 0x670);

// 0x71016f14b0
const u8* Unk_16f14b0_get(const Unk_16f14b0* self) {
    return &self->field_670;
}
