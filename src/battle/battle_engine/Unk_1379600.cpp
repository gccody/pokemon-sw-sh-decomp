// Scope: common
// The table of Unk_2432ae0: the forms and values recorded per species, and
// counts over the table.
#include "battle/battle_engine/Unk_1379600.h"

// 0x7100762fd0 (src/unsorted/leaf/Unk_7626f0.cpp)
u32 Unk_762fd0_call(const Unk_762fd0* self);

// The number of form bits of the species that have more than one (0x7101f342ec).
struct Unk_FormCountEntry {
    u16 field_0;
    u16 field_2;
};
PKMN_SIZE_ASSERT(Unk_FormCountEntry, 0x4);

extern const Unk_FormCountEntry Unk_1f342ec[144];

static u32 Unk_FormCount(u32 species) {
    for (u32 i = 0; i < 144; i++) {
        if (Unk_1f342ec[i].field_0 == species)
            return Unk_1f342ec[i].field_2;
    }
    return 1;
}

// 0x7101379600: split a form bit of species 869 into its two form numbers.
void Unk_1379600(u32 species, u32* form, u32* second) {
    if (species == 869) {
        *second = *form % 7;
        *form /= 7;
    } else {
        *second = 0;
    }
}

// 0x7101379660
u32 Unk_2432ae0::Unk_1379660(u32 species) {
    Unk_2432ae0_Entry* entry = Unk_GetEntry(species);
    if (entry == nullptr)
        return 0;
    return entry->field_24;
}

// 0x71013796b0
void Unk_2432ae0::Unk_13796b0(u32 species) {
    Unk_2432ae0_Entry* entry = Unk_GetEntry(species);
    if (entry != nullptr && entry->field_24 < 999)
        entry->field_24++;
}

// 0x7101379700
void Unk_2432ae0::Unk_1379700(const Unk_762fd0* pokemon, u32 kind) {
    Unk_12f9ef0_Info info;
    Unk_12f9ef0(&info, pokemon);
    if (kind == 1)
        kind = 0;
    else if (kind == 2)
        kind = Unk_1379460(Unk_1379460_Arg(), info.field_0) ? 2 : 0;
    info.field_14 = kind;
    Unk_13797a0(&info, Unk_762fd0_call(pokemon));
}

// 0x71013797a0
void Unk_2432ae0::Unk_13797a0(const Unk_12f9ef0_Info* info, u32 value) {
    if (info->field_d)
        return;
    if (!Unk_1379870(info)) {
        u32 form = Unk_2432ae0_Form(info->field_0, info->field_4, info->field_18);
        Unk_1379170(info->field_0, info->field_8, info->field_c, form, info->field_14);
    }
    Unk_2432ae0_Entry* entry = Unk_GetEntry(info->field_0);
    if (entry == nullptr)
        return;
    entry->field_20_0 = 1;
    entry->field_20_2 |= 1 << Unk_2432ae0_ValueBit(value);
}

// 0x7101379870: record the info's form, and whether the species had any
// before.
bool Unk_2432ae0::Unk_1379870(const Unk_12f9ef0_Info* info) {
    bool before = Unk_1379b90(info->field_0);
    u32 field_8 = info->field_8;
    u8 field_c = info->field_c;
    Unk_2432ae0_Entry* entry = Unk_GetEntry(info->field_0);
    if (entry == nullptr)
        return false;
    u64* bits;
    if (field_8 == 1) {
        if (!field_c)
            bits = &entry->field_0[1];
        else
            bits = &entry->field_0[3];
    } else {
        if (field_c)
            bits = &entry->field_0[2];
        else
            bits = &entry->field_0[0];
    }
    u32 form = Unk_2432ae0_Form(info->field_0, info->field_4, info->field_18);
    if (info->field_14 == 2) {
        *bits |= 1ull << 63;
    } else if (form < Unk_FormCount(info->field_0)) {
        *bits |= 1ull << form;
    }
    return before;
}

// 0x7101379a10
bool Unk_1379a10(u64 self, u32 species) {
    Unk_2432ae0_Entry* entry = reinterpret_cast<Unk_2432ae0*>(self)->Unk_GetEntry(species);
    if (entry == nullptr)
        return false;
    return entry->field_20_0;
}

// 0x7101379a60
u32 Unk_1379a60(u64 self) {
    Unk_2432ae0* table = reinterpret_cast<Unk_2432ae0*>(self);
    u32 count = 0;
    for (int i = 0; i < 400; i++)
        count += table->field_60.field_0[i].field_20_0;
    return count;
}

// 0x7101379aa0
void Unk_2432ae0::Unk_1379aa0(const Unk_762fd0* pokemon, u32 kind) {
    Unk_12f9ef0_Info info;
    Unk_12f9ef0(&info, pokemon);
    if (kind == 1)
        kind = 0;
    else if (kind == 2)
        kind = Unk_1379460(Unk_1379460_Arg(), info.field_0) ? 2 : 0;
    info.field_14 = kind;
    if (info.field_d)
        return;
    if (!Unk_1379870(&info)) {
        u32 form = Unk_2432ae0_Form(info.field_0, info.field_4, info.field_18);
        Unk_1379170(info.field_0, info.field_8, info.field_c, form, info.field_14);
    }
}

// 0x7101379b90: whether the species has any form recorded.
bool Unk_2432ae0::Unk_1379b90(u32 species) {
    Unk_2432ae0_Entry* entry = Unk_GetEntry(species);
    if (entry == nullptr)
        return false;
    for (int i = 0; i < 4; i++) {
        if (entry->field_0[i] != 0)
            return true;
    }
    return false;
}

// 0x7101379c20
u32 Unk_2432ae0::Unk_1379c20() {
    u32 count = 0;
    for (int i = 0; i < 400; i++) {
        const u64* bits = field_60.field_0[i].field_0;
        if (bits[0] != 0 || bits[1] != 0 || bits[2] != 0 || bits[3] != 0)
            count++;
    }
    return count;
}

// 0x7101379c60: whether the info's form is recorded.
bool Unk_2432ae0::Unk_1379c60(const Unk_12f9ef0_Info* info) {
    if (info->field_d)
        return false;
    u32 species = info->field_0;
    u32 form = Unk_2432ae0_Form(info->field_0, info->field_4, info->field_18);
    u32 field_14 = info->field_14;
    u32 field_8 = info->field_8;
    u8 field_c = info->field_c;
    Unk_2432ae0_Entry* entry = Unk_GetEntry(species);
    if (entry == nullptr)
        return false;
    u64* bits;
    if (field_8 == 1) {
        if (!field_c)
            bits = &entry->field_0[1];
        else
            bits = &entry->field_0[3];
    } else {
        if (field_c)
            bits = &entry->field_0[2];
        else
            bits = &entry->field_0[0];
    }
    if (field_14 == 2) {
        if (Unk_1379460(Unk_1379460_Arg(), species) && (*bits & (1ull << 63)) != 0)
            return true;
    } else if ((*bits & (1ull << form)) != 0) {
        return true;
    }
    return false;
}

// 0x7101379d60
bool Unk_2432ae0::Unk_1379d60() {
    for (int i = 0; i < 400; i++) {
        if (!field_60.field_0[i].field_20_0)
            return false;
    }
    return true;
}

// 0x7101379da0
bool Unk_2432ae0::Unk_1379da0() {
    return Unk_1379c20() == 400;
}
