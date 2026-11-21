// Scope: common
//
// A TU of game/pokecamp (0x71012851f0 to 0x7101290e40): twelve classes on
// Unk_24284d0 (src/unsorted/Unk_24284d0.h) with internal linkage, and the
// functions that make them. Like the TU before it (Unk_127dd90.cpp): a class
// of the TU between the twelve and Unk_24284d0, with a type of its own; here
// it also has a member (+0x3c0, 0xd in every object made), four more virtual
// functions, and a vf10 and a vf14 the twelve share. The classes are named
// after their vtables.
//
// vf11 lets go of field_78; vf12 and vf13 make another class the object
// (field_70 or field_78) hands out; vf14 makes one by the member's value.
//
// Their vf7 sets the object's callables up (400 to 884 bytes, with the
// lambdas it stores): not decompiled yet, like the larger vf8s and vf11s.
#include "unsorted/Unk_24284d0_Make.h"

// Not decompiled yet: 0x7101266170 and 0x7101269880 (two tests without
// arguments).
bool Unk_1266170();
bool Unk_1269880();

// What an object does with a message's name (src/unsorted/Unk_1127d00.h),
// an instance per size of name: "NoBerryMessage", "OnJoinSelected" and
// "OnQuitSelected" (0x7101286ed0), "OnMessageClosed" (0x7101287c80),
// "OnCookingRequestCanceled" (0x7101288770), "OnCookingRequestClosed"
// (0x71012889b0). Local to the TU in the original.
void Unk_1286ed0(Unk_24284d0* self, const char* name, bool arg2);
void Unk_1287c80(Unk_24284d0* self, const char* name, bool arg2);
bool Unk_1288770(Unk_24284d0* self, const char* name);
bool Unk_12889b0(Unk_24284d0* self, const char* name);

// A reference to a new object of one of the classes: its constructor makes
// the object on the allocator. One per class that several functions make.
#define UNK_12851F0_MADE(Name)                           \
    struct Name : Unk_239a418_Ref<Unk_239a418> {         \
        explicit Name(Unk_239a418_Allocator* allocator); \
    }

UNK_12851F0_MADE(Unk_12857e0_Made);  // Unk_242a258
UNK_12851F0_MADE(Unk_1287000_Made);  // Unk_242a348
UNK_12851F0_MADE(Unk_1287db0_Made);  // Unk_242a438
UNK_12851F0_MADE(Unk_1288890_Made);  // Unk_242a528
UNK_12851F0_MADE(Unk_1288ad0_Made);  // Unk_242a618
UNK_12851F0_MADE(Unk_128b440_Made);  // Unk_242a7f8
UNK_12851F0_MADE(Unk_12855a0_Made);  // Unk_242a8e8
UNK_12851F0_MADE(Unk_12856c0_Made);  // Unk_242a9d8

namespace {

// `to` becomes a copy of `from`.
template <class T>
void Unk_Copy(Unk_239a418_Ref<T>& to, const Unk_239a418_Ref<T>& from) {
    Unk_239a418_Ref<T> copy(from);
    T* old = to.m_ptr;
    to.m_ptr = copy.m_ptr;
    copy.m_ptr = old;
}

// Gives `object` what it hands out next. The new reference is taken by
// value and moved on: the callable that does this (0x710128dfa0) has the
// constructor's object in a slot of its own and the moved one in a slot that
// is used again, which is what an argument slot and an inlined function's
// give.
template <class Made>
void Unk_SetNext(Unk_24284d0* object, Made next) {
    object->Unk_126ad50(std::move(next));
}

class Unk_12851f0_Base : public Unk_24284d0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24284d0::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x7101286470
    void vf10() override {
        if (field_78.m_ptr) {
            Unk_Copy(field_70, field_78);
            field_78.Reset();
        } else {
            vf7(Unk_126ac90_getField68(reinterpret_cast<const Unk_126ac90*>(this)));
        }
    }
    virtual void vf11() {}  // 0x7101286cf0
    virtual void vf12() {}  // 0x7101286d00
    virtual void vf13() {}  // 0x7101286d10
    virtual void vf14();    // 0x7101286600

    u32 field_3c0 = 0xd;
};
static_assert(sizeof(Unk_12851f0_Base) == 0x3d0, "Unk_12851f0_Base");

// A class's own type and its getter.
#define UNK_12851F0_TYPE()                                             \
    static const Unk_239a418_Type* Unk_GetType() {                     \
        static Unk_239a418_Type type(Unk_12851f0_Base::Unk_GetType()); \
        return &type;                                                  \
    }                                                                  \
    const Unk_239a418_Type* vf_type() override {                       \
        return Unk_GetType();                                          \
    }

// vtable 0x710242a258
class Unk_242a258 : public Unk_12851f0_Base {
public:
    Unk_242a258() : Unk_12851f0_Base() { field_60 = 1; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x7101285f40
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012862c0
    // 0x7101286500
    void vf11() override { field_78.Reset(); }
    // 0x7101286520
    void vf12() override {
        Unk_Assign(Unk_1266170() ? field_70 : field_78, Unk_1288ad0_Made(field_8));
    }
    // 0x7101286590
    void vf13() override {
        Unk_Assign(Unk_1266170() ? field_70 : field_78, Unk_1288890_Made(field_8));
    }
};

// vtable 0x710242a348
class Unk_242a348 : public Unk_12851f0_Base {
public:
    Unk_242a348() : Unk_12851f0_Base() { field_60 = 0xc; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x71012873d0
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101287560
};

// vtable 0x710242a438
class Unk_242a438 : public Unk_12851f0_Base {
public:
    Unk_242a438() : Unk_12851f0_Base() { field_60 = 0xa; }

    UNK_12851F0_TYPE()
    // 0x7101288180
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 2;
    }
    // 0x71012881b0
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
    // 0x71012881c0
    void vf9() override {
        Unk_24284d0::vf9();
        Unk_126b5b0().m_ptr->Unk_126d2f0();
    }
};

// vtable 0x710242a528
class Unk_242a528 : public Unk_12851f0_Base {
public:
    Unk_242a528() : Unk_12851f0_Base() { field_60 = 8; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x7101288ea0
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101289080
};

// vtable 0x710242a618
class Unk_242a618 : public Unk_12851f0_Base {
public:
    Unk_242a618() : Unk_12851f0_Base() { field_60 = 9; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x7101289a00
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101289be0
};

// vtable 0x710242a708: made by Unk_12851f0_Base::vf14 alone
class Unk_242a708 : public Unk_12851f0_Base {
public:
    Unk_242a708() : Unk_12851f0_Base() { field_60 = 6; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x710128a7f0
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710128ab00
    void vf12() override;                         // 0x710128acb0
    void vf13() override;                         // 0x710128ad70
};

// vtable 0x710242a7f8
class Unk_242a7f8 : public Unk_12851f0_Base {
public:
    Unk_242a7f8() : Unk_12851f0_Base() { field_60 = 0xb; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;  // 0x710128b820
    // 0x710128b9d0
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        Unk_126b1f0();
        if (field_3c4)
            return Unk_239a418_Ref<Unk_239a418>(nullptr);
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
    // 0x710128ba20
    void vf9() override {
        Unk_24284d0::vf9();
        Unk_126b5b0().m_ptr->Unk_126d2f0();
    }

    bool field_3c4 = false;
};
static_assert(sizeof(Unk_242a7f8) == 0x3d0, "Unk_242a7f8");

// vtable 0x710242a8e8
class Unk_242a8e8 : public Unk_12851f0_Base {
public:
    Unk_242a8e8() : Unk_12851f0_Base() { field_60 = 5; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x710128c4f0
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710128c700
    // 0x710128c8b0
    void vf12() override { Unk_Assign(field_70, Unk_1288ad0_Made(field_8)); }
    // 0x710128c900
    void vf13() override { Unk_Assign(field_70, Unk_1288890_Made(field_8)); }
};

// vtable 0x710242a9d8
class Unk_242a9d8 : public Unk_12851f0_Base {
public:
    Unk_242a9d8() : Unk_12851f0_Base() { field_60 = 0; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x710128d430
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710128d750
    void vf11() override;                         // 0x710128d900
    // 0x710128da20
    void vf12() override { field_78.Reset(); }
    // 0x710128da40
    void vf13() override { field_78.Reset(); }
};

// vtable 0x710242aac8: made by one callable (0x710128dfa0)
class Unk_242aac8 : public Unk_12851f0_Base {
public:
    Unk_242aac8() : Unk_12851f0_Base() { field_60 = 2; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x710128e500
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710128e6e0
};

// vtable 0x710242abb8: made by one callable (0x710128ed40)
class Unk_242abb8 : public Unk_12851f0_Base {
public:
    Unk_242abb8() : Unk_12851f0_Base() { field_60 = 3; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x710128f220
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710128f3b0
};

// vtable 0x710242aca8: made by one callable (0x710128fa10)
class Unk_242aca8 : public Unk_12851f0_Base {
public:
    Unk_242aca8() : Unk_12851f0_Base() { field_60 = 4; }

    UNK_12851F0_TYPE()
    void vf7(u64 arg) override;                   // 0x710128fe20
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101290100
    void vf11() override;                         // 0x71012902b0
    // 0x71012903f0
    void vf12() override { field_78.Reset(); }
    // 0x7101290410
    void vf13() override { field_78.Reset(); }
};

// 0x7101286600
void Unk_12851f0_Base::vf14() {
    switch (field_3c0) {
        case 1:
            Unk_Assign(field_70, Unk_12857e0_Made(field_8));
            break;
        case 6:
            Unk_Assign(field_70, Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a708>(field_8)));
            break;
        case 0xa:
            Unk_Assign(field_70, Unk_1287db0_Made(field_8));
            break;
    }
}

}  // namespace

// The constructors that make the classes, in the classes' order: the types'
// statics are laid out in the order the classes are emitted in (see
// Unk_127dd90.cpp).
//
// NON_MATCHING (the vf_types of Unk_242a348, Unk_242a438, Unk_242a528,
// Unk_242a618 and Unk_242a708: 0x7101287270, 0x7101288020, 0x7101288d40,
// 0x71012898a0, 0x710128a690): Unk_242a708 comes with the first vtable (vf14
// makes it), where the original has it sixth: Unk_242a258's vf7, which isn't
// written, reaches four classes before vf14 does. Until it is, these five
// getters address their type's static one place off (`add x0, x8, #0x38`
// for `#0x28`, ...); nothing else in them differs.

// 0x71012857e0
Unk_12857e0_Made::Unk_12857e0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a258>(allocator)) {}

// 0x7101287000
Unk_1287000_Made::Unk_1287000_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a348>(allocator)) {}

// 0x7101287db0
Unk_1287db0_Made::Unk_1287db0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a438>(allocator)) {}

// 0x7101288890
Unk_1288890_Made::Unk_1288890_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a528>(allocator)) {}

// 0x7101288ad0
Unk_1288ad0_Made::Unk_1288ad0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a618>(allocator)) {}

// 0x710128b440
Unk_128b440_Made::Unk_128b440_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a7f8>(allocator)) {}

// 0x71012855a0
Unk_12855a0_Made::Unk_12855a0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a8e8>(allocator)) {}

// 0x71012856c0
Unk_12856c0_Made::Unk_12856c0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242a9d8>(allocator)) {}

// 0x710128dfa0: what a callable of Unk_242a9d8 runs.
// NON_MATCHING: the address of the allocator (self + 8) is kept in a register
// across the two branches (GVN finds it in both and merges it where they
// meet), where the original computes it again from `self` for the last
// constructor; 8 bytes longer. The same statement written in both branches
// isn't merged at all.
void Unk_128dfa0(Unk_24284d0** captured) {
    Unk_24284d0* self = *captured;
    if (Unk_1269880()) {
        Unk_Next<Unk_242aac8>(self, 0xc554692e5686862e);
    } else {
        Unk_1286ed0(self, "NoBerryMessage", false);
        Unk_Assign(self->field_70, Unk_1287000_Made(self->field_8));
    }
    Unk_SetNext(static_cast<Unk_24284d0*>(self->field_70.m_ptr), Unk_12856c0_Made(self->field_8));
}

// 0x710128ed40: what a callable runs
void Unk_128ed40(Unk_24284d0** captured) {
    Unk_Next<Unk_242abb8>(*captured, 0xbaa046a2066759ee);
}

// 0x710128fa10: what a callable runs
void Unk_128fa10(Unk_24284d0** captured) {
    Unk_24284d0* self = *captured;
    Unk_1287c80(self, "OnMessageClosed", false);
    Unk_Assign(self->field_70,
               Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242aca8>(self->field_8)));
}

// 0x7101286ed0
void Unk_1286ed0(Unk_24284d0* self, const char* name, bool arg2) {
    Unk_1127d00_Send<15>(self->Unk_126aca0(), name, arg2);
}

// 0x7101287c80
void Unk_1287c80(Unk_24284d0* self, const char* name, bool arg2) {
    Unk_1127d00_Send<16>(self->Unk_126aca0(), name, arg2);
}

// 0x7101288770
// NON_MATCHING (and 0x71012889b0): the registers of the hash and of the name
// (then the owner's object) are the other way round (x19 and x20); the
// instructions are the same.
bool Unk_1288770(Unk_24284d0* self, const char* name) {
    return Unk_1127d00_Take<25>(self->Unk_126aca0(), name);
}

// 0x71012889b0
bool Unk_12889b0(Unk_24284d0* self, const char* name) {
    return Unk_1127d00_Take<23>(self->Unk_126aca0(), name);
}
