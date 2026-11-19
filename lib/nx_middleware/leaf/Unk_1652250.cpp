// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1652250 {
    u8 _0[0x48];
    u32 field_48;
    u8 _4c[0x10c];
    u64 field_158;
};
PKMN_OFFSET_ASSERT(Unk_1652250, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_1652250, field_158, 0x158);

// 0x7101652250
u64 Unk_1652250_get(const Unk_1652250* self) {
    if (self->field_48 == 3) {
        return 0xffffffffffffffff;
    }
    return self->field_158;
}

extern u8 Unk_27f9cb0 __attribute__((visibility("hidden")));

// 0x71016524a0
u8 Unk_16524a0_get() {
    return Unk_27f9cb0;
}

extern u8 Unk_27f9cb2 __attribute__((visibility("hidden")));

// 0x71016528c0
u8 Unk_16528c0_get() {
    return Unk_27f9cb2;
}

// 0x7101652990
void Unk_1652990_update() {
}

extern u8 Unk_27f9db0;
extern void* Unk_27fc098;
void Unk_171aa70();
void Unk_1721360(void*);
void Unk_17220c0();

// 0x7101652a50
void Unk_1652a50_call() {
    if (Unk_27f9db0 != 0) {
        Unk_27f9db0 = 0;
        Unk_1721360(Unk_27fc098);
        Unk_17220c0();
        Unk_171aa70();
    }
}

extern u32 Unk_2456bb8;

// 0x7101652c30
void Unk_1652c30_set() {
    Unk_2456bb8 = 0x19;
}
