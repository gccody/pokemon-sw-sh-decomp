// Scope: common
//
// The Pokedex's "register_main" state (vtable 0x7102449de0): its type and thunks
// are tools/vtables.py's.
#include "contents/pokedex/Unk_dex.h"

class Unk_2449de0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_2449670* field_78;
};

// 0x7101547420
void Unk_2449de0::vf7() {
    field_70 = Unk_d0c0_String("register_main");
    field_78 = Unk_StateView<Unk_2449670>(this, "ViewDetails");
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_15405d0();
}

// 0x7101547590
u32 Unk_2449de0::vf8() {
    if (field_78->Unk_GetField5cc() != 1)
        return 0;
    field_78->Unk_1540610(false);
    Unk_RegisterApp(this)->Unk_SetField6c(6);
    return 1;
}
