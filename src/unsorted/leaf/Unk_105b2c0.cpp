// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_240bfb0;

// 0x710105b2c0
u64 Unk_105b2c0_get() {
    return Unk_240bfb0;
}

extern u64 Unk_24ba598;
extern u64 Unk_24ba5b8;
void Unk_104e0e0(u64);
void Unk_1064e30(u64);
void Unk_6a0ab0();

// 0x710105c360
void Unk_105c360_call() {
    Unk_1064e30(Unk_24ba5b8);
    Unk_6a0ab0();
    Unk_104e0e0(Unk_24ba598);
}

u32 Unk_6a0d40();

// 0x710105c3c0
bool Unk_105c3c0_call() {
    u32 r0 = Unk_6a0d40();
    return (r0 & 0xff) == 0;
}
