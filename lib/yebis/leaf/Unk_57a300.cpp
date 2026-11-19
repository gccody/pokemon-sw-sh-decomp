// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_4cadb0();
void Unk_57cfb0();
void Unk_57d4e0();

// 0x710057a300
void Unk_57a300_call() {
    Unk_57cfb0();
    Unk_57d4e0();
    Unk_4cadb0();
}
