// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1249eb0_5e8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1249eb0_5e8, field_58, 0x58);

struct Unk_1249eb0 {
    u8 _0[0x5e8];
    Unk_1249eb0_5e8* field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_1249eb0, field_5e8, 0x5e8);

// 0x7101249eb0
void Unk_1249eb0_set(const Unk_1249eb0* self) {
    self->field_5e8->field_58 = self->field_5e8->field_58 & 0xfe;
}

struct Unk_1249ed0_9b8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1249ed0_9b8, field_58, 0x58);

struct Unk_1249ed0 {
    u8 _0[0x9b8];
    Unk_1249ed0_9b8* field_9b8;
};
PKMN_OFFSET_ASSERT(Unk_1249ed0, field_9b8, 0x9b8);

// 0x7101249ed0
void Unk_1249ed0_set(const Unk_1249ed0* self) {
    self->field_9b8->field_58 = self->field_9b8->field_58 & 0xfe;
}

// 0x710124b0e0
void Unk_124b0e0_update() {}

struct Unk_124b0f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_124b0f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_124b0f0, field_8, 0x8);

// 0x710124b0f0
void Unk_124b0f0_set(const Unk_124b0f0* self, Unk_124b0f0* value) {
    *value = *self;
}

struct Unk_124b100 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_124b100, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_124b100, field_8, 0x8);

// 0x710124b100
void Unk_124b100_set(const Unk_124b100* self, Unk_124b100* value) {
    *value = *self;
}

// 0x710124b210
void Unk_124b210_update() {}

struct Unk_124b220 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_124b220, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_124b220, field_8, 0x8);

// 0x710124b220
void Unk_124b220_set(const Unk_124b220* self, Unk_124b220* value) {
    *value = *self;
}

struct Unk_124b230 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_124b230, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_124b230, field_8, 0x8);

// 0x710124b230
void Unk_124b230_set(const Unk_124b230* self, Unk_124b230* value) {
    *value = *self;
}

struct Unk_124b730 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_124b730, field_78, 0x78);

// 0x710124b730
void Unk_124b730_set(Unk_124b730* self) {
    self->field_78 = 5;
}

// 0x710124c4f0
void Unk_124c4f0_update() {}

struct Unk_124c500 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_124c500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_124c500, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_124c500, field_10, 0x10);

// 0x710124c500
void Unk_124c500_set(const Unk_124c500* self, Unk_124c500* value) {
    *value = *self;
}

struct Unk_124c520 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_124c520, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_124c520, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_124c520, field_10, 0x10);

// 0x710124c520
void Unk_124c520_set(const Unk_124c520* self, Unk_124c520* value) {
    *value = *self;
}

// 0x7101251220
void Unk_1251220_update() {}

struct Unk_1251230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251230_arg1, field_0, 0x0);

struct Unk_1251230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251230, field_0, 0x0);

// 0x7101251230
void Unk_1251230_set(const Unk_1251230* self, Unk_1251230_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251240_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251240_arg1, field_0, 0x0);

struct Unk_1251240 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251240, field_0, 0x0);

// 0x7101251240
void Unk_1251240_set(const Unk_1251240* self, Unk_1251240_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012512f0
void Unk_12512f0_update() {}

struct Unk_1251300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251300_arg1, field_0, 0x0);

struct Unk_1251300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251300, field_0, 0x0);

// 0x7101251300
void Unk_1251300_set(const Unk_1251300* self, Unk_1251300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251310_arg1, field_0, 0x0);

struct Unk_1251310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251310, field_0, 0x0);

// 0x7101251310
void Unk_1251310_set(const Unk_1251310* self, Unk_1251310_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101251440
void Unk_1251440_update() {}

struct Unk_1251450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251450_arg1, field_0, 0x0);

struct Unk_1251450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251450, field_0, 0x0);

// 0x7101251450
void Unk_1251450_set(const Unk_1251450* self, Unk_1251450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251460_arg1, field_0, 0x0);

struct Unk_1251460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251460, field_0, 0x0);

// 0x7101251460
void Unk_1251460_set(const Unk_1251460* self, Unk_1251460_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012515a0
void Unk_12515a0_update() {}

struct Unk_12515b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12515b0_arg1, field_0, 0x0);

struct Unk_12515b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12515b0, field_0, 0x0);

// 0x71012515b0
void Unk_12515b0_set(const Unk_12515b0* self, Unk_12515b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12515c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12515c0_arg1, field_0, 0x0);

struct Unk_12515c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12515c0, field_0, 0x0);

// 0x71012515c0
void Unk_12515c0_set(const Unk_12515c0* self, Unk_12515c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012515f0
void Unk_12515f0_update() {}

struct Unk_1251600 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1251600, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1251600, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1251600, field_10, 0x10);

// 0x7101251600
void Unk_1251600_set(const Unk_1251600* self, Unk_1251600* value) {
    *value = *self;
}

struct Unk_1251620 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1251620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1251620, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1251620, field_10, 0x10);

// 0x7101251620
void Unk_1251620_set(const Unk_1251620* self, Unk_1251620* value) {
    *value = *self;
}

// 0x7101251720
void Unk_1251720_update() {}

struct Unk_1251730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251730_arg1, field_0, 0x0);

struct Unk_1251730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251730, field_0, 0x0);

// 0x7101251730
void Unk_1251730_set(const Unk_1251730* self, Unk_1251730_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251740_arg1, field_0, 0x0);

struct Unk_1251740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251740, field_0, 0x0);

// 0x7101251740
void Unk_1251740_set(const Unk_1251740* self, Unk_1251740_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101251850
void Unk_1251850_update() {}

struct Unk_1251860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251860_arg1, field_0, 0x0);

struct Unk_1251860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251860, field_0, 0x0);

// 0x7101251860
void Unk_1251860_set(const Unk_1251860* self, Unk_1251860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251870_arg1, field_0, 0x0);

struct Unk_1251870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251870, field_0, 0x0);

// 0x7101251870
void Unk_1251870_set(const Unk_1251870* self, Unk_1251870_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101251980
void Unk_1251980_update() {}

struct Unk_1251990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251990_arg1, field_0, 0x0);

struct Unk_1251990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251990, field_0, 0x0);

// 0x7101251990
void Unk_1251990_set(const Unk_1251990* self, Unk_1251990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12519a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12519a0_arg1, field_0, 0x0);

struct Unk_12519a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12519a0, field_0, 0x0);

// 0x71012519a0
void Unk_12519a0_set(const Unk_12519a0* self, Unk_12519a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012519b0
u32 Unk_12519b0_get() {
    return 1;
}

// 0x71012519c0
void Unk_12519c0_update() {}

// 0x71012519d0
void Unk_12519d0_update() {}

// 0x71012519e0
void Unk_12519e0_update() {}

// 0x7101251a90
void Unk_1251a90_update() {}

struct Unk_1251aa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251aa0_arg1, field_0, 0x0);

struct Unk_1251aa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251aa0, field_0, 0x0);

// 0x7101251aa0
void Unk_1251aa0_set(const Unk_1251aa0* self, Unk_1251aa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251ab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251ab0_arg1, field_0, 0x0);

struct Unk_1251ab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251ab0, field_0, 0x0);

// 0x7101251ab0
void Unk_1251ab0_set(const Unk_1251ab0* self, Unk_1251ab0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101251c80
void Unk_1251c80_update() {}

struct Unk_1251c90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251c90_arg1, field_0, 0x0);

struct Unk_1251c90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251c90, field_0, 0x0);

// 0x7101251c90
void Unk_1251c90_set(const Unk_1251c90* self, Unk_1251c90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251ca0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251ca0_arg1, field_0, 0x0);

struct Unk_1251ca0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251ca0, field_0, 0x0);

// 0x7101251ca0
void Unk_1251ca0_set(const Unk_1251ca0* self, Unk_1251ca0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101251d40
void Unk_1251d40_update() {}

struct Unk_1251d50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251d50_arg1, field_0, 0x0);

struct Unk_1251d50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251d50, field_0, 0x0);

// 0x7101251d50
void Unk_1251d50_set(const Unk_1251d50* self, Unk_1251d50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1251d60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251d60_arg1, field_0, 0x0);

struct Unk_1251d60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1251d60, field_0, 0x0);

// 0x7101251d60
void Unk_1251d60_set(const Unk_1251d60* self, Unk_1251d60_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101251f20
void Unk_1251f20_update() {}

// 0x7101252020
void Unk_1252020_update() {}

struct Unk_1252030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252030_arg1, field_0, 0x0);

struct Unk_1252030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252030, field_0, 0x0);

// 0x7101252030
void Unk_1252030_set(const Unk_1252030* self, Unk_1252030_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252040_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252040_arg1, field_0, 0x0);

struct Unk_1252040 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252040, field_0, 0x0);

// 0x7101252040
void Unk_1252040_set(const Unk_1252040* self, Unk_1252040_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101252080
void Unk_1252080_update() {}

struct Unk_1252090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252090_arg1, field_0, 0x0);

struct Unk_1252090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252090, field_0, 0x0);

// 0x7101252090
void Unk_1252090_set(const Unk_1252090* self, Unk_1252090_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12520a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12520a0_arg1, field_0, 0x0);

struct Unk_12520a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12520a0, field_0, 0x0);

// 0x71012520a0
void Unk_12520a0_set(const Unk_12520a0* self, Unk_12520a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12520b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12520b0_arg1, field_0, 0x0);

struct Unk_12520b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12520b0, field_0, 0x0);

// 0x71012520b0
void Unk_12520b0_set(const Unk_12520b0* self, Unk_12520b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12520c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12520c0_arg1, field_0, 0x0);

struct Unk_12520c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12520c0, field_0, 0x0);

// 0x71012520c0
void Unk_12520c0_set(const Unk_12520c0* self, Unk_12520c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101252290
void Unk_1252290_update() {}

// 0x71012522d0
void Unk_12522d0_update() {}

struct Unk_12522e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12522e0_arg1, field_0, 0x0);

struct Unk_12522e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12522e0, field_0, 0x0);

// 0x71012522e0
void Unk_12522e0_set(const Unk_12522e0* self, Unk_12522e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12522f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12522f0_arg1, field_0, 0x0);

struct Unk_12522f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12522f0, field_0, 0x0);

// 0x71012522f0
void Unk_12522f0_set(const Unk_12522f0* self, Unk_12522f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252300_arg1, field_0, 0x0);

struct Unk_1252300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252300, field_0, 0x0);

// 0x7101252300
void Unk_1252300_set(const Unk_1252300* self, Unk_1252300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252310_arg1, field_0, 0x0);

struct Unk_1252310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252310, field_0, 0x0);

// 0x7101252310
void Unk_1252310_set(const Unk_1252310* self, Unk_1252310_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012524e0
void Unk_12524e0_update() {}

// 0x71012526c0
void Unk_12526c0_update() {}

struct Unk_12526d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12526d0_arg1, field_0, 0x0);

struct Unk_12526d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12526d0, field_0, 0x0);

// 0x71012526d0
void Unk_12526d0_set(const Unk_12526d0* self, Unk_12526d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12526e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12526e0_arg1, field_0, 0x0);

struct Unk_12526e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12526e0, field_0, 0x0);

// 0x71012526e0
void Unk_12526e0_set(const Unk_12526e0* self, Unk_12526e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12526f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12526f0_arg1, field_0, 0x0);

struct Unk_12526f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12526f0, field_0, 0x0);

// 0x71012526f0
void Unk_12526f0_set(const Unk_12526f0* self, Unk_12526f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252700_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252700_arg1, field_0, 0x0);

struct Unk_1252700 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252700, field_0, 0x0);

// 0x7101252700
void Unk_1252700_set(const Unk_1252700* self, Unk_1252700_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012528d0
void Unk_12528d0_update() {}

// 0x7101252910
void Unk_1252910_update() {}

struct Unk_1252920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252920_arg1, field_0, 0x0);

struct Unk_1252920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252920, field_0, 0x0);

// 0x7101252920
void Unk_1252920_set(const Unk_1252920* self, Unk_1252920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252930_arg1, field_0, 0x0);

struct Unk_1252930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252930, field_0, 0x0);

// 0x7101252930
void Unk_1252930_set(const Unk_1252930* self, Unk_1252930_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252940_arg1, field_0, 0x0);

struct Unk_1252940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252940, field_0, 0x0);

// 0x7101252940
void Unk_1252940_set(const Unk_1252940* self, Unk_1252940_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252950_arg1, field_0, 0x0);

struct Unk_1252950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252950, field_0, 0x0);

// 0x7101252950
void Unk_1252950_set(const Unk_1252950* self, Unk_1252950_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101252960
void Unk_1252960_update() {}

// 0x7101252970
void Unk_1252970_update() {}

// 0x7101252980
void Unk_1252980_update() {}

// 0x7101252990
void Unk_1252990_update() {}

// 0x71012529a0
void Unk_12529a0_update() {}

// 0x71012529b0
void Unk_12529b0_update() {}

// 0x71012529c0
void Unk_12529c0_update() {}

// 0x71012529d0
void Unk_12529d0_update() {}

// 0x7101252c80
void Unk_1252c80_update() {}

// 0x7101252df0
void Unk_1252df0_update() {}

struct Unk_1252e00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e00_arg1, field_0, 0x0);

struct Unk_1252e00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e00, field_0, 0x0);

// 0x7101252e00
void Unk_1252e00_set(const Unk_1252e00* self, Unk_1252e00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252e10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e10_arg1, field_0, 0x0);

struct Unk_1252e10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e10, field_0, 0x0);

// 0x7101252e10
void Unk_1252e10_set(const Unk_1252e10* self, Unk_1252e10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252e20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e20_arg1, field_0, 0x0);

struct Unk_1252e20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e20, field_0, 0x0);

// 0x7101252e20
void Unk_1252e20_set(const Unk_1252e20* self, Unk_1252e20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252e30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e30_arg1, field_0, 0x0);

struct Unk_1252e30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e30, field_0, 0x0);

// 0x7101252e30
void Unk_1252e30_set(const Unk_1252e30* self, Unk_1252e30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101252e70
void Unk_1252e70_update() {}

struct Unk_1252e80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e80_arg1, field_0, 0x0);

struct Unk_1252e80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e80, field_0, 0x0);

// 0x7101252e80
void Unk_1252e80_set(const Unk_1252e80* self, Unk_1252e80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252e90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e90_arg1, field_0, 0x0);

struct Unk_1252e90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252e90, field_0, 0x0);

// 0x7101252e90
void Unk_1252e90_set(const Unk_1252e90* self, Unk_1252e90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252ea0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ea0, field_0, 0x0);

void Unk_124d550(u64);

// 0x7101252ea0
void Unk_1252ea0_call(const Unk_1252ea0* self) {
    Unk_124d550(self->field_0);
}

// 0x7101252eb0
void Unk_1252eb0_update() {}

struct Unk_1252ec0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ec0_arg1, field_0, 0x0);

struct Unk_1252ec0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ec0, field_0, 0x0);

// 0x7101252ec0
void Unk_1252ec0_set(const Unk_1252ec0* self, Unk_1252ec0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252ed0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ed0_arg1, field_0, 0x0);

struct Unk_1252ed0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ed0, field_0, 0x0);

// 0x7101252ed0
void Unk_1252ed0_set(const Unk_1252ed0* self, Unk_1252ed0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101252f40
void Unk_1252f40_update() {}

struct Unk_1252f50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252f50_arg1, field_0, 0x0);

struct Unk_1252f50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252f50, field_0, 0x0);

// 0x7101252f50
void Unk_1252f50_set(const Unk_1252f50* self, Unk_1252f50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252f60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252f60_arg1, field_0, 0x0);

struct Unk_1252f60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252f60, field_0, 0x0);

// 0x7101252f60
void Unk_1252f60_set(const Unk_1252f60* self, Unk_1252f60_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101252fd0
void Unk_1252fd0_update() {}

struct Unk_1252fe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252fe0_arg1, field_0, 0x0);

struct Unk_1252fe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252fe0, field_0, 0x0);

// 0x7101252fe0
void Unk_1252fe0_set(const Unk_1252fe0* self, Unk_1252fe0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1252ff0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ff0_arg1, field_0, 0x0);

struct Unk_1252ff0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1252ff0, field_0, 0x0);

// 0x7101252ff0
void Unk_1252ff0_set(const Unk_1252ff0* self, Unk_1252ff0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253000 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253000, field_0, 0x0);

void Unk_124e390(u64);

// 0x7101253000
void Unk_1253000_call(const Unk_1253000* self) {
    Unk_124e390(self->field_0);
}

// 0x7101253010
void Unk_1253010_update() {}

struct Unk_1253020_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253020_arg1, field_0, 0x0);

struct Unk_1253020 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253020, field_0, 0x0);

// 0x7101253020
void Unk_1253020_set(const Unk_1253020* self, Unk_1253020_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253030_arg1, field_0, 0x0);

struct Unk_1253030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253030, field_0, 0x0);

// 0x7101253030
void Unk_1253030_set(const Unk_1253030* self, Unk_1253030_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012530b0
void Unk_12530b0_update() {}

struct Unk_12530c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12530c0_arg1, field_0, 0x0);

struct Unk_12530c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12530c0, field_0, 0x0);

// 0x71012530c0
void Unk_12530c0_set(const Unk_12530c0* self, Unk_12530c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12530d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12530d0_arg1, field_0, 0x0);

struct Unk_12530d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12530d0, field_0, 0x0);

// 0x71012530d0
void Unk_12530d0_set(const Unk_12530d0* self, Unk_12530d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101253160
void Unk_1253160_update() {}

struct Unk_1253170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253170_arg1, field_0, 0x0);

struct Unk_1253170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253170, field_0, 0x0);

// 0x7101253170
void Unk_1253170_set(const Unk_1253170* self, Unk_1253170_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253180_arg1, field_0, 0x0);

struct Unk_1253180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253180, field_0, 0x0);

// 0x7101253180
void Unk_1253180_set(const Unk_1253180* self, Unk_1253180_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101253200
void Unk_1253200_update() {}

struct Unk_1253210_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253210_arg1, field_0, 0x0);

struct Unk_1253210 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253210, field_0, 0x0);

// 0x7101253210
void Unk_1253210_set(const Unk_1253210* self, Unk_1253210_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253220_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253220_arg1, field_0, 0x0);

struct Unk_1253220 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253220, field_0, 0x0);

// 0x7101253220
void Unk_1253220_set(const Unk_1253220* self, Unk_1253220_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253230, field_0, 0x0);

void Unk_124f5d0(u64);

// 0x7101253230
void Unk_1253230_call(const Unk_1253230* self) {
    Unk_124f5d0(self->field_0);
}

// 0x7101253240
void Unk_1253240_update() {}

struct Unk_1253250_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253250_arg1, field_0, 0x0);

struct Unk_1253250 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253250, field_0, 0x0);

// 0x7101253250
void Unk_1253250_set(const Unk_1253250* self, Unk_1253250_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253260_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253260_arg1, field_0, 0x0);

struct Unk_1253260 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253260, field_0, 0x0);

// 0x7101253260
void Unk_1253260_set(const Unk_1253260* self, Unk_1253260_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253270 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253270, field_0, 0x0);

void Unk_124ff40(u64);

// 0x7101253270
void Unk_1253270_call(const Unk_1253270* self) {
    Unk_124ff40(self->field_0);
}

// 0x7101253280
void Unk_1253280_update() {}

struct Unk_1253290_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253290_arg1, field_0, 0x0);

struct Unk_1253290 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253290, field_0, 0x0);

// 0x7101253290
void Unk_1253290_set(const Unk_1253290* self, Unk_1253290_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12532a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532a0_arg1, field_0, 0x0);

struct Unk_12532a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532a0, field_0, 0x0);

// 0x71012532a0
void Unk_12532a0_set(const Unk_12532a0* self, Unk_12532a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12532b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532b0, field_0, 0x0);

void Unk_1250140(u64);

// 0x71012532b0
void Unk_12532b0_call(const Unk_12532b0* self) {
    Unk_1250140(self->field_0);
}

// 0x71012532c0
void Unk_12532c0_update() {}

struct Unk_12532d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532d0_arg1, field_0, 0x0);

struct Unk_12532d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532d0, field_0, 0x0);

// 0x71012532d0
void Unk_12532d0_set(const Unk_12532d0* self, Unk_12532d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12532e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532e0_arg1, field_0, 0x0);

struct Unk_12532e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12532e0, field_0, 0x0);

// 0x71012532e0
void Unk_12532e0_set(const Unk_12532e0* self, Unk_12532e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101253370
void Unk_1253370_update() {}

// 0x71012533b0
void Unk_12533b0_update() {}

struct Unk_12533c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533c0_arg1, field_0, 0x0);

struct Unk_12533c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533c0, field_0, 0x0);

// 0x71012533c0
void Unk_12533c0_set(const Unk_12533c0* self, Unk_12533c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12533d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533d0_arg1, field_0, 0x0);

struct Unk_12533d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533d0, field_0, 0x0);

// 0x71012533d0
void Unk_12533d0_set(const Unk_12533d0* self, Unk_12533d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12533e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533e0_arg1, field_0, 0x0);

struct Unk_12533e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533e0, field_0, 0x0);

// 0x71012533e0
void Unk_12533e0_set(const Unk_12533e0* self, Unk_12533e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12533f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533f0_arg1, field_0, 0x0);

struct Unk_12533f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12533f0, field_0, 0x0);

// 0x71012533f0
void Unk_12533f0_set(const Unk_12533f0* self, Unk_12533f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101253430
void Unk_1253430_update() {}

struct Unk_1253440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253440_arg1, field_0, 0x0);

struct Unk_1253440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253440, field_0, 0x0);

// 0x7101253440
void Unk_1253440_set(const Unk_1253440* self, Unk_1253440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253450_arg1, field_0, 0x0);

struct Unk_1253450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253450, field_0, 0x0);

// 0x7101253450
void Unk_1253450_set(const Unk_1253450* self, Unk_1253450_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012534f0
void Unk_12534f0_update() {}

struct Unk_1253500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253500, field_0, 0x0);

void Unk_1250ba0(u64);

// 0x7101253500
void Unk_1253500_call(const Unk_1253500* self) {
    Unk_1250ba0(self->field_0);
}

// 0x7101253510
void Unk_1253510_update() {}

struct Unk_1253520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253520_arg1, field_0, 0x0);

struct Unk_1253520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253520, field_0, 0x0);

// 0x7101253520
void Unk_1253520_set(const Unk_1253520* self, Unk_1253520_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253530_arg1, field_0, 0x0);

struct Unk_1253530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253530, field_0, 0x0);

// 0x7101253530
void Unk_1253530_set(const Unk_1253530* self, Unk_1253530_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253540 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1253540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1253540, field_8, 0x8);

// 0x7101253540
void Unk_1253540_set(const Unk_1253540* self, Unk_1253540* value) {
    *value = *self;
}

struct Unk_1253550 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1253550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1253550, field_8, 0x8);

// 0x7101253550
void Unk_1253550_set(const Unk_1253550* self, Unk_1253550* value) {
    *value = *self;
}

struct Unk_1253560 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253560, field_0, 0x0);

void Unk_1250ba0(u64);

// 0x7101253560
void Unk_1253560_call(const Unk_1253560* self) {
    Unk_1250ba0(self->field_0);
}

// 0x7101253570
void Unk_1253570_update() {}

struct Unk_1253580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253580_arg1, field_0, 0x0);

struct Unk_1253580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253580, field_0, 0x0);

// 0x7101253580
void Unk_1253580_set(const Unk_1253580* self, Unk_1253580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1253590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253590_arg1, field_0, 0x0);

struct Unk_1253590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1253590, field_0, 0x0);

// 0x7101253590
void Unk_1253590_set(const Unk_1253590* self, Unk_1253590_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012535a0
void Unk_12535a0_update() {}

// 0x71012535b0
void Unk_12535b0_update() {}

// 0x71012535c0
void Unk_12535c0_update() {}

// 0x71012535d0
void Unk_12535d0_update() {}
