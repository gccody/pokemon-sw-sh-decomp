// Scope: common
//
// The box's "marking" state (vtable 0x71023c7000): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c7000 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    u32 field_80;
};

// 0x7100a82e50
void Unk_23c7000::vf7() {
    field_70 = Unk_d0c0_String("marking");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_CallE807f0(false);
    field_80 = 0;
}

// 0x7100a82fc0
u32 Unk_23c7000::vf8() {
    switch (field_80) {
        case 0:
            if (!field_78->Unk_aa6570())
                return 0;
            field_80++;
            // fall through
        case 1:
            if (!field_78->Unk_CheckAa6650())
                return 0;
            field_78->Unk_aa6660();
            field_80++;
            // fall through
        case 2:
            if (!field_78->Unk_aa66e0())
                return 0;
            Unk_BoxApp(this)->Unk_SetField64(4);
            return 1;
    }
    return 0;
}
