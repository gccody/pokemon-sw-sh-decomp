// Scope: common
//
// A TU of game/pokecamp (0x710127dd90 to its static initialiser at
// 0x7101285150): eight classes on Unk_24284d0 (src/unsorted/Unk_24284d0.h)
// with internal linkage, and the functions that make them. The classes are
// named after their vtables.
//
// Each class has a type whose parent is one type of this file (the static at
// 0x71027ee3a0), so there is a class between them and Unk_24284d0; its vf10
// (0x710127e810) is the one seven of them have. None has a member to destroy:
// their D2 is Unk_24284d0's (clang replaces the one by the other), and their
// D0 and the destructor thunks are copies of it.
//
// Their vf7 sets the object's callables up (480 to 840 bytes, with the
// lambdas it stores): not decompiled yet, like the larger vf8s.
#include <new>

#include "gflib3/Unk_2399590.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_24284d0.h"
#include "unsorted/Unk_2771620.h"

// 0x710126ac90: field_68 of Unk_24284d0, out of line (written as a leaf).
struct Unk_126ac90;
u64 Unk_126ac90_getField68(const Unk_126ac90*);

// The four functions of a callable that does nothing, all empty (written as
// leaves), and such a callable.
void Unk_1260810_update();
void Unk_1260820_update();
void Unk_1260830_update();
void Unk_1260840_update();

class Unk_1260810_Callable : public Unk_23d4470_Callable {
public:
    Unk_1260810_Callable() {
        field_0 = reinterpret_cast<u64>(&Unk_1260810_update);
        field_8 = reinterpret_cast<void (*)(void*)>(&Unk_1260820_update);
        field_10 = reinterpret_cast<u64>(&Unk_1260830_update);
        field_18 = reinterpret_cast<u64>(&Unk_1260840_update);
    }
};

// What Unk_24284d0::Unk_126aca0's result points at: an object with a lock
// that keeps callables by hash (0x7101127d00, not decompiled).
class Unk_1127d00_Owner {
public:
    void Unk_1127d00(u64 hash, Unk_23d4470_Callable& callable, bool arg3);

    u8 _0[0x60];
    Unk_2399590_Lock field_60;
};

namespace {

class Unk_127dd90_Base : public Unk_24284d0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24284d0::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x710127e810
    void vf10() override {
        vf7(Unk_126ac90_getField68(reinterpret_cast<const Unk_126ac90*>(this)));
    }
};

// A class's own type and its getter.
#define UNK_127DD90_TYPE()                                             \
    static const Unk_239a418_Type* Unk_GetType() {                     \
        static Unk_239a418_Type type(Unk_127dd90_Base::Unk_GetType()); \
        return &type;                                                  \
    }                                                                  \
    const Unk_239a418_Type* vf_type() override {                       \
        return Unk_GetType();                                          \
    }

// The vf8 five of them have: field_70, or the object itself.
#define UNK_127DD90_VF8()                          \
    Unk_239a418_Ref<Unk_239a418> vf8() override {  \
        Unk_126b1f0();                             \
        if (field_70.m_ptr)                        \
            return field_70;                       \
        return Unk_239a418_Ref<Unk_239a418>(this); \
    }

// vtable 0x7102429af0: D0 0x710127e1e0, vf_type 0x710127e330, vf8 0x710127e7b0
class Unk_2429af0 : public Unk_127dd90_Base {
public:
    Unk_2429af0() : Unk_127dd90_Base() { field_60 = 1; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x710127e490
    UNK_127DD90_VF8()
};

// vtable 0x7102429bc0: D0 0x710127f170, vf_type 0x710127f2c0, vf8 0x710127f5b0
class Unk_2429bc0 : public Unk_127dd90_Base {
public:
    Unk_2429bc0() { field_60 = 7; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x710127f420
    UNK_127DD90_VF8()
};

// vtable 0x7102429c90: D0 0x710127fbf0, vf_type 0x710127fd40, vf8 0x71012801f0
class Unk_2429c90 : public Unk_127dd90_Base {
public:
    Unk_2429c90() : Unk_127dd90_Base() { field_60 = 2; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x710127fea0
    UNK_127DD90_VF8()
};

// vtable 0x7102429d60: D0 0x71012809b0, vf_type 0x7101280b00, vf8 0x7101280e40
class Unk_2429d60 : public Unk_127dd90_Base {
public:
    Unk_2429d60() : Unk_127dd90_Base() { field_60 = 3; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x7101280c60
    UNK_127DD90_VF8()
};

// vtable 0x7102429e30: D0 0x7101281640, vf_type 0x7101281790
class alignas(16) Unk_2429e30 : public Unk_127dd90_Base {
public:
    Unk_2429e30() : Unk_127dd90_Base() { field_60 = 6; }

    UNK_127DD90_TYPE()
    // 0x71012818f0
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 7;
    }
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101281920
    // 0x7101281b20
    void vf9() override {
        Unk_24284d0::vf9();
        Unk_126b5b0().m_ptr->Unk_126d2f0();
    }

    u16 field_3c0 = 1;
};
static_assert(sizeof(Unk_2429e30) == 0x3d0, "Unk_2429e30");

// vtable 0x7102429f00: D0 0x7101282620, vf_type 0x7101282770, vf8 0x7101282ab0
class Unk_2429f00 : public Unk_127dd90_Base {
public:
    Unk_2429f00() : Unk_127dd90_Base() { field_60 = 4; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x71012828d0
    UNK_127DD90_VF8()
};

// vtable 0x7102429fd0: D0 0x71012832b0, vf_type 0x7101283400
class Unk_2429fd0 : public Unk_127dd90_Base {
public:
    Unk_2429fd0() : Unk_127dd90_Base() { field_60 = 5; }

    UNK_127DD90_TYPE()
    // 0x7101283560
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 2;
    }
    // 0x7101283590
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
    // 0x71012835a0
    void vf9() override {
        Unk_24284d0::vf9();
        Unk_126b5b0().m_ptr->Unk_126d2f0();
    }
};

// vtable 0x710242a0a0: D0 0x7101283ed0, vf_type 0x7101284020
class Unk_242a0a0 : public Unk_127dd90_Base {
public:
    Unk_242a0a0() : Unk_127dd90_Base() { field_60 = 0; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;                   // 0x7101284180
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012844a0
    void vf10() override;                         // 0x71012846c0
};

// Makes a T on `allocator`, as Unk_New::Create does (src/gflib3/Unk_New.h).
// The allocation is a T* when it's tested: the constructor's call is then
// split in two, one of them with a null pointer (LLVM's call site splitting
// needs the tested value to be the call's argument).
template <class T>
T* Unk_Create(Unk_239a418_Allocator* allocator) {
    Unk_2771620_Scope scope(allocator);
    T* p = static_cast<T*>(allocator->vf2(sizeof(T), alignof(T)));
    if (p == nullptr)
        allocator->vf23();
    T* object = ::new (p) T();
    object->field_8 = allocator;
    object->field_10 = reinterpret_cast<u64>(object);
    object->field_18 = sizeof(T);
    object->field_20 = alignof(T);
    return object;
}

// A reference to a new T.
template <class T>
void Unk_Make(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    ::new (out) Unk_239a418_Ref<Unk_24284d0>(Unk_Create<T>(allocator));
}

// Takes over the other's reference, letting go of its own first.
template <class T>
void Unk_Assign(Unk_239a418_Ref<T>& to, Unk_239a418_Ref<T>&& from) {
    if (to.m_ptr) {
        static_cast<Unk_239a458*>(to.m_ptr)->vf5();
        to.m_ptr = nullptr;
    }
    to.m_ptr = from.Release();
}

// What two callables of the classes run (0x7101280790, 0x7101282400): gives
// the owner's object an empty callable under `hash`, with the object locked,
// and makes the next object (a T) the one `self` hands out.
template <class T>
void Unk_Next(Unk_24284d0* self, u64 hash) {
    Unk_1127d00_Owner* owner = self->Unk_126aca0()->field_60;
    owner->field_60.Lock();
    {
        Unk_1260810_Callable callable;
        owner->Unk_1127d00(hash, callable, false);
    }
    owner->field_60.Unlock();
    Unk_Assign(self->field_70, Unk_239a418_Ref<Unk_239a418>(Unk_Create<T>(self->field_8)));
}

}  // namespace

// The functions that make the classes, in the classes' order rather than
// their own: a class's vtable, its functions and its type's statics are
// emitted where it's first used, and the eight types' statics are laid out
// in the classes' order (clang merges them into one object, and the getters
// address them from the first). In the original that order comes from the
// vf7s and the callables that aren't written yet (one makes the next).

// 0x710127de10
void Unk_127de10(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429af0>(out, allocator);
}

// 0x710127f080
void Unk_127f080(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429bc0>(out, allocator);
}

// 0x710127ef60
void Unk_127ef60(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429c90>(out, allocator);
}

// 0x7101280790
void Unk_1280790(Unk_24284d0** captured) {
    Unk_Next<Unk_2429d60>(*captured, 0x1f2bffc3f5599b31);
}

// 0x7101281520
void Unk_1281520(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429e30>(out, allocator);
}

// 0x7101282400
void Unk_1282400(Unk_24284d0** captured) {
    Unk_Next<Unk_2429f00>(*captured, 0xcf2e38d49d8fd87e);
}

// 0x7101283190
void Unk_1283190(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429fd0>(out, allocator);
}

// 0x710127df30
void Unk_127df30(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_242a0a0>(out, allocator);
}
