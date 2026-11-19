// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x7102435580: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2435570 {
public:
    virtual ~Unk_2435570();
    virtual Unk_2435570* vf2();
    virtual void vf3(Unk_2435570* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_2435570) == 0x18, "Unk_2435570");

// 0x71013ca5c0
Unk_2435570* Unk_2435570::vf2() {
    return new Unk_2435570(*this);
}

// 0x71013ca600
void Unk_2435570::vf3(Unk_2435570* p) {
    new (p) Unk_2435570(*this);
}
