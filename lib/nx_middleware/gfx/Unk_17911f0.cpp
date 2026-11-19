// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: the GLSLC entry points, imports of `main`.
// Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

using Unk_17911f0_Proc = void (*)();

Unk_17911f0_Proc Unk_17912e0();
Unk_17911f0_Proc Unk_17912f0();
Unk_17911f0_Proc Unk_1791300();
Unk_17911f0_Proc Unk_1791310();
Unk_17911f0_Proc Unk_1791320();
Unk_17911f0_Proc Unk_1791330();
Unk_17911f0_Proc Unk_1791340();
Unk_17911f0_Proc Unk_1791350();

// The GLSLC entry points, in Unk_17912e0..Unk_1791350's order.
struct Unk_17911f0_Table {
    Unk_17911f0_Proc field_0;
    Unk_17911f0_Proc field_8;
    Unk_17911f0_Proc field_10;
    Unk_17911f0_Proc field_18;
    Unk_17911f0_Proc field_20;
    Unk_17911f0_Proc field_28;
    Unk_17911f0_Proc field_30;
    Unk_17911f0_Proc field_38;
};
PKMN_SIZE_ASSERT(Unk_17911f0_Table, 0x40);

// 0x71017911f0
bool Unk_17911f0(Unk_17911f0_Table* self) {
    self->field_0 = Unk_17912e0();
    self->field_8 = Unk_17912f0();
    self->field_10 = Unk_1791300();
    self->field_18 = Unk_1791310();
    self->field_20 = Unk_1791320();
    self->field_28 = Unk_1791330();
    self->field_30 = Unk_1791340();
    self->field_38 = Unk_1791350();
    return self->field_0 != nullptr && self->field_8 != nullptr && self->field_10 != nullptr &&
           self->field_18 != nullptr && self->field_20 != nullptr && self->field_28 != nullptr &&
           self->field_30 != nullptr && self->field_38 != nullptr;
}
