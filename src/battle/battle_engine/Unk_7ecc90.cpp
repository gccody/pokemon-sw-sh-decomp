// Scope: common
// The battle's Pokemon (0x71007ecc90 to 0x71007ed710, the end of the event
// system's TU): the party of each client, and every Pokemon by id.
// Placeholder names: rename once the class is known.
#include "battle/battle_engine/Unk_7fc210.h"
#include "battle/battle_engine/Unk_8139c0.h"

struct Unk_7c2d80_Main;

struct Unk_7ecc90_Con {
    const Unk_7c2d80_Main* field_0;
    Unk_7fc430_Party field_8[5];
    Unk_7ee6b0* field_120[0x1e];
};
PKMN_OFFSET_ASSERT(Unk_7ecc90_Con, field_120, 0x120);

u8 Unk_7fc5b0(Unk_7fc430_Party* self);
struct Unk_7fc2e0;
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_7ef360(const Unk_7ee6b0* self);
void Unk_7ef340(Unk_7ee6b0* self, u8 pokeId);
u8 Unk_804820(u32 client, u8 index);
void Unk_7cae30(const Unk_7c2d80_Main* self, u8 position, u8* client, u8* index);

static inline u8 Unk_7ecc90_Count(const Unk_7fc430_Party* party) {
    return Unk_7fc2e0_getField30(reinterpret_cast<const Unk_7fc2e0*>(party));
}

// The Pokemon at a position, if any.
static inline Unk_7ee6b0* Unk_7ecc90_At(Unk_7ecc90_Con* self, u8 position) {
    u8 client;
    u8 index;
    Unk_7cae30(self->field_0, position, &client, &index);
    if (client == 5)
        return nullptr;
    Unk_7fc430_Party* party = &self->field_8[client];
    u8 count = Unk_7ecc90_Count(party);
    if (index < count)
        return Unk_7fc450(party, index);
    return nullptr;
}

// 0x71007ecc90
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId) {
    return self->field_120[pokeId];
}

// 0x71007ecfd0
void Unk_7ecfd0(Unk_7ecc90_Con* self, u8 client) {
    Unk_7fc430_Party* party = &self->field_8[client];
    u8 count = Unk_7fc5b0(party);
    for (u32 i = 0; i != count; i++) {
        u8 pokeId = Unk_804820(client, i);
        if (Unk_7eef50(self->field_120[pokeId], 0x13) == 0x95) {
            u8 other = Unk_7ee6b0_getField7d(Unk_7fc450(party, count));
            Unk_7ef340(self->field_120[pokeId], other);
        }
    }
}

// 0x71007ed1a0
Unk_7fc430_Party* Unk_7ed1a0(Unk_7ecc90_Con* self, u32 client) {
    return &self->field_8[client];
}

// 0x71007ed1b0
const Unk_7fc430_Party* Unk_7ed1b0(const Unk_7ecc90_Con* self, u32 client) {
    return &self->field_8[client];
}

// 0x71007ed1c0
Unk_7ee6b0* Unk_7ed1c0(Unk_7ecc90_Con* self, u8 client, u8 index) {
    return Unk_7fc450(&self->field_8[client], index);
}

// 0x71007ed1e0
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId) {
    return self->field_120[pokeId];
}

// 0x71007ed1f0
bool Unk_7ed1f0(const Unk_7ecc90_Con* self, u8 pokeId) {
    if (pokeId < 30)
        return self->field_120[pokeId] != nullptr;
    return false;
}

// 0x71007ed220
Unk_7ee6b0* Unk_7ed220(Unk_7ecc90_Con* self, u8 pokeId) {
    return self->field_120[Unk_7ef360(self->field_120[pokeId])];
}

// 0x71007ed4d0
s32 Unk_7ed4d0(Unk_7ecc90_Con* self, u8 client, u8 pokeId) {
    Unk_7fc430_Party* party = &self->field_8[client];
    u8 count = Unk_7ecc90_Count(party);
    for (u32 i = 0; i < count; i++) {
        if (Unk_7ee6b0_getField7d(Unk_7fc450(party, i)) == pokeId)
            return i;
    }
    return -1;
}

// 0x71007ed560
Unk_7ee6b0* Unk_7ed560(Unk_7ecc90_Con* self, u8 position) {
    return Unk_7ecc90_At(self, position);
}

// 0x71007ed5e0
Unk_7ee6b0* Unk_7ed5e0(Unk_7ecc90_Con* self, u8 position) {
    return Unk_7ecc90_At(self, position);
}

// 0x71007ed660
u8 Unk_7ed660(Unk_7ecc90_Con* self, u8 position) {
    Unk_7ee6b0* poke = Unk_7ecc90_At(self, position);
    if (poke == nullptr)
        return 0x1f;
    return Unk_7ee6b0_getField7d(poke);
}

// 0x71007ed6f0
const Unk_7ee6b0* Unk_7ed6f0(const Unk_7ecc90_Con* self, u8 client, u8 index) {
    return Unk_7fc430(&self->field_8[client], index);
}
