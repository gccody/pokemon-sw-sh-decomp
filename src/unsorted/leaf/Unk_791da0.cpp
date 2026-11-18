// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27ce848;
void Unk_793880(u64);

// 0x7100791da0
void Unk_791da0_call() {
    Unk_793880(Unk_27ce848);
}

extern u64 Unk_27ce848;
void Unk_793a60(u64, void*);

// 0x7100791db0
void Unk_791db0_call(void* /*unused*/, void* value) {
    Unk_793a60(Unk_27ce848, value);
}

struct Unk_7935d0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_7935d0, field_70, 0x70);

void Unk_6744e0(u64);

// 0x71007935d0
void Unk_7935d0_call(const Unk_7935d0* self) {
    Unk_6744e0(self->field_70);
}

struct Unk_7935e0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_7935e0, field_70, 0x70);

void Unk_674620(u64);

// 0x71007935e0
void Unk_7935e0_call(const Unk_7935e0* self) {
    Unk_674620(self->field_70);
}

struct Unk_7935f0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_7935f0, field_70, 0x70);

void Unk_674680(u64);

// 0x71007935f0
void Unk_7935f0_call(const Unk_7935f0* self) {
    Unk_674680(self->field_70);
}

struct Unk_793600 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_793600, field_70, 0x70);

void Unk_674690(u64);

// 0x7100793600
void Unk_793600_call(const Unk_793600* self) {
    Unk_674690(self->field_70);
}

struct Unk_793610 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_793610, field_70, 0x70);

void Unk_6746f0(u64);

// 0x7100793610
void Unk_793610_call(const Unk_793610* self) {
    Unk_6746f0(self->field_70);
}

struct Unk_793620 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_793620, field_70, 0x70);

void Unk_674720(u64, u64, u32);

// 0x7100793620
void Unk_793620_call(const Unk_793620* self, u64 value, bool arg2) {
    Unk_674720(self->field_70, value, arg2);
}

struct Unk_793630 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_793630, field_70, 0x70);

void Unk_674b60(u64, u64, u32);

// 0x7100793630
void Unk_793630_call(const Unk_793630* self, u64 value, bool arg2) {
    Unk_674b60(self->field_70, value, arg2);
}

// 0x7100793920
void Unk_793920_update() {}

extern u64 Unk_27ce848;
void Unk_793c10(u64);

// 0x7100794490
void Unk_794490_call() {
    Unk_793c10(Unk_27ce848);
}
