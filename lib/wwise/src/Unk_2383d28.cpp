// Scope: common
// The classes with the vtables 0x7102383d28 (in the list at 0x71024df180),
// 0x7102383da8 (an array of 0x20-byte items it releases) and 0x7102383e40.
// Written from the executable. Placeholder names.
#include "Unk_23837d0.h"
#include "Unk_FastMath.h"
#include "Unk_Indexed.h"
#include "block_pool.h"

// What an item of the array calls when it goes.
struct Unk_3c9550_Obj {
    virtual void vf0(u32 arg1);
};

// An item of the array: 0x20 bytes.
struct Unk_3c9550_Item {
    u64 field_0;
    void* field_8;
    u32 field_10;
    u32 field_14;  // -1 when it has nothing to give back
    Unk_3c9550_Obj* field_18;
};
PKMN_SIZE_ASSERT(Unk_3c9550_Item, 0x20);

typedef Unk_Array<Unk_3c9550_Item> Unk_3c9550_Array;

extern u64 Unk_24bbbe0;
void Unk_3490d0(u64 self, u32 id);

// Gives back what the items have and frees the array.
static inline void Unk_3c9550_Term(Unk_3c9550_Array* self) {
    for (auto it = self->Begin(); it != self->End(); ++it) {
        if ((*it).field_8 != nullptr && (*it).field_14 != 0xffffffff) {
            Unk_3490d0(Unk_24bbbe0, (*it).field_14);
            if ((*it).field_18 != nullptr)
                (*it).field_18->vf0(0);
        }
    }
    self->Term();
}

// 0x71003c9550
void Unk_3c9550(Unk_3c9550_Array* self) {
    Unk_3c9550_Term(self);
}

// The class with the array.
struct Unk_2383da8_T {
    void** field_0;  // vptr
    u64 field_8;
    Unk_3c9550_Array field_10;
};

extern void* Unk_2383da8[];

// 0x71003c98d0: its destructor
void Unk_3c98d0(Unk_2383da8_T* self) {
    Unk_SetVtable(self, Unk_2383da8);
    Unk_3c9550_Term(&self->field_10);
}

// 0x71003c9b70: whether an item has `key`
bool Unk_3c9b70(Unk_2383da8_T* self, void* key) {
    for (auto it = self->field_10.Begin(); it != self->field_10.End(); ++it) {
        if ((*it).field_8 == key)
            return true;
    }
    return false;
}

// 0x71003c9be0: the deleting destructor
void Unk_3c9be0(Unk_2383da8_T* self) {
    Unk_SetVtable(self, Unk_2383da8);
    Unk_3c9550_Term(&self->field_10);
    operator delete(self);
}

u64 Unk_332b20_get(u64 arg0, u32 arg1, u32 arg2, u64 arg3, u32 arg4, u32 arg5);

// 0x71003c99c0
u64 Unk_3c99c0(void* /*self*/, u64 arg1, u32 arg2) {
    return Unk_332b20_get(arg1, arg2, 0, 0xffffffffffffffff, 0, 0);
}

// The class with the vtable 0x7102383e40: 0x28 bytes.
struct Unk_2383e40_T {
    void** field_0;  // vptr
    u32 field_8;
    u64 field_10;
    u64 field_18;
    void* field_20;
};

extern void* Unk_2383e40[];

// 0x71003c9bc0: its constructor
void Unk_3c9bc0(Unk_2383e40_T* self, void* arg1, u32 arg2) {
    self->field_8 = arg2;
    self->field_10 = 0;
    self->field_18 = 0;
    Unk_SetVtable(self, Unk_2383e40);
    self->field_20 = arg1;
}

struct Unk_369910;
void* Unk_3cfb30(void* arg0);
u32 Unk_369910_get(const Unk_369910* self);
void Unk_3d14e0(void* arg0, u32* arg1, u32* arg2);

// 0x71003c9e80
u32 Unk_3c9e80(Unk_2383e40_T* self, u32* result) {
    *result = 0;
    void* found = Unk_3cfb30(self->field_20);
    if (found == nullptr)
        return 2;
    *result = Unk_369910_get(static_cast<const Unk_369910*>(found));
    return 1;
}

// What it is the context of, as far as its volume.
struct Unk_3c9e00_Owner {
    u8 _0[0x3c];
    f32 field_3c;  // decibels
};

// 0x71003c9e00: how loud what it belongs to is
f32 Unk_3c9e00(Unk_2383e40_T* self) {
    return Unk_FromDecibels(static_cast<Unk_3c9e00_Owner*>(self->field_20)->field_3c);
}

// The class with the vtable 0x7102383ed8: the same with 16 bytes more.
struct Unk_2383ed8_Pair {
    u64 field_0;
    u64 field_8;
};
struct Unk_2383ed8_T : Unk_2383e40_T {
    Unk_2383ed8_Pair field_28;
};

extern void* Unk_2383ed8[];

// 0x71003c9ef0: its constructor
void Unk_3c9ef0(Unk_2383ed8_T* self, void* arg1, u32 arg2, Unk_2383ed8_Pair* arg3) {
    self->field_8 = arg2;
    self->field_10 = 0;
    self->field_18 = 0;
    Unk_SetVtable(self, Unk_2383ed8);
    self->field_20 = arg1;
    self->field_28 = *arg3;
}

// 0x71003ca000
u32 Unk_3ca000(Unk_2383e40_T* self, u32* arg1, u32* arg2) {
    Unk_3d14e0(self->field_20, arg1, arg2);
    return 1;
}

// What the objects of the list are made for, as far as it is called here.
struct Unk_2383d28_Owner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual bool vf37(u32 count);
    virtual void vf38(u32 count);
};

// An object of the list at 0x71024df180: 0x168 bytes.
struct Unk_2383d28_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u64 vf5();
    virtual bool vf6();

    u8 _8[0x40];
    Unk_2383d28_T* next;
    u8 _50[0xf8];
    Unk_2383d28_Owner* field_148;
    u8 _150[8];
    void* field_158;
    Unk_2383d28_T* field_160;  // the one before
};
PKMN_SIZE_ASSERT(Unk_2383d28_T, 0x168);

extern void* Unk_2383d28[];
extern Unk_ListPolicy<Unk_2383d28_T, Unk_ListNoCount, Unk_ListNoLast> Unk_24df180;

void Unk_34e5d0(Unk_2383d28_T* self, void* arg1, void* arg2, u32 arg3);  // the base class's
void Unk_3a4560(Unk_2383d28_T* self, Unk_2383d28_Owner* owner, u64* arg2, bool arg3);
bool Unk_3d0460(void* arg0);

// 0x71003c8e80: the constructor
void Unk_3c8e80(Unk_2383d28_T* self, void* arg1, void* arg2) {
    Unk_34e5d0(self, arg1, arg2, 0);
    Unk_SetVtable(self, Unk_2383d28);
    self->next = nullptr;
    self->field_158 = nullptr;
    self->field_160 = nullptr;
}

// 0x71003c8f00
u32 Unk_3c8f00(Unk_2383d28_T* self) {
    if (!self->field_148->vf37(1))
        return 2;
    Unk_2383d28_Owner* owner = self->field_148;
    u64 key = self->vf5();
    Unk_3a4560(self, owner, &key, self->vf6());
    return 1;
}

struct Unk_3a45b0;
void Unk_3a45b0_call(Unk_3a45b0* self, void* arg1, bool arg2);
void Unk_34e7b0(Unk_2383d28_T* self, bool arg1);

// 0x71003c8f90: out of the list, and what the base class does to end
// NON_MATCHING: the tests of "is it in the list" branch in another order
// (8 bytes less), and the object and the flag are kept in each other's
// registers.
void Unk_3c8f90(Unk_2383d28_T* self, bool arg1) {
    u64 key = self->vf5();
    Unk_3a45b0_call(reinterpret_cast<Unk_3a45b0*>(self), &key, self->vf6());
    self->field_148->vf38(1);
    if (self->field_160 != nullptr || self->next != nullptr || Unk_24df180.first == self) {
        if (self->next != nullptr)
            self->next->field_160 = self->field_160;
        if (Unk_24df180.first == self)
            Unk_24df180.first = self->next;
        else
            self->field_160->next = self->next;
        self->field_160 = nullptr;
        self->next = nullptr;
    }
    Unk_34e7b0(self, arg1);
}

// 0x71003c94c0: takes out of the list the objects whose 0x71003d0460 says no
void Unk_3c94c0() {
    auto it = Unk_24df180.BeginEx();
    while (it != Unk_24df180.End()) {
        Unk_2383d28_T* p = *it;
        if (Unk_3d0460(p->field_158)) {
            ++it;
        } else {
            if (p->next != nullptr)
                p->next->field_160 = p->field_160;
            it = Unk_24df180.Erase(it);
            p->field_160 = nullptr;
            p->next = nullptr;
        }
    }
}

// 0x71003c9f20: the deleting destructor of the classes on Unk_2383da8_T
void Unk_3c9f20(Unk_2383da8_T* self) {
    Unk_SetVtable(self, Unk_2383da8);
    Unk_3c9550_Term(&self->field_10);
    operator delete(self);
}

u64 Unk_3d2f40(void* arg0, u32 arg1, u64 arg2, u64 arg3);

// 0x71003ca130
u64 Unk_3ca130(Unk_2383e40_T* self, u64 arg1, u64 arg2) {
    return Unk_3d2f40(self->field_20, self->field_8, arg1, arg2);
}

// 0x71003ca150
f32 Unk_3ca150(Unk_2383e40_T* self) {
    return Unk_FromDecibels(static_cast<Unk_3c9e00_Owner*>(self->field_20)->field_3c);
}

// What the next functions ask (slot 33 of its vtable).
struct Unk_3ca240_Z {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void* vf33();
};

// What they pass on to (slots 57 and 58), with the other one at 0x80.
struct Unk_3ca240_Bus {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57(void* arg1, struct Unk_3ca300_Ref* ref, void* arg3);
    virtual void vf58(u32 arg1, u32 arg2, u32* result);

    u8 _8[0x78];
    Unk_3ca240_Z* field_80;
};
PKMN_OFFSET_ASSERT(Unk_3ca240_Bus, field_80, 0x80);

struct Unk_3ca240_T {
    Unk_3ca240_Bus* field_0;
    u64 field_8;
    Unk_23837d0_Object* field_10;
};

struct Unk_3ca240_Pair {
    void* field_0;
    u64 field_8;
};

// 0x71003ca240
Unk_3ca240_Pair Unk_3ca240(Unk_3ca240_T* self) {
    Unk_3ca240_Pair result;
    result.field_0 = nullptr;
    result.field_8 = 0xffffffffffffffff;
    if (self->field_0 != nullptr) {
        Unk_3ca240_Z* other = self->field_0->field_80;
        if (other != nullptr) {
            result.field_0 = other->vf33();
            if (result.field_0 != nullptr)
                result.field_8 = self->field_8;
        }
    }
    return result;
}

// A counted object with a number.
struct Unk_3ca300_Ref {
    Unk_3ca240_Bus* field_0;
    u16 field_8;

    void Clear() {
        Unk_3ca240_Bus* object = field_0;
        field_0 = nullptr;
        if (object != nullptr)
            object->vf3();
        field_8 = 0;
    }
};

// 0x71003ca300
void Unk_3ca300(Unk_3ca240_T* self, void* arg1, Unk_3ca300_Ref* ref) {
    if (self->field_0 != nullptr)
        self->field_0->vf57(arg1, ref, self->field_10);
    else
        ref->Clear();
}

// 0x71003ca360
void Unk_3ca360(Unk_3ca240_T* self, u32 arg1, u32 arg2, u32* result) {
    if (self->field_0 != nullptr)
        self->field_0->vf58(arg1, arg2, result);
    else
        *result = 0xffffffff;
}

// Unk_237ff98.h: the node class has this function.
struct Unk_237ff98_Ref;
class Unk_237ff98 {
public:
    void Unk_356a90(Unk_237ff98_Ref* out);
};

// 0x71003ca3b0
void Unk_3ca3b0(Unk_3ca240_T* self, Unk_3ca300_Ref* ref) {
    if (self->field_0 != nullptr)
        reinterpret_cast<Unk_237ff98*>(self->field_0)
            ->Unk_356a90(reinterpret_cast<Unk_237ff98_Ref*>(ref));
    else
        ref->Clear();
}

// 0x71003ca450
void Unk_3ca450(Unk_3ca240_T* self) {
    if (self->field_10 != nullptr)
        self->field_10->Release();
}

void Unk_356bc0(Unk_3ca240_Bus* self, u32 key, u32* result);

// 0x71003ca400
void Unk_3ca400(Unk_3ca240_T* self, u32 key, u32* result) {
    if (self->field_0 != nullptr)
        Unk_356bc0(self->field_0, key, result);
    else
        *result = 0xffffffff;
}
