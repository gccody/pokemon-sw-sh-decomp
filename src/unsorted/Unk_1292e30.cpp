// Scope: common
//
// Part of game/unk_1290e40's first TU (0x7101290e40 to 0x71012938b0):
// Unk_242b290 (src/unsorted/Unk_12927e0.h), what makes it, and its virtual
// functions. Its D2 is Unk_242af50's (0x71012928c0), and its D0 and
// destructor thunks branch to that.
//
// NON_MATCHING (Unk_242b290::vf_type, 0x71012930e0): its type's static is
// the second here, where the original has it sixth (+0x50 from Unk_242af50's):
// the other classes of the TU aren't made in this file, so their statics
// aren't emitted (`add x0, x8, #0x18` for `#0x58`).
#include "unsorted/Unk_12927e0.h"

// The functions of the callable Unk_242b290's vf7 stores, local to the TU in
// the original (their addresses are taken with adrp+add): the generated
// leaves of src/unsorted/leaf, and its call (0x71012934c0, not decompiled
// yet).
#define UNK_HIDDEN __attribute__((visibility("hidden")))
void Unk_12934c0(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_12935c0_update() UNK_HIDDEN;
struct Unk_12935d0;
struct Unk_12935d0_arg1;
void Unk_12935d0_set(const Unk_12935d0* self, Unk_12935d0_arg1* value) UNK_HIDDEN;
struct Unk_12935e0;
struct Unk_12935e0_arg1;
void Unk_12935e0_set(const Unk_12935e0* self, Unk_12935e0_arg1* value) UNK_HIDDEN;
#undef UNK_HIDDEN

// 0x7101292ea0: what a callable of Unk_242b1c0 runs
void Unk_1292ea0(Unk_24284d0** captured) {
    Unk_Next<Unk_242b290>(*captured, 0xbaa046a2066759ee);
}

// 0x7101293240
// NON_MATCHING: the stores that empty the struct's first two callables are
// scheduled the other way round (the original clears the second one first
// and the first one last); the instructions are the same.
void Unk_242b290::vf7(u64 arg) {
    Unk_24284d0::vf7(arg);
    Unk_126aca0()->field_70 = 7;
    Unk_126adb0_Arg desc;
    desc.field_2a0 = 0xb0ae006561ff9cbc;
    desc.field_330 = 1.0f;
    Unk_SetCallable(desc.field_0.field_20.field_200, this, &Unk_12934c0, &Unk_12935c0_update,
                    &Unk_12935d0_set, &Unk_12935e0_set);
    Unk_126adb0(this, desc);
}
