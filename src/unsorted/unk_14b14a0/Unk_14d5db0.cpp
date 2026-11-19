// Scope: common
//
// Two classes on gflib3's other reference-counted object, Unk_239a4c0
// (vtables 0x7102443a80 and 0x7102443b20), each with a holder (Unk_236d4d8)
// and a reference. Their destructors are their key functions: their vtables
// and thunks are emitted here. Each is 0x180 bytes, aligned to 0x10 like the
// callables it holds (src/unsorted/Unk_23d4470.h): every function that creates
// one (0x71007a6d90, 0x7100e81e60, and 0x71014da2b0, 0x710151d5d0 for
// Unk_2443b20) asks for 0x180 bytes aligned to 0x10, and the constructors'
// last store is the reference at +0x170. Placeholder names: rename once the
// classes are known.
#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_236d3d8.h"

class Unk_2443a80 : public Unk_239a4c0 {
public:
    ~Unk_2443a80() override;

    u64 field_58;
    Unk_236d4d8 field_60;
    Unk_239a418_Ref<Unk_239a418> field_170;
};
static_assert(sizeof(Unk_2443a80) == 0x180, "Unk_2443a80");
static_assert(__builtin_offsetof(Unk_2443a80, field_60) == 0x60, "Unk_2443a80::field_60");

// 0x71014d5db0, its D0 and thunks for +0x48
Unk_2443a80::~Unk_2443a80() {}

class Unk_2443b20 : public Unk_239a4c0 {
public:
    ~Unk_2443b20() override;

    u64 field_58;
    Unk_236d4d8 field_60;
    Unk_239a418_Ref<Unk_239a418> field_170;
};
static_assert(sizeof(Unk_2443b20) == 0x180, "Unk_2443b20");

// 0x71014d61f0, its D0 and thunks for +0x48
Unk_2443b20::~Unk_2443b20() {}
