// Scope: common
// A forwarder in the battle scene's table TU: it passes the object its first
// field points to on to Unk_9a71e0_set. Placeholder names.
#include "types.h"

struct Unk_9a71e0;
struct Unk_9a71e0_arg1;
void Unk_9a71e0_set(Unk_9a71e0* self, const Unk_9a71e0_arg1* value);

struct Unk_a64fe0 {
    Unk_9a71e0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_a64fe0, field_0, 0x0);

// 0x7100a64fe0
void Unk_a64fe0_set(const Unk_a64fe0* self, const Unk_9a71e0_arg1* value) {
    Unk_9a71e0_set(self->field_0, value);
}
