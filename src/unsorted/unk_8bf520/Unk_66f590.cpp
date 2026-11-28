// Scope: common
// The rest of the math commands of 0x71023a0500, and their registration.
#include <math.h>
#include <types.h>

#include "unsorted/unk_8bf520/Unk_66efd0.h"

// 0x710066f590: the cosine of an angle (as Unk_66efd0_Radians reads it).
s64 Unk_66f590(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(static_cast<f32>(cos(Unk_66efd0_Radians(args))));
}

// 0x710066f600: the tangent of an angle (as Unk_66efd0_Radians reads it).
s64 Unk_66f600(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(static_cast<f32>(tan(Unk_66efd0_Radians(args))));
}

// 0x710066f670: the absolute value.
s64 Unk_66f670(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    f64 value = args->field_8.f;
    return Unk_66efd0_Result(value >= 0.0 ? value : -value);
}

// A command: its name and the function that runs it.
struct Unk_66c2b0_Command {
    const char* name;
    s64 (*function)(Unk_66efd0* self, const Unk_66efd0_Args* args);
};
PKMN_SIZE_ASSERT(Unk_66c2b0_Command, 0x10);

// 0x71023a0500: the math commands, up to one without a name.
extern const Unk_66c2b0_Command Unk_23a0500[];

// 0x710066c2b0: binds the script's imports to the commands with their names
// (count of them, or all with -1).
u32 Unk_66c2b0(Unk_66efd0* self, const Unk_66c2b0_Command* commands, s32 count);

// 0x710066f690: binds the script's imports to the math commands.
u32 Unk_66f690(Unk_66efd0* self) {
    return Unk_66c2b0(self, Unk_23a0500, -1);
}
