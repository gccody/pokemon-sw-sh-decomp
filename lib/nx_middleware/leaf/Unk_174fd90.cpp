// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u8 Unk_27fc2f8 __attribute__((visibility("hidden")));
namespace nn { namespace time { u64 Finalize(); } }
void Unk_174fdd0();

// 0x710174fd90
void Unk_174fd90_call() {
    Unk_174fdd0();
    if (Unk_27fc2f8 == 1) {
        nn::time::Finalize();
        Unk_27fc2f8 = 0;
    }
}
