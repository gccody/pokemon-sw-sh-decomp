// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_7e8d00(u64, u64);

// 0x7100859440
void Unk_859440_call(u64 self, u64 value) {
    Unk_7e8d00(self, value);
}
