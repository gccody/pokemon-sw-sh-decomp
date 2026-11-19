// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_e8cc00();

// 0x7100e8cbf0
void Unk_e8cbf0_call() {
    Unk_e8cc00();
}

// 0x7100e92910
void Unk_e92910_update() {}

struct Unk_e92920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92920_arg1, field_0, 0x0);

struct Unk_e92920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92920, field_0, 0x0);

// 0x7100e92920
void Unk_e92920_set(const Unk_e92920* self, Unk_e92920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e92930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92930_arg1, field_0, 0x0);

struct Unk_e92930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92930, field_0, 0x0);

// 0x7100e92930
void Unk_e92930_set(const Unk_e92930* self, Unk_e92930_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100e92a00
void Unk_e92a00_update() {}

struct Unk_e92a10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92a10_arg1, field_0, 0x0);

struct Unk_e92a10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92a10, field_0, 0x0);

// 0x7100e92a10
void Unk_e92a10_set(const Unk_e92a10* self, Unk_e92a10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e92a20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92a20_arg1, field_0, 0x0);

struct Unk_e92a20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e92a20, field_0, 0x0);

// 0x7100e92a20
void Unk_e92a20_set(const Unk_e92a20* self, Unk_e92a20_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100e97cd0
void Unk_e97cd0_update() {}

struct Unk_e98a70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_e98a70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e98a70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_e98a70, field_10, 0x10);

// 0x7100e98a70
void Unk_e98a70_set(const Unk_e98a70* self, Unk_e98a70* value) {
    *value = *self;
}

struct Unk_e98a90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_e98a90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e98a90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_e98a90, field_10, 0x10);

// 0x7100e98a90
void Unk_e98a90_set(const Unk_e98a90* self, Unk_e98a90* value) {
    *value = *self;
}

// 0x7100e98ca0
void Unk_e98ca0_update() {}

struct Unk_e99110 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e99110, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e99110, field_8, 0x8);

// 0x7100e99110
void Unk_e99110_set(const Unk_e99110* self, Unk_e99110* value) {
    *value = *self;
}

struct Unk_e99120 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e99120, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e99120, field_8, 0x8);

// 0x7100e99120
void Unk_e99120_set(const Unk_e99120* self, Unk_e99120* value) {
    *value = *self;
}

// 0x7100e99740
void Unk_e99740_update() {}

struct Unk_e9b2d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e9b2d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e9b2d0, field_8, 0x8);

// 0x7100e9b2d0
void Unk_e9b2d0_set(const Unk_e9b2d0* self, Unk_e9b2d0* value) {
    *value = *self;
}

struct Unk_e9b2e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e9b2e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e9b2e0, field_8, 0x8);

// 0x7100e9b2e0
void Unk_e9b2e0_set(const Unk_e9b2e0* self, Unk_e9b2e0* value) {
    *value = *self;
}

u32 Unk_e9ccb0();

// 0x7100e9cef0
u32 Unk_e9cef0_call() {
    u32 r0 = Unk_e9ccb0();
    return r0 & 0xff;
}
