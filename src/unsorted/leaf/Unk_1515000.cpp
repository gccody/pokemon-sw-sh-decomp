// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1515000 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1515000, field_5cc, 0x5cc);

// 0x7101515000
void Unk_1515000_clearField5cc(Unk_1515000* self) {
    self->field_5cc = 0;
}

struct Unk_1515010 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1515010, field_5cc, 0x5cc);

// 0x7101515010
u32 Unk_1515010_getField5cc(const Unk_1515010* self) {
    return self->field_5cc;
}

// 0x7101516ee0
void Unk_1516ee0_update() {}

struct Unk_1516ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516ef0_arg1, field_0, 0x0);

struct Unk_1516ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516ef0, field_0, 0x0);

// 0x7101516ef0
void Unk_1516ef0_set(const Unk_1516ef0* self, Unk_1516ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1516f00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516f00_arg1, field_0, 0x0);

struct Unk_1516f00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516f00, field_0, 0x0);

// 0x7101516f00
void Unk_1516f00_set(const Unk_1516f00* self, Unk_1516f00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71015180e0
void Unk_15180e0_update() {}

struct Unk_15180f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15180f0_arg1, field_0, 0x0);

struct Unk_15180f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15180f0, field_0, 0x0);

// 0x71015180f0
void Unk_15180f0_set(const Unk_15180f0* self, Unk_15180f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1518100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1518100_arg1, field_0, 0x0);

struct Unk_1518100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1518100, field_0, 0x0);

// 0x7101518100
void Unk_1518100_set(const Unk_1518100* self, Unk_1518100_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710151a420
u32 Unk_151a420() {
    return 9;
}
