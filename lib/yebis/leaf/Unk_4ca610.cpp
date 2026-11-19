// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u8 Unk_24e8f38;

// 0x71004ca610
u8* Unk_4ca610_get() {
    return &Unk_24e8f38;
}
