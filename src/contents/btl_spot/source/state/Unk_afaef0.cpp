// Scope: common
//
// Callables of the battle spot's states (the segment 0x7100ad5f10-0x7100afb530):
// each holds the state it sets, weakly (the object and the handle that counts
// its references), and acts only while the handle still has references.
// Their copies and destructors are in src/unsorted/leaf/Unk_ad7360.cpp.
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// What the callables set: a value and the flag that says it's set.
struct Unk_afaef0_Target {
    u8 _0[0x8c];
    bool field_8c;
    u8 _8d[0x3];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_afaef0_Target, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_afaef0_Target, field_90, 0x90);

// The state, its value and the state's handle.
struct Unk_afaef0 {
    Unk_afaef0_Target* field_0;
    u32 field_8;
    Unk_239a418_Handle* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afaef0, field_10, 0x10);

// The object is read before the handle's count: the count's load is an
// acquire, and the original loads the object above it.
static inline void Unk_afaef0_Set(const Unk_afaef0* self) {
    Unk_afaef0_Target* target = self->field_0;
    if (self->field_10 != nullptr && self->field_10->field_54.load() != 0) {
        target->field_90 = self->field_8;
        target->field_8c = true;
    }
}

// 0x7100afaef0
void Unk_afaef0_call(const Unk_afaef0* self) {
    Unk_afaef0_Set(self);
}

// The handle first, then the object: the callable checks it and does nothing
// else.
struct Unk_afafc0 {
    Unk_239a418_Handle* field_0;
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afafc0, field_8, 0x8);

// 0x7100afafc0
void Unk_afafc0_call(const Unk_afafc0* self) {
    if (self->field_0 != nullptr && self->field_0->field_54.load() != 0) {
    }
}

// 0x7100afb060
void Unk_afb060_call(const Unk_afaef0* self) {
    Unk_afaef0_Set(self);
}

// 0x7100afb130
void Unk_afb130_call(const Unk_afaef0* self) {
    Unk_afaef0_Set(self);
}
