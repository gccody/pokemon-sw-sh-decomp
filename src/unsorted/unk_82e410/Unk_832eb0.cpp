// Scope: common
// A table of 30 values with a flag each, from the TU of
// 0x7100832c60-0x7100832f70: its initialisers (0x7100832cb0, 0x7100832db0,
// which set every value to 0xe) are leaf functions
// (src/unsorted/leaf/Unk_832cb0.cpp); these are its getters (its setter,
// 0x7100832eb0, isn't matched yet: the original indexes it in two steps).
#include <types.h>

struct Unk_832eb0_Entry {
    u32 field_0;
    u8 field_4;
};
PKMN_SIZE_ASSERT(Unk_832eb0_Entry, 0x8);

struct Unk_832eb0_Table {
    Unk_832eb0_Entry field_0[30];
};
PKMN_SIZE_ASSERT(Unk_832eb0_Table, 0xf0);

// 0x7100832ee0
u32 Unk_832ee0(const Unk_832eb0_Table* self, u8 index) {
    if (index < 30)
        return self->field_0[index].field_0;
    return 7;
}

// 0x7100832f10
u32 Unk_832f10(const Unk_832eb0_Table* self, u8 index) {
    if (index < 30)
        return self->field_0[index].field_0;
    return 0xe;
}

// 0x7100832f40
bool Unk_832f40(const Unk_832eb0_Table* self, u8 index) {
    if (index < 30)
        return self->field_0[index].field_4 != 0;
    return false;
}
