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
// their slot 0. Their D0 and their destructor thunks tail-call it. Four more
// classes on it here: Unk_242b020 and Unk_242b0f0 (made by callables of
// Unk_242ae80's, 0x7101291cb0 and 0x7101292440), Unk_242b1c0 (made by
// Unk_242ae80's vf8) and Unk_242b290 (made by a callable of Unk_242b1c0's).
//
// The classes' type statics are merged in the order their getters are
// emitted: Unk_242af50's, Unk_242ae80's, Unk_242b020's, Unk_242b0f0's,
// Unk_242b1c0's, Unk_242b290's in the original, where the makers are lambdas
// of Unk_242ae80's vf7 (emitted with it, before its vf8). That vf7 isn't
// written, so here they're functions of their own, and Unk_242b1c0's comes
// before Unk_242b020's.
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
    // Its destructor is inline (0x71012928c0): its thunks are 0x7101291c30,
    // 0x7101291c40 (+0x48), 0x7101291c90 and 0x7101291ca0 (+0x50).
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

// vtable 0x710242b1d0: what Unk_242ae80's vf8 makes.
class Unk_242b1c0 : public Unk_242af50 {
public:
    Unk_242b1c0() : Unk_242af50() { field_60 = 1; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType());
        return &type;
    }
    // 0x7101292a50, its thunks 0x7101292e40 (+0x48) and 0x7101292e60 (+0x50)
    // NON_MATCHING: its type static is two places early (+0x20 from
    // Unk_242af50's, where the original has +0x40): see the top of the file.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    void vf7(u64 arg) override;  // 0x7101292bb0
    // 0x7101292dc0
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        Unk_126b1f0();
        if (field_70.m_ptr)
            return field_70;
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
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

// vtable 0x710242b030: made by a callable of Unk_242ae80's (0x7101291cb0).
// Its implicit destructor's D0 is 0x7101291f20, its thunks 0x7101292280,
// 0x7101292290 (+0x48), 0x71012922e0 and 0x71012922f0 (+0x50).
class Unk_242b020 : public Unk_242af50 {
public:
    Unk_242b020() { field_60 = 4; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType());
        return &type;
    }
    // 0x7101291f30, its thunks 0x71012922a0 (+0x48) and 0x71012922c0 (+0x50)
    // NON_MATCHING (and Unk_242b0f0's): its type static is one place late
    // (Unk_242b1c0's is before it): see the top of the file.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    void vf7(u64 arg) override;  // 0x7101292090
    // 0x7101292220
    Unk_239a418_Ref<Unk_239a418> vf8() override {
        Unk_126b1f0();
        if (field_70.m_ptr)
            return field_70;
        return Unk_239a418_Ref<Unk_239a418>(this);
    }
};

// vtable 0x710242b100: made by a callable of Unk_242ae80's (0x7101292440).
// Its implicit destructor's D0 is 0x7101292670, its thunks 0x7101292820,
// 0x7101292830 (+0x48), 0x7101292880 and 0x7101292890 (+0x50).
class Unk_242b0f0 : public Unk_242af50 {
public:
    Unk_242b0f0() : Unk_242af50() { field_60 = 2; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType());
        return &type;
    }
    // 0x7101292680, its thunks 0x7101292840 (+0x48) and 0x7101292860 (+0x50)
    // NON_MATCHING: as Unk_242b020's.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // 0x71012927e0
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 2;
    }
    // 0x7101292810
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
};

// vtable 0x710242b2a0: made by a callable of Unk_242b1c0's (0x7101292ea0).
class Unk_242b290 : public Unk_242af50 {
public:
    Unk_242b290() : Unk_242af50() { field_60 = 3; }

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242af50::Unk_GetType());
        return &type;
    }
    // 0x71012930e0, its thunks 0x7101293460 (+0x48) and 0x7101293480 (+0x50)
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
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

// 0x7101290ea0
Unk_1290ea0_Made::Unk_1290ea0_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_242ae80>(allocator)) {}

// `object` gets `next` as the object after it (taken by value, as the
// makers in Unk_12851f0.cpp give it).
template <class Made>
void Unk_SetNext(Unk_24284d0* object, Made next) {
    object->Unk_126ad50(std::move(next));
}

bool Unk_1269880();  // 0x7101269880

// The calls of two callables Unk_242ae80's vf7 stores (local to the TU in the
// original, like the other callables' functions below).
void Unk_1291cb0(Unk_24284d0** captured) __attribute__((visibility("hidden")));
void Unk_1292440(Unk_24284d0** captured) __attribute__((visibility("hidden")));

// 0x7101291cb0
void Unk_1291cb0(Unk_24284d0** captured) {
    Unk_24284d0* self = *captured;
    if (Unk_1269880()) {
        self->Unk_126aca0()->field_60->Unk_Register(0xc554692e5686862e, false);
    } else {
        Unk_242b020* object = Unk_Create<Unk_242b020>(self->field_8);
        Unk_239a418_Ref<Unk_239a418> next(object);
        Unk_SetNext(object, Unk_1290ea0_Made(self->field_8));
        Unk_Copy(self->field_70, next);
    }
}

// 0x7101292440
void Unk_1292440(Unk_24284d0** captured) {
    Unk_Next<Unk_242b0f0>(*captured, 0xcf2e38d49d8fd87e);
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

// 0x7101290fc0
// 0x7101291020
// 0x71012910f0
// 0x7101291150
// 0x7101291290
// 0x71012912f0
Unk_242ad98::~Unk_242ad98() {}

// The functions of the callables Unk_242b1c0's vf7 stores, local to the TU in
// the original (their addresses are taken with adrp+add): the generated
// leaves of src/unsorted/leaf, and the calls (0x7101292ea0 below;
// 0x7101293610 and 0x7101293780 not decompiled yet).
#define UNK_HIDDEN __attribute__((visibility("hidden")))
void Unk_1292ea0(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_12930c0_update() UNK_HIDDEN;
struct Unk_12935f0;
struct Unk_12935f0_arg1;
void Unk_12935f0_set(const Unk_12935f0* self, Unk_12935f0_arg1* value) UNK_HIDDEN;
struct Unk_1293600;
struct Unk_1293600_arg1;
void Unk_1293600_set(const Unk_1293600* self, Unk_1293600_arg1* value) UNK_HIDDEN;
void Unk_1293610(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_1293750_update() UNK_HIDDEN;
struct Unk_1293760;
struct Unk_1293760_arg1;
void Unk_1293760_set(const Unk_1293760* self, Unk_1293760_arg1* value) UNK_HIDDEN;
struct Unk_1293770;
struct Unk_1293770_arg1;
void Unk_1293770_set(const Unk_1293770* self, Unk_1293770_arg1* value) UNK_HIDDEN;
void Unk_1293780(Unk_24284d0** captured, u64* arg) UNK_HIDDEN;
void Unk_12937b0_update() UNK_HIDDEN;
struct Unk_12937c0;
struct Unk_12937c0_arg1;
void Unk_12937c0_set(const Unk_12937c0* self, Unk_12937c0_arg1* value) UNK_HIDDEN;
struct Unk_12937d0;
struct Unk_12937d0_arg1;
void Unk_12937d0_set(const Unk_12937d0* self, Unk_12937d0_arg1* value) UNK_HIDDEN;
#undef UNK_HIDDEN

// 0x7101292bb0
void Unk_242b1c0::vf7(u64 arg) {
    Unk_24284d0::vf7(arg);
    Unk_126adb0_Arg desc;
    desc.field_0.field_0 = 0x5ea3c9811d533751;
    Unk_SetCallable(desc.field_0.field_20.field_0, this, &Unk_1292ea0, &Unk_12930c0_update,
                    &Unk_12935f0_set, &Unk_1293600_set);
    desc.field_0.field_8 = 0x5ea746811d56418f;
    Unk_SetCallable(desc.field_0.field_20.field_80, this, &Unk_1293610, &Unk_1293750_update,
                    &Unk_1293760_set, &Unk_1293770_set);
    desc.field_2a0 = 0xb0b80d6562080758;
    Unk_SetCallable(desc.field_2b0, this, &Unk_1293780, &Unk_12937b0_update, &Unk_12937c0_set,
                    &Unk_12937d0_set);
    Unk_126adb0(this, desc);
}

// The functions of the callable Unk_242b020's vf7 stores.
#define UNK_HIDDEN __attribute__((visibility("hidden")))
void Unk_1292300(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_1292370_update() UNK_HIDDEN;
struct Unk_1292380;
struct Unk_1292380_arg1;
void Unk_1292380_set(const Unk_1292380* self, Unk_1292380_arg1* value) UNK_HIDDEN;
struct Unk_1292390;
struct Unk_1292390_arg1;
void Unk_1292390_set(const Unk_1292390* self, Unk_1292390_arg1* value) UNK_HIDDEN;
#undef UNK_HIDDEN

// 0x7101292090
// NON_MATCHING: as Unk_242b290's: the stores that empty the struct's first
// callable are scheduled first, where the original has them last (after the
// fourth's); the instructions are the same.
void Unk_242b020::vf7(u64 arg) {
    Unk_24284d0::vf7(arg);
    Unk_126adb0_Arg desc;
    desc.field_2a0 = 0xb0ae016561ff9e6f;
    Unk_SetCallable(desc.field_0.field_20.field_200, this, &Unk_1292300, &Unk_1292370_update,
                    &Unk_1292380_set, &Unk_1292390_set);
    Unk_126adb0(this, desc);
}

// 0x7101292300: what Unk_242b020's callable runs: the next object becomes
// the one it hands out.
void Unk_1292300(Unk_24284d0** captured) {
    Unk_24284d0* self = *captured;
    Unk_Copy(self->field_70, self->field_78);
    self->field_78.Reset();
}

// The functions of the callable Unk_242b290's vf7 stores (its call,
// 0x71012934c0, isn't decompiled yet).
#define UNK_HIDDEN __attribute__((visibility("hidden")))
void Unk_12934c0(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_12935c0_update() UNK_HIDDEN;
struct Unk_12935d0;
struct Unk_12935d0_arg1;
void Unk_12935d0_set(const Unk_12935d0* self, Unk_12935d0_arg1* value) UNK_HIDDEN;
struct Unk_12935e0;
struct Unk_12935e0_arg1;
void Unk_12935e0_set(const Unk_12935e0* self, Unk_12935e0_arg1* value) UNK_HIDDEN;
#undef UNK_HIDDEN

// 0x7101292ea0: what a callable of Unk_242b1c0 runs
void Unk_1292ea0(Unk_24284d0** captured) {
    Unk_Next<Unk_242b290>(*captured, 0xbaa046a2066759ee);
}

// 0x7101293240
// NON_MATCHING: the stores that empty the struct's first two callables are
// scheduled the other way round (the original clears the second one first
// and the first one last); the instructions are the same.
void Unk_242b290::vf7(u64 arg) {
    Unk_24284d0::vf7(arg);
    Unk_126aca0()->field_70 = 7;
    Unk_126adb0_Arg desc;
    desc.field_2a0 = 0xb0ae006561ff9cbc;
    desc.field_330 = 1.0f;
    Unk_SetCallable(desc.field_0.field_20.field_200, this, &Unk_12934c0, &Unk_12935c0_update,
                    &Unk_12935d0_set, &Unk_12935e0_set);
    Unk_126adb0(this, desc);
}
