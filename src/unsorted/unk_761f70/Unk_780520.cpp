// Scope: common
// Small Pokémon rules: a gender from a species' gender ratio, its ability
// slots, the hidden power type of a set of IVs, whether two Pokémon can breed
// and the forms that held items give (the item tables are at 0x7101f0c728,
// 0x7101f0c76c and 0x7101f0c7b0). Placeholder names: rename once the owning
// classes are known.
#include <types.h>

// Selects the personal data of a species' form (src/battle/battle_engine/
// Unk_7ee6b0.h).
void Unk_76bc60(u16 species, u8 form);
// Reads a field of the selected personal data.
u32 Unk_76bc80(u32 param);

// The hidden power types, by the hidden power index.
extern const u8 Unk_1b13e60[] __attribute__((visibility("hidden")));
extern const u32 Unk_1f0c51c[][5] __attribute__((visibility("hidden")));
extern const u32 Unk_1f0c710[] __attribute__((visibility("hidden")));

// An entry of the item -> form tables.
struct Unk_1f0c728_Entry {
    u16 field_0;
    u8 field_2;
    u8 field_3;
};
static_assert(sizeof(Unk_1f0c728_Entry) == 4, "Unk_1f0c728_Entry");

extern const Unk_1f0c728_Entry Unk_1f0c728[17] __attribute__((visibility("hidden")));
extern const Unk_1f0c728_Entry Unk_1f0c76c[17] __attribute__((visibility("hidden")));
extern const Unk_1f0c728_Entry Unk_1f0c7b0[7] __attribute__((visibility("hidden")));

// 0x7100780520
u32 Unk_780520(u16 species, u8 form, u32 gender) {
    Unk_76bc60(species, form);
    switch (static_cast<u8>(Unk_76bc80(0x14))) {
        case 0:
            return 0;
        case 0xfe:
            return 1;
        case 0xff:
            return 2;
    }
    return gender == 2 ? 0 : gender;
}

// 0x7100780580
// NON_MATCHING: matches, but functions.csv names it _Z10Unk_780580v (its caller,
// src/unsorted/leaf/Unk_7626f0.cpp, passes the value on in w0): rename it
// _Z10Unk_780580j.
bool Unk_780580(u32 value) {
    switch (value) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 19:
        case 22:
        case 24:
            return true;
    }
    return false;
}

// 0x71007805b0
// NON_MATCHING: matches, but functions.csv names it _Z10Unk_7805b0v (see
// Unk_780580): rename it _Z10Unk_7805b0j.
bool Unk_7805b0(u32 value) {
    switch (value) {
        case 1:
        case 5:
        case 7:
        case 10:
        case 12:
        case 15:
        case 16:
        case 17:
        case 18:
        case 20:
        case 21:
        case 23:
            return true;
    }
    return false;
}

// 0x7100780620
u32 Unk_780620(u16 species, u8 form, u8 slot) {
    u32 param = slot == 2 ? 0x1c : slot == 1 ? 0x1b : 0x1a;
    Unk_76bc60(species, form);
    return static_cast<u16>(Unk_76bc80(param));
}

// 0x7100780670
// NON_MATCHING: the original takes the index modulo 16 as q - q / 16 * 16 (with
// the subtraction in 64 bits, from the table address); this masks it with ubfx.
u8 Unk_780670(u32 hp, u32 attack, u32 defense, u32 speed, u32 spAttack, u32 spDefense) {
    u32 bits = (hp & 1) | (attack & 1) << 1 | (defense & 1) << 2 | (speed & 1) << 3 |
               (spAttack & 1) << 4 | (spDefense & 1) << 5;
    return Unk_1b13e60[bits * 15 / 63 % 16];
}

// 0x71007806e0
u32 Unk_7806e0(u32 row, u32 column) {
    return Unk_1f0c51c[row][column];
}

// 0x7100780700
bool Unk_780700(u32 species1,
                u32 gender1,
                u32 eggGroup1a,
                u32 eggGroup1b,
                u32 species2,
                u32 gender2,
                u32 eggGroup2a,
                u32 eggGroup2b) {
    if (eggGroup1a == 15 || eggGroup1b == 15 || eggGroup2a == 15 || eggGroup2b == 15)
        return false;
    if (species1 == 0x84 && species2 == 0x84)
        return false;
    if (species1 == 0x84 || species2 == 0x84)
        return true;
    if (gender1 == gender2)
        return false;
    if (gender1 == 2 || gender2 == 2)
        return false;
    return eggGroup1a == eggGroup2a || eggGroup1a == eggGroup2b || eggGroup1b == eggGroup2a ||
           eggGroup1b == eggGroup2b;
}

// 0x71007807b0
u8 Unk_7807b0(u32 a1, u32 b1, u32 a2, u32 b2) {
    if (a1 == a2)
        return b1 == b2;
    return b1 == b2 ? 2 : 1;
}

// 0x71007807d0
u32 Unk_7807d0(u16 index) {
    if (index > 5)
        return 0;
    return Unk_1f0c710[index];
}

// 0x7100780800
// The original is probably a search of a constant table of this TU (the item
// and the form of each entry: Unk_1f0c728), unrolled into this switch.
u8 Unk_780800(s32 item) {
    u64 index;
    switch (item) {
        case 0x12a:
            index = 0;
            break;
        case 0x12b:
            index = 1;
            break;
        case 0x12c:
            index = 2;
            break;
        case 0x12d:
            index = 3;
            break;
        case 0x12e:
            index = 4;
            break;
        case 0x12f:
            index = 5;
            break;
        case 0x130:
            index = 6;
            break;
        case 0x131:
            index = 7;
            break;
        case 0x132:
            index = 8;
            break;
        case 0x133:
            index = 9;
            break;
        case 0x134:
            index = 10;
            break;
        case 0x135:
            index = 11;
            break;
        case 0x136:
            index = 12;
            break;
        case 0x137:
            index = 13;
            break;
        case 0x138:
            index = 14;
            break;
        case 0x139:
            index = 15;
            break;
        case 0x284:
            index = 16;
            break;
        default:
            return 0;
    }
    return Unk_1f0c728[index].field_2;
}

// 0x71007808d0
u8 Unk_7808d0(s32 item) {
    u64 index;
    switch (item) {
        case 0x388:
            index = 5;
            break;
        case 0x389:
            index = 8;
            break;
        case 0x38a:
            index = 6;
            break;
        case 0x38b:
            index = 7;
            break;
        case 0x38c:
            index = 11;
            break;
        case 0x38d:
            index = 10;
            break;
        case 0x38e:
            index = 12;
            break;
        case 0x38f:
            index = 15;
            break;
        case 0x390:
            index = 0;
            break;
        case 0x391:
            index = 1;
            break;
        case 0x392:
            index = 3;
            break;
        case 0x393:
            index = 2;
            break;
        case 0x394:
            index = 9;
            break;
        case 0x395:
            index = 4;
            break;
        case 0x396:
            index = 13;
            break;
        case 0x397:
            index = 14;
            break;
        case 0x398:
            index = 16;
            break;
        default:
            return 0;
    }
    return Unk_1f0c76c[index].field_2;
}

// 0x7100780910
u8 Unk_780910(u32 item) {
    u32 index = item - 0x455;
    if (index < 7)
        return Unk_1f0c7b0[index].field_2;
    return 0;
}

// Genesect's form from its drive.
inline u8 Unk_780940_Drive(s32 item) {
    switch (item) {
        case 0x74:
            return 1;
        case 0x75:
            return 2;
        case 0x76:
            return 3;
        case 0x77:
            return 4;
    }
    return 0;
}

// 0x7100780940
// NON_MATCHING: the original sets the plate table's address once, in a block
// all the plates' cases branch to; this copies it into each case. Genesect's
// form is d < 4 ? d + 1 : 0 there (csinc), item - 0x73 (csel) here.
bool Unk_780940(s32 species, s32 item, u16* form) {
    *form = 0;
    switch (species) {
        case 0x1e7:
            *form = item == 0;
            return true;
        case 0x1ed:
            *form = Unk_780800(item);
            return true;
        case 0x289:
            *form = Unk_780940_Drive(item);
            return true;
        case 0x305:
            *form = Unk_7808d0(item);
            return true;
    }
    return false;
}
