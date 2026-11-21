// Scope: common
// Two small functions of the class with the vtable 0x7102385800. Written
// from the executable. Placeholder names.
#include <types.h>

struct Unk_2385800_T {
    u8 _0[0x6c];
    u8 field_6c_0 : 2;
    u8 field_6c_2 : 1;
};

// 0x71003e2cb0
u32 Unk_3e2cb0(Unk_2385800_T* /*self*/) {
    return 0x2000;
}

// 0x71003e2f70
void Unk_3e2f70(Unk_2385800_T* self, bool value) {
    self->field_6c_2 = value;
}
