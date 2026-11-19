// Scope: common
// Copies of type-erased callables, slots 2 and 3 of their vtables
// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes
// named after their vtables, as tools/vtables.py names them.
#include <new>

#include <types.h>

// vtable 0x710241f3b8: what it holds is copied whole. Its vtable is
// reached directly (adrp/add), not through the GOT: the callable's class is
// local to its TU (a lambda's), so the vtable isn't preemptible.
class __attribute__((visibility("hidden"))) Unk_241f3a8 {
public:
    virtual ~Unk_241f3a8();
    virtual Unk_241f3a8* vf2();
    virtual void vf3(Unk_241f3a8* p);

    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_241f3a8) == 0x18, "Unk_241f3a8");

// 0x71011b5240
Unk_241f3a8* Unk_241f3a8::vf2() {
    return new Unk_241f3a8(*this);
}

// 0x71011b5280
void Unk_241f3a8::vf3(Unk_241f3a8* p) {
    new (p) Unk_241f3a8(*this);
}
