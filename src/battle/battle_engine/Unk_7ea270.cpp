// Scope: common
// The event system's stacks of variables and of frames (0x71007e9fe0 to
// 0x71007ea870). Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_7e89c0.h"

static inline u16 Unk_7ea270_Label(const Unk_7e9dc0_Var* var) {
    return Unk_7e9f40_getField8(reinterpret_cast<const Unk_7e9f40*>(var));
}

static inline void Unk_7ea270_SetLabel(Unk_7e9dc0_Var* var, u16 label) {
    Unk_7e9e10_setField8(reinterpret_cast<Unk_7e9e10*>(var), label);
}

static inline Unk_7e9dc0_Var* Unk_7ea270_Get(Unk_7ea110_Stack* self, u32 index) {
    if (index < 0x60)
        return self->field_8[index].field_0;
    return nullptr;
}

// 0x71007ea270
void Unk_7ea270(Unk_7ea110_Stack* self) {
    while (self->field_c08 < 0x60) {
        if (Unk_7ea270_Label(self->field_8[self->field_c08].field_0) == 0) {
            if (self->field_c08 < 0x5f) {
                Unk_7ea270_SetLabel(self->field_8[self->field_c08].field_0, 1);
                self->field_c08++;
            }
            return;
        }
        self->field_c08++;
    }
}

// 0x71007ea2f0
void Unk_7ea2f0(Unk_7ea110_Stack* self) {
    if (self->field_c08 == 0)
        return;
    for (u16 i = self->field_c08; i < 0x60; i++) {
        if (Unk_7ea270_Label(self->field_8[i].field_0) == 0)
            break;
        Unk_7ea270_SetLabel(self->field_8[i].field_0, 0);
    }
    self->field_c08--;
    Unk_7ea270_SetLabel(self->field_8[self->field_c08].field_0, 0);
    while (self->field_c08 != 0) {
        self->field_c08--;
        if (Unk_7ea270_Label(self->field_8[self->field_c08].field_0) == 1) {
            self->field_c08++;
            return;
        }
    }
}

// 0x71007ea3b0
Unk_7e9dc0_Var* Unk_7ea3b0(Unk_7ea110_Stack* self, u16 label) {
    u32 i;
    for (i = self->field_c08; i < 0x60; i++) {
        Unk_7e9dc0_Var* var = self->field_8[i].field_0;
        if (Unk_7ea270_Label(var) == 0 || Unk_7ea270_Label(var) == label)
            break;
    }
    return Unk_7ea270_Get(self, i);
}

// 0x71007ea800
Unk_7e9d60_Frame* Unk_7ea800(Unk_7ea5d0_Frames* self) {
    return self->field_8[self->field_408].field_0;
}

// 0x71007ea830
void Unk_7ea830(Unk_7ea5d0_Frames* self) {
    if (self->field_408 != 0) {
        Unk_7e9d20(self->field_8[self->field_408].field_0);
        self->field_408--;
    }
}
