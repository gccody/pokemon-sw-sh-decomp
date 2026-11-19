// Scope: common
//
// Unk_2434918 (src/unsorted/unk_133d350/Unk_2434918.h): its constructor and
// callbacks. vf7 is its key function, so its vtable, implicit destructor and
// the destructor's thunks are emitted here.
#include "unsorted/unk_133d350/Unk_2434918.h"

// 0x71013b2120
Unk_2434918::Unk_2434918(u64 arg1, const u64* arg2) : field_60(arg1), field_68(*arg2) {
    field_70 = 0xcbf29ce484222645;
}

// 0x71013b2190
bool Unk_2434918::vf7(bool value) {
    if (field_80) {
        return field_80(&field_e0, value);
    }
    return true;
}

// 0x71013b21f0
void Unk_2434918::vf8(bool value) {
    if (field_b0)
        field_b0(value);
}
