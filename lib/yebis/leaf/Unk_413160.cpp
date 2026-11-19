// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_412d20();
void Unk_412ed0();

// 0x7100413160
void Unk_413160_call(void* /*unused*/, u64 /*unused*/, u64 /*unused*/, u64 /*unused*/, u64 /*unused*/, u32 arg5) {
    if (arg5 != 0) {
        Unk_412ed0();
        return;
    }
    Unk_412d20();
}
