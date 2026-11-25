// Scope: common
// The named handle (Unk_23a8158, src/unsorted/Unk_793990.h): naming it, and
// its virtual functions, which look its index up and call the manager with
// it. A handle without a name does nothing. The slots are written as free
// functions until the class's signatures are known. Placeholder names: rename
// once the classes are known.
#include <types.h>

#include "unsorted/Unk_793990.h"

// 0x7100793d10
bool Unk_793d10(Unk_23a8158* self, const Unk_5cfaf0_Name& name) {
    if (name.field_8[0] == '\0')
        return false;
    self->field_8 = Unk_d0c0_String(name.field_8);
    s64 index = Unk_791a00(Unk_24ba4f0, self, true);
    return Unk_793640(Unk_27ce848, index, self->field_8.Unk_5cfaf0());
}

// 0x7100793de0
bool Unk_793de0(Unk_23a8158* self) {
    if (!self->Unk_HasName())
        return false;
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    if (!Unk_7936f0(Unk_27ce848, index))
        return false;
    Unk_792300(Unk_24ba4f0, index);
    return true;
}

// 0x7100793ea0
bool Unk_793ea0(Unk_23a8158* self, const void* arg1, u64 arg2, u64 arg3) {
    if (!self->Unk_HasName())
        return false;
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793740(Unk_27ce848, arg1, arg2, arg3, index);
}

// Slot 2.
// 0x7100793f30
bool Unk_793f30(Unk_23a8158* self, const Unk_5cfaf0_Name* name, const Unk_5cfaf0_Name* other) {
    if (!self->Unk_HasName())
        return false;
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793ba0(Unk_27ce848, name, other, index);
}

// Slot 3.
// 0x7100793fb0
bool Unk_793fb0(Unk_23a8158* self, u64 name, u32 arg2, f32 arg3) {
    if (!self->Unk_HasName())
        return false;
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793b20(reinterpret_cast<u64>(Unk_27ce848), name, arg3, index, arg2);
}

// Slot 4.
// 0x7100794040
u32 Unk_794040(void* handle, void* arg1) {
    Unk_23a8158* self = static_cast<Unk_23a8158*>(handle);
    if (!self->Unk_HasName())
        return 0;
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return 0;
    return Unk_7938b0(Unk_27ce848, arg1, index);
}

// Slot 5.
// 0x71007940c0
bool Unk_7940c0(Unk_23a8158* self, f32 arg1) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793930(Unk_27ce848, index, arg1);
}

// Slot 6.
// 0x7100794120
bool Unk_794120(Unk_23a8158* self, const Unk_5cfaf0_Name* name, f32 decibels) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793990(Unk_27ce848, name, decibels, index);
}
