// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100fae130
void Unk_fae130_update() {}

struct Unk_fae140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae140_arg1, field_0, 0x0);

struct Unk_fae140 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae140, field_0, 0x0);

// 0x7100fae140
void Unk_fae140_set(const Unk_fae140* self, Unk_fae140_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae150_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae150_arg1, field_0, 0x0);

struct Unk_fae150 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae150, field_0, 0x0);

// 0x7100fae150
void Unk_fae150_set(const Unk_fae150* self, Unk_fae150_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae160_0 {
    u8 _0[0x3a0];
    u32 field_3a0;
};
PKMN_OFFSET_ASSERT(Unk_fae160_0, field_3a0, 0x3a0);

struct Unk_fae160 {
    Unk_fae160_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae160, field_0, 0x0);

void Unk_fadc00(void*, u32);

// 0x7100fae160
void Unk_fae160_call(const Unk_fae160* self) {
    Unk_fadc00(self->field_0, self->field_0->field_3a0);
}

// 0x7100fae170
void Unk_fae170_update() {}

struct Unk_fae180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae180_arg1, field_0, 0x0);

struct Unk_fae180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae180, field_0, 0x0);

// 0x7100fae180
void Unk_fae180_set(const Unk_fae180* self, Unk_fae180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae190_arg1, field_0, 0x0);

struct Unk_fae190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae190, field_0, 0x0);

// 0x7100fae190
void Unk_fae190_set(const Unk_fae190* self, Unk_fae190_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fae1a0_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fae1a0_0, field_360, 0x360);

struct Unk_fae1a0 {
    Unk_fae1a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae1a0, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fae1a0
void Unk_fae1a0_call(const Unk_fae1a0* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fae1b0
void Unk_fae1b0_update() {}

struct Unk_fae1c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae1c0_arg1, field_0, 0x0);

struct Unk_fae1c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae1c0, field_0, 0x0);

// 0x7100fae1c0
void Unk_fae1c0_set(const Unk_fae1c0* self, Unk_fae1c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae1d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae1d0_arg1, field_0, 0x0);

struct Unk_fae1d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae1d0, field_0, 0x0);

// 0x7100fae1d0
void Unk_fae1d0_set(const Unk_fae1d0* self, Unk_fae1d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fae200
void Unk_fae200_update() {}

struct Unk_fae210_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae210_arg1, field_0, 0x0);

struct Unk_fae210 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae210, field_0, 0x0);

// 0x7100fae210
void Unk_fae210_set(const Unk_fae210* self, Unk_fae210_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae220_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae220_arg1, field_0, 0x0);

struct Unk_fae220 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae220, field_0, 0x0);

// 0x7100fae220
void Unk_fae220_set(const Unk_fae220* self, Unk_fae220_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fae230_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fae230_0, field_360, 0x360);

struct Unk_fae230 {
    Unk_fae230_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae230, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fae230
void Unk_fae230_call(const Unk_fae230* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fae240
void Unk_fae240_update() {}

struct Unk_fae250_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae250_arg1, field_0, 0x0);

struct Unk_fae250 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae250, field_0, 0x0);

// 0x7100fae250
void Unk_fae250_set(const Unk_fae250* self, Unk_fae250_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae260_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae260_arg1, field_0, 0x0);

struct Unk_fae260 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae260, field_0, 0x0);

// 0x7100fae260
void Unk_fae260_set(const Unk_fae260* self, Unk_fae260_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fae290
void Unk_fae290_update() {}

struct Unk_fae2a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2a0_arg1, field_0, 0x0);

struct Unk_fae2a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2a0, field_0, 0x0);

// 0x7100fae2a0
void Unk_fae2a0_set(const Unk_fae2a0* self, Unk_fae2a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae2b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2b0_arg1, field_0, 0x0);

struct Unk_fae2b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2b0, field_0, 0x0);

// 0x7100fae2b0
void Unk_fae2b0_set(const Unk_fae2b0* self, Unk_fae2b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fae2c0_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fae2c0_0, field_360, 0x360);

struct Unk_fae2c0 {
    Unk_fae2c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2c0, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fae2c0
void Unk_fae2c0_call(const Unk_fae2c0* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fae2d0
void Unk_fae2d0_update() {}

struct Unk_fae2e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2e0_arg1, field_0, 0x0);

struct Unk_fae2e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2e0, field_0, 0x0);

// 0x7100fae2e0
void Unk_fae2e0_set(const Unk_fae2e0* self, Unk_fae2e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae2f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2f0_arg1, field_0, 0x0);

struct Unk_fae2f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae2f0, field_0, 0x0);

// 0x7100fae2f0
void Unk_fae2f0_set(const Unk_fae2f0* self, Unk_fae2f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae4b0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae4b0, field_8, 0x8);

// 0x7100fae4b0
void Unk_fae4b0_call(Unk_fae4b0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

// 0x7100fae4f0
void Unk_fae4f0_update() {}

// 0x7100fae500
void Unk_fae500_update() {}

// 0x7100fae510
void Unk_fae510_update() {}

// 0x7100fae520
void Unk_fae520_update() {}

// 0x7100fae530
void Unk_fae530_update() {}

// 0x7100fae540
void Unk_fae540_update() {}

// 0x7100fae550
void Unk_fae550_update() {}

// 0x7100fae560
void Unk_fae560_update() {}

struct Unk_fae570_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae570_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae570_arg1, field_8, 0x8);

struct Unk_fae570 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae570, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae570, field_8, 0x8);

// 0x7100fae570
void Unk_fae570_call(const Unk_fae570* self, Unk_fae570_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fae5a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae5a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae5a0_arg1, field_8, 0x8);

struct Unk_fae5a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae5a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae5a0, field_8, 0x8);

// 0x7100fae5a0
void Unk_fae5a0_call(const Unk_fae5a0* self, Unk_fae5a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fae670 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae670, field_8, 0x8);

// 0x7100fae670
void Unk_fae670_call(Unk_fae670* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fae6b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae6b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae6b0_arg1, field_8, 0x8);

struct Unk_fae6b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae6b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae6b0, field_8, 0x8);

// 0x7100fae6b0
void Unk_fae6b0_call(const Unk_fae6b0* self, Unk_fae6b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fae6e0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae6e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae6e0_arg1, field_8, 0x8);

struct Unk_fae6e0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fae6e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fae6e0, field_8, 0x8);

// 0x7100fae6e0
void Unk_fae6e0_call(const Unk_fae6e0* self, Unk_fae6e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100fae730
void Unk_fae730_update() {}

struct Unk_fae740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae740_arg1, field_0, 0x0);

struct Unk_fae740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae740, field_0, 0x0);

// 0x7100fae740
void Unk_fae740_set(const Unk_fae740* self, Unk_fae740_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae750_arg1, field_0, 0x0);

struct Unk_fae750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae750, field_0, 0x0);

// 0x7100fae750
void Unk_fae750_set(const Unk_fae750* self, Unk_fae750_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fae760
void Unk_fae760_update() {}

// 0x7100fae770
void Unk_fae770_update() {}

// 0x7100fae780
void Unk_fae780_update() {}

// 0x7100fae790
void Unk_fae790_update() {}

// 0x7100fae7c0
void Unk_fae7c0_update() {}

struct Unk_fae7d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae7d0_arg1, field_0, 0x0);

struct Unk_fae7d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae7d0, field_0, 0x0);

// 0x7100fae7d0
void Unk_fae7d0_set(const Unk_fae7d0* self, Unk_fae7d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae7e0_arg1, field_0, 0x0);

struct Unk_fae7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae7e0, field_0, 0x0);

// 0x7100fae7e0
void Unk_fae7e0_set(const Unk_fae7e0* self, Unk_fae7e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fae7f0
void Unk_fae7f0_update() {}

// 0x7100fae800
void Unk_fae800_update() {}

// 0x7100fae810
void Unk_fae810_update() {}

// 0x7100fae820
void Unk_fae820_update() {}

// 0x7100fae850
void Unk_fae850_update() {}

struct Unk_fae860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae860_arg1, field_0, 0x0);

struct Unk_fae860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae860, field_0, 0x0);

// 0x7100fae860
void Unk_fae860_set(const Unk_fae860* self, Unk_fae860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae870_arg1, field_0, 0x0);

struct Unk_fae870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae870, field_0, 0x0);

// 0x7100fae870
void Unk_fae870_set(const Unk_fae870* self, Unk_fae870_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fae880
void Unk_fae880_update() {}

// 0x7100fae890
void Unk_fae890_update() {}

// 0x7100fae8a0
void Unk_fae8a0_update() {}

// 0x7100fae8b0
void Unk_fae8b0_update() {}

// 0x7100fae8e0
void Unk_fae8e0_update() {}

struct Unk_fae8f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae8f0_arg1, field_0, 0x0);

struct Unk_fae8f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae8f0, field_0, 0x0);

// 0x7100fae8f0
void Unk_fae8f0_set(const Unk_fae8f0* self, Unk_fae8f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fae900_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae900_arg1, field_0, 0x0);

struct Unk_fae900 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae900, field_0, 0x0);

// 0x7100fae900
void Unk_fae900_set(const Unk_fae900* self, Unk_fae900_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fae910
void Unk_fae910_update() {}

// 0x7100fae920
void Unk_fae920_update() {}

// 0x7100fae930
void Unk_fae930_update() {}

// 0x7100fae940
void Unk_fae940_update() {}

// 0x7100fae9e0
void Unk_fae9e0_update() {}

struct Unk_fae9f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae9f0_arg1, field_0, 0x0);

struct Unk_fae9f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae9f0, field_0, 0x0);

// 0x7100fae9f0
void Unk_fae9f0_set(const Unk_fae9f0* self, Unk_fae9f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faea00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea00_arg1, field_0, 0x0);

struct Unk_faea00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea00, field_0, 0x0);

// 0x7100faea00
void Unk_faea00_set(const Unk_faea00* self, Unk_faea00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faea50
void Unk_faea50_update() {}

struct Unk_faea60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea60_arg1, field_0, 0x0);

struct Unk_faea60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea60, field_0, 0x0);

// 0x7100faea60
void Unk_faea60_set(const Unk_faea60* self, Unk_faea60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faea70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea70_arg1, field_0, 0x0);

struct Unk_faea70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea70, field_0, 0x0);

// 0x7100faea70
void Unk_faea70_set(const Unk_faea70* self, Unk_faea70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_faea80_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_faea80_0, field_360, 0x360);

struct Unk_faea80 {
    Unk_faea80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_faea80, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100faea80
void Unk_faea80_call(const Unk_faea80* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100faea90
void Unk_faea90_update() {}

struct Unk_faeaa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeaa0_arg1, field_0, 0x0);

struct Unk_faeaa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeaa0, field_0, 0x0);

// 0x7100faeaa0
void Unk_faeaa0_set(const Unk_faeaa0* self, Unk_faeaa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faeab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeab0_arg1, field_0, 0x0);

struct Unk_faeab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeab0, field_0, 0x0);

// 0x7100faeab0
void Unk_faeab0_set(const Unk_faeab0* self, Unk_faeab0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faeae0
void Unk_faeae0_update() {}

struct Unk_faeaf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeaf0_arg1, field_0, 0x0);

struct Unk_faeaf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeaf0, field_0, 0x0);

// 0x7100faeaf0
void Unk_faeaf0_set(const Unk_faeaf0* self, Unk_faeaf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faeb00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb00_arg1, field_0, 0x0);

struct Unk_faeb00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb00, field_0, 0x0);

// 0x7100faeb00
void Unk_faeb00_set(const Unk_faeb00* self, Unk_faeb00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faeb50
void Unk_faeb50_update() {}

struct Unk_faeb60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb60_arg1, field_0, 0x0);

struct Unk_faeb60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb60, field_0, 0x0);

// 0x7100faeb60
void Unk_faeb60_set(const Unk_faeb60* self, Unk_faeb60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faeb70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb70_arg1, field_0, 0x0);

struct Unk_faeb70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb70, field_0, 0x0);

// 0x7100faeb70
void Unk_faeb70_set(const Unk_faeb70* self, Unk_faeb70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_faeb80_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_faeb80_0, field_360, 0x360);

struct Unk_faeb80 {
    Unk_faeb80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeb80, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100faeb80
void Unk_faeb80_call(const Unk_faeb80* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100faeb90
void Unk_faeb90_update() {}

struct Unk_faeba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeba0_arg1, field_0, 0x0);

struct Unk_faeba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faeba0, field_0, 0x0);

// 0x7100faeba0
void Unk_faeba0_set(const Unk_faeba0* self, Unk_faeba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faebb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faebb0_arg1, field_0, 0x0);

struct Unk_faebb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faebb0, field_0, 0x0);

// 0x7100faebb0
void Unk_faebb0_set(const Unk_faebb0* self, Unk_faebb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faec50
void Unk_faec50_update() {}

struct Unk_faec60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faec60_arg1, field_0, 0x0);

struct Unk_faec60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faec60, field_0, 0x0);

// 0x7100faec60
void Unk_faec60_set(const Unk_faec60* self, Unk_faec60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faec70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faec70_arg1, field_0, 0x0);

struct Unk_faec70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faec70, field_0, 0x0);

// 0x7100faec70
void Unk_faec70_set(const Unk_faec70* self, Unk_faec70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faec80
void Unk_faec80_update() {}

// 0x7100faec90
void Unk_faec90_update() {}

// 0x7100faeca0
void Unk_faeca0_update() {}

// 0x7100faecb0
void Unk_faecb0_update() {}

// 0x7100faed50
void Unk_faed50_update() {}

struct Unk_faed60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faed60_arg1, field_0, 0x0);

struct Unk_faed60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faed60, field_0, 0x0);

// 0x7100faed60
void Unk_faed60_set(const Unk_faed60* self, Unk_faed60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_faed70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faed70_arg1, field_0, 0x0);

struct Unk_faed70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_faed70, field_0, 0x0);

// 0x7100faed70
void Unk_faed70_set(const Unk_faed70* self, Unk_faed70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100faed80
void Unk_faed80_update() {}

// 0x7100faed90
void Unk_faed90_update() {}

// 0x7100faeda0
void Unk_faeda0_update() {}

// 0x7100faedb0
void Unk_faedb0_update() {}
