// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_6ae9d0(u64);

// 0x7101061800
void Unk_1061800_call(void* /*unused*/, u64 value) {
    Unk_6ae9d0(value);
}
