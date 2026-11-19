// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x71023e4b68: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_23e4b58 {
public:
    virtual ~Unk_23e4b58();
    virtual Unk_23e4b58* vf2();
    virtual void vf3(Unk_23e4b58* p);

    u64 field_8;
    u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23e4b58) == 0x20, "Unk_23e4b58");

// 0x7100cf43d0
Unk_23e4b58* Unk_23e4b58::vf2() {
    return new Unk_23e4b58(*this);
}

// 0x7100cf4410
void Unk_23e4b58::vf3(Unk_23e4b58* p) {
    new (p) Unk_23e4b58(*this);
}
