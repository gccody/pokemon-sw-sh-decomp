// Scope: common
//
// The box's "search" state (vtable 0x7123c7750): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c7750 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c7ed0* field_78;
    Unk_23c81e8* field_80;
    u32 field_88;
};

// 0x7100a888c0
void Unk_23c7750::vf7() {
    field_70 = Unk_d0c0_String("search");
    field_80 = Unk_BoxTopView(this);
    UNK_CHECK(field_80 != nullptr);
    field_78 = Unk_StateView<Unk_23c7ed0>(this, "View_Search");
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_a8c8d0();
    field_78->Unk_a8c870();
    field_88 = 0;
}
