// Scope: common
// Unk_23ad1f8's function (the TU of 0x71008332e0-0x7100833440).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_812de0;
struct Unk_8130b0;
void Unk_812de0_set(Unk_812de0* self);
void Unk_8130b0_remove(Unk_8130b0* self, void* object);
void Unk_813130_clearField4e(Unk_813130* self);
void* Unk_813140(Unk_813130* self);
bool Unk_80bf00(void* self, void* object, void* other, void* arg3);
void Unk_80bfd0(void* self, void* object, void* other);

// 0x7100833310
void Unk_833310(Unk_23ad1f8* self, Unk_23acc98_Result& /*result*/, const Unk_833310_Arg& arg) {
    Unk_813130_clearField4e(arg.field_10);
    while (void* other = Unk_813140(arg.field_10)) {
        if (Unk_80bf00(Unk_23acc98_Field38(self), arg.field_0, other, arg.field_8)) {
            Unk_812de0_set(reinterpret_cast<Unk_812de0*>(Unk_23acc98_Data(self)->field_10));
            Unk_80bfd0(Unk_23acc98_Field38(self), arg.field_0, other);
            Unk_8130b0_remove(reinterpret_cast<Unk_8130b0*>(arg.field_10), other);
        }
    }
}
