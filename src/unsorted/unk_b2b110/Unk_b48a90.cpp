// Scope: common
// Three std::function callables (libc++'s __func, vtables 0x71023cfb50,
// 0x71023cfb98 and 0x71023cfbe0): their calls, and the whole of the second
// one but its destroy (slot 4, in src/unsorted/virtual): a lambda that holds
// a weak reference (a reference to the object's handle) and, when called,
// passes its argument the object (locked as an Unk_239bd80, or none). Their
// other slots are in src/unsorted/clone and src/unsorted/virtual. Placeholder
// classes named after their vtables, as tools/vtables.py names them.
#include <functional>
#include <memory>
#include <new>
#include <vector>

#include <types.h>

#include "gflib3/Unk_239bd80.h"
#include "gflib3/Unk_Lock.h"

// What the callables are called with.
struct Unk_b48aa0_Arg {
    u8 _0[0x320];
    std::vector<void*> field_320;
};
PKMN_OFFSET_ASSERT(Unk_b48aa0_Arg, field_320, 0x320);

void Unk_618ec0(void* self, Unk_239bd80* object, const u64& value);
void Unk_ee3500(void* self, void* arg);

class __attribute__((visibility("hidden"))) Unk_23cfb40 {
public:
    virtual ~Unk_23cfb40();
    virtual Unk_23cfb40* vf2();
    virtual void vf3(Unk_23cfb40* p);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(Unk_b48aa0_Arg** arg);

    std::function<void(Unk_b48aa0_Arg*)>* field_8;
};
static_assert(sizeof(Unk_23cfb40) == 0x10, "Unk_23cfb40");

// 0x7100b48aa0
void Unk_23cfb40::vf6(Unk_b48aa0_Arg** arg) {
    Unk_b48aa0_Arg* value = *arg;
    if (value != nullptr && value->field_320.size() != 0)
        (*field_8)(value);
}

class __attribute__((visibility("hidden"))) Unk_23cfb88 {
public:
    Unk_23cfb88(const Unk_23cfb88& other) = default;
    virtual ~Unk_23cfb88();
    virtual Unk_23cfb88* vf2();
    virtual void vf3(Unk_23cfb88* p);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(void** arg);

    // The copy tests the pointer it stored (the placement copy, slot 3, would
    // load the other's again with Unk_239a418_Ref).
    Unk_239a418_Ref2<Unk_239a418_Handle> field_8;
};
static_assert(sizeof(Unk_23cfb88) == 0x10, "Unk_23cfb88");

// 0x7100b48b00 (D2), 0x7100b48b40 (D0)
Unk_23cfb88::~Unk_23cfb88() {}

// 0x7100b48b80
Unk_23cfb88* Unk_23cfb88::vf2() {
    return new Unk_23cfb88(*this);
}

// 0x7100b48bd0
void Unk_23cfb88::vf3(Unk_23cfb88* p) {
    new (p) Unk_23cfb88(*this);
}

// 0x7100b48c40
void Unk_23cfb88::vf5() {
    // libc++'s destroy_deallocate: the allocator frees with the builtin
    // operator delete, so the reference's clearing store is dropped.
    field_8.~Unk_239a418_Ref2();
    std::allocator<Unk_23cfb88>().deallocate(this, 1);
}

// 0x7100b48c80
void Unk_23cfb88::vf6(void** arg) {
    Unk_239a418_Handle* handle = field_8.m_ptr;
    auto call = [handle](void* value) {
        Unk_239a418_Ref<Unk_239bd80> object =
            handle != nullptr ? Unk_Lock<Unk_239bd80>(handle) : Unk_239a418_Ref<Unk_239bd80>();
        Unk_618ec0(value, object.m_ptr, 8);
    };
    call(*arg);
}

class __attribute__((visibility("hidden"))) Unk_23cfbd0 {
public:
    virtual ~Unk_23cfbd0();
    virtual Unk_23cfbd0* vf2();
    virtual void vf3(Unk_23cfbd0* p);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(void** arg);

    alignas(16) u64 field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_23cfbd0) == 0x20, "Unk_23cfbd0");

// 0x7100b48df0
void Unk_23cfbd0::vf6(void** arg) {
    Unk_ee3500(*arg, &field_10);
}
