// Scope: common
// The constructor, destructors and virtual functions of Unk_2432f50
// (src/unsorted/Unk_138f100.h). The destructor is its key function: its
// vtables and thunks are emitted here.
#include "unsorted/Unk_138f100.h"

// The block's key in the store.
extern const u32 Unk_1f345f4;

static void Unk_Write(Unk_2432f50* self) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_138f3c0_T* data = &self->field_60;
    u64 size = sizeof(self->field_60);
    store->Unk_13456e0(Unk_1f345f4, data, size);
}

// 0x710138f100
Unk_2432f50::Unk_2432f50() : field_60() {}

// 0x710138f150, 0x710138f240 (D0), thunks 0x710138f1a0/0x710138f290 (+0x48)
// and 0x710138f1f0/0x710138f2e0 (+0x50)
Unk_2432f50::~Unk_2432f50() {}

// 0x710138f330
void Unk_2432f50::vf7() {
    field_60.field_0 = 0xc4811baaa2cb7b86;
    field_60.field_8 = 0xcbf29ce484222645;
    field_60.field_10 = 0;
    field_60.field_18 = 0;
    Unk_Write(this);
}

// 0x710138f500
void Unk_2432f50::vf8() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_138f3c0_T* data = &field_60;
    u64 size = sizeof(field_60);
    if (!store->Unk_1346030(Unk_1f345f4, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f345f4);
}

// 0x710138f590
void Unk_2432f50::vf9() {
    Unk_Write(this);
}
