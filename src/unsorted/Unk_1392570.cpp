// Scope: common
// Another block of the scrambled block store (src/unsorted/families/
// Unk_13471e0.h), 0x3208 bytes: read and written through two template
// instantiations of their own (Unk_1392b10_T, Unk_1392430_T). And the
// constructor of Unk_24331b0 (src/unsorted/Unk_1392d70.h). Placeholder names:
// rename once the classes are known.
#include "unsorted/Unk_1392d70.h"

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The block's key in the store.
extern const u32 Unk_1f346f4 __attribute__((visibility("hidden")));

u8 Unk_7c2280();

// The block as it's read.
struct Unk_1392b10_T {
    u8 _0[0x3208];
};
PKMN_SIZE_ASSERT(Unk_1392b10_T, 0x3208);

// An entry of the block as it's written (cleared).
struct Unk_1392430_Entry {
    Unk_1392430_Entry()
        : field_0(Unk_7c2280()),
          field_2(),
          field_20(0),
          field_28(0),
          field_30(0),
          field_38(),
          field_58(0),
          field_60(),
          field_70() {}

    u8 field_0;
    u16 field_2[13];
    u64 field_20;
    u64 field_28;
    u16 field_30;
    u64 field_38[4];
    u32 field_58;
    u64 field_60[2];
    u64 field_70[2];
};
PKMN_SIZE_ASSERT(Unk_1392430_Entry, 0x80);
PKMN_OFFSET_ASSERT(Unk_1392430_Entry, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_1392430_Entry, field_58, 0x58);

// The block as it's written.
struct Unk_1392430_T {
    Unk_1392430_T() : field_3200(0) {}

    Unk_1392430_Entry field_0[100];
    u8 field_3200;
};
PKMN_SIZE_ASSERT(Unk_1392430_T, 0x3208);
PKMN_OFFSET_ASSERT(Unk_1392430_T, field_3200, 0x3200);

// 0x7101392570
// NON_MATCHING: the original tests the result's flag as a byte (tst #0xff),
// as if Unk_1346860_Result::field_0 were a u8, not the header's bool.
void Unk_1392570(Unk_1392b10_T* data) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    u64 size = sizeof(*data);
    if (!store->Unk_1346030(Unk_1f346f4, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f346f4);
}

// Writes the block (inlined).
static void Unk_Write(Unk_1392430_T* data) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    u64 size = sizeof(*data);
    store->Unk_13456e0(Unk_1f346f4, data, size);
}

// 0x71013925f0: writes a cleared block.
// NON_MATCHING: the original zeroes each entry's +0x60 before its +0x70; here
// they're stored the other way round (every layout of +0x60..0x80 tried).
void Unk_13925f0() {
    Unk_1392430_T block;
    Unk_Write(&block);
}

// 0x7101392d30
Unk_24331b0::Unk_24331b0() {}
