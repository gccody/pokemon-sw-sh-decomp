// Scope: common
//
// The box's "boxtray_in" state (vtable 0x71023c66b0): its vf9, type and
// thunks are tools/vtables.py's (src/unsorted/virtual/Unk_a7e580.cpp).
#include "contents/pokebox/Unk_box.h"

class Unk_23c66b0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a7e320
void Unk_23c66b0::vf7() {
    field_70 = Unk_d0c0_String("boxtray_in");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_aa68c0();
    if (field_78->Unk_GetField620()) {
        field_78->Unk_a95770(false);
        Unk_a77610(Unk_BoxApp(this), nullptr);
    }
}

// 0x7100a7e4f0
u32 Unk_23c66b0::vf8() {
    if (!field_78->Unk_aa6f70())
        return 0;
    Unk_BoxApp(this)->Unk_SetField64(4);
    return 1;
}
