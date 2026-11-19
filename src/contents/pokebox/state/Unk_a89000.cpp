// Scope: common
//
// The box's "search_end" state (vtable 0x7123c7820): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c7820 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    Unk_23c7ed0* field_80;
};

// 0x7100a89000
void Unk_23c7820::vf7() {
    field_70 = Unk_d0c0_String("search_end");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    Unk_a96ad0_call(field_78);
    field_80 = Unk_StateView<Unk_23c7ed0>(this, "View_Search");
    UNK_CHECK(field_80 != nullptr);
    Unk_a8c940_call(field_80);
}
