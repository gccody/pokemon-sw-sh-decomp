// Scope: common
//
// A class on Unk_23a7ca0_Primary (src/unsorted/Unk_23a7ca0_Base.h, vtable
// 0x710236d418): eleven references and two objects it owns, freed through
// allocators. Its destructor is its key function: its vtable is emitted here.
// Placeholder names: rename once the class is known.
#include <memory>

#include "unsorted/Unk_23a7ca0_Base.h"
#include "unsorted/Unk_23f4660.h"

struct Unk_236d418_Owned {
    u64 field_0;
};

class Unk_236d418 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_236d418() override;
    void vf2() override;
    void vf3() override;

    Unk_239a418_Ref<Unk_239a418> field_50;
    Unk_239a418_Ref<Unk_239a418> field_58;
    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    std::unique_ptr<Unk_236d418_Owned, Unk_23f4660_Deleter> field_98;
    Unk_239a418_Ref<Unk_239a418> field_b8;
    Unk_239a418_Ref<Unk_239a418> field_c0;
    u64 field_c8;
    std::unique_ptr<Unk_236d418_Owned, Unk_23f4660_Deleter> field_d0;
};
static_assert(sizeof(Unk_236d418) == 0xf0, "Unk_236d418");
static_assert(__builtin_offsetof(Unk_236d418, field_98) == 0x98, "Unk_236d418::field_98");
static_assert(__builtin_offsetof(Unk_236d418, field_d0) == 0xd0, "Unk_236d418::field_d0");

// 0x71000084f0, its D0
Unk_236d418::~Unk_236d418() {}
