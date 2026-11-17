// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10307f0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10307f0, field_18, 0x18);

void Unk_1030800(u64);

// 0x71010307f0
void Unk_10307f0_call(const Unk_10307f0* self) {
    if (self->field_18 != 0) {
        Unk_1030800(self->field_18);
    }
}

void Unk_1031080(void*, u32);

// 0x71010314a0
void Unk_10314a0_call(void* self) {
    Unk_1031080(self, 1);
}

void Unk_1031080(void*, u32);

// 0x71010314b0
void Unk_10314b0_call(void* self) {
    Unk_1031080(self, 2);
}

void Unk_1031080(void*, u32);

// 0x71010314c0
void Unk_10314c0_call(void* self) {
    Unk_1031080(self, 3);
}

void Unk_1031080(void*, u32);

// 0x71010314d0
void Unk_10314d0_call(void* self) {
    Unk_1031080(self, 4);
}

void Unk_1031080(void*, u32);

// 0x71010314e0
void Unk_10314e0_call(void* self) {
    Unk_1031080(self, 5);
}
