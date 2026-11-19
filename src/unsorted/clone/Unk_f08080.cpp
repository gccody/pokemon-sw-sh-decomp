// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023fa4a0: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23fa490 {
public:
    virtual ~Unk_23fa490();
    virtual Unk_23fa490* vf2();
    virtual void vf3(Unk_23fa490* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23fa490) == 0x10, "Unk_23fa490");

// 0x7100f08080
Unk_23fa490* Unk_23fa490::vf2() {
    return new Unk_23fa490(*this);
}

// 0x7100f080c0
void Unk_23fa490::vf3(Unk_23fa490* p) {
    new (p) Unk_23fa490(*this);
}
