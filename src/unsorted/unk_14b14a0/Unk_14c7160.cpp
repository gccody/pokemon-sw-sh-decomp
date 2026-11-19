// Scope: common
//
// A class on Unk_239bd80 (vtable 0x7102443420) that owns an object freed
// through an allocator. Its destructor is its key function: its vtable and
// thunks are emitted here. Placeholder names: rename once the classes are
// known.
#include <memory>

#include "gflib3/Unk_239bd80.h"
#include "unsorted/Unk_23f4660.h"

// The object it owns (vtable 0x7102443518): three references. Its vtable has
// no destructor, and the deleter destroys it directly (final, so that clang
// doesn't warn about that).
class Unk_2443518 final {
public:
    virtual void vf0();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
};
static_assert(sizeof(Unk_2443518) == 0x20, "Unk_2443518");

class Unk_2443420 : public Unk_239bd80 {
public:
    ~Unk_2443420() override;
    const Unk_239a418_Type* vf_type() override;

    std::unique_ptr<Unk_2443518, Unk_23f4660_Deleter> field_148;
    u64 field_168;
};
static_assert(sizeof(Unk_2443420) == 0x170, "Unk_2443420");
static_assert(__builtin_offsetof(Unk_2443420, field_148) == 0x148, "Unk_2443420::field_148");

// 0x71014c7160, its D0 and thunks for +0x48 and +0x50
Unk_2443420::~Unk_2443420() {}
