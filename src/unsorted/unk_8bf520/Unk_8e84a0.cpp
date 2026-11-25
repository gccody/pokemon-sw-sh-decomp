// Scope: common
// The Battle Tower's view Unk_23bcc08 (src/unsorted/unk_8bf520/Unk_8e7dd0.h):
// its callables' invokers, and the state "statebattletowerin" (Unk_23bcd20,
// on Unk_23bcdf0: src/unsorted/unk_8bf520/Unk_8e9610.h): its vf7, and with its
// vtable, its D0 and thunks. Its vf8 is in
// src/unsorted/unk_8bf520/Unk_8e8710.cpp, its vf9 in
// src/unsorted/virtual/Unk_8e4150.cpp. Placeholder names: rename once the
// classes are known.
#include "unsorted/unk_8bf520/Unk_8e7dd0.h"
#include "unsorted/unk_8bf520/Unk_8e9610.h"

void Unk_14e1a30(u64 self, u32 arg);
void Unk_ec9400(Unk_239a418* object);
void Unk_ec9430(Unk_239a418* object);

// 0x71008e84d0
void Unk_8e84d0(Unk_23bcc08_Closure* closure) {
    Unk_23bcc08* self = closure->field_0;
    u32 selection;
    switch (closure->field_8) {
        case 0:
            selection = 0;
            break;
        case 1:
            selection = 1;
            break;
        default:
            selection = 2;
            break;
    }
    self->field_5cc = Unk_23bcc08_Result{selection, Unk_23bcc08_ToMode(selection)};
    Unk_14e1a30(reinterpret_cast<u64>(self->field_6d0.m_ptr), 0);
}

// 0x71008e8560
void Unk_8e8560(Unk_23bcc08_Closure* closure) {
    Unk_23bcc08* self = closure->field_0;
    u32 selection = closure->field_8;
    self->field_5cc = Unk_23bcc08_Result{selection, Unk_23bcc08_ToMode(selection)};
    Unk_14e1a30(reinterpret_cast<u64>(self->field_6d0.m_ptr), 0);
}

// 0x71008e85e0
void Unk_8e85e0(Unk_23bcc08_Closure* closure) {
    Unk_23bcc08* self = closure->field_0;
    if (closure->field_8)
        Unk_ec9430(self->field_6a0.m_ptr);
    else
        Unk_ec9400(self->field_6a0.m_ptr);
    self->Unk_8e7c70();
    Unk_e80580(self, 1, 1);
}

// tools/leafgen.py's placeholder.
void Unk_eb6230(void* view, u32 arg);

// The state "statebattletowerin" (vtable 0x71023bcd30).
class Unk_23bcd20 : public Unk_23bcdf0 {
public:
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x71008e8660; the vtable's D0 0x71008e8740 and thunks for +0x48
// (0x71008e87f0 D1, 0x71008e8890 D0) and +0x50 (0x71008e8950 D1,
// 0x71008e89f0 D0)
void Unk_23bcd20::vf7() {
    field_70 = Unk_d0c0_String("statebattletowerin");
    Unk_8e8f80();
    Unk_23bcb40* app = Unk_DynamicCast<Unk_23bcb40>(Unk_HandleObject(field_68));
    static_cast<Unk_23bcc08*>(field_78.m_ptr)->Unk_8e7080(app->field_60);
    Unk_eb6230(field_78.m_ptr, 0);
}
