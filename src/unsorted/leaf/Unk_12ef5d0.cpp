// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_12ef5d0 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef5d0, field_68, 0x68);

void Unk_15032c0(void*);

// 0x71012ef5d0
void Unk_12ef5d0_call(const Unk_12ef5d0* self) {
    Unk_15032c0(self->field_68);
}

struct Unk_12ef5e0 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef5e0, field_68, 0x68);

void Unk_1505a30(void*);

// 0x71012ef5e0
void Unk_12ef5e0_call(const Unk_12ef5e0* self) {
    Unk_1505a30(self->field_68);
}

struct Unk_12ef5f0 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef5f0, field_68, 0x68);

void Unk_1505cf0(void*);

// 0x71012ef5f0
void Unk_12ef5f0_call(const Unk_12ef5f0* self) {
    Unk_1505cf0(self->field_68);
}

struct Unk_12ef600 {
    u8 _0[0x68];
    Unk_239a418* field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef600, field_68, 0x68);

// 0x71012ef600
void Unk_12ef600_call(Unk_12ef600* self) {
    Unk_239a418* v0 = self->field_68;
    self->field_68 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

struct Unk_12ef620_60 {
    u8 _0[0x48];
    void* field_48;
};
PKMN_OFFSET_ASSERT(Unk_12ef620_60, field_48, 0x48);

struct Unk_12ef620 {
    u8 _0[0x60];
    Unk_12ef620_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_12ef620, field_60, 0x60);

u32 Unk_14db6e0(void*);

// 0x71012ef620
bool Unk_12ef620_call(const Unk_12ef620* self) {
    if (self->field_60->field_48 == nullptr) {
        return false;
    }
    u32 r0 = Unk_14db6e0(self->field_60->field_48);
    return r0 == 0;
}

// 0x71012ef820
void Unk_12ef820_update() {}

struct Unk_12ef830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef830_arg1, field_0, 0x0);

struct Unk_12ef830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef830, field_0, 0x0);

// 0x71012ef830
void Unk_12ef830_set(const Unk_12ef830* self, Unk_12ef830_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ef840_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef840_arg1, field_0, 0x0);

struct Unk_12ef840 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef840, field_0, 0x0);

// 0x71012ef840
void Unk_12ef840_set(const Unk_12ef840* self, Unk_12ef840_arg1* value) {
    value->field_0 = self->field_0;
}
