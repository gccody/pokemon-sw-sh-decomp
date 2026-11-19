// Scope: common
// A copy the battle Pokemon's TU calls out of line (0x71007f3610), so it's
// in another TU. Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_7ee6b0.h"

// 0x71007f4450
void Unk_7f4450(Unk_7f4450_Data* self, const Unk_7f4450_Data* other) {
    *self = *other;
}
