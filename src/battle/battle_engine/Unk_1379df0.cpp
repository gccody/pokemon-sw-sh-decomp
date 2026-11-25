// Scope: common
// The rest of Unk_2432ae0: the values and field_20_1 of the table's entries,
// the last species with a form recorded, and the block's other fields.
#include "battle/battle_engine/Unk_1379600.h"

// 0x71007c2280 (as in src/unsorted/Unk_136af10.cpp)
u8 Unk_7c2280();

// 0x7101379df0: whether the species has the value recorded (always, for the
// value 0x71007c2280 gives).
bool Unk_2432ae0::Unk_1379df0(u32 species, u32 value) {
    if (Unk_7c2280() == value)
        return true;
    Unk_2432ae0_Entry* entry = Unk_GetEntry(species);
    if (entry == nullptr)
        return false;
    return (entry->field_20_2 & (1 << Unk_2432ae0_ValueBit(value))) != 0;
}

// 0x7101379eb0: the last species with a form recorded (0 when there's none).
u32 Unk_2432ae0::Unk_1379eb0() {
    for (int i = 399; i >= 0; i--) {
        const u64* bits = field_60.field_0[i].field_0;
        if (bits[0] != 0 || bits[1] != 0 || bits[2] != 0 || bits[3] != 0)
            return Unk_12fa530(i + 1);
    }
    return 0;
}

// 0x7101379ef0
u8 Unk_2432ae0::Unk_1379ef0() {
    return field_60.field_4b02;
}

// 0x7101379f00
void Unk_2432ae0::Unk_1379f00(u8 value) {
    field_60.field_4b02 = value;
}

// 0x7101379f10
void Unk_2432ae0::Unk_1379f10(u8 value) {
    field_60.field_4b03 = value;
}

// 0x7101379f20
u8 Unk_2432ae0::Unk_1379f20() {
    return field_60.field_4b03;
}

// 0x7101379f30
void Unk_1379f30(void* self, u32 species) {
    Unk_2432ae0_Entry* entry = static_cast<Unk_2432ae0*>(self)->Unk_GetEntry(species);
    if (entry == nullptr)
        return;
    if (Unk_1379460(Unk_1379460_Arg(), species))
        entry->field_20_1 = 1;
}

// 0x7101379f90
bool Unk_2432ae0::Unk_1379f90(u32 species) {
    Unk_2432ae0_Entry* entry = Unk_GetEntry(species);
    if (entry == nullptr)
        return false;
    if (!Unk_1379460(Unk_1379460_Arg(), species))
        return false;
    return entry->field_20_1;
}

// 0x710137a010
u32 Unk_2432ae0::Unk_137a010() {
    u32 count = 0;
    for (int i = 0; i < 400; i++) {
        const Unk_2432ae0_Entry& entry = field_60.field_0[i];
        if (entry.field_20_0 && (entry.field_0[2] != 0 || entry.field_0[3] != 0))
            count++;
    }
    return count;
}

// 0x710137a050
bool Unk_2432ae0::Unk_137a050() {
    return field_60.field_4b90;
}

// 0x710137a060
void Unk_2432ae0::Unk_137a060() {
    field_60.field_4b90 = false;
}

// 0x710137a070
Unk_2432ae0_Record* Unk_2432ae0::Unk_137a070(u32 index) {
    if (index > 3)
        index = 0;
    return &field_60.field_4b08[index];
}

// 0x710137a090
u32 Unk_2432ae0::Unk_137a090(u32 index) {
    if (index > 3)
        index = 0;
    return field_60.field_4b08[index].field_1c;
}

// 0x710137a0b0: put the info in the first free record.
bool Unk_2432ae0::Unk_137a0b0(const Unk_12f9ef0_Info* info, u32 value) {
    if (field_60.field_4b90)
        return false;
    for (int i = 0; i < 4; i++) {
        if (field_60.field_4b08[i].field_0.field_0 == 0) {
            field_60.field_4b08[i].field_0 = *info;
            field_60.field_4b08[i].field_1c = value;
            return true;
        }
    }
    return false;
}

// 0x710137a170
void Unk_2432ae0::Unk_137a170(u64 value) {
    if (!field_60.field_4b90) {
        field_60.field_4b88 = value;
        field_60.field_4b90 = true;
    }
}
