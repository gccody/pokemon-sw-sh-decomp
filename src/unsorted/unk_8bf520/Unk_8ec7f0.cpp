// Scope: common
// Setters of small records, in the TU of 0x71008ec7f0-0x71008ecc80. Each
// clears the record, stores its values, then sets the record's first flag.
// Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ec800_Value {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_SIZE_ASSERT(Unk_8ec800_Value, 0x28);

struct Unk_8ec800 {
    u8 _0[0x20];
    u32 field_20;
    u8 _24[0x4];
    Unk_8ec800_Value field_28;
    u32 field_50;
    bool field_54;
};
PKMN_OFFSET_ASSERT(Unk_8ec800, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec800, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec800, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_8ec800, field_54, 0x54);

// 0x71008ec800
void Unk_8ec800_set(Unk_8ec800* self, const Unk_8ec800_Value* value) {
    self->field_20 = 0;
    self->field_50 = 0;
    self->field_54 = false;
    self->field_28 = *value;
    self->field_54 = true;
}

struct Unk_8ec850_Value {
    u8 field_0;
    u8 field_1;
    u8 field_2;
};
PKMN_SIZE_ASSERT(Unk_8ec850_Value, 0x3);

struct Unk_8ec850_Entry {
    u8 field_0;
    Unk_8ec850_Value field_1;
};
PKMN_SIZE_ASSERT(Unk_8ec850_Entry, 0x4);

struct Unk_8ec850_Flags {
    bool field_0;
    bool field_1;
};
PKMN_SIZE_ASSERT(Unk_8ec850_Flags, 0x2);

struct Unk_8ec850 {
    u8 _0[0x20];
    u64 field_20;
    Unk_8ec850_Entry field_28;
    u8 _2c[0x4];
    u64 field_30;
    Unk_8ec850_Flags field_38;
};
PKMN_OFFSET_ASSERT(Unk_8ec850, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec850, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec850, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_8ec850, field_38, 0x38);

// 0x71008ec850
// NON_MATCHING: the 3-byte copy loads its two halves in the other order.
void Unk_8ec850_set(Unk_8ec850* self, u64 arg1, u8 arg2, const Unk_8ec850_Value* arg3, u64 arg4) {
    self->field_20 = 0;
    self->field_30 = 0;
    self->field_38 = Unk_8ec850_Flags();
    self->field_28 = Unk_8ec850_Entry();
    self->field_20 = arg1;
    self->field_28.field_0 = arg2;
    self->field_28.field_1 = *arg3;
    self->field_30 = arg4;
    self->field_38.field_0 = true;
}

struct Unk_8ec8c0_Flags {
    bool field_0;
    bool field_1;
    bool field_2;
};
PKMN_SIZE_ASSERT(Unk_8ec8c0_Flags, 0x3);

struct Unk_8ec8c0 {
    u8 _0[0x20];
    u64 field_20;
    u8 field_28;
    u8 _29[0x7];
    u64 field_30;
    Unk_8ec8c0_Flags field_38;
};
PKMN_OFFSET_ASSERT(Unk_8ec8c0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec8c0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec8c0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_8ec8c0, field_38, 0x38);

// 0x71008ec8c0
void Unk_8ec8c0_set(Unk_8ec8c0* self, u8 arg1, u64 arg2, u64 arg3) {
    self->field_38 = Unk_8ec8c0_Flags();
    self->field_20 = arg2;
    self->field_28 = arg1;
    self->field_30 = arg3;
    self->field_38.field_0 = true;
}

struct Unk_8ec910_State {
    u16 field_0;
    u8 field_2;
    u8 field_3;
    bool field_4;
    bool field_5;
    u8 field_6;
    u8 field_7;
};
PKMN_SIZE_ASSERT(Unk_8ec910_State, 0x8);

struct Unk_8ec910_Record {
    u8 _0[0x20];
    u8 field_20;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    u8 field_24;
    u8 _25;
    Unk_8ec910_State field_26;
};
PKMN_OFFSET_ASSERT(Unk_8ec910_Record, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec910_Record, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_8ec910_Record, field_26, 0x26);

// 0x71008ec910
// The existing name gives the record and the five bytes as unsigned long.
void Unk_8ec910(unsigned long self,
                unsigned long arg1,
                unsigned long arg2,
                unsigned long arg3,
                unsigned long arg4,
                unsigned long arg5) {
    Unk_8ec910_Record* record = reinterpret_cast<Unk_8ec910_Record*>(self);
    record->field_26 = Unk_8ec910_State();
    record->field_20 = arg1;
    record->field_21 = arg2;
    record->field_22 = arg3;
    record->field_23 = arg4;
    record->field_24 = arg5;
    record->field_26.field_4 = true;
}
