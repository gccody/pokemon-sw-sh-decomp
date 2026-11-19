// Scope: common
//
// The box's "search_start" state (vtable 0x7123c78f0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c78f0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    Unk_23c7ed0* field_80;
};

// 0x7100a89530
void Unk_23c78f0::vf7() {
    field_70 = Unk_d0c0_String("search_start");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    Unk_a96ae0_call(field_78);
    field_80 = Unk_StateView<Unk_23c7ed0>(this, "View_Search");
    UNK_CHECK(field_80 != nullptr);
    Unk_e806b0(field_80, true, true);
    field_80->Unk_a8ca80();
    Unk_a8c930_call(field_80);
}
