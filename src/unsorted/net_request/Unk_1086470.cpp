// Scope: common
// A stored callback called with a value read from a second object, and the
// copy and destruction of a pair of references. Placeholder types: rename and
// move once the owning classes are known.
#include <new>

#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1086b30_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg, u64* value);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_1086b30_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1086b30_Target, field_80, 0x80);

struct Unk_1086b30_Source {
    u8 field_0[0x978];
    u64 field_978;
};
PKMN_OFFSET_ASSERT(Unk_1086b30_Source, field_978, 0x978);

struct Unk_1086b30 {
    Unk_1086b30_Target* field_0;
    Unk_1086b30_Source* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1086b30, field_8, 0x8);

// 0x7101086b30
void Unk_1086b30_call(Unk_1086b30* self) {
    Unk_1086b30_Target* target = self->field_0;
    u64 value = self->field_8->field_978;
    target->field_60(target->field_80, &value);
}

class Unk_1086b70_Object : public Unk_239a418 {};

// Two references, dropped in reverse order. The copy tests the pointer it
// stored (Unk_239a418_Ref2), not the source's again.
struct Unk_1086b70 {
    ~Unk_1086b70();

    Unk_239a418_Ref2<Unk_1086b70_Object> field_0;
    Unk_239a418_Ref2<Unk_1086b70_Object> field_8;
};
static_assert(sizeof(Unk_1086b70) == 0x10, "Unk_1086b70");
PKMN_OFFSET_ASSERT(Unk_1086b70, field_8, 0x8);

// 0x7101086b70
Unk_1086b70::~Unk_1086b70() = default;

// 0x7101086bc0
void Unk_1086bc0_copy(const Unk_1086b70* self, Unk_1086b70* out) {
    new (out) Unk_1086b70(*self);
}
