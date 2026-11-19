#pragma once
// The Pokedex app (prog/contents/pokedex: bin/appli/pokedex, the ZKN_*
// message labels): what its states use. Placeholder names: rename them once
// the classes are known.
#include <types.h>

#include "contents/common/framework.h"

// tools/leafgen.py's placeholders for accessors of the Pokedex's classes: the
// classes below forward to them.
struct Unk_15407f0;
u32 Unk_15407f0_getField5cc(const Unk_15407f0* self);
struct Unk_153bdd0;
void Unk_153bdd0_setField6c(Unk_153bdd0* self, u32 value);

void Unk_152a790_call(void* self);
void Unk_152c2a0_call(void* self);
void Unk_15248c0_call(void* self);

// The Pokedex's details view (vtable 0x7102447cf0: "ViewDetails").
class Unk_2447cf0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_1525470(Unk_23f6118* bar);
    void Unk_1525710(Unk_23f6118* bar);
    void Unk_1527a40(bool value);
};

// The list's background view (vtable 0x7102448020: "ViewBg").
class Unk_2448020 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The list view (vtable 0x71024482c0: "ViewList").
class Unk_24482c0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The Pokedex's top view (vtable 0x7102447e50: "ViewTop").
class Unk_2447e50 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_1528730();
};

// The registration's details view (vtable 0x7102449670: "ViewDetails").
class Unk_2449670 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    void Unk_1540610(bool value);
    void Unk_15405d0();
    void Unk_1541910();

    u32 Unk_GetField5cc() const {
        return Unk_15407f0_getField5cc(reinterpret_cast<const Unk_15407f0*>(this));
    }
};

// The registration app (vtable 0x7102449478): its states get it from their
// field_68.
class Unk_2449478 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();  // 0x710153dd60

    // The state to go to next.
    void Unk_SetField6c(u32 value) {
        Unk_153bdd0_setField6c(reinterpret_cast<Unk_153bdd0*>(this), value);
    }
};

inline Unk_2449478* Unk_RegisterApp(Unk_23f43c8* state) {
    return Unk_DynamicCast<Unk_2449478>(Unk_HandleObject(state->field_68));
}

// The Pokedex app (vtable 0x7102447af8): its states get it from their field_68.
class Unk_2447af8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();  // 0x7101520be0

    void Unk_151ccc0();
    void Unk_151cd20(u32 arg);
};

inline Unk_2447af8* Unk_DexApp(Unk_23f43c8* state) {
    return Unk_DynamicCast<Unk_2447af8>(Unk_HandleObject(state->field_68));
}
