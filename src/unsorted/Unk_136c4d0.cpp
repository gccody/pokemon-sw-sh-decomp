// Scope: common
#include "unsorted/Unk_136c4d0.h"

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The block's key in the store.
extern const u32 Unk_1f340a8;

extern const u32 Unk_1f340d0[] __attribute__((visibility("hidden")));

static const u64 kMagic = 0x0cf9069c673b98d1;

// 0x710136c610
// NON_MATCHING: the original tests the result's flag as a byte (tst #0xff),
// as if Unk_1346860_Result::field_0 were a u8, not the header's bool.
void Unk_2432608::vf8() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_136c4d0_T* data = &field_60;
    u64 size = sizeof(field_60);
    if (!store->Unk_1346030(Unk_1f340a8, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f340a8);
}

// 0x710136c6a0
void Unk_2432608::vf9() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_136c4d0_T* data = &field_60;
    u64 size = sizeof(field_60);
    store->Unk_13456e0(Unk_1f340a8, data, size);
}

// 0x710136c700
u32 Unk_2432608::Unk_136c700(const int& index) {
    return Unk_1f340d0[index];
}

// 0x710136c720
void Unk_2432608::Unk_136c720(const int& index, const Unk_136c4d0_Key& value) {
    field_60.field_0[index].field_0 = value;
}

// 0x710136c740
void Unk_2432608::Unk_136c740(const int& index, const u64& value) {
    field_60.field_0[index].field_8 = value;
}

// 0x710136c760
void Unk_2432608::Unk_136c760(const int& index, const u8& value) {
    field_60.field_0[index].field_10 = value;
}

// 0x710136c780
void Unk_2432608::Unk_136c780(const int& index, const u8& value) {
    field_60.field_0[index].field_11 = value;
}

// 0x710136c7a0
void Unk_2432608::Unk_136c7a0(const int& index, const int& value) {
    field_60.field_0[index].field_12 = value;
    if (value == 0)
        field_60.field_0[index].field_13_1 = false;
}

// 0x710136c7e0
void Unk_2432608::Unk_136c7e0(const int& index, const bool& value) {
    field_60.field_0[index].field_13_1 = value;
}

// 0x710136c810
int Unk_2432608::Unk_136c810(const int& index) {
    return field_60.field_0[index].field_12;
}

// 0x710136c830
void Unk_2432608::Unk_136c830(const int& index, const bool& value) {
    field_60.field_0[index].field_13_0 = value;
}

// 0x710136c860
bool Unk_2432608::Unk_136c860(const int& index) {
    return field_60.field_0[index].field_13_0;
}

// 0x710136c880
bool Unk_2432608::Unk_136c880(const int& index) {
    return field_60.field_0[index].field_13_1;
}

// 0x710136c8a0
void Unk_2432608::Unk_136c8a0(const u16& value) {
    field_60.field_a60 = value;
    for (Unk_136c4d0_Entry& entry : field_60.field_0) {
        if (entry.field_0.field_0 != kMagic)
            continue;
        if (field_60.field_a60 != 0) {
            entry.field_12 = 6;
            entry.field_10 = 4;
        } else {
            entry.field_12 = 0;
        }
    }
}

// 0x710136c910
bool Unk_2432608::Unk_136c910(const int& index) {
    return field_60.field_0[index].field_0.field_0 == kMagic;
}
