// Scope: common
//
// The Pokedex's "details_out" state (vtable 0x7102448fc8): its type and
// thunks are tools/vtables.py's.
#include "contents/pokedex/Unk_dex.h"

class Unk_2448fc8 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_2448020* field_78;
    Unk_2447cf0* field_80;
};

// 0x7101537480
void Unk_2448fc8::vf7() {
    field_70 = Unk_d0c0_String("details_out");
    field_78 = Unk_StateView<Unk_2448020>(this, "ViewBg");
    UNK_CHECK(field_78 != nullptr);
    Unk_152a790_call(field_78);
    field_80 = Unk_StateView<Unk_2447cf0>(this, "ViewDetails");
    UNK_CHECK(field_80 != nullptr);
    Unk_15248c0_call(field_80);
    Unk_DexApp(this)->Unk_151cd20(0);
}
