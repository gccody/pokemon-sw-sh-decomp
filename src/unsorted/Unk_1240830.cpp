// Scope: common
//
// A TU of game/pokecamp (0x7101240830 to 0x7101243470): Unk_2425e60, a class
// on Unk_2423d30 (src/unsorted/Unk_1240830_2423d30.h), and four classes on
// Unk_2423ec8 (src/unsorted/Unk_2423ec8.h) with internal linkage. Written like
// Unk_1238d90.cpp, the TU before it: a class of the TU between the four and
// Unk_2423ec8, with a type of its own and the vf7 they share. The classes are
// named after their vtables.
//
// Unk_2425e60's vtable is emitted here (its vf_type, 0x7101241030, is in
// src/unsorted/types/Unk_1241030.cpp, and its constructor, 0x7101125b70, in
// another TU). It makes Unk_2425ff8 (0x7101240890); Unk_2425ff8's vf8 makes
// Unk_2426310 or hands out a callable that makes Unk_2426100 (0x7101241ce0),
// whose vf8 makes Unk_2426208. The last three are in Unk_12424f0.h.
#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_1127d00.h"
#include "unsorted/Unk_1240830_2423d30.h"
#include "unsorted/Unk_2423ec8.h"

// src/unsorted/leaf/Unk_11575f0.cpp: fields of what the camp's callables get.
struct Unk_115ba20;
u8 Unk_115ba20_getField3b0(const Unk_115ba20* self);
struct Unk_115b9f0;
u8* Unk_115b9f0_getField328Ptr(Unk_115b9f0* self);

// Not decompiled yet: 0x710123dad0, of the TU before this one. Keeps a
// callable holding `ref` (a copy) under `hash`, with the owner locked.
void Unk_123dad0(Unk_1127d00_Owner* owner,
                 u64 hash,
                 const Unk_239a418_Ref<Unk_239a418>& ref,
                 bool arg);

// An object of the camp's (on gflib3's object) that runs a callable.
class Unk_1158640_Owner : public Unk_239a418 {
public:
    // Not decompiled yet: 0x7101158640.
    Unk_239a418_Ref<Unk_239a418> Unk_1158640(const Unk_23d4470_Callable& callable);
};

// What Unk_2423ec8::Unk_12164a0 finds also holds one (0x71012415b0).
struct Unk_12415b0_Result {
    u8 _0[0x358];
    Unk_239a418_Ref<Unk_1158640_Owner> field_358;
};
PKMN_OFFSET_ASSERT(Unk_12415b0_Result, field_358, 0x358);

// The functions of a callable that calls another one (it holds a pointer to
// it), from another TU: the call is 0x7101124210, not decompiled yet.
struct Unk_1124210;
struct Unk_1124210_arg1;
void Unk_1124210_call(Unk_1124210* self, Unk_1124210_arg1* arg);
void Unk_11243c0_update();
struct Unk_11246a0;
struct Unk_11246a0_arg1;
void Unk_11246a0_set(const Unk_11246a0* self, Unk_11246a0_arg1* value);
struct Unk_11246b0;
struct Unk_11246b0_arg1;
void Unk_11246b0_set(const Unk_11246b0* self, Unk_11246b0_arg1* value);

class Unk_1124210_Callable : public Unk_23d4470_Callable {
public:
    // What it holds goes in first, then its functions.
    explicit Unk_1124210_Callable(Unk_23d4470_Callable& target) {
        *reinterpret_cast<Unk_23d4470_Callable**>(field_20) = &target;
        field_0 = reinterpret_cast<u64>(&Unk_1124210_call);
        field_8 = reinterpret_cast<void (*)(void*)>(&Unk_11243c0_update);
        field_10 = reinterpret_cast<u64>(&Unk_11246a0_set);
        field_18 = reinterpret_cast<u64>(&Unk_11246b0_set);
    }
};

// A reference to a new Unk_2425ff8: its constructor makes the object on the
// allocator.
struct Unk_1240890_Made : Unk_239a418_Ref<Unk_239a418> {
    explicit Unk_1240890_Made(Unk_239a418_Allocator* allocator);
};

// vtable 0x7102425e60
class Unk_2425e60 : public Unk_2423d30 {
public:
    void vf7() override;  // 0x7101240830
    const Unk_239a418_Type* vf_type() override;
    void vf18() override;  // 0x7101240a30
};

// 0x7101240830
void Unk_2425e60::vf7() {
    Unk_2423d30::vf7();
    Unk_Assign(field_90, Unk_1240890_Made(field_8));
    static_cast<Unk_2423ec8*>(field_90.m_ptr)->vf7(reinterpret_cast<u64>(this));
}

namespace {

// A reference takes the other's object (a copy), letting go of its own after.
template <class T>
void Unk_Copy(Unk_239a418_Ref<T>& to, const Unk_239a418_Ref<T>& from) {
    Unk_239a418_Ref<T> copy(from);
    T* p = to.m_ptr;
    to.m_ptr = copy.m_ptr;
    copy.m_ptr = p;
}

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

#include "unsorted/Unk_12424f0.h"

// 0x7101240890
Unk_1240890_Made::Unk_1240890_Made(Unk_239a418_Allocator* allocator)
    : Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2425ff8>(allocator)) {}

namespace {

// 0x7101241ce0: the callable Unk_2425ff8's vf8 hands out, on an object of the
// camp's. When the object has its flag, keeps a callable holding the object's
// reference under a name's hash (folded; no string in the executable has it)
// and makes Unk_2426100 the next one, with a new Unk_2425ff8 after it.
bool Unk_1241ce0(Unk_2425ff8* const* captured, Unk_115ba20* const* object) {
    Unk_115ba20* p = *object;
    Unk_2425ff8* self = *captured;
    if (!Unk_115ba20_getField3b0(p))
        return false;
    Unk_123dad0(self->Unk_12164a0()->field_60, 0xa1a11995fefe6ce6,
                *reinterpret_cast<const Unk_239a418_Ref<Unk_239a418>*>(
                    Unk_115b9f0_getField328Ptr(reinterpret_cast<Unk_115b9f0*>(p))),
                false);
    Unk_2426100* next = Unk_Create<Unk_2426100>(self->field_8);
    Unk_Assign(self->field_70, Unk_239a418_Ref<Unk_239a418>(next));
    next->Unk_1216550(Unk_1240890_Made(self->field_8));
    return true;
}

}  // namespace

// The other functions of that callable (written as leaves).
void Unk_1241f30_update();
struct Unk_1242df0;
struct Unk_1242df0_arg1;
void Unk_1242df0_set(const Unk_1242df0* self, Unk_1242df0_arg1* value);
struct Unk_1242e00;
struct Unk_1242e00_arg1;
void Unk_1242e00_set(const Unk_1242e00* self, Unk_1242e00_arg1* value);

namespace {

class Unk_1241ce0_Callable : public Unk_23d4470_Callable {
public:
    explicit Unk_1241ce0_Callable(Unk_2425ff8* self) {
        field_0 = reinterpret_cast<u64>(&Unk_1241ce0);
        field_8 = reinterpret_cast<void (*)(void*)>(&Unk_1241f30_update);
        field_10 = reinterpret_cast<u64>(&Unk_1242df0_set);
        field_18 = reinterpret_cast<u64>(&Unk_1242e00_set);
        *reinterpret_cast<Unk_2425ff8**>(field_20) = self;
    }
};

// 0x71012415b0: when a name's callable is taken out (the names' hashes are
// folded), gives the owner's object a callable that makes the next object;
// or makes Unk_2426310 the next one. This object, until there's a next one.
Unk_239a418_Ref<Unk_239a418> Unk_2425ff8::vf8() {
    if (Unk_12164a0()->field_60->Unk_Take(0xc554692e5686862e)) {
        Unk_239a418_Ref<Unk_1158640_Owner> owner =
            reinterpret_cast<Unk_12415b0_Result*>(Unk_12164a0())->field_358;
        Unk_1241ce0_Callable callable(this);
        Unk_239a418_Ref<Unk_239a418> result =
            owner.m_ptr->Unk_1158640(Unk_1124210_Callable(callable));
    } else if (Unk_12164a0()->field_60->Unk_Take(0xcf2e38d49d8fd87e)) {
        Unk_Assign(field_70, Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2426310>(field_8)));
    }
    if (field_70.m_ptr)
        return field_70;
    return Unk_239a418_Ref<Unk_239a418>(this);
}

// 0x7101242140: makes Unk_2426208 the next object, or makes the one kept in
// field_78 the next one, when a name's callable is taken out (the names'
// hashes are folded). This object, until there's a next one.
Unk_239a418_Ref<Unk_239a418> Unk_2426100::vf8() {
    if (Unk_12164a0()->field_60->Unk_Take(0xbaa046a2066759ee)) {
        Unk_Assign(field_70, Unk_239a418_Ref<Unk_239a418>(Unk_Create<Unk_2426208>(field_8)));
    } else if (Unk_12164a0()->field_60->Unk_Take(0x44b3013f578e8a70)) {
        Unk_Copy(field_70, field_78);
        field_78.Reset();
    }
    if (field_70.m_ptr)
        return field_70;
    return Unk_239a418_Ref<Unk_239a418>(this);
}

}  // namespace
