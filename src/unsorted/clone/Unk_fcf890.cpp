// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x7102403840: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403830 {
public:
    virtual ~Unk_2403830();
    virtual Unk_2403830* vf2();
    virtual void vf3(Unk_2403830* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403830) == 0x10, "Unk_2403830");

// 0x7100fcf890
Unk_2403830* Unk_2403830::vf2() {
    return new Unk_2403830(*this);
}

// 0x7100fcf8d0
void Unk_2403830::vf3(Unk_2403830* p) {
    new (p) Unk_2403830(*this);
}

// vtable 0x7102403888: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403878 {
public:
    virtual ~Unk_2403878();
    virtual Unk_2403878* vf2();
    virtual void vf3(Unk_2403878* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403878) == 0x10, "Unk_2403878");

// 0x7100fcf980
Unk_2403878* Unk_2403878::vf2() {
    return new Unk_2403878(*this);
}

// 0x7100fcf9c0
void Unk_2403878::vf3(Unk_2403878* p) {
    new (p) Unk_2403878(*this);
}

// vtable 0x71024038d0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24038c0 {
public:
    virtual ~Unk_24038c0();
    virtual Unk_24038c0* vf2();
    virtual void vf3(Unk_24038c0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24038c0) == 0x10, "Unk_24038c0");

// 0x7100fcfa70
Unk_24038c0* Unk_24038c0::vf2() {
    return new Unk_24038c0(*this);
}

// 0x7100fcfab0
void Unk_24038c0::vf3(Unk_24038c0* p) {
    new (p) Unk_24038c0(*this);
}

// vtable 0x7102403918: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403908 {
public:
    virtual ~Unk_2403908();
    virtual Unk_2403908* vf2();
    virtual void vf3(Unk_2403908* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403908) == 0x10, "Unk_2403908");

// 0x7100fcfb60
Unk_2403908* Unk_2403908::vf2() {
    return new Unk_2403908(*this);
}

// 0x7100fcfba0
void Unk_2403908::vf3(Unk_2403908* p) {
    new (p) Unk_2403908(*this);
}

// vtable 0x7102403960: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403950 {
public:
    virtual ~Unk_2403950();
    virtual Unk_2403950* vf2();
    virtual void vf3(Unk_2403950* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403950) == 0x10, "Unk_2403950");

// 0x7100fcfc50
Unk_2403950* Unk_2403950::vf2() {
    return new Unk_2403950(*this);
}

// 0x7100fcfc90
void Unk_2403950::vf3(Unk_2403950* p) {
    new (p) Unk_2403950(*this);
}

// vtable 0x71024039a8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403998 {
public:
    virtual ~Unk_2403998();
    virtual Unk_2403998* vf2();
    virtual void vf3(Unk_2403998* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403998) == 0x10, "Unk_2403998");

// 0x7100fcfd40
Unk_2403998* Unk_2403998::vf2() {
    return new Unk_2403998(*this);
}

// 0x7100fcfd80
void Unk_2403998::vf3(Unk_2403998* p) {
    new (p) Unk_2403998(*this);
}

// vtable 0x7102403d98: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403d88 {
public:
    virtual ~Unk_2403d88();
    virtual Unk_2403d88* vf2();
    virtual void vf3(Unk_2403d88* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403d88) == 0x10, "Unk_2403d88");

// 0x7100fd3760
Unk_2403d88* Unk_2403d88::vf2() {
    return new Unk_2403d88(*this);
}

// 0x7100fd37a0
void Unk_2403d88::vf3(Unk_2403d88* p) {
    new (p) Unk_2403d88(*this);
}

// vtable 0x7102403de0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403dd0 {
public:
    virtual ~Unk_2403dd0();
    virtual Unk_2403dd0* vf2();
    virtual void vf3(Unk_2403dd0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403dd0) == 0x10, "Unk_2403dd0");

// 0x7100fd3850
Unk_2403dd0* Unk_2403dd0::vf2() {
    return new Unk_2403dd0(*this);
}

// 0x7100fd3890
void Unk_2403dd0::vf3(Unk_2403dd0* p) {
    new (p) Unk_2403dd0(*this);
}

// vtable 0x7102403e28: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403e18 {
public:
    virtual ~Unk_2403e18();
    virtual Unk_2403e18* vf2();
    virtual void vf3(Unk_2403e18* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403e18) == 0x10, "Unk_2403e18");

// 0x7100fd3940
Unk_2403e18* Unk_2403e18::vf2() {
    return new Unk_2403e18(*this);
}

// 0x7100fd3980
void Unk_2403e18::vf3(Unk_2403e18* p) {
    new (p) Unk_2403e18(*this);
}

// vtable 0x7102403f98: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403f88 {
public:
    virtual ~Unk_2403f88();
    virtual Unk_2403f88* vf2();
    virtual void vf3(Unk_2403f88* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403f88) == 0x10, "Unk_2403f88");

// 0x7100fd63c0
Unk_2403f88* Unk_2403f88::vf2() {
    return new Unk_2403f88(*this);
}

// 0x7100fd6400
void Unk_2403f88::vf3(Unk_2403f88* p) {
    new (p) Unk_2403f88(*this);
}

// vtable 0x7102403fe0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2403fd0 {
public:
    virtual ~Unk_2403fd0();
    virtual Unk_2403fd0* vf2();
    virtual void vf3(Unk_2403fd0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2403fd0) == 0x10, "Unk_2403fd0");

// 0x7100fd6490
Unk_2403fd0* Unk_2403fd0::vf2() {
    return new Unk_2403fd0(*this);
}

// 0x7100fd64d0
void Unk_2403fd0::vf3(Unk_2403fd0* p) {
    new (p) Unk_2403fd0(*this);
}

// vtable 0x7102404028: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404018 {
public:
    virtual ~Unk_2404018();
    virtual Unk_2404018* vf2();
    virtual void vf3(Unk_2404018* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404018) == 0x10, "Unk_2404018");

// 0x7100fd6530
Unk_2404018* Unk_2404018::vf2() {
    return new Unk_2404018(*this);
}

// 0x7100fd6570
void Unk_2404018::vf3(Unk_2404018* p) {
    new (p) Unk_2404018(*this);
}

// vtable 0x7102404070: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404060 {
public:
    virtual ~Unk_2404060();
    virtual Unk_2404060* vf2();
    virtual void vf3(Unk_2404060* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404060) == 0x10, "Unk_2404060");

// 0x7100fd65d0
Unk_2404060* Unk_2404060::vf2() {
    return new Unk_2404060(*this);
}

// 0x7100fd6610
void Unk_2404060::vf3(Unk_2404060* p) {
    new (p) Unk_2404060(*this);
}

// vtable 0x71024040b8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24040a8 {
public:
    virtual ~Unk_24040a8();
    virtual Unk_24040a8* vf2();
    virtual void vf3(Unk_24040a8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24040a8) == 0x10, "Unk_24040a8");

// 0x7100fd6670
Unk_24040a8* Unk_24040a8::vf2() {
    return new Unk_24040a8(*this);
}

// 0x7100fd66b0
void Unk_24040a8::vf3(Unk_24040a8* p) {
    new (p) Unk_24040a8(*this);
}

// vtable 0x7102404100: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24040f0 {
public:
    virtual ~Unk_24040f0();
    virtual Unk_24040f0* vf2();
    virtual void vf3(Unk_24040f0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24040f0) == 0x10, "Unk_24040f0");

// 0x7100fd6710
Unk_24040f0* Unk_24040f0::vf2() {
    return new Unk_24040f0(*this);
}

// 0x7100fd6750
void Unk_24040f0::vf3(Unk_24040f0* p) {
    new (p) Unk_24040f0(*this);
}

// vtable 0x7102404148: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404138 {
public:
    virtual ~Unk_2404138();
    virtual Unk_2404138* vf2();
    virtual void vf3(Unk_2404138* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404138) == 0x10, "Unk_2404138");

// 0x7100fd67b0
Unk_2404138* Unk_2404138::vf2() {
    return new Unk_2404138(*this);
}

// 0x7100fd67f0
void Unk_2404138::vf3(Unk_2404138* p) {
    new (p) Unk_2404138(*this);
}

// vtable 0x7102404190: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404180 {
public:
    virtual ~Unk_2404180();
    virtual Unk_2404180* vf2();
    virtual void vf3(Unk_2404180* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404180) == 0x10, "Unk_2404180");

// 0x7100fd6850
Unk_2404180* Unk_2404180::vf2() {
    return new Unk_2404180(*this);
}

// 0x7100fd6890
void Unk_2404180::vf3(Unk_2404180* p) {
    new (p) Unk_2404180(*this);
}

// vtable 0x71024041d8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24041c8 {
public:
    virtual ~Unk_24041c8();
    virtual Unk_24041c8* vf2();
    virtual void vf3(Unk_24041c8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24041c8) == 0x10, "Unk_24041c8");

// 0x7100fd68f0
Unk_24041c8* Unk_24041c8::vf2() {
    return new Unk_24041c8(*this);
}

// 0x7100fd6930
void Unk_24041c8::vf3(Unk_24041c8* p) {
    new (p) Unk_24041c8(*this);
}

// vtable 0x7102404220: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404210 {
public:
    virtual ~Unk_2404210();
    virtual Unk_2404210* vf2();
    virtual void vf3(Unk_2404210* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404210) == 0x10, "Unk_2404210");

// 0x7100fd6990
Unk_2404210* Unk_2404210::vf2() {
    return new Unk_2404210(*this);
}

// 0x7100fd69d0
void Unk_2404210::vf3(Unk_2404210* p) {
    new (p) Unk_2404210(*this);
}

// vtable 0x7102404268: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404258 {
public:
    virtual ~Unk_2404258();
    virtual Unk_2404258* vf2();
    virtual void vf3(Unk_2404258* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404258) == 0x10, "Unk_2404258");

// 0x7100fd6a30
Unk_2404258* Unk_2404258::vf2() {
    return new Unk_2404258(*this);
}

// 0x7100fd6a70
void Unk_2404258::vf3(Unk_2404258* p) {
    new (p) Unk_2404258(*this);
}

// vtable 0x71024042b0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24042a0 {
public:
    virtual ~Unk_24042a0();
    virtual Unk_24042a0* vf2();
    virtual void vf3(Unk_24042a0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24042a0) == 0x10, "Unk_24042a0");

// 0x7100fd6ad0
Unk_24042a0* Unk_24042a0::vf2() {
    return new Unk_24042a0(*this);
}

// 0x7100fd6b10
void Unk_24042a0::vf3(Unk_24042a0* p) {
    new (p) Unk_24042a0(*this);
}

// vtable 0x71024042f8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24042e8 {
public:
    virtual ~Unk_24042e8();
    virtual Unk_24042e8* vf2();
    virtual void vf3(Unk_24042e8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24042e8) == 0x10, "Unk_24042e8");

// 0x7100fd6b70
Unk_24042e8* Unk_24042e8::vf2() {
    return new Unk_24042e8(*this);
}

// 0x7100fd6bb0
void Unk_24042e8::vf3(Unk_24042e8* p) {
    new (p) Unk_24042e8(*this);
}

// vtable 0x7102404340: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404330 {
public:
    virtual ~Unk_2404330();
    virtual Unk_2404330* vf2();
    virtual void vf3(Unk_2404330* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404330) == 0x10, "Unk_2404330");

// 0x7100fd6c10
Unk_2404330* Unk_2404330::vf2() {
    return new Unk_2404330(*this);
}

// 0x7100fd6c50
void Unk_2404330::vf3(Unk_2404330* p) {
    new (p) Unk_2404330(*this);
}

// vtable 0x7102404388: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404378 {
public:
    virtual ~Unk_2404378();
    virtual Unk_2404378* vf2();
    virtual void vf3(Unk_2404378* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404378) == 0x10, "Unk_2404378");

// 0x7100fd6cb0
Unk_2404378* Unk_2404378::vf2() {
    return new Unk_2404378(*this);
}

// 0x7100fd6cf0
void Unk_2404378::vf3(Unk_2404378* p) {
    new (p) Unk_2404378(*this);
}

// vtable 0x71024043d0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24043c0 {
public:
    virtual ~Unk_24043c0();
    virtual Unk_24043c0* vf2();
    virtual void vf3(Unk_24043c0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24043c0) == 0x10, "Unk_24043c0");

// 0x7100fd6d50
Unk_24043c0* Unk_24043c0::vf2() {
    return new Unk_24043c0(*this);
}

// 0x7100fd6d90
void Unk_24043c0::vf3(Unk_24043c0* p) {
    new (p) Unk_24043c0(*this);
}

// vtable 0x7102404418: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404408 {
public:
    virtual ~Unk_2404408();
    virtual Unk_2404408* vf2();
    virtual void vf3(Unk_2404408* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404408) == 0x10, "Unk_2404408");

// 0x7100fd6df0
Unk_2404408* Unk_2404408::vf2() {
    return new Unk_2404408(*this);
}

// 0x7100fd6e30
void Unk_2404408::vf3(Unk_2404408* p) {
    new (p) Unk_2404408(*this);
}

// vtable 0x7102404460: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404450 {
public:
    virtual ~Unk_2404450();
    virtual Unk_2404450* vf2();
    virtual void vf3(Unk_2404450* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404450) == 0x10, "Unk_2404450");

// 0x7100fd6e90
Unk_2404450* Unk_2404450::vf2() {
    return new Unk_2404450(*this);
}

// 0x7100fd6ed0
void Unk_2404450::vf3(Unk_2404450* p) {
    new (p) Unk_2404450(*this);
}

// vtable 0x71024044a8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404498 {
public:
    virtual ~Unk_2404498();
    virtual Unk_2404498* vf2();
    virtual void vf3(Unk_2404498* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404498) == 0x10, "Unk_2404498");

// 0x7100fd6f30
Unk_2404498* Unk_2404498::vf2() {
    return new Unk_2404498(*this);
}

// 0x7100fd6f70
void Unk_2404498::vf3(Unk_2404498* p) {
    new (p) Unk_2404498(*this);
}

// vtable 0x71024044f0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24044e0 {
public:
    virtual ~Unk_24044e0();
    virtual Unk_24044e0* vf2();
    virtual void vf3(Unk_24044e0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24044e0) == 0x10, "Unk_24044e0");

// 0x7100fd6fd0
Unk_24044e0* Unk_24044e0::vf2() {
    return new Unk_24044e0(*this);
}

// 0x7100fd7010
void Unk_24044e0::vf3(Unk_24044e0* p) {
    new (p) Unk_24044e0(*this);
}

// vtable 0x7102404538: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404528 {
public:
    virtual ~Unk_2404528();
    virtual Unk_2404528* vf2();
    virtual void vf3(Unk_2404528* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404528) == 0x10, "Unk_2404528");

// 0x7100fd7070
Unk_2404528* Unk_2404528::vf2() {
    return new Unk_2404528(*this);
}

// 0x7100fd70b0
void Unk_2404528::vf3(Unk_2404528* p) {
    new (p) Unk_2404528(*this);
}

// vtable 0x7102404580: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404570 {
public:
    virtual ~Unk_2404570();
    virtual Unk_2404570* vf2();
    virtual void vf3(Unk_2404570* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404570) == 0x10, "Unk_2404570");

// 0x7100fd7110
Unk_2404570* Unk_2404570::vf2() {
    return new Unk_2404570(*this);
}

// 0x7100fd7150
void Unk_2404570::vf3(Unk_2404570* p) {
    new (p) Unk_2404570(*this);
}

// vtable 0x71024045c8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24045b8 {
public:
    virtual ~Unk_24045b8();
    virtual Unk_24045b8* vf2();
    virtual void vf3(Unk_24045b8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24045b8) == 0x10, "Unk_24045b8");

// 0x7100fd71b0
Unk_24045b8* Unk_24045b8::vf2() {
    return new Unk_24045b8(*this);
}

// 0x7100fd71f0
void Unk_24045b8::vf3(Unk_24045b8* p) {
    new (p) Unk_24045b8(*this);
}

// vtable 0x7102404610: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404600 {
public:
    virtual ~Unk_2404600();
    virtual Unk_2404600* vf2();
    virtual void vf3(Unk_2404600* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404600) == 0x10, "Unk_2404600");

// 0x7100fd7250
Unk_2404600* Unk_2404600::vf2() {
    return new Unk_2404600(*this);
}

// 0x7100fd7290
void Unk_2404600::vf3(Unk_2404600* p) {
    new (p) Unk_2404600(*this);
}

// vtable 0x7102404658: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404648 {
public:
    virtual ~Unk_2404648();
    virtual Unk_2404648* vf2();
    virtual void vf3(Unk_2404648* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404648) == 0x10, "Unk_2404648");

// 0x7100fd72f0
Unk_2404648* Unk_2404648::vf2() {
    return new Unk_2404648(*this);
}

// 0x7100fd7330
void Unk_2404648::vf3(Unk_2404648* p) {
    new (p) Unk_2404648(*this);
}

// vtable 0x71024046a0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404690 {
public:
    virtual ~Unk_2404690();
    virtual Unk_2404690* vf2();
    virtual void vf3(Unk_2404690* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404690) == 0x10, "Unk_2404690");

// 0x7100fd7390
Unk_2404690* Unk_2404690::vf2() {
    return new Unk_2404690(*this);
}

// 0x7100fd73d0
void Unk_2404690::vf3(Unk_2404690* p) {
    new (p) Unk_2404690(*this);
}

// vtable 0x71024046e8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24046d8 {
public:
    virtual ~Unk_24046d8();
    virtual Unk_24046d8* vf2();
    virtual void vf3(Unk_24046d8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24046d8) == 0x10, "Unk_24046d8");

// 0x7100fd7440
Unk_24046d8* Unk_24046d8::vf2() {
    return new Unk_24046d8(*this);
}

// 0x7100fd7480
void Unk_24046d8::vf3(Unk_24046d8* p) {
    new (p) Unk_24046d8(*this);
}

// vtable 0x7102404730: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404720 {
public:
    virtual ~Unk_2404720();
    virtual Unk_2404720* vf2();
    virtual void vf3(Unk_2404720* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404720) == 0x10, "Unk_2404720");

// 0x7100fd74e0
Unk_2404720* Unk_2404720::vf2() {
    return new Unk_2404720(*this);
}

// 0x7100fd7520
void Unk_2404720::vf3(Unk_2404720* p) {
    new (p) Unk_2404720(*this);
}

// vtable 0x7102404778: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404768 {
public:
    virtual ~Unk_2404768();
    virtual Unk_2404768* vf2();
    virtual void vf3(Unk_2404768* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404768) == 0x10, "Unk_2404768");

// 0x7100fd7580
Unk_2404768* Unk_2404768::vf2() {
    return new Unk_2404768(*this);
}

// 0x7100fd75c0
void Unk_2404768::vf3(Unk_2404768* p) {
    new (p) Unk_2404768(*this);
}

// vtable 0x71024047c0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24047b0 {
public:
    virtual ~Unk_24047b0();
    virtual Unk_24047b0* vf2();
    virtual void vf3(Unk_24047b0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24047b0) == 0x10, "Unk_24047b0");

// 0x7100fd7620
Unk_24047b0* Unk_24047b0::vf2() {
    return new Unk_24047b0(*this);
}

// 0x7100fd7660
void Unk_24047b0::vf3(Unk_24047b0* p) {
    new (p) Unk_24047b0(*this);
}

// vtable 0x7102404808: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24047f8 {
public:
    virtual ~Unk_24047f8();
    virtual Unk_24047f8* vf2();
    virtual void vf3(Unk_24047f8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24047f8) == 0x10, "Unk_24047f8");

// 0x7100fd76c0
Unk_24047f8* Unk_24047f8::vf2() {
    return new Unk_24047f8(*this);
}

// 0x7100fd7700
void Unk_24047f8::vf3(Unk_24047f8* p) {
    new (p) Unk_24047f8(*this);
}

// vtable 0x7102404850: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404840 {
public:
    virtual ~Unk_2404840();
    virtual Unk_2404840* vf2();
    virtual void vf3(Unk_2404840* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404840) == 0x10, "Unk_2404840");

// 0x7100fd7760
Unk_2404840* Unk_2404840::vf2() {
    return new Unk_2404840(*this);
}

// 0x7100fd77a0
void Unk_2404840::vf3(Unk_2404840* p) {
    new (p) Unk_2404840(*this);
}

// vtable 0x7102404898: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404888 {
public:
    virtual ~Unk_2404888();
    virtual Unk_2404888* vf2();
    virtual void vf3(Unk_2404888* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404888) == 0x10, "Unk_2404888");

// 0x7100fd7800
Unk_2404888* Unk_2404888::vf2() {
    return new Unk_2404888(*this);
}

// 0x7100fd7840
void Unk_2404888::vf3(Unk_2404888* p) {
    new (p) Unk_2404888(*this);
}

// vtable 0x71024048e0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24048d0 {
public:
    virtual ~Unk_24048d0();
    virtual Unk_24048d0* vf2();
    virtual void vf3(Unk_24048d0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24048d0) == 0x10, "Unk_24048d0");

// 0x7100fd78a0
Unk_24048d0* Unk_24048d0::vf2() {
    return new Unk_24048d0(*this);
}

// 0x7100fd78e0
void Unk_24048d0::vf3(Unk_24048d0* p) {
    new (p) Unk_24048d0(*this);
}

// vtable 0x7102404928: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404918 {
public:
    virtual ~Unk_2404918();
    virtual Unk_2404918* vf2();
    virtual void vf3(Unk_2404918* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404918) == 0x10, "Unk_2404918");

// 0x7100fd7940
Unk_2404918* Unk_2404918::vf2() {
    return new Unk_2404918(*this);
}

// 0x7100fd7980
void Unk_2404918::vf3(Unk_2404918* p) {
    new (p) Unk_2404918(*this);
}

// vtable 0x7102404970: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404960 {
public:
    virtual ~Unk_2404960();
    virtual Unk_2404960* vf2();
    virtual void vf3(Unk_2404960* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404960) == 0x10, "Unk_2404960");

// 0x7100fd79e0
Unk_2404960* Unk_2404960::vf2() {
    return new Unk_2404960(*this);
}

// 0x7100fd7a20
void Unk_2404960::vf3(Unk_2404960* p) {
    new (p) Unk_2404960(*this);
}

// vtable 0x71024049b8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24049a8 {
public:
    virtual ~Unk_24049a8();
    virtual Unk_24049a8* vf2();
    virtual void vf3(Unk_24049a8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24049a8) == 0x10, "Unk_24049a8");

// 0x7100fd7a80
Unk_24049a8* Unk_24049a8::vf2() {
    return new Unk_24049a8(*this);
}

// 0x7100fd7ac0
void Unk_24049a8::vf3(Unk_24049a8* p) {
    new (p) Unk_24049a8(*this);
}

// vtable 0x7102404a00: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24049f0 {
public:
    virtual ~Unk_24049f0();
    virtual Unk_24049f0* vf2();
    virtual void vf3(Unk_24049f0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_24049f0) == 0x10, "Unk_24049f0");

// 0x7100fd7b20
Unk_24049f0* Unk_24049f0::vf2() {
    return new Unk_24049f0(*this);
}

// 0x7100fd7b60
void Unk_24049f0::vf3(Unk_24049f0* p) {
    new (p) Unk_24049f0(*this);
}

// vtable 0x7102404a48: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404a38 {
public:
    virtual ~Unk_2404a38();
    virtual Unk_2404a38* vf2();
    virtual void vf3(Unk_2404a38* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404a38) == 0x10, "Unk_2404a38");

// 0x7100fd7bc0
Unk_2404a38* Unk_2404a38::vf2() {
    return new Unk_2404a38(*this);
}

// 0x7100fd7c00
void Unk_2404a38::vf3(Unk_2404a38* p) {
    new (p) Unk_2404a38(*this);
}

// vtable 0x7102404a90: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404a80 {
public:
    virtual ~Unk_2404a80();
    virtual Unk_2404a80* vf2();
    virtual void vf3(Unk_2404a80* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404a80) == 0x10, "Unk_2404a80");

// 0x7100fd7c60
Unk_2404a80* Unk_2404a80::vf2() {
    return new Unk_2404a80(*this);
}

// 0x7100fd7ca0
void Unk_2404a80::vf3(Unk_2404a80* p) {
    new (p) Unk_2404a80(*this);
}

// vtable 0x7102404ad8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404ac8 {
public:
    virtual ~Unk_2404ac8();
    virtual Unk_2404ac8* vf2();
    virtual void vf3(Unk_2404ac8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404ac8) == 0x10, "Unk_2404ac8");

// 0x7100fd7d00
Unk_2404ac8* Unk_2404ac8::vf2() {
    return new Unk_2404ac8(*this);
}

// 0x7100fd7d40
void Unk_2404ac8::vf3(Unk_2404ac8* p) {
    new (p) Unk_2404ac8(*this);
}

// vtable 0x7102404b20: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2404b10 {
public:
    virtual ~Unk_2404b10();
    virtual Unk_2404b10* vf2();
    virtual void vf3(Unk_2404b10* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2404b10) == 0x10, "Unk_2404b10");

// 0x7100fd7da0
Unk_2404b10* Unk_2404b10::vf2() {
    return new Unk_2404b10(*this);
}

// 0x7100fd7de0
void Unk_2404b10::vf3(Unk_2404b10* p) {
    new (p) Unk_2404b10(*this);
}
