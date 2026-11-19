// Scope: common
//
// The box's "scroll_party" state (vtable 0x7123c7680): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c7680 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    u32 field_80;
};

// 0x7100a883b0
void Unk_23c7680::vf7() {
    field_70 = Unk_d0c0_String("scroll_party");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_80 = 0;
}

// 0x7100a88510
u32 Unk_23c7680::vf8() {
    switch (field_80) {
        case 0:
            if (field_78->Unk_a9b5f0())
                return 0;
            if (field_78->Unk_a9b6b0())
                Unk_a77610(Unk_BoxApp(this), field_78->Unk_aab510());
            field_80++;
            return 0;
        case 1:
            if (!field_78->Unk_a9b9c0())
                return 0;
            Unk_BoxApp(this)->Unk_SetField64(4);
            return 1;
    }
    return 0;
}
