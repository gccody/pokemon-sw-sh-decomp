// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710122d9b0
void Unk_122d9b0_update() {}

// 0x710122d9c0
void Unk_122d9c0_update() {}

// 0x710122d9d0
void Unk_122d9d0_update() {}

struct Unk_115bde0;
struct Unk_122d9e0_arg1 {
    Unk_115bde0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_122d9e0_arg1, field_0, 0x0);

void Unk_115bde0_call(Unk_115bde0*, u32);

// 0x710122d9e0
void Unk_122d9e0_call(void* /*unused*/, const Unk_122d9e0_arg1* value) {
    Unk_115bde0_call(value->field_0, 0);
}

// 0x710122d9f0
void Unk_122d9f0_update() {}

// 0x710122da00
void Unk_122da00_update() {}

// 0x710122da10
void Unk_122da10_update() {}
