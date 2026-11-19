// Scope: common
//
// The box's "scroll_box" state (vtable 0x7123c75b0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c75b0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    u32 field_80;
};

// 0x7100a87ea0
void Unk_23c75b0::vf7() {
    field_70 = Unk_d0c0_String("scroll_box");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_80 = 0;
}

// 0x7100a88000
u32 Unk_23c75b0::vf8() {
    switch (field_80) {
        case 0:
            if (field_78->Unk_a9adf0())
                return 0;
            if (field_78->Unk_a9aeb0())
                Unk_a77610(Unk_BoxApp(this), field_78->Unk_aab510());
            field_80++;
            return 0;
        case 1:
            if (!field_78->Unk_a9b100())
                return 0;
            Unk_BoxApp(this)->Unk_SetField64(4);
            return 1;
    }
    return 0;
}
