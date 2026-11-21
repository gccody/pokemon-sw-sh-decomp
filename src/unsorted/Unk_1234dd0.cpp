// Scope: common
//
// A TU of game/pokecamp (0x7101234dd0 to 0x7101238d90): seven classes on
// Unk_2423ec8 (src/unsorted/Unk_2423ec8.h) with internal linkage. Written
// like Unk_1238d90.cpp, the TU after it: a class of the TU between the seven
// and Unk_2423ec8, with a type of its own and the vf7 they share. The classes
// are named after their vtables.
//
// Four of the seven are here, those a function of their own makes. The
// others are made inside functions that aren't decompiled yet: Unk_2424b40
// and Unk_2424d50 by Unk_2424a38's vf8 (0x71012361c0), Unk_2424f60 by the
// TU's first function (0x7101234dd0). The larger vf7 and vf8s are not
// decompiled either.
#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_2423ec8.h"

// A reference to a new object of one of the classes: its constructor makes
// the object on the allocator.
#define UNK_1234DD0_MADE(Name)                           \
    struct Name : Unk_239a418_Ref<Unk_239a418> {         \
        explicit Name(Unk_239a418_Allocator* allocator); \
    }

UNK_1234DD0_MADE(Unk_1234fd0_Made);  // Unk_2424930
UNK_1234DD0_MADE(Unk_1235c80_Made);  // Unk_2424a38
UNK_1234DD0_MADE(Unk_1236ff0_Made);  // Unk_2424c48
UNK_1234DD0_MADE(Unk_1235e20_Made);  // Unk_2424e58

namespace {

class Unk_1234dd0_Base : public Unk_2423ec8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2423ec8::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x7101235760
    void vf7(u64 arg) override { Unk_2423ec8::vf7(arg); }
};

// A class's own type and its getter.
#define UNK_1234DD0_TYPE()                                             \
    static const Unk_239a418_Type* Unk_GetType() {                     \
        static Unk_239a418_Type type(Unk_1234dd0_Base::Unk_GetType()); \
        return &type;                                                  \
    }                                                                  \
    const Unk_239a418_Type* vf_type() override {                       \
        return Unk_GetType();                                          \
    }

// vtable 0x7102424930
class Unk_2424930 : public Unk_1234dd0_Base {
public:
    Unk_2424930() : Unk_1234dd0_Base() { field_60 = 1; }

    UNK_1234DD0_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101235770
};

// vtable 0x7102424a38
class Unk_2424a38 : public Unk_1234dd0_Base {
public:
    Unk_2424a38() : Unk_1234dd0_Base() { field_60 = 2; }

    UNK_1234DD0_TYPE()
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012361c0
};

// vtable 0x7102424c48
class Unk_2424c48 : public Unk_1234dd0_Base {
public:
    Unk_2424c48() : Unk_1234dd0_Base() { field_60 = 6; }

    UNK_1234DD0_TYPE()
    void vf7(u64 arg) override;                   // 0x7101237390
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012374d0
    // 0x71012375f0
    void vf9() override { Unk_2423ec8::vf9(); }

    bool field_80 = false;
};
static_assert(sizeof(Unk_2424c48) == 0x88, "Unk_2424c48");

// vtable 0x7102424e58
class Unk_2424e58 : public Unk_1234dd0_Base {
public:
    Unk_2424e58() : Unk_1234dd0_Base() { field_60 = 5; }

    UNK_1234DD0_TYPE()
    // 0x71012381c0
    void vf7(u64 arg) override {
        Unk_2423ec8::vf7(arg);
        Unk_12164a0()->field_78 = 3;
    }
    // 0x71012381f0
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
    // 0x7101238200
    void vf9() override { Unk_2423ec8::vf9(); }
};

}  // namespace

// The constructors that make the classes, in the classes' order: the types'
// statics are laid out in the order the classes are emitted in (see
// Unk_127dd90.cpp).
//
// NON_MATCHING (the vf_types of Unk_2424c48 and Unk_2424e58, 0x7101237230
// and 0x7101238060): the classes between (Unk_2424b40, Unk_2424d50) aren't
// here, so these two getters address their type's static one and two places
// off (`add x0, x8, #0x38` for `#0x48`); nothing else in them differs.

// 0x7101234fd0
Unk_1234fd0_Made::Unk_1234fd0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2424930>(allocator)) {}

// 0x7101235c80
Unk_1235c80_Made::Unk_1235c80_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2424a38>(allocator)) {}

// 0x7101236ff0
Unk_1236ff0_Made::Unk_1236ff0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2424c48>(allocator)) {}

// 0x7101235e20
Unk_1235e20_Made::Unk_1235e20_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2424e58>(allocator)) {}
