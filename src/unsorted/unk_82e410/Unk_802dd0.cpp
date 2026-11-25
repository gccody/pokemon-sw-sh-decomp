// Scope: common
// The five entries and Pokemon id table of src/unsorted/unk_82e410/Unk_802dd0.h:
// setting them up from the battle's positions, assigning, swapping and
// counting them. Placeholder names: rename once the class is known.
#include "unsorted/unk_82e410/Unk_802dd0.h"

#include <cstring>

struct Unk_7ee6b0;
struct Unk_7cac30;
struct Unk_7cad30;
struct Unk_7c2d80_Main;

u8 Unk_7cac30_call(const Unk_7cac30* self);
bool Unk_7cad30_call(const Unk_7cad30* self, u32 position);
u8 Unk_7cb660(void* self, u8 position);
void Unk_7cae30(const Unk_7c2d80_Main* self, u8 position, u8* client, u8* index);
bool Unk_7cbf80(void* self, u8 pokeId, u8 otherId);
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId);
Unk_7ee6b0* Unk_7ed1c0(Unk_7ecc90_Con* self, u8 client, u8 index);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
bool Unk_7ef2b0_call(void* self);
void Unk_7ef380(Unk_7ee6b0* self, u8 pokeId);

// 0x7100802dd0
void Unk_802dd0(Unk_802dd0_Self* self) {
    self->field_30 = self->field_f;
    self->field_3c = 0;
    self->field_38 = 30;
}

// 0x7100802df0
void Unk_802df0(Unk_802dd0_Self* self, const Unk_802dd0_Self* other) {
    std::memcpy(self->field_0, other->field_0, sizeof(self->field_0));
    std::memcpy(self->field_f, other->field_f, sizeof(self->field_f));
}

// 0x7100802e30
void Unk_802e30(Unk_802dd0_Self* self, void* main, Unk_7ecc90_Con* con) {
    for (u32 i = 0; i < 5; i++) {
        self->field_0[i].field_0 = 0;
        self->field_0[i].field_1 = 5;
        self->field_0[i].field_2 = 0x1f;
    }
    for (u32 i = 0; i < self->field_38; i++)
        self->at(i) = 5;

    u8 last = Unk_7cac30_call(static_cast<const Unk_7cac30*>(main));
    u32 count = last + 1;
    for (u32 i = 0; i < count; i++) {
        if (!Unk_7cad30_call(static_cast<const Unk_7cad30*>(main), i))
            continue;
        Unk_802dd0_Self::Entry& entry = self->field_0[i];
        if (entry.field_0 != 0)
            continue;
        u8 kind = Unk_7cb660(main, i);
        if (kind == 5)
            continue;
        entry.field_0 = 1;
        entry.field_1 = kind;
        entry.field_2 = 0x1f;
    }

    for (u32 i = 0; i < count; i++) {
        u8 client;
        u8 index;
        Unk_7cae30(static_cast<const Unk_7c2d80_Main*>(main), i, &client, &index);
        if (client == 5)
            continue;
        Unk_7ee6b0* poke = Unk_7ed1c0(con, client, index);
        if (poke == nullptr || Unk_7ef2b0_call(poke)) {
            self->field_0[i].field_2 = 0x1f;
        } else {
            u8 pokeId = Unk_7ee6b0_getField7d(poke);
            self->field_0[i].field_2 = pokeId;
            self->at(pokeId) = i;
        }
    }
}

// 0x7100802ff0
void Unk_802ff0(void* self_, u8 pokeId) {
    Unk_802dd0_Self* self = static_cast<Unk_802dd0_Self*>(self_);
    for (u32 i = 0; i < 5; i++) {
        Unk_802dd0_Self::Entry& entry = self->field_0[i];
        if (entry.field_0 != 0 && entry.field_2 == pokeId) {
            entry.field_2 = 0x1f;
            return;
        }
    }
}

// 0x7100803080
void Unk_803080(Unk_802dd0_Self* self, void* main, u8 index, u8 pokeId, Unk_7ecc90_Con* con) {
    self->field_0[index].field_2 = pokeId;
    self->at(pokeId) = index;
    Unk_8030d0(self, main, index, con);
}

// 0x71008030d0
void Unk_8030d0(Unk_802dd0_Self* self, void* main, u8 index, Unk_7ecc90_Con* con) {
    u8 pokeId = self->field_0[index].field_2;
    if (pokeId == 0x1f)
        return;
    for (u32 i = 0; i < 5; i++) {
        const Unk_802dd0_Self::Entry& entry = self->field_0[i];
        if (entry.field_0 == 0 || entry.field_2 == 0x1f || entry.field_2 == pokeId)
            continue;
        if (Unk_7cbf80(main, entry.field_2, pokeId))
            continue;
        Unk_7ef380(Unk_7ecc90(con, entry.field_2), pokeId);
        Unk_7ef380(Unk_7ecc90(con, pokeId), entry.field_2);
    }
}

// 0x71008032d0
void Unk_8032d0(Unk_802dd0_Self* self, u8 a, u8 b) {
    Unk_802dd0_Self::Entry entry = self->field_0[a];
    self->field_0[a] = self->field_0[b];
    self->field_0[b] = entry;
    if (self->field_0[a].field_2 != 0x1f)
        self->at(self->field_0[a].field_2) = a;
    if (self->field_0[b].field_2 != 0x1f)
        self->at(self->field_0[b].field_2) = b;
}

// 0x7100803390
u8 Unk_803390(const Unk_802dd0_Self* self, u8 kind, u8* out) {
    u8 count = 0;
    for (u32 i = 0; i < 5; i++) {
        const Unk_802dd0_Self::Entry& entry = self->field_0[i];
        if (entry.field_0 != 0 && entry.field_1 == kind && entry.field_2 == 0x1f)
            out[count++] = i;
    }
    return count;
}

// 0x71008034a0
u8 Unk_8034a0(const Unk_802dd0_Self* self, u8 kind) {
    u8 count = 0;
    for (u32 i = 0; i < 5; i++) {
        const Unk_802dd0_Self::Entry& entry = self->field_0[i];
        if (entry.field_0 != 0 && entry.field_1 == kind && entry.field_2 == 0x1f)
            count++;
    }
    return count;
}

// NON_MATCHING: block layout: the original returns true right after each
// entry's check, with its own `mov w0, #1; ret`; this shares one return block.
// 0x7100803560
bool Unk_803560(void* self_, u8 pokeId) {
    const Unk_802dd0_Self* self = static_cast<const Unk_802dd0_Self*>(self_);
    for (u32 i = 0; i < 5; i++) {
        const Unk_802dd0_Self::Entry& entry = self->field_0[i];
        if (entry.field_0 != 0 && entry.field_2 == pokeId)
            return true;
    }
    return false;
}
