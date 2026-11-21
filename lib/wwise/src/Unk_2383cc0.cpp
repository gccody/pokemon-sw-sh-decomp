// Scope: common
// The owner of the items (vtable 0x7102383cc0). Written from the executable.
// Placeholder names.
#include "Unk_2383cc0.h"

// 0x71003c2cb0
Unk_2383cc0::Unk_2383cc0() {
    Unk_2383cc0_SetVptr(this, Unk_2383cc0_Vtable);
    field_8.first = nullptr;
    field_10 = 0;
    field_18 = 0;
    field_20 = 0;
    field_28 = 0;
}

// 0x71003c2ec0
void Unk_3c2ec0(Unk_2383cc0* self, Unk_2383c58_Item* item) {
    self->field_8.AddFirst(item);
}

// 0x71003c2ee0
void Unk_3c2ee0(Unk_2383cc0* self, Unk_2383c58_Item* item) {
    self->field_8.Remove(item);
}

struct Unk_2383c58_T;
void Unk_3c3020(Unk_2383cc0* self, Unk_2383c58_Item* item, u32* arg2, u32 arg3, u32 arg4,
                bool arg5);
void Unk_3c33f0(Unk_2383cc0* self, u32 count);

// 0x71003c2f40 was named with the derived class: passes the events on, then
// lets the time go on
void Unk_3c2f40(Unk_2383c58_T* object, Unk_3c2490_Pair* events, u32 count) {
    Unk_2383cc0* self = reinterpret_cast<Unk_2383cc0*>(object);
    while (!events->IsEmpty()) {
        Unk_3c2f40_Event* event = events->First();
        events->RemoveFirst();
        if (!event->field_10_30 && event->field_10_31)
            Unk_2383cc0_vf1(self, events, event);
        Unk_3c3020(self, event->field_0, &event->field_8, event->field_c, 0, true);
        int pool = Unk_237e820;
        event->~Unk_3c2f40_Event();
        Unk_3047c0(pool, event);
    }
    Unk_3c33f0(self, count);
}
