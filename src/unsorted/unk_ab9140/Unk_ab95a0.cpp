// Scope: common
// Getters and setters from the TU(s) of 0x7100ab9140-0x7100abed80, called
// from the Battle Stadium code (game/btl_spot). Their fields overlap from one
// function to the next, so each takes a placeholder type of its own.
// 0x7100ab95d0, 0x7100ab9600 and 0x7100aba2a0-0x7100aba330 are vtable
// slots (tools/vtables.py's).
#include "gflib3/Unk_239a418.h"

struct Unk_ab95a0 {
    u8 _0[0x1d0];
    Unk_239a418* field_1d0;
};
PKMN_OFFSET_ASSERT(Unk_ab95a0, field_1d0, 0x1d0);

// 0x7100ab95a0
Unk_239a418_Ref<Unk_239a418> Unk_ab95a0_get(const Unk_ab95a0* self) {
    return Unk_239a418_Ref<Unk_239a418>(self->field_1d0);
}

struct Unk_ab9780 {
    u8 _0[0x1d8];
    Unk_239a418* field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_ab9780, field_1d8, 0x1d8);

// 0x7100ab9780
Unk_239a418_Ref<Unk_239a418> Unk_ab9780_get(const Unk_ab9780* self) {
    return Unk_239a418_Ref<Unk_239a418>(self->field_1d8);
}

// 0x850 bytes copied as a whole (memcpy)
struct Unk_ab97c0_Data {
    u8 data[0x850];
};

struct Unk_ab97c0 {
    u8 _0[0x1e8];
    Unk_ab97c0_Data field_1e8;
};
PKMN_OFFSET_ASSERT(Unk_ab97c0, field_1e8, 0x1e8);

// 0x7100ab97c0
void Unk_ab97c0_set(Unk_ab97c0* self, const Unk_ab97c0_Data& data) {
    self->field_1e8 = data;
}

// 0x7100ab97d0
Unk_ab97c0_Data Unk_ab97d0_get(const Unk_ab97c0* self) {
    return self->field_1e8;
}

struct Unk_ab9ea0 {
    u8 _0[0xa80];
    bool field_a80;
    u8 _a81[0xf];
    u8 field_a90[0x1];
};
PKMN_OFFSET_ASSERT(Unk_ab9ea0, field_a80, 0xa80);
PKMN_OFFSET_ASSERT(Unk_ab9ea0, field_a90, 0xa90);

// 0x7100ab9ea0
const u8* Unk_ab9ea0_get(const Unk_ab9ea0* self) {
    return self->field_a80 ? self->field_a90 : nullptr;
}

struct Unk_aba260_Pair {
    bool field_0;
    u64 field_8;
};
PKMN_SIZE_ASSERT(Unk_aba260_Pair, 0x10);

struct Unk_aba260 {
    u8 _0[0x18c0];
    Unk_aba260_Pair field_18c0;
    u8 field_18d0;
};
PKMN_OFFSET_ASSERT(Unk_aba260, field_18c0, 0x18c0);
PKMN_OFFSET_ASSERT(Unk_aba260, field_18d0, 0x18d0);

// 0x7100aba260
Unk_aba260_Pair Unk_aba260_get(const Unk_aba260* self) {
    return self->field_18c0;
}

// 0x7100aba270
u8 Unk_aba270_get(const Unk_aba260* self) {
    return self->field_18d0;
}

// 0x7100aba280
void Unk_aba280_clear(Unk_aba260* self) {
    self->field_18c0.field_0 = false;
    self->field_18d0 = 0;
}

struct Unk_abb090 {
    u8 _0[0x18fc];
    bool field_18fc;
};
PKMN_OFFSET_ASSERT(Unk_abb090, field_18fc, 0x18fc);

// 0x7100abb090
void Unk_abb090_set(Unk_abb090* self, bool value) {
    self->field_18fc = value;
}

// 0x7100abb0a0
bool Unk_abb0a0_get(const Unk_abb090* self) {
    return self->field_18fc;
}

struct Unk_15afe30;
struct Unk_15afe30_arg1;
void Unk_15afe30_set(Unk_15afe30* self, const Unk_15afe30_arg1* arg1);

struct Unk_abb0b0 {
    u8 _0[0x1920];
    u8 field_1920[0x70];
    u8 field_1990[0x1];
};
PKMN_OFFSET_ASSERT(Unk_abb0b0, field_1920, 0x1920);
PKMN_OFFSET_ASSERT(Unk_abb0b0, field_1990, 0x1990);

// 0x7100abb0b0
void Unk_abb0b0_set(Unk_abb0b0* self, const Unk_15afe30_arg1* arg1) {
    Unk_15afe30_set(reinterpret_cast<Unk_15afe30*>(self->field_1920), arg1);
}

// 0x7100abb0c0
void Unk_abb0c0_set(Unk_abb0b0* self, const Unk_15afe30_arg1* arg1) {
    Unk_15afe30_set(reinterpret_cast<Unk_15afe30*>(self->field_1990), arg1);
}
