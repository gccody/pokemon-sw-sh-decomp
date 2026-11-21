// Scope: common
// Two functions of the bus's second base (0xc0) and two more deleting
// destructors of what an effect starts with. Written from the executable.
// Placeholder names.
#include "Unk_23847d8.h"
#include "Unk_24df148.h"

extern void* const Unk_2380be8[8];

static inline void Unk_2380be8_Dtor(Unk_24df148_SlotCtx* self) {
    *reinterpret_cast<void* const**>(self) = Unk_2380be8 + 2;
    reinterpret_cast<void (*)(Unk_24df148_SlotCtx*)>(Unk_2380be8[7])(self);
}

// 0x71003d5820: the bus
Unk_24df148_Bus* Unk_3d5820(Unk_24df148_Sub* self) {
    return Unk_24df148_Outer(self);
}

// 0x71003d5830: its node's ID
u32 Unk_3d5830(Unk_24df148_Sub* self) {
    return Unk_24df148_Outer(self)->Id();
}

// 0x71003d5850
void Unk_3d5850(Unk_24df148_SlotCtx* self) {
    Unk_2380be8_Dtor(self);
    operator delete(self);
}

// 0x71003d59d0
void Unk_3d59d0(Unk_24df148_SlotCtx* self) {
    Unk_2380be8_Dtor(self);
    operator delete(self);
}

// 0x71003d5890: the destructor of what measures a bus
void Unk_3d5890(void* object) {
    Unk_23847d8_T* self = static_cast<Unk_23847d8_T*>(object);
    self->field_0 = Unk_23847d8 + 2;
    if (self->field_10 != nullptr) {
        Unk_304740(Unk_2381488, self->field_10);
        self->field_10 = nullptr;
    }
    if (self->field_18 != nullptr) {
        Unk_304740(Unk_2381488, self->field_18);
        self->field_18 = nullptr;
    }
    if (self->field_20 != nullptr) {
        Unk_304740(Unk_2381488, self->field_20);
        self->field_20 = nullptr;
    }
    if (self->field_28 != nullptr)
        Unk_304740(Unk_2381488, self->field_28);
    if (self->field_30 != nullptr)
        Unk_3047c0(Unk_2381488, self->field_30);
    if (self->field_38 != nullptr)
        Unk_3047c0(Unk_2381488, self->field_38);
}
