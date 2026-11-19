// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9b0a40 {
    u8 _0[0x4a8];
    void* field_4a8;
    u8 _4b0[0x18];
    u32 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_9b0a40, field_4a8, 0x4a8);
PKMN_OFFSET_ASSERT(Unk_9b0a40, field_4c8, 0x4c8);

u32 Unk_794040(void*, void*);
void Unk_9b0670(void*);

// 0x71009b0a40
void Unk_9b0a40_call(Unk_9b0a40* self, void* value) {
    Unk_9b0670(self);
    u32 r1 = Unk_794040(self->field_4a8, value);
    self->field_4c8 = r1;
}
