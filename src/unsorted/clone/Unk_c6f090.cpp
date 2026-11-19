// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023dd080: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23dd070 {
public:
    virtual ~Unk_23dd070();
    virtual Unk_23dd070* vf2();
    virtual void vf3(Unk_23dd070* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23dd070) == 0x18, "Unk_23dd070");

// 0x7100c6f090
Unk_23dd070* Unk_23dd070::vf2() {
    return new Unk_23dd070(*this);
}

// 0x7100c6f0d0
void Unk_23dd070::vf3(Unk_23dd070* p) {
    new (p) Unk_23dd070(*this);
}
