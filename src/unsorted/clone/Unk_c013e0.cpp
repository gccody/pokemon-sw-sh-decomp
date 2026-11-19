// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023d7d38: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d7d28 {
public:
    virtual ~Unk_23d7d28();
    virtual Unk_23d7d28* vf2();
    virtual void vf3(Unk_23d7d28* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23d7d28) == 0x10, "Unk_23d7d28");

// 0x7100c013e0
Unk_23d7d28* Unk_23d7d28::vf2() {
    return new Unk_23d7d28(*this);
}

// 0x7100c01420
void Unk_23d7d28::vf3(Unk_23d7d28* p) {
    new (p) Unk_23d7d28(*this);
}

// vtable 0x71023d7d80: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d7d70 {
public:
    virtual ~Unk_23d7d70();
    virtual Unk_23d7d70* vf2();
    virtual void vf3(Unk_23d7d70* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23d7d70) == 0x10, "Unk_23d7d70");

// 0x7100c014a0
Unk_23d7d70* Unk_23d7d70::vf2() {
    return new Unk_23d7d70(*this);
}

// 0x7100c014e0
void Unk_23d7d70::vf3(Unk_23d7d70* p) {
    new (p) Unk_23d7d70(*this);
}

// vtable 0x71023d7ef8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d7ee8 {
public:
    virtual ~Unk_23d7ee8();
    virtual Unk_23d7ee8* vf2();
    virtual void vf3(Unk_23d7ee8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23d7ee8) == 0x10, "Unk_23d7ee8");

// 0x7100c035a0
Unk_23d7ee8* Unk_23d7ee8::vf2() {
    return new Unk_23d7ee8(*this);
}

// 0x7100c035e0
void Unk_23d7ee8::vf3(Unk_23d7ee8* p) {
    new (p) Unk_23d7ee8(*this);
}

// vtable 0x71023d8c70: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d8c60 {
public:
    virtual ~Unk_23d8c60();
    virtual Unk_23d8c60* vf2();
    virtual void vf3(Unk_23d8c60* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23d8c60) == 0x10, "Unk_23d8c60");

// 0x7100c0bfc0
Unk_23d8c60* Unk_23d8c60::vf2() {
    return new Unk_23d8c60(*this);
}

// 0x7100c0c000
void Unk_23d8c60::vf3(Unk_23d8c60* p) {
    new (p) Unk_23d8c60(*this);
}
