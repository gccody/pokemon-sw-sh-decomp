// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023c28f8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c28e8 {
public:
    virtual ~Unk_23c28e8();
    virtual Unk_23c28e8* vf2();
    virtual void vf3(Unk_23c28e8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c28e8) == 0x10, "Unk_23c28e8");

// 0x710098de90
Unk_23c28e8* Unk_23c28e8::vf2() {
    return new Unk_23c28e8(*this);
}

// 0x710098ded0
void Unk_23c28e8::vf3(Unk_23c28e8* p) {
    new (p) Unk_23c28e8(*this);
}

// vtable 0x71023c2940: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2930 {
public:
    virtual ~Unk_23c2930();
    virtual Unk_23c2930* vf2();
    virtual void vf3(Unk_23c2930* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2930) == 0x18, "Unk_23c2930");

// 0x710098dfe0
Unk_23c2930* Unk_23c2930::vf2() {
    return new Unk_23c2930(*this);
}

// 0x710098e020
void Unk_23c2930::vf3(Unk_23c2930* p) {
    new (p) Unk_23c2930(*this);
}

// vtable 0x71023c2988: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2978 {
public:
    virtual ~Unk_23c2978();
    virtual Unk_23c2978* vf2();
    virtual void vf3(Unk_23c2978* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2978) == 0x18, "Unk_23c2978");

// 0x710098e0e0
Unk_23c2978* Unk_23c2978::vf2() {
    return new Unk_23c2978(*this);
}

// 0x710098e120
void Unk_23c2978::vf3(Unk_23c2978* p) {
    new (p) Unk_23c2978(*this);
}
