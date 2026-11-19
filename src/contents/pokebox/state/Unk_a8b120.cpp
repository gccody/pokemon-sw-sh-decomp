// Scope: common
//
// The box's "wallpaper_start" state (vtable 0x7123c7d00): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c7d00 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c8530* field_78;
};

// 0x7100a8b120
void Unk_23c7d00::vf7() {
    field_70 = Unk_d0c0_String("wallpaper_start");
    field_78 = Unk_StateView<Unk_23c8530>(this, "View_Wallpaper");
    UNK_CHECK(field_78 != nullptr);
    Unk_e806b0(field_78, true, true);
    field_78->Unk_ab3b10();
    Unk_ab3ab0_call(field_78);
}
