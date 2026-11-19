// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_1722130();

// 0x7101721350
void Unk_1721350_call() {
    Unk_1722130();
}

extern u64 Unk_27fc088;
namespace nn { namespace os { u64 GetSystemTickFrequency(); } }

// 0x71017214d0
void Unk_17214d0_call() {
    u64 r0 = nn::os::GetSystemTickFrequency();
    Unk_27fc088 = r0;
}
