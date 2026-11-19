// Scope: common
//
// The box's "pokeicon_release" state (vtable 0x7123c74e0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c74e0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a879a0
void Unk_23c74e0::vf7() {
    field_70 = Unk_d0c0_String("pokeicon_release");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
}
