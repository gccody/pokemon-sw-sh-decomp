// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023c98c0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c98b0 {
public:
    virtual ~Unk_23c98b0();
    virtual Unk_23c98b0* vf2();
    virtual void vf3(Unk_23c98b0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c98b0) == 0x10, "Unk_23c98b0");

// 0x7100ad7090
Unk_23c98b0* Unk_23c98b0::vf2() {
    return new Unk_23c98b0(*this);
}

// 0x7100ad70d0
void Unk_23c98b0::vf3(Unk_23c98b0* p) {
    new (p) Unk_23c98b0(*this);
}

// vtable 0x71023c9908: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c98f8 {
public:
    virtual ~Unk_23c98f8();
    virtual Unk_23c98f8* vf2();
    virtual void vf3(Unk_23c98f8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c98f8) == 0x10, "Unk_23c98f8");

// 0x7100ad7190
Unk_23c98f8* Unk_23c98f8::vf2() {
    return new Unk_23c98f8(*this);
}

// 0x7100ad71d0
void Unk_23c98f8::vf3(Unk_23c98f8* p) {
    new (p) Unk_23c98f8(*this);
}

// vtable 0x71023c9950: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9940 {
public:
    virtual ~Unk_23c9940();
    virtual Unk_23c9940* vf2();
    virtual void vf3(Unk_23c9940* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9940) == 0x10, "Unk_23c9940");

// 0x7100ad7280
Unk_23c9940* Unk_23c9940::vf2() {
    return new Unk_23c9940(*this);
}

// 0x7100ad72c0
void Unk_23c9940::vf3(Unk_23c9940* p) {
    new (p) Unk_23c9940(*this);
}

// vtable 0x71023c9ac0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9ab0 {
public:
    virtual ~Unk_23c9ab0();
    virtual Unk_23c9ab0* vf2();
    virtual void vf3(Unk_23c9ab0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9ab0) == 0x10, "Unk_23c9ab0");

// 0x7100ad9340
Unk_23c9ab0* Unk_23c9ab0::vf2() {
    return new Unk_23c9ab0(*this);
}

// 0x7100ad9380
void Unk_23c9ab0::vf3(Unk_23c9ab0* p) {
    new (p) Unk_23c9ab0(*this);
}

// vtable 0x71023c9b08: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9af8 {
public:
    virtual ~Unk_23c9af8();
    virtual Unk_23c9af8* vf2();
    virtual void vf3(Unk_23c9af8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9af8) == 0x10, "Unk_23c9af8");

// 0x7100ad9780
Unk_23c9af8* Unk_23c9af8::vf2() {
    return new Unk_23c9af8(*this);
}

// 0x7100ad97c0
void Unk_23c9af8::vf3(Unk_23c9af8* p) {
    new (p) Unk_23c9af8(*this);
}

// vtable 0x71023c9b50: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9b40 {
public:
    virtual ~Unk_23c9b40();
    virtual Unk_23c9b40* vf2();
    virtual void vf3(Unk_23c9b40* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9b40) == 0x10, "Unk_23c9b40");

// 0x7100ad9870
Unk_23c9b40* Unk_23c9b40::vf2() {
    return new Unk_23c9b40(*this);
}

// 0x7100ad98b0
void Unk_23c9b40::vf3(Unk_23c9b40* p) {
    new (p) Unk_23c9b40(*this);
}

// vtable 0x71023c9b98: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9b88 {
public:
    virtual ~Unk_23c9b88();
    virtual Unk_23c9b88* vf2();
    virtual void vf3(Unk_23c9b88* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9b88) == 0x10, "Unk_23c9b88");

// 0x7100ad9960
Unk_23c9b88* Unk_23c9b88::vf2() {
    return new Unk_23c9b88(*this);
}

// 0x7100ad99a0
void Unk_23c9b88::vf3(Unk_23c9b88* p) {
    new (p) Unk_23c9b88(*this);
}

// vtable 0x71023c9be0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9bd0 {
public:
    virtual ~Unk_23c9bd0();
    virtual Unk_23c9bd0* vf2();
    virtual void vf3(Unk_23c9bd0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9bd0) == 0x10, "Unk_23c9bd0");

// 0x7100ad9a50
Unk_23c9bd0* Unk_23c9bd0::vf2() {
    return new Unk_23c9bd0(*this);
}

// 0x7100ad9a90
void Unk_23c9bd0::vf3(Unk_23c9bd0* p) {
    new (p) Unk_23c9bd0(*this);
}

// vtable 0x71023c9c28: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c9c18 {
public:
    virtual ~Unk_23c9c18();
    virtual Unk_23c9c18* vf2();
    virtual void vf3(Unk_23c9c18* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c9c18) == 0x10, "Unk_23c9c18");

// 0x7100ad9b40
Unk_23c9c18* Unk_23c9c18::vf2() {
    return new Unk_23c9c18(*this);
}

// 0x7100ad9b80
void Unk_23c9c18::vf3(Unk_23c9c18* p) {
    new (p) Unk_23c9c18(*this);
}

// vtable 0x71023ca128: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca118 {
public:
    virtual ~Unk_23ca118();
    virtual Unk_23ca118* vf2();
    virtual void vf3(Unk_23ca118* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca118) == 0x10, "Unk_23ca118");

// 0x7100adca40
Unk_23ca118* Unk_23ca118::vf2() {
    return new Unk_23ca118(*this);
}

// 0x7100adca80
void Unk_23ca118::vf3(Unk_23ca118* p) {
    new (p) Unk_23ca118(*this);
}

// vtable 0x71023ca170: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca160 {
public:
    virtual ~Unk_23ca160();
    virtual Unk_23ca160* vf2();
    virtual void vf3(Unk_23ca160* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca160) == 0x10, "Unk_23ca160");

// 0x7100adcb30
Unk_23ca160* Unk_23ca160::vf2() {
    return new Unk_23ca160(*this);
}

// 0x7100adcb70
void Unk_23ca160::vf3(Unk_23ca160* p) {
    new (p) Unk_23ca160(*this);
}

// vtable 0x71023ca540: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca530 {
public:
    virtual ~Unk_23ca530();
    virtual Unk_23ca530* vf2();
    virtual void vf3(Unk_23ca530* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca530) == 0x10, "Unk_23ca530");

// 0x7100ae47b0
Unk_23ca530* Unk_23ca530::vf2() {
    return new Unk_23ca530(*this);
}

// 0x7100ae47f0
void Unk_23ca530::vf3(Unk_23ca530* p) {
    new (p) Unk_23ca530(*this);
}

// vtable 0x71023ca588: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca578 {
public:
    virtual ~Unk_23ca578();
    virtual Unk_23ca578* vf2();
    virtual void vf3(Unk_23ca578* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca578) == 0x10, "Unk_23ca578");

// 0x7100ae4880
Unk_23ca578* Unk_23ca578::vf2() {
    return new Unk_23ca578(*this);
}

// 0x7100ae48c0
void Unk_23ca578::vf3(Unk_23ca578* p) {
    new (p) Unk_23ca578(*this);
}

// vtable 0x71023ca5d0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca5c0 {
public:
    virtual ~Unk_23ca5c0();
    virtual Unk_23ca5c0* vf2();
    virtual void vf3(Unk_23ca5c0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca5c0) == 0x10, "Unk_23ca5c0");

// 0x7100ae4920
Unk_23ca5c0* Unk_23ca5c0::vf2() {
    return new Unk_23ca5c0(*this);
}

// 0x7100ae4960
void Unk_23ca5c0::vf3(Unk_23ca5c0* p) {
    new (p) Unk_23ca5c0(*this);
}

// vtable 0x71023ca618: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca608 {
public:
    virtual ~Unk_23ca608();
    virtual Unk_23ca608* vf2();
    virtual void vf3(Unk_23ca608* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca608) == 0x10, "Unk_23ca608");

// 0x7100ae49c0
Unk_23ca608* Unk_23ca608::vf2() {
    return new Unk_23ca608(*this);
}

// 0x7100ae4a00
void Unk_23ca608::vf3(Unk_23ca608* p) {
    new (p) Unk_23ca608(*this);
}

// vtable 0x71023ca660: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca650 {
public:
    virtual ~Unk_23ca650();
    virtual Unk_23ca650* vf2();
    virtual void vf3(Unk_23ca650* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca650) == 0x10, "Unk_23ca650");

// 0x7100ae4a60
Unk_23ca650* Unk_23ca650::vf2() {
    return new Unk_23ca650(*this);
}

// 0x7100ae4aa0
void Unk_23ca650::vf3(Unk_23ca650* p) {
    new (p) Unk_23ca650(*this);
}

// vtable 0x71023ca6a8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca698 {
public:
    virtual ~Unk_23ca698();
    virtual Unk_23ca698* vf2();
    virtual void vf3(Unk_23ca698* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca698) == 0x10, "Unk_23ca698");

// 0x7100ae4b00
Unk_23ca698* Unk_23ca698::vf2() {
    return new Unk_23ca698(*this);
}

// 0x7100ae4b40
void Unk_23ca698::vf3(Unk_23ca698* p) {
    new (p) Unk_23ca698(*this);
}

// vtable 0x71023ca6f0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca6e0 {
public:
    virtual ~Unk_23ca6e0();
    virtual Unk_23ca6e0* vf2();
    virtual void vf3(Unk_23ca6e0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca6e0) == 0x10, "Unk_23ca6e0");

// 0x7100ae4ba0
Unk_23ca6e0* Unk_23ca6e0::vf2() {
    return new Unk_23ca6e0(*this);
}

// 0x7100ae4be0
void Unk_23ca6e0::vf3(Unk_23ca6e0* p) {
    new (p) Unk_23ca6e0(*this);
}

// vtable 0x71023ca738: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca728 {
public:
    virtual ~Unk_23ca728();
    virtual Unk_23ca728* vf2();
    virtual void vf3(Unk_23ca728* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca728) == 0x10, "Unk_23ca728");

// 0x7100ae4c40
Unk_23ca728* Unk_23ca728::vf2() {
    return new Unk_23ca728(*this);
}

// 0x7100ae4c80
void Unk_23ca728::vf3(Unk_23ca728* p) {
    new (p) Unk_23ca728(*this);
}

// vtable 0x71023ca780: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca770 {
public:
    virtual ~Unk_23ca770();
    virtual Unk_23ca770* vf2();
    virtual void vf3(Unk_23ca770* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca770) == 0x10, "Unk_23ca770");

// 0x7100ae4ce0
Unk_23ca770* Unk_23ca770::vf2() {
    return new Unk_23ca770(*this);
}

// 0x7100ae4d20
void Unk_23ca770::vf3(Unk_23ca770* p) {
    new (p) Unk_23ca770(*this);
}

// vtable 0x71023ca7c8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca7b8 {
public:
    virtual ~Unk_23ca7b8();
    virtual Unk_23ca7b8* vf2();
    virtual void vf3(Unk_23ca7b8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca7b8) == 0x10, "Unk_23ca7b8");

// 0x7100ae4d80
Unk_23ca7b8* Unk_23ca7b8::vf2() {
    return new Unk_23ca7b8(*this);
}

// 0x7100ae4dc0
void Unk_23ca7b8::vf3(Unk_23ca7b8* p) {
    new (p) Unk_23ca7b8(*this);
}

// vtable 0x71023ca810: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca800 {
public:
    virtual ~Unk_23ca800();
    virtual Unk_23ca800* vf2();
    virtual void vf3(Unk_23ca800* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca800) == 0x10, "Unk_23ca800");

// 0x7100ae4e20
Unk_23ca800* Unk_23ca800::vf2() {
    return new Unk_23ca800(*this);
}

// 0x7100ae4e60
void Unk_23ca800::vf3(Unk_23ca800* p) {
    new (p) Unk_23ca800(*this);
}

// vtable 0x71023ca858: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca848 {
public:
    virtual ~Unk_23ca848();
    virtual Unk_23ca848* vf2();
    virtual void vf3(Unk_23ca848* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca848) == 0x10, "Unk_23ca848");

// 0x7100ae4ec0
Unk_23ca848* Unk_23ca848::vf2() {
    return new Unk_23ca848(*this);
}

// 0x7100ae4f00
void Unk_23ca848::vf3(Unk_23ca848* p) {
    new (p) Unk_23ca848(*this);
}

// vtable 0x71023ca8a0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca890 {
public:
    virtual ~Unk_23ca890();
    virtual Unk_23ca890* vf2();
    virtual void vf3(Unk_23ca890* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca890) == 0x10, "Unk_23ca890");

// 0x7100ae4f60
Unk_23ca890* Unk_23ca890::vf2() {
    return new Unk_23ca890(*this);
}

// 0x7100ae4fa0
void Unk_23ca890::vf3(Unk_23ca890* p) {
    new (p) Unk_23ca890(*this);
}

// vtable 0x71023ca8e8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca8d8 {
public:
    virtual ~Unk_23ca8d8();
    virtual Unk_23ca8d8* vf2();
    virtual void vf3(Unk_23ca8d8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca8d8) == 0x10, "Unk_23ca8d8");

// 0x7100ae5000
Unk_23ca8d8* Unk_23ca8d8::vf2() {
    return new Unk_23ca8d8(*this);
}

// 0x7100ae5040
void Unk_23ca8d8::vf3(Unk_23ca8d8* p) {
    new (p) Unk_23ca8d8(*this);
}

// vtable 0x71023ca930: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca920 {
public:
    virtual ~Unk_23ca920();
    virtual Unk_23ca920* vf2();
    virtual void vf3(Unk_23ca920* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca920) == 0x10, "Unk_23ca920");

// 0x7100ae50a0
Unk_23ca920* Unk_23ca920::vf2() {
    return new Unk_23ca920(*this);
}

// 0x7100ae50e0
void Unk_23ca920::vf3(Unk_23ca920* p) {
    new (p) Unk_23ca920(*this);
}

// vtable 0x71023ca978: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca968 {
public:
    virtual ~Unk_23ca968();
    virtual Unk_23ca968* vf2();
    virtual void vf3(Unk_23ca968* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca968) == 0x10, "Unk_23ca968");

// 0x7100ae5140
Unk_23ca968* Unk_23ca968::vf2() {
    return new Unk_23ca968(*this);
}

// 0x7100ae5180
void Unk_23ca968::vf3(Unk_23ca968* p) {
    new (p) Unk_23ca968(*this);
}

// vtable 0x71023ca9c0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca9b0 {
public:
    virtual ~Unk_23ca9b0();
    virtual Unk_23ca9b0* vf2();
    virtual void vf3(Unk_23ca9b0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca9b0) == 0x10, "Unk_23ca9b0");

// 0x7100ae51e0
Unk_23ca9b0* Unk_23ca9b0::vf2() {
    return new Unk_23ca9b0(*this);
}

// 0x7100ae5220
void Unk_23ca9b0::vf3(Unk_23ca9b0* p) {
    new (p) Unk_23ca9b0(*this);
}

// vtable 0x71023caa08: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ca9f8 {
public:
    virtual ~Unk_23ca9f8();
    virtual Unk_23ca9f8* vf2();
    virtual void vf3(Unk_23ca9f8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ca9f8) == 0x10, "Unk_23ca9f8");

// 0x7100ae5280
Unk_23ca9f8* Unk_23ca9f8::vf2() {
    return new Unk_23ca9f8(*this);
}

// 0x7100ae52c0
void Unk_23ca9f8::vf3(Unk_23ca9f8* p) {
    new (p) Unk_23ca9f8(*this);
}

// vtable 0x71023caa50: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caa40 {
public:
    virtual ~Unk_23caa40();
    virtual Unk_23caa40* vf2();
    virtual void vf3(Unk_23caa40* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caa40) == 0x10, "Unk_23caa40");

// 0x7100ae5320
Unk_23caa40* Unk_23caa40::vf2() {
    return new Unk_23caa40(*this);
}

// 0x7100ae5360
void Unk_23caa40::vf3(Unk_23caa40* p) {
    new (p) Unk_23caa40(*this);
}

// vtable 0x71023caa98: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caa88 {
public:
    virtual ~Unk_23caa88();
    virtual Unk_23caa88* vf2();
    virtual void vf3(Unk_23caa88* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caa88) == 0x10, "Unk_23caa88");

// 0x7100ae53c0
Unk_23caa88* Unk_23caa88::vf2() {
    return new Unk_23caa88(*this);
}

// 0x7100ae5400
void Unk_23caa88::vf3(Unk_23caa88* p) {
    new (p) Unk_23caa88(*this);
}

// vtable 0x71023caae0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caad0 {
public:
    virtual ~Unk_23caad0();
    virtual Unk_23caad0* vf2();
    virtual void vf3(Unk_23caad0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caad0) == 0x10, "Unk_23caad0");

// 0x7100ae5460
Unk_23caad0* Unk_23caad0::vf2() {
    return new Unk_23caad0(*this);
}

// 0x7100ae54a0
void Unk_23caad0::vf3(Unk_23caad0* p) {
    new (p) Unk_23caad0(*this);
}

// vtable 0x71023cab28: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cab18 {
public:
    virtual ~Unk_23cab18();
    virtual Unk_23cab18* vf2();
    virtual void vf3(Unk_23cab18* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cab18) == 0x10, "Unk_23cab18");

// 0x7100ae5500
Unk_23cab18* Unk_23cab18::vf2() {
    return new Unk_23cab18(*this);
}

// 0x7100ae5540
void Unk_23cab18::vf3(Unk_23cab18* p) {
    new (p) Unk_23cab18(*this);
}

// vtable 0x71023cab70: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cab60 {
public:
    virtual ~Unk_23cab60();
    virtual Unk_23cab60* vf2();
    virtual void vf3(Unk_23cab60* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cab60) == 0x10, "Unk_23cab60");

// 0x7100ae55a0
Unk_23cab60* Unk_23cab60::vf2() {
    return new Unk_23cab60(*this);
}

// 0x7100ae55e0
void Unk_23cab60::vf3(Unk_23cab60* p) {
    new (p) Unk_23cab60(*this);
}

// vtable 0x71023cabb8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caba8 {
public:
    virtual ~Unk_23caba8();
    virtual Unk_23caba8* vf2();
    virtual void vf3(Unk_23caba8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caba8) == 0x10, "Unk_23caba8");

// 0x7100ae5640
Unk_23caba8* Unk_23caba8::vf2() {
    return new Unk_23caba8(*this);
}

// 0x7100ae5680
void Unk_23caba8::vf3(Unk_23caba8* p) {
    new (p) Unk_23caba8(*this);
}

// vtable 0x71023cac00: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cabf0 {
public:
    virtual ~Unk_23cabf0();
    virtual Unk_23cabf0* vf2();
    virtual void vf3(Unk_23cabf0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cabf0) == 0x10, "Unk_23cabf0");

// 0x7100ae56e0
Unk_23cabf0* Unk_23cabf0::vf2() {
    return new Unk_23cabf0(*this);
}

// 0x7100ae5720
void Unk_23cabf0::vf3(Unk_23cabf0* p) {
    new (p) Unk_23cabf0(*this);
}

// vtable 0x71023cac48: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cac38 {
public:
    virtual ~Unk_23cac38();
    virtual Unk_23cac38* vf2();
    virtual void vf3(Unk_23cac38* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cac38) == 0x10, "Unk_23cac38");

// 0x7100ae5780
Unk_23cac38* Unk_23cac38::vf2() {
    return new Unk_23cac38(*this);
}

// 0x7100ae57c0
void Unk_23cac38::vf3(Unk_23cac38* p) {
    new (p) Unk_23cac38(*this);
}

// vtable 0x71023cac90: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cac80 {
public:
    virtual ~Unk_23cac80();
    virtual Unk_23cac80* vf2();
    virtual void vf3(Unk_23cac80* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cac80) == 0x10, "Unk_23cac80");

// 0x7100ae5820
Unk_23cac80* Unk_23cac80::vf2() {
    return new Unk_23cac80(*this);
}

// 0x7100ae5860
void Unk_23cac80::vf3(Unk_23cac80* p) {
    new (p) Unk_23cac80(*this);
}

// vtable 0x71023cacd8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cacc8 {
public:
    virtual ~Unk_23cacc8();
    virtual Unk_23cacc8* vf2();
    virtual void vf3(Unk_23cacc8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cacc8) == 0x10, "Unk_23cacc8");

// 0x7100ae58c0
Unk_23cacc8* Unk_23cacc8::vf2() {
    return new Unk_23cacc8(*this);
}

// 0x7100ae5900
void Unk_23cacc8::vf3(Unk_23cacc8* p) {
    new (p) Unk_23cacc8(*this);
}

// vtable 0x71023cad20: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cad10 {
public:
    virtual ~Unk_23cad10();
    virtual Unk_23cad10* vf2();
    virtual void vf3(Unk_23cad10* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cad10) == 0x10, "Unk_23cad10");

// 0x7100ae5960
Unk_23cad10* Unk_23cad10::vf2() {
    return new Unk_23cad10(*this);
}

// 0x7100ae59a0
void Unk_23cad10::vf3(Unk_23cad10* p) {
    new (p) Unk_23cad10(*this);
}

// vtable 0x71023cad68: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cad58 {
public:
    virtual ~Unk_23cad58();
    virtual Unk_23cad58* vf2();
    virtual void vf3(Unk_23cad58* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cad58) == 0x10, "Unk_23cad58");

// 0x7100ae5a00
Unk_23cad58* Unk_23cad58::vf2() {
    return new Unk_23cad58(*this);
}

// 0x7100ae5a40
void Unk_23cad58::vf3(Unk_23cad58* p) {
    new (p) Unk_23cad58(*this);
}

// vtable 0x71023cadb0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cada0 {
public:
    virtual ~Unk_23cada0();
    virtual Unk_23cada0* vf2();
    virtual void vf3(Unk_23cada0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cada0) == 0x10, "Unk_23cada0");

// 0x7100ae5aa0
Unk_23cada0* Unk_23cada0::vf2() {
    return new Unk_23cada0(*this);
}

// 0x7100ae5ae0
void Unk_23cada0::vf3(Unk_23cada0* p) {
    new (p) Unk_23cada0(*this);
}

// vtable 0x71023cadf8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cade8 {
public:
    virtual ~Unk_23cade8();
    virtual Unk_23cade8* vf2();
    virtual void vf3(Unk_23cade8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cade8) == 0x10, "Unk_23cade8");

// 0x7100ae5b40
Unk_23cade8* Unk_23cade8::vf2() {
    return new Unk_23cade8(*this);
}

// 0x7100ae5b80
void Unk_23cade8::vf3(Unk_23cade8* p) {
    new (p) Unk_23cade8(*this);
}

// vtable 0x71023cae40: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cae30 {
public:
    virtual ~Unk_23cae30();
    virtual Unk_23cae30* vf2();
    virtual void vf3(Unk_23cae30* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cae30) == 0x10, "Unk_23cae30");

// 0x7100ae5be0
Unk_23cae30* Unk_23cae30::vf2() {
    return new Unk_23cae30(*this);
}

// 0x7100ae5c20
void Unk_23cae30::vf3(Unk_23cae30* p) {
    new (p) Unk_23cae30(*this);
}

// vtable 0x71023cae88: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cae78 {
public:
    virtual ~Unk_23cae78();
    virtual Unk_23cae78* vf2();
    virtual void vf3(Unk_23cae78* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cae78) == 0x10, "Unk_23cae78");

// 0x7100ae5c80
Unk_23cae78* Unk_23cae78::vf2() {
    return new Unk_23cae78(*this);
}

// 0x7100ae5cc0
void Unk_23cae78::vf3(Unk_23cae78* p) {
    new (p) Unk_23cae78(*this);
}

// vtable 0x71023caed0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caec0 {
public:
    virtual ~Unk_23caec0();
    virtual Unk_23caec0* vf2();
    virtual void vf3(Unk_23caec0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caec0) == 0x10, "Unk_23caec0");

// 0x7100ae5d20
Unk_23caec0* Unk_23caec0::vf2() {
    return new Unk_23caec0(*this);
}

// 0x7100ae5d60
void Unk_23caec0::vf3(Unk_23caec0* p) {
    new (p) Unk_23caec0(*this);
}

// vtable 0x71023caf18: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caf08 {
public:
    virtual ~Unk_23caf08();
    virtual Unk_23caf08* vf2();
    virtual void vf3(Unk_23caf08* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caf08) == 0x10, "Unk_23caf08");

// 0x7100ae5dc0
Unk_23caf08* Unk_23caf08::vf2() {
    return new Unk_23caf08(*this);
}

// 0x7100ae5e00
void Unk_23caf08::vf3(Unk_23caf08* p) {
    new (p) Unk_23caf08(*this);
}

// vtable 0x71023caf60: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caf50 {
public:
    virtual ~Unk_23caf50();
    virtual Unk_23caf50* vf2();
    virtual void vf3(Unk_23caf50* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caf50) == 0x10, "Unk_23caf50");

// 0x7100ae5e60
Unk_23caf50* Unk_23caf50::vf2() {
    return new Unk_23caf50(*this);
}

// 0x7100ae5ea0
void Unk_23caf50::vf3(Unk_23caf50* p) {
    new (p) Unk_23caf50(*this);
}

// vtable 0x71023cafa8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23caf98 {
public:
    virtual ~Unk_23caf98();
    virtual Unk_23caf98* vf2();
    virtual void vf3(Unk_23caf98* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23caf98) == 0x10, "Unk_23caf98");

// 0x7100ae5f00
Unk_23caf98* Unk_23caf98::vf2() {
    return new Unk_23caf98(*this);
}

// 0x7100ae5f40
void Unk_23caf98::vf3(Unk_23caf98* p) {
    new (p) Unk_23caf98(*this);
}

// vtable 0x71023caff0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cafe0 {
public:
    virtual ~Unk_23cafe0();
    virtual Unk_23cafe0* vf2();
    virtual void vf3(Unk_23cafe0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cafe0) == 0x10, "Unk_23cafe0");

// 0x7100ae5fa0
Unk_23cafe0* Unk_23cafe0::vf2() {
    return new Unk_23cafe0(*this);
}

// 0x7100ae5fe0
void Unk_23cafe0::vf3(Unk_23cafe0* p) {
    new (p) Unk_23cafe0(*this);
}

// vtable 0x71023cb038: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb028 {
public:
    virtual ~Unk_23cb028();
    virtual Unk_23cb028* vf2();
    virtual void vf3(Unk_23cb028* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb028) == 0x10, "Unk_23cb028");

// 0x7100ae6040
Unk_23cb028* Unk_23cb028::vf2() {
    return new Unk_23cb028(*this);
}

// 0x7100ae6080
void Unk_23cb028::vf3(Unk_23cb028* p) {
    new (p) Unk_23cb028(*this);
}

// vtable 0x71023cb080: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb070 {
public:
    virtual ~Unk_23cb070();
    virtual Unk_23cb070* vf2();
    virtual void vf3(Unk_23cb070* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb070) == 0x10, "Unk_23cb070");

// 0x7100ae60e0
Unk_23cb070* Unk_23cb070::vf2() {
    return new Unk_23cb070(*this);
}

// 0x7100ae6120
void Unk_23cb070::vf3(Unk_23cb070* p) {
    new (p) Unk_23cb070(*this);
}

// vtable 0x71023cb0c8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb0b8 {
public:
    virtual ~Unk_23cb0b8();
    virtual Unk_23cb0b8* vf2();
    virtual void vf3(Unk_23cb0b8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb0b8) == 0x10, "Unk_23cb0b8");

// 0x7100ae6180
Unk_23cb0b8* Unk_23cb0b8::vf2() {
    return new Unk_23cb0b8(*this);
}

// 0x7100ae61c0
void Unk_23cb0b8::vf3(Unk_23cb0b8* p) {
    new (p) Unk_23cb0b8(*this);
}

// vtable 0x71023cb110: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb100 {
public:
    virtual ~Unk_23cb100();
    virtual Unk_23cb100* vf2();
    virtual void vf3(Unk_23cb100* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb100) == 0x10, "Unk_23cb100");

// 0x7100ae6220
Unk_23cb100* Unk_23cb100::vf2() {
    return new Unk_23cb100(*this);
}

// 0x7100ae6260
void Unk_23cb100::vf3(Unk_23cb100* p) {
    new (p) Unk_23cb100(*this);
}

// vtable 0x71023cb158: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb148 {
public:
    virtual ~Unk_23cb148();
    virtual Unk_23cb148* vf2();
    virtual void vf3(Unk_23cb148* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb148) == 0x10, "Unk_23cb148");

// 0x7100ae62c0
Unk_23cb148* Unk_23cb148::vf2() {
    return new Unk_23cb148(*this);
}

// 0x7100ae6300
void Unk_23cb148::vf3(Unk_23cb148* p) {
    new (p) Unk_23cb148(*this);
}

// vtable 0x71023cb1a0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb190 {
public:
    virtual ~Unk_23cb190();
    virtual Unk_23cb190* vf2();
    virtual void vf3(Unk_23cb190* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb190) == 0x10, "Unk_23cb190");

// 0x7100ae6360
Unk_23cb190* Unk_23cb190::vf2() {
    return new Unk_23cb190(*this);
}

// 0x7100ae63a0
void Unk_23cb190::vf3(Unk_23cb190* p) {
    new (p) Unk_23cb190(*this);
}

// vtable 0x71023cb1e8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb1d8 {
public:
    virtual ~Unk_23cb1d8();
    virtual Unk_23cb1d8* vf2();
    virtual void vf3(Unk_23cb1d8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb1d8) == 0x10, "Unk_23cb1d8");

// 0x7100ae6400
Unk_23cb1d8* Unk_23cb1d8::vf2() {
    return new Unk_23cb1d8(*this);
}

// 0x7100ae6440
void Unk_23cb1d8::vf3(Unk_23cb1d8* p) {
    new (p) Unk_23cb1d8(*this);
}

// vtable 0x71023cb230: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb220 {
public:
    virtual ~Unk_23cb220();
    virtual Unk_23cb220* vf2();
    virtual void vf3(Unk_23cb220* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb220) == 0x10, "Unk_23cb220");

// 0x7100ae64a0
Unk_23cb220* Unk_23cb220::vf2() {
    return new Unk_23cb220(*this);
}

// 0x7100ae64e0
void Unk_23cb220::vf3(Unk_23cb220* p) {
    new (p) Unk_23cb220(*this);
}

// vtable 0x71023cb278: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb268 {
public:
    virtual ~Unk_23cb268();
    virtual Unk_23cb268* vf2();
    virtual void vf3(Unk_23cb268* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb268) == 0x10, "Unk_23cb268");

// 0x7100ae6540
Unk_23cb268* Unk_23cb268::vf2() {
    return new Unk_23cb268(*this);
}

// 0x7100ae6580
void Unk_23cb268::vf3(Unk_23cb268* p) {
    new (p) Unk_23cb268(*this);
}

// vtable 0x71023cb2c0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb2b0 {
public:
    virtual ~Unk_23cb2b0();
    virtual Unk_23cb2b0* vf2();
    virtual void vf3(Unk_23cb2b0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb2b0) == 0x10, "Unk_23cb2b0");

// 0x7100ae65e0
Unk_23cb2b0* Unk_23cb2b0::vf2() {
    return new Unk_23cb2b0(*this);
}

// 0x7100ae6620
void Unk_23cb2b0::vf3(Unk_23cb2b0* p) {
    new (p) Unk_23cb2b0(*this);
}

// vtable 0x71023cb308: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb2f8 {
public:
    virtual ~Unk_23cb2f8();
    virtual Unk_23cb2f8* vf2();
    virtual void vf3(Unk_23cb2f8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb2f8) == 0x10, "Unk_23cb2f8");

// 0x7100ae6680
Unk_23cb2f8* Unk_23cb2f8::vf2() {
    return new Unk_23cb2f8(*this);
}

// 0x7100ae66c0
void Unk_23cb2f8::vf3(Unk_23cb2f8* p) {
    new (p) Unk_23cb2f8(*this);
}

// vtable 0x71023cb350: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb340 {
public:
    virtual ~Unk_23cb340();
    virtual Unk_23cb340* vf2();
    virtual void vf3(Unk_23cb340* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb340) == 0x10, "Unk_23cb340");

// 0x7100ae6720
Unk_23cb340* Unk_23cb340::vf2() {
    return new Unk_23cb340(*this);
}

// 0x7100ae6760
void Unk_23cb340::vf3(Unk_23cb340* p) {
    new (p) Unk_23cb340(*this);
}

// vtable 0x71023cb398: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb388 {
public:
    virtual ~Unk_23cb388();
    virtual Unk_23cb388* vf2();
    virtual void vf3(Unk_23cb388* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb388) == 0x10, "Unk_23cb388");

// 0x7100ae67c0
Unk_23cb388* Unk_23cb388::vf2() {
    return new Unk_23cb388(*this);
}

// 0x7100ae6800
void Unk_23cb388::vf3(Unk_23cb388* p) {
    new (p) Unk_23cb388(*this);
}

// vtable 0x71023cb3e0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb3d0 {
public:
    virtual ~Unk_23cb3d0();
    virtual Unk_23cb3d0* vf2();
    virtual void vf3(Unk_23cb3d0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb3d0) == 0x10, "Unk_23cb3d0");

// 0x7100ae6860
Unk_23cb3d0* Unk_23cb3d0::vf2() {
    return new Unk_23cb3d0(*this);
}

// 0x7100ae68a0
void Unk_23cb3d0::vf3(Unk_23cb3d0* p) {
    new (p) Unk_23cb3d0(*this);
}

// vtable 0x71023cb428: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb418 {
public:
    virtual ~Unk_23cb418();
    virtual Unk_23cb418* vf2();
    virtual void vf3(Unk_23cb418* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb418) == 0x10, "Unk_23cb418");

// 0x7100ae6900
Unk_23cb418* Unk_23cb418::vf2() {
    return new Unk_23cb418(*this);
}

// 0x7100ae6940
void Unk_23cb418::vf3(Unk_23cb418* p) {
    new (p) Unk_23cb418(*this);
}

// vtable 0x71023cb470: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb460 {
public:
    virtual ~Unk_23cb460();
    virtual Unk_23cb460* vf2();
    virtual void vf3(Unk_23cb460* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb460) == 0x10, "Unk_23cb460");

// 0x7100ae69a0
Unk_23cb460* Unk_23cb460::vf2() {
    return new Unk_23cb460(*this);
}

// 0x7100ae69e0
void Unk_23cb460::vf3(Unk_23cb460* p) {
    new (p) Unk_23cb460(*this);
}

// vtable 0x71023cb4b8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb4a8 {
public:
    virtual ~Unk_23cb4a8();
    virtual Unk_23cb4a8* vf2();
    virtual void vf3(Unk_23cb4a8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb4a8) == 0x10, "Unk_23cb4a8");

// 0x7100ae6a40
Unk_23cb4a8* Unk_23cb4a8::vf2() {
    return new Unk_23cb4a8(*this);
}

// 0x7100ae6a80
void Unk_23cb4a8::vf3(Unk_23cb4a8* p) {
    new (p) Unk_23cb4a8(*this);
}

// vtable 0x71023cb500: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb4f0 {
public:
    virtual ~Unk_23cb4f0();
    virtual Unk_23cb4f0* vf2();
    virtual void vf3(Unk_23cb4f0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb4f0) == 0x10, "Unk_23cb4f0");

// 0x7100ae6ae0
Unk_23cb4f0* Unk_23cb4f0::vf2() {
    return new Unk_23cb4f0(*this);
}

// 0x7100ae6b20
void Unk_23cb4f0::vf3(Unk_23cb4f0* p) {
    new (p) Unk_23cb4f0(*this);
}

// vtable 0x71023cb548: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb538 {
public:
    virtual ~Unk_23cb538();
    virtual Unk_23cb538* vf2();
    virtual void vf3(Unk_23cb538* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb538) == 0x10, "Unk_23cb538");

// 0x7100ae6b80
Unk_23cb538* Unk_23cb538::vf2() {
    return new Unk_23cb538(*this);
}

// 0x7100ae6bc0
void Unk_23cb538::vf3(Unk_23cb538* p) {
    new (p) Unk_23cb538(*this);
}

// vtable 0x71023cb590: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb580 {
public:
    virtual ~Unk_23cb580();
    virtual Unk_23cb580* vf2();
    virtual void vf3(Unk_23cb580* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb580) == 0x10, "Unk_23cb580");

// 0x7100ae6c20
Unk_23cb580* Unk_23cb580::vf2() {
    return new Unk_23cb580(*this);
}

// 0x7100ae6c60
void Unk_23cb580::vf3(Unk_23cb580* p) {
    new (p) Unk_23cb580(*this);
}

// vtable 0x71023cb5d8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb5c8 {
public:
    virtual ~Unk_23cb5c8();
    virtual Unk_23cb5c8* vf2();
    virtual void vf3(Unk_23cb5c8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb5c8) == 0x10, "Unk_23cb5c8");

// 0x7100ae6cc0
Unk_23cb5c8* Unk_23cb5c8::vf2() {
    return new Unk_23cb5c8(*this);
}

// 0x7100ae6d00
void Unk_23cb5c8::vf3(Unk_23cb5c8* p) {
    new (p) Unk_23cb5c8(*this);
}

// vtable 0x71023cb620: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb610 {
public:
    virtual ~Unk_23cb610();
    virtual Unk_23cb610* vf2();
    virtual void vf3(Unk_23cb610* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb610) == 0x10, "Unk_23cb610");

// 0x7100ae6d60
Unk_23cb610* Unk_23cb610::vf2() {
    return new Unk_23cb610(*this);
}

// 0x7100ae6da0
void Unk_23cb610::vf3(Unk_23cb610* p) {
    new (p) Unk_23cb610(*this);
}

// vtable 0x71023cb668: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb658 {
public:
    virtual ~Unk_23cb658();
    virtual Unk_23cb658* vf2();
    virtual void vf3(Unk_23cb658* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb658) == 0x10, "Unk_23cb658");

// 0x7100ae6e00
Unk_23cb658* Unk_23cb658::vf2() {
    return new Unk_23cb658(*this);
}

// 0x7100ae6e40
void Unk_23cb658::vf3(Unk_23cb658* p) {
    new (p) Unk_23cb658(*this);
}

// vtable 0x71023cb6b0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb6a0 {
public:
    virtual ~Unk_23cb6a0();
    virtual Unk_23cb6a0* vf2();
    virtual void vf3(Unk_23cb6a0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb6a0) == 0x10, "Unk_23cb6a0");

// 0x7100ae6ea0
Unk_23cb6a0* Unk_23cb6a0::vf2() {
    return new Unk_23cb6a0(*this);
}

// 0x7100ae6ee0
void Unk_23cb6a0::vf3(Unk_23cb6a0* p) {
    new (p) Unk_23cb6a0(*this);
}

// vtable 0x71023cb6f8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb6e8 {
public:
    virtual ~Unk_23cb6e8();
    virtual Unk_23cb6e8* vf2();
    virtual void vf3(Unk_23cb6e8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb6e8) == 0x10, "Unk_23cb6e8");

// 0x7100ae6f40
Unk_23cb6e8* Unk_23cb6e8::vf2() {
    return new Unk_23cb6e8(*this);
}

// 0x7100ae6f80
void Unk_23cb6e8::vf3(Unk_23cb6e8* p) {
    new (p) Unk_23cb6e8(*this);
}

// vtable 0x71023cb740: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb730 {
public:
    virtual ~Unk_23cb730();
    virtual Unk_23cb730* vf2();
    virtual void vf3(Unk_23cb730* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb730) == 0x10, "Unk_23cb730");

// 0x7100ae6fe0
Unk_23cb730* Unk_23cb730::vf2() {
    return new Unk_23cb730(*this);
}

// 0x7100ae7020
void Unk_23cb730::vf3(Unk_23cb730* p) {
    new (p) Unk_23cb730(*this);
}

// vtable 0x71023cb788: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb778 {
public:
    virtual ~Unk_23cb778();
    virtual Unk_23cb778* vf2();
    virtual void vf3(Unk_23cb778* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb778) == 0x10, "Unk_23cb778");

// 0x7100ae7080
Unk_23cb778* Unk_23cb778::vf2() {
    return new Unk_23cb778(*this);
}

// 0x7100ae70c0
void Unk_23cb778::vf3(Unk_23cb778* p) {
    new (p) Unk_23cb778(*this);
}

// vtable 0x71023cb7d0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb7c0 {
public:
    virtual ~Unk_23cb7c0();
    virtual Unk_23cb7c0* vf2();
    virtual void vf3(Unk_23cb7c0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb7c0) == 0x10, "Unk_23cb7c0");

// 0x7100ae7120
Unk_23cb7c0* Unk_23cb7c0::vf2() {
    return new Unk_23cb7c0(*this);
}

// 0x7100ae7160
void Unk_23cb7c0::vf3(Unk_23cb7c0* p) {
    new (p) Unk_23cb7c0(*this);
}

// vtable 0x71023cb818: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb808 {
public:
    virtual ~Unk_23cb808();
    virtual Unk_23cb808* vf2();
    virtual void vf3(Unk_23cb808* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb808) == 0x10, "Unk_23cb808");

// 0x7100ae71d0
Unk_23cb808* Unk_23cb808::vf2() {
    return new Unk_23cb808(*this);
}

// 0x7100ae7210
void Unk_23cb808::vf3(Unk_23cb808* p) {
    new (p) Unk_23cb808(*this);
}

// vtable 0x71023cb860: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb850 {
public:
    virtual ~Unk_23cb850();
    virtual Unk_23cb850* vf2();
    virtual void vf3(Unk_23cb850* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb850) == 0x10, "Unk_23cb850");

// 0x7100ae7270
Unk_23cb850* Unk_23cb850::vf2() {
    return new Unk_23cb850(*this);
}

// 0x7100ae72b0
void Unk_23cb850::vf3(Unk_23cb850* p) {
    new (p) Unk_23cb850(*this);
}

// vtable 0x71023cb8a8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb898 {
public:
    virtual ~Unk_23cb898();
    virtual Unk_23cb898* vf2();
    virtual void vf3(Unk_23cb898* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb898) == 0x10, "Unk_23cb898");

// 0x7100ae7310
Unk_23cb898* Unk_23cb898::vf2() {
    return new Unk_23cb898(*this);
}

// 0x7100ae7350
void Unk_23cb898::vf3(Unk_23cb898* p) {
    new (p) Unk_23cb898(*this);
}

// vtable 0x71023cb8f0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb8e0 {
public:
    virtual ~Unk_23cb8e0();
    virtual Unk_23cb8e0* vf2();
    virtual void vf3(Unk_23cb8e0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb8e0) == 0x10, "Unk_23cb8e0");

// 0x7100ae73b0
Unk_23cb8e0* Unk_23cb8e0::vf2() {
    return new Unk_23cb8e0(*this);
}

// 0x7100ae73f0
void Unk_23cb8e0::vf3(Unk_23cb8e0* p) {
    new (p) Unk_23cb8e0(*this);
}

// vtable 0x71023cb938: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb928 {
public:
    virtual ~Unk_23cb928();
    virtual Unk_23cb928* vf2();
    virtual void vf3(Unk_23cb928* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb928) == 0x10, "Unk_23cb928");

// 0x7100ae7450
Unk_23cb928* Unk_23cb928::vf2() {
    return new Unk_23cb928(*this);
}

// 0x7100ae7490
void Unk_23cb928::vf3(Unk_23cb928* p) {
    new (p) Unk_23cb928(*this);
}

// vtable 0x71023cb980: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb970 {
public:
    virtual ~Unk_23cb970();
    virtual Unk_23cb970* vf2();
    virtual void vf3(Unk_23cb970* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb970) == 0x10, "Unk_23cb970");

// 0x7100ae74f0
Unk_23cb970* Unk_23cb970::vf2() {
    return new Unk_23cb970(*this);
}

// 0x7100ae7530
void Unk_23cb970::vf3(Unk_23cb970* p) {
    new (p) Unk_23cb970(*this);
}

// vtable 0x71023cb9c8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cb9b8 {
public:
    virtual ~Unk_23cb9b8();
    virtual Unk_23cb9b8* vf2();
    virtual void vf3(Unk_23cb9b8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cb9b8) == 0x10, "Unk_23cb9b8");

// 0x7100ae7590
Unk_23cb9b8* Unk_23cb9b8::vf2() {
    return new Unk_23cb9b8(*this);
}

// 0x7100ae75d0
void Unk_23cb9b8::vf3(Unk_23cb9b8* p) {
    new (p) Unk_23cb9b8(*this);
}

// vtable 0x71023cba10: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cba00 {
public:
    virtual ~Unk_23cba00();
    virtual Unk_23cba00* vf2();
    virtual void vf3(Unk_23cba00* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cba00) == 0x10, "Unk_23cba00");

// 0x7100ae7630
Unk_23cba00* Unk_23cba00::vf2() {
    return new Unk_23cba00(*this);
}

// 0x7100ae7670
void Unk_23cba00::vf3(Unk_23cba00* p) {
    new (p) Unk_23cba00(*this);
}

// vtable 0x71023cba58: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cba48 {
public:
    virtual ~Unk_23cba48();
    virtual Unk_23cba48* vf2();
    virtual void vf3(Unk_23cba48* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cba48) == 0x10, "Unk_23cba48");

// 0x7100ae76d0
Unk_23cba48* Unk_23cba48::vf2() {
    return new Unk_23cba48(*this);
}

// 0x7100ae7710
void Unk_23cba48::vf3(Unk_23cba48* p) {
    new (p) Unk_23cba48(*this);
}

// vtable 0x71023cbaa0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cba90 {
public:
    virtual ~Unk_23cba90();
    virtual Unk_23cba90* vf2();
    virtual void vf3(Unk_23cba90* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cba90) == 0x10, "Unk_23cba90");

// 0x7100ae7770
Unk_23cba90* Unk_23cba90::vf2() {
    return new Unk_23cba90(*this);
}

// 0x7100ae77b0
void Unk_23cba90::vf3(Unk_23cba90* p) {
    new (p) Unk_23cba90(*this);
}

// vtable 0x71023cbd00: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cbcf0 {
public:
    virtual ~Unk_23cbcf0();
    virtual Unk_23cbcf0* vf2();
    virtual void vf3(Unk_23cbcf0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cbcf0) == 0x10, "Unk_23cbcf0");

// 0x7100ae8e20
Unk_23cbcf0* Unk_23cbcf0::vf2() {
    return new Unk_23cbcf0(*this);
}

// 0x7100ae8e60
void Unk_23cbcf0::vf3(Unk_23cbcf0* p) {
    new (p) Unk_23cbcf0(*this);
}

// vtable 0x71023cbd48: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cbd38 {
public:
    virtual ~Unk_23cbd38();
    virtual Unk_23cbd38* vf2();
    virtual void vf3(Unk_23cbd38* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cbd38) == 0x10, "Unk_23cbd38");

// 0x7100ae8f10
Unk_23cbd38* Unk_23cbd38::vf2() {
    return new Unk_23cbd38(*this);
}

// 0x7100ae8f50
void Unk_23cbd38::vf3(Unk_23cbd38* p) {
    new (p) Unk_23cbd38(*this);
}

// vtable 0x71023cbd90: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cbd80 {
public:
    virtual ~Unk_23cbd80();
    virtual Unk_23cbd80* vf2();
    virtual void vf3(Unk_23cbd80* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cbd80) == 0x10, "Unk_23cbd80");

// 0x7100ae9000
Unk_23cbd80* Unk_23cbd80::vf2() {
    return new Unk_23cbd80(*this);
}

// 0x7100ae9040
void Unk_23cbd80::vf3(Unk_23cbd80* p) {
    new (p) Unk_23cbd80(*this);
}

// vtable 0x71023cbf60: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cbf50 {
public:
    virtual ~Unk_23cbf50();
    virtual Unk_23cbf50* vf2();
    virtual void vf3(Unk_23cbf50* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cbf50) == 0x10, "Unk_23cbf50");

// 0x7100aeb0f0
Unk_23cbf50* Unk_23cbf50::vf2() {
    return new Unk_23cbf50(*this);
}

// 0x7100aeb130
void Unk_23cbf50::vf3(Unk_23cbf50* p) {
    new (p) Unk_23cbf50(*this);
}

// vtable 0x71023cbfa8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cbf98 {
public:
    virtual ~Unk_23cbf98();
    virtual Unk_23cbf98* vf2();
    virtual void vf3(Unk_23cbf98* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cbf98) == 0x10, "Unk_23cbf98");

// 0x7100aeb1e0
Unk_23cbf98* Unk_23cbf98::vf2() {
    return new Unk_23cbf98(*this);
}

// 0x7100aeb220
void Unk_23cbf98::vf3(Unk_23cbf98* p) {
    new (p) Unk_23cbf98(*this);
}

// vtable 0x71023cbff0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cbfe0 {
public:
    virtual ~Unk_23cbfe0();
    virtual Unk_23cbfe0* vf2();
    virtual void vf3(Unk_23cbfe0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cbfe0) == 0x10, "Unk_23cbfe0");

// 0x7100aeb2d0
Unk_23cbfe0* Unk_23cbfe0::vf2() {
    return new Unk_23cbfe0(*this);
}

// 0x7100aeb310
void Unk_23cbfe0::vf3(Unk_23cbfe0* p) {
    new (p) Unk_23cbfe0(*this);
}

// vtable 0x71023cc038: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc028 {
public:
    virtual ~Unk_23cc028();
    virtual Unk_23cc028* vf2();
    virtual void vf3(Unk_23cc028* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc028) == 0x10, "Unk_23cc028");

// 0x7100aeb3c0
Unk_23cc028* Unk_23cc028::vf2() {
    return new Unk_23cc028(*this);
}

// 0x7100aeb400
void Unk_23cc028::vf3(Unk_23cc028* p) {
    new (p) Unk_23cc028(*this);
}

// vtable 0x71023cc080: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc070 {
public:
    virtual ~Unk_23cc070();
    virtual Unk_23cc070* vf2();
    virtual void vf3(Unk_23cc070* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc070) == 0x10, "Unk_23cc070");

// 0x7100aeb4b0
Unk_23cc070* Unk_23cc070::vf2() {
    return new Unk_23cc070(*this);
}

// 0x7100aeb4f0
void Unk_23cc070::vf3(Unk_23cc070* p) {
    new (p) Unk_23cc070(*this);
}

// vtable 0x71023cc0c8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc0b8 {
public:
    virtual ~Unk_23cc0b8();
    virtual Unk_23cc0b8* vf2();
    virtual void vf3(Unk_23cc0b8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc0b8) == 0x10, "Unk_23cc0b8");

// 0x7100aeb5a0
Unk_23cc0b8* Unk_23cc0b8::vf2() {
    return new Unk_23cc0b8(*this);
}

// 0x7100aeb5e0
void Unk_23cc0b8::vf3(Unk_23cc0b8* p) {
    new (p) Unk_23cc0b8(*this);
}

// vtable 0x71023cc110: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc100 {
public:
    virtual ~Unk_23cc100();
    virtual Unk_23cc100* vf2();
    virtual void vf3(Unk_23cc100* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc100) == 0x10, "Unk_23cc100");

// 0x7100aeb690
Unk_23cc100* Unk_23cc100::vf2() {
    return new Unk_23cc100(*this);
}

// 0x7100aeb6d0
void Unk_23cc100::vf3(Unk_23cc100* p) {
    new (p) Unk_23cc100(*this);
}

// vtable 0x71023cc298: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc288 {
public:
    virtual ~Unk_23cc288();
    virtual Unk_23cc288* vf2();
    virtual void vf3(Unk_23cc288* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc288) == 0x10, "Unk_23cc288");

// 0x7100aed2e0
Unk_23cc288* Unk_23cc288::vf2() {
    return new Unk_23cc288(*this);
}

// 0x7100aed320
void Unk_23cc288::vf3(Unk_23cc288* p) {
    new (p) Unk_23cc288(*this);
}

// vtable 0x71023cc2e0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc2d0 {
public:
    virtual ~Unk_23cc2d0();
    virtual Unk_23cc2d0* vf2();
    virtual void vf3(Unk_23cc2d0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc2d0) == 0x10, "Unk_23cc2d0");

// 0x7100aed3d0
Unk_23cc2d0* Unk_23cc2d0::vf2() {
    return new Unk_23cc2d0(*this);
}

// 0x7100aed410
void Unk_23cc2d0::vf3(Unk_23cc2d0* p) {
    new (p) Unk_23cc2d0(*this);
}

// vtable 0x71023cc328: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc318 {
public:
    virtual ~Unk_23cc318();
    virtual Unk_23cc318* vf2();
    virtual void vf3(Unk_23cc318* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc318) == 0x10, "Unk_23cc318");

// 0x7100aed700
Unk_23cc318* Unk_23cc318::vf2() {
    return new Unk_23cc318(*this);
}

// 0x7100aed740
void Unk_23cc318::vf3(Unk_23cc318* p) {
    new (p) Unk_23cc318(*this);
}

// vtable 0x71023cc370: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc360 {
public:
    virtual ~Unk_23cc360();
    virtual Unk_23cc360* vf2();
    virtual void vf3(Unk_23cc360* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc360) == 0x10, "Unk_23cc360");

// 0x7100aed7f0
Unk_23cc360* Unk_23cc360::vf2() {
    return new Unk_23cc360(*this);
}

// 0x7100aed830
void Unk_23cc360::vf3(Unk_23cc360* p) {
    new (p) Unk_23cc360(*this);
}

// vtable 0x71023cc3b8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc3a8 {
public:
    virtual ~Unk_23cc3a8();
    virtual Unk_23cc3a8* vf2();
    virtual void vf3(Unk_23cc3a8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc3a8) == 0x10, "Unk_23cc3a8");

// 0x7100aed8e0
Unk_23cc3a8* Unk_23cc3a8::vf2() {
    return new Unk_23cc3a8(*this);
}

// 0x7100aed920
void Unk_23cc3a8::vf3(Unk_23cc3a8* p) {
    new (p) Unk_23cc3a8(*this);
}

// vtable 0x71023cc400: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc3f0 {
public:
    virtual ~Unk_23cc3f0();
    virtual Unk_23cc3f0* vf2();
    virtual void vf3(Unk_23cc3f0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc3f0) == 0x10, "Unk_23cc3f0");

// 0x7100aed9d0
Unk_23cc3f0* Unk_23cc3f0::vf2() {
    return new Unk_23cc3f0(*this);
}

// 0x7100aeda10
void Unk_23cc3f0::vf3(Unk_23cc3f0* p) {
    new (p) Unk_23cc3f0(*this);
}

// vtable 0x71023cc448: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc438 {
public:
    virtual ~Unk_23cc438();
    virtual Unk_23cc438* vf2();
    virtual void vf3(Unk_23cc438* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc438) == 0x10, "Unk_23cc438");

// 0x7100aedac0
Unk_23cc438* Unk_23cc438::vf2() {
    return new Unk_23cc438(*this);
}

// 0x7100aedb00
void Unk_23cc438::vf3(Unk_23cc438* p) {
    new (p) Unk_23cc438(*this);
}

// vtable 0x71023cc490: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc480 {
public:
    virtual ~Unk_23cc480();
    virtual Unk_23cc480* vf2();
    virtual void vf3(Unk_23cc480* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc480) == 0x10, "Unk_23cc480");

// 0x7100aedbb0
Unk_23cc480* Unk_23cc480::vf2() {
    return new Unk_23cc480(*this);
}

// 0x7100aedbf0
void Unk_23cc480::vf3(Unk_23cc480* p) {
    new (p) Unk_23cc480(*this);
}

// vtable 0x71023cc4d8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc4c8 {
public:
    virtual ~Unk_23cc4c8();
    virtual Unk_23cc4c8* vf2();
    virtual void vf3(Unk_23cc4c8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc4c8) == 0x10, "Unk_23cc4c8");

// 0x7100aedca0
Unk_23cc4c8* Unk_23cc4c8::vf2() {
    return new Unk_23cc4c8(*this);
}

// 0x7100aedce0
void Unk_23cc4c8::vf3(Unk_23cc4c8* p) {
    new (p) Unk_23cc4c8(*this);
}

// vtable 0x71023cc520: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc510 {
public:
    virtual ~Unk_23cc510();
    virtual Unk_23cc510* vf2();
    virtual void vf3(Unk_23cc510* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc510) == 0x10, "Unk_23cc510");

// 0x7100aede60
Unk_23cc510* Unk_23cc510::vf2() {
    return new Unk_23cc510(*this);
}

// 0x7100aedea0
void Unk_23cc510::vf3(Unk_23cc510* p) {
    new (p) Unk_23cc510(*this);
}

// vtable 0x71023cc568: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc558 {
public:
    virtual ~Unk_23cc558();
    virtual Unk_23cc558* vf2();
    virtual void vf3(Unk_23cc558* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc558) == 0x10, "Unk_23cc558");

// 0x7100aedf50
Unk_23cc558* Unk_23cc558::vf2() {
    return new Unk_23cc558(*this);
}

// 0x7100aedf90
void Unk_23cc558::vf3(Unk_23cc558* p) {
    new (p) Unk_23cc558(*this);
}

// vtable 0x71023cc6d8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc6c8 {
public:
    virtual ~Unk_23cc6c8();
    virtual Unk_23cc6c8* vf2();
    virtual void vf3(Unk_23cc6c8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc6c8) == 0x10, "Unk_23cc6c8");

// 0x7100aefe30
Unk_23cc6c8* Unk_23cc6c8::vf2() {
    return new Unk_23cc6c8(*this);
}

// 0x7100aefe70
void Unk_23cc6c8::vf3(Unk_23cc6c8* p) {
    new (p) Unk_23cc6c8(*this);
}

// vtable 0x71023cc720: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc710 {
public:
    virtual ~Unk_23cc710();
    virtual Unk_23cc710* vf2();
    virtual void vf3(Unk_23cc710* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc710) == 0x10, "Unk_23cc710");

// 0x7100aeff20
Unk_23cc710* Unk_23cc710::vf2() {
    return new Unk_23cc710(*this);
}

// 0x7100aeff60
void Unk_23cc710::vf3(Unk_23cc710* p) {
    new (p) Unk_23cc710(*this);
}

// vtable 0x71023cc768: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc758 {
public:
    virtual ~Unk_23cc758();
    virtual Unk_23cc758* vf2();
    virtual void vf3(Unk_23cc758* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc758) == 0x10, "Unk_23cc758");

// 0x7100af0010
Unk_23cc758* Unk_23cc758::vf2() {
    return new Unk_23cc758(*this);
}

// 0x7100af0050
void Unk_23cc758::vf3(Unk_23cc758* p) {
    new (p) Unk_23cc758(*this);
}

// vtable 0x71023cc8f0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc8e0 {
public:
    virtual ~Unk_23cc8e0();
    virtual Unk_23cc8e0* vf2();
    virtual void vf3(Unk_23cc8e0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc8e0) == 0x10, "Unk_23cc8e0");

// 0x7100af1e40
Unk_23cc8e0* Unk_23cc8e0::vf2() {
    return new Unk_23cc8e0(*this);
}

// 0x7100af1e80
void Unk_23cc8e0::vf3(Unk_23cc8e0* p) {
    new (p) Unk_23cc8e0(*this);
}

// vtable 0x71023cc938: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc928 {
public:
    virtual ~Unk_23cc928();
    virtual Unk_23cc928* vf2();
    virtual void vf3(Unk_23cc928* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc928) == 0x10, "Unk_23cc928");

// 0x7100af1f30
Unk_23cc928* Unk_23cc928::vf2() {
    return new Unk_23cc928(*this);
}

// 0x7100af1f70
void Unk_23cc928::vf3(Unk_23cc928* p) {
    new (p) Unk_23cc928(*this);
}

// vtable 0x71023cc980: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc970 {
public:
    virtual ~Unk_23cc970();
    virtual Unk_23cc970* vf2();
    virtual void vf3(Unk_23cc970* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc970) == 0x10, "Unk_23cc970");

// 0x7100af2020
Unk_23cc970* Unk_23cc970::vf2() {
    return new Unk_23cc970(*this);
}

// 0x7100af2060
void Unk_23cc970::vf3(Unk_23cc970* p) {
    new (p) Unk_23cc970(*this);
}

// vtable 0x71023cc9c8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cc9b8 {
public:
    virtual ~Unk_23cc9b8();
    virtual Unk_23cc9b8* vf2();
    virtual void vf3(Unk_23cc9b8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cc9b8) == 0x10, "Unk_23cc9b8");

// 0x7100af2110
Unk_23cc9b8* Unk_23cc9b8::vf2() {
    return new Unk_23cc9b8(*this);
}

// 0x7100af2150
void Unk_23cc9b8::vf3(Unk_23cc9b8* p) {
    new (p) Unk_23cc9b8(*this);
}

// vtable 0x71023cca10: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cca00 {
public:
    virtual ~Unk_23cca00();
    virtual Unk_23cca00* vf2();
    virtual void vf3(Unk_23cca00* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cca00) == 0x10, "Unk_23cca00");

// 0x7100af2200
Unk_23cca00* Unk_23cca00::vf2() {
    return new Unk_23cca00(*this);
}

// 0x7100af2240
void Unk_23cca00::vf3(Unk_23cca00* p) {
    new (p) Unk_23cca00(*this);
}

// vtable 0x71023cca58: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cca48 {
public:
    virtual ~Unk_23cca48();
    virtual Unk_23cca48* vf2();
    virtual void vf3(Unk_23cca48* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cca48) == 0x10, "Unk_23cca48");

// 0x7100af22f0
Unk_23cca48* Unk_23cca48::vf2() {
    return new Unk_23cca48(*this);
}

// 0x7100af2330
void Unk_23cca48::vf3(Unk_23cca48* p) {
    new (p) Unk_23cca48(*this);
}

// vtable 0x71023ccaa0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cca90 {
public:
    virtual ~Unk_23cca90();
    virtual Unk_23cca90* vf2();
    virtual void vf3(Unk_23cca90* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cca90) == 0x10, "Unk_23cca90");

// 0x7100af23e0
Unk_23cca90* Unk_23cca90::vf2() {
    return new Unk_23cca90(*this);
}

// 0x7100af2420
void Unk_23cca90::vf3(Unk_23cca90* p) {
    new (p) Unk_23cca90(*this);
}

// vtable 0x71023ccae8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccad8 {
public:
    virtual ~Unk_23ccad8();
    virtual Unk_23ccad8* vf2();
    virtual void vf3(Unk_23ccad8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccad8) == 0x10, "Unk_23ccad8");

// 0x7100af24d0
Unk_23ccad8* Unk_23ccad8::vf2() {
    return new Unk_23ccad8(*this);
}

// 0x7100af2510
void Unk_23ccad8::vf3(Unk_23ccad8* p) {
    new (p) Unk_23ccad8(*this);
}

// vtable 0x71023ccb30: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccb20 {
public:
    virtual ~Unk_23ccb20();
    virtual Unk_23ccb20* vf2();
    virtual void vf3(Unk_23ccb20* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccb20) == 0x10, "Unk_23ccb20");

// 0x7100af25c0
Unk_23ccb20* Unk_23ccb20::vf2() {
    return new Unk_23ccb20(*this);
}

// 0x7100af2600
void Unk_23ccb20::vf3(Unk_23ccb20* p) {
    new (p) Unk_23ccb20(*this);
}

// vtable 0x71023ccb78: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccb68 {
public:
    virtual ~Unk_23ccb68();
    virtual Unk_23ccb68* vf2();
    virtual void vf3(Unk_23ccb68* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccb68) == 0x10, "Unk_23ccb68");

// 0x7100af26b0
Unk_23ccb68* Unk_23ccb68::vf2() {
    return new Unk_23ccb68(*this);
}

// 0x7100af26f0
void Unk_23ccb68::vf3(Unk_23ccb68* p) {
    new (p) Unk_23ccb68(*this);
}

// vtable 0x71023ccbc0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccbb0 {
public:
    virtual ~Unk_23ccbb0();
    virtual Unk_23ccbb0* vf2();
    virtual void vf3(Unk_23ccbb0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccbb0) == 0x10, "Unk_23ccbb0");

// 0x7100af27a0
Unk_23ccbb0* Unk_23ccbb0::vf2() {
    return new Unk_23ccbb0(*this);
}

// 0x7100af27e0
void Unk_23ccbb0::vf3(Unk_23ccbb0* p) {
    new (p) Unk_23ccbb0(*this);
}

// vtable 0x71023ccc08: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccbf8 {
public:
    virtual ~Unk_23ccbf8();
    virtual Unk_23ccbf8* vf2();
    virtual void vf3(Unk_23ccbf8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccbf8) == 0x10, "Unk_23ccbf8");

// 0x7100af2890
Unk_23ccbf8* Unk_23ccbf8::vf2() {
    return new Unk_23ccbf8(*this);
}

// 0x7100af28d0
void Unk_23ccbf8::vf3(Unk_23ccbf8* p) {
    new (p) Unk_23ccbf8(*this);
}

// vtable 0x71023ccc50: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccc40 {
public:
    virtual ~Unk_23ccc40();
    virtual Unk_23ccc40* vf2();
    virtual void vf3(Unk_23ccc40* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccc40) == 0x10, "Unk_23ccc40");

// 0x7100af2980
Unk_23ccc40* Unk_23ccc40::vf2() {
    return new Unk_23ccc40(*this);
}

// 0x7100af29c0
void Unk_23ccc40::vf3(Unk_23ccc40* p) {
    new (p) Unk_23ccc40(*this);
}

// vtable 0x71023ccc98: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccc88 {
public:
    virtual ~Unk_23ccc88();
    virtual Unk_23ccc88* vf2();
    virtual void vf3(Unk_23ccc88* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccc88) == 0x10, "Unk_23ccc88");

// 0x7100af2a70
Unk_23ccc88* Unk_23ccc88::vf2() {
    return new Unk_23ccc88(*this);
}

// 0x7100af2ab0
void Unk_23ccc88::vf3(Unk_23ccc88* p) {
    new (p) Unk_23ccc88(*this);
}

// vtable 0x71023ccce0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cccd0 {
public:
    virtual ~Unk_23cccd0();
    virtual Unk_23cccd0* vf2();
    virtual void vf3(Unk_23cccd0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cccd0) == 0x10, "Unk_23cccd0");

// 0x7100af2b60
Unk_23cccd0* Unk_23cccd0::vf2() {
    return new Unk_23cccd0(*this);
}

// 0x7100af2ba0
void Unk_23cccd0::vf3(Unk_23cccd0* p) {
    new (p) Unk_23cccd0(*this);
}

// vtable 0x71023ccd28: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccd18 {
public:
    virtual ~Unk_23ccd18();
    virtual Unk_23ccd18* vf2();
    virtual void vf3(Unk_23ccd18* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccd18) == 0x10, "Unk_23ccd18");

// 0x7100af2c50
Unk_23ccd18* Unk_23ccd18::vf2() {
    return new Unk_23ccd18(*this);
}

// 0x7100af2c90
void Unk_23ccd18::vf3(Unk_23ccd18* p) {
    new (p) Unk_23ccd18(*this);
}

// vtable 0x71023cce98: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cce88 {
public:
    virtual ~Unk_23cce88();
    virtual Unk_23cce88* vf2();
    virtual void vf3(Unk_23cce88* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cce88) == 0x10, "Unk_23cce88");

// 0x7100af59d0
Unk_23cce88* Unk_23cce88::vf2() {
    return new Unk_23cce88(*this);
}

// 0x7100af5a10
void Unk_23cce88::vf3(Unk_23cce88* p) {
    new (p) Unk_23cce88(*this);
}

// vtable 0x71023ccee0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cced0 {
public:
    virtual ~Unk_23cced0();
    virtual Unk_23cced0* vf2();
    virtual void vf3(Unk_23cced0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cced0) == 0x10, "Unk_23cced0");

// 0x7100af5ac0
Unk_23cced0* Unk_23cced0::vf2() {
    return new Unk_23cced0(*this);
}

// 0x7100af5b00
void Unk_23cced0::vf3(Unk_23cced0* p) {
    new (p) Unk_23cced0(*this);
}

// vtable 0x71023ccf28: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccf18 {
public:
    virtual ~Unk_23ccf18();
    virtual Unk_23ccf18* vf2();
    virtual void vf3(Unk_23ccf18* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccf18) == 0x10, "Unk_23ccf18");

// 0x7100af6130
Unk_23ccf18* Unk_23ccf18::vf2() {
    return new Unk_23ccf18(*this);
}

// 0x7100af6170
void Unk_23ccf18::vf3(Unk_23ccf18* p) {
    new (p) Unk_23ccf18(*this);
}

// vtable 0x71023ccf70: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccf60 {
public:
    virtual ~Unk_23ccf60();
    virtual Unk_23ccf60* vf2();
    virtual void vf3(Unk_23ccf60* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccf60) == 0x10, "Unk_23ccf60");

// 0x7100af6220
Unk_23ccf60* Unk_23ccf60::vf2() {
    return new Unk_23ccf60(*this);
}

// 0x7100af6260
void Unk_23ccf60::vf3(Unk_23ccf60* p) {
    new (p) Unk_23ccf60(*this);
}

// vtable 0x71023ccfb8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccfa8 {
public:
    virtual ~Unk_23ccfa8();
    virtual Unk_23ccfa8* vf2();
    virtual void vf3(Unk_23ccfa8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccfa8) == 0x10, "Unk_23ccfa8");

// 0x7100af6310
Unk_23ccfa8* Unk_23ccfa8::vf2() {
    return new Unk_23ccfa8(*this);
}

// 0x7100af6350
void Unk_23ccfa8::vf3(Unk_23ccfa8* p) {
    new (p) Unk_23ccfa8(*this);
}

// vtable 0x71023cd000: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ccff0 {
public:
    virtual ~Unk_23ccff0();
    virtual Unk_23ccff0* vf2();
    virtual void vf3(Unk_23ccff0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ccff0) == 0x10, "Unk_23ccff0");

// 0x7100af6400
Unk_23ccff0* Unk_23ccff0::vf2() {
    return new Unk_23ccff0(*this);
}

// 0x7100af6440
void Unk_23ccff0::vf3(Unk_23ccff0* p) {
    new (p) Unk_23ccff0(*this);
}

// vtable 0x71023cd048: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd038 {
public:
    virtual ~Unk_23cd038();
    virtual Unk_23cd038* vf2();
    virtual void vf3(Unk_23cd038* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd038) == 0x10, "Unk_23cd038");

// 0x7100af64f0
Unk_23cd038* Unk_23cd038::vf2() {
    return new Unk_23cd038(*this);
}

// 0x7100af6530
void Unk_23cd038::vf3(Unk_23cd038* p) {
    new (p) Unk_23cd038(*this);
}

// vtable 0x71023cd090: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd080 {
public:
    virtual ~Unk_23cd080();
    virtual Unk_23cd080* vf2();
    virtual void vf3(Unk_23cd080* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd080) == 0x10, "Unk_23cd080");

// 0x7100af65e0
Unk_23cd080* Unk_23cd080::vf2() {
    return new Unk_23cd080(*this);
}

// 0x7100af6620
void Unk_23cd080::vf3(Unk_23cd080* p) {
    new (p) Unk_23cd080(*this);
}

// vtable 0x71023cd0d8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd0c8 {
public:
    virtual ~Unk_23cd0c8();
    virtual Unk_23cd0c8* vf2();
    virtual void vf3(Unk_23cd0c8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd0c8) == 0x10, "Unk_23cd0c8");

// 0x7100af66d0
Unk_23cd0c8* Unk_23cd0c8::vf2() {
    return new Unk_23cd0c8(*this);
}

// 0x7100af6710
void Unk_23cd0c8::vf3(Unk_23cd0c8* p) {
    new (p) Unk_23cd0c8(*this);
}

// vtable 0x71023cd120: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd110 {
public:
    virtual ~Unk_23cd110();
    virtual Unk_23cd110* vf2();
    virtual void vf3(Unk_23cd110* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd110) == 0x10, "Unk_23cd110");

// 0x7100af67c0
Unk_23cd110* Unk_23cd110::vf2() {
    return new Unk_23cd110(*this);
}

// 0x7100af6800
void Unk_23cd110::vf3(Unk_23cd110* p) {
    new (p) Unk_23cd110(*this);
}

// vtable 0x71023cd168: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd158 {
public:
    virtual ~Unk_23cd158();
    virtual Unk_23cd158* vf2();
    virtual void vf3(Unk_23cd158* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd158) == 0x10, "Unk_23cd158");

// 0x7100af68b0
Unk_23cd158* Unk_23cd158::vf2() {
    return new Unk_23cd158(*this);
}

// 0x7100af68f0
void Unk_23cd158::vf3(Unk_23cd158* p) {
    new (p) Unk_23cd158(*this);
}

// vtable 0x71023cd1b0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd1a0 {
public:
    virtual ~Unk_23cd1a0();
    virtual Unk_23cd1a0* vf2();
    virtual void vf3(Unk_23cd1a0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd1a0) == 0x10, "Unk_23cd1a0");

// 0x7100af69a0
Unk_23cd1a0* Unk_23cd1a0::vf2() {
    return new Unk_23cd1a0(*this);
}

// 0x7100af69e0
void Unk_23cd1a0::vf3(Unk_23cd1a0* p) {
    new (p) Unk_23cd1a0(*this);
}

// vtable 0x71023cd1f8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd1e8 {
public:
    virtual ~Unk_23cd1e8();
    virtual Unk_23cd1e8* vf2();
    virtual void vf3(Unk_23cd1e8* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd1e8) == 0x10, "Unk_23cd1e8");

// 0x7100af6a90
Unk_23cd1e8* Unk_23cd1e8::vf2() {
    return new Unk_23cd1e8(*this);
}

// 0x7100af6ad0
void Unk_23cd1e8::vf3(Unk_23cd1e8* p) {
    new (p) Unk_23cd1e8(*this);
}

// vtable 0x71023cd240: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd230 {
public:
    virtual ~Unk_23cd230();
    virtual Unk_23cd230* vf2();
    virtual void vf3(Unk_23cd230* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd230) == 0x10, "Unk_23cd230");

// 0x7100af6b80
Unk_23cd230* Unk_23cd230::vf2() {
    return new Unk_23cd230(*this);
}

// 0x7100af6bc0
void Unk_23cd230::vf3(Unk_23cd230* p) {
    new (p) Unk_23cd230(*this);
}

// vtable 0x71023cd288: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd278 {
public:
    virtual ~Unk_23cd278();
    virtual Unk_23cd278* vf2();
    virtual void vf3(Unk_23cd278* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd278) == 0x10, "Unk_23cd278");

// 0x7100af6c70
Unk_23cd278* Unk_23cd278::vf2() {
    return new Unk_23cd278(*this);
}

// 0x7100af6cb0
void Unk_23cd278::vf3(Unk_23cd278* p) {
    new (p) Unk_23cd278(*this);
}

// vtable 0x71023cd2d0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd2c0 {
public:
    virtual ~Unk_23cd2c0();
    virtual Unk_23cd2c0* vf2();
    virtual void vf3(Unk_23cd2c0* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd2c0) == 0x10, "Unk_23cd2c0");

// 0x7100af6d60
Unk_23cd2c0* Unk_23cd2c0::vf2() {
    return new Unk_23cd2c0(*this);
}

// 0x7100af6da0
void Unk_23cd2c0::vf3(Unk_23cd2c0* p) {
    new (p) Unk_23cd2c0(*this);
}

// vtable 0x71023cd318: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd308 {
public:
    virtual ~Unk_23cd308();
    virtual Unk_23cd308* vf2();
    virtual void vf3(Unk_23cd308* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd308) == 0x10, "Unk_23cd308");

// 0x7100af6e50
Unk_23cd308* Unk_23cd308::vf2() {
    return new Unk_23cd308(*this);
}

// 0x7100af6e90
void Unk_23cd308::vf3(Unk_23cd308* p) {
    new (p) Unk_23cd308(*this);
}

// vtable 0x71023cd360: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23cd350 {
public:
    virtual ~Unk_23cd350();
    virtual Unk_23cd350* vf2();
    virtual void vf3(Unk_23cd350* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23cd350) == 0x10, "Unk_23cd350");

// 0x7100af6f40
Unk_23cd350* Unk_23cd350::vf2() {
    return new Unk_23cd350(*this);
}

// 0x7100af6f80
void Unk_23cd350::vf3(Unk_23cd350* p) {
    new (p) Unk_23cd350(*this);
}
