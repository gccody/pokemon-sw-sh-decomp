// Scope: common
//
// The box's "pokeicon_get" state (vtable 0x71023c6e60): its vf9, type and
// thunks are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c6e60 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a82550
void Unk_23c6e60::vf7() {
    field_70 = Unk_d0c0_String("pokeicon_get");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
}

// 0x7100a826b0
u32 Unk_23c6e60::vf8() {
    if (!field_78->Unk_aa9920())
        return 0;
    Unk_BoxApp(this)->Unk_SetField64(4);
    return 1;
}
