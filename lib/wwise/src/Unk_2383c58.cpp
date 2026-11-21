// Scope: common
// The class with the vtable 0x7102383c58: the one object at 0x71024df140,
// with a list of items it goes through when its registered function is
// called. Written from the executable. Placeholder names.
#include "Unk_2383cc0.h"

struct Unk_2383c58_T : Unk_2383cc0 {};

// What the registered function is called with.
struct Unk_3c2490_Arg {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

extern void* Unk_2383c58[];

static inline void Unk_SetVtable(void* self, void** vtable) {
    Unk_2383cc0_SetVptr(self, vtable);
}
extern Unk_2383c58_T* Unk_24df140;

void Unk_3323d0(void (*callback)(), u32 location, void* cookie);
void Unk_3326d0(void (*callback)(), u32 location);
void Unk_3c2f40(Unk_2383c58_T* self, Unk_3c2490_Pair* pair, u32 count);
void Unk_3c4370(Unk_2383c58_Item* item, Unk_3c2490_Pair* pair, u32 count);
void Unk_3c4480(Unk_2383c58_Item* item);
void Unk_3c2490(Unk_3c2490_Arg* arg);

// 0x71003c23f0: the object, made at the first call
Unk_2383c58_T* Unk_3c23f0() {
    if (Unk_24df140 == nullptr) {
        Unk_2383c58_T* self =
            static_cast<Unk_2383c58_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_2383c58_T)));
        if (self != nullptr) {
            new (self) Unk_2383cc0;
            Unk_SetVtable(self, Unk_2383c58);
        }
        Unk_24df140 = self;
        if (Unk_24df140 != nullptr)
            Unk_3323d0(reinterpret_cast<void (*)()>(Unk_3c2490), 0x90, nullptr);
    }
    return Unk_24df140;
}

// 0x71003c2490: the registered function
void Unk_3c2490(Unk_3c2490_Arg* arg) {
    Unk_2383c58_T* self = Unk_24df140;
    if (self == nullptr)
        return;
    u32 result = arg->vf3();
    if (Unk_24df140 == nullptr)
        return;
    Unk_3c2490_Pair pair;
    pair.last = nullptr;
    pair.first = nullptr;
    u32 count = static_cast<u16>(result);
    for (Unk_2383c58_Item* item = self->field_8.first; item != nullptr;) {
        Unk_2383c58_Item* next = item->next;
        Unk_3c4370(item, &pair, count);
        item = next;
    }
    Unk_3c2f40(self, &pair, count);
}

// 0x71003c2520: destroys it
void Unk_3c2520(Unk_2383c58_T* self) {
    Unk_3326d0(reinterpret_cast<void (*)()>(Unk_3c2490), 0x90);
    for (Unk_2383c58_Item* item = self->field_8.first; item != nullptr;) {
        Unk_2383c58_Item* next = item->next;
        Unk_3c4480(item);
        item = next;
    }
    if (self != nullptr) {
        int pool = Unk_237e820;
        Unk_SetVtable(self, Unk_2383c58);
        Unk_24df140 = nullptr;
        self->Unk_2383cc0::~Unk_2383cc0();
        Unk_3047c0(pool, self);
    }
}
