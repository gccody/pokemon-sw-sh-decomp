// Scope: common
// The destructor and virtual functions of Unk_24331b0. The destructor is its
// key function: its vtables and thunks are emitted here.
#include "unsorted/Unk_1392d70.h"

#include <cstring>

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The block's key in the store.
extern const u32 Unk_1f346f8;

// 0x710076f7d0, 0x710076f7e0 (game/unk_761f70): hand an entry to `self`.
void Unk_76f7d0(void* self, void* entry);
void Unk_76f7e0(void* self, void* entry);

// 0x7101392d70, 0x7101392e60 (D0), thunks 0x7101392dc0/0x7101392eb0 (+0x48)
// and 0x7101392e10/0x7101392f00 (+0x50)
Unk_24331b0::~Unk_24331b0() {}

// 0x7101392f50
void Unk_24331b0::vf7() {
    std::memset(&field_60, 0, sizeof(field_60));
    vf9();
}

// 0x7101392f90
// NON_MATCHING: the original tests the result's flag as a byte (tst #0xff),
// as if Unk_1346860_Result::field_0 were a u8, not the header's bool.
void Unk_24331b0::vf8() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_1393080_T* data = &field_60;
    u64 size = sizeof(field_60);
    if (!store->Unk_1346030(Unk_1f346f8, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f346f8);
}

// 0x7101393020
void Unk_24331b0::vf9() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_1393080_T* data = &field_60;
    u64 size = sizeof(field_60);
    store->Unk_13456e0(Unk_1f346f8, data, size);
}

// 0x71013931c0
void Unk_24331b0::Unk_13931c0(int index, void* const& target) {
    Unk_76f7d0(target, &field_60.field_0[index]);
}

// 0x71013931e0
void Unk_24331b0::Unk_13931e0(int index, void* const& target) {
    Unk_76f7e0(target, &field_60.field_0[index]);
}

// 0x7101393200
void Unk_24331b0::Unk_1393200(int index) {
    std::memset(&field_60.field_0[index], 0, sizeof(field_60.field_0[index]));
}
