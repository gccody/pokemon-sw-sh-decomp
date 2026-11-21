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
// Seven of the twelve are here, those a function of their own makes. The
// others are made inside functions that aren't decompiled yet: Unk_2425728
// by the shared vf17 (0x710123a080), Unk_2425830 by Unk_2425728's vf14, and
// Unk_2425b48, Unk_2425c50 and Unk_2425d58 each by the vf8 of the one before
// (from Unk_2425a40's, 0x710123e690). The vf8s are not decompiled either.
#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_1127d00.h"
#include "unsorted/Unk_2423ec8.h"

// Not decompiled yet: 0x7101266170 (a test without arguments).
bool Unk_1266170();

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

namespace {

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

// The constructors that make the classes, in the classes' order: the types'
// statics are laid out in the order the classes are emitted in (see
// Unk_127dd90.cpp).
//
// NON_MATCHING (the vf_types of Unk_2425938 and Unk_2425a40, 0x710123dde0
// and 0x710123e530): the two classes before them (Unk_2425728, Unk_2425830)
// aren't here, so these two getters address their type's static two places
// off (`add x0, x8, #0x68` for `#0x88`); nothing else in them differs.

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

// 0x7101239180
Unk_1239180_Made::Unk_1239180_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425938>(allocator)) {}

// 0x7101239500
Unk_1239500_Made::Unk_1239500_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425a40>(allocator)) {}

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
