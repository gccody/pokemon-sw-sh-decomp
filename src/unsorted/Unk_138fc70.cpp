// Scope: common
// The virtual functions, constructor and destructors of Unk_2433018
// (src/unsorted/Unk_138f100.h). The destructor is its key function: its
// vtables and thunks are emitted here. Its block's key is a constant.
#include "unsorted/Unk_138f100.h"

static void Unk_Write(Unk_2433018* self) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    const u32 key = 0x9751babe;
    Unk_138fce0_T* data = &self->field_60;
    u64 size = sizeof(self->field_60);
    store->Unk_13456e0(key, data, size);
}

// 0x710138fc70
void Unk_2433018::vf7() {
    field_60 = Unk_138fce0_T();
    Unk_Write(this);
}

// 0x710138fe20
// NON_MATCHING: the original calls the read template's instantiation named
// for Unk_1390560_T (0x7101390560), which only this function calls: it's this
// block's type, but the families file names it apart (the key is a constant,
// not a global, so nothing tied the two together).
void Unk_2433018::vf8() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    const u32 key = 0x9751babe;
    Unk_138fce0_T* data = &field_60;
    u64 size = sizeof(field_60);
    if (!store->Unk_1346030(key, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&key);
}

// 0x710138feb0
void Unk_2433018::vf9() {
    Unk_Write(this);
}

// 0x710138ff20
Unk_2433018::Unk_2433018() : field_60() {}

// 0x710138ff70 (D0; its D2 is Unk_239a418's, 0x71005e32f0), thunks
// 0x710138ffc0/0x7101390010 (+0x48) and 0x7101390060/0x71013900b0 (+0x50)
Unk_2433018::~Unk_2433018() {}
