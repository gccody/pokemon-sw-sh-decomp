// Scope: common
//
// The box's "boxtray_put" state (vtable 0x71023c6850): its vf9, type and
// thunks are tools/vtables.py's (src/unsorted/virtual/Unk_a7efa0.cpp).
#include "contents/pokebox/Unk_box.h"

class Unk_23c6850 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a7eda0
void Unk_23c6850::vf7() {
    field_70 = Unk_d0c0_String("boxtray_put");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_CallAa89f0();
}

// 0x7100a7ef10
u32 Unk_23c6850::vf8() {
    if (!field_78->Unk_aa8a00())
        return 0;
    Unk_BoxApp(this)->Unk_SetField64(4);
    return 1;
}
