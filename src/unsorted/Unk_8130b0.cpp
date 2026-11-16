// Scope: common
#include <types.h>

struct Unk_8130b0 {
    void* field_0[9];
    u8 _48[4];
    u8 field_4c;
    u8 _4d;
    u8 field_4e;
};
PKMN_OFFSET_ASSERT(Unk_8130b0, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_8130b0, field_4e, 0x4e);

// 0x71008130b0
// Removes the first occurrence of item and moves the rest down.
void Unk_8130b0_remove(Unk_8130b0* self, void* item) {
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->field_0[i] == item) {
            for (u32 j = i + 1; j < self->field_4c; j++)
                self->field_0[j - 1] = self->field_0[j];
            self->field_4c--;
            self->field_4e--;
            return;
        }
    }
}
