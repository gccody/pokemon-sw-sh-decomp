// Scope: common
//
// The start of a TU of game/unk_1290e40 (0x7101290e40 to 0x71012938b0):
// Unk_242ad98's destructor and vf7, which makes the object its base holds at
// +0x3c0 (Unk_242ae80), and that class and the one it's on (Unk_242af50),
// two classes on Unk_24284d0 (src/unsorted/Unk_24284d0.h) with internal
// linkage. The classes are named after their vtables.
//
// Unk_242af50 has a reference of its own (+0x3c0): its destructor is inline,
// and the classes on it without members to destroy have it (0x71012928c0) in
// their slot 0. Their D0 and their destructor thunks tail-call it.
#include "unsorted/Unk_23f43c8.h"
#include "unsorted/Unk_24284d0_Make.h"

// A class on Unk_23f43c8 (vtable 0x71024283f8), in game/pokecamp: only what
// Unk_242ad98 uses of it is written here.
class Unk_24283e8 : public Unk_23f43c8 {
public:
    ~Unk_24283e8() override;  // 0x710126b950
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;  // 0x7101269310
    u32 vf8() override;
    void vf9() override;
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();

    u8 _78[0x348];
    // What vf7 makes (a class on Unk_24284d0); vf7 runs it with the object.
    Unk_239a418_Ref<Unk_239a418> field_3c0;
    u8 _3c8[0x768];
};
PKMN_OFFSET_ASSERT(Unk_24283e8, field_3c0, 0x3c0);
PKMN_SIZE_ASSERT(Unk_24283e8, 0xb30);

// 0x710128c0e0 (in game/pokecamp, not decompiled yet): takes what the
// owner keeps under `hash` into `out`, with the owner locked; whether there
// was something.
bool Unk_128c0e0(Unk_1127d00_Owner* self, u64 hash, Unk_239a418_Ref<Unk_239a418>* out);

// vtable 0x710242ada8 (its vf_type is in src/unsorted/types/Unk_1291080.cpp).
class Unk_242ad98 : public Unk_24283e8 {
public:
    ~Unk_242ad98() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;

    Unk_239a418_Ref<Unk_239a418> field_b30;
};
PKMN_OFFSET_ASSERT(Unk_242ad98, field_b30, 0xb30);

namespace {

// vtable 0x710242af60, on Unk_24284d0 with a reference of its own. Six
// classes are on it (Unk_242ae80 here, five from 0x7101291f20 on).
class Unk_242af50 : public Unk_24284d0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24284d0::Unk_GetType());
        return &type;
    }
    // 0x7101291b00, its thunks 0x7101291c50 (+0x48) and 0x7101291c70 (+0x50)
    // NON_MATCHING: the original inlines Unk_24284d0::Unk_GetType into it
    // (288 bytes) and its thunks call it; here the inliner defers that (it
    // would make vf_type too big for the thunks), so vf_type calls it and the
    // thunks get vf_type's body.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x7101291c20
    void vf7(u64 arg) override { Unk_24284d0::vf7(arg); }
    // 0x7101291a40
    void vf10() override {
        vf7(Unk_126ac90_getField68(reinterpret_cast<const Unk_126ac90*>(this)));
    }

    Unk_239a418_Ref<Unk_239a418> field_3c0;
};
static_assert(sizeof(Unk_242af50) == 0x3d0, "Unk_242af50");

// `to` becomes a copy of `from` (a copy swapped in, its old pointer let go
// of with the copy).
template <class T>
void Unk_Copy(Unk_239a418_Ref<T>& to, const Unk_239a418_Ref<T>& from) {
    Unk_239a418_Ref<T> copy(from);
    std::swap(to.m_ptr, copy.m_ptr);
}

// vtable 0x710242b1d0: what Unk_242ae80's vf8 makes. Its functions are
// 0x7101292a40 (D0) to 0x7101292dc0 (vf8), not written here yet.
class Unk_242b1c0 : public Unk_242af50 {
public:
    Unk_242b1c0() : Unk_242af50() { field_60 = 1; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    void vf7(u64 arg) override;
    Unk_239a418_Ref<Unk_239a418> vf8() override;
};

// vtable 0x710242ae90
class Unk_242ae80 : public Unk_242af50 {
public:
    Unk_242ae80() : Unk_242af50() { field_60 = 0; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x71012914c0: sets the object's callables up (792 bytes, with the
    // lambdas it stores, 0x7101291cb0 on): not decompiled yet, like the vf7s
    // of the classes in Unk_127dd90.cpp and Unk_12851f0.cpp.
    void vf7(u64 arg) override;
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012917e0
};

}  // namespace

// A reference to a new Unk_242ae80, made on the allocator.
struct Unk_1290ea0_Made : Unk_239a418_Ref<Unk_239a418> {
    explicit Unk_1290ea0_Made(Unk_239a418_Allocator* allocator);
};

// 0x7101290e40
void Unk_242ad98::vf7() {
    Unk_24283e8::vf7();
    Unk_Assign(field_3c0, Unk_1290ea0_Made(field_8));
    static_cast<Unk_24284d0*>(field_3c0.m_ptr)->vf7(reinterpret_cast<u64>(this));
}

// 0x71012917e0
// NON_MATCHING: the end. The swap into field_70 stores the object's pointer
// as an integer (the one Unk_Create stored at +0x10), so field_70's address
// isn't folded into one GEP and the reload after the `if` goes through a
// phi: `this` isn't known to be non-null there, and Ref(this) tests it.
Unk_239a418_Ref<Unk_239a418> Unk_242ae80::vf8() {
    Unk_126b1f0();
    if (Unk_128c0e0(Unk_126aca0()->field_60, 0xa1a11995fefe6ce6, &field_3c0)) {
        Unk_242b1c0* object = Unk_Create<Unk_242b1c0>(field_8);
        Unk_239a418_Ref<Unk_239a418> next(object);
        object->Unk_126ad50(Unk_1290ea0_Made(field_8));
        Unk_Copy(object->field_3c0, Unk_239a418_Ref<Unk_239a418>(field_3c0));
        Unk_Copy(field_70, next);
    }
    if (field_70.m_ptr)
        return field_70;
    return Unk_239a418_Ref<Unk_239a418>(this);
}

// 0x7101290ea0
Unk_1290ea0_Made::Unk_1290ea0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242ae80>(allocator)) {}

// 0x7101290fc0
// 0x7101291020
// 0x71012910f0
// 0x7101291150
// 0x7101291290
// 0x71012912f0
Unk_242ad98::~Unk_242ad98() {}
