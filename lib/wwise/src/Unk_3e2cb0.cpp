// Scope: common
// Two small functions of the class with the vtable 0x7102385800. Written
// from the executable. Placeholder names.
#include <types.h>

struct Unk_2385800_T {
    u8 _0[0x1c];
    u32 field_1c;  // ticks in a beat
    u8 _20[0x30];
    f32 field_50;  // beats in a minute
    f32 field_54;  // milliseconds a tick takes
    f32 field_58;  // ticks in a millisecond
    u8 _5c[0x10];
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

// 0x71003e2f30: a tempo (the one it has when there is none)
void Unk_3e2f30(Unk_2385800_T* self, f32 tempo) {
    if (tempo != 0.0f)
        self->field_50 = tempo;
    else
        tempo = self->field_50;
    f32 ticks = tempo * self->field_1c;
    self->field_54 = 60000.0f / ticks;
    self->field_58 = ticks / 60000.0f;
}
