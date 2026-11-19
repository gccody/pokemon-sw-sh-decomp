// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x710111aa90
void Unk_111aa90_update() {}

struct Unk_111aaa0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_111aaa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_111aaa0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_111aaa0, field_10, 0x10);

// 0x710111aaa0
void Unk_111aaa0_set(const Unk_111aaa0* self, Unk_111aaa0* value) {
    *value = *self;
}

struct Unk_111aac0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_111aac0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_111aac0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_111aac0, field_10, 0x10);

// 0x710111aac0
void Unk_111aac0_set(const Unk_111aac0* self, Unk_111aac0* value) {
    *value = *self;
}

struct Unk_111bb10 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_111bb10, field_0, 0x0);

// 0x710111bb10
void Unk_111bb10_call(Unk_111bb10* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1120d00 {
    u8 _0[0x908];
    u32 field_908;
};
PKMN_OFFSET_ASSERT(Unk_1120d00, field_908, 0x908);

// 0x7101120d00
u32 Unk_1120d00_getField908(const Unk_1120d00* self) {
    return self->field_908;
}

struct Unk_1121220 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1121220, field_0, 0x0);

// 0x7101121220
void Unk_1121220_call(Unk_1121220* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1121260 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1121260, field_0, 0x0);

// 0x7101121260
void Unk_1121260_call(Unk_1121260* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

// 0x7101123ea0
void Unk_1123ea0_update() {}

// 0x7101124130
void Unk_1124130_update() {}

struct Unk_1124140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124140_arg1, field_0, 0x0);

struct Unk_1124140 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124140, field_0, 0x0);

// 0x7101124140
void Unk_1124140_set(const Unk_1124140* self, Unk_1124140_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124150_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124150_arg1, field_0, 0x0);

struct Unk_1124150 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124150, field_0, 0x0);

// 0x7101124150
void Unk_1124150_set(const Unk_1124150* self, Unk_1124150_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124160_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124160_arg1, field_0, 0x0);

struct Unk_1124160 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124160, field_0, 0x0);

// 0x7101124160
void Unk_1124160_set(const Unk_1124160* self, Unk_1124160_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124170_arg1, field_0, 0x0);

struct Unk_1124170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124170, field_0, 0x0);

// 0x7101124170
void Unk_1124170_set(const Unk_1124170* self, Unk_1124170_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011241e0
void Unk_11241e0_update() {}

struct Unk_11241f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11241f0_arg1, field_0, 0x0);

struct Unk_11241f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11241f0, field_0, 0x0);

// 0x71011241f0
void Unk_11241f0_set(const Unk_11241f0* self, Unk_11241f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124200_arg1, field_0, 0x0);

struct Unk_1124200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124200, field_0, 0x0);

// 0x7101124200
void Unk_1124200_set(const Unk_1124200* self, Unk_1124200_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011243c0
void Unk_11243c0_update() {}

// 0x7101124670
void Unk_1124670_update() {}

struct Unk_1124680 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1124680, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1124680, field_8, 0x8);

// 0x7101124680
void Unk_1124680_set(const Unk_1124680* self, Unk_1124680* value) {
    *value = *self;
}

struct Unk_1124690 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1124690, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1124690, field_8, 0x8);

// 0x7101124690
void Unk_1124690_set(const Unk_1124690* self, Unk_1124690* value) {
    *value = *self;
}

struct Unk_11246a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11246a0_arg1, field_0, 0x0);

struct Unk_11246a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11246a0, field_0, 0x0);

// 0x71011246a0
void Unk_11246a0_set(const Unk_11246a0* self, Unk_11246a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11246b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11246b0_arg1, field_0, 0x0);

struct Unk_11246b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11246b0, field_0, 0x0);

// 0x71011246b0
void Unk_11246b0_set(const Unk_11246b0* self, Unk_11246b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101124710
void Unk_1124710_update() {}

// 0x7101124720
void Unk_1124720_update() {}

// 0x7101124730
void Unk_1124730_update() {}

// 0x71011248d0
void Unk_11248d0_update() {}

// 0x7101124910
void Unk_1124910_update() {}

struct Unk_1124920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124920_arg1, field_0, 0x0);

struct Unk_1124920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124920, field_0, 0x0);

// 0x7101124920
void Unk_1124920_set(const Unk_1124920* self, Unk_1124920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124930_arg1, field_0, 0x0);

struct Unk_1124930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124930, field_0, 0x0);

// 0x7101124930
void Unk_1124930_set(const Unk_1124930* self, Unk_1124930_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124940_arg1, field_0, 0x0);

struct Unk_1124940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124940, field_0, 0x0);

// 0x7101124940
void Unk_1124940_set(const Unk_1124940* self, Unk_1124940_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124950_arg1, field_0, 0x0);

struct Unk_1124950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124950, field_0, 0x0);

// 0x7101124950
void Unk_1124950_set(const Unk_1124950* self, Unk_1124950_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011249a0
void Unk_11249a0_update() {}

struct Unk_11249b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11249b0_arg1, field_0, 0x0);

struct Unk_11249b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11249b0, field_0, 0x0);

// 0x71011249b0
void Unk_11249b0_set(const Unk_11249b0* self, Unk_11249b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11249c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11249c0_arg1, field_0, 0x0);

struct Unk_11249c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11249c0, field_0, 0x0);

// 0x71011249c0
void Unk_11249c0_set(const Unk_11249c0* self, Unk_11249c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101124a40
void Unk_1124a40_update() {}

struct Unk_1124a50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124a50_arg1, field_0, 0x0);

struct Unk_1124a50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124a50, field_0, 0x0);

// 0x7101124a50
void Unk_1124a50_set(const Unk_1124a50* self, Unk_1124a50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124a60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124a60_arg1, field_0, 0x0);

struct Unk_1124a60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124a60, field_0, 0x0);

// 0x7101124a60
void Unk_1124a60_set(const Unk_1124a60* self, Unk_1124a60_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101124ad0
void Unk_1124ad0_update() {}

struct Unk_1124ae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124ae0_arg1, field_0, 0x0);

struct Unk_1124ae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124ae0, field_0, 0x0);

// 0x7101124ae0
void Unk_1124ae0_set(const Unk_1124ae0* self, Unk_1124ae0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124af0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124af0_arg1, field_0, 0x0);

struct Unk_1124af0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124af0, field_0, 0x0);

// 0x7101124af0
void Unk_1124af0_set(const Unk_1124af0* self, Unk_1124af0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101124b40
void Unk_1124b40_update() {}

struct Unk_1124b50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124b50_arg1, field_0, 0x0);

struct Unk_1124b50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124b50, field_0, 0x0);

// 0x7101124b50
void Unk_1124b50_set(const Unk_1124b50* self, Unk_1124b50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124b60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124b60_arg1, field_0, 0x0);

struct Unk_1124b60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124b60, field_0, 0x0);

// 0x7101124b60
void Unk_1124b60_set(const Unk_1124b60* self, Unk_1124b60_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101124d00
void Unk_1124d00_update() {}

// 0x7101124f90
void Unk_1124f90_update() {}

struct Unk_1124fa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fa0_arg1, field_0, 0x0);

struct Unk_1124fa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fa0, field_0, 0x0);

// 0x7101124fa0
void Unk_1124fa0_set(const Unk_1124fa0* self, Unk_1124fa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124fb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fb0_arg1, field_0, 0x0);

struct Unk_1124fb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fb0, field_0, 0x0);

// 0x7101124fb0
void Unk_1124fb0_set(const Unk_1124fb0* self, Unk_1124fb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124fc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fc0_arg1, field_0, 0x0);

struct Unk_1124fc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fc0, field_0, 0x0);

// 0x7101124fc0
void Unk_1124fc0_set(const Unk_1124fc0* self, Unk_1124fc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124fd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fd0_arg1, field_0, 0x0);

struct Unk_1124fd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fd0, field_0, 0x0);

// 0x7101124fd0
void Unk_1124fd0_set(const Unk_1124fd0* self, Unk_1124fd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1124fe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fe0_arg1, field_0, 0x0);

struct Unk_1124fe0_0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fe0_0, field_0, 0x0);

struct Unk_1124fe0 {
    Unk_1124fe0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1124fe0, field_0, 0x0);

u32 Unk_11611a0(u64);

// 0x7101124fe0
void Unk_1124fe0_call(const Unk_1124fe0* self, const Unk_1124fe0_arg1* value) {
    u32 r0 = Unk_11611a0(value->field_0);
    self->field_0->field_0 = self->field_0->field_0 & r0;
}

// 0x7101125020
void Unk_1125020_update() {}

struct Unk_1125030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1125030_arg1, field_0, 0x0);

struct Unk_1125030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1125030, field_0, 0x0);

// 0x7101125030
void Unk_1125030_set(const Unk_1125030* self, Unk_1125030_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1125040_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1125040_arg1, field_0, 0x0);

struct Unk_1125040 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1125040, field_0, 0x0);

// 0x7101125040
void Unk_1125040_set(const Unk_1125040* self, Unk_1125040_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011250c0
void Unk_11250c0_update() {}

struct Unk_11250d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11250d0_arg1, field_0, 0x0);

struct Unk_11250d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11250d0, field_0, 0x0);

// 0x71011250d0
void Unk_11250d0_set(const Unk_11250d0* self, Unk_11250d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11250e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11250e0_arg1, field_0, 0x0);

struct Unk_11250e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11250e0, field_0, 0x0);

// 0x71011250e0
void Unk_11250e0_set(const Unk_11250e0* self, Unk_11250e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011266e0
void Unk_11266e0_update() {}

// 0x71011268a0
void Unk_11268a0_update() {}

struct Unk_11268b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11268b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11268b0, field_8, 0x8);

// 0x71011268b0
void Unk_11268b0_set(const Unk_11268b0* self, Unk_11268b0* value) {
    *value = *self;
}

struct Unk_11268c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11268c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11268c0, field_8, 0x8);

// 0x71011268c0
void Unk_11268c0_set(const Unk_11268c0* self, Unk_11268c0* value) {
    *value = *self;
}

struct Unk_11268d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11268d0_arg1, field_0, 0x0);

struct Unk_11268d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11268d0, field_0, 0x0);

// 0x71011268d0
void Unk_11268d0_set(const Unk_11268d0* self, Unk_11268d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11268e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11268e0_arg1, field_0, 0x0);

struct Unk_11268e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11268e0, field_0, 0x0);

// 0x71011268e0
void Unk_11268e0_set(const Unk_11268e0* self, Unk_11268e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101126ab0
void Unk_1126ab0_update() {}

struct Unk_1126ac0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1126ac0_arg1, field_0, 0x0);

struct Unk_1126ac0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1126ac0, field_0, 0x0);

// 0x7101126ac0
void Unk_1126ac0_set(const Unk_1126ac0* self, Unk_1126ac0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1126ad0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1126ad0_arg1, field_0, 0x0);

struct Unk_1126ad0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1126ad0, field_0, 0x0);

// 0x7101126ad0
void Unk_1126ad0_set(const Unk_1126ad0* self, Unk_1126ad0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101126c80
void Unk_1126c80_update() {}

struct Unk_1126c90 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1126c90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1126c90, field_8, 0x8);

// 0x7101126c90
void Unk_1126c90_set(const Unk_1126c90* self, Unk_1126c90* value) {
    *value = *self;
}

struct Unk_1126ca0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1126ca0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1126ca0, field_8, 0x8);

// 0x7101126ca0
void Unk_1126ca0_set(const Unk_1126ca0* self, Unk_1126ca0* value) {
    *value = *self;
}

// 0x7101126e70
void Unk_1126e70_update() {}

// 0x7101127250
void Unk_1127250_update() {}

// 0x71011272a0
void Unk_11272a0_update() {}

struct Unk_11272b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11272b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11272b0, field_8, 0x8);

// 0x71011272b0
void Unk_11272b0_set(const Unk_11272b0* self, Unk_11272b0* value) {
    *value = *self;
}

struct Unk_11272c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11272c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11272c0, field_8, 0x8);

// 0x71011272c0
void Unk_11272c0_set(const Unk_11272c0* self, Unk_11272c0* value) {
    *value = *self;
}

struct Unk_11272d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11272d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11272d0, field_8, 0x8);

// 0x71011272d0
void Unk_11272d0_set(const Unk_11272d0* self, Unk_11272d0* value) {
    *value = *self;
}

struct Unk_11272e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11272e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11272e0, field_8, 0x8);

// 0x71011272e0
void Unk_11272e0_set(const Unk_11272e0* self, Unk_11272e0* value) {
    *value = *self;
}

struct Unk_11272f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11272f0_arg1, field_0, 0x0);

struct Unk_11272f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11272f0, field_0, 0x0);

// 0x71011272f0
void Unk_11272f0_set(const Unk_11272f0* self, Unk_11272f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1127300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127300_arg1, field_0, 0x0);

struct Unk_1127300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127300, field_0, 0x0);

// 0x7101127300
void Unk_1127300_set(const Unk_1127300* self, Unk_1127300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1127310_arg1_0 {
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19(u64);
};

struct Unk_1127310_arg1 {
    Unk_1127310_arg1_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127310_arg1, field_0, 0x0);

struct Unk_1127310_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127310_arg2, field_0, 0x0);

// 0x7101127310
void Unk_1127310_call(void* /*unused*/,
                      const Unk_1127310_arg1* value,
                      const Unk_1127310_arg2* arg2) {
    value->field_0->vf19(arg2->field_0);
}

// 0x7101127330
void Unk_1127330_update() {}

// 0x7101127340
void Unk_1127340_update() {}

// 0x7101127350
void Unk_1127350_update() {}

// 0x7101127880
void Unk_1127880_update() {}

// 0x71011278c0
void Unk_11278c0_update() {}

struct Unk_11278d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11278d0_arg1, field_0, 0x0);

struct Unk_11278d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11278d0, field_0, 0x0);

// 0x71011278d0
void Unk_11278d0_set(const Unk_11278d0* self, Unk_11278d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11278e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11278e0_arg1, field_0, 0x0);

struct Unk_11278e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11278e0, field_0, 0x0);

// 0x71011278e0
void Unk_11278e0_set(const Unk_11278e0* self, Unk_11278e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11278f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11278f0_arg1, field_0, 0x0);

struct Unk_11278f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11278f0, field_0, 0x0);

// 0x71011278f0
void Unk_11278f0_set(const Unk_11278f0* self, Unk_11278f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1127900_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127900_arg1, field_0, 0x0);

struct Unk_1127900 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127900, field_0, 0x0);

// 0x7101127900
void Unk_1127900_set(const Unk_1127900* self, Unk_1127900_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101127ad0
void Unk_1127ad0_update() {}

struct Unk_1127ae0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1127ae0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1127ae0, field_8, 0x8);

// 0x7101127ae0
void Unk_1127ae0_set(const Unk_1127ae0* self, Unk_1127ae0* value) {
    *value = *self;
}

struct Unk_1127af0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1127af0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1127af0, field_8, 0x8);

// 0x7101127af0
void Unk_1127af0_set(const Unk_1127af0* self, Unk_1127af0* value) {
    *value = *self;
}

// 0x7101127b60
void Unk_1127b60_update() {}

struct Unk_1127b70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127b70_arg1, field_0, 0x0);

struct Unk_1127b70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127b70, field_0, 0x0);

// 0x7101127b70
void Unk_1127b70_set(const Unk_1127b70* self, Unk_1127b70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1127b80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127b80_arg1, field_0, 0x0);

struct Unk_1127b80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1127b80, field_0, 0x0);

// 0x7101127b80
void Unk_1127b80_set(const Unk_1127b80* self, Unk_1127b80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11281f0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11281f0, field_0, 0x0);

// 0x71011281f0
void Unk_11281f0_call(Unk_11281f0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1128230_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1128230_arg1, field_0, 0x0);

struct Unk_1128230 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1128230, field_0, 0x0);

// 0x7101128230
void Unk_1128230_call(const Unk_1128230* self, Unk_1128230_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1128250_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1128250_arg1, field_0, 0x0);

struct Unk_1128250 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1128250, field_0, 0x0);

// 0x7101128250
void Unk_1128250_call(const Unk_1128250* self, Unk_1128250_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
