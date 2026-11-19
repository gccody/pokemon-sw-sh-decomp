// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_12f0100_168 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_12f0100_168, field_170, 0x170);

struct Unk_12f0100 {
    u8 _0[0x168];
    Unk_12f0100_168* field_168;
};
PKMN_OFFSET_ASSERT(Unk_12f0100, field_168, 0x168);

// 0x71012f0100
u8 Unk_12f0100_get(const Unk_12f0100* self) {
    if (self->field_168 == nullptr) {
        return 0;
    }
    return self->field_168->field_170;
}

struct Unk_12f6220_0 {
    u8 _0[0x160];
    u8 field_160;
    u8 _161[0x10f];
    void* field_270;
};
PKMN_OFFSET_ASSERT(Unk_12f6220_0, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_12f6220_0, field_270, 0x270);

struct Unk_12f6220 {
    Unk_12f6220_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12f6220, field_0, 0x0);

void Unk_12f6240(void*, void*);

// 0x71012f6220
void Unk_12f6220_call(const Unk_12f6220* self) {
    Unk_12f6240(self->field_0->field_270, &self->field_0->field_160);
}

// 0x71012f6230
void Unk_12f6230_update() {}

struct Unk_12f6950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12f6950_arg1, field_0, 0x0);

struct Unk_12f6950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12f6950, field_0, 0x0);

// 0x71012f6950
void Unk_12f6950_set(const Unk_12f6950* self, Unk_12f6950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12f6960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12f6960_arg1, field_0, 0x0);

struct Unk_12f6960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12f6960, field_0, 0x0);

// 0x71012f6960
void Unk_12f6960_set(const Unk_12f6960* self, Unk_12f6960_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012f9ec0
void Unk_12f9ec0_update() {}

struct Unk_12f9ed0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12f9ed0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12f9ed0, field_8, 0x8);

// 0x71012f9ed0
void Unk_12f9ed0_set(const Unk_12f9ed0* self, Unk_12f9ed0* value) {
    *value = *self;
}

struct Unk_12f9ee0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12f9ee0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12f9ee0, field_8, 0x8);

// 0x71012f9ee0
void Unk_12f9ee0_set(const Unk_12f9ee0* self, Unk_12f9ee0* value) {
    *value = *self;
}

// 0x71012fd750
void Unk_12fd750_update() {}

struct Unk_12fd760 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12fd760, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fd760, field_8, 0x8);

// 0x71012fd760
void Unk_12fd760_set(const Unk_12fd760* self, Unk_12fd760* value) {
    *value = *self;
}

struct Unk_12fd770 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12fd770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fd770, field_8, 0x8);

// 0x71012fd770
void Unk_12fd770_set(const Unk_12fd770* self, Unk_12fd770* value) {
    *value = *self;
}

// 0x71012fd890
void Unk_12fd890_update() {}

struct Unk_12fd8a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fd8a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fd8a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fd8a0, field_10, 0x10);

// 0x71012fd8a0
void Unk_12fd8a0_set(const Unk_12fd8a0* self, Unk_12fd8a0* value) {
    *value = *self;
}

struct Unk_12fd8c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fd8c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fd8c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fd8c0, field_10, 0x10);

// 0x71012fd8c0
void Unk_12fd8c0_set(const Unk_12fd8c0* self, Unk_12fd8c0* value) {
    *value = *self;
}

// 0x71012fd9f0
void Unk_12fd9f0_update() {}

struct Unk_12fda00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fda00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fda00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fda00, field_10, 0x10);

// 0x71012fda00
void Unk_12fda00_set(const Unk_12fda00* self, Unk_12fda00* value) {
    *value = *self;
}

struct Unk_12fda20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fda20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fda20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fda20, field_10, 0x10);

// 0x71012fda20
void Unk_12fda20_set(const Unk_12fda20* self, Unk_12fda20* value) {
    *value = *self;
}

// 0x71012fdb50
void Unk_12fdb50_update() {}

struct Unk_12fdb60 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fdb60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fdb60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fdb60, field_10, 0x10);

// 0x71012fdb60
void Unk_12fdb60_set(const Unk_12fdb60* self, Unk_12fdb60* value) {
    *value = *self;
}

struct Unk_12fdb80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fdb80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fdb80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fdb80, field_10, 0x10);

// 0x71012fdb80
void Unk_12fdb80_set(const Unk_12fdb80* self, Unk_12fdb80* value) {
    *value = *self;
}

// 0x71012fdcb0
void Unk_12fdcb0_update() {}

struct Unk_12fdcc0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fdcc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fdcc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fdcc0, field_10, 0x10);

// 0x71012fdcc0
void Unk_12fdcc0_set(const Unk_12fdcc0* self, Unk_12fdcc0* value) {
    *value = *self;
}

struct Unk_12fdce0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_12fdce0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12fdce0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12fdce0, field_10, 0x10);

// 0x71012fdce0
void Unk_12fdce0_set(const Unk_12fdce0* self, Unk_12fdce0* value) {
    *value = *self;
}

struct Unk_12fe070 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12fe070, field_0, 0x0);

// 0x71012fe070
void Unk_12fe070_call(Unk_12fe070* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}
