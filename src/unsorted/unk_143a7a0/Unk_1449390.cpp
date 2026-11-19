// Scope: common
//
// A class on Unk_23f4660 (vtable 0x710243c120): a reference, four callables,
// three holders (Unk_236d3d8), an object it owns, freed through an allocator,
// and two more references. Its destructor is its key function: its vtable is
// emitted here. Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_23f4660.h"

// The owned object: destroyed through its vtable.
class Unk_243c120_Owned {
public:
    virtual ~Unk_243c120_Owned();
};

class Unk_243c120 : public Unk_23f4660 {
public:
    ~Unk_243c120() override;
    const Unk_239a418_Type* vf_type() override;

    u8 _5d0[0x628 - 0x5d0];
    Unk_239a418_Ref<Unk_239a418> field_628;
    u64 field_630;
    u64 field_638;
    Unk_23d4470_Callable field_640[4];
    u8 _840[0x2e60 - 0x840];
    Unk_236d3d8 field_2e60[3];
    u64 field_3190;
    std::unique_ptr<Unk_243c120_Owned, Unk_23f4660_Deleter> field_3198;
    u64 field_31b8;
    Unk_239a418_Ref<Unk_239a418> field_31c0;
    Unk_239a418_Ref<Unk_239a418> field_31c8;
};
static_assert(sizeof(Unk_243c120) == 0x31d0, "Unk_243c120");
static_assert(__builtin_offsetof(Unk_243c120, field_640) == 0x640, "Unk_243c120::field_640");
static_assert(__builtin_offsetof(Unk_243c120, field_2e60) == 0x2e60, "Unk_243c120::field_2e60");
static_assert(__builtin_offsetof(Unk_243c120, field_3198) == 0x3198, "Unk_243c120::field_3198");

// 0x7101449390 (its D0 tail-calls it)
Unk_243c120::~Unk_243c120() {}
