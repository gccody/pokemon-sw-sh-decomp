// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023c4b18: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23c4b08 {
public:
    virtual ~Unk_23c4b08();
    virtual Unk_23c4b08* vf2();
    virtual void vf3(Unk_23c4b08* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23c4b08) == 0x10, "Unk_23c4b08");

// 0x71009b0290
Unk_23c4b08* Unk_23c4b08::vf2() {
    return new Unk_23c4b08(*this);
}

// 0x71009b02d0
void Unk_23c4b08::vf3(Unk_23c4b08* p) {
    new (p) Unk_23c4b08(*this);
}
