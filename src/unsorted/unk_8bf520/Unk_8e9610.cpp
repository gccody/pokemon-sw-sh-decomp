// Scope: common
// Two of the Battle Tower's states (src/unsorted/unk_8bf520/Unk_8e9610.h):
// their vf7 and vf8, and with their vtables, their D0s and thunks.
#include "unsorted/unk_8bf520/Unk_8e9610.h"

// tools/leafgen.py's placeholders.
void Unk_eb6230(void* view, u32 arg);
struct Unk_8e80e0;
void Unk_8e80e0_call(Unk_8e80e0* self);

// 0x71008e9890; the vtable's D0 0x71008e9920 and thunks for +0x48
// (0x71008e99c0 D1, 0x71008e9a60 D0) and +0x50 (0x71008e9b00 D1,
// 0x71008e9ba0 D0)
void Unk_23bcf90::vf7() {
    field_70 = Unk_d0c0_String("statebattletowershowhelp");
    Unk_8e8f80();
    Unk_eb6230(field_88.m_ptr, 0);
    Unk_ViewE807f0(static_cast<Unk_23f4660*>(field_88.m_ptr), false);
}

// 0x71008e9900
u32 Unk_23bcf90::vf8() {
    return static_cast<Unk_8e9900_View*>(field_88.m_ptr)->vf17();
}

// 0x71008e9c40; the vtable's D0 0x71008e9d60 and thunks for +0x48
// (0x71008e9e00 D1, 0x71008e9ea0 D0) and +0x50 (0x71008e9f40 D1,
// 0x71008e9fe0 D0)
void Unk_23bd060::vf7() {
    field_70 = Unk_d0c0_String("statebattletowerselectmode");
    Unk_8e8f80();
    Unk_8e80e0_call(reinterpret_cast<Unk_8e80e0*>(field_78.m_ptr));
    Unk_ViewE807f0(static_cast<Unk_23f4660*>(field_78.m_ptr), false);
    Unk_e80580(static_cast<Unk_23f4660*>(field_78.m_ptr), 1, 1);
}

// 0x71008e9cc0
u32 Unk_23bd060::vf8() {
    Unk_8e9cc0_View* view = static_cast<Unk_8e9cc0_View*>(field_78.m_ptr);
    if (!view->field_5cc)
        return 0;
    if (view->field_5d4) {
        Unk_23bcb40* app = Unk_DynamicCast<Unk_23bcb40>(Unk_HandleObject(field_68));
        app->field_60 = view->field_5d8;
    }
    return 1;
}
