// Scope: common
//
// Two classes on gflib3's other reference-counted object, Unk_239a4c0: one owns an object that it
// deletes and then gives back to an allocator (vtable 0x710242f6a8), the other
// resets a reference before it goes (vtable 0x710242f3e0). Their destructors
// are their key functions: their vtables and thunks are emitted here.
// Placeholder names: rename once the classes are known.
#include <memory>

#include "gflib3/Unk_239a4c0.h"

// What frees the owned object: deletes it (a virtual call; the family's
// operator delete is empty), then gives its memory back to the allocator.
struct Unk_242f6a8_Deleter {
    template <class T>
    void operator()(T* p) const {
        delete p;
        field_0->vf3(reinterpret_cast<u64>(p), field_8, field_10);
    }

    Unk_239a418_Allocator* field_0;
    u64 field_8;
    u64 field_10;
};

class Unk_242f6a8 : public Unk_239a4c0 {
public:
    ~Unk_242f6a8() override;

    std::unique_ptr<Unk_239a418_Base, Unk_242f6a8_Deleter> field_58;
};
static_assert(sizeof(Unk_242f6a8) == 0x78, "Unk_242f6a8");
static_assert(__builtin_offsetof(Unk_242f6a8, field_58) == 0x58, "Unk_242f6a8::field_58");

// 0x710130a510, its D0 and thunks for +0x48
Unk_242f6a8::~Unk_242f6a8() {}
