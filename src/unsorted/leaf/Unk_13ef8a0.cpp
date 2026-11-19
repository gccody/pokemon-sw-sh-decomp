// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_24368b0[] __attribute__((visibility("hidden")));

// 0x71013ef8a0
const u8* Unk_13ef8a0_get() {
    return Unk_24368b0;
}

u64 Unk_e591a0();

// 0x71013f15c0
u64 Unk_13f15c0_call() {
    u64 r0 = Unk_e591a0();
    return r0 & 1;
}

void Unk_d9cea0();

// 0x71013f2170
u32 Unk_13f2170_call() {
    Unk_d9cea0();
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d720e0(u32);

// 0x71013f4200
u32 Unk_13f4200_call(Unk_66efd0* self) {
    Unk_d720e0(0);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d720e0(u32);

// 0x71013f4240
u32 Unk_13f4240_call(Unk_66efd0* self) {
    Unk_d720e0(1);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d6cb90();

// 0x71013f5d50
u32 Unk_13f5d50_call(Unk_66efd0* self) {
    Unk_d6cb90();
    Unk_66efd0_update(self, 0xc);
    return 1;
}

u64 Unk_1376830();

// 0x71013f5ee0
u64 Unk_13f5ee0_call() {
    u64 r0 = Unk_1376830();
    return r0 & 1;
}

// 0x71013f5f00
u64 Unk_13f5f00_get() {
    return 0;
}

// 0x71013f5f10
u64 Unk_13f5f10_get() {
    return 0;
}
