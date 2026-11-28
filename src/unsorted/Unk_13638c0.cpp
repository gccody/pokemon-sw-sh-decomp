// Scope: common
// The virtual functions of Unk_2432200 (src/unsorted/Unk_13630d0.h): the
// reads and writes of its block, and the redraw of its entries.
#include "unsorted/Unk_13630d0.h"

#include <algorithm>

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The block's key in the store.
extern const u32 Unk_1f33d64;

static void Unk_Write(Unk_2432200* self) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_1363ac0_T* data = &self->field_60;
    u64 size = sizeof(self->field_60);
    store->Unk_13456e0(Unk_1f33d64, data, size);
}

// 0x7101363a50
void Unk_2432200::vf7() {
    Unk_1363780();
    Unk_Write(this);
}

// 0x7101363c00
void Unk_2432200::vf8() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_1363ac0_T* data = &field_60;
    u64 size = sizeof(field_60);
    if (!store->Unk_1346030(Unk_1f33d64, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f33d64);
}

// 0x7101363c90
void Unk_2432200::vf9() {
    Unk_Write(this);
}

// 0x7101363cf0
void Unk_2432200::Unk_1363cf0() {
    Unk_ead0f0_Random random;
    random.Unk_ead0f0(field_60.field_800);
    std::uniform_int_distribution<u32> number(1, 100);
    for (int i = 0; i < 512; i++) {
        u32 first = number(random);
        u32 second = number(random);
        if (field_60.field_0[i].field_0 == 2) {
            field_60.field_0[i].field_0 = 1;
            field_60.field_0[i].field_1 = first;
            field_60.field_0[i].field_2 = second;
        }
    }
    field_60.field_800 = field_60.field_808;
    field_60.field_808 = Unk_ead110();
}
