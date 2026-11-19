// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

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
