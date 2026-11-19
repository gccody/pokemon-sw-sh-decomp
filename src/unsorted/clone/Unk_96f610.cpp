// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023c1608: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c15f8 {
public:
    virtual ~Unk_23c15f8();
    virtual Unk_23c15f8* vf2();
    virtual void vf3(Unk_23c15f8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c15f8) == 0x10, "Unk_23c15f8");

// 0x710096f610
Unk_23c15f8* Unk_23c15f8::vf2() {
    return new Unk_23c15f8(*this);
}

// 0x710096f650
void Unk_23c15f8::vf3(Unk_23c15f8* p) {
    new (p) Unk_23c15f8(*this);
}

// vtable 0x71023c1fc0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c1fb0 {
public:
    virtual ~Unk_23c1fb0();
    virtual Unk_23c1fb0* vf2();
    virtual void vf3(Unk_23c1fb0* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c1fb0) == 0x18, "Unk_23c1fb0");

// 0x7100985dc0
Unk_23c1fb0* Unk_23c1fb0::vf2() {
    return new Unk_23c1fb0(*this);
}

// 0x7100985e00
void Unk_23c1fb0::vf3(Unk_23c1fb0* p) {
    new (p) Unk_23c1fb0(*this);
}

// vtable 0x71023c2050: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2040 {
public:
    virtual ~Unk_23c2040();
    virtual Unk_23c2040* vf2();
    virtual void vf3(Unk_23c2040* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2040) == 0x18, "Unk_23c2040");

// 0x71009866c0
Unk_23c2040* Unk_23c2040::vf2() {
    return new Unk_23c2040(*this);
}

// 0x7100986700
void Unk_23c2040::vf3(Unk_23c2040* p) {
    new (p) Unk_23c2040(*this);
}

// vtable 0x71023c2098: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2088 {
public:
    virtual ~Unk_23c2088();
    virtual Unk_23c2088* vf2();
    virtual void vf3(Unk_23c2088* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2088) == 0x18, "Unk_23c2088");

// 0x71009867c0
Unk_23c2088* Unk_23c2088::vf2() {
    return new Unk_23c2088(*this);
}

// 0x7100986800
void Unk_23c2088::vf3(Unk_23c2088* p) {
    new (p) Unk_23c2088(*this);
}

// vtable 0x71023c20e0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c20d0 {
public:
    virtual ~Unk_23c20d0();
    virtual Unk_23c20d0* vf2();
    virtual void vf3(Unk_23c20d0* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c20d0) == 0x18, "Unk_23c20d0");

// 0x71009868d0
Unk_23c20d0* Unk_23c20d0::vf2() {
    return new Unk_23c20d0(*this);
}

// 0x7100986910
void Unk_23c20d0::vf3(Unk_23c20d0* p) {
    new (p) Unk_23c20d0(*this);
}

// vtable 0x71023c2128: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2118 {
public:
    virtual ~Unk_23c2118();
    virtual Unk_23c2118* vf2();
    virtual void vf3(Unk_23c2118* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2118) == 0x18, "Unk_23c2118");

// 0x71009869d0
Unk_23c2118* Unk_23c2118::vf2() {
    return new Unk_23c2118(*this);
}

// 0x7100986a10
void Unk_23c2118::vf3(Unk_23c2118* p) {
    new (p) Unk_23c2118(*this);
}

// vtable 0x71023c2170: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2160 {
public:
    virtual ~Unk_23c2160();
    virtual Unk_23c2160* vf2();
    virtual void vf3(Unk_23c2160* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c2160) == 0x10, "Unk_23c2160");

// 0x7100987140
Unk_23c2160* Unk_23c2160::vf2() {
    return new Unk_23c2160(*this);
}

// 0x7100987180
void Unk_23c2160::vf3(Unk_23c2160* p) {
    new (p) Unk_23c2160(*this);
}

// vtable 0x71023c21b8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c21a8 {
public:
    virtual ~Unk_23c21a8();
    virtual Unk_23c21a8* vf2();
    virtual void vf3(Unk_23c21a8* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c21a8) == 0x18, "Unk_23c21a8");

// 0x7100987480
Unk_23c21a8* Unk_23c21a8::vf2() {
    return new Unk_23c21a8(*this);
}

// 0x71009874c0
void Unk_23c21a8::vf3(Unk_23c21a8* p) {
    new (p) Unk_23c21a8(*this);
}

// vtable 0x71023c2200: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c21f0 {
public:
    virtual ~Unk_23c21f0();
    virtual Unk_23c21f0* vf2();
    virtual void vf3(Unk_23c21f0* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c21f0) == 0x18, "Unk_23c21f0");

// 0x7100987650
Unk_23c21f0* Unk_23c21f0::vf2() {
    return new Unk_23c21f0(*this);
}

// 0x7100987690
void Unk_23c21f0::vf3(Unk_23c21f0* p) {
    new (p) Unk_23c21f0(*this);
}

// vtable 0x71023c2248: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2238 {
public:
    virtual ~Unk_23c2238();
    virtual Unk_23c2238* vf2();
    virtual void vf3(Unk_23c2238* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2238) == 0x18, "Unk_23c2238");

// 0x7100987810
Unk_23c2238* Unk_23c2238::vf2() {
    return new Unk_23c2238(*this);
}

// 0x7100987850
void Unk_23c2238::vf3(Unk_23c2238* p) {
    new (p) Unk_23c2238(*this);
}

// vtable 0x71023c2290: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2280 {
public:
    virtual ~Unk_23c2280();
    virtual Unk_23c2280* vf2();
    virtual void vf3(Unk_23c2280* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2280) == 0x18, "Unk_23c2280");

// 0x7100987980
Unk_23c2280* Unk_23c2280::vf2() {
    return new Unk_23c2280(*this);
}

// 0x71009879c0
void Unk_23c2280::vf3(Unk_23c2280* p) {
    new (p) Unk_23c2280(*this);
}

// vtable 0x71023c22d8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c22c8 {
public:
    virtual ~Unk_23c22c8();
    virtual Unk_23c22c8* vf2();
    virtual void vf3(Unk_23c22c8* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c22c8) == 0x18, "Unk_23c22c8");

// 0x7100987a90
Unk_23c22c8* Unk_23c22c8::vf2() {
    return new Unk_23c22c8(*this);
}

// 0x7100987ad0
void Unk_23c22c8::vf3(Unk_23c22c8* p) {
    new (p) Unk_23c22c8(*this);
}

// vtable 0x71023c2320: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c2310 {
public:
    virtual ~Unk_23c2310();
    virtual Unk_23c2310* vf2();
    virtual void vf3(Unk_23c2310* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23c2310) == 0x18, "Unk_23c2310");

// 0x7100987ba0
Unk_23c2310* Unk_23c2310::vf2() {
    return new Unk_23c2310(*this);
}

// 0x7100987be0
void Unk_23c2310::vf3(Unk_23c2310* p) {
    new (p) Unk_23c2310(*this);
}
