// Scope: common
// Pointers into what an item plays. Written from the executable.
// Placeholder names.
#include "Unk_3e2390.h"

// 0x71003e2ee0: what it plays is somewhere else
void Unk_3e2ee0(Unk_3e2ee0_T* self, u8* start) {
    if (self->field_8 != nullptr) {
        s64 offset = start - self->field_8;
        if (self->field_28 != nullptr)
            self->field_28 += offset;
        if (self->field_30 != nullptr)
            self->field_30 += offset;
        if (self->field_38 != nullptr)
            self->field_38 += offset;
        self->field_8 = start;
    }
}
