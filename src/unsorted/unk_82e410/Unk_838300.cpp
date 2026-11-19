// Scope: common
// A record of what a move does to up to five battlers, from the TU that
// ends at 0x7100838820 (0x71008384b0-0x71008384e0, its leaf getters, are in
// src/unsorted/leaf): who and what it is about (copied in by 0x71008383b0)
// and an entry per battler: whether it's set, the battler's slot, an id
// (0xea: none) and two values. Placeholder names. Not matched yet:
// 0x71008383b0 (the original merges the entries' reset stores across
// entries) and 0x7100838710 (an id per kind, its switch laid out apart).
#include <types.h>

struct Unk_7ca1c0;
struct Unk_7ee800;
struct Unk_7fe250;
struct Unk_803c70;
struct Unk_8384e0;
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
bool Unk_7ee800_getField273(const Unk_7ee800* self);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
void Unk_803c70_set(Unk_803c70* self);
u8 Unk_8384e0_getField30(const Unk_8384e0* self);
u8 Unk_803790(void* self, u8 index);

struct Unk_8383b0_Entry {
    bool field_0;
    u8 field_1;
    u16 field_2;
    s32 field_4;
    u32 field_8;
};
PKMN_SIZE_ASSERT(Unk_8383b0_Entry, 0xc);

struct Unk_8383b0_Source {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8383b0_Source, field_30, 0x30);

struct Unk_8383b0_Record {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
    Unk_8383b0_Entry field_34[5];
};
PKMN_OFFSET_ASSERT(Unk_8383b0_Record, field_34, 0x34);
PKMN_SIZE_ASSERT(Unk_8383b0_Record, 0x70);

void Unk_837810(Unk_803c70* out, const Unk_8383b0_Record* record);
void Unk_837d10(Unk_803c70* out, const Unk_8383b0_Record* record);
void Unk_838020(Unk_803c70* out, const Unk_8383b0_Record* record);
void Unk_838210(Unk_803c70* out, const Unk_8383b0_Record* record);

// 0x7100838300
void Unk_838300(void* /*self*/, Unk_803c70* out, const Unk_8383b0_Record* record) {
    Unk_803c70_set(out);
    switch (Unk_8384e0_getField30(reinterpret_cast<const Unk_8384e0*>(record))) {
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            Unk_837810(out, record);
            break;
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
            Unk_837d10(out, record);
            break;
        case 35:
        case 36:
        case 37:
        case 39:
        case 40:
        case 42:
        case 43:
            Unk_838210(out, record);
            break;
        case 44:
            Unk_838020(out, record);
            break;
    }
}

// 0x7100838420
bool Unk_838420(const Unk_8383b0_Record* self) {
    if (Unk_7ca1c0_getField150(reinterpret_cast<const Unk_7ca1c0*>(self->field_0)) == 2) {
        u8 kind = self->field_30;
        if (kind <= 0x2c) {
            u64 mask = Unk_7ee800_getField273(reinterpret_cast<const Unk_7ee800*>(self->field_10))
                           ? 0x5b80fff8000
                           : 0x180000007e00;
            return (mask & (1ull << kind)) != 0;
        }
    }
    return false;
}

// 0x71008384f0
u16 Unk_8384f0(const Unk_8383b0_Record* self, u8 index) {
    return self->field_34[index].field_2;
}

// 0x7100838510
s32 Unk_838510(const Unk_8383b0_Record* self, u8 slot) {
    for (u32 i = 0; i < 5; i++)
        if (self->field_34[i].field_1 == slot)
            return self->field_34[i].field_4;
    return 0;
}

// 0x71008385c0
u32 Unk_8385c0(const Unk_8383b0_Record* self, u8 index) {
    return self->field_34[index].field_8;
}

// 0x71008385e0
u8 Unk_8385e0(const Unk_8383b0_Record* self, u8 index) {
    return self->field_34[index].field_1;
}

// 0x7100838600
bool Unk_838600(const Unk_8383b0_Record* self, u8 index) {
    return self->field_34[index].field_0;
}

// 0x7100838620
bool Unk_838620(const Unk_8383b0_Record* self) {
    for (u32 i = 0; i < 5; i++)
        if (self->field_34[i].field_0)
            return true;
    return false;
}

static u8 Unk_838650_Slot(Unk_8383b0_Record* self, u8 index) {
    return Unk_803790(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_8)),
                      index);
}

// 0x7100838650
void Unk_838650(Unk_8383b0_Record* self, u8 index, u16 id) {
    Unk_8383b0_Entry& entry = self->field_34[index];
    entry.field_0 = true;
    entry.field_2 = id;
    entry.field_1 = Unk_838650_Slot(self, index);
}

// 0x71008386a0
void Unk_8386a0(Unk_8383b0_Record* self, u8 index, s32 value) {
    u16 id = value == 0 ? 0xea : value < 0 ? 0x32 : 0x31;
    Unk_8383b0_Entry& entry = self->field_34[index];
    entry.field_0 = true;
    entry.field_2 = id;
    entry.field_1 = Unk_838650_Slot(self, index);
    entry.field_4 = value;
}

// 0x71008387c0
void Unk_8387c0(Unk_8383b0_Record* self, u8 index, u32 value) {
    if (!value)
        return;
    Unk_8383b0_Entry& entry = self->field_34[index];
    entry.field_0 = true;
    entry.field_8 = value;
    entry.field_2 = 0x33;
    entry.field_1 = Unk_838650_Slot(self, index);
}
