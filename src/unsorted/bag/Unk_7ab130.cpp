// Scope: common
//
// Callbacks that step the bag's value (src/unsorted/bag/Unk_7aaba0.cpp) down
// by one or by ten, then run its object's field_4c0. Placeholder names:
// rename once the classes are known.
#include <types.h>

void Unk_7aaba0(void* obj, s32 step);
void Unk_1500c40(u64);

struct Unk_7ab130_Obj {
    u8 _0[0x4c0];
    u64 field_4c0;
};
static_assert(__builtin_offsetof(Unk_7ab130_Obj, field_4c0) == 0x4c0, "Unk_7ab130_Obj::field_4c0");

struct Unk_7ab160 {
    Unk_7ab130_Obj* field_0;
};

// 0x71007ab160
void Unk_7ab160_call(const Unk_7ab160* self) {
    Unk_7ab130_Obj* obj = self->field_0;
    Unk_7aaba0(obj, -1);
    if (obj->field_4c0 != 0)
        Unk_1500c40(obj->field_4c0);
}

struct Unk_7ab1d0 {
    Unk_7ab130_Obj* field_0;
};

// 0x71007ab1d0
void Unk_7ab1d0_call(const Unk_7ab1d0* self) {
    Unk_7ab130_Obj* obj = self->field_0;
    Unk_7aaba0(obj, -1);
    if (obj->field_4c0 != 0)
        Unk_1500c40(obj->field_4c0);
}

struct Unk_7ab240 {
    Unk_7ab130_Obj* field_0;
};

// 0x71007ab240
void Unk_7ab240_call(const Unk_7ab240* self) {
    Unk_7ab130_Obj* obj = self->field_0;
    Unk_7aaba0(obj, -10);
    if (obj->field_4c0 != 0)
        Unk_1500c40(obj->field_4c0);
}

struct Unk_7ab2b0 {
    Unk_7ab130_Obj* field_0;
};

// 0x71007ab2b0
void Unk_7ab2b0_call(const Unk_7ab2b0* self) {
    Unk_7ab130_Obj* obj = self->field_0;
    Unk_7aaba0(obj, -10);
    if (obj->field_4c0 != 0)
        Unk_1500c40(obj->field_4c0);
}
