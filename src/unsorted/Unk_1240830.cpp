// Scope: common
//
// A TU of game/pokecamp (0x7101240830 to 0x7101243470): four classes on
// Unk_2423ec8 (src/unsorted/Unk_2423ec8.h) with internal linkage. Written
// like Unk_1238d90.cpp, the TU before it: a class of the TU between the four
// and Unk_2423ec8, with a type of its own and the vf7 they share. The classes
// are named after their vtables.
//
// One of the four is here, the one a function of its own makes. The others
// are made inside vf8s that aren't decompiled yet: Unk_2426310 by
// Unk_2425ff8's (0x71012415b0), Unk_2426100 by a function at 0x7101241ce0,
// Unk_2426208 by Unk_2426100's (0x7101242140).
#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_2423ec8.h"

// A reference to a new Unk_2425ff8: its constructor makes the object on the
// allocator.
struct Unk_1240890_Made : Unk_239a418_Ref<Unk_239a418> {
    explicit Unk_1240890_Made(Unk_239a418_Allocator* allocator);
};

namespace {

class Unk_1240830_Base : public Unk_2423ec8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2423ec8::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x71012415a0
    void vf7(u64 arg) override { Unk_2423ec8::vf7(arg); }
};

// vtable 0x7102425ff8
class Unk_2425ff8 : public Unk_1240830_Base {
public:
    Unk_2425ff8() : Unk_1240830_Base() { field_60 = 0; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_1240830_Base::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012415b0
};

}  // namespace

// 0x7101240890
Unk_1240890_Made::Unk_1240890_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425ff8>(allocator)) {}
