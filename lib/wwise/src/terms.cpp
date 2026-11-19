// Scope: common
// Functions that free what an object owns. Placeholder names.
#include "containers.h"

struct Unk_30b010 {
    u8 _0[0x10];
    void* field_10;
    u8 _18[0x48];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_30b010, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_30b010, field_60, 0x60);

void Unk_30c140(u64 a0);
void Unk_308aa0(void* self);

// 0x710030b010
void Unk_30b010_call(Unk_30b010* self) {
    if (self->field_10 == nullptr)
        Unk_30c140(self->field_60);
    Unk_308aa0(self);
}

struct Unk_35b640 {
    u8 _0[8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_35b640, field_8, 0x8);

// 0x710035b640
void Unk_35b640_call(const Unk_35b640* self) {
    if (self->field_8 != nullptr)
        Unk_3047c0(Unk_237e820, self->field_8);
}

void Unk_374480(u64 self);

struct Unk_377670 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_377670, field_18, 0x18);

// 0x7100377670
void Unk_377670_call(Unk_377670* self) {
    void* p = self->field_18;
    if (p != nullptr) {
        int pool = Unk_237e820;
        Unk_374480(reinterpret_cast<u64>(p));
        Unk_3047c0(pool, p);
        self->field_18 = nullptr;
    }
}

// A buffer and whether it was allocated (from the pool at 0x7102385820).
struct Unk_3e4640_Buffer {
    void* field_0;
    bool field_8;

    void Free() {
        if (field_0 != nullptr && field_8) {
            Unk_Pool2385820::Free(field_0);
            field_8 = false;
        }
        field_0 = nullptr;
    }
};

struct Unk_3e4640 {
    u8 _0[8];
    Unk_3e4640_Buffer field_8;
};
PKMN_OFFSET_ASSERT(Unk_3e4640, field_8, 0x8);

// 0x71003e4640
void Unk_3e4640_call(Unk_3e4640* self) {
    self->field_8.Free();
}

struct Unk_3e4ab0 {
    u8 _0[0x30];
    Unk_3e4640_Buffer field_30;
};
PKMN_OFFSET_ASSERT(Unk_3e4ab0, field_30, 0x30);

// 0x71003e4ab0
void Unk_3e4ab0_call(Unk_3e4ab0* self) {
    self->field_30.Free();
}

struct Unk_3e52d0 {
    u8 _0[0x30];
    Unk_3e4640_Buffer field_30;
};
PKMN_OFFSET_ASSERT(Unk_3e52d0, field_30, 0x30);

// 0x71003e52d0
void Unk_3e52d0_call(Unk_3e52d0* self) {
    self->field_30.Free();
}

struct Unk_3e54e0 {
    u8 _0[0x40];
    Unk_3e4640_Buffer field_40;
};
PKMN_OFFSET_ASSERT(Unk_3e54e0, field_40, 0x40);

// 0x71003e54e0
void Unk_3e54e0_call(Unk_3e54e0* self) {
    self->field_40.Free();
}
