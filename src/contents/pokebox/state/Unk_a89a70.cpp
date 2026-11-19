// Scope: common
//
// The box's "swap_boxtray" state (vtable 0x7123c79c0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c79c0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a89a70
void Unk_23c79c0::vf7() {
    field_70 = Unk_d0c0_String("swap_boxtray");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_aa7fd0();
}

// 0x7100a89be0
u32 Unk_23c79c0::vf8() {
    if (!field_78->Unk_aa81f0())
        return 0;
    Unk_BoxApp(this)->Unk_SetField64(4);
    return 1;
}
