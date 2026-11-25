#pragma once
// Three classes of the game/pokecamp TU of src/unsorted/Unk_1240830.cpp
// (0x7101240830 to 0x7101243470), on its Unk_1240830_Base, with internal
// linkage like the others. Named after their vtables. Not included anywhere
// yet: include it in Unk_1240830.cpp after Unk_1240830_Base, and before the
// functions that make the classes, once those are written there:
//
//   Unk_2426100  made by 0x7101241ce0 (a callback; field_60 1)
//   Unk_2426208  made by Unk_2426100's vf8 (0x7101242140; field_60 3)
//   Unk_2426310  made by Unk_2425ff8's vf8 (0x71012415b0; field_60 2)
//
// Their vtables, and with them every function below and the classes'
// destructors, vf_types and destructor and vf_type thunks (0x7101241f40,
// 0x7101241fe0 and 0x71012424f0 to 0x7101243270, but 0x7101242df0 and
// 0x7101242e00), are only emitted where an object is made. With a scratch
// function making each of the three in a TU of its own, all of them match
// but the three vf_types: those address their type's static 0x10 off,
// because Unk_2425ff8's type is in the TU before them (the statics, in
// .L_MergedGlobals: Unk_1240830_Base's at +0x0, Unk_2425ff8's at +0x10, then
// these three in this order).
#include "unsorted/Unk_1127d00.h"
#include "unsorted/Unk_2423ec8.h"

namespace {

// A class's own type and its getter.
#define UNK_12424F0_TYPE()                                             \
    static const Unk_239a418_Type* Unk_GetType() {                     \
        static Unk_239a418_Type type(Unk_1240830_Base::Unk_GetType()); \
        return &type;                                                  \
    }                                                                  \
    const Unk_239a418_Type* vf_type() override {                       \
        return Unk_GetType();                                          \
    }

// vtable 0x7102426100
class Unk_2426100 : public Unk_1240830_Base {
public:
    Unk_2426100() : Unk_1240830_Base() { field_60 = 1; }

    UNK_12424F0_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101242140
};

// vtable 0x7102426208
class Unk_2426208 : public Unk_1240830_Base {
public:
    Unk_2426208() : Unk_1240830_Base() { field_60 = 3; }

    UNK_12424F0_TYPE()
    // 0x71012429b0
    void vf7(u64 arg) override {
        Unk_2423ec8::vf7(arg);
        Unk_12164a0()->field_78 = 7;
    }
    // 0x71012429e0: this object, until the callable kept under a name's hash
    // is taken out. The name isn't in the executable (its hash is folded,
    // and no string there has it).
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        if (Unk_12164a0()->field_60->Unk_Take(0xc2a248855176e6d1))
            return Unk_239a418_Ref<Unk_239a418>(nullptr);
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
    // 0x7101242b00
    void vf9() override {
        Unk_2423ec8::vf9();
        Unk_12165c0();
    }
};

// vtable 0x7102426310
class Unk_2426310 : public Unk_1240830_Base {
public:
    Unk_2426310() : Unk_1240830_Base() { field_60 = 2; }

    UNK_12424F0_TYPE()
    // 0x7101243010
    void vf7(u64 arg) override {
        Unk_2423ec8::vf7(arg);
        Unk_12164a0()->field_78 = 3;
    }
    // 0x7101243040
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
};

#undef UNK_12424F0_TYPE

}  // namespace
