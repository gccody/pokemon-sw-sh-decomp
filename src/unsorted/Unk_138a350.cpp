// Scope: common
// A history of 50 records, newest first: adding one moves the others up.
// Placeholder names: nothing names the class or its records.
#include <algorithm>

#include <types.h>

// 0x20 bytes, copied as a block
struct Unk_138a350_Block {
    u64 field_0[4];
};

// 0x68 bytes: its three blocks are copied one by one
struct Unk_138a350_Record {
    Unk_138a350_Record& operator=(const Unk_138a350_Record& other) {
        field_0 = other.field_0;
        field_8 = other.field_8;
        field_28 = other.field_28;
        field_48 = other.field_48;
        return *this;
    }

    u64 field_0;
    Unk_138a350_Block field_8;
    Unk_138a350_Block field_28;
    Unk_138a350_Block field_48;
};
PKMN_SIZE_ASSERT(Unk_138a350_Record, 0x68);

struct Unk_138a350_History {
    u8 _0[0x60];
    Unk_138a350_Record field_60[50];
};
PKMN_OFFSET_ASSERT(Unk_138a350_History, field_60, 0x60);
PKMN_SIZE_ASSERT(Unk_138a350_History, 0x14b0);

// 0x710138a350 (Shield: 0x710138a380)
// NON_MATCHING: the same 1,245 instructions but for one copy. The copy loop is
// unrolled into one block of 637 loads and stores, and the scheduler lets the
// store of record 38's field_0 float: the original keeps it until the end of
// the function, this stores it 512 instructions after its load and lets a
// second store (record 19's last word) float instead. One more store after the
// last assignment gives the original's order, so something there differs.
void Unk_138a350(Unk_138a350_History* self, const Unk_138a350_Record* record) {
    std::copy_backward(self->field_60, self->field_60 + 49, self->field_60 + 50);
    self->field_60[0] = *record;
}
