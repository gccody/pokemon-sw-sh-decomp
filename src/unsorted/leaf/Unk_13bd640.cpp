// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u64 Unk_d1f140();

// 0x71013bd640
u64 Unk_13bd640_call() {
    u64 r0 = Unk_d1f140();
    return r0 & 1;
}

u64 Unk_d634d0();

// 0x71013bec00
u64 Unk_13bec00_call() {
    u64 r0 = Unk_d634d0();
    return r0 & 1;
}

struct Unk_13bedc0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13bedc0_arg1, field_8, 0x8);

void Unk_d28300(bool);

// 0x71013bedc0
u32 Unk_13bedc0_call(void* /*unused*/, const Unk_13bedc0_arg1* value) {
    Unk_d28300(value->field_8 != 0);
    return 1;
}

// 0x71013bf710
u32 Unk_13bf710_get() {
    return 1;
}

void Unk_d2af10();

// 0x71013c4b50
u32 Unk_13c4b50_call() {
    Unk_d2af10();
    return 1;
}

struct Unk_13c5670_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c5670_arg1, field_8, 0x8);

void Unk_d29c40_set(bool);

// 0x71013c5670
u32 Unk_13c5670_call(void* /*unused*/, const Unk_13c5670_arg1* value) {
    Unk_d29c40_set(value->field_8 != 0);
    return 1;
}

struct Unk_13c56e0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c56e0_arg1, field_8, 0x8);

void Unk_d29e50_set(bool);

// 0x71013c56e0
u32 Unk_13c56e0_call(void* /*unused*/, const Unk_13c56e0_arg1* value) {
    Unk_d29e50_set(value->field_8 != 0);
    return 1;
}

struct Unk_13c67e0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13c67e0_arg1, field_8, 0x8);

void Unk_e38bb0(bool);

// 0x71013c67e0
u32 Unk_13c67e0_call(void* /*unused*/, const Unk_13c67e0_arg1* value) {
    Unk_e38bb0(value->field_8 != 0);
    return 1;
}

// 0x71013cee80
void Unk_13cee80_update() {}

struct Unk_13cee90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13cee90_arg1, field_0, 0x0);

struct Unk_13cee90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13cee90, field_0, 0x0);

// 0x71013cee90
void Unk_13cee90_set(const Unk_13cee90* self, Unk_13cee90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_13ceea0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13ceea0_arg1, field_0, 0x0);

struct Unk_13ceea0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13ceea0, field_0, 0x0);

// 0x71013ceea0
void Unk_13ceea0_set(const Unk_13ceea0* self, Unk_13ceea0_arg1* value) {
    value->field_0 = self->field_0;
}
