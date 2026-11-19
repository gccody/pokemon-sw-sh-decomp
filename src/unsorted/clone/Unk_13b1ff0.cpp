// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71024348e0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_24348d0 {
public:
    virtual ~Unk_24348d0();
    virtual Unk_24348d0* vf2();
    virtual void vf3(Unk_24348d0* p);

    u32 field_8;
};
static_assert(sizeof(Unk_24348d0) == 0x10, "Unk_24348d0");

// 0x71013b1ff0
Unk_24348d0* Unk_24348d0::vf2() {
    return new Unk_24348d0(*this);
}

// 0x71013b2030
void Unk_24348d0::vf3(Unk_24348d0* p) {
    new (p) Unk_24348d0(*this);
}
