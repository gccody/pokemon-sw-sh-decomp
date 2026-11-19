// Scope: common
//
// The box's "wallpaper_end" state (vtable 0x7123c7c30): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c7c30 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c8530* field_78;
};

// 0x7100a8abb0
void Unk_23c7c30::vf7() {
    field_70 = Unk_d0c0_String("wallpaper_end");
    field_78 = Unk_StateView<Unk_23c8530>(this, "View_Wallpaper");
    UNK_CHECK(field_78 != nullptr);
    Unk_ab3ac0_call(field_78);
}
