// Scope: common
//
// Callables of the battle spot's states (the segment 0x7100ad5f10-0x7100afb530):
// each holds the state it sets, weakly (the object and the handle that counts
// its references), and acts only while the handle still has references.
// Their copies and destructors are in src/unsorted/leaf/Unk_ad7360.cpp.
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// What the callables set: a value, the flag that says it's set, and (for
// Unk_afb2d0) the flag it was picked by.
struct Unk_afb200_Target {
    u8 _0[0x8c];
    bool field_8c;
    u8 _8d[0x3];
    u32 field_90;
    bool field_94;
};
PKMN_OFFSET_ASSERT(Unk_afb200_Target, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_afb200_Target, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_afb200_Target, field_94, 0x94);

// The state, its value and the state's handle.
struct Unk_afb200 {
    Unk_afb200_Target* field_0;
    u32 field_8;
    Unk_239a418_Handle* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb200, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb200, field_10, 0x10);

// The object is read before the handle's count: the count's load is an
// acquire, and the original loads the object above it.
static inline void Unk_afb200_Set(const Unk_afb200* self) {
    Unk_afb200_Target* target = self->field_0;
    if (self->field_10 != nullptr && self->field_10->field_54.load() != 0) {
        target->field_90 = self->field_8;
        target->field_8c = true;
    }
}

// 0x7100afb200
void Unk_afb200_call(const Unk_afb200* self) {
    Unk_afb200_Set(self);
}

// The state, the values for a set and a clear flag, and the state's handle.
struct Unk_afb2d0 {
    Unk_afb200_Target* field_0;
    u32 field_8;
    u32 field_c;
    Unk_239a418_Handle* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb2d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb2d0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_afb2d0, field_10, 0x10);

// 0x7100afb2d0
void Unk_afb2d0_call(const Unk_afb2d0* self, const bool* flag) {
    bool value = *flag;  // read first, like the object
    Unk_afb200_Target* target = self->field_0;
    if (self->field_10 != nullptr && self->field_10->field_54.load() != 0) {
        target->field_90 = value ? self->field_8 : self->field_c;
        target->field_8c = true;
        target->field_94 = value;
    }
}

// 0x7100afb3c0
void Unk_afb3c0_call(const Unk_afb200* self) {
    Unk_afb200_Set(self);
}
