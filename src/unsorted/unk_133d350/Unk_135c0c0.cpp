// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102431fa8): two
// members with destructors of their own (0x710135c460, 0x710135c290) and two
// objects it owns (Unk_2438308_Owned), freed through allocators. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2438308.h"

// Members with out-of-line destructors, not decompiled yet.
struct Unk_135c460 {
    ~Unk_135c460();

    u8 _0[0x660];
};

struct Unk_135c290 {
    ~Unk_135c290();

    u8 _0[0x330];
};

class Unk_2431fa8 : public Unk_239a418 {
public:
    ~Unk_2431fa8() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();

    Unk_135c460 field_60;
    Unk_135c290 field_6c0;
    std::unique_ptr<Unk_2438308_Owned, Unk_23f4660_Deleter> field_9f0;
    std::unique_ptr<Unk_2438308_Owned, Unk_23f4660_Deleter> field_a10;
};
static_assert(sizeof(Unk_2431fa8) == 0xa30, "Unk_2431fa8");
static_assert(__builtin_offsetof(Unk_2431fa8, field_6c0) == 0x6c0, "Unk_2431fa8::field_6c0");
static_assert(__builtin_offsetof(Unk_2431fa8, field_9f0) == 0x9f0, "Unk_2431fa8::field_9f0");

// 0x710135c0c0, its D0 and thunks for +0x48 and +0x50
Unk_2431fa8::~Unk_2431fa8() {}
