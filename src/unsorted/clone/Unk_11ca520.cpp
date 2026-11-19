// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x7102420138: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_2420128 {
public:
    virtual ~Unk_2420128();
    virtual Unk_2420128* vf2();
    virtual void vf3(Unk_2420128* p);

    u64 field_8;
};
static_assert(sizeof(Unk_2420128) == 0x10, "Unk_2420128");

// 0x71011ca520
Unk_2420128* Unk_2420128::vf2() {
    return new Unk_2420128(*this);
}

// 0x71011ca560
void Unk_2420128::vf3(Unk_2420128* p) {
    new (p) Unk_2420128(*this);
}
