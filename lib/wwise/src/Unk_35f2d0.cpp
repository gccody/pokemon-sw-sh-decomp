// Scope: common
// An object with two rows of three tables of points (Unk_35f3b0_Table).
// Placeholder names.
#include <string.h>
#include "Unk_360c20.h"

struct Unk_35f2d0_Self {
    u64 field_0;
    Unk_35f3b0_Table field_8[2][3];
};
PKMN_SIZE_ASSERT(Unk_35f2d0_Self, 0x68);

// 0x710035f2d0
u32 Unk_35f2d0(Unk_35f2d0_Self* self) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            self->field_8[i][j].Unset();
    }
    return 1;
}

// 0x710035f3b0
u32 Unk_35f3b0(Unk_35f2d0_Self* self, u32 row, u32 column, u32 count,
               const Unk_35f3b0_Point* points, u32 scaling) {
    Unk_35f3b0_Table* table = &self->field_8[row][column];
    u32 result = table->Set(points, count, scaling);
    if (result == 1 && column == 0) {
        if (scaling == 0) {
            table->field_c = 4;
        } else if (scaling == 2) {
            for (u32 i = 0; i < table->field_8; i++)
                table->field_0[i].field_4 += 1.0f;
            table->field_c = 0;
        }
    }
    return result;
}
