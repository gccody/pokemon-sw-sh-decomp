// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x71011575f0
void Unk_11575f0_update() {}

struct Unk_1157600 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1157600, field_78, 0x78);

// 0x7101157600
u64 Unk_1157600_getField78(const Unk_1157600* self) {
    return self->field_78;
}

struct Unk_1157610 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_1157610, field_80, 0x80);

// 0x7101157610
u64 Unk_1157610_getField80(const Unk_1157610* self) {
    return self->field_80;
}

struct Unk_115a250 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_115a250, field_0, 0x0);

// 0x710115a250
void Unk_115a250_call(Unk_115a250* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

void Unk_115a2e0(void*, u64, u32, u64);

// 0x710115a510
void Unk_115a510_call(void* self, u32 value, u64 arg2) {
    Unk_115a2e0(self, 0, value, arg2);
}

struct Unk_115a6e0 {
    u8 _0[0x308];
    u64 field_308;
};
PKMN_OFFSET_ASSERT(Unk_115a6e0, field_308, 0x308);

// 0x710115a6e0
u64 Unk_115a6e0_getField308(const Unk_115a6e0* self) {
    return self->field_308;
}

struct Unk_115a710 {
    u8 _0[0x310];
    u8 field_310;
};
PKMN_OFFSET_ASSERT(Unk_115a710, field_310, 0x310);

// 0x710115a710
u8 Unk_115a710_getField310(const Unk_115a710* self) {
    return self->field_310;
}

struct Unk_115a720 {
    u8 _0[0x308];
    u64 field_308;
    u8 field_310;
};
PKMN_OFFSET_ASSERT(Unk_115a720, field_308, 0x308);
PKMN_OFFSET_ASSERT(Unk_115a720, field_310, 0x310);

// 0x710115a720
void Unk_115a720_set(Unk_115a720* self, u8 value) {
    self->field_308 = 0;
    self->field_310 = value;
}

struct Unk_115a730 {
    u8 _0[0x308];
    u64 field_308;
    u8 field_310;
};
PKMN_OFFSET_ASSERT(Unk_115a730, field_308, 0x308);
PKMN_OFFSET_ASSERT(Unk_115a730, field_310, 0x310);

// 0x710115a730
void Unk_115a730_set(Unk_115a730* self) {
    self->field_308 = 0;
    self->field_310 = 0xfd;
}

struct Unk_115b9d0 {
    u8 _0[0x3a0];
    u64 field_3a0;
};
PKMN_OFFSET_ASSERT(Unk_115b9d0, field_3a0, 0x3a0);

// 0x710115b9d0
u64 Unk_115b9d0_getField3a0(const Unk_115b9d0* self) {
    return self->field_3a0;
}

struct Unk_115b9e0 {
    u8 _0[0x3a8];
    u64 field_3a8;
};
PKMN_OFFSET_ASSERT(Unk_115b9e0, field_3a8, 0x3a8);

// 0x710115b9e0
u64 Unk_115b9e0_getField3a8(const Unk_115b9e0* self) {
    return self->field_3a8;
}

struct Unk_115b9f0 {
    u8 _0[0x328];
    u8 field_328;
};
PKMN_OFFSET_ASSERT(Unk_115b9f0, field_328, 0x328);

// 0x710115b9f0
u8* Unk_115b9f0_getField328Ptr(Unk_115b9f0* self) {
    return &self->field_328;
}

struct Unk_115ba00 {
    u8 _0[0x330];
    u8 field_330;
};
PKMN_OFFSET_ASSERT(Unk_115ba00, field_330, 0x330);

// 0x710115ba00
u8* Unk_115ba00_getField330Ptr(Unk_115ba00* self) {
    return &self->field_330;
}

struct Unk_115ba10 {
    u8 _0[0x338];
    u8 field_338;
};
PKMN_OFFSET_ASSERT(Unk_115ba10, field_338, 0x338);

// 0x710115ba10
u8* Unk_115ba10_getField338Ptr(Unk_115ba10* self) {
    return &self->field_338;
}

struct Unk_115ba20 {
    u8 _0[0x3b0];
    u8 field_3b0;
};
PKMN_OFFSET_ASSERT(Unk_115ba20, field_3b0, 0x3b0);

// 0x710115ba20
u8 Unk_115ba20_getField3b0(const Unk_115ba20* self) {
    return self->field_3b0;
}

struct Unk_115bb40 {
    u8 _0[0x3b1];
    u8 field_3b1;
};
PKMN_OFFSET_ASSERT(Unk_115bb40, field_3b1, 0x3b1);

// 0x710115bb40
u8 Unk_115bb40_getField3b1(const Unk_115bb40* self) {
    return self->field_3b1;
}

struct Unk_115bbb0 {
    u8 _0[0x3b4];
    u32 field_3b4;
};
PKMN_OFFSET_ASSERT(Unk_115bbb0, field_3b4, 0x3b4);

// 0x710115bbb0
bool Unk_115bbb0_check(const Unk_115bbb0* self) {
    return self->field_3b4 != 0;
}

struct Unk_115bbc0 {
    u8 _0[0x3b4];
    u32 field_3b4;
};
PKMN_OFFSET_ASSERT(Unk_115bbc0, field_3b4, 0x3b4);

// 0x710115bbc0
u32 Unk_115bbc0_getField3b4(const Unk_115bbc0* self) {
    return self->field_3b4;
}

struct Unk_115bbd0 {
    u8 _0[0x3b4];
    u32 field_3b4;
};
PKMN_OFFSET_ASSERT(Unk_115bbd0, field_3b4, 0x3b4);

// 0x710115bbd0
void Unk_115bbd0_setField3b4(Unk_115bbd0* self, u32 value) {
    self->field_3b4 = value;
}

struct Unk_115bbe0 {
    u8 _0[0x3b8];
    u32 field_3b8;
};
PKMN_OFFSET_ASSERT(Unk_115bbe0, field_3b8, 0x3b8);

// 0x710115bbe0
u32 Unk_115bbe0_getField3b8(const Unk_115bbe0* self) {
    return self->field_3b8;
}

struct Unk_115bbf0 {
    u8 _0[0x3b8];
    u32 field_3b8;
};
PKMN_OFFSET_ASSERT(Unk_115bbf0, field_3b8, 0x3b8);

// 0x710115bbf0
void Unk_115bbf0_setField3b8(Unk_115bbf0* self, u32 value) {
    self->field_3b8 = value;
}

struct Unk_115bc00 {
    u8 _0[0x3bc];
    u32 field_3bc;
};
PKMN_OFFSET_ASSERT(Unk_115bc00, field_3bc, 0x3bc);

// 0x710115bc00
u32 Unk_115bc00_getField3bc(const Unk_115bc00* self) {
    return self->field_3bc;
}

struct Unk_115bde0 {
    u8 _0[0x3c0];
    u8 field_3c0;
};
PKMN_OFFSET_ASSERT(Unk_115bde0, field_3c0, 0x3c0);

void Unk_115bc90();

// 0x710115bde0
void Unk_115bde0_call(Unk_115bde0* self, u32 value) {
    self->field_3c0 = ~value & 1;
    Unk_115bc90();
}

struct Unk_115bfa0 {
    u8 _0[0x418];
    bool field_418;
};
PKMN_OFFSET_ASSERT(Unk_115bfa0, field_418, 0x418);

// 0x710115bfa0
void Unk_115bfa0_set(Unk_115bfa0* self, bool value) {
    self->field_418 = value;
}

struct Unk_115bfb0 {
    u8 _0[0x419];
    bool field_419;
};
PKMN_OFFSET_ASSERT(Unk_115bfb0, field_419, 0x419);

// 0x710115bfb0
void Unk_115bfb0_set(Unk_115bfb0* self, bool value) {
    self->field_419 = value;
}

struct Unk_115bfc0 {
    u8 _0[0x41a];
    bool field_41a;
};
PKMN_OFFSET_ASSERT(Unk_115bfc0, field_41a, 0x41a);

// 0x710115bfc0
void Unk_115bfc0_set(Unk_115bfc0* self, bool value) {
    self->field_41a = value;
}

struct Unk_115cb20 {
    u8 _0[0x4f0];
    f32 field_4f0;
    u8 _4f4[0x4];
    u32 field_4f8;
};
PKMN_OFFSET_ASSERT(Unk_115cb20, field_4f0, 0x4f0);
PKMN_OFFSET_ASSERT(Unk_115cb20, field_4f8, 0x4f8);

// 0x710115cb20
void Unk_115cb20_set(Unk_115cb20* self, f32 fvalue) {
    self->field_4f0 = fvalue;
    self->field_4f8 = 0x3fc00000;
}

struct Unk_115cb30 {
    u8 _0[0x4f0];
    u32 field_4f0;
    u8 _4f4[0x4];
    u32 field_4f8;
};
PKMN_OFFSET_ASSERT(Unk_115cb30, field_4f0, 0x4f0);
PKMN_OFFSET_ASSERT(Unk_115cb30, field_4f8, 0x4f8);

// 0x710115cb30
void Unk_115cb30_set(Unk_115cb30* self) {
    self->field_4f0 = 0x43fa0000;
    self->field_4f8 = 0x41a00000;
}

// 0x710115eff0
void Unk_115eff0_update() {}

struct Unk_115f000_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f000_arg1, field_0, 0x0);

struct Unk_115f000 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f000, field_0, 0x0);

// 0x710115f000
void Unk_115f000_set(const Unk_115f000* self, Unk_115f000_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_115f010_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f010_arg1, field_0, 0x0);

struct Unk_115f010 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f010, field_0, 0x0);

// 0x710115f010
void Unk_115f010_set(const Unk_115f010* self, Unk_115f010_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710115f340
u32 Unk_115f340_get() {
    return 0;
}

// 0x710115f350
void Unk_115f350_update() {}

struct Unk_115f360_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f360_arg1, field_0, 0x0);

struct Unk_115f360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f360, field_0, 0x0);

// 0x710115f360
void Unk_115f360_set(const Unk_115f360* self, Unk_115f360_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_115f370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f370_arg1, field_0, 0x0);

struct Unk_115f370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_115f370, field_0, 0x0);

// 0x710115f370
void Unk_115f370_set(const Unk_115f370* self, Unk_115f370_arg1* value) {
    value->field_0 = self->field_0;
}
