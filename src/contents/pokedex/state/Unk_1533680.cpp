// Scope: common
//
// The Pokedex's "top_main" state (vtable 0x7102448948): its type and thunks
// are tools/vtables.py's.
#include "contents/pokedex/Unk_dex.h"

class Unk_2448948 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_2447e50* field_78;
};

// 0x7101533680
void Unk_2448948::vf7() {
    field_70 = Unk_d0c0_String("top_main");
    field_78 = Unk_StateView<Unk_2447e50>(this, "ViewTop");
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_1528730();
}
