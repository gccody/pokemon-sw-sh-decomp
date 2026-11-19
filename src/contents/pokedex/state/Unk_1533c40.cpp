// Scope: common
//
// The Pokedex's "action_in" state (vtable 0x712448a18): its type and thunks
// are tools/vtables.py's.
#include "contents/pokedex/Unk_dex.h"

class Unk_2448a18 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_2447cf0* field_78;
};

// 0x7101533c40
void Unk_2448a18::vf7() {
    field_70 = Unk_d0c0_String("action_in");
    field_78 = Unk_StateView<Unk_2447cf0>(this, "ViewDetails");
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_1525710(Unk_StateView<Unk_23f6118>(this, "OptionBar"));
    field_78->Unk_1527a40(true);
}
