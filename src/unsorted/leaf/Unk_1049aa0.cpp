// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27790f0;
void Unk_6c2e30(u64);

// 0x7101049aa0
void Unk_1049aa0_call() {
    if (Unk_27790f0 != 0) {
        Unk_6c2e30(Unk_27790f0);
    }
}

extern u64 Unk_27790f0;
void Unk_6c2fa0(u64);

// 0x7101049ac0
void Unk_1049ac0_call() {
    if (Unk_27790f0 != 0) {
        Unk_6c2fa0(Unk_27790f0);
    }
}

extern u64 Unk_27790f0;
void Unk_6c2ea0(u64);

// 0x7101049ae0
void Unk_1049ae0_call() {
    if (Unk_27790f0 != 0) {
        Unk_6c2ea0(Unk_27790f0);
    }
}

extern u64 Unk_27790f0;
void Unk_6c2e60(u64);

// 0x7101049b00
void Unk_1049b00_call() {
    if (Unk_27790f0 != 0) {
        Unk_6c2e60(Unk_27790f0);
    }
}

extern u64 Unk_27790f0;
void Unk_6c3140(u64);

// 0x7101049b20
void Unk_1049b20_call() {
    if (Unk_27790f0 != 0) {
        Unk_6c3140(Unk_27790f0);
    }
}

struct Unk_1049d00 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1049d00, field_70, 0x70);

// 0x7101049d00
u8 Unk_1049d00_getField70(const Unk_1049d00* self) {
    return self->field_70;
}

struct Unk_1049d10 {
    u8 _0[0x71];
    u8 field_71;
};
PKMN_OFFSET_ASSERT(Unk_1049d10, field_71, 0x71);

// 0x7101049d10
u8 Unk_1049d10_getField71(const Unk_1049d10* self) {
    return self->field_71;
}
