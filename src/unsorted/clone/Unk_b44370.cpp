// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023cf728: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cf718 {
public:
    virtual ~Unk_23cf718();
    virtual Unk_23cf718* vf2();
    virtual void vf3(Unk_23cf718* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cf718) == 0x10, "Unk_23cf718");

// 0x7100b44370
Unk_23cf718* Unk_23cf718::vf2() {
    return new Unk_23cf718(*this);
}

// 0x7100b443b0
void Unk_23cf718::vf3(Unk_23cf718* p) {
    new (p) Unk_23cf718(*this);
}

// vtable 0x71023cf958: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cf948 {
public:
    virtual ~Unk_23cf948();
    virtual Unk_23cf948* vf2();
    virtual void vf3(Unk_23cf948* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cf948) == 0x10, "Unk_23cf948");

// 0x7100b462b0
Unk_23cf948* Unk_23cf948::vf2() {
    return new Unk_23cf948(*this);
}

// 0x7100b462f0
void Unk_23cf948::vf3(Unk_23cf948* p) {
    new (p) Unk_23cf948(*this);
}

// vtable 0x71023cfac0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cfab0 {
public:
    virtual ~Unk_23cfab0();
    virtual Unk_23cfab0* vf2();
    virtual void vf3(Unk_23cfab0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cfab0) == 0x10, "Unk_23cfab0");

// 0x7100b48860
Unk_23cfab0* Unk_23cfab0::vf2() {
    return new Unk_23cfab0(*this);
}

// 0x7100b488a0
void Unk_23cfab0::vf3(Unk_23cfab0* p) {
    new (p) Unk_23cfab0(*this);
}

// vtable 0x71023cfb08: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cfaf8 {
public:
    virtual ~Unk_23cfaf8();
    virtual Unk_23cfaf8* vf2();
    virtual void vf3(Unk_23cfaf8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cfaf8) == 0x10, "Unk_23cfaf8");

// 0x7100b48940
Unk_23cfaf8* Unk_23cfaf8::vf2() {
    return new Unk_23cfaf8(*this);
}

// 0x7100b48980
void Unk_23cfaf8::vf3(Unk_23cfaf8* p) {
    new (p) Unk_23cfaf8(*this);
}

// vtable 0x71023cfb50: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cfb40 {
public:
    virtual ~Unk_23cfb40();
    virtual Unk_23cfb40* vf2();
    virtual void vf3(Unk_23cfb40* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cfb40) == 0x10, "Unk_23cfb40");

// 0x7100b48a20
Unk_23cfb40* Unk_23cfb40::vf2() {
    return new Unk_23cfb40(*this);
}

// 0x7100b48a60
void Unk_23cfb40::vf3(Unk_23cfb40* p) {
    new (p) Unk_23cfb40(*this);
}

// vtable 0x71023cfd00: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cfcf0 {
public:
    virtual ~Unk_23cfcf0();
    virtual Unk_23cfcf0* vf2();
    virtual void vf3(Unk_23cfcf0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cfcf0) == 0x10, "Unk_23cfcf0");

// 0x7100b49010
Unk_23cfcf0* Unk_23cfcf0::vf2() {
    return new Unk_23cfcf0(*this);
}

// 0x7100b49050
void Unk_23cfcf0::vf3(Unk_23cfcf0* p) {
    new (p) Unk_23cfcf0(*this);
}
