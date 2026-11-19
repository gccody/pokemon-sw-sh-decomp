// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_9f9140_88 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_9f9140_88, field_170, 0x170);

struct Unk_9f9140 {
    u8 _0[0x88];
    Unk_9f9140_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_9f9140, field_88, 0x88);

// 0x71009f9140
bool Unk_9f9140_check(const Unk_9f9140* self) {
    if (self->field_88 == nullptr) {
        return true;
    }
    return self->field_88->field_170 != 0;
}

struct Unk_9f9320 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9320, field_10, 0x10);

void Unk_140c020(u64, u32, u32);

// 0x71009f9320
void Unk_9f9320_call(const Unk_9f9320* self) {
    Unk_140c020(self->field_10, 0xffffffff, 1);
}

struct Unk_9f9330 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9330, field_10, 0x10);

void Unk_140c020(u64, u32, u32);

// 0x71009f9330
void Unk_9f9330_call(const Unk_9f9330* self) {
    Unk_140c020(self->field_10, 0xffffffff, 0);
}

struct Unk_9f9340 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9340, field_10, 0x10);

void Unk_140bff0(u64);

// 0x71009f9340
void Unk_9f9340_call(const Unk_9f9340* self) {
    Unk_140bff0(self->field_10);
}

struct Unk_9f9350 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9350, field_10, 0x10);

// 0x71009f9350
bool Unk_9f9350_check(const Unk_9f9350* self) {
    return self->field_10 == 0;
}

struct Unk_9f9360_10 {
    u8 _0[0x180];
    u32 field_180;
};
PKMN_OFFSET_ASSERT(Unk_9f9360_10, field_180, 0x180);

struct Unk_9f9360 {
    u8 _0[0x10];
    Unk_9f9360_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9360, field_10, 0x10);

// 0x71009f9360
u32 Unk_9f9360_get(const Unk_9f9360* self) {
    if (self->field_10 == nullptr) {
        return 0;
    }
    return self->field_10->field_180;
}

struct Unk_9f9380_18 {
    u8 _0[0x180];
    u32 field_180;
};
PKMN_OFFSET_ASSERT(Unk_9f9380_18, field_180, 0x180);

struct Unk_9f9380 {
    u8 _0[0x18];
    Unk_9f9380_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_9f9380, field_18, 0x18);

// 0x71009f9380
u32 Unk_9f9380_get(const Unk_9f9380* self) {
    if (self->field_18 == nullptr) {
        return 0;
    }
    return self->field_18->field_180;
}

// 0x7100a3cdd0
void Unk_a3cdd0_update() {}

// 0x7100a3cde0
void Unk_a3cde0_update() {}

// 0x7100a3ec10
void Unk_a3ec10_update() {}

// 0x7100a40220
void Unk_a40220_update() {}

// 0x7100a40840
void Unk_a40840_update() {}

// 0x7100a40ab0
void Unk_a40ab0_update() {}

// 0x7100a41560
void Unk_a41560_update() {}

// 0x7100a41880
void Unk_a41880_update() {}

// 0x7100a42630
void Unk_a42630_update() {}

void Unk_a38ab0(void*, u64, u64, u32);

// 0x7100a42640
void Unk_a42640_call(void* self, u64 value, u64 arg2) {
    Unk_a38ab0(self, value, arg2, 0);
}

void Unk_a38e50(void*, u64, u64, u32);

// 0x7100a42650
void Unk_a42650_call(void* self, u64 value, u64 arg2) {
    Unk_a38e50(self, value, arg2, 0);
}

void Unk_a39390(void*, u64, u64, u32);

// 0x7100a42660
void Unk_a42660_call(void* self, u64 value, u64 arg2) {
    Unk_a39390(self, value, arg2, 0);
}

void Unk_a39880(void*, u64, u64, u32);

// 0x7100a42670
void Unk_a42670_call(void* self, u64 value, u64 arg2) {
    Unk_a39880(self, value, arg2, 0);
}

void Unk_a39eb0(void*, u64, u64, u32);

// 0x7100a42680
void Unk_a42680_call(void* self, u64 value, u64 arg2) {
    Unk_a39eb0(self, value, arg2, 0);
}

void Unk_a3a270(void*, u64, u64, u32);

// 0x7100a42750
void Unk_a42750_call(void* self, u64 value, u64 arg2) {
    Unk_a3a270(self, value, arg2, 0);
}

void Unk_a3a4f0(void*, u64, u64, u32);

// 0x7100a42760
void Unk_a42760_call(void* self, u64 value, u64 arg2) {
    Unk_a3a4f0(self, value, arg2, 0);
}

void Unk_a3a770(void*, u64, u64, u32);

// 0x7100a42770
void Unk_a42770_call(void* self, u64 value, u64 arg2) {
    Unk_a3a770(self, value, arg2, 0);
}

void Unk_a3aa00(void*, u64, u64, u32);

// 0x7100a42780
void Unk_a42780_call(void* self, u64 value, u64 arg2) {
    Unk_a3aa00(self, value, arg2, 0);
}

void Unk_a3ae20(void*, u64, u64, u32);

// 0x7100a42790
void Unk_a42790_call(void* self, u64 value, u64 arg2) {
    Unk_a3ae20(self, value, arg2, 0);
}

void Unk_a3b260(void*, u64, u64, u32);

// 0x7100a427a0
void Unk_a427a0_call(void* self, u64 value, u64 arg2) {
    Unk_a3b260(self, value, arg2, 0);
}

void Unk_a3b050(void*, u64, u64, u32);

// 0x7100a427b0
void Unk_a427b0_call(void* self, u64 value, u64 arg2) {
    Unk_a3b050(self, value, arg2, 0);
}

void Unk_a3b650(void*, u64, u64, u32);

// 0x7100a427c0
void Unk_a427c0_call(void* self, u64 value, u64 arg2) {
    Unk_a3b650(self, value, arg2, 0);
}

void Unk_a3b4f0(void*, u64, u64, u32);

// 0x7100a427d0
void Unk_a427d0_call(void* self, u64 value, u64 arg2) {
    Unk_a3b4f0(self, value, arg2, 0);
}

void Unk_a3bf50(void*, u64, u64, u32);

// 0x7100a427e0
void Unk_a427e0_call(void* self, u64 value, u64 arg2) {
    Unk_a3bf50(self, value, arg2, 0);
}

void Unk_a3b7d0(void*, u64, u64, u32);

// 0x7100a427f0
void Unk_a427f0_call(void* self, u64 value, u64 arg2) {
    Unk_a3b7d0(self, value, arg2, 0);
}

// 0x7100a42800
void Unk_a42800_update() {}

void Unk_a3c990(void*, u64, u64, u32);

// 0x7100a42810
void Unk_a42810_call(void* self, u64 value, u64 arg2) {
    Unk_a3c990(self, value, arg2, 0);
}

void Unk_a3c810(void*, u64, u64, u32);

// 0x7100a42820
void Unk_a42820_call(void* self, u64 value, u64 arg2) {
    Unk_a3c810(self, value, arg2, 0);
}

void Unk_a3cc70(void*, u64, u64, u32);

// 0x7100a42970
void Unk_a42970_call(void* self, u64 value, u64 arg2) {
    Unk_a3cc70(self, value, arg2, 0);
}

// 0x7100a42980
void Unk_a42980_update() {}

void Unk_a38ab0(void*, u64, u64, u32);

// 0x7100a42990
void Unk_a42990_call(void* self, u64 value, u64 arg2) {
    Unk_a38ab0(self, value, arg2, 1);
}

void Unk_a38e50(void*, u64, u64, u32);

// 0x7100a429a0
void Unk_a429a0_call(void* self, u64 value, u64 arg2) {
    Unk_a38e50(self, value, arg2, 0);
}

void Unk_a39880(void*, u64, u64, u32);

// 0x7100a429b0
void Unk_a429b0_call(void* self, u64 value, u64 arg2) {
    Unk_a39880(self, value, arg2, 1);
}

void Unk_a39390(void*, u64, u64, u32);

// 0x7100a429c0
void Unk_a429c0_call(void* self, u64 value, u64 arg2) {
    Unk_a39390(self, value, arg2, 1);
}

void Unk_a39eb0(void*, u64, u64, u32);

// 0x7100a429d0
void Unk_a429d0_call(void* self, u64 value, u64 arg2) {
    Unk_a39eb0(self, value, arg2, 1);
}

void Unk_a3a270(void*, u64, u64, u32);

// 0x7100a42aa0
void Unk_a42aa0_call(void* self, u64 value, u64 arg2) {
    Unk_a3a270(self, value, arg2, 1);
}

void Unk_a3a4f0(void*, u64, u64, u32);

// 0x7100a42ab0
void Unk_a42ab0_call(void* self, u64 value, u64 arg2) {
    Unk_a3a4f0(self, value, arg2, 1);
}

void Unk_a3a770(void*, u64, u64, u32);

// 0x7100a42ac0
void Unk_a42ac0_call(void* self, u64 value, u64 arg2) {
    Unk_a3a770(self, value, arg2, 1);
}

void Unk_a3aa00(void*, u64, u64, u32);

// 0x7100a42ad0
void Unk_a42ad0_call(void* self, u64 value, u64 arg2) {
    Unk_a3aa00(self, value, arg2, 1);
}

void Unk_a3ae20(void*, u64, u64, u32);

// 0x7100a42ae0
void Unk_a42ae0_call(void* self, u64 value, u64 arg2) {
    Unk_a3ae20(self, value, arg2, 1);
}

void Unk_a3b260(void*, u64, u64, u32);

// 0x7100a42af0
void Unk_a42af0_call(void* self, u64 value, u64 arg2) {
    Unk_a3b260(self, value, arg2, 1);
}

void Unk_a3b050(void*, u64, u64, u32);

// 0x7100a42b00
void Unk_a42b00_call(void* self, u64 value, u64 arg2) {
    Unk_a3b050(self, value, arg2, 1);
}

void Unk_a3b650(void*, u64, u64, u32);

// 0x7100a42b10
void Unk_a42b10_call(void* self, u64 value, u64 arg2) {
    Unk_a3b650(self, value, arg2, 1);
}

void Unk_a3b4f0(void*, u64, u64, u32);

// 0x7100a42b20
void Unk_a42b20_call(void* self, u64 value, u64 arg2) {
    Unk_a3b4f0(self, value, arg2, 1);
}

void Unk_a3bf50(void*, u64, u64, u32);

// 0x7100a42b30
void Unk_a42b30_call(void* self, u64 value, u64 arg2) {
    Unk_a3bf50(self, value, arg2, 1);
}

void Unk_a3b7d0(void*, u64, u64, u32);

// 0x7100a42b40
void Unk_a42b40_call(void* self, u64 value, u64 arg2) {
    Unk_a3b7d0(self, value, arg2, 1);
}

// 0x7100a42b50
void Unk_a42b50_update() {}

void Unk_a3c810(void*, u64, u64, u32);

// 0x7100a42b60
void Unk_a42b60_call(void* self, u64 value, u64 arg2) {
    Unk_a3c810(self, value, arg2, 1);
}

void Unk_a3c990(void*, u64, u64, u32);

// 0x7100a42b70
void Unk_a42b70_call(void* self, u64 value, u64 arg2) {
    Unk_a3c990(self, value, arg2, 1);
}

void Unk_a3cc70(void*, u64, u64, u32);

// 0x7100a42cc0
void Unk_a42cc0_call(void* self, u64 value, u64 arg2) {
    Unk_a3cc70(self, value, arg2, 1);
}

// 0x7100a42cd0
void Unk_a42cd0_update() {}

// 0x7100a47fc0
void Unk_a47fc0_update() {}

// 0x7100a488f0
void Unk_a488f0_update() {}

// 0x7100a49140
void Unk_a49140_update() {}

// 0x7100a497e0
void Unk_a497e0_update() {}

// 0x7100a4c310
void Unk_a4c310_update() {}

// 0x7100a4c9a0
void Unk_a4c9a0_update() {}

// 0x7100a4ddb0
void Unk_a4ddb0_update() {}

// 0x7100a4ddc0
void Unk_a4ddc0_update() {}

// 0x7100a4e380
void Unk_a4e380_update() {}

// 0x7100a4ea20
void Unk_a4ea20_update() {}

// 0x7100a4ebf0
void Unk_a4ebf0_update() {}

// 0x7100a4f260
void Unk_a4f260_update() {}

// 0x7100a51e30
void Unk_a51e30_update() {}

// 0x7100a51e40
void Unk_a51e40_update() {}

// 0x7100a51e50
void Unk_a51e50_update() {}

// 0x7100a51e60
void Unk_a51e60_update() {}

// 0x7100a51e70
void Unk_a51e70_update() {}

// 0x7100a51e80
void Unk_a51e80_update() {}

// 0x7100a51e90
void Unk_a51e90_update() {}

// 0x7100a51ea0
void Unk_a51ea0_update() {}

// 0x7100a51eb0
void Unk_a51eb0_update() {}

// 0x7100a51ec0
void Unk_a51ec0_update() {}

// 0x7100a51ed0
void Unk_a51ed0_update() {}

// 0x7100a51ee0
void Unk_a51ee0_update() {}

// 0x7100a51ef0
void Unk_a51ef0_update() {}

// 0x7100a529a0
void Unk_a529a0_update() {}

// 0x7100a53990
void Unk_a53990_update() {}

// 0x7100a53b30
void Unk_a53b30_update() {}

// 0x7100a53b40
void Unk_a53b40_update() {}

// 0x7100a5bb00
void Unk_a5bb00_update() {}

// 0x7100a5bb10
void Unk_a5bb10_update() {}

// 0x7100a5bb20
void Unk_a5bb20_update() {}

// 0x7100a5bb30
void Unk_a5bb30_update() {}

// 0x7100a5bb40
void Unk_a5bb40_update() {}

// 0x7100a5bb50
void Unk_a5bb50_update() {}

// 0x7100a5bb60
void Unk_a5bb60_update() {}

// 0x7100a5bb70
void Unk_a5bb70_update() {}

// 0x7100a5bb80
void Unk_a5bb80_update() {}

// 0x7100a5bb90
void Unk_a5bb90_update() {}

// 0x7100a5bba0
void Unk_a5bba0_update() {}

// 0x7100a5bbb0
void Unk_a5bbb0_update() {}

// 0x7100a5bbc0
void Unk_a5bbc0_update() {}

// 0x7100a5bbd0
void Unk_a5bbd0_update() {}

// 0x7100a5bbe0
void Unk_a5bbe0_update() {}

// 0x7100a5bbf0
void Unk_a5bbf0_update() {}

// 0x7100a5bc00
void Unk_a5bc00_update() {}

// 0x7100a5bc10
void Unk_a5bc10_update() {}

// 0x7100a5bc20
void Unk_a5bc20_update() {}

// 0x7100a5bc30
void Unk_a5bc30_update() {}

// 0x7100a5bc90
void Unk_a5bc90_update() {}

// 0x7100a5bca0
void Unk_a5bca0_update() {}

// 0x7100a5d4e0
void Unk_a5d4e0_update() {}

// 0x7100a5d4f0
void Unk_a5d4f0_update() {}

// 0x7100a5d500
void Unk_a5d500_update() {}

// 0x7100a5d510
void Unk_a5d510_update() {}

// 0x7100a5d520
void Unk_a5d520_update() {}

// 0x7100a5da20
void Unk_a5da20_update() {}

void Unk_954bd0(u64);

// 0x7100a5da30
void Unk_a5da30_call(void* /*unused*/, u64 value) {
    Unk_954bd0(value);
}

struct Unk_a5edc0_arg1 {
    u8 _0[0x5c8];
    u64 field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_a5edc0_arg1, field_5c8, 0x5c8);

void Unk_98a670(u64);

// 0x7100a5edc0
void Unk_a5edc0_call(void* /*unused*/, const Unk_a5edc0_arg1* value) {
    Unk_98a670(value->field_5c8);
}

// 0x7100a5ef70
void Unk_a5ef70_update() {}

// 0x7100a5f350
void Unk_a5f350_update() {}

// 0x7100a5fb30
void Unk_a5fb30_update() {}

// 0x7100a5fb40
void Unk_a5fb40_update() {}

// 0x7100a5fb50
void Unk_a5fb50_update() {}

// 0x7100a5fb60
void Unk_a5fb60_update() {}

// 0x7100a5fb70
void Unk_a5fb70_update() {}

// 0x7100a5fb80
void Unk_a5fb80_update() {}

// 0x7100a5fb90
void Unk_a5fb90_update() {}

// 0x7100a61150
void Unk_a61150_update() {}

// 0x7100a61160
void Unk_a61160_update() {}

// 0x7100a61170
void Unk_a61170_update() {}

// 0x7100a61180
void Unk_a61180_update() {}

// 0x7100a61190
void Unk_a61190_update() {}

// 0x7100a61470
void Unk_a61470_update() {}

// 0x7100a63590
void Unk_a63590_update() {}

// 0x7100a635a0
void Unk_a635a0_update() {}

// 0x7100a63760
void Unk_a63760_update() {}

// 0x7100a63770
void Unk_a63770_update() {}

// 0x7100a63780
void Unk_a63780_update() {}

// 0x7100a63790
void Unk_a63790_update() {}

// 0x7100a637a0
void Unk_a637a0_update() {}

// 0x7100a637b0
void Unk_a637b0_update() {}

// 0x7100a637c0
void Unk_a637c0_update() {}

// 0x7100a637d0
void Unk_a637d0_update() {}

// 0x7100a637e0
void Unk_a637e0_update() {}

// 0x7100a637f0
void Unk_a637f0_update() {}

// 0x7100a63800
void Unk_a63800_update() {}

// 0x7100a63810
void Unk_a63810_update() {}

// 0x7100a63820
void Unk_a63820_update() {}

// 0x7100a63830
void Unk_a63830_update() {}

// 0x7100a63840
void Unk_a63840_update() {}

// 0x7100a63850
void Unk_a63850_update() {}

// 0x7100a63860
void Unk_a63860_update() {}

// 0x7100a63870
void Unk_a63870_update() {}

// 0x7100a63880
void Unk_a63880_update() {}

// 0x7100a63890
void Unk_a63890_update() {}

// 0x7100a638a0
void Unk_a638a0_update() {}

// 0x7100a638b0
void Unk_a638b0_update() {}

// 0x7100a638c0
void Unk_a638c0_update() {}

// 0x7100a638d0
void Unk_a638d0_update() {}

// 0x7100a638e0
void Unk_a638e0_update() {}

// 0x7100a638f0
void Unk_a638f0_update() {}

// 0x7100a63900
void Unk_a63900_update() {}

// 0x7100a63910
void Unk_a63910_update() {}

// 0x7100a63920
void Unk_a63920_update() {}

// 0x7100a63930
void Unk_a63930_update() {}

// 0x7100a63940
void Unk_a63940_update() {}

// 0x7100a63950
void Unk_a63950_update() {}

// 0x7100a63960
void Unk_a63960_update() {}

// 0x7100a63970
void Unk_a63970_update() {}

// 0x7100a63980
void Unk_a63980_update() {}

// 0x7100a63990
void Unk_a63990_update() {}

// 0x7100a639a0
void Unk_a639a0_update() {}

// 0x7100a639b0
void Unk_a639b0_update() {}

// 0x7100a639c0
void Unk_a639c0_update() {}

// 0x7100a639d0
void Unk_a639d0_update() {}

// 0x7100a639e0
void Unk_a639e0_update() {}

// 0x7100a639f0
void Unk_a639f0_update() {}

// 0x7100a63a00
void Unk_a63a00_update() {}

// 0x7100a63a10
void Unk_a63a10_update() {}

// 0x7100a63a20
void Unk_a63a20_update() {}

// 0x7100a63a30
void Unk_a63a30_update() {}

// 0x7100a63a40
void Unk_a63a40_update() {}

// 0x7100a63a50
void Unk_a63a50_update() {}

// 0x7100a63a60
void Unk_a63a60_update() {}

// 0x7100a63a70
void Unk_a63a70_update() {}

// 0x7100a63a80
void Unk_a63a80_update() {}

// 0x7100a63a90
void Unk_a63a90_update() {}

// 0x7100a63aa0
void Unk_a63aa0_update() {}

// 0x7100a63ab0
void Unk_a63ab0_update() {}

// 0x7100a63ac0
void Unk_a63ac0_update() {}

// 0x7100a63ad0
void Unk_a63ad0_update() {}

// 0x7100a63ae0
void Unk_a63ae0_update() {}

// 0x7100a63af0
void Unk_a63af0_update() {}

// 0x7100a63b00
void Unk_a63b00_update() {}

// 0x7100a63b10
void Unk_a63b10_update() {}

// 0x7100a63b20
void Unk_a63b20_update() {}

// 0x7100a63b30
void Unk_a63b30_update() {}

// 0x7100a63b40
void Unk_a63b40_update() {}

// 0x7100a63b50
void Unk_a63b50_update() {}

// 0x7100a63b60
void Unk_a63b60_update() {}

// 0x7100a63b70
void Unk_a63b70_update() {}

// 0x7100a63b80
void Unk_a63b80_update() {}

// 0x7100a63b90
void Unk_a63b90_update() {}

// 0x7100a63ba0
void Unk_a63ba0_update() {}

// 0x7100a63bb0
void Unk_a63bb0_update() {}

// 0x7100a63bc0
void Unk_a63bc0_update() {}

// 0x7100a63bd0
void Unk_a63bd0_update() {}

// 0x7100a63be0
void Unk_a63be0_update() {}

// 0x7100a63bf0
void Unk_a63bf0_update() {}

// 0x7100a63c00
void Unk_a63c00_update() {}

// 0x7100a63c10
void Unk_a63c10_update() {}

// 0x7100a63c20
void Unk_a63c20_update() {}

// 0x7100a63c30
void Unk_a63c30_update() {}

// 0x7100a63c40
void Unk_a63c40_update() {}

// 0x7100a63c50
void Unk_a63c50_update() {}

// 0x7100a63c60
void Unk_a63c60_update() {}

// 0x7100a63c70
void Unk_a63c70_update() {}

// 0x7100a63c80
void Unk_a63c80_update() {}

// 0x7100a63c90
void Unk_a63c90_update() {}

// 0x7100a63ca0
void Unk_a63ca0_update() {}

// 0x7100a63cb0
void Unk_a63cb0_update() {}

// 0x7100a63cc0
void Unk_a63cc0_update() {}

// 0x7100a63cd0
void Unk_a63cd0_update() {}

// 0x7100a63ce0
void Unk_a63ce0_update() {}

// 0x7100a63cf0
void Unk_a63cf0_update() {}

// 0x7100a63d00
void Unk_a63d00_update() {}

// 0x7100a63d10
void Unk_a63d10_update() {}

// 0x7100a63d20
void Unk_a63d20_update() {}

// 0x7100a63d30
void Unk_a63d30_update() {}

// 0x7100a63d40
void Unk_a63d40_update() {}

// 0x7100a63d50
void Unk_a63d50_update() {}

// 0x7100a63d60
void Unk_a63d60_update() {}

// 0x7100a63d70
void Unk_a63d70_update() {}

// 0x7100a63d80
void Unk_a63d80_update() {}

// 0x7100a63d90
void Unk_a63d90_update() {}

// 0x7100a63da0
void Unk_a63da0_update() {}

// 0x7100a63db0
void Unk_a63db0_update() {}

// 0x7100a63dc0
void Unk_a63dc0_update() {}

// 0x7100a63dd0
void Unk_a63dd0_update() {}

// 0x7100a63de0
void Unk_a63de0_update() {}

// 0x7100a63df0
void Unk_a63df0_update() {}

// 0x7100a63e00
void Unk_a63e00_update() {}

// 0x7100a63e10
void Unk_a63e10_update() {}

// 0x7100a63e20
void Unk_a63e20_update() {}

// 0x7100a63e30
void Unk_a63e30_update() {}

// 0x7100a63e40
void Unk_a63e40_update() {}

// 0x7100a63e50
void Unk_a63e50_update() {}

// 0x7100a63e60
void Unk_a63e60_update() {}

// 0x7100a63e70
void Unk_a63e70_update() {}

// 0x7100a63e80
void Unk_a63e80_update() {}

// 0x7100a63e90
void Unk_a63e90_update() {}

// 0x7100a63ea0
void Unk_a63ea0_update() {}

// 0x7100a63eb0
void Unk_a63eb0_update() {}

// 0x7100a63ec0
void Unk_a63ec0_update() {}

// 0x7100a63ed0
void Unk_a63ed0_update() {}

// 0x7100a63ee0
void Unk_a63ee0_update() {}

// 0x7100a63ef0
void Unk_a63ef0_update() {}

// 0x7100a63f00
void Unk_a63f00_update() {}

// 0x7100a63f10
void Unk_a63f10_update() {}

// 0x7100a63f20
void Unk_a63f20_update() {}

// 0x7100a63f30
void Unk_a63f30_update() {}

// 0x7100a63f40
void Unk_a63f40_update() {}

// 0x7100a63f50
void Unk_a63f50_update() {}

// 0x7100a63f60
void Unk_a63f60_update() {}

// 0x7100a63f70
void Unk_a63f70_update() {}

// 0x7100a63f80
void Unk_a63f80_update() {}

// 0x7100a63f90
void Unk_a63f90_update() {}

// 0x7100a63fa0
void Unk_a63fa0_update() {}

// 0x7100a63fb0
void Unk_a63fb0_update() {}

// 0x7100a63fc0
void Unk_a63fc0_update() {}

// 0x7100a63fd0
void Unk_a63fd0_update() {}

// 0x7100a63fe0
void Unk_a63fe0_update() {}

// 0x7100a63ff0
void Unk_a63ff0_update() {}

// 0x7100a64000
void Unk_a64000_update() {}

// 0x7100a64010
void Unk_a64010_update() {}

// 0x7100a64020
void Unk_a64020_update() {}

// 0x7100a64030
void Unk_a64030_update() {}

// 0x7100a64040
void Unk_a64040_update() {}

// 0x7100a64050
void Unk_a64050_update() {}

// 0x7100a64060
void Unk_a64060_update() {}

// 0x7100a64070
void Unk_a64070_update() {}

// 0x7100a64080
void Unk_a64080_update() {}

// 0x7100a64090
void Unk_a64090_update() {}

// 0x7100a640a0
void Unk_a640a0_update() {}

// 0x7100a640b0
void Unk_a640b0_update() {}

// 0x7100a640c0
void Unk_a640c0_update() {}

// 0x7100a640d0
void Unk_a640d0_update() {}

// 0x7100a640e0
void Unk_a640e0_update() {}

// 0x7100a640f0
void Unk_a640f0_update() {}

// 0x7100a64100
void Unk_a64100_update() {}

// 0x7100a64110
void Unk_a64110_update() {}

// 0x7100a64120
void Unk_a64120_update() {}

// 0x7100a64130
void Unk_a64130_update() {}

// 0x7100a64140
void Unk_a64140_update() {}

// 0x7100a64150
void Unk_a64150_update() {}

// 0x7100a64160
void Unk_a64160_update() {}

// 0x7100a64170
void Unk_a64170_update() {}

// 0x7100a64180
void Unk_a64180_update() {}

// 0x7100a64190
void Unk_a64190_update() {}

// 0x7100a641a0
void Unk_a641a0_update() {}

// 0x7100a641b0
void Unk_a641b0_update() {}

// 0x7100a641c0
void Unk_a641c0_update() {}

// 0x7100a641d0
void Unk_a641d0_update() {}

// 0x7100a641e0
void Unk_a641e0_update() {}

// 0x7100a641f0
void Unk_a641f0_update() {}

// 0x7100a64200
void Unk_a64200_update() {}

// 0x7100a64210
void Unk_a64210_update() {}

// 0x7100a64220
void Unk_a64220_update() {}

// 0x7100a64230
void Unk_a64230_update() {}

// 0x7100a64240
void Unk_a64240_update() {}

// 0x7100a64250
void Unk_a64250_update() {}

// 0x7100a64260
void Unk_a64260_update() {}

// 0x7100a64270
void Unk_a64270_update() {}

// 0x7100a64280
void Unk_a64280_update() {}

// 0x7100a64290
void Unk_a64290_update() {}

// 0x7100a642a0
void Unk_a642a0_update() {}

// 0x7100a642b0
void Unk_a642b0_update() {}

// 0x7100a642c0
void Unk_a642c0_update() {}

// 0x7100a642d0
void Unk_a642d0_update() {}

// 0x7100a642e0
void Unk_a642e0_update() {}

// 0x7100a642f0
void Unk_a642f0_update() {}

// 0x7100a64300
void Unk_a64300_update() {}

// 0x7100a64310
void Unk_a64310_update() {}

// 0x7100a64320
void Unk_a64320_update() {}

// 0x7100a64330
void Unk_a64330_update() {}

// 0x7100a64340
void Unk_a64340_update() {}

// 0x7100a64350
void Unk_a64350_update() {}

// 0x7100a64360
void Unk_a64360_update() {}

// 0x7100a64370
void Unk_a64370_update() {}

// 0x7100a64380
void Unk_a64380_update() {}

// 0x7100a64390
void Unk_a64390_update() {}

// 0x7100a643a0
void Unk_a643a0_update() {}

// 0x7100a643b0
void Unk_a643b0_update() {}

// 0x7100a643c0
void Unk_a643c0_update() {}

// 0x7100a643d0
void Unk_a643d0_update() {}

// 0x7100a643e0
void Unk_a643e0_update() {}

// 0x7100a643f0
void Unk_a643f0_update() {}

// 0x7100a64400
void Unk_a64400_update() {}

// 0x7100a64410
void Unk_a64410_update() {}

// 0x7100a64420
void Unk_a64420_update() {}

// 0x7100a64430
void Unk_a64430_update() {}

// 0x7100a64440
void Unk_a64440_update() {}

// 0x7100a64450
void Unk_a64450_update() {}

// 0x7100a64460
void Unk_a64460_update() {}

// 0x7100a64470
void Unk_a64470_update() {}

// 0x7100a64480
void Unk_a64480_update() {}

// 0x7100a64490
void Unk_a64490_update() {}

// 0x7100a644a0
void Unk_a644a0_update() {}

// 0x7100a644b0
void Unk_a644b0_update() {}

// 0x7100a644c0
void Unk_a644c0_update() {}

// 0x7100a644d0
void Unk_a644d0_update() {}

// 0x7100a644e0
void Unk_a644e0_update() {}

// 0x7100a644f0
void Unk_a644f0_update() {}

// 0x7100a64500
void Unk_a64500_update() {}

// 0x7100a64510
void Unk_a64510_update() {}

// 0x7100a64520
void Unk_a64520_update() {}

// 0x7100a64530
void Unk_a64530_update() {}

// 0x7100a64540
void Unk_a64540_update() {}

// 0x7100a64550
void Unk_a64550_update() {}

// 0x7100a64560
void Unk_a64560_update() {}

// 0x7100a64570
void Unk_a64570_update() {}

// 0x7100a64580
void Unk_a64580_update() {}

// 0x7100a64590
void Unk_a64590_update() {}

// 0x7100a645a0
void Unk_a645a0_update() {}

// 0x7100a645b0
void Unk_a645b0_update() {}

// 0x7100a645c0
void Unk_a645c0_update() {}

// 0x7100a645d0
void Unk_a645d0_update() {}

// 0x7100a645e0
void Unk_a645e0_update() {}

// 0x7100a645f0
void Unk_a645f0_update() {}

// 0x7100a64600
void Unk_a64600_update() {}

// 0x7100a64610
void Unk_a64610_update() {}

// 0x7100a64620
void Unk_a64620_update() {}

// 0x7100a64630
void Unk_a64630_update() {}

// 0x7100a64640
void Unk_a64640_update() {}

// 0x7100a64650
void Unk_a64650_update() {}

// 0x7100a64660
void Unk_a64660_update() {}

// 0x7100a64670
void Unk_a64670_update() {}

// 0x7100a64680
void Unk_a64680_update() {}

// 0x7100a64690
void Unk_a64690_update() {}

// 0x7100a646a0
void Unk_a646a0_update() {}

// 0x7100a646b0
void Unk_a646b0_update() {}

// 0x7100a646c0
void Unk_a646c0_update() {}

// 0x7100a646d0
void Unk_a646d0_update() {}

// 0x7100a646e0
void Unk_a646e0_update() {}

// 0x7100a646f0
void Unk_a646f0_update() {}

// 0x7100a64700
void Unk_a64700_update() {}

// 0x7100a64710
void Unk_a64710_update() {}

// 0x7100a64720
void Unk_a64720_update() {}

// 0x7100a64730
void Unk_a64730_update() {}

// 0x7100a64740
void Unk_a64740_update() {}

// 0x7100a64750
void Unk_a64750_update() {}

// 0x7100a64760
void Unk_a64760_update() {}

// 0x7100a64770
void Unk_a64770_update() {}

// 0x7100a64780
void Unk_a64780_update() {}

// 0x7100a64790
void Unk_a64790_update() {}

// 0x7100a647a0
void Unk_a647a0_update() {}

// 0x7100a647b0
void Unk_a647b0_update() {}

// 0x7100a647c0
void Unk_a647c0_update() {}

// 0x7100a647d0
void Unk_a647d0_update() {}

// 0x7100a647e0
void Unk_a647e0_update() {}

// 0x7100a647f0
void Unk_a647f0_update() {}

// 0x7100a64800
void Unk_a64800_update() {}

// 0x7100a64810
void Unk_a64810_update() {}

// 0x7100a64820
void Unk_a64820_update() {}

// 0x7100a64830
void Unk_a64830_update() {}

// 0x7100a64840
void Unk_a64840_update() {}

// 0x7100a64850
void Unk_a64850_update() {}

// 0x7100a64860
void Unk_a64860_update() {}

// 0x7100a64870
void Unk_a64870_update() {}

// 0x7100a64880
void Unk_a64880_update() {}

// 0x7100a64890
void Unk_a64890_update() {}

// 0x7100a648a0
void Unk_a648a0_update() {}

// 0x7100a648b0
void Unk_a648b0_update() {}

// 0x7100a648c0
void Unk_a648c0_update() {}

// 0x7100a648d0
void Unk_a648d0_update() {}

// 0x7100a648e0
void Unk_a648e0_update() {}

// 0x7100a648f0
void Unk_a648f0_update() {}

// 0x7100a64900
void Unk_a64900_update() {}

// 0x7100a64910
void Unk_a64910_update() {}

// 0x7100a64920
void Unk_a64920_update() {}

// 0x7100a64930
void Unk_a64930_update() {}

// 0x7100a64940
void Unk_a64940_update() {}

// 0x7100a64950
void Unk_a64950_update() {}

// 0x7100a64960
void Unk_a64960_update() {}

// 0x7100a64970
void Unk_a64970_update() {}

// 0x7100a64980
void Unk_a64980_update() {}

// 0x7100a64990
void Unk_a64990_update() {}

// 0x7100a649a0
void Unk_a649a0_update() {}

// 0x7100a649b0
void Unk_a649b0_update() {}

// 0x7100a649c0
void Unk_a649c0_update() {}

// 0x7100a649d0
void Unk_a649d0_update() {}

// 0x7100a649e0
void Unk_a649e0_update() {}

// 0x7100a649f0
void Unk_a649f0_update() {}

// 0x7100a64a00
void Unk_a64a00_update() {}

// 0x7100a64a10
void Unk_a64a10_update() {}

// 0x7100a64a20
void Unk_a64a20_update() {}

// 0x7100a64a30
void Unk_a64a30_update() {}

// 0x7100a64a40
void Unk_a64a40_update() {}

// 0x7100a64a50
void Unk_a64a50_update() {}

// 0x7100a64a60
void Unk_a64a60_update() {}

// 0x7100a64a70
void Unk_a64a70_update() {}

// 0x7100a64a80
void Unk_a64a80_update() {}

// 0x7100a64a90
void Unk_a64a90_update() {}

// 0x7100a64aa0
void Unk_a64aa0_update() {}

// 0x7100a64ab0
void Unk_a64ab0_update() {}

// 0x7100a64ac0
void Unk_a64ac0_update() {}

// 0x7100a64ad0
void Unk_a64ad0_update() {}

// 0x7100a64ae0
void Unk_a64ae0_update() {}

// 0x7100a64af0
void Unk_a64af0_update() {}

// 0x7100a64b00
void Unk_a64b00_update() {}

// 0x7100a64b10
void Unk_a64b10_update() {}

// 0x7100a64b20
void Unk_a64b20_update() {}

// 0x7100a64b30
void Unk_a64b30_update() {}

// 0x7100a64b40
void Unk_a64b40_update() {}

// 0x7100a64b50
void Unk_a64b50_update() {}

// 0x7100a64b60
void Unk_a64b60_update() {}

// 0x7100a64b70
void Unk_a64b70_update() {}

// 0x7100a64b80
void Unk_a64b80_update() {}

// 0x7100a64b90
void Unk_a64b90_update() {}

// 0x7100a64ba0
void Unk_a64ba0_update() {}

// 0x7100a64bb0
void Unk_a64bb0_update() {}

// 0x7100a64bc0
void Unk_a64bc0_update() {}

// 0x7100a64bd0
void Unk_a64bd0_update() {}

// 0x7100a64be0
void Unk_a64be0_update() {}

// 0x7100a64bf0
void Unk_a64bf0_update() {}

// 0x7100a64c00
void Unk_a64c00_update() {}

// 0x7100a64c10
void Unk_a64c10_update() {}

// 0x7100a64c20
void Unk_a64c20_update() {}

// 0x7100a64c30
void Unk_a64c30_update() {}

// 0x7100a64c40
void Unk_a64c40_update() {}

// 0x7100a64c50
void Unk_a64c50_update() {}

// 0x7100a64c60
void Unk_a64c60_update() {}

// 0x7100a64c70
void Unk_a64c70_update() {}

// 0x7100a64c80
void Unk_a64c80_update() {}

// 0x7100a64c90
void Unk_a64c90_update() {}

// 0x7100a64ca0
void Unk_a64ca0_update() {}

// 0x7100a64cb0
void Unk_a64cb0_update() {}

// 0x7100a64cc0
void Unk_a64cc0_update() {}

// 0x7100a64cd0
void Unk_a64cd0_update() {}

// 0x7100a64ce0
void Unk_a64ce0_update() {}

// 0x7100a64cf0
void Unk_a64cf0_update() {}

// 0x7100a64d00
void Unk_a64d00_update() {}

// 0x7100a64d10
void Unk_a64d10_update() {}

// 0x7100a64d20
void Unk_a64d20_update() {}

// 0x7100a64d30
void Unk_a64d30_update() {}

// 0x7100a64d40
void Unk_a64d40_update() {}

// 0x7100a64d50
void Unk_a64d50_update() {}

// 0x7100a64d60
void Unk_a64d60_update() {}

// 0x7100a64d70
void Unk_a64d70_update() {}

// 0x7100a64d80
void Unk_a64d80_update() {}

// 0x7100a64d90
void Unk_a64d90_update() {}

// 0x7100a64da0
void Unk_a64da0_update() {}

// 0x7100a64db0
void Unk_a64db0_update() {}

// 0x7100a64dc0
void Unk_a64dc0_update() {}

// 0x7100a64dd0
void Unk_a64dd0_update() {}

// 0x7100a64de0
void Unk_a64de0_update() {}

// 0x7100a64df0
void Unk_a64df0_update() {}

// 0x7100a64e00
void Unk_a64e00_update() {}

// 0x7100a64e10
void Unk_a64e10_update() {}

// 0x7100a64e20
void Unk_a64e20_update() {}

// 0x7100a64e30
void Unk_a64e30_update() {}

// 0x7100a64e40
void Unk_a64e40_update() {}

// 0x7100a64e50
void Unk_a64e50_update() {}

// 0x7100a64e60
void Unk_a64e60_update() {}

// 0x7100a64e70
void Unk_a64e70_update() {}

// 0x7100a64e80
void Unk_a64e80_update() {}

// 0x7100a64e90
void Unk_a64e90_update() {}

// 0x7100a64ea0
void Unk_a64ea0_update() {}

// 0x7100a64eb0
void Unk_a64eb0_update() {}

// 0x7100a64ec0
void Unk_a64ec0_update() {}

// 0x7100a64ed0
void Unk_a64ed0_update() {}

// 0x7100a64ee0
void Unk_a64ee0_update() {}

// 0x7100a64ef0
void Unk_a64ef0_update() {}

// 0x7100a64f00
void Unk_a64f00_update() {}

// 0x7100a64f10
void Unk_a64f10_update() {}

// 0x7100a64f20
void Unk_a64f20_update() {}

// 0x7100a64f30
void Unk_a64f30_update() {}

// 0x7100a64f40
void Unk_a64f40_update() {}

// 0x7100a64f50
void Unk_a64f50_update() {}

// 0x7100a64f60
void Unk_a64f60_update() {}

// 0x7100a64f70
void Unk_a64f70_update() {}

// 0x7100a64f80
void Unk_a64f80_update() {}

// 0x7100a64f90
void Unk_a64f90_update() {}

// 0x7100a64fa0
void Unk_a64fa0_update() {}

// 0x7100a64fb0
void Unk_a64fb0_update() {}

// 0x7100a64fc0
void Unk_a64fc0_update() {}

// 0x7100a64fd0
void Unk_a64fd0_update() {}

// 0x7100a64ff0
void Unk_a64ff0_update() {}

struct Unk_a65000_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65000_arg1, field_0, 0x0);

struct Unk_a65000 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65000, field_0, 0x0);

// 0x7100a65000
void Unk_a65000_set(const Unk_a65000* self, Unk_a65000_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65010_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65010_arg1, field_0, 0x0);

struct Unk_a65010 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65010, field_0, 0x0);

// 0x7100a65010
void Unk_a65010_set(const Unk_a65010* self, Unk_a65010_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a65030
void Unk_a65030_update() {}

struct Unk_a65040_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65040_arg1, field_0, 0x0);

struct Unk_a65040 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65040, field_0, 0x0);

// 0x7100a65040
void Unk_a65040_set(const Unk_a65040* self, Unk_a65040_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65050_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65050_arg1, field_0, 0x0);

struct Unk_a65050 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65050, field_0, 0x0);

// 0x7100a65050
void Unk_a65050_set(const Unk_a65050* self, Unk_a65050_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a65290
void Unk_a65290_update() {}

struct Unk_a652a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652a0_arg1, field_0, 0x0);

struct Unk_a652a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652a0, field_0, 0x0);

// 0x7100a652a0
void Unk_a652a0_set(const Unk_a652a0* self, Unk_a652a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a652b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652b0_arg1, field_0, 0x0);

struct Unk_a652b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652b0, field_0, 0x0);

// 0x7100a652b0
void Unk_a652b0_set(const Unk_a652b0* self, Unk_a652b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a652d0
void Unk_a652d0_update() {}

struct Unk_a652e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652e0_arg1, field_0, 0x0);

struct Unk_a652e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652e0, field_0, 0x0);

// 0x7100a652e0
void Unk_a652e0_set(const Unk_a652e0* self, Unk_a652e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a652f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652f0_arg1, field_0, 0x0);

struct Unk_a652f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a652f0, field_0, 0x0);

// 0x7100a652f0
void Unk_a652f0_set(const Unk_a652f0* self, Unk_a652f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a65310
void Unk_a65310_update() {}

struct Unk_a65320_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65320_arg1, field_0, 0x0);

struct Unk_a65320 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65320, field_0, 0x0);

// 0x7100a65320
void Unk_a65320_set(const Unk_a65320* self, Unk_a65320_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65330_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65330_arg1, field_0, 0x0);

struct Unk_a65330 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65330, field_0, 0x0);

// 0x7100a65330
void Unk_a65330_set(const Unk_a65330* self, Unk_a65330_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65480_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a65480_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a65480_0, field_3c8, 0x3c8);

struct Unk_a65480_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65480_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65480_arg1, field_8, 0x8);

struct Unk_a65480 {
    Unk_a65480_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65480, field_0, 0x0);

// 0x7100a65480
void Unk_a65480_set(const Unk_a65480* self, const Unk_a65480_arg1* value) {
    Unk_a65480_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a654a0
void Unk_a654a0_update() {}

struct Unk_a654b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a654b0_arg1, field_0, 0x0);

struct Unk_a654b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a654b0, field_0, 0x0);

// 0x7100a654b0
void Unk_a654b0_set(const Unk_a654b0* self, Unk_a654b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a654c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a654c0_arg1, field_0, 0x0);

struct Unk_a654c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a654c0, field_0, 0x0);

// 0x7100a654c0
void Unk_a654c0_set(const Unk_a654c0* self, Unk_a654c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65610_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a65610_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a65610_0, field_3c8, 0x3c8);

struct Unk_a65610_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65610_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65610_arg1, field_8, 0x8);

struct Unk_a65610 {
    Unk_a65610_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65610, field_0, 0x0);

// 0x7100a65610
void Unk_a65610_set(const Unk_a65610* self, const Unk_a65610_arg1* value) {
    Unk_a65610_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a65630
void Unk_a65630_update() {}

struct Unk_a65640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65640_arg1, field_0, 0x0);

struct Unk_a65640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65640, field_0, 0x0);

// 0x7100a65640
void Unk_a65640_set(const Unk_a65640* self, Unk_a65640_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65650_arg1, field_0, 0x0);

struct Unk_a65650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65650, field_0, 0x0);

// 0x7100a65650
void Unk_a65650_set(const Unk_a65650* self, Unk_a65650_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a657a0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a657a0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a657a0_0, field_3f8, 0x3f8);

struct Unk_a657a0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a657a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a657a0_arg1, field_8, 0x8);

struct Unk_a657a0 {
    Unk_a657a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a657a0, field_0, 0x0);

// 0x7100a657a0
void Unk_a657a0_set(const Unk_a657a0* self, const Unk_a657a0_arg1* value) {
    Unk_a657a0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a657c0
void Unk_a657c0_update() {}

struct Unk_a657d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a657d0_arg1, field_0, 0x0);

struct Unk_a657d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a657d0, field_0, 0x0);

// 0x7100a657d0
void Unk_a657d0_set(const Unk_a657d0* self, Unk_a657d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a657e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a657e0_arg1, field_0, 0x0);

struct Unk_a657e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a657e0, field_0, 0x0);

// 0x7100a657e0
void Unk_a657e0_set(const Unk_a657e0* self, Unk_a657e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a657f0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a657f0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a657f0_0, field_3f8, 0x3f8);

struct Unk_a657f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a657f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a657f0_arg1, field_8, 0x8);

struct Unk_a657f0 {
    Unk_a657f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a657f0, field_0, 0x0);

// 0x7100a657f0
void Unk_a657f0_set(const Unk_a657f0* self, const Unk_a657f0_arg1* value) {
    Unk_a657f0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a65810
void Unk_a65810_update() {}

struct Unk_a65820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65820_arg1, field_0, 0x0);

struct Unk_a65820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65820, field_0, 0x0);

// 0x7100a65820
void Unk_a65820_set(const Unk_a65820* self, Unk_a65820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65830_arg1, field_0, 0x0);

struct Unk_a65830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65830, field_0, 0x0);

// 0x7100a65830
void Unk_a65830_set(const Unk_a65830* self, Unk_a65830_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65840_0 {
    u8 _0[0x420];
    u64 field_420;
    u64 field_428;
};
PKMN_OFFSET_ASSERT(Unk_a65840_0, field_420, 0x420);
PKMN_OFFSET_ASSERT(Unk_a65840_0, field_428, 0x428);

struct Unk_a65840_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65840_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65840_arg1, field_8, 0x8);

struct Unk_a65840 {
    Unk_a65840_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65840, field_0, 0x0);

// 0x7100a65840
void Unk_a65840_set(const Unk_a65840* self, const Unk_a65840_arg1* value) {
    Unk_a65840_0* p0 = self->field_0;
    p0->field_428 = value->field_8;
    p0->field_420 = value->field_0;
}

// 0x7100a65860
void Unk_a65860_update() {}

struct Unk_a65870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65870_arg1, field_0, 0x0);

struct Unk_a65870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65870, field_0, 0x0);

// 0x7100a65870
void Unk_a65870_set(const Unk_a65870* self, Unk_a65870_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65880_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65880_arg1, field_0, 0x0);

struct Unk_a65880 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65880, field_0, 0x0);

// 0x7100a65880
void Unk_a65880_set(const Unk_a65880* self, Unk_a65880_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65890_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a65890_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a65890_0, field_3c8, 0x3c8);

struct Unk_a65890_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65890_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65890_arg1, field_8, 0x8);

struct Unk_a65890 {
    Unk_a65890_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65890, field_0, 0x0);

// 0x7100a65890
void Unk_a65890_set(const Unk_a65890* self, const Unk_a65890_arg1* value) {
    Unk_a65890_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a658b0
void Unk_a658b0_update() {}

struct Unk_a658c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a658c0_arg1, field_0, 0x0);

struct Unk_a658c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a658c0, field_0, 0x0);

// 0x7100a658c0
void Unk_a658c0_set(const Unk_a658c0* self, Unk_a658c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a658d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a658d0_arg1, field_0, 0x0);

struct Unk_a658d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a658d0, field_0, 0x0);

// 0x7100a658d0
void Unk_a658d0_set(const Unk_a658d0* self, Unk_a658d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a658e0_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a658e0_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a658e0_0, field_448, 0x448);

struct Unk_a658e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a658e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a658e0_arg1, field_8, 0x8);

struct Unk_a658e0 {
    Unk_a658e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a658e0, field_0, 0x0);

// 0x7100a658e0
void Unk_a658e0_set(const Unk_a658e0* self, const Unk_a658e0_arg1* value) {
    Unk_a658e0_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a65900
void Unk_a65900_update() {}

struct Unk_a65910_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65910_arg1, field_0, 0x0);

struct Unk_a65910 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65910, field_0, 0x0);

// 0x7100a65910
void Unk_a65910_set(const Unk_a65910* self, Unk_a65910_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65920_arg1, field_0, 0x0);

struct Unk_a65920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65920, field_0, 0x0);

// 0x7100a65920
void Unk_a65920_set(const Unk_a65920* self, Unk_a65920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65930_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a65930_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a65930_0, field_448, 0x448);

struct Unk_a65930_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65930_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65930_arg1, field_8, 0x8);

struct Unk_a65930 {
    Unk_a65930_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65930, field_0, 0x0);

// 0x7100a65930
void Unk_a65930_set(const Unk_a65930* self, const Unk_a65930_arg1* value) {
    Unk_a65930_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a65950
void Unk_a65950_update() {}

struct Unk_a65960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65960_arg1, field_0, 0x0);

struct Unk_a65960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65960, field_0, 0x0);

// 0x7100a65960
void Unk_a65960_set(const Unk_a65960* self, Unk_a65960_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65970_arg1, field_0, 0x0);

struct Unk_a65970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65970, field_0, 0x0);

// 0x7100a65970
void Unk_a65970_set(const Unk_a65970* self, Unk_a65970_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65980_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a65980_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a65980_0, field_448, 0x448);

struct Unk_a65980_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65980_arg1, field_8, 0x8);

struct Unk_a65980 {
    Unk_a65980_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65980, field_0, 0x0);

// 0x7100a65980
void Unk_a65980_set(const Unk_a65980* self, const Unk_a65980_arg1* value) {
    Unk_a65980_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a659a0
void Unk_a659a0_update() {}

struct Unk_a659b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a659b0_arg1, field_0, 0x0);

struct Unk_a659b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a659b0, field_0, 0x0);

// 0x7100a659b0
void Unk_a659b0_set(const Unk_a659b0* self, Unk_a659b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a659c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a659c0_arg1, field_0, 0x0);

struct Unk_a659c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a659c0, field_0, 0x0);

// 0x7100a659c0
void Unk_a659c0_set(const Unk_a659c0* self, Unk_a659c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a65bf0
void Unk_a65bf0_update() {}

struct Unk_a65c00 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65c00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65c00, field_8, 0x8);

// 0x7100a65c00
void Unk_a65c00_set(const Unk_a65c00* self, Unk_a65c00* value) {
    *value = *self;
}

struct Unk_a65c10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65c10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65c10, field_8, 0x8);

// 0x7100a65c10
void Unk_a65c10_set(const Unk_a65c10* self, Unk_a65c10* value) {
    *value = *self;
}

struct Unk_a65c20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65c20, field_0, 0x0);

void Unk_981350(u64);

// 0x7100a65c20
void Unk_a65c20_call(const Unk_a65c20* self) {
    Unk_981350(self->field_0);
}

// 0x7100a65c30
void Unk_a65c30_update() {}

struct Unk_a65c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65c40_arg1, field_0, 0x0);

struct Unk_a65c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65c40, field_0, 0x0);

// 0x7100a65c40
void Unk_a65c40_set(const Unk_a65c40* self, Unk_a65c40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65c50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65c50_arg1, field_0, 0x0);

struct Unk_a65c50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65c50, field_0, 0x0);

// 0x7100a65c50
void Unk_a65c50_set(const Unk_a65c50* self, Unk_a65c50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65da0_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a65da0_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a65da0_0, field_3d8, 0x3d8);

struct Unk_a65da0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65da0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65da0_arg1, field_8, 0x8);

struct Unk_a65da0 {
    Unk_a65da0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65da0, field_0, 0x0);

// 0x7100a65da0
void Unk_a65da0_set(const Unk_a65da0* self, const Unk_a65da0_arg1* value) {
    Unk_a65da0_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a65dc0
void Unk_a65dc0_update() {}

struct Unk_a65dd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65dd0_arg1, field_0, 0x0);

struct Unk_a65dd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65dd0, field_0, 0x0);

// 0x7100a65dd0
void Unk_a65dd0_set(const Unk_a65dd0* self, Unk_a65dd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65de0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65de0_arg1, field_0, 0x0);

struct Unk_a65de0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65de0, field_0, 0x0);

// 0x7100a65de0
void Unk_a65de0_set(const Unk_a65de0* self, Unk_a65de0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65f30_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a65f30_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a65f30_0, field_3d8, 0x3d8);

struct Unk_a65f30_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a65f30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a65f30_arg1, field_8, 0x8);

struct Unk_a65f30 {
    Unk_a65f30_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65f30, field_0, 0x0);

// 0x7100a65f30
void Unk_a65f30_set(const Unk_a65f30* self, const Unk_a65f30_arg1* value) {
    Unk_a65f30_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a65f50
void Unk_a65f50_update() {}

struct Unk_a65f60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65f60_arg1, field_0, 0x0);

struct Unk_a65f60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65f60, field_0, 0x0);

// 0x7100a65f60
void Unk_a65f60_set(const Unk_a65f60* self, Unk_a65f60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65f70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65f70_arg1, field_0, 0x0);

struct Unk_a65f70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65f70, field_0, 0x0);

// 0x7100a65f70
void Unk_a65f70_set(const Unk_a65f70* self, Unk_a65f70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a65f90
void Unk_a65f90_update() {}

struct Unk_a65fa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65fa0_arg1, field_0, 0x0);

struct Unk_a65fa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65fa0, field_0, 0x0);

// 0x7100a65fa0
void Unk_a65fa0_set(const Unk_a65fa0* self, Unk_a65fa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65fb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65fb0_arg1, field_0, 0x0);

struct Unk_a65fb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65fb0, field_0, 0x0);

// 0x7100a65fb0
void Unk_a65fb0_set(const Unk_a65fb0* self, Unk_a65fb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a65fd0
void Unk_a65fd0_update() {}

struct Unk_a65fe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65fe0_arg1, field_0, 0x0);

struct Unk_a65fe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65fe0, field_0, 0x0);

// 0x7100a65fe0
void Unk_a65fe0_set(const Unk_a65fe0* self, Unk_a65fe0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a65ff0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65ff0_arg1, field_0, 0x0);

struct Unk_a65ff0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a65ff0, field_0, 0x0);

// 0x7100a65ff0
void Unk_a65ff0_set(const Unk_a65ff0* self, Unk_a65ff0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a66290
void Unk_a66290_update() {}

struct Unk_a662a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a662a0_arg1, field_0, 0x0);

struct Unk_a662a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a662a0, field_0, 0x0);

// 0x7100a662a0
void Unk_a662a0_set(const Unk_a662a0* self, Unk_a662a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a662b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a662b0_arg1, field_0, 0x0);

struct Unk_a662b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a662b0, field_0, 0x0);

// 0x7100a662b0
void Unk_a662b0_set(const Unk_a662b0* self, Unk_a662b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a66fb0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a66fb0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a66fb0_0, field_3c8, 0x3c8);

struct Unk_a66fb0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a66fb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a66fb0_arg1, field_8, 0x8);

struct Unk_a66fb0 {
    Unk_a66fb0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a66fb0, field_0, 0x0);

// 0x7100a66fb0
void Unk_a66fb0_set(const Unk_a66fb0* self, const Unk_a66fb0_arg1* value) {
    Unk_a66fb0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a66fd0
void Unk_a66fd0_update() {}

struct Unk_a66fe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a66fe0_arg1, field_0, 0x0);

struct Unk_a66fe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a66fe0, field_0, 0x0);

// 0x7100a66fe0
void Unk_a66fe0_set(const Unk_a66fe0* self, Unk_a66fe0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a66ff0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a66ff0_arg1, field_0, 0x0);

struct Unk_a66ff0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a66ff0, field_0, 0x0);

// 0x7100a66ff0
void Unk_a66ff0_set(const Unk_a66ff0* self, Unk_a66ff0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67000_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a67000_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a67000_0, field_3c8, 0x3c8);

struct Unk_a67000_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67000_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67000_arg1, field_8, 0x8);

struct Unk_a67000 {
    Unk_a67000_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67000, field_0, 0x0);

// 0x7100a67000
void Unk_a67000_set(const Unk_a67000* self, const Unk_a67000_arg1* value) {
    Unk_a67000_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a67020
void Unk_a67020_update() {}

struct Unk_a67030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67030_arg1, field_0, 0x0);

struct Unk_a67030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67030, field_0, 0x0);

// 0x7100a67030
void Unk_a67030_set(const Unk_a67030* self, Unk_a67030_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67040_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67040_arg1, field_0, 0x0);

struct Unk_a67040 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67040, field_0, 0x0);

// 0x7100a67040
void Unk_a67040_set(const Unk_a67040* self, Unk_a67040_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67050_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a67050_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a67050_0, field_3c8, 0x3c8);

struct Unk_a67050_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67050_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67050_arg1, field_8, 0x8);

struct Unk_a67050 {
    Unk_a67050_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67050, field_0, 0x0);

// 0x7100a67050
void Unk_a67050_set(const Unk_a67050* self, const Unk_a67050_arg1* value) {
    Unk_a67050_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a67070
void Unk_a67070_update() {}

struct Unk_a67080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67080_arg1, field_0, 0x0);

struct Unk_a67080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67080, field_0, 0x0);

// 0x7100a67080
void Unk_a67080_set(const Unk_a67080* self, Unk_a67080_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67090_arg1, field_0, 0x0);

struct Unk_a67090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67090, field_0, 0x0);

// 0x7100a67090
void Unk_a67090_set(const Unk_a67090* self, Unk_a67090_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a670a0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a670a0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a670a0_0, field_3c8, 0x3c8);

struct Unk_a670a0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a670a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a670a0_arg1, field_8, 0x8);

struct Unk_a670a0 {
    Unk_a670a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a670a0, field_0, 0x0);

// 0x7100a670a0
void Unk_a670a0_set(const Unk_a670a0* self, const Unk_a670a0_arg1* value) {
    Unk_a670a0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a670c0
void Unk_a670c0_update() {}

struct Unk_a670d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a670d0_arg1, field_0, 0x0);

struct Unk_a670d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a670d0, field_0, 0x0);

// 0x7100a670d0
void Unk_a670d0_set(const Unk_a670d0* self, Unk_a670d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a670e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a670e0_arg1, field_0, 0x0);

struct Unk_a670e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a670e0, field_0, 0x0);

// 0x7100a670e0
void Unk_a670e0_set(const Unk_a670e0* self, Unk_a670e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a670f0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a670f0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a670f0_0, field_3f8, 0x3f8);

struct Unk_a670f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a670f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a670f0_arg1, field_8, 0x8);

struct Unk_a670f0 {
    Unk_a670f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a670f0, field_0, 0x0);

// 0x7100a670f0
void Unk_a670f0_set(const Unk_a670f0* self, const Unk_a670f0_arg1* value) {
    Unk_a670f0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a67110
void Unk_a67110_update() {}

struct Unk_a67120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67120_arg1, field_0, 0x0);

struct Unk_a67120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67120, field_0, 0x0);

// 0x7100a67120
void Unk_a67120_set(const Unk_a67120* self, Unk_a67120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67130_arg1, field_0, 0x0);

struct Unk_a67130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67130, field_0, 0x0);

// 0x7100a67130
void Unk_a67130_set(const Unk_a67130* self, Unk_a67130_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67140_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a67140_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a67140_0, field_448, 0x448);

struct Unk_a67140_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67140_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67140_arg1, field_8, 0x8);

struct Unk_a67140 {
    Unk_a67140_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67140, field_0, 0x0);

// 0x7100a67140
void Unk_a67140_set(const Unk_a67140* self, const Unk_a67140_arg1* value) {
    Unk_a67140_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a67160
void Unk_a67160_update() {}

struct Unk_a67170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67170_arg1, field_0, 0x0);

struct Unk_a67170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67170, field_0, 0x0);

// 0x7100a67170
void Unk_a67170_set(const Unk_a67170* self, Unk_a67170_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67180_arg1, field_0, 0x0);

struct Unk_a67180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67180, field_0, 0x0);

// 0x7100a67180
void Unk_a67180_set(const Unk_a67180* self, Unk_a67180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67190_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a67190_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a67190_0, field_448, 0x448);

struct Unk_a67190_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67190_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67190_arg1, field_8, 0x8);

struct Unk_a67190 {
    Unk_a67190_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67190, field_0, 0x0);

// 0x7100a67190
void Unk_a67190_set(const Unk_a67190* self, const Unk_a67190_arg1* value) {
    Unk_a67190_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a671b0
void Unk_a671b0_update() {}

struct Unk_a671c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a671c0_arg1, field_0, 0x0);

struct Unk_a671c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a671c0, field_0, 0x0);

// 0x7100a671c0
void Unk_a671c0_set(const Unk_a671c0* self, Unk_a671c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a671d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a671d0_arg1, field_0, 0x0);

struct Unk_a671d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a671d0, field_0, 0x0);

// 0x7100a671d0
void Unk_a671d0_set(const Unk_a671d0* self, Unk_a671d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a671e0_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a671e0_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a671e0_0, field_448, 0x448);

struct Unk_a671e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a671e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a671e0_arg1, field_8, 0x8);

struct Unk_a671e0 {
    Unk_a671e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a671e0, field_0, 0x0);

// 0x7100a671e0
void Unk_a671e0_set(const Unk_a671e0* self, const Unk_a671e0_arg1* value) {
    Unk_a671e0_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a67200
void Unk_a67200_update() {}

struct Unk_a67210_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67210_arg1, field_0, 0x0);

struct Unk_a67210 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67210, field_0, 0x0);

// 0x7100a67210
void Unk_a67210_set(const Unk_a67210* self, Unk_a67210_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67220_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67220_arg1, field_0, 0x0);

struct Unk_a67220 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67220, field_0, 0x0);

// 0x7100a67220
void Unk_a67220_set(const Unk_a67220* self, Unk_a67220_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67230_0 {
    u8 _0[0x450];
    u64 field_450;
    u64 field_458;
};
PKMN_OFFSET_ASSERT(Unk_a67230_0, field_450, 0x450);
PKMN_OFFSET_ASSERT(Unk_a67230_0, field_458, 0x458);

struct Unk_a67230_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67230_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67230_arg1, field_8, 0x8);

struct Unk_a67230 {
    Unk_a67230_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67230, field_0, 0x0);

// 0x7100a67230
void Unk_a67230_set(const Unk_a67230* self, const Unk_a67230_arg1* value) {
    Unk_a67230_0* p0 = self->field_0;
    p0->field_458 = value->field_8;
    p0->field_450 = value->field_0;
}

// 0x7100a67250
void Unk_a67250_update() {}

struct Unk_a67260_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67260_arg1, field_0, 0x0);

struct Unk_a67260 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67260, field_0, 0x0);

// 0x7100a67260
void Unk_a67260_set(const Unk_a67260* self, Unk_a67260_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67270_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67270_arg1, field_0, 0x0);

struct Unk_a67270 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67270, field_0, 0x0);

// 0x7100a67270
void Unk_a67270_set(const Unk_a67270* self, Unk_a67270_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67280_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a67280_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a67280_0, field_3f8, 0x3f8);

struct Unk_a67280_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67280_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67280_arg1, field_8, 0x8);

struct Unk_a67280 {
    Unk_a67280_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67280, field_0, 0x0);

// 0x7100a67280
void Unk_a67280_set(const Unk_a67280* self, const Unk_a67280_arg1* value) {
    Unk_a67280_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a672a0
void Unk_a672a0_update() {}

struct Unk_a672b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a672b0_arg1, field_0, 0x0);

struct Unk_a672b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a672b0, field_0, 0x0);

// 0x7100a672b0
void Unk_a672b0_set(const Unk_a672b0* self, Unk_a672b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a672c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a672c0_arg1, field_0, 0x0);

struct Unk_a672c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a672c0, field_0, 0x0);

// 0x7100a672c0
void Unk_a672c0_set(const Unk_a672c0* self, Unk_a672c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a672d0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a672d0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a672d0_0, field_3c8, 0x3c8);

struct Unk_a672d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a672d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a672d0_arg1, field_8, 0x8);

struct Unk_a672d0 {
    Unk_a672d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a672d0, field_0, 0x0);

// 0x7100a672d0
void Unk_a672d0_set(const Unk_a672d0* self, const Unk_a672d0_arg1* value) {
    Unk_a672d0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a672f0
void Unk_a672f0_update() {}

struct Unk_a67300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67300_arg1, field_0, 0x0);

struct Unk_a67300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67300, field_0, 0x0);

// 0x7100a67300
void Unk_a67300_set(const Unk_a67300* self, Unk_a67300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67310_arg1, field_0, 0x0);

struct Unk_a67310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67310, field_0, 0x0);

// 0x7100a67310
void Unk_a67310_set(const Unk_a67310* self, Unk_a67310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67320_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a67320_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a67320_0, field_448, 0x448);

struct Unk_a67320_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67320_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67320_arg1, field_8, 0x8);

struct Unk_a67320 {
    Unk_a67320_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67320, field_0, 0x0);

// 0x7100a67320
void Unk_a67320_set(const Unk_a67320* self, const Unk_a67320_arg1* value) {
    Unk_a67320_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a67340
void Unk_a67340_update() {}

struct Unk_a67350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67350_arg1, field_0, 0x0);

struct Unk_a67350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67350, field_0, 0x0);

// 0x7100a67350
void Unk_a67350_set(const Unk_a67350* self, Unk_a67350_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67360_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67360_arg1, field_0, 0x0);

struct Unk_a67360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67360, field_0, 0x0);

// 0x7100a67360
void Unk_a67360_set(const Unk_a67360* self, Unk_a67360_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67510_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a67510_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a67510_0, field_3d8, 0x3d8);

struct Unk_a67510_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67510_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67510_arg1, field_8, 0x8);

struct Unk_a67510 {
    Unk_a67510_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67510, field_0, 0x0);

// 0x7100a67510
void Unk_a67510_set(const Unk_a67510* self, const Unk_a67510_arg1* value) {
    Unk_a67510_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a67530
void Unk_a67530_update() {}

struct Unk_a67540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67540_arg1, field_0, 0x0);

struct Unk_a67540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67540, field_0, 0x0);

// 0x7100a67540
void Unk_a67540_set(const Unk_a67540* self, Unk_a67540_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67550_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67550_arg1, field_0, 0x0);

struct Unk_a67550 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67550, field_0, 0x0);

// 0x7100a67550
void Unk_a67550_set(const Unk_a67550* self, Unk_a67550_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67560_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a67560_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a67560_0, field_3d8, 0x3d8);

struct Unk_a67560_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a67560_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a67560_arg1, field_8, 0x8);

struct Unk_a67560 {
    Unk_a67560_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67560, field_0, 0x0);

// 0x7100a67560
void Unk_a67560_set(const Unk_a67560* self, const Unk_a67560_arg1* value) {
    Unk_a67560_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a67580
void Unk_a67580_update() {}

struct Unk_a67590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67590_arg1, field_0, 0x0);

struct Unk_a67590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67590, field_0, 0x0);

// 0x7100a67590
void Unk_a67590_set(const Unk_a67590* self, Unk_a67590_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a675a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a675a0_arg1, field_0, 0x0);

struct Unk_a675a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a675a0, field_0, 0x0);

// 0x7100a675a0
void Unk_a675a0_set(const Unk_a675a0* self, Unk_a675a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a675c0
void Unk_a675c0_update() {}

struct Unk_a675d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a675d0_arg1, field_0, 0x0);

struct Unk_a675d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a675d0, field_0, 0x0);

// 0x7100a675d0
void Unk_a675d0_set(const Unk_a675d0* self, Unk_a675d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a675e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a675e0_arg1, field_0, 0x0);

struct Unk_a675e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a675e0, field_0, 0x0);

// 0x7100a675e0
void Unk_a675e0_set(const Unk_a675e0* self, Unk_a675e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a67600
void Unk_a67600_update() {}

struct Unk_a67610_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67610_arg1, field_0, 0x0);

struct Unk_a67610 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67610, field_0, 0x0);

// 0x7100a67610
void Unk_a67610_set(const Unk_a67610* self, Unk_a67610_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a67620_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67620_arg1, field_0, 0x0);

struct Unk_a67620 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a67620, field_0, 0x0);

// 0x7100a67620
void Unk_a67620_set(const Unk_a67620* self, Unk_a67620_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68280_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a68280_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a68280_0, field_3c8, 0x3c8);

struct Unk_a68280_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68280_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68280_arg1, field_8, 0x8);

struct Unk_a68280 {
    Unk_a68280_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68280, field_0, 0x0);

// 0x7100a68280
void Unk_a68280_set(const Unk_a68280* self, const Unk_a68280_arg1* value) {
    Unk_a68280_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a682a0
void Unk_a682a0_update() {}

struct Unk_a682b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a682b0_arg1, field_0, 0x0);

struct Unk_a682b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a682b0, field_0, 0x0);

// 0x7100a682b0
void Unk_a682b0_set(const Unk_a682b0* self, Unk_a682b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a682c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a682c0_arg1, field_0, 0x0);

struct Unk_a682c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a682c0, field_0, 0x0);

// 0x7100a682c0
void Unk_a682c0_set(const Unk_a682c0* self, Unk_a682c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a682d0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a682d0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a682d0_0, field_3c8, 0x3c8);

struct Unk_a682d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a682d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a682d0_arg1, field_8, 0x8);

struct Unk_a682d0 {
    Unk_a682d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a682d0, field_0, 0x0);

// 0x7100a682d0
void Unk_a682d0_set(const Unk_a682d0* self, const Unk_a682d0_arg1* value) {
    Unk_a682d0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a682f0
void Unk_a682f0_update() {}

struct Unk_a68300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68300_arg1, field_0, 0x0);

struct Unk_a68300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68300, field_0, 0x0);

// 0x7100a68300
void Unk_a68300_set(const Unk_a68300* self, Unk_a68300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68310_arg1, field_0, 0x0);

struct Unk_a68310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68310, field_0, 0x0);

// 0x7100a68310
void Unk_a68310_set(const Unk_a68310* self, Unk_a68310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68320_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a68320_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a68320_0, field_3f8, 0x3f8);

struct Unk_a68320_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68320_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68320_arg1, field_8, 0x8);

struct Unk_a68320 {
    Unk_a68320_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68320, field_0, 0x0);

// 0x7100a68320
void Unk_a68320_set(const Unk_a68320* self, const Unk_a68320_arg1* value) {
    Unk_a68320_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a68340
void Unk_a68340_update() {}

struct Unk_a68350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68350_arg1, field_0, 0x0);

struct Unk_a68350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68350, field_0, 0x0);

// 0x7100a68350
void Unk_a68350_set(const Unk_a68350* self, Unk_a68350_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68360_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68360_arg1, field_0, 0x0);

struct Unk_a68360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68360, field_0, 0x0);

// 0x7100a68360
void Unk_a68360_set(const Unk_a68360* self, Unk_a68360_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68370_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a68370_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a68370_0, field_448, 0x448);

struct Unk_a68370_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68370_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68370_arg1, field_8, 0x8);

struct Unk_a68370 {
    Unk_a68370_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68370, field_0, 0x0);

// 0x7100a68370
void Unk_a68370_set(const Unk_a68370* self, const Unk_a68370_arg1* value) {
    Unk_a68370_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a68390
void Unk_a68390_update() {}

struct Unk_a683a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683a0_arg1, field_0, 0x0);

struct Unk_a683a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683a0, field_0, 0x0);

// 0x7100a683a0
void Unk_a683a0_set(const Unk_a683a0* self, Unk_a683a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a683b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683b0_arg1, field_0, 0x0);

struct Unk_a683b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683b0, field_0, 0x0);

// 0x7100a683b0
void Unk_a683b0_set(const Unk_a683b0* self, Unk_a683b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a683c0_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a683c0_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a683c0_0, field_448, 0x448);

struct Unk_a683c0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a683c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a683c0_arg1, field_8, 0x8);

struct Unk_a683c0 {
    Unk_a683c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683c0, field_0, 0x0);

// 0x7100a683c0
void Unk_a683c0_set(const Unk_a683c0* self, const Unk_a683c0_arg1* value) {
    Unk_a683c0_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a683e0
void Unk_a683e0_update() {}

struct Unk_a683f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683f0_arg1, field_0, 0x0);

struct Unk_a683f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a683f0, field_0, 0x0);

// 0x7100a683f0
void Unk_a683f0_set(const Unk_a683f0* self, Unk_a683f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68400_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68400_arg1, field_0, 0x0);

struct Unk_a68400 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68400, field_0, 0x0);

// 0x7100a68400
void Unk_a68400_set(const Unk_a68400* self, Unk_a68400_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68410_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a68410_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a68410_0, field_448, 0x448);

struct Unk_a68410_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68410_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68410_arg1, field_8, 0x8);

struct Unk_a68410 {
    Unk_a68410_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68410, field_0, 0x0);

// 0x7100a68410
void Unk_a68410_set(const Unk_a68410* self, const Unk_a68410_arg1* value) {
    Unk_a68410_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a68430
void Unk_a68430_update() {}

struct Unk_a68440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68440_arg1, field_0, 0x0);

struct Unk_a68440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68440, field_0, 0x0);

// 0x7100a68440
void Unk_a68440_set(const Unk_a68440* self, Unk_a68440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68450_arg1, field_0, 0x0);

struct Unk_a68450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68450, field_0, 0x0);

// 0x7100a68450
void Unk_a68450_set(const Unk_a68450* self, Unk_a68450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68460_0 {
    u8 _0[0x450];
    u64 field_450;
    u64 field_458;
};
PKMN_OFFSET_ASSERT(Unk_a68460_0, field_450, 0x450);
PKMN_OFFSET_ASSERT(Unk_a68460_0, field_458, 0x458);

struct Unk_a68460_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68460_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68460_arg1, field_8, 0x8);

struct Unk_a68460 {
    Unk_a68460_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68460, field_0, 0x0);

// 0x7100a68460
void Unk_a68460_set(const Unk_a68460* self, const Unk_a68460_arg1* value) {
    Unk_a68460_0* p0 = self->field_0;
    p0->field_458 = value->field_8;
    p0->field_450 = value->field_0;
}

// 0x7100a68480
void Unk_a68480_update() {}

struct Unk_a68490_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68490_arg1, field_0, 0x0);

struct Unk_a68490 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68490, field_0, 0x0);

// 0x7100a68490
void Unk_a68490_set(const Unk_a68490* self, Unk_a68490_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a684a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684a0_arg1, field_0, 0x0);

struct Unk_a684a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684a0, field_0, 0x0);

// 0x7100a684a0
void Unk_a684a0_set(const Unk_a684a0* self, Unk_a684a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a684b0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a684b0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a684b0_0, field_3f8, 0x3f8);

struct Unk_a684b0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a684b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a684b0_arg1, field_8, 0x8);

struct Unk_a684b0 {
    Unk_a684b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684b0, field_0, 0x0);

// 0x7100a684b0
void Unk_a684b0_set(const Unk_a684b0* self, const Unk_a684b0_arg1* value) {
    Unk_a684b0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a684d0
void Unk_a684d0_update() {}

struct Unk_a684e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684e0_arg1, field_0, 0x0);

struct Unk_a684e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684e0, field_0, 0x0);

// 0x7100a684e0
void Unk_a684e0_set(const Unk_a684e0* self, Unk_a684e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a684f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684f0_arg1, field_0, 0x0);

struct Unk_a684f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a684f0, field_0, 0x0);

// 0x7100a684f0
void Unk_a684f0_set(const Unk_a684f0* self, Unk_a684f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68500_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a68500_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a68500_0, field_3c8, 0x3c8);

struct Unk_a68500_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68500_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68500_arg1, field_8, 0x8);

struct Unk_a68500 {
    Unk_a68500_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68500, field_0, 0x0);

// 0x7100a68500
void Unk_a68500_set(const Unk_a68500* self, const Unk_a68500_arg1* value) {
    Unk_a68500_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a68520
void Unk_a68520_update() {}

struct Unk_a68530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68530_arg1, field_0, 0x0);

struct Unk_a68530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68530, field_0, 0x0);

// 0x7100a68530
void Unk_a68530_set(const Unk_a68530* self, Unk_a68530_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68540_arg1, field_0, 0x0);

struct Unk_a68540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68540, field_0, 0x0);

// 0x7100a68540
void Unk_a68540_set(const Unk_a68540* self, Unk_a68540_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68550_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a68550_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a68550_0, field_448, 0x448);

struct Unk_a68550_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68550_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68550_arg1, field_8, 0x8);

struct Unk_a68550 {
    Unk_a68550_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68550, field_0, 0x0);

// 0x7100a68550
void Unk_a68550_set(const Unk_a68550* self, const Unk_a68550_arg1* value) {
    Unk_a68550_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a68570
void Unk_a68570_update() {}

struct Unk_a68580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68580_arg1, field_0, 0x0);

struct Unk_a68580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68580, field_0, 0x0);

// 0x7100a68580
void Unk_a68580_set(const Unk_a68580* self, Unk_a68580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68590_arg1, field_0, 0x0);

struct Unk_a68590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68590, field_0, 0x0);

// 0x7100a68590
void Unk_a68590_set(const Unk_a68590* self, Unk_a68590_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a685a0 {
    u64 field_0;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_a685a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a685a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a685a0, field_c, 0xc);

void Unk_9891e0(u64, u32, u32, u64);

// 0x7100a685a0
void Unk_a685a0_call(const Unk_a685a0* self, u64 value) {
    Unk_9891e0(self->field_0, self->field_c, self->field_8, value);
}

// 0x7100a685c0
void Unk_a685c0_update() {}

struct Unk_a685d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a685d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a685d0, field_8, 0x8);

// 0x7100a685d0
void Unk_a685d0_set(const Unk_a685d0* self, Unk_a685d0* value) {
    *value = *self;
}

struct Unk_a685e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a685e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a685e0, field_8, 0x8);

// 0x7100a685e0
void Unk_a685e0_set(const Unk_a685e0* self, Unk_a685e0* value) {
    *value = *self;
}

// 0x7100a68610
void Unk_a68610_update() {}

struct Unk_a68620 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68620, field_8, 0x8);

// 0x7100a68620
void Unk_a68620_set(const Unk_a68620* self, Unk_a68620* value) {
    *value = *self;
}

struct Unk_a68630 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68630, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68630, field_8, 0x8);

// 0x7100a68630
void Unk_a68630_set(const Unk_a68630* self, Unk_a68630* value) {
    *value = *self;
}

struct Unk_a68640_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a68640_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a68640_0, field_3d8, 0x3d8);

struct Unk_a68640_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68640_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68640_arg1, field_8, 0x8);

struct Unk_a68640 {
    Unk_a68640_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68640, field_0, 0x0);

// 0x7100a68640
void Unk_a68640_set(const Unk_a68640* self, const Unk_a68640_arg1* value) {
    Unk_a68640_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a68660
void Unk_a68660_update() {}

struct Unk_a68670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68670_arg1, field_0, 0x0);

struct Unk_a68670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68670, field_0, 0x0);

// 0x7100a68670
void Unk_a68670_set(const Unk_a68670* self, Unk_a68670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68680_arg1, field_0, 0x0);

struct Unk_a68680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68680, field_0, 0x0);

// 0x7100a68680
void Unk_a68680_set(const Unk_a68680* self, Unk_a68680_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68690_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a68690_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a68690_0, field_3d8, 0x3d8);

struct Unk_a68690_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a68690_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a68690_arg1, field_8, 0x8);

struct Unk_a68690 {
    Unk_a68690_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68690, field_0, 0x0);

// 0x7100a68690
void Unk_a68690_set(const Unk_a68690* self, const Unk_a68690_arg1* value) {
    Unk_a68690_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a686b0
void Unk_a686b0_update() {}

struct Unk_a686c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a686c0_arg1, field_0, 0x0);

struct Unk_a686c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a686c0, field_0, 0x0);

// 0x7100a686c0
void Unk_a686c0_set(const Unk_a686c0* self, Unk_a686c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a686d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a686d0_arg1, field_0, 0x0);

struct Unk_a686d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a686d0, field_0, 0x0);

// 0x7100a686d0
void Unk_a686d0_set(const Unk_a686d0* self, Unk_a686d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a686f0
void Unk_a686f0_update() {}

struct Unk_a68700_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68700_arg1, field_0, 0x0);

struct Unk_a68700 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68700, field_0, 0x0);

// 0x7100a68700
void Unk_a68700_set(const Unk_a68700* self, Unk_a68700_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68710_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68710_arg1, field_0, 0x0);

struct Unk_a68710 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68710, field_0, 0x0);

// 0x7100a68710
void Unk_a68710_set(const Unk_a68710* self, Unk_a68710_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a68730
void Unk_a68730_update() {}

struct Unk_a68740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68740_arg1, field_0, 0x0);

struct Unk_a68740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68740, field_0, 0x0);

// 0x7100a68740
void Unk_a68740_set(const Unk_a68740* self, Unk_a68740_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a68750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68750_arg1, field_0, 0x0);

struct Unk_a68750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68750, field_0, 0x0);

// 0x7100a68750
void Unk_a68750_set(const Unk_a68750* self, Unk_a68750_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a68780
void Unk_a68780_update() {}

struct Unk_a68790_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68790_arg1, field_0, 0x0);

struct Unk_a68790 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a68790, field_0, 0x0);

// 0x7100a68790
void Unk_a68790_set(const Unk_a68790* self, Unk_a68790_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a687a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a687a0_arg1, field_0, 0x0);

struct Unk_a687a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a687a0, field_0, 0x0);

// 0x7100a687a0
void Unk_a687a0_set(const Unk_a687a0* self, Unk_a687a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a69270_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a69270_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a69270_0, field_3c8, 0x3c8);

struct Unk_a69270_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69270_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69270_arg1, field_8, 0x8);

struct Unk_a69270 {
    Unk_a69270_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69270, field_0, 0x0);

// 0x7100a69270
void Unk_a69270_set(const Unk_a69270* self, const Unk_a69270_arg1* value) {
    Unk_a69270_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a69290
void Unk_a69290_update() {}

struct Unk_a692a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692a0_arg1, field_0, 0x0);

struct Unk_a692a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692a0, field_0, 0x0);

// 0x7100a692a0
void Unk_a692a0_set(const Unk_a692a0* self, Unk_a692a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a692b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692b0_arg1, field_0, 0x0);

struct Unk_a692b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692b0, field_0, 0x0);

// 0x7100a692b0
void Unk_a692b0_set(const Unk_a692b0* self, Unk_a692b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a692c0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a692c0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a692c0_0, field_3c8, 0x3c8);

struct Unk_a692c0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a692c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a692c0_arg1, field_8, 0x8);

struct Unk_a692c0 {
    Unk_a692c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692c0, field_0, 0x0);

// 0x7100a692c0
void Unk_a692c0_set(const Unk_a692c0* self, const Unk_a692c0_arg1* value) {
    Unk_a692c0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a692e0
void Unk_a692e0_update() {}

struct Unk_a692f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692f0_arg1, field_0, 0x0);

struct Unk_a692f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a692f0, field_0, 0x0);

// 0x7100a692f0
void Unk_a692f0_set(const Unk_a692f0* self, Unk_a692f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a69300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69300_arg1, field_0, 0x0);

struct Unk_a69300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69300, field_0, 0x0);

// 0x7100a69300
void Unk_a69300_set(const Unk_a69300* self, Unk_a69300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a69310_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_a69310_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_a69310_0, field_3d8, 0x3d8);

struct Unk_a69310_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69310_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69310_arg1, field_8, 0x8);

struct Unk_a69310 {
    Unk_a69310_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69310, field_0, 0x0);

// 0x7100a69310
void Unk_a69310_set(const Unk_a69310* self, const Unk_a69310_arg1* value) {
    Unk_a69310_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

// 0x7100a69330
void Unk_a69330_update() {}

struct Unk_a69340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69340_arg1, field_0, 0x0);

struct Unk_a69340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69340, field_0, 0x0);

// 0x7100a69340
void Unk_a69340_set(const Unk_a69340* self, Unk_a69340_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a69350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69350_arg1, field_0, 0x0);

struct Unk_a69350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69350, field_0, 0x0);

// 0x7100a69350
void Unk_a69350_set(const Unk_a69350* self, Unk_a69350_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a69430_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69430_arg1, field_0, 0x0);

struct Unk_a69430 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69430, field_0, 0x0);

// 0x7100a69430
void Unk_a69430_call(const Unk_a69430* self, Unk_a69430_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a69450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69450_arg1, field_0, 0x0);

struct Unk_a69450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a69450, field_0, 0x0);

// 0x7100a69450
void Unk_a69450_set(Unk_a69450* self, Unk_a69450_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_a69580 {
    u64 field_0;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_a69580, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69580, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a69580, field_c, 0xc);

void Unk_9891e0(u64, u32, u32, u64);

// 0x7100a69580
void Unk_a69580_call(const Unk_a69580* self, u64 value) {
    Unk_9891e0(self->field_0, self->field_c, self->field_8, value);
}

// 0x7100a695a0
void Unk_a695a0_update() {}

struct Unk_a695b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a695b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a695b0, field_8, 0x8);

// 0x7100a695b0
void Unk_a695b0_set(const Unk_a695b0* self, Unk_a695b0* value) {
    *value = *self;
}

struct Unk_a695c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a695c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a695c0, field_8, 0x8);

// 0x7100a695c0
void Unk_a695c0_set(const Unk_a695c0* self, Unk_a695c0* value) {
    *value = *self;
}

// 0x7100a695f0
void Unk_a695f0_update() {}

struct Unk_a69600 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69600, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69600, field_8, 0x8);

// 0x7100a69600
void Unk_a69600_set(const Unk_a69600* self, Unk_a69600* value) {
    *value = *self;
}

struct Unk_a69610 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69610, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69610, field_8, 0x8);

// 0x7100a69610
void Unk_a69610_set(const Unk_a69610* self, Unk_a69610* value) {
    *value = *self;
}

struct Unk_a69950_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69950_arg1, field_8, 0x8);

struct Unk_a69950 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69950, field_8, 0x8);

// 0x7100a69950
void Unk_a69950_call(const Unk_a69950* self, Unk_a69950_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a69980_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69980_arg1, field_8, 0x8);

struct Unk_a69980 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69980, field_8, 0x8);

// 0x7100a69980
void Unk_a69980_set(Unk_a69980* self, Unk_a69980_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a69bc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69bc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69bc0_arg1, field_8, 0x8);

struct Unk_a69bc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69bc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69bc0, field_8, 0x8);

// 0x7100a69bc0
void Unk_a69bc0_call(const Unk_a69bc0* self, Unk_a69bc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a69bf0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69bf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69bf0_arg1, field_8, 0x8);

struct Unk_a69bf0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69bf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69bf0, field_8, 0x8);

// 0x7100a69bf0
void Unk_a69bf0_set(Unk_a69bf0* self, Unk_a69bf0_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a69e40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69e40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69e40_arg1, field_8, 0x8);

struct Unk_a69e40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69e40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69e40, field_8, 0x8);

// 0x7100a69e40
void Unk_a69e40_call(const Unk_a69e40* self, Unk_a69e40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a69e70_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69e70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69e70_arg1, field_8, 0x8);

struct Unk_a69e70 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a69e70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a69e70, field_8, 0x8);

// 0x7100a69e70
void Unk_a69e70_set(Unk_a69e70* self, Unk_a69e70_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

void Unk_ee3c60(u64);

// 0x7100a69ff0
void Unk_a69ff0_call(void* /*unused*/, u64 value) {
    Unk_ee3c60(value);
}

// 0x7100a6a000
void Unk_a6a000_update() {}

// 0x7100a6a010
void Unk_a6a010_update() {}

// 0x7100a6a020
void Unk_a6a020_update() {}

void Unk_ee3c20(u64);

// 0x7100a6a170
void Unk_a6a170_call(void* /*unused*/, u64 value) {
    Unk_ee3c20(value);
}

// 0x7100a6a180
void Unk_a6a180_update() {}

// 0x7100a6a190
void Unk_a6a190_update() {}

// 0x7100a6a1a0
void Unk_a6a1a0_update() {}

// 0x7100a6a2a0
void Unk_a6a2a0_update() {}

struct Unk_a6a2b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6a2b0_arg1, field_0, 0x0);

struct Unk_a6a2b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6a2b0, field_0, 0x0);

// 0x7100a6a2b0
void Unk_a6a2b0_set(const Unk_a6a2b0* self, Unk_a6a2b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6a2c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6a2c0_arg1, field_0, 0x0);

struct Unk_a6a2c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6a2c0, field_0, 0x0);

// 0x7100a6a2c0
void Unk_a6a2c0_set(const Unk_a6a2c0* self, Unk_a6a2c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6a370_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a370_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a370_arg1, field_8, 0x8);

struct Unk_a6a370 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a370, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a370, field_8, 0x8);

// 0x7100a6a370
void Unk_a6a370_call(const Unk_a6a370* self, Unk_a6a370_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6a3a0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a3a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a3a0_arg1, field_8, 0x8);

struct Unk_a6a3a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a3a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a3a0, field_8, 0x8);

// 0x7100a6a3a0
void Unk_a6a3a0_set(Unk_a6a3a0* self, Unk_a6a3a0_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6a5f0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a5f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a5f0_arg1, field_8, 0x8);

struct Unk_a6a5f0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a5f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a5f0, field_8, 0x8);

// 0x7100a6a5f0
void Unk_a6a5f0_call(const Unk_a6a5f0* self, Unk_a6a5f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6a620_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a620_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a620_arg1, field_8, 0x8);

struct Unk_a6a620 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a620, field_8, 0x8);

// 0x7100a6a620
void Unk_a6a620_set(Unk_a6a620* self, Unk_a6a620_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6a830_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a830_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a830_arg1, field_8, 0x8);

struct Unk_a6a830 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a830, field_8, 0x8);

// 0x7100a6a830
void Unk_a6a830_call(const Unk_a6a830* self, Unk_a6a830_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6a860_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a860_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a860_arg1, field_8, 0x8);

struct Unk_a6a860 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6a860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6a860, field_8, 0x8);

// 0x7100a6a860
void Unk_a6a860_set(Unk_a6a860* self, Unk_a6a860_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6aba0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6aba0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6aba0_arg1, field_8, 0x8);

struct Unk_a6aba0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6aba0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6aba0, field_8, 0x8);

// 0x7100a6aba0
void Unk_a6aba0_call(const Unk_a6aba0* self, Unk_a6aba0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6abd0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6abd0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6abd0_arg1, field_8, 0x8);

struct Unk_a6abd0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6abd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6abd0, field_8, 0x8);

// 0x7100a6abd0
void Unk_a6abd0_set(Unk_a6abd0* self, Unk_a6abd0_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

// 0x7100a6aca0
void Unk_a6aca0_update() {}

struct Unk_a6acb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_a6acb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6acb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a6acb0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_a6acb0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_a6acb0, field_20, 0x20);

// 0x7100a6acb0
void Unk_a6acb0_set(const Unk_a6acb0* self, Unk_a6acb0* value) {
    *value = *self;
}

struct Unk_a6acd0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_a6acd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6acd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a6acd0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_a6acd0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_a6acd0, field_20, 0x20);

// 0x7100a6acd0
void Unk_a6acd0_set(const Unk_a6acd0* self, Unk_a6acd0* value) {
    *value = *self;
}

// 0x7100a6aee0
void Unk_a6aee0_update() {}

struct Unk_a6aef0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_a6aef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6aef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a6aef0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_a6aef0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_a6aef0, field_20, 0x20);

// 0x7100a6aef0
void Unk_a6aef0_set(const Unk_a6aef0* self, Unk_a6aef0* value) {
    *value = *self;
}

struct Unk_a6af10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_a6af10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6af10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a6af10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_a6af10, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_a6af10, field_20, 0x20);

// 0x7100a6af10
void Unk_a6af10_set(const Unk_a6af10* self, Unk_a6af10* value) {
    *value = *self;
}

// 0x7100a6b100
void Unk_a6b100_update() {}

struct Unk_a6b110 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_a6b110, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b110, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a6b110, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_a6b110, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_a6b110, field_20, 0x20);

// 0x7100a6b110
void Unk_a6b110_set(const Unk_a6b110* self, Unk_a6b110* value) {
    *value = *self;
}

struct Unk_a6b130 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_a6b130, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b130, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a6b130, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_a6b130, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_a6b130, field_20, 0x20);

// 0x7100a6b130
void Unk_a6b130_set(const Unk_a6b130* self, Unk_a6b130* value) {
    *value = *self;
}

struct Unk_a6b220_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b220_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b220_arg1, field_8, 0x8);

struct Unk_a6b220 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b220, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b220, field_8, 0x8);

// 0x7100a6b220
void Unk_a6b220_call(const Unk_a6b220* self, Unk_a6b220_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6b250_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b250_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b250_arg1, field_8, 0x8);

struct Unk_a6b250 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b250, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b250, field_8, 0x8);

// 0x7100a6b250
void Unk_a6b250_set(Unk_a6b250* self, Unk_a6b250_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6b4d0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b4d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b4d0_arg1, field_8, 0x8);

struct Unk_a6b4d0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b4d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b4d0, field_8, 0x8);

// 0x7100a6b4d0
void Unk_a6b4d0_call(const Unk_a6b4d0* self, Unk_a6b4d0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6b500_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b500_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b500_arg1, field_8, 0x8);

struct Unk_a6b500 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b500, field_8, 0x8);

// 0x7100a6b500
void Unk_a6b500_set(Unk_a6b500* self, Unk_a6b500_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6b760_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b760_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b760_arg1, field_8, 0x8);

struct Unk_a6b760 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b760, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b760, field_8, 0x8);

// 0x7100a6b760
void Unk_a6b760_call(const Unk_a6b760* self, Unk_a6b760_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6b790_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b790_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b790_arg1, field_8, 0x8);

struct Unk_a6b790 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b790, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b790, field_8, 0x8);

// 0x7100a6b790
void Unk_a6b790_set(Unk_a6b790* self, Unk_a6b790_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

// 0x7100a6b950
void Unk_a6b950_update() {}

struct Unk_a6b960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6b960_arg1, field_0, 0x0);

struct Unk_a6b960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6b960, field_0, 0x0);

// 0x7100a6b960
void Unk_a6b960_set(const Unk_a6b960* self, Unk_a6b960_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6b970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6b970_arg1, field_0, 0x0);

struct Unk_a6b970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6b970, field_0, 0x0);

// 0x7100a6b970
void Unk_a6b970_set(const Unk_a6b970* self, Unk_a6b970_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6b980 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b980, field_8, 0x8);

void Unk_965af0(u64, u32);
void Unk_ed2ed0(u64, u32);

// 0x7100a6b980
void Unk_a6b980_call(const Unk_a6b980* self) {
    Unk_ed2ed0(self->field_8, 1);
    Unk_965af0(self->field_0, 1);
}

struct Unk_a6b9f0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b9f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b9f0_arg1, field_8, 0x8);

struct Unk_a6b9f0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6b9f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6b9f0, field_8, 0x8);

// 0x7100a6b9f0
void Unk_a6b9f0_call(const Unk_a6b9f0* self, Unk_a6b9f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6ba20_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6ba20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6ba20_arg1, field_8, 0x8);

struct Unk_a6ba20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6ba20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6ba20, field_8, 0x8);

// 0x7100a6ba20
void Unk_a6ba20_set(Unk_a6ba20* self, Unk_a6ba20_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6bac0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6bac0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6bac0_arg1, field_8, 0x8);

struct Unk_a6bac0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6bac0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6bac0, field_8, 0x8);

// 0x7100a6bac0
void Unk_a6bac0_call(const Unk_a6bac0* self, Unk_a6bac0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6baf0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6baf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6baf0_arg1, field_8, 0x8);

struct Unk_a6baf0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6baf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6baf0, field_8, 0x8);

// 0x7100a6baf0
void Unk_a6baf0_set(Unk_a6baf0* self, Unk_a6baf0_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

struct Unk_a6bb10_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a6bb10_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a6bb10_0, field_3c8, 0x3c8);

struct Unk_a6bb10_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6bb10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6bb10_arg1, field_8, 0x8);

struct Unk_a6bb10 {
    Unk_a6bb10_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb10, field_0, 0x0);

// 0x7100a6bb10
void Unk_a6bb10_set(const Unk_a6bb10* self, const Unk_a6bb10_arg1* value) {
    Unk_a6bb10_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a6bb30
void Unk_a6bb30_update() {}

struct Unk_a6bb40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb40_arg1, field_0, 0x0);

struct Unk_a6bb40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb40, field_0, 0x0);

// 0x7100a6bb40
void Unk_a6bb40_set(const Unk_a6bb40* self, Unk_a6bb40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bb50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb50_arg1, field_0, 0x0);

struct Unk_a6bb50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb50, field_0, 0x0);

// 0x7100a6bb50
void Unk_a6bb50_set(const Unk_a6bb50* self, Unk_a6bb50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bb60_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a6bb60_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a6bb60_0, field_3c8, 0x3c8);

struct Unk_a6bb60_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6bb60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6bb60_arg1, field_8, 0x8);

struct Unk_a6bb60 {
    Unk_a6bb60_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb60, field_0, 0x0);

// 0x7100a6bb60
void Unk_a6bb60_set(const Unk_a6bb60* self, const Unk_a6bb60_arg1* value) {
    Unk_a6bb60_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a6bb80
void Unk_a6bb80_update() {}

struct Unk_a6bb90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb90_arg1, field_0, 0x0);

struct Unk_a6bb90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bb90, field_0, 0x0);

// 0x7100a6bb90
void Unk_a6bb90_set(const Unk_a6bb90* self, Unk_a6bb90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bba0_arg1, field_0, 0x0);

struct Unk_a6bba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bba0, field_0, 0x0);

// 0x7100a6bba0
void Unk_a6bba0_set(const Unk_a6bba0* self, Unk_a6bba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bbb0_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a6bbb0_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a6bbb0_0, field_448, 0x448);

struct Unk_a6bbb0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6bbb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6bbb0_arg1, field_8, 0x8);

struct Unk_a6bbb0 {
    Unk_a6bbb0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bbb0, field_0, 0x0);

// 0x7100a6bbb0
void Unk_a6bbb0_set(const Unk_a6bbb0* self, const Unk_a6bbb0_arg1* value) {
    Unk_a6bbb0_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a6bbd0
void Unk_a6bbd0_update() {}

struct Unk_a6bbe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bbe0_arg1, field_0, 0x0);

struct Unk_a6bbe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bbe0, field_0, 0x0);

// 0x7100a6bbe0
void Unk_a6bbe0_set(const Unk_a6bbe0* self, Unk_a6bbe0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bbf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bbf0_arg1, field_0, 0x0);

struct Unk_a6bbf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bbf0, field_0, 0x0);

// 0x7100a6bbf0
void Unk_a6bbf0_set(const Unk_a6bbf0* self, Unk_a6bbf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bc00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc00, field_0, 0x0);

void Unk_97fdd0(u64, u32);

// 0x7100a6bc00
void Unk_a6bc00_call(const Unk_a6bc00* self) {
    Unk_97fdd0(self->field_0, 1);
}

// 0x7100a6bc10
void Unk_a6bc10_update() {}

struct Unk_a6bc20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc20_arg1, field_0, 0x0);

struct Unk_a6bc20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc20, field_0, 0x0);

// 0x7100a6bc20
void Unk_a6bc20_set(const Unk_a6bc20* self, Unk_a6bc20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bc30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc30_arg1, field_0, 0x0);

struct Unk_a6bc30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc30, field_0, 0x0);

// 0x7100a6bc30
void Unk_a6bc30_set(const Unk_a6bc30* self, Unk_a6bc30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a6bc60
void Unk_a6bc60_update() {}

struct Unk_a6bc70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc70_arg1, field_0, 0x0);

struct Unk_a6bc70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc70, field_0, 0x0);

// 0x7100a6bc70
void Unk_a6bc70_set(const Unk_a6bc70* self, Unk_a6bc70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bc80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc80_arg1, field_0, 0x0);

struct Unk_a6bc80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bc80, field_0, 0x0);

// 0x7100a6bc80
void Unk_a6bc80_set(const Unk_a6bc80* self, Unk_a6bc80_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a6bca0
void Unk_a6bca0_update() {}

struct Unk_a6bcb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bcb0_arg1, field_0, 0x0);

struct Unk_a6bcb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bcb0, field_0, 0x0);

// 0x7100a6bcb0
void Unk_a6bcb0_set(const Unk_a6bcb0* self, Unk_a6bcb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bcc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bcc0_arg1, field_0, 0x0);

struct Unk_a6bcc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bcc0, field_0, 0x0);

// 0x7100a6bcc0
void Unk_a6bcc0_set(const Unk_a6bcc0* self, Unk_a6bcc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a6bcf0
void Unk_a6bcf0_update() {}

struct Unk_a6bd00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bd00_arg1, field_0, 0x0);

struct Unk_a6bd00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bd00, field_0, 0x0);

// 0x7100a6bd00
void Unk_a6bd00_set(const Unk_a6bd00* self, Unk_a6bd00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bd10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bd10_arg1, field_0, 0x0);

struct Unk_a6bd10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bd10, field_0, 0x0);

// 0x7100a6bd10
void Unk_a6bd10_set(const Unk_a6bd10* self, Unk_a6bd10_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a6bf80
void Unk_a6bf80_update() {}

struct Unk_a6bf90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bf90_arg1, field_0, 0x0);

struct Unk_a6bf90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bf90, field_0, 0x0);

// 0x7100a6bf90
void Unk_a6bf90_set(const Unk_a6bf90* self, Unk_a6bf90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6bfa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bfa0_arg1, field_0, 0x0);

struct Unk_a6bfa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6bfa0, field_0, 0x0);

// 0x7100a6bfa0
void Unk_a6bfa0_set(const Unk_a6bfa0* self, Unk_a6bfa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c030_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c030_arg1, field_0, 0x0);

struct Unk_a6c030 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c030, field_0, 0x0);

// 0x7100a6c030
void Unk_a6c030_call(const Unk_a6c030* self, Unk_a6c030_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6c050_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c050_arg1, field_0, 0x0);

struct Unk_a6c050 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c050, field_0, 0x0);

// 0x7100a6c050
void Unk_a6c050_set(Unk_a6c050* self, Unk_a6c050_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_a6c0e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c0e0_arg1, field_0, 0x0);

struct Unk_a6c0e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c0e0, field_0, 0x0);

// 0x7100a6c0e0
void Unk_a6c0e0_call(const Unk_a6c0e0* self, Unk_a6c0e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6c100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c100_arg1, field_0, 0x0);

struct Unk_a6c100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c100, field_0, 0x0);

// 0x7100a6c100
void Unk_a6c100_set(Unk_a6c100* self, Unk_a6c100_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

// 0x7100a6c160
void Unk_a6c160_update() {}

struct Unk_a6c170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c170_arg1, field_0, 0x0);

struct Unk_a6c170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c170, field_0, 0x0);

// 0x7100a6c170
void Unk_a6c170_set(const Unk_a6c170* self, Unk_a6c170_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c180_arg1, field_0, 0x0);

struct Unk_a6c180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c180, field_0, 0x0);

// 0x7100a6c180
void Unk_a6c180_set(const Unk_a6c180* self, Unk_a6c180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c190, field_0, 0x0);

void Unk_954450(u64);

// 0x7100a6c190
void Unk_a6c190_call(const Unk_a6c190* self) {
    Unk_954450(self->field_0);
}

// 0x7100a6c1a0
void Unk_a6c1a0_update() {}

struct Unk_a6c1b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1b0_arg1, field_0, 0x0);

struct Unk_a6c1b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1b0, field_0, 0x0);

// 0x7100a6c1b0
void Unk_a6c1b0_set(const Unk_a6c1b0* self, Unk_a6c1b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c1c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1c0_arg1, field_0, 0x0);

struct Unk_a6c1c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1c0, field_0, 0x0);

// 0x7100a6c1c0
void Unk_a6c1c0_set(const Unk_a6c1c0* self, Unk_a6c1c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c1d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1d0, field_0, 0x0);

void Unk_954570(u64);

// 0x7100a6c1d0
void Unk_a6c1d0_call(const Unk_a6c1d0* self) {
    Unk_954570(self->field_0);
}

// 0x7100a6c1e0
void Unk_a6c1e0_update() {}

struct Unk_a6c1f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1f0_arg1, field_0, 0x0);

struct Unk_a6c1f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c1f0, field_0, 0x0);

// 0x7100a6c1f0
void Unk_a6c1f0_set(const Unk_a6c1f0* self, Unk_a6c1f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c200_arg1, field_0, 0x0);

struct Unk_a6c200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c200, field_0, 0x0);

// 0x7100a6c200
void Unk_a6c200_set(const Unk_a6c200* self, Unk_a6c200_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c210 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c210, field_0, 0x0);

void Unk_98c900(u64);

// 0x7100a6c210
void Unk_a6c210_call(const Unk_a6c210* self) {
    Unk_98c900(self->field_0);
}

struct Unk_a6c260_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c260_arg1, field_0, 0x0);

struct Unk_a6c260 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c260, field_0, 0x0);

// 0x7100a6c260
void Unk_a6c260_call(const Unk_a6c260* self, Unk_a6c260_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_a6c280_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c280_arg1, field_0, 0x0);

struct Unk_a6c280 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c280, field_0, 0x0);

// 0x7100a6c280
void Unk_a6c280_set(Unk_a6c280* self, Unk_a6c280_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_a6c290_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a6c290_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a6c290_0, field_3c8, 0x3c8);

struct Unk_a6c290_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6c290_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6c290_arg1, field_8, 0x8);

struct Unk_a6c290 {
    Unk_a6c290_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c290, field_0, 0x0);

// 0x7100a6c290
void Unk_a6c290_set(const Unk_a6c290* self, const Unk_a6c290_arg1* value) {
    Unk_a6c290_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a6c2b0
void Unk_a6c2b0_update() {}

struct Unk_a6c2c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c2c0_arg1, field_0, 0x0);

struct Unk_a6c2c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c2c0, field_0, 0x0);

// 0x7100a6c2c0
void Unk_a6c2c0_set(const Unk_a6c2c0* self, Unk_a6c2c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c2d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c2d0_arg1, field_0, 0x0);

struct Unk_a6c2d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c2d0, field_0, 0x0);

// 0x7100a6c2d0
void Unk_a6c2d0_set(const Unk_a6c2d0* self, Unk_a6c2d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c2e0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_a6c2e0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_a6c2e0_0, field_3f8, 0x3f8);

struct Unk_a6c2e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6c2e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6c2e0_arg1, field_8, 0x8);

struct Unk_a6c2e0 {
    Unk_a6c2e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c2e0, field_0, 0x0);

// 0x7100a6c2e0
void Unk_a6c2e0_set(const Unk_a6c2e0* self, const Unk_a6c2e0_arg1* value) {
    Unk_a6c2e0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x7100a6c300
void Unk_a6c300_update() {}

struct Unk_a6c310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c310_arg1, field_0, 0x0);

struct Unk_a6c310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c310, field_0, 0x0);

// 0x7100a6c310
void Unk_a6c310_set(const Unk_a6c310* self, Unk_a6c310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c320_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c320_arg1, field_0, 0x0);

struct Unk_a6c320 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c320, field_0, 0x0);

// 0x7100a6c320
void Unk_a6c320_set(const Unk_a6c320* self, Unk_a6c320_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c330_0 {
    u8 _0[0x420];
    u64 field_420;
    u64 field_428;
};
PKMN_OFFSET_ASSERT(Unk_a6c330_0, field_420, 0x420);
PKMN_OFFSET_ASSERT(Unk_a6c330_0, field_428, 0x428);

struct Unk_a6c330_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6c330_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6c330_arg1, field_8, 0x8);

struct Unk_a6c330 {
    Unk_a6c330_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c330, field_0, 0x0);

// 0x7100a6c330
void Unk_a6c330_set(const Unk_a6c330* self, const Unk_a6c330_arg1* value) {
    Unk_a6c330_0* p0 = self->field_0;
    p0->field_428 = value->field_8;
    p0->field_420 = value->field_0;
}

// 0x7100a6c350
void Unk_a6c350_update() {}

struct Unk_a6c360_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c360_arg1, field_0, 0x0);

struct Unk_a6c360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c360, field_0, 0x0);

// 0x7100a6c360
void Unk_a6c360_set(const Unk_a6c360* self, Unk_a6c360_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c370_arg1, field_0, 0x0);

struct Unk_a6c370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c370, field_0, 0x0);

// 0x7100a6c370
void Unk_a6c370_set(const Unk_a6c370* self, Unk_a6c370_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c380_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_a6c380_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_a6c380_0, field_3c8, 0x3c8);

struct Unk_a6c380_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6c380_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6c380_arg1, field_8, 0x8);

struct Unk_a6c380 {
    Unk_a6c380_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c380, field_0, 0x0);

// 0x7100a6c380
void Unk_a6c380_set(const Unk_a6c380* self, const Unk_a6c380_arg1* value) {
    Unk_a6c380_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x7100a6c3a0
void Unk_a6c3a0_update() {}

struct Unk_a6c3b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c3b0_arg1, field_0, 0x0);

struct Unk_a6c3b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c3b0, field_0, 0x0);

// 0x7100a6c3b0
void Unk_a6c3b0_set(const Unk_a6c3b0* self, Unk_a6c3b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c3c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c3c0_arg1, field_0, 0x0);

struct Unk_a6c3c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c3c0, field_0, 0x0);

// 0x7100a6c3c0
void Unk_a6c3c0_set(const Unk_a6c3c0* self, Unk_a6c3c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c3d0_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_a6c3d0_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_a6c3d0_0, field_448, 0x448);

struct Unk_a6c3d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6c3d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6c3d0_arg1, field_8, 0x8);

struct Unk_a6c3d0 {
    Unk_a6c3d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c3d0, field_0, 0x0);

// 0x7100a6c3d0
void Unk_a6c3d0_set(const Unk_a6c3d0* self, const Unk_a6c3d0_arg1* value) {
    Unk_a6c3d0_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x7100a6c3f0
void Unk_a6c3f0_update() {}

struct Unk_a6c400_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c400_arg1, field_0, 0x0);

struct Unk_a6c400 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c400, field_0, 0x0);

// 0x7100a6c400
void Unk_a6c400_set(const Unk_a6c400* self, Unk_a6c400_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a6c410_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c410_arg1, field_0, 0x0);

struct Unk_a6c410 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a6c410, field_0, 0x0);

// 0x7100a6c410
void Unk_a6c410_set(const Unk_a6c410* self, Unk_a6c410_arg1* value) {
    value->field_0 = self->field_0;
}
