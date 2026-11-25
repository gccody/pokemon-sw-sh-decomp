// Scope: common
//
// A class on gflib3's other reference-counted object (vtable 0x71023bdfe0),
// 0x80 bytes: an owned array of 0xc0-byte elements, freed through an
// allocator, and a few small fields. Its maker and destructor. Placeholder
// names: rename once the class is known.
#include <functional>
#include <memory>

#include "gflib3/Unk_239a4c0.h"
#include "gflib3/Unk_New.h"
#include "unsorted/Unk_131fb20_Array.h"
#include "unsorted/Unk_23c9470.h"

// What the element's array holds (0x28 bytes: it frees count * 0x28 with
// alignment 8).
struct Unk_23bdfd0_Item {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
static_assert(sizeof(Unk_23bdfd0_Item) == 0x28, "Unk_23bdfd0_Item");

// An element of the owned array, 0xc0 bytes: a function and an array. Its
// deleter (0x71008ed390) isn't inlined: the original's copy is an earlier
// TU's.
struct Unk_23bdfd0_Entry {
    u8 _0[0x10];
    std::function<void()> field_10;
    Unk_131fb20_Array<Unk_23bdfd0_Item> field_40;
    u8 _a0[0x20];
};
static_assert(sizeof(Unk_23bdfd0_Entry) == 0xc0, "Unk_23bdfd0_Entry");
PKMN_OFFSET_ASSERT(Unk_23bdfd0_Entry, field_40, 0x40);

// Its constructor is implicit: the maker value-initializes it, zeroing it
// before the constructor runs.
class Unk_23bdfd0 : public Unk_239a4c0 {
public:
    ~Unk_23bdfd0() override;

    std::unique_ptr<Unk_23bdfd0_Entry[], Unk_23c9470_ArrayDeleter> field_58;
    u32 field_78 = 0;
    u16 field_7c = 0;
    u8 field_7e = 0;
};
static_assert(sizeof(Unk_23bdfd0) == 0x80, "Unk_23bdfd0");
PKMN_OFFSET_ASSERT(Unk_23bdfd0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_23bdfd0, field_78, 0x78);

// 0x710090f360
template Unk_23bdfd0* Unk_New::Create<Unk_23bdfd0>(Unk_239a418_Allocator*);

// 0x710090f4f0, 0x710090f520 (D0), thunks 0x710090f550/0x710090f590 (+0x48)
Unk_23bdfd0::~Unk_23bdfd0() {}
