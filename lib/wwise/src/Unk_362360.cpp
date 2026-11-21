// Scope: common
// The objects that refer to an Unk_360c20_T (Unk_362360_T) and a class
// derived from them. Placeholder names.
#include "Unk_360c20.h"

void operator delete(void* ptr) noexcept;

extern void* Unk_2380be8[];
extern void* Unk_2380c28[];
extern void* Unk_24bbbf8;

void Unk_39b740(void* self, unsigned long owner, u32 id);

struct Unk_3624a0_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* allocator);
};

struct Unk_3624a0_T : Unk_362360_T {
    Unk_3624a0_Obj* field_60;
};

// 0x7100362360
void Unk_362360(Unk_362360_T* self) {
    Unk_360c20_T* target = self->field_10;
    if (target != nullptr) {
        for (auto it = target->field_50.Begin(); it != target->field_50.End(); ++it)
            Unk_39b740(Unk_24bbbf8, reinterpret_cast<unsigned long>(self), (*it).field_6);
    }
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_30 = 0xff;
    self->field_38 = 0xff;
    self->field_40 = 0;
    if (self->field_8 != nullptr) {
        self->field_8->vf5(&Unk_2380d10);
        self->field_8 = nullptr;
    }
    Unk_360c20_T* p = self->field_10;
    if (p != nullptr) {
        if (p->field_70.Remove(self))
            p->vf3();
        self->field_10 = nullptr;
    }
    self->field_48.Term();
}

static inline void Unk_3624a0_Term(Unk_3624a0_T* self) {
    if (self->field_60 != nullptr) {
        self->field_60->vf2(&Unk_2380d10);
        self->field_60 = nullptr;
    }
    Unk_362360(self);
}

// 0x71003624a0
void Unk_3624a0(Unk_3624a0_T* self) {
    Unk_3624a0_Term(self);
}

// 0x71003624e0
void Unk_3624e0(Unk_3624a0_T* self, Unk_3624a0_T* other) {
    Unk_3624a0_Obj* obj = other->field_60;
    other->field_60 = nullptr;
    self->vf5();
    self->field_8 = other->field_8;
    Unk_360c20_T* p = other->field_10;
    self->field_10 = p;
    if (p != nullptr) {
        p->field_70.AddFirst(self);
        p->vf2();
    }
    other->field_8 = nullptr;
    other->vf5();
    self->field_60 = obj;
}

// 0x7100362570
void Unk_362570(Unk_362360_T* self) {
    Unk_SetVtable(self, Unk_2380be8);
    Unk_362360(self);
}

// 0x7100362590
void Unk_362590(Unk_362360_T* self) {
    Unk_SetVtable(self, Unk_2380be8);
    Unk_362360(self);
    operator delete(self);
}

static inline void Unk_362610_Dtor(Unk_3624a0_T* self) {
    Unk_SetVtable(self, Unk_2380c28);
    Unk_3624a0_Term(self);
    Unk_SetVtable(self, Unk_2380be8);
    Unk_362360(self);
}

// 0x7100362610
void Unk_362610(Unk_3624a0_T* self) {
    Unk_362610_Dtor(self);
}

// 0x7100362680
void Unk_362680(Unk_3624a0_T* self) {
    Unk_362610_Dtor(self);
    operator delete(self);
}
