// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x710242f498): two
// references and two holders (Unk_236d3d8, Unk_236d658). Its destructor is
// its key function: its vtable and thunks are emitted here. Placeholder
// names: rename once the class is known.
#include "unsorted/Unk_236d3d8.h"

class Unk_242f498 : public Unk_239a418 {
public:
    ~Unk_242f498() override;
    const Unk_239a418_Type* vf_type() override;

    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
    Unk_236d3d8 field_70;
    Unk_236d658 field_180;
};
static_assert(sizeof(Unk_242f498) == 0x290, "Unk_242f498");
static_assert(__builtin_offsetof(Unk_242f498, field_180) == 0x180, "Unk_242f498::field_180");

// 0x7101307bb0, its D0 and thunks for +0x48 and +0x50
Unk_242f498::~Unk_242f498() {}
