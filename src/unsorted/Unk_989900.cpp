// Scope: common
// The battle scene's view system's scene (unsorted/Unk_98a420.h,
// Unk_23c4ef0_Scene): what it does with the objects it holds at +0x38 and
// +0x58, and functions that forward to what they lead to. Its headers
// declare the class without these functions, so they are free functions
// over a view of its fields. Placeholder names and types: rename and move
// once the classes are known. The callees of 0x71008ec... were matched first
// as tools/leafgen.py's placeholders, each with its own type: the objects are
// passed as those.
#include <bitset>
#include <memory>

#include <nn/os.h>
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

struct Unk_23c4ef0_Scene;

// What the scene's +0x18 points to: two objects it sets flags on.
struct Unk_989900_Owner {
    u8 _0[0x3f8];
    Unk_239a418* field_3f8;
    Unk_239a418* field_400;
};
PKMN_OFFSET_ASSERT(Unk_989900_Owner, field_3f8, 0x3f8);
PKMN_OFFSET_ASSERT(Unk_989900_Owner, field_400, 0x400);

// What the scene is set up with (its +0x8): the allocator its objects come
// from and the owner.
struct Unk_989900_Args {
    Unk_239a418_Allocator* field_0;
    u64 field_8;
    Unk_989900_Owner* field_10;
};
static_assert(sizeof(Unk_989900_Args) == 0x18, "Unk_989900_Args");

// A type-erased callable, 0x80 bytes, like Unk_23d4470_Callable
// (src/unsorted/Unk_23d4470.h): an invoker (+0x0) that takes the storage
// (+0x20), what disposes of it (+0x8), what copies it (+0x10, also used to
// move it) and what moves it (+0x18). The functions of the one here were
// matched first as functions of their own (src/unsorted/leaf), so Set takes
// them.
class Unk_989900_Callable {
public:
    using Invoke = void (*)(void* storage);
    using Dispose = void (*)(void* storage);
    using Copy = void (*)(const void* from, void* to);

    Unk_989900_Callable()
        : field_0(nullptr), field_8(nullptr), field_10(nullptr), field_18(nullptr) {}
    Unk_989900_Callable(const Unk_989900_Callable& other)
        : field_0(nullptr), field_8(nullptr), field_10(nullptr), field_18(nullptr) {
        Assign(other);
    }
    ~Unk_989900_Callable() { Reset(); }

    Unk_989900_Callable& operator=(Unk_989900_Callable other) {
        Reset();
        Assign(other);
        return *this;
    }

    // Holds a callable that captures one pointer.
    template <class A, class B, class C, class D>
    void Set(void* captured, A invoke, B dispose, C copy, D move) {
        field_0 = reinterpret_cast<Invoke>(invoke);
        field_8 = reinterpret_cast<Dispose>(dispose);
        field_10 = reinterpret_cast<Copy>(copy);
        field_18 = reinterpret_cast<Copy>(move);
        *reinterpret_cast<void**>(field_20) = captured;
    }

    Invoke field_0;
    Dispose field_8;
    Copy field_10;
    Copy field_18;
    alignas(16) u8 field_20[0x60];

private:
    void Reset() {
        if (Dispose dispose = field_8) {
            field_18 = nullptr;
            field_10 = nullptr;
            field_8 = nullptr;
            field_0 = nullptr;
            dispose(field_20);
        }
    }
    void Assign(const Unk_989900_Callable& other) {
        if (other.field_10)
            other.field_10(other.field_20, field_20);
        field_0 = other.field_0;
        field_8 = other.field_8;
        field_10 = other.field_10;
        field_18 = other.field_18;
    }
};
static_assert(sizeof(Unk_989900_Callable) == 0x80, "Unk_989900_Callable");

// The base of the scene's two objects (vtable 0x71023c1530, declared with its
// slots in src/unsorted/virtual/Unk_967110.cpp): what it is made with and a
// reference. Its constructor is out of line (0x71014dbec0).
class Unk_23c1530 {
public:
    explicit Unk_23c1530(u64 arg);
    virtual ~Unk_23c1530() {}
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();

    u64 field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
};
static_assert(sizeof(Unk_23c1530) == 0x18, "Unk_23c1530");

// The scene's +0x38 object (vtable 0x71024441f0), 0xb0 bytes: a callable and
// a reference. The scene's deleter destroys it directly.
class Unk_24441f0 final : public Unk_23c1530 {
public:
    explicit Unk_24441f0(u64 arg) : Unk_23c1530(arg) {}
    ~Unk_24441f0() override {}
    u32 vf2() override;

    Unk_989900_Callable field_20;
    Unk_239a418_Ref<Unk_239a418> field_a0;
};
static_assert(sizeof(Unk_24441f0) == 0xb0, "Unk_24441f0");
PKMN_OFFSET_ASSERT(Unk_24441f0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_24441f0, field_a0, 0xa0);

// The scene's +0x58 object (vtable 0x7102444238, declared with its slots in
// src/unsorted/virtual/Unk_14c4b80.cpp), 0x20 bytes: a reference.
class Unk_2444238 final : public Unk_23c1530 {
public:
    explicit Unk_2444238(u64 arg) : Unk_23c1530(arg) {}
    ~Unk_2444238() override {}
    u32 vf2() override;

    Unk_239a418_Ref<Unk_239a418> field_18;
};
static_assert(sizeof(Unk_2444238) == 0x20, "Unk_2444238");

// The scene's fields (as in unsorted/Unk_98a420.h).
struct Unk_989900_Scene {
    u64 Unk_Object38() const { return reinterpret_cast<u64>(field_38.get()); }
    u64 Unk_Object58() const { return reinterpret_cast<u64>(field_58.get()); }

    u8 _0[0x8];
    Unk_989900_Args field_8;
    std::bitset<1> field_20;
    u8 _28[0x38 - 0x28];
    std::unique_ptr<Unk_24441f0, Unk_23f4660_Deleter> field_38;
    std::unique_ptr<Unk_2444238, Unk_23f4660_Deleter> field_58;
    bool field_78;
    bool field_79;
};
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_79, 0x79);

inline Unk_989900_Scene* Unk_989900_View(Unk_23c4ef0_Scene* scene) {
    return reinterpret_cast<Unk_989900_Scene*>(scene);
}

// What the +0x38 and +0x58 objects are asked (0x71014d...).
bool Unk_14dd320(u64 object);
bool Unk_14dc210(u64 object);
bool Unk_14dd5e0(u64 object);
bool Unk_14dc4d0(u64 object);
bool Unk_14dd2b0(u64 object);
void Unk_14dbf60(u64 object);
void Unk_14dbff0(u64 object);
void Unk_14dc050(u64 object);

// Sets or clears the flag `bit` of an object.
void Unk_601140(Unk_239a418* object, bool value, u32 bit);

// Sets or clears the flag 6 of the +0x18 object's two objects.
inline void Unk_989900_SetFlag6(Unk_989900_Owner* owner, bool value) {
    Unk_239a418_Ref<Unk_239a418> first(owner->field_3f8);
    Unk_239a418_Ref<Unk_239a418> second(owner->field_400);
    if (first.m_ptr)
        Unk_601140(first.m_ptr, value, 6);
    if (second.m_ptr)
        Unk_601140(second.m_ptr, value, 6);
}

// 0x7100989d20
bool Unk_989d20(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dd320(self->Unk_Object58());
    if (!done)
        Unk_14dbff0(self->Unk_Object58());
    self->field_78 = done;
    return done;
}

// 0x7100989d60
bool Unk_989d60(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dc210(self->Unk_Object38());
    if (!done)
        Unk_14dbff0(self->Unk_Object38());
    self->field_79 = done;
    return done;
}

// 0x7100989da0
bool Unk_989da0(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dd5e0(self->Unk_Object58());
    if (!done)
        Unk_14dbff0(self->Unk_Object58());
    self->field_78 = false;
    return done;
}

// 0x7100989de0
bool Unk_989de0(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dc4d0(self->Unk_Object38());
    if (done) {
        if (Unk_989900_Owner* owner = self->field_8.field_10)
            Unk_989900_SetFlag6(owner, true);
    } else {
        Unk_14dbff0(self->Unk_Object38());
    }
    self->field_79 = false;
    return done;
}

// 0x7100989eb0
void Unk_989eb0(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    if (self->field_78) {
        Unk_14dbf60(self->Unk_Object58());
        Unk_14dbff0(self->Unk_Object58());
        Unk_14dc050(self->Unk_Object58());
    }
    if (self->field_79) {
        Unk_14dbf60(self->Unk_Object38());
        Unk_14dbff0(self->Unk_Object38());
        Unk_14dc050(self->Unk_Object38());
    }
    Unk_989900_Owner* owner = self->field_8.field_10;
    bool value = self->field_79 ? !Unk_14dd2b0(self->Unk_Object38()) : true;
    if (owner)
        Unk_989900_SetFlag6(owner, value);
}

// The +0x38 object's Unk_23bdd98 (its +0x638).
u8* Unk_98ab90(u64 object);

// What the +0x38 object leads to, at `offset`.
inline u8* Unk_989900_Sub38(Unk_23c4ef0_Scene* scene, u64 offset) {
    return Unk_98ab90(Unk_989900_View(scene)->Unk_Object38()) + offset;
}

struct Unk_8ec490;
struct Unk_8ec4c0;
struct Unk_8ec510;
struct Unk_8ec540;
void Unk_8ec490_set(Unk_8ec490* self, u64 value, u64 arg2, u32 arg3, bool arg4, u64 arg5);
u8 Unk_8ec4c0_getField42(const Unk_8ec4c0* self);
void Unk_8ec510_set(Unk_8ec510* self, u64 value, u32 arg2, bool arg3, u64 arg4);
u8 Unk_8ec540_getField3a(const Unk_8ec540* self);
void Unk_8ec910(u64 self, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5);

// 0x7100989fd0
void Unk_989fd0(Unk_23c4ef0_Scene* scene, u64 arg1, u64 arg2, u32 arg3, bool arg4, u64 arg5) {
    Unk_8ec490_set(reinterpret_cast<Unk_8ec490*>(Unk_989900_Sub38(scene, 0x3e8)), arg1, arg2, arg3,
                   arg4, arg5);
}

// 0x710098a030
u8 Unk_98a030(Unk_23c4ef0_Scene* scene) {
    return Unk_8ec4c0_getField42(
        reinterpret_cast<const Unk_8ec4c0*>(Unk_989900_Sub38(scene, 0x3e8)));
}

// 0x710098a050
void Unk_98a050(Unk_23c4ef0_Scene* scene, u64 arg1, u32 arg2, bool arg3, u64 arg4) {
    Unk_8ec510_set(reinterpret_cast<Unk_8ec510*>(Unk_989900_Sub38(scene, 0x430)), arg1, arg2, arg3,
                   arg4);
}

// 0x710098a0a0
u8 Unk_98a0a0(Unk_23c4ef0_Scene* scene) {
    return Unk_8ec540_getField3a(
        reinterpret_cast<const Unk_8ec540*>(Unk_989900_Sub38(scene, 0x430)));
}

// 0x710098a0c0
void Unk_98a0c0(Unk_23c4ef0_Scene* scene, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    Unk_8ec910(reinterpret_cast<u64>(Unk_989900_Sub38(scene, 0xe0)), arg1, arg2, arg3, arg4, arg5);
}

// What the scene's objects lead to (0x71014dd2a0, 0x71014dd6a0), to which the
// scene gives its owner.
class Unk_989900_Object38 : public Unk_239a418 {
public:
    void Unk_SetOwner(Unk_989900_Owner* owner) { field_728 = owner; }

    u8 _60[0x728 - 0x60];
    Unk_989900_Owner* field_728;
};
PKMN_OFFSET_ASSERT(Unk_989900_Object38, field_728, 0x728);

class Unk_989900_Object58 : public Unk_239a418 {
public:
    void Unk_SetOwner(Unk_989900_Owner* owner) { field_700 = owner; }

    u8 _60[0x700 - 0x60];
    Unk_989900_Owner* field_700;
};
PKMN_OFFSET_ASSERT(Unk_989900_Object58, field_700, 0x700);

Unk_239a418_Ref<Unk_989900_Object38> Unk_14dd2a0(u64 object);
Unk_239a418_Ref<Unk_989900_Object58> Unk_14dd6a0(u64 object);

// What 0x71024ba560 points to: the scene's objects are made with its +0x268.
struct Unk_989900_App {
    u8 _0[0x268];
    u64 field_268;
};
PKMN_OFFSET_ASSERT(Unk_989900_App, field_268, 0x268);

// 0x71024ba560 (as in src/unsorted/registry/Unk_e7b5e0.cpp)
extern Unk_989900_App* Unk_24ba560;

// The callable the +0x38 object is given: it sets the scene's flag 0. Its
// functions are this TU's (reached with adrp + add, not through the GOT), as
// a lambda's would be: hidden, as the tables of docs/game_code.md's batch 23.
struct Unk_98aee0;
struct Unk_98af10;
struct Unk_98af10_arg1;
struct Unk_98af20;
struct Unk_98af20_arg1;
void Unk_98aee0_set(const Unk_98aee0* self) __attribute__((visibility("hidden")));
void Unk_98af00_update() __attribute__((visibility("hidden")));
void Unk_98af10_set(const Unk_98af10* self, Unk_98af10_arg1* out)
    __attribute__((visibility("hidden")));
void Unk_98af20_set(const Unk_98af20* self, Unk_98af20_arg1* out)
    __attribute__((visibility("hidden")));

// NON_MATCHING: the callable's storage address (+0x20) is kept in a register
// across the calls, where the original computes it again each time, and the
// callable's four words are copied in another order (the original loads two
// and stores two at a time: 0x8 and 0x18, then 0x0 and 0x10). The global
// (Unk_989900_app, reached through the GOT slot 0x7102496518) is a
// placeholder whose address isn't known yet.
// 0x7100989900
void Unk_989900(Unk_23c4ef0_Scene* scene, const Unk_989900_Args& args) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    if (self->field_38 != nullptr)
        nn::diag::detail::AbortImpl("", "", "", 0);
    self->field_8 = args;
    u64 app = Unk_24ba560->field_268;
    {
        Unk_989900_Callable callable;
        callable.Set(scene, &Unk_98aee0_set, &Unk_98af00_update, &Unk_98af10_set, &Unk_98af20_set);
        self->field_38 = Unk_2771620_MakeUnique<Unk_24441f0>(self->field_8.field_0, app);
        self->field_38->field_20 = callable;
        Unk_14dc210(self->Unk_Object38());
    }
    self->field_58 = Unk_2771620_MakeUnique<Unk_2444238>(self->field_8.field_0, app);
    Unk_14dd320(self->Unk_Object58());
    Unk_14dd2a0(self->Unk_Object38()).m_ptr->Unk_SetOwner(self->field_8.field_10);
    Unk_14dd6a0(self->Unk_Object58()).m_ptr->Unk_SetOwner(self->field_8.field_10);
}
