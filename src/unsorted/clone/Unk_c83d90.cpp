// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023ddb40: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23ddb30 {
public:
    virtual ~Unk_23ddb30();
    virtual Unk_23ddb30* vf2();
    virtual void vf3(Unk_23ddb30* p);

    u64 field_8;
};
static_assert(sizeof(Unk_23ddb30) == 0x10, "Unk_23ddb30");

// 0x7100c83d90
Unk_23ddb30* Unk_23ddb30::vf2() {
    return new Unk_23ddb30(*this);
}

// 0x7100c83dd0
void Unk_23ddb30::vf3(Unk_23ddb30* p) {
    new (p) Unk_23ddb30(*this);
}
