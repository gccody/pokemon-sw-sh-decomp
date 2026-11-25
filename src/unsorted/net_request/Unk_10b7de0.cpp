// Scope: common
// Leaf functions that call a stored callback on the object a handle points
// to. Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10b83e0_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_10b83e0_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_10b83e0_Target, field_80, 0x80);

struct Unk_10b83e0 {
    Unk_10b83e0_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b83e0, field_0, 0x0);

// 0x71010b83e0
void Unk_10b83e0_call(Unk_10b83e0* self) {
    Unk_10b83e0_Target* target = self->field_0;
    target->field_60(target->field_80);
}

struct Unk_10b8460_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_10b8460_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_10b8460_Target, field_80, 0x80);

struct Unk_10b8460 {
    Unk_10b8460_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8460, field_0, 0x0);

// 0x71010b8460
void Unk_10b8460_call(Unk_10b8460* self) {
    Unk_10b8460_Target* target = self->field_0;
    target->field_60(target->field_80);
}
