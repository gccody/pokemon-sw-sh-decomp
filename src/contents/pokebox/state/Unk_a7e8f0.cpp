// Scope: common
//
// The box's "boxtray_out" state (vtable 0x71023c6780): its vf9, type and
// thunks are tools/vtables.py's (src/unsorted/virtual/Unk_a7eb60.cpp).
#include "contents/pokebox/Unk_box.h"

class Unk_23c6780 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a7e8f0
void Unk_23c6780::vf7() {
    field_70 = Unk_d0c0_String("boxtray_out");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_aa70c0();
}

// 0x7100a7ea60
u32 Unk_23c6780::vf8() {
    if (!field_78->Unk_aa74f0())
        return 0;
    Unk_23c63c8* app = Unk_BoxApp(this);
    if (field_78->Unk_GetField620()) {
        if (field_78->Unk_GetField60c())
            field_78->Unk_a99330(false);
        Unk_a77610(app, field_78->Unk_aab8c0());
    }
    app->Unk_SetField64(4);
    return 1;
}
