// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_2433c50[] __attribute__((visibility("hidden")));

// 0x71013a3530
const u8* Unk_13a3530_get() {
    return Unk_2433c50;
}

struct Unk_66efd0;
extern u64 Unk_24ba5a8;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_da5b40(u64);

// 0x71013a3f20
u32 Unk_13a3f20_call(Unk_66efd0* self) {
    Unk_da5b40(Unk_24ba5a8);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
extern u64 Unk_24ba5a8;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_a74310(u64, u32);

// 0x71013a45a0
u32 Unk_13a45a0_call(Unk_66efd0* self) {
    Unk_a74310(Unk_24ba5a8, 0);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
extern u64 Unk_24ba5a8;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_14856c0(u64);

// 0x71013a4680
u32 Unk_13a4680_call(Unk_66efd0* self) {
    Unk_14856c0(Unk_24ba5a8);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
extern u64 Unk_24ba5a8;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_1296460(u64);

// 0x71013a46c0
u32 Unk_13a46c0_call(Unk_66efd0* self) {
    Unk_1296460(Unk_24ba5a8);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d9abd0();

// 0x71013a48f0
u32 Unk_13a48f0_call(Unk_66efd0* self) {
    Unk_d9abd0();
    Unk_66efd0_update(self, 0xc);
    return 1;
}
