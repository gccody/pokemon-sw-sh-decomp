#pragma once
// What the contents' apps (prog/contents/...: the box, the bag, Battle
// Stadium, ...) are written on: hashed names, an app's frame and its views,
// the states of an app and casts between the classes on gflib3's object.
// The strings and hashed names are gflib3's (unsorted/Unk_d0c0.h).
// Placeholder names: rename them once the classes are known.
#include <algorithm>
#include <vector>

#include <nn/os.h>
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_23f43c8.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_23f6328.h"
#include "unsorted/Unk_d0c0.h"

// Game Freak's check in a release build: it keeps the condition, and its
// failure aborts without the condition's text.
#define UNK_CHECK(condition)                            \
    do {                                                \
        if (!(condition))                               \
            nn::diag::detail::AbortImpl("", "", "", 0); \
    } while (0)

// Plays a sound by its name (0x7101502120).
bool Unk_1502120(const Unk_5cfaf0_Name& name);

// The object a handle (an object's vf2) refers to, through its +0x50
// interface: null once it's gone.
inline Unk_239a498* Unk_HandleObject(const Unk_239a418_Ref<Unk_239a418>& handle) {
    Unk_239a418* p = handle.m_ptr;
    if (p == nullptr)
        return nullptr;
    return reinterpret_cast<Unk_239a498*>(reinterpret_cast<Unk_239a418_Handle*>(p)->field_60);
}

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

// The object as a T, or null when it isn't one: through its +0x50 interface.
template <class T, class U>
T* Unk_DynamicCast(U* object) {
    if (object == nullptr)
        return nullptr;
    Unk_239a498* interface = object;
    if (!Unk_61a530<T>(interface))
        return nullptr;
    return static_cast<T*>(interface);
}

// The views of an app's frame (its field_548), by name.
class Unk_a7bb80_Views {
public:
    // The view of that name, as a T (0x7100a7bb80 for the box's top view,
    // 0x7100795bc0 for an option bar): null when there's none or it isn't one.
    // Inline: its definition is in contents/common/views.h, for the TUs
    // that inline it (the others call the copies).
    template <class T>
    T* Unk_a7bb80(const Unk_5cfaf0_Name& name);

    u8 _0[0x78];
    std::vector<Unk_23f4660*> field_78;
};
static_assert(__builtin_offsetof(Unk_a7bb80_Views, field_78) == 0x78, "Unk_a7bb80_Views::field_78");

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// An app's frame (type 0x71027d9380): the states get it from their field_60.
class Unk_23f41d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    u8 _60[0x548 - 0x60];
    Unk_a7bb80_Views* field_548;
};
static_assert(__builtin_offsetof(Unk_23f41d0, field_548) == 0x548, "Unk_23f41d0::field_548");

// A state's frame; it has to be there.
inline Unk_a7bb80_Views* Unk_StateViews(Unk_23f43c8* state) {
    return Unk_DynamicCast<Unk_23f41d0>(Unk_HandleObject(state->field_60))->field_548;
}

// A view of a state's frame by name, as a T: null when there's none.
template <class T, size_t N>
inline T* Unk_StateView(Unk_23f43c8* state, const char (&name)[N]) {
    return Unk_StateViews(state)->Unk_a7bb80<T>(name);
}

// An option bar (vtable 0x71023f6118): the views named "OptionBar".
class Unk_23f6118 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// Functions of the views (Unk_23f4660).
void Unk_e806b0(Unk_23f4660* view, bool visible, bool children);
// tools/leafgen.py's placeholder, with the view as a u64.
void Unk_e80580(u64 view, u32 arg1, u32 arg2);
inline void Unk_e80580(Unk_23f4660* view, u32 arg1, u32 arg2) {
    Unk_e80580(reinterpret_cast<u64>(view), arg1, arg2);
}

// Functions of the option bars: tools/leafgen.py's placeholders, with the
// bar as a u64.
void Unk_eb7730(u64 bar);
void Unk_eb77f0(u64 bar);
bool Unk_eb7830(u64 bar);
inline void Unk_eb7730(Unk_23f6118* bar) {
    Unk_eb7730(reinterpret_cast<u64>(bar));
}
inline void Unk_eb77f0(Unk_23f6118* bar) {
    Unk_eb77f0(reinterpret_cast<u64>(bar));
}
inline bool Unk_eb7830(Unk_23f6118* bar) {
    return Unk_eb7830(reinterpret_cast<u64>(bar));
}

// What a system message view shows (0x18 bytes): the message, and flags.
struct Unk_eb8930_Params {
    Unk_eb8930_Params()
        : field_0(nullptr),
          field_8(0),
          field_c(0),
          field_10(true),
          field_11(true),
          field_12(false) {}

    Unk_239a418* field_0;
    u32 field_8;
    u32 field_c;
    bool field_10;
    bool field_11;
    bool field_12;
};
static_assert(sizeof(Unk_eb8930_Params) == 0x18, "Unk_eb8930_Params");

// tools/leafgen.py's placeholder, with the view as a u64.
bool Unk_eb8e80(u64 view);

// A system message view (vtable 0x71023f6218): the views named
// "SystemMessageView".
class Unk_23f6218 : public Unk_23f6328 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6328::Unk_GetType());
        return &type;
    }

    // Shows a message (0x7100eb8930).
    void Unk_eb8930(const Unk_eb8930_Params& params);
    // Whether it's done (0x7100eb8e80).
    bool Unk_IsDoneEb8e80() { return Unk_eb8e80(reinterpret_cast<u64>(this)); }
};

// The type 0x71027e0b20.
class Unk_23f65d0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// A tips view (vtable 0x71023f64b0): the views named "TipsView".
class Unk_23f64b0 : public Unk_23f65d0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f65d0::Unk_GetType());
        return &type;
    }

    // Slot 17: whether it's done.
    virtual bool vf17();

    void Unk_ebb140(Unk_239a418_Ref<Unk_239a418> tips);
    void Unk_ebb290(bool value);
};

// What an attention view shows (0x10 bytes): a kind and the message.
struct Unk_eb5fb0_Params {
    Unk_eb5fb0_Params() : field_0(0), field_8(nullptr) {}

    u32 field_0;
    Unk_239a418* field_8;
};
static_assert(sizeof(Unk_eb5fb0_Params) == 0x10, "Unk_eb5fb0_Params");

// An attention view (vtable 0x71023f5fa8): the views named "AttentionView".
// Its getter's copy out of line is 0x7100eb6100 (tools/leafgen.py named it
// as a function of the view's vf_type, which tail-calls it).
class Unk_23f5fa8 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    // Shows a message (0x7100eb5fb0).
    void Unk_eb5fb0(const Unk_eb5fb0_Params& params);
};
