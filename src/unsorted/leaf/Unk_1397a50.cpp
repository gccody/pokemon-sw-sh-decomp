// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7101397a50
u32 Unk_1397a50() {
    return 0;
}

struct Unk_1399e80 {
    u8 _0[0xa0];
    void* field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1399e80, field_a0, 0xa0);

void Unk_139f9b0(void*);

// 0x7101399e80
void Unk_1399e80_call(const Unk_1399e80* self) {
    if (self->field_a0 != nullptr) {
        Unk_139f9b0(self->field_a0);
    }
}

struct Unk_139a160 {
    u8 _0[0xa8];
    void* field_a8;
};
PKMN_OFFSET_ASSERT(Unk_139a160, field_a8, 0xa8);

void Unk_13a0a70(void*);

// 0x710139a160
void Unk_139a160_call(const Unk_139a160* self) {
    if (self->field_a8 != nullptr) {
        Unk_13a0a70(self->field_a8);
    }
}

struct Unk_139a170 {
    u8 _0[0xa8];
    Unk_239a418* field_a8;
};
PKMN_OFFSET_ASSERT(Unk_139a170, field_a8, 0xa8);

// 0x710139a170
void Unk_139a170_call(Unk_139a170* self) {
    if (self->field_a8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_a8)->vf5();
        self->field_a8 = nullptr;
    }
}
