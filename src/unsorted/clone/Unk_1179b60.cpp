// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x710241c898: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_241c888 {
public:
    virtual ~Unk_241c888();
    virtual Unk_241c888* vf2();
    virtual void vf3(Unk_241c888* p);

    u64 field_8;
    u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_241c888) == 0x20, "Unk_241c888");

// 0x7101179b60
Unk_241c888* Unk_241c888::vf2() {
    return new Unk_241c888(*this);
}

// 0x7101179ba0
void Unk_241c888::vf3(Unk_241c888* p) {
    new (p) Unk_241c888(*this);
}
