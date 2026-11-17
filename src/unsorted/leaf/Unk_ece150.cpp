// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24ba618;
void Unk_eaa600(u64, void*);

// 0x7100ece150
void Unk_ece150_call(void* self) {
    Unk_eaa600(Unk_24ba618, self);
}
