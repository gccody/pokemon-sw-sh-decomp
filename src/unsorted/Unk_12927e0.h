#pragma once
// Classes of game/unk_1290e40's first TU (0x7101290e40 to 0x71012938b0) on
// Unk_24284d0 (src/unsorted/Unk_24284d0.h), with internal linkage, like the
// camp's (src/unsorted/Unk_12851f0.cpp). Named after their vtables.
//
// Six classes derive from Unk_242af50, a class of the TU with a reference of
// its own (+0x3c0): its D2 (0x71012928c0) is slot 0 of all six vtables, their
// D0s and destructor thunks branch to it, and their types' parent is its type
// (the static at 0x71027ee610). The types' statics follow it in the order
// Unk_242af50, (Unk_242ae80, Unk_242b020), Unk_242b0f0 (+0x30), Unk_242b1c0
// (+0x40), Unk_242b290 (+0x50).
//
// clang emits a class with internal linkage only in a TU that makes it, and
// the TU is split between several files here: Unk_242b0f0 is made by
// 0x7101292440 (src/unsorted/Unk_1291c90.cpp), Unk_242b1c0 by Unk_242ae80's
// vf8 (0x71012917e0, src/unsorted/Unk_1290e40.cpp), Unk_242b290 by a
// callable (0x7101292ea0, src/unsorted/Unk_1292e30.cpp). A file that makes
// one includes this.
#include "unsorted/Unk_24284d0_Make.h"

// What Unk_24284d0's callables are set up from (0x710126adb0 takes it): the
// shape of the object's fields from +0x80. The hashes and the five callables
// are a member of their own: the vf7s address the storage of each of the five
// from the stack pointer itself (`mov x10, sp`) and the last callable's from
// the struct's pointer, which is what a GEP into a member gives.
struct Unk_126adb0_Callables {
    u64 field_0 = 0xcbf29ce484222645;  // the 64-bit FNV-1a hash of "" (and the next three)
    u64 field_8 = 0xcbf29ce484222645;
    u64 field_10 = 0xcbf29ce484222645;
    u64 field_18 = 0xcbf29ce484222645;
    Unk_24284d0_Callables field_20;
};
static_assert(sizeof(Unk_126adb0_Callables) == 0x2a0, "Unk_126adb0_Callables");

struct Unk_126adb0_Arg {
    Unk_126adb0_Callables field_0;
    u64 field_2a0;
    u64 field_2a8;  // left as it is
    Unk_23d4470_Callable field_2b0;
    f32 field_330 = 0.0f;
};
static_assert(sizeof(Unk_126adb0_Arg) == 0x340, "Unk_126adb0_Arg");
PKMN_OFFSET_ASSERT(Unk_126adb0_Arg, field_2a0, 0x2a0);
PKMN_OFFSET_ASSERT(Unk_126adb0_Arg, field_2b0, 0x2b0);
PKMN_OFFSET_ASSERT(Unk_126adb0_Arg, field_330, 0x330);

// 0x710126adb0, not decompiled yet: sets the object's callables up from
// `arg` (a copy of its last callable is tested first).
bool Unk_126adb0(Unk_24284d0* self, const Unk_126adb0_Arg& arg);

// What a callable's functions are: the generated leaves of each one's
// (src/unsorted/leaf) take a pointer to their own struct.
template <class Call, class Update, class Set1, class Set2>
void Unk_SetCallable(Unk_23d4470_Callable& callable,
                     Unk_24284d0* self,
                     Call call,
                     Update update,
                     Set1 set1,
                     Set2 set2) {
    *reinterpret_cast<Unk_24284d0**>(&callable.field_20) = self;
    callable.field_0 = reinterpret_cast<u64>(call);
    callable.field_8 = reinterpret_cast<void (*)(void*)>(update);
    callable.field_10 = reinterpret_cast<u64>(set1);
    callable.field_18 = reinterpret_cast<u64>(set2);
}

namespace {

// vtable 0x710242af60
class Unk_242af50 : public Unk_24284d0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24284d0::Unk_GetType());
        return &type;
    }
    // 0x7101291b00
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // 0x7101291c20
    void vf7(u64 arg) override { Unk_24284d0::vf7(arg); }
    // 0x7101291a40 (the six classes' too)
    void vf10() override {
        vf7(Unk_126ac90_getField68(reinterpret_cast<const Unk_126ac90*>(this)));
    }

    Unk_239a418_Ref<Unk_239a418> field_3c0;
};
static_assert(sizeof(Unk_242af50) == 0x3d0, "Unk_242af50");
PKMN_OFFSET_ASSERT(Unk_242af50, field_3c0, 0x3c0);

// A class's own type and its getter.
#define UNK_12927E0_TYPE()                                        \
    static const Unk_239a418_Type* Unk_GetType() {                \
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType()); \
        return &type;                                             \
    }                                                             \
    const Unk_239a418_Type* vf_type() override {                  \
        return Unk_GetType();                                     \
    }

// vtable 0x710242b100: vf_type 0x7101292680
class Unk_242b0f0 : public Unk_242af50 {
public:
    Unk_242b0f0() : Unk_242af50() { field_60 = 2; }

    UNK_12927E0_TYPE()
    // 0x71012927e0
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 2;
    }
    // 0x7101292810
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
};

// vtable 0x710242b1d0: vf_type 0x7101292a50
class Unk_242b1c0 : public Unk_242af50 {
public:
    Unk_242b1c0() : Unk_242af50() { field_60 = 1; }

    UNK_12927E0_TYPE()
    void vf7(u64 arg) override;  // 0x7101292bb0
    // 0x7101292dc0
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        Unk_126b1f0();
        if (field_70.m_ptr)
            return field_70;
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
};

// vtable 0x710242b2a0: vf_type 0x71012930e0
class Unk_242b290 : public Unk_242af50 {
public:
    Unk_242b290() : Unk_242af50() { field_60 = 3; }

    UNK_12927E0_TYPE()
    void vf7(u64 arg) override;  // 0x7101293240
    // 0x71012933f0
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        Unk_126b1f0();
        if (field_3c8)
            return Unk_239a418_Ref<Unk_239a418>(nullptr);
        return Unk_239a418_Ref<Unk_239a418>(this);
    }

    bool field_3c8 = false;
};
static_assert(sizeof(Unk_242b290) == 0x3d0, "Unk_242b290");
PKMN_OFFSET_ASSERT(Unk_242b290, field_3c8, 0x3c8);

}  // namespace
