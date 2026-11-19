// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023d24c0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d24b0 {
public:
    virtual ~Unk_23d24b0();
    virtual Unk_23d24b0* vf2();
    virtual void vf3(Unk_23d24b0* p);

    alignas(16) u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23d24b0) == 0x20, "Unk_23d24b0");

// 0x7100b991b0
Unk_23d24b0* Unk_23d24b0::vf2() {
    return new Unk_23d24b0(*this);
}

// 0x7100b991f0
void Unk_23d24b0::vf3(Unk_23d24b0* p) {
    new (p) Unk_23d24b0(*this);
}

// vtable 0x71023d2508: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d24f8 {
public:
    virtual ~Unk_23d24f8();
    virtual Unk_23d24f8* vf2();
    virtual void vf3(Unk_23d24f8* p);

    alignas(16) u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23d24f8) == 0x20, "Unk_23d24f8");

// 0x7100b99540
Unk_23d24f8* Unk_23d24f8::vf2() {
    return new Unk_23d24f8(*this);
}

// 0x7100b99580
void Unk_23d24f8::vf3(Unk_23d24f8* p) {
    new (p) Unk_23d24f8(*this);
}

// vtable 0x71023d2550: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d2540 {
public:
    virtual ~Unk_23d2540();
    virtual Unk_23d2540* vf2();
    virtual void vf3(Unk_23d2540* p);

    alignas(16) u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23d2540) == 0x20, "Unk_23d2540");

// 0x7100b998d0
Unk_23d2540* Unk_23d2540::vf2() {
    return new Unk_23d2540(*this);
}

// 0x7100b99910
void Unk_23d2540::vf3(Unk_23d2540* p) {
    new (p) Unk_23d2540(*this);
}

// vtable 0x71023d2598: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d2588 {
public:
    virtual ~Unk_23d2588();
    virtual Unk_23d2588* vf2();
    virtual void vf3(Unk_23d2588* p);

    alignas(16) u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23d2588) == 0x20, "Unk_23d2588");

// 0x7100b99da0
Unk_23d2588* Unk_23d2588::vf2() {
    return new Unk_23d2588(*this);
}

// 0x7100b99de0
void Unk_23d2588::vf3(Unk_23d2588* p) {
    new (p) Unk_23d2588(*this);
}

// vtable 0x71023d25e0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d25d0 {
public:
    virtual ~Unk_23d25d0();
    virtual Unk_23d25d0* vf2();
    virtual void vf3(Unk_23d25d0* p);

    alignas(16) u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23d25d0) == 0x20, "Unk_23d25d0");

// 0x7100b99fd0
Unk_23d25d0* Unk_23d25d0::vf2() {
    return new Unk_23d25d0(*this);
}

// 0x7100b9a010
void Unk_23d25d0::vf3(Unk_23d25d0* p) {
    new (p) Unk_23d25d0(*this);
}

// vtable 0x71023d2628: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d2618 {
public:
    virtual ~Unk_23d2618();
    virtual Unk_23d2618* vf2();
    virtual void vf3(Unk_23d2618* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23d2618) == 0x10, "Unk_23d2618");

// 0x7100b9a200
Unk_23d2618* Unk_23d2618::vf2() {
    return new Unk_23d2618(*this);
}

// 0x7100b9a240
void Unk_23d2618::vf3(Unk_23d2618* p) {
    new (p) Unk_23d2618(*this);
}

// vtable 0x71023d2670: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23d2660 {
public:
    virtual ~Unk_23d2660();
    virtual Unk_23d2660* vf2();
    virtual void vf3(Unk_23d2660* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23d2660) == 0x18, "Unk_23d2660");

// 0x7100b9a2e0
Unk_23d2660* Unk_23d2660::vf2() {
    return new Unk_23d2660(*this);
}

// 0x7100b9a320
void Unk_23d2660::vf3(Unk_23d2660* p) {
    new (p) Unk_23d2660(*this);
}
