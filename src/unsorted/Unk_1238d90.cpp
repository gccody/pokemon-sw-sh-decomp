// Scope: common
//
// A TU of game/pokecamp (0x7101238d90 to 0x7101240830): twelve classes on
// Unk_2423ec8 (src/unsorted/Unk_2423ec8.h) with internal linkage, the states
// of a cooking request by the names of the messages they send. Written like
// the TUs of the classes on Unk_24284d0 (Unk_127dd90.cpp, Unk_12851f0.cpp): a
// class of the TU between the twelve and Unk_2423ec8, with a type of its own,
// a member (+0x80, 0xd in every object made) and the vf7 and vf17 they share.
// The classes are named after their vtables.
//
// vf11, vf14 and vf15 answer a message (the request received, closed,
// canceled): most send one on and make another class what the object hands
// out next (field_70, or field_78 while something else has the turn).
//
// Nine of the twelve are here: the seven a function of their own makes,
// Unk_2425728 (made by the shared vf17, 0x710123a080) and Unk_2425830 (by
// Unk_2425728's vf14). The others are made inside functions that aren't
// decompiled yet: Unk_2425b48, Unk_2425c50 and Unk_2425d58 each by the vf8 of
// the one before (from Unk_2425a40's, 0x710123e690). Most vf8s are not
// decompiled either.
#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_1127d00.h"
#include "unsorted/Unk_1240830_2423d30.h"
#include "unsorted/Unk_2423ec8.h"

// Not decompiled yet: 0x7101266170 (a test without arguments).
bool Unk_1266170();

// Of Unk_2423ec8's, not decompiled yet (0x71012165d0), and its getters
// written as leaves (src/unsorted/leaf/Unk_1211400.cpp): the owner (field_68),
// the state of an object on it (field_60), and something of the owner's.
void Unk_12165d0(Unk_2423ec8* self);
struct Unk_1216490;
u64 Unk_1216490_getField68(const Unk_1216490* self);
struct Unk_1215350;
u32 Unk_1215350_getField60(const Unk_1215350* self);
struct Unk_12165b0;
u64 Unk_12165b0_get(const Unk_12165b0* self);

// Not decompiled yet: 0x710120ff40, given what Unk_12165b0_get gives and a
// flag.
struct Unk_120ff40_Self;
void Unk_120ff40(Unk_120ff40_Self* self, bool arg);

// Of Unk_2423d30's (0x7101215d70, not decompiled yet): `next` becomes its
// object, which is told (vf9 to the one before, vf7 to the new one).
void Unk_1215d70(Unk_2423d30* self, Unk_239a418_Ref<Unk_239a418> next);

// src/unsorted/leaf/Unk_11575f0.cpp: fields of what the camp's callables get
// (the first a flag: its callers test bit 0).
struct Unk_115ba20;
bool Unk_115ba20_getField3b0(const Unk_115ba20* self);
struct Unk_115b9f0;
u8* Unk_115b9f0_getField328Ptr(Unk_115b9f0* self);

// Not decompiled yet: 0x710123dad0. Keeps a callable holding `ref` (a copy)
// under `hash`, with the owner locked.
void Unk_123dad0(Unk_1127d00_Owner* owner,
                 u64 hash,
                 const Unk_239a418_Ref<Unk_239a418>& ref,
                 bool arg);

// What Unk_2423ec8::Unk_12164a0 finds is one (src/unsorted/types/Unk_1180870.cpp:
// its getter is out of line, 0x710117dca0).
class Unk_241cb78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();
};

// Whether an object's type is T's or one derived from it (the same template
// as tools/typegen.py's).
template <class T>
bool Unk_61a530(Unk_239a498* object) {
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

// What an object does with a message's name (src/unsorted/Unk_1127d00.h), an
// instance per size of name: "OnCookingRequestClosed" (0x710123b9d0),
// "OnCookingRequestCanceled" (0x710123c2e0), the names of 14 characters taken
// out ("NoBerryMessage", "OnJoinSelected", "OnQuitSelected": 0x710123a6b0),
// and "OnCookingRequestFirstReceived" kept with a flag (0x710123b880: taken
// by reference, and the callers pass a temporary, whose stack slot is used
// again after the call). Local to the TU in the original.
template <u64 N>
void Unk_123b880(Unk_2423ec8* self, const char (&name)[N], const bool& arg2, bool arg3) {
    Unk_1127d00_Send<N>(self->Unk_12164a0(), name, arg2, arg3);
}
void Unk_123b9d0(Unk_2423ec8* self, const char* name, bool arg2);
void Unk_123c2e0(Unk_2423ec8* self, const char* name, bool arg2);
bool Unk_123a6b0(Unk_2423ec8* self, const char* name);

// A reference to a new object of one of the classes: its constructor makes
// the object on the allocator.
#define UNK_1238D90_MADE(Name)                           \
    struct Name : Unk_239a418_Ref<Unk_239a418> {         \
        explicit Name(Unk_239a418_Allocator* allocator); \
    }

UNK_1238D90_MADE(Unk_1239340_Made);  // Unk_2425200
UNK_1238D90_MADE(Unk_123a7d0_Made);  // Unk_2425308
UNK_1238D90_MADE(Unk_123a990_Made);  // Unk_2425410
UNK_1238D90_MADE(Unk_123bb00_Made);  // Unk_2425518
UNK_1238D90_MADE(Unk_123c410_Made);  // Unk_2425620
UNK_1238D90_MADE(Unk_1239180_Made);  // Unk_2425938
UNK_1238D90_MADE(Unk_1239500_Made);  // Unk_2425a40

// Not in the executable: what makes Unk_2425728, for the shared vf17. The
// original's vf17 has it inlined, but the types' statics (and the vf_types
// that address them) show Unk_2425728 emitted after Unk_2425620 and before
// Unk_2425938: as an internal function, called by vf17 alone, it is inlined
// and emitted with vf17 (after Unk_2425200), which puts the statics of
// Unk_2425308 to Unk_2425620 two places off. Until the rest of the TU shows
// how the original got that order, it is a function of its own, defined
// after Unk_123c410_Made.
UNK_1238D90_MADE(Unk_2425728_Made);

namespace {

// What makes Unk_2425830: Unk_2425728's vf14 has it inlined.
UNK_1238D90_MADE(Unk_2425830_Made);

class Unk_1238d90_Base : public Unk_2423ec8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2423ec8::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x7101239ca0
    void vf7(u64 arg) override { Unk_2423ec8::vf7(arg); }
    void vf17() override;  // 0x710123a080

    u32 field_80 = 0xd;
};
static_assert(sizeof(Unk_1238d90_Base) == 0x88, "Unk_1238d90_Base");

// A class's own type and its getter.
#define UNK_1238D90_TYPE()                                             \
    static const Unk_239a418_Type* Unk_GetType() {                     \
        static Unk_239a418_Type type(Unk_1238d90_Base::Unk_GetType()); \
        return &type;                                                  \
    }                                                                  \
    const Unk_239a418_Type* vf_type() override {                       \
        return Unk_GetType();                                          \
    }

// vtable 0x7102425200
class Unk_2425200 : public Unk_1238d90_Base {
public:
    Unk_2425200() : Unk_1238d90_Base() { field_60 = 1; }

    UNK_1238D90_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101239cb0
    // 0x7101239f20
    void vf11() override {
        if (!Unk_1266170()) {
            Unk_123b880(this, "OnCookingRequestFirstReceived", false, false);
            field_78.Reset();
        }
    }
    // 0x7101239f80
    void vf14() override {
        Unk_123b9d0(this, "OnCookingRequestClosed", false);
        Unk_Assign(Unk_1266170() ? field_70 : field_78, Unk_123bb00_Made(field_8));
    }
    // 0x710123a000
    void vf15() override {
        Unk_123c2e0(this, "OnCookingRequestCanceled", false);
        Unk_Assign(Unk_1266170() ? field_70 : field_78, Unk_123c410_Made(field_8));
    }
};

// vtable 0x7102425308
class Unk_2425308 : public Unk_1238d90_Base {
public:
    Unk_2425308() : Unk_1238d90_Base() { field_60 = 0xa; }

    UNK_1238D90_TYPE()
    // 0x710123ad50
    void vf7(u64 arg) override {
        Unk_2423ec8::vf7(arg);
        Unk_12164a0()->field_78 = 3;
    }
    // 0x710123ad80
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
    // 0x710123ad90
    void vf9() override { Unk_2423ec8::vf9(); }
};

// vtable 0x7102425410
class Unk_2425410 : public Unk_1238d90_Base {
public:
    Unk_2425410() : Unk_1238d90_Base() { field_60 = 0xc; }

    UNK_1238D90_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710123b260
    // 0x710123b360
    void vf11() override {
        Unk_123b880(this, "OnCookingRequestFirstReceived", false, false);
        Unk_Assign(field_78, Unk_1239340_Made(field_8));
    }
    // 0x710123b3d0
    void vf14() override {
        Unk_123b9d0(this, "OnCookingRequestClosed", false);
        Unk_Assign(field_78, Unk_123bb00_Made(field_8));
    }
    // 0x710123b430
    void vf15() override {
        Unk_123c2e0(this, "OnCookingRequestCanceled", false);
        Unk_Assign(field_78, Unk_123c410_Made(field_8));
    }
    // 0x710123b490
    void vf17() override {}
};

// vtable 0x7102425518
class Unk_2425518 : public Unk_1238d90_Base {
public:
    Unk_2425518() : Unk_1238d90_Base() { field_60 = 9; }

    UNK_1238D90_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710123bec0
    // 0x710123bfb0
    void vf11() override {
        Unk_123b880(this, "OnCookingRequestFirstReceived", false, false);
        Unk_Assign(field_70, Unk_1239180_Made(field_8));
    }
};

// vtable 0x7102425620
class Unk_2425620 : public Unk_1238d90_Base {
public:
    Unk_2425620() : Unk_1238d90_Base() { field_60 = 8; }

    UNK_1238D90_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710123c7c0
    // 0x710123c8b0
    void vf11() override {
        Unk_123b880(this, "OnCookingRequestFirstReceived", false, false);
        Unk_Assign(field_70, Unk_1239180_Made(field_8));
    }
};

// vtable 0x7102425728: what the shared vf17 makes when field_80 is 6.
class Unk_2425728 : public Unk_1238d90_Base {
public:
    Unk_2425728() : Unk_1238d90_Base() { field_60 = 6; }

    UNK_1238D90_TYPE()
    // 0x710123cde0: when "OnQuitSelected"'s callable is taken out and the
    // next object (field_70) isn't in one of the states 5, 8, 9 and 11, tells
    // the owner's and makes field_80 10. The next object, or this one.
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        Unk_12165d0(this);
        if (Unk_123a6b0(this, "OnQuitSelected") && !Unk_IsClosing(field_70)) {
            Unk_120ff40(reinterpret_cast<Unk_120ff40_Self*>(
                            Unk_12165b0_get(reinterpret_cast<const Unk_12165b0*>(this))),
                        false);
            field_80 = 0xa;
        }
        if (field_70.m_ptr)
            return field_70;
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
    void vf14() override;  // 0x710123ce90
    // 0x710123d090
    void vf15() override {
        Unk_123c2e0(this, "OnCookingRequestCanceled", false);
        Unk_Assign(Unk_1266170() ? field_70 : field_78, Unk_123c410_Made(field_8));
    }

private:
    static bool Unk_IsClosing(const Unk_239a418_Ref<Unk_239a418>& next) {
        if (next.m_ptr == nullptr)
            return false;
        switch (Unk_1215350_getField60(reinterpret_cast<const Unk_1215350*>(next.m_ptr))) {
            case 5:
            case 8:
            case 9:
            case 0xb:
                return true;
            default:
                return false;
        }
    }
};

// vtable 0x7102425830: what Unk_2425728's vf14 makes.
class Unk_2425830 : public Unk_1238d90_Base {
public:
    Unk_2425830() : Unk_1238d90_Base() { field_60 = 0xb; }

    UNK_1238D90_TYPE()
    // 0x710123d5d0
    void vf7(u64 arg) override {
        Unk_2423ec8::vf7(arg);
        Unk_12164a0()->field_78 = 7;
        Unk_12165c0();
    }
    // 0x710123d610: none once a name's callable is taken out (its hash is
    // folded), else this object.
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        if (Unk_12164a0()->field_60->Unk_Take(0xc2a248855176e6d1))
            return Unk_239a418_Ref<Unk_239a418>(nullptr);
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
    // 0x710123d730
    void vf9() override { Unk_2423ec8::vf9(); }
};

// 0x710123ce90
void Unk_2425728::vf14() {
    Unk_123b9d0(this, "OnCookingRequestClosed", false);
    Unk_Assign(Unk_1266170() ? field_70 : field_78, Unk_2425830_Made(field_8));
}

// vtable 0x7102425938
class Unk_2425938 : public Unk_1238d90_Base {
public:
    Unk_2425938() : Unk_1238d90_Base() { field_60 = 5; }

    UNK_1238D90_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710123df40
    // 0x710123e110
    void vf14() override {
        Unk_123b9d0(this, "OnCookingRequestClosed", false);
        Unk_Assign(field_70, Unk_123bb00_Made(field_8));
    }
    // 0x710123e170
    void vf15() override {
        Unk_123c2e0(this, "OnCookingRequestCanceled", false);
        Unk_Assign(field_70, Unk_123c410_Made(field_8));
    }
};

// vtable 0x7102425a40
class Unk_2425a40 : public Unk_1238d90_Base {
public:
    Unk_2425a40() : Unk_1238d90_Base() { field_60 = 0; }

    UNK_1238D90_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x710123e690
    // 0x710123ead0
    void vf11() override {
        Unk_123b880(this, "OnCookingRequestFirstReceived", false, false);
        Unk_239a418_Ref<Unk_239a418>& slot = Unk_1266170() ? field_70 : field_78;
        Unk_Assign(slot, Unk_1239180_Made(field_8));
        static_cast<Unk_2423ec8*>(slot.m_ptr)->Unk_1216550(Unk_1239500_Made(field_8));
    }
    // 0x710123eb90
    void vf14() override {
        if (!Unk_1266170()) {
            Unk_123b9d0(this, "OnCookingRequestClosed", false);
            field_78.Reset();
        }
    }
    // 0x710123ebf0
    void vf15() override {
        if (!Unk_1266170()) {
            Unk_123c2e0(this, "OnCookingRequestCanceled", false);
            field_78.Reset();
        }
    }
};

}  // namespace

// 0x710123a080: keeps a callable under a name's hash (folded), makes the
// next object by field_80 and has the owner take it.
// NON_MATCHING: Unk_2425728 is made by a call (Unk_2425728_Made, above), not
// inline; and the address of field_70 is kept in a register of its own (x24,
// so 16 more bytes of frame) where the original addresses it from `this`
// each time.
void Unk_1238d90_Base::vf17() {
    Unk_12164a0()->field_60->Unk_Register(0x21480a97cb258df7, false);
    switch (field_80) {
        case 1:
            Unk_Assign(field_70, Unk_1239340_Made(field_8));
            break;
        case 6:
            Unk_Assign(field_70, Unk_2425728_Made(field_8));
            break;
        case 0xa:
            Unk_Assign(field_70, Unk_123a7d0_Made(field_8));
            break;
    }
    if (field_70.m_ptr) {
        Unk_1215d70(reinterpret_cast<Unk_2423d30*>(
                        Unk_1216490_getField68(reinterpret_cast<const Unk_1216490*>(this))),
                    field_70);
    }
}

// The constructors that make the classes, in the classes' order: the types'
// statics are laid out in the order the classes are emitted in (see
// Unk_127dd90.cpp).

// 0x7101239340
Unk_1239340_Made::Unk_1239340_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425200>(allocator)) {}

// 0x710123a7d0
Unk_123a7d0_Made::Unk_123a7d0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425308>(allocator)) {}

// 0x710123a990
Unk_123a990_Made::Unk_123a990_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425410>(allocator)) {}

// 0x710123bb00
Unk_123bb00_Made::Unk_123bb00_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425518>(allocator)) {}

// 0x710123c410
Unk_123c410_Made::Unk_123c410_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425620>(allocator)) {}

Unk_2425728_Made::Unk_2425728_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425728>(allocator)) {}

namespace {

Unk_2425830_Made::Unk_2425830_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425830>(allocator)) {}

}  // namespace

// 0x7101239180
Unk_1239180_Made::Unk_1239180_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425938>(allocator)) {}

// 0x7101239500
Unk_1239500_Made::Unk_1239500_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425a40>(allocator)) {}

// What the owner's handle (Unk_23f43c8::field_68) refers to, when it's an
// Unk_241cb78: what Unk_2423ec8::Unk_12164a0 finds through its owner.
static Unk_12164a0_Result* Unk_123da00_Find(Unk_2423d30* owner) {
    Unk_239a418* handle = owner->field_68.m_ptr;
    if (handle == nullptr)
        return nullptr;
    Unk_239a498* object =
        reinterpret_cast<Unk_239a498*>(reinterpret_cast<Unk_239a418_Handle*>(handle)->field_60);
    if (object == nullptr || !Unk_61a530<Unk_241cb78>(object))
        return nullptr;
    return reinterpret_cast<Unk_12164a0_Result*>(static_cast<Unk_241cb78*>(object));
}

// What an object does with a reference: the owner keeps a callable holding
// it under `hash`. `target` is read after the reference is.
template <class Target>
static void Unk_123da00_Keep(Target* target,
                             u64 hash,
                             const Unk_239a418_Ref<Unk_239a418>& ref,
                             bool arg) {
    Unk_123dad0(target->field_60, hash, ref, arg);
}

// 0x710123da00: the callable 0x7101238d90 (not decompiled yet) hands out, on
// an object of the camp's. When the object has its flag, keeps a callable
// holding the object's reference under a name's hash (folded). Local to the
// TU in the original.
bool Unk_123da00(Unk_2423d30* const* captured, Unk_115ba20* const* object) {
    Unk_115ba20* p = *object;
    Unk_2423d30* self = *captured;
    if (!Unk_115ba20_getField3b0(p))
        return false;
    Unk_123da00_Keep(Unk_123da00_Find(self), 0x6a368cfd19f9e7f9,
                     *reinterpret_cast<const Unk_239a418_Ref<Unk_239a418>*>(
                         Unk_115b9f0_getField328Ptr(reinterpret_cast<Unk_115b9f0*>(p))),
                     true);
    return true;
}

// 0x710123b9d0
void Unk_123b9d0(Unk_2423ec8* self, const char* name, bool arg2) {
    Unk_1127d00_Send<23>(self->Unk_12164a0(), name, arg2);
}

// 0x710123c2e0
void Unk_123c2e0(Unk_2423ec8* self, const char* name, bool arg2) {
    Unk_1127d00_Send<25>(self->Unk_12164a0(), name, arg2);
}

// 0x710123a6b0
// NON_MATCHING: the registers of the hash and of the name (then the owner's
// object) are the other way round (x19 and x20); the instructions are the
// same.
bool Unk_123a6b0(Unk_2423ec8* self, const char* name) {
    return Unk_1127d00_Take<15>(self->Unk_12164a0(), name);
}

// 0x710123b880: the instance for a name of 29 characters. An instance of a
// template, not a function of its own: a caller's code depends on it (what
// LLVM learns from a plain function's body, that the flag's address isn't
// kept, lets the caller's last call be a tail call; an instance may be
// replaced by another TU's, so nothing is learned from it).
template void Unk_123b880<30>(Unk_2423ec8*, const char (&)[30], const bool&, bool);
