// Scope: common
//
// The box's "menu" state (vtable 0x71023c70d0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c70d0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    void Unk_a84900(u32 value);

    Unk_23c81e8* field_78;
    Unk_23f6218* field_80;
};

// 0x7100a84900
void Unk_23c70d0::Unk_a84900(u32 value) {
    Unk_23c63c8* app = Unk_BoxApp(this);
    Unk_23c63c8_Data* data = app->Unk_GetField70();
    data->field_1a4 = value;
    u32 arg1 = 2;
    u32 arg2 = 0;
    u32 arg3 = 0;
    field_78->Unk_aaaf10(&arg1, &arg2, &arg3);
    data->field_4c = arg1;
    data->field_50 = arg3;
    data->field_52 = field_78->Unk_GetField614();
    data->field_19c = field_78->Unk_GetField618();
    app->Unk_SetField64(2);
}
