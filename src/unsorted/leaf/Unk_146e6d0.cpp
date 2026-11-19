// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_146e6d0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e6d0, field_8, 0x8);

// 0x710146e6d0
void Unk_146e6d0_call(Unk_146e6d0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_146e710_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e710_arg1, field_8, 0x8);

struct Unk_146e710 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e710, field_8, 0x8);

// 0x710146e710
void Unk_146e710_call(const Unk_146e710* self, Unk_146e710_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146e740_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e740_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e740_arg1, field_8, 0x8);

struct Unk_146e740 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e740, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e740, field_8, 0x8);

// 0x710146e740
void Unk_146e740_call(const Unk_146e740* self, Unk_146e740_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146e950 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e950, field_8, 0x8);

// 0x710146e950
void Unk_146e950_call(Unk_146e950* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_146e990_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e990_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e990_arg1, field_8, 0x8);

struct Unk_146e990 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e990, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e990, field_8, 0x8);

// 0x710146e990
void Unk_146e990_call(const Unk_146e990* self, Unk_146e990_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146e9c0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e9c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e9c0_arg1, field_8, 0x8);

struct Unk_146e9c0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146e9c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146e9c0, field_8, 0x8);

// 0x710146e9c0
void Unk_146e9c0_call(const Unk_146e9c0* self, Unk_146e9c0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146f910 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146f910, field_8, 0x8);

// 0x710146f910
void Unk_146f910_call(Unk_146f910* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_146f950_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146f950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146f950_arg1, field_8, 0x8);

struct Unk_146f950 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146f950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146f950, field_8, 0x8);

// 0x710146f950
void Unk_146f950_call(const Unk_146f950* self, Unk_146f950_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146f980_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146f980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146f980_arg1, field_8, 0x8);

struct Unk_146f980 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146f980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146f980, field_8, 0x8);

// 0x710146f980
void Unk_146f980_call(const Unk_146f980* self, Unk_146f980_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146fb90 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146fb90, field_8, 0x8);

// 0x710146fb90
void Unk_146fb90_call(Unk_146fb90* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_146fbd0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146fbd0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146fbd0_arg1, field_8, 0x8);

struct Unk_146fbd0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146fbd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146fbd0, field_8, 0x8);

// 0x710146fbd0
void Unk_146fbd0_call(const Unk_146fbd0* self, Unk_146fbd0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_146fc00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146fc00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146fc00_arg1, field_8, 0x8);

struct Unk_146fc00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_146fc00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_146fc00, field_8, 0x8);

// 0x710146fc00
void Unk_146fc00_call(const Unk_146fc00* self, Unk_146fc00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1470a40_0 {
    u8 _0[0x5e0];
    u32 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_1470a40_0, field_5e0, 0x5e0);

struct Unk_1470a40 {
    Unk_1470a40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470a40, field_0, 0x0);

// 0x7101470a40
void Unk_1470a40_set(const Unk_1470a40* self) {
    self->field_0->field_5e0 = 3;
}

// 0x7101470a50
void Unk_1470a50_update() {}

struct Unk_1470a60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470a60_arg1, field_0, 0x0);

struct Unk_1470a60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470a60, field_0, 0x0);

// 0x7101470a60
void Unk_1470a60_set(const Unk_1470a60* self, Unk_1470a60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1470a70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470a70_arg1, field_0, 0x0);

struct Unk_1470a70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470a70, field_0, 0x0);

// 0x7101470a70
void Unk_1470a70_set(const Unk_1470a70* self, Unk_1470a70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1470a80_0 {
    u8 _0[0x5e0];
    u32 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_1470a80_0, field_5e0, 0x5e0);

struct Unk_1470a80 {
    Unk_1470a80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470a80, field_0, 0x0);

// 0x7101470a80
void Unk_1470a80_set(const Unk_1470a80* self) {
    self->field_0->field_5e0 = 4;
}

// 0x7101470a90
void Unk_1470a90_update() {}

struct Unk_1470aa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470aa0_arg1, field_0, 0x0);

struct Unk_1470aa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470aa0, field_0, 0x0);

// 0x7101470aa0
void Unk_1470aa0_set(const Unk_1470aa0* self, Unk_1470aa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1470ab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470ab0_arg1, field_0, 0x0);

struct Unk_1470ab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470ab0, field_0, 0x0);

// 0x7101470ab0
void Unk_1470ab0_set(const Unk_1470ab0* self, Unk_1470ab0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1470ac0_0 {
    u8 _0[0x5e0];
    u32 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_1470ac0_0, field_5e0, 0x5e0);

struct Unk_1470ac0 {
    Unk_1470ac0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470ac0, field_0, 0x0);

// 0x7101470ac0
void Unk_1470ac0_set(const Unk_1470ac0* self) {
    self->field_0->field_5e0 = 1;
}

// 0x7101470ad0
void Unk_1470ad0_update() {}

struct Unk_1470ae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470ae0_arg1, field_0, 0x0);

struct Unk_1470ae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470ae0, field_0, 0x0);

// 0x7101470ae0
void Unk_1470ae0_set(const Unk_1470ae0* self, Unk_1470ae0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1470af0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470af0_arg1, field_0, 0x0);

struct Unk_1470af0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470af0, field_0, 0x0);

// 0x7101470af0
void Unk_1470af0_set(const Unk_1470af0* self, Unk_1470af0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101470b20
void Unk_1470b20_update() {}

struct Unk_1470b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470b30_arg1, field_0, 0x0);

struct Unk_1470b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470b30, field_0, 0x0);

// 0x7101470b30
void Unk_1470b30_set(const Unk_1470b30* self, Unk_1470b30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1470b40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470b40_arg1, field_0, 0x0);

struct Unk_1470b40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1470b40, field_0, 0x0);

// 0x7101470b40
void Unk_1470b40_set(const Unk_1470b40* self, Unk_1470b40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1472180_0 {
    u8 _0[0x61c];
    u32 field_61c;
};
PKMN_OFFSET_ASSERT(Unk_1472180_0, field_61c, 0x61c);

struct Unk_1472180 {
    Unk_1472180_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472180, field_0, 0x0);

// 0x7101472180
void Unk_1472180_set(const Unk_1472180* self) {
    self->field_0->field_61c = 1;
}

// 0x7101472190
void Unk_1472190_update() {}

struct Unk_14721a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14721a0_arg1, field_0, 0x0);

struct Unk_14721a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14721a0, field_0, 0x0);

// 0x71014721a0
void Unk_14721a0_set(const Unk_14721a0* self, Unk_14721a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14721b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14721b0_arg1, field_0, 0x0);

struct Unk_14721b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14721b0, field_0, 0x0);

// 0x71014721b0
void Unk_14721b0_set(const Unk_14721b0* self, Unk_14721b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71014721e0
void Unk_14721e0_update() {}

struct Unk_14721f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14721f0_arg1, field_0, 0x0);

struct Unk_14721f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14721f0, field_0, 0x0);

// 0x71014721f0
void Unk_14721f0_set(const Unk_14721f0* self, Unk_14721f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1472200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472200_arg1, field_0, 0x0);

struct Unk_1472200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472200, field_0, 0x0);

// 0x7101472200
void Unk_1472200_set(const Unk_1472200* self, Unk_1472200_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1472210_0 {
    u8 _0[0x61c];
    u32 field_61c;
};
PKMN_OFFSET_ASSERT(Unk_1472210_0, field_61c, 0x61c);

struct Unk_1472210 {
    Unk_1472210_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472210, field_0, 0x0);

// 0x7101472210
void Unk_1472210_set(const Unk_1472210* self) {
    self->field_0->field_61c = 3;
}

// 0x7101472220
void Unk_1472220_update() {}

struct Unk_1472230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472230_arg1, field_0, 0x0);

struct Unk_1472230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472230, field_0, 0x0);

// 0x7101472230
void Unk_1472230_set(const Unk_1472230* self, Unk_1472230_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1472240_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472240_arg1, field_0, 0x0);

struct Unk_1472240 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472240, field_0, 0x0);

// 0x7101472240
void Unk_1472240_set(const Unk_1472240* self, Unk_1472240_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101472280
void Unk_1472280_update() {}

struct Unk_1472290_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472290_arg1, field_0, 0x0);

struct Unk_1472290 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1472290, field_0, 0x0);

// 0x7101472290
void Unk_1472290_set(const Unk_1472290* self, Unk_1472290_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14722a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14722a0_arg1, field_0, 0x0);

struct Unk_14722a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14722a0, field_0, 0x0);

// 0x71014722a0
void Unk_14722a0_set(const Unk_14722a0* self, Unk_14722a0_arg1* value) {
    value->field_0 = self->field_0;
}
