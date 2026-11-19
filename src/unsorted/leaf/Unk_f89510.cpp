// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100f89510
void Unk_f89510_update() {}

// 0x7100f89520
void Unk_f89520_update() {}

// 0x7100f89530
void Unk_f89530_update() {}

// 0x7100f89540
void Unk_f89540_update() {}

struct Unk_f89550_0 {
    u8 _0[0x1f8];
    u8 field_1f8;
    u8 _1f9[0x3];
    u32 field_1fc;
};
PKMN_OFFSET_ASSERT(Unk_f89550_0, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_f89550_0, field_1fc, 0x1fc);

struct Unk_f89550 {
    Unk_f89550_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f89550, field_0, 0x0);

// 0x7100f89550
void Unk_f89550_set(const Unk_f89550* self) {
    Unk_f89550_0* p0 = self->field_0;
    p0->field_1fc = 1;
    p0->field_1f8 = 1;
}

// 0x7100f89570
void Unk_f89570_update() {}

struct Unk_f89580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f89580_arg1, field_0, 0x0);

struct Unk_f89580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f89580, field_0, 0x0);

// 0x7100f89580
void Unk_f89580_set(const Unk_f89580* self, Unk_f89580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f89590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f89590_arg1, field_0, 0x0);

struct Unk_f89590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f89590, field_0, 0x0);

// 0x7100f89590
void Unk_f89590_set(const Unk_f89590* self, Unk_f89590_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f8b610
void Unk_f8b610_update() {}

// 0x7100f8b620
void Unk_f8b620_update() {}

// 0x7100f8b630
void Unk_f8b630_update() {}

// 0x7100f8b640
void Unk_f8b640_update() {}

struct Unk_f8b650_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(u32);
    u8 _8[0x78];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f8b650_0, field_80, 0x80);

struct Unk_f8b650 {
    Unk_f8b650_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b650, field_0, 0x0);

// 0x7100f8b650
void Unk_f8b650_call(const Unk_f8b650* self) {
    Unk_f8b650_0* v0 = self->field_0;
    v0->field_80 = 3;
    v0->vf17(3);
}

// 0x7100f8b670
void Unk_f8b670_update() {}

struct Unk_f8b680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b680_arg1, field_0, 0x0);

struct Unk_f8b680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b680, field_0, 0x0);

// 0x7100f8b680
void Unk_f8b680_set(const Unk_f8b680* self, Unk_f8b680_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8b690_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b690_arg1, field_0, 0x0);

struct Unk_f8b690 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b690, field_0, 0x0);

// 0x7100f8b690
void Unk_f8b690_set(const Unk_f8b690* self, Unk_f8b690_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8b6a0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(u32);
    u8 _8[0x78];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f8b6a0_0, field_80, 0x80);

struct Unk_f8b6a0 {
    Unk_f8b6a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b6a0, field_0, 0x0);

// 0x7100f8b6a0
void Unk_f8b6a0_call(const Unk_f8b6a0* self) {
    Unk_f8b6a0_0* v0 = self->field_0;
    v0->field_80 = 0;
    v0->vf17(0);
}

// 0x7100f8b6c0
void Unk_f8b6c0_update() {}

struct Unk_f8b6d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b6d0_arg1, field_0, 0x0);

struct Unk_f8b6d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b6d0, field_0, 0x0);

// 0x7100f8b6d0
void Unk_f8b6d0_set(const Unk_f8b6d0* self, Unk_f8b6d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8b6e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b6e0_arg1, field_0, 0x0);

struct Unk_f8b6e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b6e0, field_0, 0x0);

// 0x7100f8b6e0
void Unk_f8b6e0_set(const Unk_f8b6e0* self, Unk_f8b6e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f8b840
void Unk_f8b840_update() {}

// 0x7100f8b850
void Unk_f8b850_update() {}

// 0x7100f8b860
void Unk_f8b860_update() {}

// 0x7100f8b870
void Unk_f8b870_update() {}

// 0x7100f8b880
void Unk_f8b880_update() {}

struct Unk_f8b890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b890_arg1, field_0, 0x0);

struct Unk_f8b890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b890, field_0, 0x0);

// 0x7100f8b890
void Unk_f8b890_set(const Unk_f8b890* self, Unk_f8b890_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8b8a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b8a0_arg1, field_0, 0x0);

struct Unk_f8b8a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8b8a0, field_0, 0x0);

// 0x7100f8b8a0
void Unk_f8b8a0_set(const Unk_f8b8a0* self, Unk_f8b8a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8d7f0 {
    u8 _0[0x628];
    u64 field_628;
};
PKMN_OFFSET_ASSERT(Unk_f8d7f0, field_628, 0x628);

void Unk_14e1a30(u64, u32);

// 0x7100f8d7f0
void Unk_f8d7f0_call(const Unk_f8d7f0* self) {
    Unk_14e1a30(self->field_628, 1);
}

struct Unk_f8d800 {
    u8 _0[0x628];
    u64 field_628;
};
PKMN_OFFSET_ASSERT(Unk_f8d800, field_628, 0x628);

void Unk_14e1a30(u64, u32);

// 0x7100f8d800
void Unk_f8d800_call(const Unk_f8d800* self) {
    Unk_14e1a30(self->field_628, 0);
}

struct Unk_f8d810 {
    u8 _0[0x640];
    u32 field_640;
};
PKMN_OFFSET_ASSERT(Unk_f8d810, field_640, 0x640);

// 0x7100f8d810
bool Unk_f8d810_check(const Unk_f8d810* self) {
    return self->field_640 < 0x80;
}

// 0x7100f8db20
void Unk_f8db20_update() {}

struct Unk_f8db30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db30_arg1, field_0, 0x0);

struct Unk_f8db30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db30, field_0, 0x0);

// 0x7100f8db30
void Unk_f8db30_set(const Unk_f8db30* self, Unk_f8db30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8db40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db40_arg1, field_0, 0x0);

struct Unk_f8db40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db40, field_0, 0x0);

// 0x7100f8db40
void Unk_f8db40_set(const Unk_f8db40* self, Unk_f8db40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8db50_0 {
    u8 _0[0x640];
    u32 field_640;
};
PKMN_OFFSET_ASSERT(Unk_f8db50_0, field_640, 0x640);

struct Unk_f8db50_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db50_arg1, field_0, 0x0);

struct Unk_f8db50 {
    Unk_f8db50_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db50, field_0, 0x0);

// 0x7100f8db50
void Unk_f8db50_set(const Unk_f8db50* self, const Unk_f8db50_arg1* value) {
    self->field_0->field_640 = value->field_0;
}

// 0x7100f8db60
void Unk_f8db60_update() {}

struct Unk_f8db70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db70_arg1, field_0, 0x0);

struct Unk_f8db70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db70, field_0, 0x0);

// 0x7100f8db70
void Unk_f8db70_set(const Unk_f8db70* self, Unk_f8db70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8db80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db80_arg1, field_0, 0x0);

struct Unk_f8db80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db80, field_0, 0x0);

// 0x7100f8db80
void Unk_f8db80_set(const Unk_f8db80* self, Unk_f8db80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8db90_0 {
    u8 _0[0x644];
    u8 field_644;
};
PKMN_OFFSET_ASSERT(Unk_f8db90_0, field_644, 0x644);

struct Unk_f8db90 {
    Unk_f8db90_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8db90, field_0, 0x0);

// 0x7100f8db90
void Unk_f8db90_set(const Unk_f8db90* self) {
    self->field_0->field_644 = 1;
}

// 0x7100f8dba0
void Unk_f8dba0_update() {}

struct Unk_f8dbb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8dbb0_arg1, field_0, 0x0);

struct Unk_f8dbb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8dbb0, field_0, 0x0);

// 0x7100f8dbb0
void Unk_f8dbb0_set(const Unk_f8dbb0* self, Unk_f8dbb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8dbc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8dbc0_arg1, field_0, 0x0);

struct Unk_f8dbc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8dbc0, field_0, 0x0);

// 0x7100f8dbc0
void Unk_f8dbc0_set(const Unk_f8dbc0* self, Unk_f8dbc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8e9a0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8e9a0, field_8, 0x8);

// 0x7100f8e9a0
void Unk_f8e9a0_call(Unk_f8e9a0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f8e9e0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8e9e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8e9e0_arg1, field_8, 0x8);

struct Unk_f8e9e0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8e9e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8e9e0, field_8, 0x8);

// 0x7100f8e9e0
void Unk_f8e9e0_call(const Unk_f8e9e0* self, Unk_f8e9e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f8ea10_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8ea10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8ea10_arg1, field_8, 0x8);

struct Unk_f8ea10 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8ea10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8ea10, field_8, 0x8);

// 0x7100f8ea10
void Unk_f8ea10_call(const Unk_f8ea10* self, Unk_f8ea10_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f8ea90 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8ea90, field_8, 0x8);

// 0x7100f8ea90
void Unk_f8ea90_call(Unk_f8ea90* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f8ead0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8ead0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8ead0_arg1, field_8, 0x8);

struct Unk_f8ead0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8ead0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8ead0, field_8, 0x8);

// 0x7100f8ead0
void Unk_f8ead0_call(const Unk_f8ead0* self, Unk_f8ead0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f8eb00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8eb00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8eb00_arg1, field_8, 0x8);

struct Unk_f8eb00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f8eb00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f8eb00, field_8, 0x8);

// 0x7100f8eb00
void Unk_f8eb00_call(const Unk_f8eb00* self, Unk_f8eb00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100f8eb30
void Unk_f8eb30_update() {}

// 0x7100f8eb40
void Unk_f8eb40_update() {}

// 0x7100f8eb50
void Unk_f8eb50_update() {}

// 0x7100f8eb60
void Unk_f8eb60_update() {}

struct Unk_f8eb70_0 {
    u8 _0[0xa0];
    u8 field_a0;
    u8 _a1[0x157];
    u8 field_1f8;
    u8 _1f9[0x3];
    u32 field_1fc;
};
PKMN_OFFSET_ASSERT(Unk_f8eb70_0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_f8eb70_0, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_f8eb70_0, field_1fc, 0x1fc);

struct Unk_f8eb70 {
    Unk_f8eb70_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8eb70, field_0, 0x0);

void Unk_f6cd80(void*);

// 0x7100f8eb70
void Unk_f8eb70_call(const Unk_f8eb70* self) {
    Unk_f8eb70_0* p0 = self->field_0;
    Unk_f6cd80(&p0->field_a0);
    p0->field_1fc = 2;
    p0->field_1f8 = 1;
}

// 0x7100f8ebb0
void Unk_f8ebb0_update() {}

struct Unk_f8ebc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ebc0_arg1, field_0, 0x0);

struct Unk_f8ebc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ebc0, field_0, 0x0);

// 0x7100f8ebc0
void Unk_f8ebc0_set(const Unk_f8ebc0* self, Unk_f8ebc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8ebd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ebd0_arg1, field_0, 0x0);

struct Unk_f8ebd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ebd0, field_0, 0x0);

// 0x7100f8ebd0
void Unk_f8ebd0_set(const Unk_f8ebd0* self, Unk_f8ebd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8ebe0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ebe0, field_0, 0x0);

void Unk_f89de0(void*, u32);

// 0x7100f8ebe0
void Unk_f8ebe0_call(const Unk_f8ebe0* self) {
    Unk_f89de0(self->field_0, 1);
}

// 0x7100f8ebf0
void Unk_f8ebf0_update() {}

struct Unk_f8ec00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ec00_arg1, field_0, 0x0);

struct Unk_f8ec00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ec00, field_0, 0x0);

// 0x7100f8ec00
void Unk_f8ec00_set(const Unk_f8ec00* self, Unk_f8ec00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8ec10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ec10_arg1, field_0, 0x0);

struct Unk_f8ec10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ec10, field_0, 0x0);

// 0x7100f8ec10
void Unk_f8ec10_set(const Unk_f8ec10* self, Unk_f8ec10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e1824_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1824_Data, field_18, 0x18);

extern Unk_27e1824_Data Unk_27e1824 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f8ec20
void Unk_f8ec20_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1824.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1824.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1824.field_18 = 0xffff;
    Unk_27e1824.field_10 = 0;
    Unk_27e1824.field_8 = r2;
    Unk_27e1824.field_c = 0;
    Unk_27e1824.field_14 = 0xffffffff;
}
