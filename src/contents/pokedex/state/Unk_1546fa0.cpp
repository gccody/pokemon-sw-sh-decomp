// Scope: common
//
// The Pokedex's "register_end" state (vtable 0x7102449d10): its type and thunks
// are tools/vtables.py's.
#include "contents/pokedex/Unk_dex.h"

class Unk_2449d10 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_2449670* field_78;
};

// 0x7101546fa0
void Unk_2449d10::vf7() {
    field_70 = Unk_d0c0_String("register_end");
    field_78 = Unk_StateView<Unk_2449670>(this, "ViewDetails");
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_1541910();
}
