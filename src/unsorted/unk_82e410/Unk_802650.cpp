// Scope: common
// A record of 0x14f bytes per battle side: four groups of up to 30 Pokemon
// positions with a flag each, a flag and a counter per position, and a list of
// up to 30 positions (0x7100802660 to 0x7100802d4c). Placeholder names:
// rename once the class is known.
#include <types.h>

#include "unsorted/unk_82e410/Unk_802dd0.h"

struct Unk_7ee6b0;

bool Unk_7ed1f0(const Unk_7ecc90_Con* self, u8 pokeId);
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
bool Unk_7ef2b0_call(void* self);
u8 Unk_7cb490(u8 position);

struct Unk_802660_Self {
    struct Group {
        u8 field_0;  // how many of the 30 are used
        u8 field_1[30];
        u8 field_1f[30];

        void clear() {
            field_0 = 0;
            for (u32 i = 0; i < 30; i++) {
                field_1[i] = 0;
                field_1f[i] = 0x1f;
            }
        }
    };

    Group field_0[4];
    u8 field_f4[30];
    u8 field_112[30];
    u8 field_130[30];
    u8 field_14e;  // how many of field_130 are used
};
PKMN_SIZE_ASSERT(Unk_802660_Self::Group, 0x3d);
PKMN_OFFSET_ASSERT(Unk_802660_Self, field_f4, 0xf4);
PKMN_OFFSET_ASSERT(Unk_802660_Self, field_112, 0x112);
PKMN_OFFSET_ASSERT(Unk_802660_Self, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_802660_Self, field_14e, 0x14e);
PKMN_SIZE_ASSERT(Unk_802660_Self, 0x14f);

bool Unk_802940(const Unk_802660_Self* self, u8 value);

// 0x7100802660
void Unk_802660(Unk_802660_Self* self, const Unk_802660_Self* other) {
    *self = *other;
}

// 0x7100802670
void Unk_802670(Unk_802660_Self* self, Unk_7ecc90_Con* con) {
    for (u32 i = 0; i < 4; i++)
        self->field_0[i].clear();
    for (u32 i = 0; i < 30; i++) {
        bool flag = false;
        if (Unk_7ed1f0(con, i))
            flag = Unk_7ef2b0_call(Unk_7ed1e0(con, i));
        self->field_f4[i] = flag;
        self->field_112[i] = 0;
    }
    for (u32 i = 0; i < 30; i++)
        self->field_130[i] = 0x1f;
    self->field_14e = 0;
}

// 0x7100802780
void Unk_802780(Unk_802660_Self* self) {
    for (u32 i = 3; i > 0; i--)
        self->field_0[i] = self->field_0[i - 1];
    self->field_0[0].clear();
    for (u32 i = 0; i < 30; i++)
        self->field_130[i] = 0x1f;
    self->field_14e = 0;
}

// 0x7100802870
void Unk_802870(Unk_802660_Self* self, u8 value) {
    Unk_802660_Self::Group& group = self->field_0[0];
    if (group.field_0 < 30) {
        group.field_1f[group.field_0] = value;
        group.field_1[group.field_0] = 0;
        group.field_0++;
    }
    if (value < 30) {
        self->field_f4[value] = 1;
        if (self->field_112[value] < 100)
            self->field_112[value]++;
    }
}

// 0x71008028d0
void Unk_8028d0(void* self_, u8 value) {
    Unk_802660_Self* self = static_cast<Unk_802660_Self*>(self_);
    if (value >= 30)
        return;
    u8& flag = self->field_f4[value];
    if (flag != 0) {
        flag = 0;
        if (!Unk_802940(self, value) && self->field_14e < 30)
            self->field_130[self->field_14e++] = value;
    }
}

// 0x7100802940
bool Unk_802940(const Unk_802660_Self* self, u8 value) {
    for (u32 i = 0; i < 30; i++) {
        if (self->field_130[i] == value)
            return true;
    }
    return false;
}

// 0x7100802ac0
bool Unk_802ac0(const Unk_802660_Self* self, u8 value) {
    if (value < 30)
        return self->field_f4[value] != 0;
    return false;
}

// 0x7100802af0
u32 Unk_802af0(const Unk_802660_Self* self, u8 side) {
    u32 sum = 0;
    for (u32 i = 0; i < 30; i++) {
        if (Unk_7cb490(i) == side)
            sum += self->field_112[i];
    }
    return sum;
}

// 0x7100802b50
void Unk_802b50(Unk_802660_Self* self, u8 group, u8 index) {
    if (group < 4 && index < self->field_0[group].field_0)
        self->field_0[group].field_1[index] = 1;
}

// 0x7100802b90
u8 Unk_802b90(const Unk_802660_Self* self, u8 group) {
    if (group < 4)
        return self->field_0[group].field_0;
    return 0;
}

// 0x7100802bc0
u8 Unk_802bc0(const Unk_802660_Self* self, u8 group, u8 index) {
    if (group < 4) {
        if (index < self->field_0[group].field_0)
            return self->field_0[group].field_1f[index];
        return 0x1f;
    }
    return 0x1f;
}

// 0x7100802c10
bool Unk_802c10(const Unk_802660_Self* self, u8 group, u8 index) {
    if (group < 4) {
        if (index < self->field_0[group].field_0)
            return self->field_0[group].field_1[index] != 0;
        return false;
    }
    return false;
}

// 0x7100802c60
u8 Unk_802c60(const Unk_802660_Self* self) {
    for (u32 i = 0; i < 4; i++) {
        u8 count = self->field_0[i].field_0;
        if (count != 0) {
            u8 last = count - 1;
            return self->field_0[i].field_1f[last];
        }
    }
    return 0x1f;
}

// 0x7100802cc0
bool Unk_802cc0(const Unk_802660_Self* self, const Unk_802dd0_Self* other) {
    for (u32 i = 0; i < self->field_14e; i++) {
        if (Unk_8034a0(other, Unk_7cb490(self->field_130[i])) != 0)
            return true;
    }
    return false;
}
