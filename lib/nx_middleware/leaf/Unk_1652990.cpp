// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101652990
void Unk_1652990_update() {
}

extern u8 Unk_27f9db0;
extern u64 Unk_27fc098;
void Unk_171aa70();
void Unk_1721360(u64);
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
