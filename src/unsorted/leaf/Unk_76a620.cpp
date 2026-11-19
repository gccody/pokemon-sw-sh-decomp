// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_76a620 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_76a620, field_0, 0x0);

// 0x710076a620
void Unk_76a620_call(Unk_76a620* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}
