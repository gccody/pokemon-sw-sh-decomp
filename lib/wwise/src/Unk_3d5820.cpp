// Scope: common
// Two functions of the bus's second base (0xc0) and two more deleting
// destructors of what an effect starts with. Written from the executable.
// Placeholder names.
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
