// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100332b20
u32 Unk_332b20_get() {
    return 4;
}

// 0x7100333890
u32 Unk_333890_get() {
    return 0x42;
}

void Unk_3c8a50();

// 0x7100333a00
void Unk_333a00_call() {
    Unk_3c8a50();
}
